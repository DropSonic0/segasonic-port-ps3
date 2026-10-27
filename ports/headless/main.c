/**
*    Name:        main.c
*    Description: runs the game with no screen or sound, with the controls a script drives, and writes a
*                 hash of the board state (and of the frame the video draws) after every frame, in the
*                 format tools/reference/s32ref uses
*    Version:     0.1.0
*    Created:     11-10-2026
*    Modified:    25-10-2026
*    Author:      Sebastian Toyos
*
*    license:BSD-3-Clause
*    Usage: sonic_headless [--frames N] [--hashes FILE] [--script FILE]
*                          [--dump-frame N --dump-dir DIR] [--video-hashes FILE] [--video-dump N ... --video-dir DIR]
*                          [--sound-hashes FILE] [--sound-levels FILE] [--wide] [--assets FILE] [--extract ROM_SET]
*                          [--actions FILE]
*    The game's data is its assets pack (game/data.h): --assets, or segasonic.assets beside the executable.
*    --extract first writes that pack from the player's ROM set (a .zip or a folder), as the first run does
*    (runtime/src/extract.c). The scaffold (SEGASONIC_SCAFFOLD) runs the original code, so it reads the ROM
*    set from rom/ instead.
*    --dump-frame saves the board's memories at the end of that frame, in the files tools/reference/s32ref
*    writes, so the two compare byte by byte. --video-hashes and --video-dump draw every frame with the
*    board's video (runtime/src/video.c): the hash of each frame, and frames as BMP. --sound-hashes runs the
*    sound board too (the decompiled sound program and the chips, runtime/src/sound_cpu.c and
*    sound_chips.c), and writes for each frame the hash of its samples and of the sound board's memories.
*    --sound-levels runs it too, and writes for each frame how loud each chip and the window port's mix of
*    them are, and how many of the mix's samples pass 16 bits (write_levels). SEGASONIC_VIDEO_WORKERS=N in
*    the environment draws the video's rows on N threads beside this one (runtime/src/workers.c), as the
*    ports do: the frames are the same, which the checks show.
*    --actions (the console build) presses the console's actions in the frames a file names, as the window
*    port's keys do: the menus, OPTIONS, the map (tools/make_screenshots.py); and section+ and section-, the
*    window's F8 and F7, move the camera to the stage's section after or before.
*/
#include "s32/machine.h"
#include "s32/program.h"
#include "s32/script.h"
#include "s32/video.h"
#include "s32/workers.h"
#include "sound/chips.h"
#include "game/data.h"
#include "game/extract.h"
#include "s32/bus.h"
#ifdef SEGASONIC_CONSOLE
#include "console.h"
#endif

#if defined(__CELLOS_LV2__) || defined(__SNC__) || defined(__PS3__)
#include <PSGL/psgl.h>
#include <PSGL/psglu.h>
#include <cell/pad.h>
#include <cell/audio.h>
#endif

#include <inttypes.h>
#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef SEGASONIC_CONSOLE
#define USAGE_ACTIONS " [--actions FILE]"
#else
#define USAGE_ACTIONS ""
#endif
#define USAGE "Usage: sonic_headless [--frames N] [--hashes FILE] [--script FILE]" \
	" [--dump-frame N --dump-dir DIR] [--video-hashes FILE] [--video-dump N ... --video-dir DIR]" \
	" [--sound-hashes FILE] [--sound-levels FILE] [--sprite-census FILE] [--tile-census FILE] [--memory-census FILE] [--wide]" \
	" [--assets FILE] [--extract ROM_SET]" USAGE_ACTIONS "\n"
#define ASSETS_FILE "segasonic.assets"
#define MAX_VIDEO_DUMPS 64
#define CENSUS_SLOTS (1u << 20)

static jmp_buf finished;
static uint64_t frames_wanted = 600;
static bool wide_video;    /* --wide: the video's wide picture (s32_video_set_wide) */
static FILE *hashes;
static s32_script *script;
static uint64_t dump_frame = UINT64_MAX;
static const char *dump_dir;
static FILE *video_hashes;
static uint64_t video_dumps[MAX_VIDEO_DUMPS];
static int video_dump_count;
static const char *video_dir;
static FILE *sound_hashes;
static FILE *sound_levels;
static FILE *sprite_census;
static uint64_t *census_seen;    /* hashes of the sprite and color sets written, open addressing (0 = free) */

/* --sprite-census: every sprite of the ROM the list draws, with the colors its pens show, once per set of
colors and way of drawing it: "ADDRESS WORDS ROWS BITS OPAQUE COLOR..." (hex; OPAQUE 1 when it draws the
end code and goes on past it, else 0; colors RGB555, one a pen) */
static void on_sprite_drawn(uint32_t address, int words, int rows, bool bits8, bool opaque, const uint16_t *pixels)
{
	const int pens = bits8 ? 256 : 16;
	uint16_t colors[256];
	uint64_t hash = 0xcbf29ce484222325ull;
	uint32_t slot;

	for (int pen = 0; pen < pens; pen++)
		colors[pen] = s32_video_sprite_pixel_color(pixels[pen]);
	hash = (hash ^ address) * 0x100000001b3ull;
	hash = (hash ^ (uint64_t)((uint32_t)words << 16 | (uint32_t)rows << 2 | (opaque ? 2u : 0u) | (bits8 ? 1u : 0u)))
		* 0x100000001b3ull;
	for (int pen = 0; pen < pens; pen++)
		hash = (hash ^ colors[pen]) * 0x100000001b3ull;
	if (hash == 0)
		hash = 1;
	for (slot = (uint32_t)hash & (CENSUS_SLOTS - 1); census_seen[slot] != 0; slot = (slot + 1) & (CENSUS_SLOTS - 1))
	if (census_seen[slot] == hash)
		return;
	census_seen[slot] = hash;
	fprintf(sprite_census, "%06X %d %d %d %d", address, words, rows, bits8 ? 8 : 4, opaque ? 1 : 0);
	for (int pen = 0; pen < pens; pen++)
		fprintf(sprite_census, " %04X", colors[pen]);
	fputc('\n', sprite_census);
}

/* --tile-census: every tile the tilemaps that are on show (every TILE_CENSUS_EVERY frames), with the colors
its pens show, once per set of colors: "TILE COLOR TILEMAP COLOR..." (hex; colors RGB555, one a pen) */
#define TILE_CENSUS_EVERY 30
static FILE *tile_census;
static uint64_t *tile_census_seen;

static void on_tile_shown(int tilemap, uint32_t tile, uint16_t color)
{
	uint16_t colors[16];
	uint64_t hash = 0xcbf29ce484222325ull;
	uint32_t slot;

	if (program_frames() % TILE_CENSUS_EVERY != 0)
		return;
	for (int pen = 0; pen < 16; pen++)
		colors[pen] = s32_video_tile_pen_color(tilemap, color, pen);
	hash = (hash ^ tile) * 0x100000001b3ull;
	for (int pen = 0; pen < 16; pen++)
		hash = (hash ^ colors[pen]) * 0x100000001b3ull;
	if (hash == 0)
		hash = 1;
	for (slot = (uint32_t)hash & (CENSUS_SLOTS - 1); tile_census_seen[slot] != 0; slot = (slot + 1) & (CENSUS_SLOTS - 1))
	if (tile_census_seen[slot] == hash)
		return;
	tile_census_seen[slot] = hash;
	fprintf(tile_census, "%04X %03X %d", tile, color, tilemap);
	for (int pen = 0; pen < 16; pen++)
		fprintf(tile_census, " %04X", colors[pen]);
	fputc('\n', tile_census);
}

static void write_file(const char *name, const void *data, size_t size)
{
	char path[1024];
	FILE *output;

	snprintf(path, sizeof(path), "%s/%s", dump_dir, name);
	output = fopen(path, "wb");
	if (!output)
	{
		fprintf(stderr, "%s: cannot write\n", path);
		return;
	}
	fwrite(data, 1, size, output);
	fclose(output);
}

static void dump_state(void)
{
	write_file("work_ram.bin", s32_board.work_ram, sizeof(s32_board.work_ram));
	write_file("video_ram.bin", s32_board.video_ram, sizeof(s32_board.video_ram));
	write_file("sprite_ram.bin", s32_board.sprite_ram, sizeof(s32_board.sprite_ram));
	write_file("palette.bin", s32_board.palette, sizeof(s32_board.palette));
	write_file("mixer.bin", s32_board.mixer, sizeof(s32_board.mixer));
	write_file("shared_ram.bin", s32_board.shared_ram, sizeof(s32_board.shared_ram));
	write_file("eeprom.bin", s32_board.eeprom.data, sizeof(s32_board.eeprom.data));
}

/* The last frame the video drew, as a 24-bit BMP */
static void write_bmp(const char *path)
{
	int width;
	const uint32_t *pixels = s32_video_frame(&width);
	const uint32_t row = ((uint32_t)width * 3 + 3) & ~3u;
	const uint32_t size = 54 + row * S32_VIDEO_HEIGHT;
	uint8_t *file = (uint8_t *)calloc(size, 1);
	FILE *output;

	if (!file)
		return;
	for (int byte = 0; byte < 4; byte++)
	{
		file[2 + byte] = (uint8_t)(size >> (8 * byte));
		file[18 + byte] = (uint8_t)((uint32_t)width >> (8 * byte));
		file[22 + byte] = (uint8_t)((uint32_t)S32_VIDEO_HEIGHT >> (8 * byte));
	}
	file[0] = 'B';
	file[1] = 'M';
	file[10] = 54;
	file[14] = 40;
	file[26] = 1;
	file[28] = 24;
	for (int y = 0; y < S32_VIDEO_HEIGHT; y++)
	for (int x = 0; x < width; x++)
	{
		const uint32_t pixel = pixels[y * S32_VIDEO_MAX_WIDTH + x];
		uint8_t *out = &file[54 + (uint32_t)(S32_VIDEO_HEIGHT - 1 - y) * row + (uint32_t)x * 3];

		out[0] = (uint8_t)pixel;
		out[1] = (uint8_t)(pixel >> 8);
		out[2] = (uint8_t)(pixel >> 16);
	}
	output = fopen(path, "wb");
	if (output)
	{
		fwrite(file, 1, size, output);
		fclose(output);
	}
	else
		fprintf(stderr, "%s: cannot write\n", path);
	free(file);
}

static void on_irq_changed(bool asserted)
{
	program_irq_line(asserted);
}

static void on_log(const char *message)
{
	fprintf(stderr, "[s32] %s\n", message);
}

/* --sound-levels: the frame's loudest sample of each chip (FM0, FM1: the YM3438s; PCM: the RF5C68) and of
their mix as the window port makes it (each YM3438 at 0.30, the RF5C68 at 0.40, volume 1; the RF5C68's
samples taken at the YM3438s' times), how many of the mix's samples pass 16 bits, and how many of the
RF5C68's are at its own limit (it sums its channels into 16 bits): "FRAME FM0 FM1 PCM MIX CLIPPED PCM_LIMIT" */
static void write_levels(void)
{
	const int32_t *samples[3];
	size_t counts[3];
	int32_t peaks[3] = { 0 };
	double mix_peak = 0.0;
	unsigned clipped = 0, pcm_limit = 0;

	for (int chip = 0; chip < 3; chip++)
	{
		samples[chip] = sound_chips_frame_samples(chip, &counts[chip]);
		for (size_t at = 0; at < counts[chip] * 2; at++)
		{
			if (abs(samples[chip][at]) > peaks[chip])
				peaks[chip] = abs(samples[chip][at]);
			if (chip == 2 && (samples[chip][at] >= 32767 || samples[chip][at] <= -32767))
				pcm_limit++;
		}
	}
	for (size_t at = 0; counts[1] && counts[2] && at < counts[0]; at++)
	{
		const size_t fm1 = at < counts[1] ? at : counts[1] - 1, pcm = at * counts[2] / counts[0];

		for (int side = 0; side < 2; side++)
		{
			const double value = 0.30 * (samples[0][at * 2 + side] + samples[1][fm1 * 2 + side])
				+ 0.40 * samples[2][pcm * 2 + side];

			if (value > mix_peak || -value > mix_peak)
				mix_peak = value < 0 ? -value : value;
			if (value > 32767.0 || value < -32768.0)
				clipped++;
		}
	}
	fprintf(sound_levels, "%" PRIu64 " %d %d %d %.0f %u %u\n", program_frames() - 1, peaks[0], peaks[1], peaks[2],
		mix_peak, clipped, pcm_limit);
}

#if defined(__CELLOS_LV2__) || defined(__SNC__) || defined(__PS3__)
static bool ps3_graphics_initialized = false;
static PSGLdevice* ps3_device = NULL;
static PSGLcontext* ps3_context = NULL;
static GLuint ps3_texture = 0;
static uint32_t ps3_audio_port = 0xFFFFFFFF;
static bool ps3_pad_initialized = false;
static bool ps3_pause_requested = false;
static CellPadData last_ps3_pads[3];
static uint32_t last_ps3_held[3] = { 0 };

#define PS3_OUTPUT_RATE 48000
static const double PS3_FM_RATE = S32_SOUND_CLOCK / 144.0;
static const double PS3_PCM_RATE = S32_PCM_CLOCK / 384.0;

typedef struct ps3_resampler
{
	double step;
	double position;
	int32_t *samples;
	size_t count;
	size_t capacity;
} ps3_resampler;

static ps3_resampler ps3_chips[3];

static void ps3_get_save_path(const char *filename, char *out_path, size_t size)
{
	FILE *f = fopen("/dev_hdd0/game/SEGASONIC/USRDIR/segasonic.assets", "rb");
	if (f)
	{
		fclose(f);
		snprintf(out_path, size, "/dev_hdd0/game/SEGASONIC/USRDIR/%s", filename);
		return;
	}
	snprintf(out_path, size, "USRDIR/%s", filename);
}

static void ps3_load_eeprom(void)
{
	char path[1024];
	size_t size;
	FILE *input;

	ps3_get_save_path("segasonic.eeprom", path, sizeof(path));
	input = fopen(path, "rb");
	if (!input)
	{
		ps3_get_save_path("sonic.eeprom", path, sizeof(path));
		input = fopen(path, "rb");
	}
	if (input)
	{
		fseek(input, 0, SEEK_END);
		size = ftell(input);
		fseek(input, 0, SEEK_SET);
		if (size == sizeof(s32_board.eeprom.data))
			fread(s32_board.eeprom.data, 1, size, input);
		fclose(input);
	}
}

static void ps3_save_eeprom(void)
{
	char path[1024];
	FILE *output;

	if (!s32_board.eeprom.dirty)
		return;
	ps3_get_save_path("segasonic.eeprom", path, sizeof(path));
	output = fopen(path, "wb");
	if (output)
	{
		fwrite(s32_board.eeprom.data, 1, sizeof(s32_board.eeprom.data), output);
		fclose(output);
		s32_board.eeprom.dirty = false;
	}
}

#ifdef SEGASONIC_CONSOLE
static void ps3_load_times(void)
{
	char path[1024];
	FILE *input;
	int level = 0;
	unsigned long frames = 0;
	char line[128];

	ps3_get_save_path("segasonic.times", path, sizeof(path));
	input = fopen(path, "r");
	if (!input)
		return;
	while (fgets(line, sizeof(line), input))
	{
		if (sscanf(line, " level %d = %lu", &level, &frames) == 2 && level >= 0 && level < CONSOLE_LEVELS)
			console_best_times.levels[level] = (uint32_t)frames;
		else if (sscanf(line, " run %d = %lu", &level, &frames) == 2 && level >= 0 && level < CONSOLE_LEVELS)
			console_best_times.run[level] = (uint32_t)frames;
	}
	fclose(input);
}

static void ps3_save_times(void)
{
	char path[1024];
	FILE *output;

	if (!console_best_times.changed)
		return;
	ps3_get_save_path("segasonic.times", path, sizeof(path));
	output = fopen(path, "w");
	console_best_times.changed = false;
	if (!output)
		return;
	fputs("; TIME ATTACK's best times\n", output);
	for (int level = 0; level < CONSOLE_LEVELS; level++)
		fprintf(output, "level %d = %lu\n", level, (unsigned long)console_best_times.levels[level]);
	for (int level = 0; level < CONSOLE_LEVELS; level++)
		fprintf(output, "run %d = %lu\n", level, (unsigned long)console_best_times.run[level]);
	fclose(output);
}

static void ps3_tell_console_settings(void)
{
	console_window_settings.window_scale = 2;
	console_window_settings.full_screen = true;
	console_window_settings.smooth = true;
	console_window_settings.bilinear = false;
	console_window_settings.crt = false;
	console_window_settings.wide = wide_video;
	console_window_settings.volume = 5;
	console_window_settings.title_music = 0;
	console_window_settings.continues = 3;
	console_window_settings.changed = false;
}
#endif

static void ps3_resampler_keep(ps3_resampler *chip, const int32_t *samples, size_t count)
{
	if (chip->count + count > chip->capacity)
	{
		chip->capacity = (chip->count + count) * 2;
		chip->samples = (int32_t *)realloc(chip->samples, chip->capacity * 2 * sizeof(int32_t));
	}
	if (chip->samples)
	{
		memcpy(chip->samples + chip->count * 2, samples, count * 2 * sizeof(int32_t));
		chip->count += count;
	}
}

static void ps3_resampler_sample_at(const ps3_resampler *chip, double position, double out[2])
{
	const size_t index = (size_t)position;
	const double fraction = position - (double)index;

	for (int side = 0; side < 2; side++)
	{
		const double here = chip->samples[index * 2 + side];
		const double next = chip->samples[(index + 1) * 2 + side];
		out[side] = here + (next - here) * fraction;
	}
}

static void ps3_resampler_drop_used(ps3_resampler *chip)
{
	const size_t used = (size_t)chip->position;

	if (!used)
		return;
	memmove(chip->samples, chip->samples + used * 2, (chip->count - used) * 2 * sizeof(int32_t));
	chip->count -= used;
	chip->position -= (double)used;
}

static void ps3_graphics_init(void)
{
	PSGLinitOptions options;
	PSGLdeviceParameters params;

	memset(&options, 0, sizeof(options));
	options.enable = PSGL_INIT_MAX_SPUS | PSGL_INIT_INITIALIZE_SPUS | PSGL_INIT_HOST_MEMORY_SIZE;
	options.maxSPUs = 0;
	options.initializeSPUs = false;
	options.hostMemorySize = 4 * 1024 * 1024;

	psglInit(&options);

	memset(&params, 0, sizeof(params));
	params.enable = PSGL_DEVICE_PARAMETERS_COLOR_FORMAT | PSGL_DEVICE_PARAMETERS_DEPTH_FORMAT | PSGL_DEVICE_PARAMETERS_BUFFERING_MODE;
	params.bufferingMode = PSGL_BUFFERING_MODE_TRIPLE;
	params.colorFormat = GL_ARGB_SCE;
	params.depthFormat = GL_NONE;

	ps3_device = psglCreateDeviceExtended(&params);
	ps3_context = psglCreateContext();
	psglMakeCurrent(ps3_context, ps3_device);

	glGenTextures(1, &ps3_texture);
	glBindTexture(GL_TEXTURE_2D, ps3_texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	ps3_graphics_initialized = true;
}

static void ps3_audio_init(void)
{
	if (cellAudioInit() == CELL_OK || cellAudioInit() == CELL_AUDIO_ERROR_ALREADY_INIT)
	{
		CellAudioPortParam portParam;
		memset(&portParam, 0, sizeof(portParam));
		portParam.nChannel = CELL_AUDIO_PORT_2CH;
		portParam.nBlock = 8;
		portParam.attr = 0;
		if (cellAudioPortOpen(&portParam, &ps3_audio_port) == CELL_OK)
		{
			cellAudioPortStart(ps3_audio_port);
			cellAudioSetPortLevel(ps3_audio_port, 1.0f);
		}
	}
	ps3_chips[0].step = ps3_chips[1].step = PS3_FM_RATE / PS3_OUTPUT_RATE;
	ps3_chips[2].step = PS3_PCM_RATE / PS3_OUTPUT_RATE;
}

static void ps3_graphics_render_frame(void)
{
	int width = 0;
	const uint32_t *pixels;
	GLuint deviceWidth = 1280, deviceHeight = 720;

	if (!ps3_graphics_initialized) return;
	pixels = s32_video_frame(&width);
	if (!pixels || width <= 0) return;

	glBindTexture(GL_TEXTURE_2D, ps3_texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_ARGB_SCE, S32_VIDEO_MAX_WIDTH, S32_VIDEO_HEIGHT, 0, GL_ARGB_SCE, GL_UNSIGNED_INT_8_8_8_8_REV, pixels);

	psglGetDeviceDimensions(ps3_device, &deviceWidth, &deviceHeight);

	bool is_wide = (width > 320);
	GLint viewX = 0, viewY = 0, viewW = (GLint)deviceWidth, viewH = (GLint)deviceHeight;

	if (!is_wide)
	{
		viewH = (GLint)deviceHeight;
		viewW = (GLint)(viewH * (4.0f / 3.0f));
		if (viewW > (GLint)deviceWidth)
		{
			viewW = (GLint)deviceWidth;
			viewH = (GLint)(viewW * (3.0f / 4.0f));
		}
		viewX = ((GLint)deviceWidth - viewW) / 2;
		viewY = ((GLint)deviceHeight - viewH) / 2;
	}

	glViewport(viewX, viewY, viewW, viewH);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrthof(0.0f, 1.0f, 0.0f, 1.0f, -1.0f, 1.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glEnable(GL_TEXTURE_2D);

	float u1 = (float)width / (float)S32_VIDEO_MAX_WIDTH;

	GLfloat vertices[] = { 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f };
	GLfloat texcoords[] = { 0.0f, 1.0f, u1, 1.0f, u1, 0.0f, 0.0f, 0.0f };

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glVertexPointer(2, GL_FLOAT, 0, vertices);
	glTexCoordPointer(2, GL_FLOAT, 0, texcoords);

	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisable(GL_TEXTURE_2D);

	psglSwap();
}

static void ps3_audio_render_frame(void)
{
	static float floatBuffer[PS3_OUTPUT_RATE / 60 * 2];
	size_t made = 0;

	if (ps3_audio_port == 0xFFFFFFFF) return;

	s32_board.time_passes(s32_board.cycles);
	sound_chips_end_frame(s32_board.cycles);

	for (int chip = 0; chip < 3; chip++)
	{
		size_t count;
		const int32_t *samples = sound_chips_frame_samples(chip, &count);
		ps3_resampler_keep(&ps3_chips[chip], samples, count);
	}

	while (made < PS3_OUTPUT_RATE / 60)
	{
		double fm0[2], fm1[2], pcm[2];

		if (ps3_chips[0].position + 1 >= (double)ps3_chips[0].count
			|| ps3_chips[1].position + 1 >= (double)ps3_chips[1].count
			|| ps3_chips[2].position + 1 >= (double)ps3_chips[2].count)
			break;

		ps3_resampler_sample_at(&ps3_chips[0], ps3_chips[0].position, fm0);
		ps3_resampler_sample_at(&ps3_chips[1], ps3_chips[1].position, fm1);
		ps3_resampler_sample_at(&ps3_chips[2], ps3_chips[2].position, pcm);

		for (int side = 0; side < 2; side++)
		{
			double value = 0.30 * (fm0[side] + fm1[side]) + 0.40 * pcm[side];
			float fval = (float)(value / 32768.0);
			if (fval > 1.0f) fval = 1.0f;
			if (fval < -1.0f) fval = -1.0f;
			floatBuffer[made * 2 + side] = fval;
		}

		for (int chip = 0; chip < 3; chip++)
			ps3_chips[chip].position += ps3_chips[chip].step;
		made++;
	}

	for (int chip = 0; chip < 3; chip++)
		ps3_resampler_drop_used(&ps3_chips[chip]);

	if (made > 0)
		cellAudioAdd2chData(ps3_audio_port, floatBuffer, (uint32_t)made, 1.0f);
}

static void ps3_pad_update(void)
{
	if (!ps3_pad_initialized)
	{
		cellPadInit(7);
		ps3_pad_initialized = true;
	}

	uint32_t global_pressed = 0;
	uint32_t global_held = 0;

	for (int p = 0; p < 3; p++)
	{
		CellPadData padData;
		if (cellPadGetData(p, &padData) == CELL_PAD_OK && padData.len > 0)
		{
			last_ps3_pads[p] = padData;
		}

		if (last_ps3_pads[p].len <= 0) continue;

		uint16_t digital1 = last_ps3_pads[p].button[CELL_PAD_BTN_OFFSET_DIGITAL1];
		uint16_t digital2 = last_ps3_pads[p].button[CELL_PAD_BTN_OFFSET_DIGITAL2];
		uint32_t held = 0;

		int stickX = (int)(last_ps3_pads[p].button[CELL_PAD_BTN_OFFSET_ANALOG_LEFT_X] & 0xFF) - 128;
		int stickY = (int)(last_ps3_pads[p].button[CELL_PAD_BTN_OFFSET_ANALOG_LEFT_Y] & 0xFF) - 128;
		int rstickX = (int)(last_ps3_pads[p].button[CELL_PAD_BTN_OFFSET_ANALOG_RIGHT_X] & 0xFF) - 128;
		int rstickY = (int)(last_ps3_pads[p].button[CELL_PAD_BTN_OFFSET_ANALOG_RIGHT_Y] & 0xFF) - 128;

		int roll_x = 0, roll_y = 0;
		if (abs(stickX) > 20) roll_x += (stickX > 0) ? (stickX - 20) / 8 : (stickX + 20) / 8;
		if (abs(stickY) > 20) roll_y += (stickY > 0) ? (stickY - 20) / 8 : (stickY + 20) / 8;
		if (abs(rstickX) > 20) roll_x += (rstickX > 0) ? (rstickX - 20) / 8 : (rstickX + 20) / 8;
		if (abs(rstickY) > 20) roll_y += (rstickY > 0) ? (rstickY - 20) / 8 : (rstickY + 20) / 8;

		if (digital1 & CELL_PAD_CTRL_UP) { held |= ACTION_BIT(ACTION_UP); roll_y -= 8; }
		if (digital1 & CELL_PAD_CTRL_DOWN) { held |= ACTION_BIT(ACTION_DOWN); roll_y += 8; }
		if (digital1 & CELL_PAD_CTRL_LEFT) { held |= ACTION_BIT(ACTION_LEFT); roll_x -= 8; }
		if (digital1 & CELL_PAD_CTRL_RIGHT) { held |= ACTION_BIT(ACTION_RIGHT); roll_x += 8; }

		s32_board.input.trackball_x[p] = (uint16_t)(s32_board.input.trackball_x[p] + roll_x);
		s32_board.input.trackball_y[p] = (uint16_t)(s32_board.input.trackball_y[p] + roll_y);

		bool jump_btn = (digital2 & (CELL_PAD_CTRL_CROSS | CELL_PAD_CTRL_CIRCLE | CELL_PAD_CTRL_SQUARE)) != 0;
		if (jump_btn)
		{
			held |= ACTION_BIT(ACTION_ACCEPT) | ACTION_BIT(ACTION_JUMP);
			if (p == 0) s32_board.input.port_a &= (uint8_t)~0x01u;
			else if (p == 1) s32_board.input.port_b &= (uint8_t)~0x01u;
			else if (p == 2) s32_board.input.port_a &= (uint8_t)~0x04u;
		}
		else
		{
			if (p == 0) s32_board.input.port_a |= 0x01u;
			else if (p == 1) s32_board.input.port_b |= 0x01u;
			else if (p == 2) s32_board.input.port_a |= 0x04u;
		}

		if (digital2 & (CELL_PAD_CTRL_TRIANGLE | CELL_PAD_CTRL_L1 | CELL_PAD_CTRL_R1))
		{
			held |= ACTION_BIT(ACTION_BACK);
		}

		if (digital1 & CELL_PAD_CTRL_START)
		{
			held |= ACTION_BIT(ACTION_START);
#ifdef SEGASONIC_CONSOLE
			if (p == 0 && console_in_game() && !console_start_prompted(0))
			{
			}
			else
#endif
			{
				if (p == 0) s32_board.input.port_e &= (uint8_t)~0x10u;
				else if (p == 1) s32_board.input.port_e &= (uint8_t)~0x20u;
				else if (p == 2) s32_board.input.port_e &= (uint8_t)~0x80u;
			}
		}
		else
		{
			if (p == 0) s32_board.input.port_e |= 0x10u;
			else if (p == 1) s32_board.input.port_e |= 0x20u;
			else if (p == 2) s32_board.input.port_e |= 0x80u;
		}

		if (digital1 & CELL_PAD_CTRL_SELECT)
		{
			if (p == 0) s32_board.input.port_e &= (uint8_t)~0x04u;
			else if (p == 1) s32_board.input.port_e &= (uint8_t)~0x08u;
			else if (p == 2) s32_board.input.port_e &= (uint8_t)~0x40u;
		}
		else
		{
			if (p == 0) s32_board.input.port_e |= 0x04u;
			else if (p == 1) s32_board.input.port_e |= 0x08u;
			else if (p == 2) s32_board.input.port_e |= 0x40u;
		}

		if (p == 0)
		{
			if (digital2 & CELL_PAD_CTRL_L2) s32_board.input.port_e &= (uint8_t)~0x08u;
			if (digital2 & CELL_PAD_CTRL_R2) s32_board.input.port_e &= (uint8_t)~0x02u;
			else s32_board.input.port_e |= 0x02u;
			if (digital2 & (CELL_PAD_CTRL_L3 | CELL_PAD_CTRL_R3)) s32_board.input.port_e &= (uint8_t)~0x01u;
			else s32_board.input.port_e |= 0x01u;
		}

		uint32_t pressed = held & ~last_ps3_held[p];
		last_ps3_held[p] = held;

		if (p == 0)
		{
			global_pressed = pressed;
			global_held = held;

#ifdef SEGASONIC_CONSOLE
			if (console_in_game() && !console_start_prompted(0) && (pressed & ACTION_BIT(ACTION_START)))
			{
				ps3_pause_requested = true;
			}
#endif
		}
	}

#ifdef SEGASONIC_CONSOLE
	if (!console_in_game() && (global_pressed & ACTION_BIT(ACTION_BACK)))
		console_back();
	console_actions(global_pressed, global_held);
	s32_video_set_wide(console_wide_now());
#endif
}

#ifdef SEGASONIC_CONSOLE
static uint32_t ps3_pause_picture[S32_VIDEO_MAX_WIDTH * S32_VIDEO_HEIGHT];

static void ps3_draw_pause_picture(int *width)
{
	const uint32_t *pixels;

	console_draw_frame();
	pixels = s32_video_frame(width);
	memcpy(ps3_pause_picture, pixels, sizeof(ps3_pause_picture));
	console_pause_text(true);
	console_draw_frame();
	pixels = s32_video_frame(width);
	for (size_t i = 0; i < sizeof(ps3_pause_picture) / sizeof(ps3_pause_picture[0]); i++)
	{
		const uint32_t color = ps3_pause_picture[i];
		uint32_t grey;

		if (pixels[i] != color)
		{
			ps3_pause_picture[i] = pixels[i];
			continue;
		}
		grey = ((((color >> 16) & 0xFF) * 77 + ((color >> 8) & 0xFF) * 150 + (color & 0xFF) * 29) >> 8) * 3 / 4;
		ps3_pause_picture[i] = 0xFF000000u | (grey << 16) | (grey << 8) | grey;
	}
	console_pause_text(false);
	console_draw_frame();
}

static void ps3_run_pause(void)
{
	int width = 320;
	bool paused = true;

	ps3_pause_requested = false;
	ps3_draw_pause_picture(&width);

	while (paused)
	{
		CellPadData padData;
		if (cellPadGetData(0, &padData) == CELL_PAD_OK && padData.len > 0)
		{
			uint16_t digital1 = padData.button[CELL_PAD_BTN_OFFSET_DIGITAL1];
			uint16_t digital2 = padData.button[CELL_PAD_BTN_OFFSET_DIGITAL2];
			uint32_t held = 0;

			if (digital1 & CELL_PAD_CTRL_START) held |= ACTION_BIT(ACTION_START);
			if (digital2 & (CELL_PAD_CTRL_CROSS | CELL_PAD_CTRL_CIRCLE | CELL_PAD_CTRL_SQUARE)) held |= ACTION_BIT(ACTION_ACCEPT);

			uint32_t pressed = held & ~last_ps3_held[0];
			last_ps3_held[0] = held;

			if (pressed & (ACTION_BIT(ACTION_START) | ACTION_BIT(ACTION_ACCEPT)))
			{
				paused = false;
			}
		}

		if (ps3_graphics_initialized)
		{
			GLuint deviceWidth = 1280, deviceHeight = 720;
			glBindTexture(GL_TEXTURE_2D, ps3_texture);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_ARGB_SCE, S32_VIDEO_MAX_WIDTH, S32_VIDEO_HEIGHT, 0, GL_ARGB_SCE, GL_UNSIGNED_INT_8_8_8_8_REV, ps3_pause_picture);

			psglGetDeviceDimensions(ps3_device, &deviceWidth, &deviceHeight);

			GLint viewX = 0, viewY = 0, viewW = (GLint)deviceWidth, viewH = (GLint)deviceHeight;
			if (width <= 320)
			{
				viewH = (GLint)deviceHeight;
				viewW = (GLint)(viewH * (4.0f / 3.0f));
				if (viewW > (GLint)deviceWidth)
				{
					viewW = (GLint)deviceWidth;
					viewH = (GLint)(viewW * (3.0f / 4.0f));
				}
				viewX = ((GLint)deviceWidth - viewW) / 2;
				viewY = ((GLint)deviceHeight - viewH) / 2;
			}
			glViewport(viewX, viewY, viewW, viewH);

			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			glOrthof(0.0f, 1.0f, 0.0f, 1.0f, -1.0f, 1.0f);
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();

			glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			glEnable(GL_TEXTURE_2D);

			float u1 = (float)width / (float)S32_VIDEO_MAX_WIDTH;
			GLfloat vertices[] = { 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f };
			GLfloat texcoords[] = { 0.0f, 1.0f, u1, 1.0f, u1, 0.0f, 0.0f, 0.0f };

			glEnableClientState(GL_VERTEX_ARRAY);
			glEnableClientState(GL_TEXTURE_COORD_ARRAY);
			glVertexPointer(2, GL_FLOAT, 0, vertices);
			glTexCoordPointer(2, GL_FLOAT, 0, texcoords);

			glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

			glDisableClientState(GL_TEXTURE_COORD_ARRAY);
			glDisableClientState(GL_VERTEX_ARRAY);
			glDisable(GL_TEXTURE_2D);

			psglSwap();
		}
	}
}
#endif
#endif

static void on_frame_done(void)
{
#if defined(__CELLOS_LV2__) || defined(__SNC__) || defined(__PS3__)
	ps3_graphics_render_frame();
	ps3_audio_render_frame();
#ifdef SEGASONIC_CONSOLE
	if (console_quit_requested())
		longjmp(finished, 1);
	if (console_window_settings.changed)
	{
		wide_video = console_window_settings.wide;
		s32_video_set_wide(wide_video);
		console_window_settings.changed = false;
	}
	ps3_tell_console_settings();
	if (ps3_pause_requested)
		ps3_run_pause();
	if (console_best_times.changed)
		ps3_save_times();
#endif
	if (program_frames() % 600 == 0)
		ps3_save_eeprom();
#endif
	if (hashes)
		fprintf(hashes, "%" PRIu64 " %016" PRIx64 "\n", program_frames() - 1, s32_state_hash());
	if (dump_dir && program_frames() - 1 == dump_frame)
		dump_state();
	if (video_hashes)
		fprintf(video_hashes, "%" PRIu64 " %016" PRIx64 "\n", program_frames() - 1, s32_video_frame_hash());
	if (sound_hashes || sound_levels)
	{
		s32_board.time_passes(s32_board.cycles);
		sound_chips_end_frame(s32_board.cycles);
		if (sound_hashes)
			fprintf(sound_hashes, "%" PRIu64 " %016" PRIx64 " %016" PRIx64 "\n", program_frames() - 1,
			sound_chips_frame_hash(), sound_board_state_hash());
		if (sound_levels)
			write_levels();
	}
	for (int index = 0; index < video_dump_count && video_dir; index++)
	if (video_dumps[index] == program_frames() - 1)
	{
		char path[1024];

		snprintf(path, sizeof(path), "%s/frame_%" PRIu64 ".bmp", video_dir, video_dumps[index]);
		write_bmp(path);
	}
#if !defined(__CELLOS_LV2__) && !defined(__SNC__) && !defined(__PS3__)
	if (program_frames() >= frames_wanted)
		longjmp(finished, 1);
#endif
}

#ifdef SEGASONIC_CONSOLE
/* --actions: the console's actions (console_actions.h) a file presses, as the window port's keys do, one a
line: "FRAME ACTION [FRAMES]", FRAME a frame number or +N for N frames after the previous line, held FRAMES
frames (1 by default) and pressed on the first; '#' starts a comment */
#define MAX_ACTION_EVENTS 1024

static struct
{
	uint64_t frame, frames;
	console_action action;
	int section;          /* section+ (1) or section- (-1) instead of an action: the window's F8 and F7 */
} action_events[MAX_ACTION_EVENTS];
static int action_event_count;

static const char *const action_names[ACTIONS] = { "up", "down", "left", "right", "accept", "back", "start", "jump" };

static bool load_actions(const char *path)
{
	FILE *input = fopen(path, "r");
	char line[256];
	uint64_t previous = 0;
	int number = 0;

	if (!input)
	{
		fprintf(stderr, "%s: cannot be read\n", path);
		return false;
	}
	while (fgets(line, sizeof(line), input))
	{
		char when[32], name[32];
		unsigned long long frames = 1;
		char *comment = strchr(line, '#');
		int fields, action = 0, section;

		number++;
		if (comment)
			*comment = '\0';
		fields = sscanf(line, "%31s %31s %llu", when, name, &frames);
		if (fields <= 0)
			continue;
		while (fields >= 2 && action < ACTIONS && strcmp(name, action_names[action]) != 0)
			action++;
		section = fields < 2 ? 0 : (strcmp(name, "section+") == 0 ? 1 : (strcmp(name, "section-") == 0 ? -1 : 0));
		if (fields < 2 || (action == ACTIONS && !section) || frames == 0 || action_event_count == MAX_ACTION_EVENTS)
		{
			fprintf(stderr, "%s:%d: not an action line\n", path, number);
			fclose(input);
			return false;
		}
		previous = when[0] == '+' ? previous + strtoull(when + 1, NULL, 10) : strtoull(when, NULL, 10);
		action_events[action_event_count].frame = previous;
		action_events[action_event_count].frames = frames;
		action_events[action_event_count].action = (console_action)(section ? 0 : action);
		action_events[action_event_count].section = section;
		action_event_count++;
	}
	fclose(input);
	return true;
}

static bool actions_hold_start, actions_hold_button;    /* player 1's start and button, held by the actions */

/* The frame's actions, as the window port hands them over (ports/sdl2/main.c): start is player 1's start
button too outside a game (or with their start prompt up), jump their button */
static void apply_actions(uint64_t frame)
{
	uint32_t pressed = 0, held = 0;
	bool start, button;

	for (int index = 0; index < action_event_count; index++)
	if (action_events[index].section)
	{
		if (frame == action_events[index].frame)
			console_debug_section(action_events[index].section);
	}
	else if (frame >= action_events[index].frame && frame - action_events[index].frame < action_events[index].frames)
	{
		held |= ACTION_BIT(action_events[index].action);
		if (frame == action_events[index].frame)
			pressed |= ACTION_BIT(action_events[index].action);
	}
	start = (held & ACTION_BIT(ACTION_START)) && (!console_in_game() || console_start_prompted(0));
	button = (held & ACTION_BIT(ACTION_JUMP)) != 0;
	/* (the ports are active low; a button the actions held is released when they let go of it) */
	if (start)
		s32_board.input.port_e &= (uint8_t)~0x10u;
	else if (actions_hold_start)
		s32_board.input.port_e |= 0x10u;
	if (button)
		s32_board.input.port_a &= (uint8_t)~0x01u;
	else if (actions_hold_button)
		s32_board.input.port_a |= 0x01u;
	actions_hold_start = start;
	actions_hold_button = button;
	if (!console_in_game() && (pressed & ACTION_BIT(ACTION_BACK)))
		console_back();
	console_actions(pressed, held);
}
#endif


static void on_controls_update(void)
{
	/* VBLANK of the board's frame is starting */
	s32_script_apply(script, s32_board.frame);
#if defined(__CELLOS_LV2__) || defined(__SNC__) || defined(__PS3__)
	ps3_pad_update();
#endif
#ifdef SEGASONIC_CONSOLE
	apply_actions(s32_board.frame);
	if (wide_video)
		s32_video_set_wide(console_wide_now());    /* (as the console's port does: the stages wider) */
#endif
}

int main(int argc, char **argv)
{
	const char *hashes_path = NULL;
	const char *script_path = NULL;
	const char *video_hashes_path = NULL;
	const char *sound_hashes_path = NULL;
	const char *sound_levels_path = NULL;
	const char *sprite_census_path = NULL;
	const char *tile_census_path = NULL;
	const char *memory_census_path = NULL;
	const char *assets_path = NULL;
	const char *extract_source = NULL;
	char beside[1024];
	bool frames_given = false;

	for (int index = 1; index < argc; index++)
	{
		if (strcmp(argv[index], "--frames") == 0 && index + 1 < argc)
		{
			frames_wanted = strtoull(argv[++index], NULL, 10);
			frames_given = true;
		}
		else if (strcmp(argv[index], "--hashes") == 0 && index + 1 < argc)
			hashes_path = argv[++index];
		else if (strcmp(argv[index], "--script") == 0 && index + 1 < argc)
			script_path = argv[++index];
		else if (strcmp(argv[index], "--dump-frame") == 0 && index + 1 < argc)
			dump_frame = strtoull(argv[++index], NULL, 10);
		else if (strcmp(argv[index], "--dump-dir") == 0 && index + 1 < argc)
			dump_dir = argv[++index];
		else if (strcmp(argv[index], "--video-hashes") == 0 && index + 1 < argc)
			video_hashes_path = argv[++index];
		else if (strcmp(argv[index], "--video-dump") == 0 && index + 1 < argc && video_dump_count < MAX_VIDEO_DUMPS)
			video_dumps[video_dump_count++] = strtoull(argv[++index], NULL, 10);
		else if (strcmp(argv[index], "--wide") == 0)
			wide_video = true;
#ifdef SEGASONIC_CONSOLE
		else if (strcmp(argv[index], "--actions") == 0 && index + 1 < argc)
		{
			if (!load_actions(argv[++index]))
				return 1;
		}
#endif
		else if (strcmp(argv[index], "--video-dir") == 0 && index + 1 < argc)
			video_dir = argv[++index];
		else if (strcmp(argv[index], "--sound-hashes") == 0 && index + 1 < argc)
			sound_hashes_path = argv[++index];
		else if (strcmp(argv[index], "--sound-levels") == 0 && index + 1 < argc)
			sound_levels_path = argv[++index];
		else if (strcmp(argv[index], "--sprite-census") == 0 && index + 1 < argc)
			sprite_census_path = argv[++index];
		else if (strcmp(argv[index], "--tile-census") == 0 && index + 1 < argc)
			tile_census_path = argv[++index];
		else if (strcmp(argv[index], "--memory-census") == 0 && index + 1 < argc)
			memory_census_path = argv[++index];
		else if (strcmp(argv[index], "--assets") == 0 && index + 1 < argc)
			assets_path = argv[++index];
		else if (strcmp(argv[index], "--extract") == 0 && index + 1 < argc)
			extract_source = argv[++index];
		else
		{
			fprintf(stderr, USAGE);
			return 1;
		}
	}
#ifdef SEGASONIC_SCAFFOLD
	(void)assets_path;
	(void)beside;
	{
		const char *problem = game_rom_set_load("rom");

		if (problem)
		{
			fprintf(stderr, "rom: %s\n", problem);
			return 1;
		}
	}
#else
	if (!assets_path)
	{
		/* (the executable's folder, as argv[0] gives it) */
		const char *slash = strrchr(argv[0], '/'), *backslash = strrchr(argv[0], '\\');
		const char *last = slash > backslash ? slash : backslash;

		snprintf(beside, sizeof(beside), "%.*s" ASSETS_FILE, last ? (int)(last - argv[0] + 1) : 0, argv[0]);
		assets_path = beside;
	}
	if (extract_source)
	{
		const char *problem = game_data_extract(extract_source, assets_path);

		if (problem)
		{
			fprintf(stderr, "%s: %s\n", extract_source, problem);
			return 1;
		}
	}
	switch (game_data_load(assets_path))
	{
	case GAME_DATA_LOADED:
		break;
	case GAME_DATA_MISSING:
#if defined(__CELLOS_LV2__) || defined(__SNC__) || defined(__PS3__)
	{
							  static const char *const ps3_paths[] = {
								  "/app_home/segasonic.assets",
								  "/app_home/USRDIR/segasonic.assets",
								  "/dev_hdd0/game/SEGASONIC/USRDIR/segasonic.assets",
								  "USRDIR/segasonic.assets",
								  NULL
							  };
							  int p_idx = 0;
							  while (ps3_paths[p_idx])
							  {
								  if (game_data_load(ps3_paths[p_idx]) == GAME_DATA_LOADED)
								  {
									  assets_path = ps3_paths[p_idx];
									  break;
								  }
								  p_idx++;
							  }
							  if (ps3_paths[p_idx])
								  break;
	}
#endif
		fprintf(stderr, "%s: no game assets\n", assets_path);
		return 1;
	default:
		fprintf(stderr, "%s: the game assets cannot be read\n", assets_path);
		return 1;
	}
#endif
	if (script_path)
	{
		char error[256];

		script = s32_script_load(script_path, error, sizeof(error));
		if (!script)
		{
			fprintf(stderr, "%s\n", error);
			return 1;
		}
		if (!frames_given && s32_script_frames(script))
			frames_wanted = s32_script_frames(script);
	}
	if (hashes_path)
		hashes = fopen(hashes_path, "w");
	if (video_hashes_path || video_dump_count || sprite_census_path || tile_census_path)
	{
#ifdef SEGASONIC_CONSOLE
		console_prepare_sprites(game_sprites, GAME_SPRITES_SIZE, game_program);
		s32_video_init(game_tiles, GAME_TILES_SIZE, game_sprites, GAME_SPRITES_SIZE);
		s32_board.frame_shown = console_draw_frame;    /* (WIDE's sides of a stage's map too) */
#else
		s32_video_init(game_tiles, GAME_TILES_SIZE, game_sprites, GAME_SPRITES_SIZE);
#endif
#ifdef SEGASONIC_CONSOLE
		console_window_settings.wide = wide_video;
#else
		s32_video_set_wide(wide_video);
#endif
		if (video_hashes_path)
			video_hashes = fopen(video_hashes_path, "w");
	}
	if (sprite_census_path)
	{
		sprite_census = fopen(sprite_census_path, "w");
		census_seen = calloc(CENSUS_SLOTS, sizeof(*census_seen));
		if (!sprite_census || !census_seen)
		{
			fprintf(stderr, "%s: cannot be written\n", sprite_census_path);
			return 1;
		}
		s32_video_sprite_observer = on_sprite_drawn;
	}
	if (tile_census_path)
	{
		tile_census = fopen(tile_census_path, "w");
		tile_census_seen = calloc(CENSUS_SLOTS, sizeof(*tile_census_seen));
		if (!tile_census || !tile_census_seen)
		{
			fprintf(stderr, "%s: cannot be written\n", tile_census_path);
			return 1;
		}
		s32_video_tile_observer = on_tile_shown;
	}
	if (sound_hashes_path || sound_levels_path)
	{
		s32_board.sound_rom = game_sound;
		sound_chips_attach();
		sound_cpu_attach();
		if (sound_hashes_path)
			sound_hashes = fopen(sound_hashes_path, "w");
		if (sound_levels_path)
			sound_levels = fopen(sound_levels_path, "w");
	}

	s32_board.irq_changed = on_irq_changed;
	s32_board.controls_update = on_controls_update;
	s32_board.log = on_log;
	s32_board.frame_timing = true;
	/* (the video's rows on that many threads beside this one: the same frames, which the checks show) */
#if !defined(__CELLOS_LV2__) && !defined(__SNC__) && !defined(__PS3__)
	if (getenv("SEGASONIC_VIDEO_WORKERS"))
		s32_workers_start(atoi(getenv("SEGASONIC_VIDEO_WORKERS")));
#else
	ps3_graphics_init();
	ps3_audio_init();
	s32_board.sound_rom = game_sound;
	sound_chips_attach();
	sound_cpu_attach();
#ifdef SEGASONIC_CONSOLE
	console_jingle_program(0, -1);
	console_prepare_sprites(game_sprites, GAME_SPRITES_SIZE, game_program);
	s32_video_init(game_tiles, GAME_TILES_SIZE, game_sprites, GAME_SPRITES_SIZE);
	s32_board.frame_shown = console_draw_frame;
	ps3_tell_console_settings();
	ps3_load_eeprom();
	ps3_load_times();
#else
	s32_video_init(game_tiles, GAME_TILES_SIZE, game_sprites, GAME_SPRITES_SIZE);
	ps3_load_eeprom();
#endif
#endif
	s32_init(game_program);
	program_reset();
	program_frame_done = on_frame_done;

	if (!setjmp(finished))
		program_run();

	if (hashes)
		fclose(hashes);
	if (video_hashes)
		fclose(video_hashes);
	if (sound_hashes)
		fclose(sound_hashes);
	if (sound_levels)
		fclose(sound_levels);
	if (sprite_census)
		fclose(sprite_census);
	free(census_seen);
	if (tile_census)
		fclose(tile_census);
	free(tile_census_seen);
	if (memory_census_path)
	{
#ifdef S32_MEMORY_CENSUS
		FILE *census = fopen(memory_census_path, "w");
		if (census)
		{
			s32_memory_census_write(census);
			fclose(census);
		}
		else
			fprintf(stderr, "%s: cannot be written\n", memory_census_path);
#else
		fprintf(stderr, "--memory-census: this build does not count memory accesses\n");
#endif
	}
	s32_script_free(script);
	printf("frames:            %" PRIu64 "\n", program_frames());
	printf("interrupts taken:  %u\n", program_interrupts());
	printf("sprite lists:      %u\n", s32_board.sprite_lists);
	printf("sound requests:    %u\n", s32_board.sound_requests);
	printf("unmapped reads:    %u\n", s32_board.unmapped_reads);
	printf("unmapped writes:   %u\n", s32_board.unmapped_writes);
	printf("eeprom written:    %s\n", s32_board.eeprom.dirty ? "yes" : "no");
	return 0;
}
