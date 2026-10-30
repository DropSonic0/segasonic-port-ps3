/**
*    Name:        video.c
*    Description: Sega System 32 video: the tilemaps, text, bitmap and backdrop layers, the sprite frame
*                 buffers and the mixer, drawing each frame from the board's memories
*    Version:     0.1.0
*    Created:     13-10-2026
*    Modified:    19-10-2026
*    Author:      Sebastian Toyos
*
*    license:BSD-3-Clause
*    Behavior follows MAME's sega/segas32_v.cpp (Aaron Giles) pixel for pixel: tools/reference/video
*    builds that file unmodified, and tools/check_scenarios.py --video compares its frames with these.
*    MAME's terms are in tools/reference/mame/LICENSE.
*
*    How a frame is made: every layer draws a palette offset per pixel (0 is transparent) into a buffer
*    of its own, through its clip windows. The sprites were drawn before, into the hidden one of two
*    frame buffers, when the board sent the list. The mixer then takes, pixel by pixel, the topmost
*    layer that is not transparent in the order its priority registers give, maybe blends it with the
*    one below, and looks the color up in the palette.
*
*    Video RAM holds the tilemap pages (32 x 16 cells of a 16x16 tile, 0x400 bytes each), the text cells
*    and their graphics, the bitmap layer, the line tables, and the registers at 0x31FF00.
*/
#include "s32/video.h"

#include "s32/machine.h"
#include "s32/workers.h"

#include <stdbool.h>
#include <string.h>

#if defined(__CELLOS_LV2__) || defined(__SNC__) || defined(__PS3__)
#include <ppu_intrinsics.h>
#include <sys/sys_time.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../ports/ps3/spu_host.h"
#endif

#define WIDTH   S32_VIDEO_MAX_WIDTH
#define HEIGHT  S32_VIDEO_HEIGHT

/* The layers in the mixer's order: its registers come in this order */
enum
{
	LAYER_TEXT,
	LAYER_NBG0,
	LAYER_NBG1,
	LAYER_NBG2,
	LAYER_NBG3,
	LAYER_BITMAP,
	LAYER_SPRITES,
	LAYER_BACKDROP,
	LAYERS
};

/* A rectangle with inclusive edges (the clip windows keep one past their right and bottom edges) */
typedef struct area
{
	int left;
	int right;
	int top;
	int bottom;
} area;

/* What a layer drew: a palette offset per pixel, and the rows where everything is transparent */
typedef struct layer
{
	uint16_t pixels[HEIGHT][WIDTH];
	bool empty[HEIGHT];
} layer;

/* Where the clip windows turn a layer on and off along each row: lists of columns that start at the
left edge and end one past the right edge, one for each set of windows (0-31) and one for each row
whose windows come from the line table (32 + the row) */
typedef struct clip_runs
{
	uint8_t list_of_row[256];
	uint16_t lists[256][16];
} clip_runs;

/* The source of one row of a layer: its pixel at a screen column */
typedef uint16_t(*pixel_source)(const void *row, int x);

/* A layer in the mixer's list */
typedef struct mix_layer
{
	uint16_t palette_base;
	uint16_t sprite_blend;      /* sprite groups this layer blends with */
	uint8_t blend;              /* layers this one blends with */
	uint8_t index;              /* LAYER_ */
	uint8_t priority;           /* the register's priority << 3 | the layer's own rank */
	uint8_t shift;              /* of the pixel, before the palette base is added */
	uint8_t offsets;            /* color offsets 0 or 1, or none (2) */
} mix_layer;

/* What one sprite draws with */
typedef struct sprite_drawing
{
	uint16_t *row;
	const area *inside;         /* the clip it draws in */
	const area *outside;        /* the clip it leaves alone, on the rows it covers */
	bool outside_row;
	bool indirect;              /* pens go through a table of 16 colors */
	bool shadow;                /* darkens what is under it instead */
	bool bits8;
	int color;
	int transparent_bits;       /* an indirect color with all these bits set is transparent */
	uint16_t table[16];
	bool one_to_one;            /* sin zoom: un pen es un pixel */
	int lut_mid[16];            /* el pixel de cada pen (-1: transparente) lejos de los extremos de la palabra */
	int lut_end[16];            /* lo mismo para el primer y el �ltimo pen de la palabra */
} sprite_drawing;

static struct
{
	const uint8_t *tiles;
	uint32_t tile_count;
	const uint8_t *sprite_rom;
	uint32_t sprite_rom_words;
	uint32_t sprite_banks;                  /* of 4 MB */

	area visible;                           /* 320 or 416 x 224 */
	bool wide;                              /* s32_video_set_wide */
	int side;                               /* this frame's: S32_VIDEO_WIDE_SIDE when wide, else 0 */
	int sprite_side;                        /* the sprite list's: every sprite that much to the right */
	layer layers[LAYERS] __attribute__((aligned(128)));                 /* the sprites' entry is unused: they have their own buffers */
	uint16_t sprites[2][HEIGHT][WIDTH] __attribute__((aligned(128)));   /* frame buffers: one is shown, the list draws into the other */
	int shown_sprites;
	uint32_t frame[HEIGHT][WIDTH] __attribute__((aligned(128)));
	clip_runs runs;
} video;

static const uint16_t transparent_row[WIDTH] = { 0 };
static uint32_t palette_argb[0x4000];   /* la paleta ya convertida a ARGB, una vez por frame */
static uint8_t *tile_pens;   /* por tile: 16 filas x 16 pens, 1 byte cada uno */

static void decode_tiles(void)
{
	static const uint8_t byte_of_column[16] = { 0, 0, 2, 2, 1, 1, 3, 3, 4, 4, 6, 6, 5, 5, 7, 7 };

	free(tile_pens);
	tile_pens = video.tile_count ? (uint8_t *)malloc((size_t)video.tile_count * 256) : NULL;
	if (tile_pens == NULL)
		return;     /* sin memoria: queda el camino lento de siempre */
	for (uint32_t tile = 0; tile < video.tile_count; tile++)
	for (int y = 0; y < 16; y++)
	for (int x = 0; x < 16; x++)
	{
		const uint8_t value = video.tiles[(size_t)tile * 128 + y * 8 + byte_of_column[x]];

		tile_pens[(size_t)tile * 256 + y * 16 + x] = (x & 1) ? (value & 0x0f) : (value >> 4);
	}
}

/* ---- the board's memories ---- */

static bool bit(uint32_t value, int number)
{
	return (value >> number) & 1;
}

static int sign_extend(uint32_t value, int bits)
{
	const uint32_t sign = 1u << (bits - 1);
	return (int)((value & ((sign << 1) - 1)) ^ sign) - (int)sign;
}

/* x >> count, rounding down for negative numbers too */
static int shift_down(int value, int count)
{
	return value >= 0 ? value >> count : ~(~value >> count);
}

static inline uint16_t video_word(uint32_t index)
{
	const uint8_t *at = &s32_board.video_ram[(index & 0xffff) * 2];
	return (uint16_t)(at[0] | ((uint16_t)at[1] << 8));
}

/* A register of the tilemap chip, by its offset from 0x31FF00 */
static uint16_t video_register(uint32_t offset)
{
	return video_word((0x1ff00 + offset) / 2);
}

/* A mixer register, by its offset in the mixer's window */
static uint16_t mixer_register(uint32_t offset)
{
	return s32_board.mixer[offset / 2];
}

static uint16_t sprite_word(uint32_t index)
{
	const uint8_t *at = &s32_board.sprite_ram[(index & 0xffff) * 2];
	return (uint16_t)(at[0] | at[1] << 8);
}

static uint32_t big_endian_word(const uint8_t *at)
{
#if defined(__CELLOS_LV2__) || defined(__SNC__) || defined(__PS3__)
	return *(const uint32_t *)at;    /* la PPU ya es big-endian */
#else
	return (uint32_t)at[0] << 24 | (uint32_t)at[1] << 16 | (uint32_t)at[2] << 8 | at[3];
#endif
}

static void clip_area(area *target, const area *bounds)
{
	if (bounds->left > target->left)
		target->left = bounds->left;
	if (bounds->right < target->right)
		target->right = bounds->right;
	if (bounds->top > target->top)
		target->top = bounds->top;
	if (bounds->bottom < target->bottom)
		target->bottom = bounds->bottom;
}

/* ---- tiles and text cells ---- */

/* The pen (0-15) of a pixel of a 16x16 tile: rows of 8 bytes, two pens a byte with the high nibble
first, and the byte pairs of each half of the row swapped */
static int tile_pen(uint32_t tile, int x, int y)
{
	static const uint8_t byte_of_column[16] = { 0, 0, 2, 2, 1, 1, 3, 3, 4, 4, 6, 6, 5, 5, 7, 7 };
	const uint8_t value = video.tiles[(size_t)(tile % video.tile_count) * 128 + y * 8 + byte_of_column[x]];

	return (x & 1) ? (value & 0x0f) : (value >> 4);
}

/* A pixel of a tilemap page (32 x 16 cells, 512 x 256 pixels). A cell is the tile number (13 bits, the
bank above them), its color (bits 4-12, over the number) and its flips (bit 14 x, bit 15 y). */
static const uint16_t *own_cell_words;    /* s32_video_set_cells */
static const uint8_t *own_cell_marks;

static uint16_t page_pixel(int page, int bank, int y, int x)
{
	const uint32_t index = (uint32_t)page << 9 | (uint32_t)(y >> 4) << 5 | (uint32_t)(x >> 4);
	const uint16_t cell = own_cell_marks && own_cell_marks[index] ? own_cell_words[index] : video_word(index);
	const uint32_t tile = (uint32_t)bank << 13 | (cell & 0x1fff);
	const int column = (cell & 0x4000) ? 15 - (x & 15) : (x & 15);
	const int line = (cell & 0x8000) ? 15 - (y & 15) : (y & 15);
	const int pen = tile_pen(tile, column, line);

	return pen ? (uint16_t)(((cell >> 4) & 0x1ff) << 4 | pen) : 0;
}

/* The cell a row of pixels is on: its tile's row of pens, color and flip, kept while the row stays on it */
typedef struct tile_cache
{
	int key;                 /* the cell's column over the row's two pages (page << 5 | cell), -1 for none yet */
	const uint8_t *row;      /* the tile's 8 bytes at the row being drawn */
	uint16_t palette;
	bool flip_x;
} tile_cache;

/* page_pixel, but the cell and tile are looked up only when 'key' (the cell the pixel is in) changes */
static uint16_t cached_page_pixel(tile_cache *cache, int key, int page, int bank, int y, int x)
{
	static const uint8_t byte_of_column[16] = { 0, 0, 2, 2, 1, 1, 3, 3, 4, 4, 6, 6, 5, 5, 7, 7 };

	if (cache->key != key || !cache->row)
	{
		const uint32_t index = (uint32_t)page << 9 | (uint32_t)(y >> 4) << 5 | (uint32_t)(x >> 4);
		const uint16_t cell = own_cell_marks && own_cell_marks[index] ? own_cell_words[index] : video_word(index);
		const uint32_t tile = (uint32_t)bank << 13 | (cell & 0x1fff);
		const int line = (cell & 0x8000) ? 15 - (y & 15) : (y & 15);

		cache->key = key;
		cache->row = &video.tiles[(size_t)(tile % video.tile_count) * 128 + line * 8];
		cache->palette = (uint16_t)(((cell >> 4) & 0x1ff) << 4);
		cache->flip_x = (cell & 0x4000) != 0;
	}
	{
		const int column = cache->flip_x ? 15 - (x & 15) : (x & 15);
		const uint8_t value = cache->row[byte_of_column[column]];
		const int pen = (column & 1) ? (value & 0x0f) : (value >> 4);

		return pen ? (uint16_t)(cache->palette | pen) : 0;
	}
}

/* A pixel of the text layer (64 x 32 cells of 8x8, a 512 x 256 map). The cells' page and the bank of
their graphics come from register 0x5C; the graphics are in video RAM too, 32 bytes a character,
four bytes a row, the high nibble first. */
static uint16_t text_pixel(int y, int x)
{
	const uint16_t control = video_register(0x5c);
	const uint16_t cell = video_word((uint32_t)((control >> 4) & 0x1f) << 11 | (uint32_t)(y >> 3) << 6 | (uint32_t)(x >> 3));
	const uint32_t character = (uint32_t)(control & 7) << 9 | (cell & 0x1ff);
	const uint8_t value = s32_board.video_ram[character * 32 + (y & 7) * 4 + (x & 7) / 2];
	const int pen = (x & 1) ? (value & 0x0f) : (value >> 4);

	return pen ? (uint16_t)(((cell >> 9) & 0x7f) << 4 | pen) : 0;
}

/* ---- clip windows ---- */

/* Window 0-4 (0x60 + 8 each: left, top, right, bottom), with one past its right and bottom edges */
static void window_of(int number, bool flip, area *window)
{
	const uint32_t at = 0x60 + 8 * (uint32_t)number;
	const int left = video_register(at) & 0x1ff;
	const int top = video_register(at + 2) & 0xff;
	const int right = (video_register(at + 4) & 0x1ff) + 1;
	const int bottom = (video_register(at + 6) & 0xff) + 1;

	if (!flip)
	{
		window->left = left + video.side;
		window->right = right + video.side;
		if (video.side && left == 0 && right >= 320)
		{
			window->left = 0;
			window->right = video.visible.right + 1;
		}
		window->top = top;
		window->bottom = bottom;
	}
	else
	{
		window->left = video.visible.right + 1 - right;
		window->right = video.visible.right + 1 - left;
		window->top = video.visible.bottom + 1 - bottom;
		window->bottom = video.visible.bottom + 1 - top;
	}
}

static void sort_by_left(const area *windows, int *order)
{
	for (int index = 1; index < 5; index++)
	{
		const int key = order[index];
		int place = index - 1;

		while (place >= 0 && windows[order[place]].left > windows[key].left)
		{
			order[place + 1] = order[place];
			place--;
		}
		order[place + 1] = key;
	}
}

/* The list for a set of windows: taken from left to right, a window that starts inside the last run
stretches it */
static void merge_windows(uint16_t *list, const area *windows, const int *order, int set, const area *edges)
{
	uint16_t *end = list;

	*end++ = (uint16_t)edges->left;
	for (int index = 0; index < 5; index++)
	{
		const area *window = &windows[order[index]];

		if (!bit((uint32_t)set, order[index]))
			continue;
		if (end != list + 1 && window->left <= end[-1])
		{
			if (window->right > end[-1])
				end[-1] = (uint16_t)window->right;
		}
		else
		{
			*end++ = (uint16_t)window->left;
			*end++ = (uint16_t)window->right;
		}
	}
	*end = (uint16_t)edges->right;
}

/* Windows 2 and 3 can take their columns from the line table instead, row by row (0xFFFF: none) */
static void line_window(int number, int line, bool flip, uint32_t table, const area *edges, area *window, int *crossing)
{
	const uint16_t left = video_word(table + 0x100 * (uint32_t)(number - 2) + (uint32_t)line);
	const uint16_t right = video_word(table + 0x200 + 0x100 * (uint32_t)(number - 2) + (uint32_t)line);

	if (left == 0xffff || right == 0xffff)
		*crossing &= ~(1 << number);
	else if (!flip)
	{
		window->left = (left & 0x1ff) + video.side;
		window->right = (right & 0x1ff) + 1 + video.side;
		if (video.side && (left & 0x1ff) == 0 && (right & 0x1ff) + 1 >= 320)
		{
			window->left = 0;
			window->right = video.visible.right + 1;
		}
	}
	else
	{
		window->left = video.visible.right + 1 - ((right & 0x1ff) + 1);
		window->right = video.visible.right + 1 - (left & 0x1ff);
	}
	clip_area(window, edges);
	if (window->left >= window->right)
		*crossing &= ~(1 << number);
}

/* A layer's runs: 'selected' picks windows 0-4. The first run of each row is drawn when the layer draws
outside its windows (or has them off), and the runs alternate from there. */
static bool find_clip_runs(bool enabled, bool outside, int selected, clip_runs *runs)
{
	const bool flip = bit(video_register(0x00), 9);
	const uint16_t line_control = video_register(0x04);
	const bool line_windows = bit(line_control, 4) || bit(line_control, 5);
	const area edges = { video.visible.left, video.visible.right + 1, video.visible.top, video.visible.bottom + 1 };
	area windows[5];
	int order[5];

	memset(runs, 0, sizeof(*runs));
	runs->lists[0][0] = (uint16_t)edges.left;
	runs->lists[0][1] = (uint16_t)edges.right;
	if (!enabled)
		return true;

	for (int number = 0; number < 5; number++)
	{
		window_of(number, flip, &windows[number]);
		clip_area(&windows[number], &edges);
		order[number] = number;
	}
	sort_by_left(windows, order);
	for (int set = 1; set < 32; set++)
	if (set & selected)
		merge_windows(runs->lists[set], windows, order, set, &edges);

	for (int y = edges.top; y < edges.bottom; y++)
	{
		int crossing = 0;
		area row_windows[5];
		int row_order[5];

		for (int number = 0; number < 5; number++)
		if (bit((uint32_t)selected, number) && y >= windows[number].top && y < windows[number].bottom)
			crossing |= 1 << number;
		if (!line_windows)
		{
			runs->list_of_row[y] = (uint8_t)crossing;
			continue;
		}

		for (int number = 0; number < 5; number++)
		{
			row_windows[number] = windows[number];
			row_order[number] = number;
		}
		for (int number = 2; number <= 3; number++)
		if (bit(line_control, number + 2) && bit((uint32_t)selected, number))
			line_window(number, flip ? video.visible.bottom - y : y, flip, (uint32_t)(line_control >> 10) * 0x400,
			&edges, &row_windows[number], &crossing);
		sort_by_left(row_windows, row_order);
		merge_windows(runs->lists[32 + y], row_windows, row_order, crossing, &edges);
		runs->list_of_row[y] = (uint8_t)(32 + y);
	}
	return outside;
}

/* One row of a layer through its runs, which alternate between drawn and cleared starting with 'drawn'.
Overlapping windows can make a run start before the last one ended: it is drawn again. */
static void draw_row(layer *out, int y, const uint16_t *runs, bool drawn, pixel_source pixel, const void *row)
{
	uint16_t *pixels = out->pixels[y];
	int transparent = 0;

	for (;; runs++, drawn = !drawn)
	{
		if (drawn)
		{
			for (int x = runs[0]; x < runs[1] && x < WIDTH; x++)
			{
				pixels[x] = pixel(row, x);
				transparent += pixels[x] == 0;
			}
		}
		else
		{
			for (int x = runs[0]; x < runs[1] && x < WIDTH; x++)
				pixels[x] = 0;
			transparent += runs[1] - runs[0];
		}
		if (runs[1] > video.visible.right)
			break;
	}
	out->empty[y] = transparent == video.visible.right + 1 - video.visible.left;
}

/* Una fila de tilemap sin zoom: copia celda por celda en vez de pixel por pixel */
static unsigned fill_tile_row(uint16_t *out, int left, int right, const int *pages, int bank, int line,
	int column, int step)
{
	const uint32_t cell_row = (uint32_t)(line >> 4) << 5;
	unsigned seen = 0;
	int x = left;

	column &= 0xfff;
	while (x <= right)
	{
		const int in_cell = column & 15;
		int count = step > 0 ? 16 - in_cell : in_cell + 1;
		const uint32_t index = (uint32_t)pages[(column >> 9) & 1] << 9 | cell_row | (uint32_t)((column >> 4) & 31);
		const uint16_t cell = video_word(index);
		uint32_t tile = (uint32_t)bank << 13 | (cell & 0x1fff);
		const int tile_line = (cell & 0x8000) ? 15 - (line & 15) : (line & 15);
		const unsigned palette = (unsigned)((cell >> 4) & 0x1ff) << 4;
		const int dir = (cell & 0x4000) ? -step : step;
		int at = (cell & 0x4000) ? 15 - in_cell : in_cell;
		const uint8_t *pens;

		if (tile >= video.tile_count)
			tile %= video.tile_count;
		pens = &tile_pens[(size_t)tile * 256 + tile_line * 16];
		if (count > right - x + 1)
			count = right - x + 1;

		/* Si toda la l�nea del tile es transparente (ceros), saltar en bloque */
		if (*(const uint64_t *)pens == 0 && *(const uint64_t *)(pens + 8) == 0)
		{
			memset(&out[x], 0, (size_t)count * sizeof(uint16_t));
			x += count;
			column = (column + step * count) & 0xfff;
			continue;
		}

		/* Desenrollado directo para tiles completos de 16 p�xeles */
		if (count == 16 && dir == 1 && at == 0)
		{
			for (int i = 0; i < 16; i++)
			{
				const unsigned pen = pens[i];
				const unsigned val = pen ? (palette | pen) : 0;
				out[x + i] = (uint16_t)val;
				seen |= val;
			}
			x += 16;
			column = (column + step * 16) & 0xfff;
			continue;
		}
		if (count == 16 && dir == -1 && at == 15)
		{
			for (int i = 0; i < 16; i++)
			{
				const unsigned pen = pens[15 - i];
				const unsigned val = pen ? (palette | pen) : 0;
				out[x + i] = (uint16_t)val;
				seen |= val;
			}
			x += 16;
			column = (column + step * 16) & 0xfff;
			continue;
		}

		for (int i = 0; i < count; i++, at += dir)
		{
			const unsigned pen = pens[at];
			const unsigned value = pen ? (palette | pen) : 0;

			out[x + i] = (uint16_t)value;
			seen |= value;
		}
		x += count;
		column = (column + step * count) & 0xfff;
	}
	return seen;
}

static bool runs_in_order(const uint16_t *runs)
{
	for (;; runs++)
	{
		if (runs[1] < runs[0])
			return false;
		if (runs[1] > video.visible.right)
			return true;
	}
}

/* Borra lo que las ventanas de recorte dejan afuera; dice si borr� algo */
static bool clip_filled_row(uint16_t *pixels, const uint16_t *runs, bool drawn)
{
	bool clipped = false;

	for (;; runs++, drawn = !drawn)
	{
		const int end = runs[1] < WIDTH ? runs[1] : WIDTH;

		if (!drawn && end > runs[0])
		{
			memset(&pixels[runs[0]], 0, (size_t)(end - runs[0]) * sizeof(uint16_t));
			clipped = true;
		}
		if (runs[1] > video.visible.right)
			break;
	}
	return clipped;
}

static void draw_tile_row(layer *out, int y, const uint16_t *runs, bool drawn, const int *pages, int bank,
	int line, int column, int step, pixel_source slow, const void *slow_row)
{
	uint16_t *pixels = out->pixels[y];
	unsigned seen;

	if (tile_pens == NULL || !runs_in_order(runs))
	{
		draw_row(out, y, runs, drawn, slow, slow_row);    /* el camino de siempre */
		return;
	}
	seen = fill_tile_row(pixels, video.visible.left, video.visible.right, pages, bank, line, column, step);
	if (clip_filled_row(pixels, runs, drawn))
	{
		seen = 0;
		for (int x = video.visible.left; x <= video.visible.right; x++)
			seen |= pixels[x];
	}
	out->empty[y] = seen == 0;
}

/* ---- the layers ---- */

/* The four pages of tilemap 0-3 (upper left, upper right, lower left, lower right) and its tile bank */
static int pages_of(int number, int *pages)
{
	const uint16_t upper = video_register(0x40 + 4 * (uint32_t)number);
	const uint16_t lower = video_register(0x42 + 4 * (uint32_t)number);

	pages[0] = upper & 0x7f;
	pages[1] = (upper >> 8) & 0x7f;
	pages[2] = lower & 0x7f;
	pages[3] = (lower >> 8) & 0x7f;
	return (s32_board.tilebank_external & 1) << 1 | ((video_register(0x00) >> 10) & 1);
}

/* Register 0x00 flips tilemap 0-3 against the whole screen's flip (bit 9); bit 8 keeps them from
flipping vertically */
static void flips_of(int number, bool *flip_x, bool *flip_y)
{
	const uint16_t control = video_register(0x00);
	const bool screen_flip = bit(control, 9);
	const bool layer_flip = bit(control, number);

	*flip_x = layer_flip ? !screen_flip : screen_flip;
	*flip_y = (layer_flip && !bit(control, 8)) ? !screen_flip : screen_flip;
}

typedef struct zoomed_row
{
	int pages[2];       /* left and right page of the row's half */
	int bank;
	int line;           /* the row within the pages */
	uint32_t x_start;   /* source column at the left edge, 12.20 */
	uint32_t x_step;
	tile_cache cache;
} zoomed_row;

static uint16_t zoomed_pixel(const void *source, int x)
{
	zoomed_row *row = (zoomed_row *)source;
	const uint32_t column = row->x_start + row->x_step * (uint32_t)(x - video.visible.left);

	return cached_page_pixel(&row->cache, (int)((column >> 24) & 0x3f), row->pages[(column >> 29) & 1], row->bank,
		row->line, (int)((column >> 20) & 0x1ff));
}

/* What NBG0 or NBG1 draws with, the same on every row: the source at the top row, and how it moves */
typedef struct zoomed_layer
{
	int number;
	int pages[4];
	int bank;
	bool first_drawn;
	uint32_t x_start;
	uint32_t x_step;
	uint32_t source_y;  /* at the top row, 12.20 */
	uint32_t y_step;
} zoomed_layer;

static void draw_zoomed_row_fast(layer *out, int y, const uint16_t *runs, bool drawn, const zoomed_row *row)
{
	uint16_t *pixels = out->pixels[y];
	int transparent = 0;
	int last_key = -1;
	const uint8_t *pens = NULL;
	unsigned palette = 0;
	bool flip_x = false;
	const int line = row->line;
	const int bank = row->bank;
	const int tile_y = line & 15;
	const uint32_t cell_y_offset = (uint32_t)(line >> 4) << 5;

	for (;; runs++, drawn = !drawn)
	{
		const int x0 = runs[0];
		const int x1 = runs[1] < WIDTH ? runs[1] : WIDTH;
		if (drawn)
		{
			uint32_t col = row->x_start + (uint32_t)(x0 - video.visible.left) * row->x_step;
			const uint32_t step = row->x_step;

			for (int x = x0; x < x1; x++, col += step)
			{
				const int key = (int)((col >> 24) & 0x3f);
				if (key != last_key)
				{
					last_key = key;
					const int page = row->pages[(col >> 29) & 1];
					const uint32_t index = (uint32_t)page << 9 | cell_y_offset | (uint32_t)((col >> 24) & 31);
					const uint16_t cell = own_cell_marks && own_cell_marks[index] ? own_cell_words[index] : video_word(index);
					uint32_t tile = (uint32_t)bank << 13 | (cell & 0x1fff);
					const int tile_line = (cell & 0x8000) ? 15 - tile_y : tile_y;
					if (tile >= video.tile_count)
						tile %= video.tile_count;
					pens = &tile_pens[(size_t)tile * 256 + tile_line * 16];
					palette = (unsigned)(((cell >> 4) & 0x1ff) << 4);
					flip_x = (cell & 0x4000) != 0;
				}
				const int col_in_tile = (int)((col >> 20) & 15);
				const int c = flip_x ? 15 - col_in_tile : col_in_tile;
				const unsigned pen = pens[c];
				const unsigned val = pen ? (palette | pen) : 0;
				pixels[x] = (uint16_t)val;
				transparent += (val == 0);
			}
		}
		else
		{
			for (int x = x0; x < x1; x++)
				pixels[x] = 0;
			transparent += x1 - x0;
		}
		if (runs[1] > video.visible.right)
			break;
	}
	out->empty[y] = transparent == video.visible.right + 1 - video.visible.left;
}

static void draw_zoomed_rows(void *context, int first, int last)
{
	const zoomed_layer *zoomed = (const zoomed_layer *)context;

	for (int y = first; y <= last; y++)
	{
		const uint32_t source_y = zoomed->source_y + (uint32_t)(y - video.visible.top) * zoomed->y_step;
		const int half = (source_y >> 27) & 2;
		const zoomed_row row = {
			{ zoomed->pages[half], zoomed->pages[half + 1] }, zoomed->bank, (source_y >> 20) & 0xff,
			zoomed->x_start, zoomed->x_step
		};

		if (zoomed->x_step == 0x100000u || zoomed->x_step == 0u - 0x100000u)
			draw_tile_row(&video.layers[LAYER_NBG0 + zoomed->number], y, video.runs.lists[video.runs.list_of_row[y]],
			zoomed->first_drawn, row.pages, row.bank, row.line, (int)(row.x_start >> 20),
			zoomed->x_step == 0x100000u ? 1 : -1, zoomed_pixel, &row);
		else if (tile_pens != NULL)
			draw_zoomed_row_fast(&video.layers[LAYER_NBG0 + zoomed->number], y, video.runs.lists[video.runs.list_of_row[y]],
			zoomed->first_drawn, &row);
		else
			draw_row(&video.layers[LAYER_NBG0 + zoomed->number], y, video.runs.lists[video.runs.list_of_row[y]],
			zoomed->first_drawn, zoomed_pixel, &row);
	}
}

/* NBG0 and NBG1: scrolled (with a fraction) and zoomed about a center. The steps are screen pixels per
source pixel (0x200 = 1); the source moves by their reciprocal, in 12.20. */
static void draw_zoomed(int number)
{
	const uint32_t scroll = 0x10 + 8 * (uint32_t)number;
	const uint32_t center = 0x30 + 4 * (uint32_t)number;
	int pages[4];
	const int bank = pages_of(number, pages);
	bool flip_x;
	bool flip_y;
	int x_zoom = video_register(0x50 + 4 * (uint32_t)number) & 0xfff;
	int y_zoom = bit(video_register(0x00), 14) ? video_register(0x52 + 4 * (uint32_t)number) & 0xfff : x_zoom;
	uint32_t x_step;
	uint32_t y_step;
	uint32_t x_start;
	uint32_t source_y;
	const bool first_drawn = find_clip_runs(bit(video_register(0x02), 11 + number), bit(video_register(0x02), 6 + number),
		(video_register(0x06) >> (4 * number)) & 0x0f, &video.runs);

	flips_of(number, &flip_x, &flip_y);
	if (x_zoom < 0x80)
		x_zoom = 0x80;
	if (y_zoom < 0x80)
		y_zoom = 0x80;
	x_step = (0x200u << 20) / (uint32_t)x_zoom;
	y_step = (0x200u << 20) / (uint32_t)y_zoom;

	/* the scroll with its fraction, less the center (one bit more of it while zoomed) */
	x_start = (uint32_t)(video_register(scroll + 2) & 0x3ff) << 20;
	x_start += (uint32_t)(video_register(scroll) & 0xff00) << 4;
	source_y = (uint32_t)(video_register(scroll + 6) & 0x1ff) << 20;
	source_y += (uint32_t)(video_register(scroll + 4) & 0xfe00) << 4;
	x_start -= (uint32_t)sign_extend(video_register(center), x_zoom != 0x200 ? 10 : 9) * x_step;
	source_y -= (uint32_t)sign_extend(video_register(center + 2), y_zoom != 0x200 ? 10 : 9) * y_step;
	x_start += (uint32_t)(video.visible.left - video.side) * x_step;
	source_y += (uint32_t)video.visible.top * y_step;
	if (flip_y)
	{
		source_y += (uint32_t)(video.visible.bottom - 2 * video.visible.top) * y_step;
		y_step = 0u - y_step;
	}
	if (flip_x)
	{
		x_start += (uint32_t)(video.visible.right - 2 * video.visible.left) * x_step;
		x_step = 0u - x_step;
	}

	{
		const zoomed_layer zoomed = {
			number, { pages[0], pages[1], pages[2], pages[3] }, bank, first_drawn, x_start, x_step, source_y, y_step
		};

		s32_workers_rows(draw_zoomed_rows, (void *)&zoomed, video.visible.top, video.visible.bottom);
	}
}

typedef struct scrolled_row
{
	int pages[2];
	int bank;
	int line;
	int x_start;        /* source column at the left edge */
	int x_step;
	tile_cache cache;
} scrolled_row;

static uint16_t scrolled_pixel(const void *source, int x)
{
	scrolled_row *row = (scrolled_row *)source;
	const uint32_t column = (uint32_t)(row->x_start + row->x_step * (x - video.visible.left));

	return cached_page_pixel(&row->cache, (int)((column >> 4) & 0x3f), row->pages[(column >> 9) & 1], row->bank,
		row->line, (int)(column & 0x1ff));
}

/* What NBG2 or NBG3 draws with, the same on every row */
typedef struct scrolled_layer
{
	int number;
	uint32_t table;
	bool row_scroll;
	bool row_select;
	int x_scroll;
	int y_scroll;
	int pages[4];
	int bank;
	bool flip_x;
	bool flip_y;
	bool first_drawn;
} scrolled_layer;

static void draw_scrolled_rows(void *context, int first, int last)
{
	const scrolled_layer *scrolled = (const scrolled_layer *)context;

	for (int y = first; y <= last; y++)
	{
		const int line = scrolled->flip_y ? video.visible.bottom - y : y;
		int source_y = scrolled->y_scroll + line;
		scrolled_row row;

		row.x_start = (scrolled->flip_x ? video.visible.right : video.visible.left) + scrolled->x_scroll - video.side;
		row.x_step = scrolled->flip_x ? -1 : 1;
		if (scrolled->row_scroll)
			row.x_start += video_word(scrolled->table + (uint32_t)line) & 0x3ff;
		if (scrolled->row_select)
			source_y = (scrolled->y_scroll + video_word(scrolled->table + 0x200 + (uint32_t)line)) & 0x1ff;
		row.pages[0] = scrolled->pages[(source_y >> 7) & 2];
		row.pages[1] = scrolled->pages[((source_y >> 7) & 2) + 1];
		row.bank = scrolled->bank;
		row.line = source_y & 0xff;
		row.cache.key = -1;
		draw_tile_row(&video.layers[LAYER_NBG0 + scrolled->number], y, video.runs.lists[video.runs.list_of_row[y]],
			scrolled->first_drawn, row.pages, row.bank, row.line, row.x_start, row.x_step, scrolled_pixel, &row);
	}
}

/* NBG2 and NBG3: scrolled, and row by row the line table can add to the column (row scroll) or pick
the source row (row select). Register 0x04 turns those on; its top bits place the table. */
static void draw_scrolled(int number)
{
	const uint16_t line_control = video_register(0x04);
	const bool line_windows = bit(line_control, number + 2);
	scrolled_layer scrolled;

	scrolled.number = number;
	scrolled.table = (uint32_t)(line_control >> 10) * 0x400 + 0x100 * (uint32_t)(number - 2);
	scrolled.row_scroll = bit(line_control, number - 2) && !line_windows;
	scrolled.row_select = bit(line_control, number) && !line_windows;
	scrolled.x_scroll = (video_register(0x12 + 8 * (uint32_t)number) & 0x3ff) - (video_register(0x30 + 4 * (uint32_t)number) & 0x1ff);
	scrolled.y_scroll = video_register(0x16 + 8 * (uint32_t)number) & 0x1ff;
	scrolled.bank = pages_of(number, scrolled.pages);
	scrolled.first_drawn = find_clip_runs(bit(video_register(0x02), 11 + number), bit(video_register(0x02), 6 + number),
		(video_register(0x06) >> (4 * number)) & 0x0f, &video.runs);
	flips_of(number, &scrolled.flip_x, &scrolled.flip_y);
	s32_workers_rows(draw_scrolled_rows, &scrolled, video.visible.top, video.visible.bottom);
}

/* The text layer, with no scroll and no windows; the screen's flip turns the whole 512 x 256 map */
static void draw_text_rows(void *context, int first, int last)
{
	const bool flip = *(const bool *)context;
	const uint16_t control = video_register(0x5c);
	const uint32_t cell_page = (uint32_t)((control >> 4) & 0x1f) << 11;
	const uint32_t character_bank = (uint32_t)(control & 7) << 9;
	const int limit = video.side ? 320 : video.visible.right + 1;
	const int left_draw = video.side;
	const int right_draw = video.side + limit - 1;

	for (int y = first; y <= last; y++)
	{
		uint16_t *out = video.layers[LAYER_TEXT].pixels[y];
		const int source_y = flip ? 255 - y : y;
		const uint32_t cell_row = cell_page | (uint32_t)(source_y >> 3) << 6;
		const int line = (source_y & 7) * 4;
		const uint8_t *graphics = NULL;
		uint32_t palette = 0;
		int cached_cell = -1;
		unsigned seen = 0;

		if (left_draw > video.visible.left)
			memset(&out[video.visible.left], 0, (size_t)(left_draw - video.visible.left) * sizeof(uint16_t));
		if (video.visible.right > right_draw)
			memset(&out[right_draw + 1], 0, (size_t)(video.visible.right - right_draw) * sizeof(uint16_t));

		for (int x = left_draw; x <= right_draw; x++)
		{
			const int column = x - video.side;
			const int source_x = flip ? 511 - column : column;
			if ((source_x >> 3) != cached_cell)
			{
				const uint16_t cell = video_word(cell_row | (uint32_t)(source_x >> 3));

				cached_cell = source_x >> 3;
				graphics = &s32_board.video_ram[(character_bank | (cell & 0x1ff)) * 32 + line];
				palette = (uint32_t)((cell >> 9) & 0x7f) << 4;
			}
			{
				const uint8_t value = graphics[(source_x & 7) >> 1];
				const int pen = (source_x & 1) ? (value & 0x0f) : (value >> 4);
				const uint16_t px = pen ? (uint16_t)(palette | (uint32_t)pen) : 0;

				out[x] = px;
				seen |= px;
			}
		}
		video.layers[LAYER_TEXT].empty[y] = (seen == 0);
	}
}

static void draw_text(void)
{
	bool flip = bit(video_register(0x00), 9);

	s32_workers_rows(draw_text_rows, &flip, video.visible.top, video.visible.bottom);
}

typedef struct bitmap_row
{
	uint32_t start;     /* the row in video RAM: a byte offset (8 bits a pixel) or a word (4 bits) */
	int x_scroll;
	int color;
	bool bits8;
} bitmap_row;

static uint16_t bitmap_pixel(const void *source, int x)
{
	const bitmap_row *row = (const bitmap_row *)source;
	const int column = (x - video.side + row->x_scroll) & 0x1ff;
	int pixel;

	if (row->bits8)
	{
		pixel = s32_board.video_ram[row->start + (uint32_t)column] + row->color;
		return (pixel & 0xff) ? (uint16_t)pixel : 0;
	}
	pixel = ((video_word(row->start + (uint32_t)column / 4) >> (4 * (column & 3))) & 0x0f) + row->color;
	return (pixel & 0x0f) ? (uint16_t)pixel : 0;
}

/* What the bitmap layer draws with, the same on every row */
typedef struct bitmap_layer
{
	bool bits8;
	int x_scroll;
	int y_scroll;
	int color;
	bool first_drawn;
} bitmap_layer;

static void draw_bitmap_rows(void *context, int first, int last)
{
	const bitmap_layer *bitmap = (const bitmap_layer *)context;

	for (int y = first; y <= last; y++)
	{
		const bitmap_row row = {
			bitmap->bits8 ? 512 * (uint32_t)((y + bitmap->y_scroll) & 0xff) : 128 * (uint32_t)((y + bitmap->y_scroll) & 0x1ff),
			bitmap->x_scroll, bitmap->color, bitmap->bits8
		};

		draw_row(&video.layers[LAYER_BITMAP], y, video.runs.lists[video.runs.list_of_row[y]], bitmap->first_drawn,
			bitmap_pixel, &row);
	}
}

/* The bitmap layer: 512 pixels a row from the start of video RAM, 4 or 8 bits each (register 0x00
bit 11), scrolled by registers 0x88 and 0x8A, its palette from 0x8C; window 4 clips it */
static void draw_bitmap(void)
{
	bitmap_layer bitmap;

	bitmap.bits8 = bit(video_register(0x00), 11);
	bitmap.x_scroll = video_register(0x88) & 0x1ff;
	bitmap.y_scroll = video_register(0x8a) & 0x1ff;
	bitmap.color = (video_register(0x8c) << 4) & 0x1fff0 & ~((1 << (bitmap.bits8 ? 8 : 4)) - 1);
	bitmap.first_drawn = find_clip_runs(bit(video_register(0x02), 15), bit(video_register(0x02), 10), 0x10, &video.runs);
	s32_workers_rows(draw_bitmap_rows, &bitmap, video.visible.top, video.visible.bottom);
}

/* The backdrop: one color for the screen, or one per line (register 0x5E bit 15), wrapping at 511 */
static void draw_backdrop(void)
{
	const uint16_t control = video_register(0x5e);
	const bool flip = bit(video_register(0x00), 9);
	static uint16_t last_control = 0xffff;
	static int last_flip = -1;

	if (control == last_control && (int)flip == last_flip)
		return;
	last_control = control;
	last_flip = (int)flip;

	for (int y = video.visible.top; y <= video.visible.bottom; y++)
	{
		const int color = (control & 0x1e00) + (bit(control, 15) ? (control + y) & 0x1ff : 0);
		uint16_t *row = video.layers[LAYER_BACKDROP].pixels[flip ? video.visible.bottom - y : y];
		const uint32_t c32 = (uint32_t)(uint16_t)color | ((uint32_t)(uint16_t)color << 16);
		const int right = video.visible.right;
		int x = video.visible.left;

		while (x + 1 <= right)
		{
			*(uint32_t *)&row[x] = c32;
			x += 2;
		}
		if (x <= right)
			row[x] = (uint16_t)color;
	}
}

/* Every layer the registers leave on (0x02 and 0x8E turn them off, 0x00 bits 12-13 too for NBG2-3);
the backdrop is always there. The layers drawn, as bits by LAYER_. */
s32_tile_observer s32_video_tile_observer = NULL;

/* Every cell of the pages tilemap 'number' shows, to s32_video_tile_observer */
static void observe_tilemap(int number)
{
	int pages[4];
	const int bank = pages_of(number, pages);

	for (int index = 0; index < 4; index++)
	{
		bool seen = false;

		for (int earlier = 0; earlier < index; earlier++)
			seen = seen || pages[earlier] == pages[index];
		if (seen)
			continue;
		for (uint32_t cell = 0; cell < 32 * 16; cell++)
		{
			const uint16_t word = video_word((uint32_t)pages[index] << 9 | cell);

			s32_video_tile_observer(number, (uint32_t)bank << 13 | (word & 0x1fff), (word >> 4) & 0x1ff);
		}
	}
}

static int draw_layers(void)
{
	const uint16_t control = video_register(0x00);
	const uint16_t off = video_register(0x02);
	const uint16_t more_off = video_register(0x8e);
	int drawn = 0;

	if (!bit(off, 0) && !bit(more_off, 1) && (mixer_register(0x20 + 2 * LAYER_NBG0) & 0x0f) != 0)
	{
		draw_zoomed(0);
		if (s32_video_tile_observer != NULL)
			observe_tilemap(0);
		drawn |= 1 << LAYER_NBG0;
	}
	if (!bit(off, 1) && !bit(more_off, 2) && (mixer_register(0x20 + 2 * LAYER_NBG1) & 0x0f) != 0)
	{
		draw_zoomed(1);
		if (s32_video_tile_observer != NULL)
			observe_tilemap(1);
		drawn |= 1 << LAYER_NBG1;
	}
	if (!bit(off, 2) && !bit(more_off, 3) && !bit(control, 12) && (mixer_register(0x20 + 2 * LAYER_NBG2) & 0x0f) != 0)
	{
		draw_scrolled(2);
		if (s32_video_tile_observer != NULL)
			observe_tilemap(2);
		drawn |= 1 << LAYER_NBG2;
	}
	if (!bit(off, 3) && !bit(more_off, 4) && !bit(control, 13) && (mixer_register(0x20 + 2 * LAYER_NBG3) & 0x0f) != 0)
	{
		draw_scrolled(3);
		if (s32_video_tile_observer != NULL)
			observe_tilemap(3);
		drawn |= 1 << LAYER_NBG3;
	}
	if (!bit(off, 4) && !bit(more_off, 0) && (mixer_register(0x20 + 2 * LAYER_TEXT) & 0x0f) != 0)
	{
		draw_text();
		drawn |= 1 << LAYER_TEXT;
	}
	if (!bit(off, 5) && !bit(more_off, 5) && (mixer_register(0x20 + 2 * LAYER_BITMAP) & 0x0f) != 0)
	{
		draw_bitmap();
		drawn |= 1 << LAYER_BITMAP;
	}
	draw_backdrop();
	return drawn;
}

/* ---- sprites ---- */

s32_sprite_observer s32_video_sprite_observer = NULL;

static void put_sprite_pixel(const sprite_drawing *sprite, int x, int pen, int skipped_pen)
{
	int pixel;

	if (x < sprite->inside->left || x > sprite->inside->right || pen == skipped_pen)
		return;
	if (sprite->outside_row && x >= sprite->outside->left && x <= sprite->outside->right)
		return;
	if (!sprite->indirect)
	{
		if (pen == 0)
			return;
		pixel = sprite->color | pen;
	}
	else
	{
		pixel = sprite->bits8 ? sprite->table[pen >> 4] | (pen & 0x0f) : sprite->table[pen];
		if ((pixel & sprite->transparent_bits) == sprite->transparent_bits)
			return;
	}
	if (!sprite->shadow)
		sprite->row[x] = (uint16_t)pixel;
	else
		sprite->row[x] &= 0x7fff;
}

/* A 32-bit word of sprite graphics: lectura directa sin conversi�n innecesaria */
static inline uint32_t sprite_graphics(bool from_ram, uint32_t bank, uint32_t index)
{
	if (from_ram)
		return *(const uint32_t *)&s32_board.sprite_ram[(index & 0x7fff) * 4];

	const uint32_t word = (bank << 20) | (index & 0xfffff);
	const uint32_t idx = (word < video.sprite_rom_words) ? word : (word % (video.sprite_rom_words ? video.sprite_rom_words : 1));
	return ((const uint32_t *)video.sprite_rom)[idx];
}

static unsigned dbg_rows_1to1, dbg_rows_zoom, dbg_words_1to1, dbg_words_zoom;

/* One row of a sprite: words of 8 pens (4 bits) or 4 (8 bits), each pen repeated or skipped by the
zoom. The first and last pen of a word are transparent at all ones (unless the sprite is opaque),
and a word that ends with them ends the row. */
static void draw_sprite_row(const sprite_drawing *sprite, bool from_ram, uint32_t bank, uint32_t address,
	int x, int x_end, int x_delta, int x_zoom, int end_pen)
{
	const int bits = sprite->bits8 ? 8 : 4;
	const int pens = 32 / bits;
	const int pen_mask = (1 << bits) - 1;
	const int clip_left = sprite->inside->left;
	const int clip_right = sprite->inside->right;
	const bool leave_alone = sprite->outside_row;
	const int alone_left = sprite->outside->left;
	const int alone_right = sprite->outside->right;
	const bool indirect = sprite->indirect;
	const bool shadow = sprite->shadow;
	const bool bits8 = sprite->bits8;
	const int transparent_bits = sprite->transparent_bits;
	uint16_t *const row = sprite->row;
	int x_accumulator = 0;

	dbg_rows_zoom++;
	while (x != x_end)
	{
		const uint32_t word = sprite_graphics(from_ram, bank, address++);
		int pen = 0;

		dbg_words_zoom++;
		for (int index = 0; index < pens; index++)
		{
			const int skipped_pen = (index == 0 || index == pens - 1) ? end_pen : 0;
			int pixel = -1;    /* what the pen puts in the buffer, or -1 when it is transparent */

			pen = (int)(word >> (32 - bits * (index + 1))) & pen_mask;
			if (pen != skipped_pen)
			{
				if (!indirect)
				{
					if (pen != 0)
						pixel = sprite->color | pen;
				}
				else
				{
					const int looked_up = bits8 ? sprite->table[pen >> 4] | (pen & 0x0f) : sprite->table[pen];

					if ((looked_up & transparent_bits) != transparent_bits)
						pixel = looked_up;
				}
			}
			while (x_accumulator < 0x10000 && x != x_end)
			{
				if (pixel >= 0 && x >= clip_left && x <= clip_right
					&& !(leave_alone && x >= alone_left && x <= alone_right))
				{
					if (!shadow)
						row[x] = (uint16_t)pixel;
					else
						row[x] &= 0x7fff;
				}
				x += x_delta;
				x_accumulator += x_zoom;
			}
			x_accumulator -= 0x10000;
		}
		if (end_pen != 0 && pen == pen_mask)
			break;
	}
}
/* Una fila de sprite sin zoom (4 bits por pen): igual que draw_sprite_row, pero con los colores ya resueltos */
static void draw_sprite_row_1to1(const sprite_drawing *sprite, bool from_ram, uint32_t bank, uint32_t address,
	int x, int x_end, int x_delta, int end_pen)
{
	const int clip_left = sprite->inside->left;
	const int clip_right = sprite->inside->right;
	const bool leave_alone = sprite->outside_row;
	const int alone_left = sprite->outside->left;
	const int alone_right = sprite->outside->right;
	const bool shadow = sprite->shadow;
	uint16_t *const row = sprite->row;
	int n = (x_end - x) * x_delta;                 /* p�xeles que quedan por recorrer */
	const int last = x + (n - 1) * x_delta;
	const int lo = x < last ? x : last;
	const int hi = x < last ? last : x;

	dbg_rows_1to1++;
	if (n <= 0)
		return;

	const bool touches_alone = leave_alone && !(hi < alone_left || lo > alone_right);
	if (!touches_alone && lo >= clip_left && hi <= clip_right)
	{
		const int *lut_mid = sprite->lut_mid;
		const int *lut_end = sprite->lut_end;
		const bool skip_zero = lut_end[0] < 0;
		uint16_t *dst = row + x;
		const uint32_t *rom_ptr = (const uint32_t *)video.sprite_rom;
		uint32_t rom_idx = (bank << 20) | (address & 0xfffff);
		if (rom_idx >= video.sprite_rom_words) rom_idx %= (video.sprite_rom_words ? video.sprite_rom_words : 1);

		/* Fast-path ultra optimizado para sprites normales (no volteados horizontalmente) */
		if (x_delta == 1 && !shadow)
		{
			while (n > 0)
			{
				uint32_t word = !from_ram ? rom_ptr[rom_idx++] : sprite_graphics(true, bank, address);
				if (!from_ram && rom_idx >= video.sprite_rom_words) rom_idx = 0;
				address++;
				dbg_words_1to1++;

				if (n >= 8)
				{
					if (word == 0 && skip_zero) { dst += 8; n -= 8; continue; }
					const int p0 = (int)(word >> 28) & 15; const int px0 = lut_end[p0]; if (px0 >= 0) dst[0] = (uint16_t)px0;
					const int p1 = (int)(word >> 24) & 15; const int px1 = lut_mid[p1]; if (px1 >= 0) dst[1] = (uint16_t)px1;
					const int p2 = (int)(word >> 20) & 15; const int px2 = lut_mid[p2]; if (px2 >= 0) dst[2] = (uint16_t)px2;
					const int p3 = (int)(word >> 16) & 15; const int px3 = lut_mid[p3]; if (px3 >= 0) dst[3] = (uint16_t)px3;
					const int p4 = (int)(word >> 12) & 15; const int px4 = lut_mid[p4]; if (px4 >= 0) dst[4] = (uint16_t)px4;
					const int p5 = (int)(word >> 8) & 15; const int px5 = lut_mid[p5]; if (px5 >= 0) dst[5] = (uint16_t)px5;
					const int p6 = (int)(word >> 4) & 15; const int px6 = lut_mid[p6]; if (px6 >= 0) dst[6] = (uint16_t)px6;
					const int p7 = (int)(word)& 15; const int px7 = lut_end[p7]; if (px7 >= 0) dst[7] = (uint16_t)px7;
					dst += 8; n -= 8;
					if (end_pen != 0 && p7 == 15) break;
				}
				else
				{
					for (int index = 0; index < n; index++) {
						const int pen = (int)(word >> (28 - 4 * index)) & 15;
						const int px = (index == 0 ? lut_end : lut_mid)[pen];
						if (px >= 0) dst[index] = (uint16_t)px;
					}
					n = 0;
				}
			}
			return;
		}

		/* Fast-path para sombras sin voltear */
		if (x_delta == 1 && shadow)
		{
			while (n > 0)
			{
				uint32_t word = !from_ram ? rom_ptr[rom_idx++] : sprite_graphics(true, bank, address);
				if (!from_ram && rom_idx >= video.sprite_rom_words) rom_idx = 0;
				address++;
				dbg_words_1to1++;

				if (n >= 8)
				{
					if (word == 0 && skip_zero) { dst += 8; n -= 8; continue; }
					const int p0 = (int)(word >> 28) & 15; if (lut_end[p0] >= 0) dst[0] &= 0x7fff;
					const int p1 = (int)(word >> 24) & 15; if (lut_mid[p1] >= 0) dst[1] &= 0x7fff;
					const int p2 = (int)(word >> 20) & 15; if (lut_mid[p2] >= 0) dst[2] &= 0x7fff;
					const int p3 = (int)(word >> 16) & 15; if (lut_mid[p3] >= 0) dst[3] &= 0x7fff;
					const int p4 = (int)(word >> 12) & 15; if (lut_mid[p4] >= 0) dst[4] &= 0x7fff;
					const int p5 = (int)(word >> 8) & 15; if (lut_mid[p5] >= 0) dst[5] &= 0x7fff;
					const int p6 = (int)(word >> 4) & 15; if (lut_mid[p6] >= 0) dst[6] &= 0x7fff;
					const int p7 = (int)(word)& 15; if (lut_end[p7] >= 0) dst[7] &= 0x7fff;
					dst += 8; n -= 8;
					if (end_pen != 0 && p7 == 15) break;
				}
				else
				{
					for (int index = 0; index < n; index++) {
						const int pen = (int)(word >> (28 - 4 * index)) & 15;
						if ((index == 0 ? lut_end : lut_mid)[pen] >= 0) dst[index] &= 0x7fff;
					}
					n = 0;
				}
			}
			return;
		}

		/* Caso volteado (flip horizontal x_delta == -1) con salto de ceros y desenrollado */
		while (n > 0)
		{
			uint32_t word = !from_ram ? rom_ptr[rom_idx++] : sprite_graphics(true, bank, address);
			if (!from_ram && rom_idx >= video.sprite_rom_words) rom_idx = 0;
			address++;
			dbg_words_1to1++;

			if (n >= 8)
			{
				if (word == 0 && skip_zero) { dst -= 8; n -= 8; continue; }
				const int p0 = (int)(word >> 28) & 15; const int px0 = lut_end[p0]; if (px0 >= 0) { if (!shadow) dst[0] = (uint16_t)px0; else dst[0] &= 0x7fff; }
				const int p1 = (int)(word >> 24) & 15; const int px1 = lut_mid[p1]; if (px1 >= 0) { if (!shadow) dst[-1] = (uint16_t)px1; else dst[-1] &= 0x7fff; }
				const int p2 = (int)(word >> 20) & 15; const int px2 = lut_mid[p2]; if (px2 >= 0) { if (!shadow) dst[-2] = (uint16_t)px2; else dst[-2] &= 0x7fff; }
				const int p3 = (int)(word >> 16) & 15; const int px3 = lut_mid[p3]; if (px3 >= 0) { if (!shadow) dst[-3] = (uint16_t)px3; else dst[-3] &= 0x7fff; }
				const int p4 = (int)(word >> 12) & 15; const int px4 = lut_mid[p4]; if (px4 >= 0) { if (!shadow) dst[-4] = (uint16_t)px4; else dst[-4] &= 0x7fff; }
				const int p5 = (int)(word >> 8) & 15; const int px5 = lut_mid[p5]; if (px5 >= 0) { if (!shadow) dst[-5] = (uint16_t)px5; else dst[-5] &= 0x7fff; }
				const int p6 = (int)(word >> 4) & 15; const int px6 = lut_mid[p6]; if (px6 >= 0) { if (!shadow) dst[-6] = (uint16_t)px6; else dst[-6] &= 0x7fff; }
				const int p7 = (int)(word)& 15; const int px7 = lut_end[p7]; if (px7 >= 0) { if (!shadow) dst[-7] = (uint16_t)px7; else dst[-7] &= 0x7fff; }
				dst -= 8; n -= 8;
				if (end_pen != 0 && p7 == 15) break;
			}
			else
			{
				for (int index = 0; index < n; index++) {
					const int pen = (int)(word >> (28 - 4 * index)) & 15;
					const int px = (index == 0 ? lut_end : lut_mid)[pen];
					if (px >= 0) {
						if (!shadow) dst[-index] = (uint16_t)px;
						else dst[-index] &= 0x7fff;
					}
				}
				n = 0;
			}
		}
		return;
	}

	/* camino con clip: lectura directa de ROM sin modulo ni funciones intermedias */
	const bool skip_zero_slow = sprite->lut_end[0] < 0;
	const uint32_t *rom_ptr = (const uint32_t *)video.sprite_rom;
	uint32_t rom_idx = (bank << 20) | (address & 0xfffff);
	if (rom_idx >= video.sprite_rom_words) rom_idx %= (video.sprite_rom_words ? video.sprite_rom_words : 1);

	/* Si empieza a la izquierda de la pantalla, saltar palabras completas de 8 p�xeles fuera de pantalla */
	if (x_delta == 1 && x < clip_left)
	{
		const int skip_words = (clip_left - x) / 8;
		if (skip_words > 0)
		{
			x += skip_words * 8;
			address += (uint32_t)skip_words;
			if (!from_ram)
				rom_idx = (rom_idx + (uint32_t)skip_words) % (video.sprite_rom_words ? video.sprite_rom_words : 1);
		}
	}
	else if (x_delta == -1 && x > clip_right)
	{
		const int skip_words = (x - clip_right) / 8;
		if (skip_words > 0)
		{
			x -= skip_words * 8;
			address += (uint32_t)skip_words;
			if (!from_ram)
				rom_idx = (rom_idx + (uint32_t)skip_words) % (video.sprite_rom_words ? video.sprite_rom_words : 1);
		}
	}

	while (x != x_end)
	{
		const uint32_t word = !from_ram ? rom_ptr[rom_idx++] : sprite_graphics(true, bank, address);
		if (!from_ram && rom_idx >= video.sprite_rom_words) rom_idx = 0;
		address++;
		int pen = 0;

		dbg_words_1to1++;

		/* Si las 8 palabras caen completamente dentro de la presa (enmascaradas), saltarlas de golpe */
		if (x_delta == 1 && leave_alone && x >= alone_left && x + 7 <= alone_right)
		{
			x += 8;
			continue;
		}
		if (x_delta == -1 && leave_alone && x - 7 >= alone_left && x <= alone_right)
		{
			x -= 8;
			continue;
		}

		/* Si las 8 palabras est�n libres de la presa y dentro de la pantalla, escribir directo a toda velocidad */
		if (x_delta == 1 && (!leave_alone || (x + 7 < alone_left || x > alone_right)) && x >= clip_left && x + 7 <= clip_right)
		{
			uint16_t *dst = row + x;
			const int *lut_mid = sprite->lut_mid;
			const int *lut_end = sprite->lut_end;
			if (word == 0 && skip_zero_slow) { x += 8; continue; }
			if (!shadow)
			{
				const int p0 = (int)(word >> 28) & 15; const int px0 = lut_end[p0]; if (px0 >= 0) dst[0] = (uint16_t)px0;
				const int p1 = (int)(word >> 24) & 15; const int px1 = lut_mid[p1]; if (px1 >= 0) dst[1] = (uint16_t)px1;
				const int p2 = (int)(word >> 20) & 15; const int px2 = lut_mid[p2]; if (px2 >= 0) dst[2] = (uint16_t)px2;
				const int p3 = (int)(word >> 16) & 15; const int px3 = lut_mid[p3]; if (px3 >= 0) dst[3] = (uint16_t)px3;
				const int p4 = (int)(word >> 12) & 15; const int px4 = lut_mid[p4]; if (px4 >= 0) dst[4] = (uint16_t)px4;
				const int p5 = (int)(word >> 8) & 15; const int px5 = lut_mid[p5]; if (px5 >= 0) dst[5] = (uint16_t)px5;
				const int p6 = (int)(word >> 4) & 15; const int px6 = lut_mid[p6]; if (px6 >= 0) dst[6] = (uint16_t)px6;
				const int p7 = (int)(word)& 15; const int px7 = lut_end[p7]; if (px7 >= 0) dst[7] = (uint16_t)px7;
				x += 8;
				if (end_pen != 0 && p7 == 15) break;
			}
			else
			{
				const int p0 = (int)(word >> 28) & 15; if (lut_end[p0] >= 0) dst[0] &= 0x7fff;
				const int p1 = (int)(word >> 24) & 15; if (lut_mid[p1] >= 0) dst[1] &= 0x7fff;
				const int p2 = (int)(word >> 20) & 15; if (lut_mid[p2] >= 0) dst[2] &= 0x7fff;
				const int p3 = (int)(word >> 16) & 15; if (lut_mid[p3] >= 0) dst[3] &= 0x7fff;
				const int p4 = (int)(word >> 12) & 15; if (lut_mid[p4] >= 0) dst[4] &= 0x7fff;
				const int p5 = (int)(word >> 8) & 15; if (lut_mid[p5] >= 0) dst[5] &= 0x7fff;
				const int p6 = (int)(word >> 4) & 15; if (lut_mid[p6] >= 0) dst[6] &= 0x7fff;
				const int p7 = (int)(word)& 15; if (lut_end[p7] >= 0) dst[7] &= 0x7fff;
				x += 8;
				if (end_pen != 0 && p7 == 15) break;
			}
			continue;
		}

		if (x_delta == -1 && (!leave_alone || (x < alone_left || x - 7 > alone_right)) && x - 7 >= clip_left && x <= clip_right)
		{
			uint16_t *dst = row + x;
			const int *lut_mid = sprite->lut_mid;
			const int *lut_end = sprite->lut_end;
			if (word == 0 && skip_zero_slow) { x -= 8; continue; }
			if (!shadow)
			{
				const int p0 = (int)(word >> 28) & 15; const int px0 = lut_end[p0]; if (px0 >= 0) dst[0] = (uint16_t)px0;
				const int p1 = (int)(word >> 24) & 15; const int px1 = lut_mid[p1]; if (px1 >= 0) dst[-1] = (uint16_t)px1;
				const int p2 = (int)(word >> 20) & 15; const int px2 = lut_mid[p2]; if (px2 >= 0) dst[-2] = (uint16_t)px2;
				const int p3 = (int)(word >> 16) & 15; const int px3 = lut_mid[p3]; if (px3 >= 0) dst[-3] = (uint16_t)px3;
				const int p4 = (int)(word >> 12) & 15; const int px4 = lut_mid[p4]; if (px4 >= 0) dst[-4] = (uint16_t)px4;
				const int p5 = (int)(word >> 8) & 15; const int px5 = lut_mid[p5]; if (px5 >= 0) dst[-5] = (uint16_t)px5;
				const int p6 = (int)(word >> 4) & 15; const int px6 = lut_mid[p6]; if (px6 >= 0) dst[-6] = (uint16_t)px6;
				const int p7 = (int)(word)& 15; const int px7 = lut_end[p7]; if (px7 >= 0) dst[-7] = (uint16_t)px7;
				x -= 8;
				if (end_pen != 0 && p7 == 15) break;
			}
			else
			{
				const int p0 = (int)(word >> 28) & 15; if (lut_end[p0] >= 0) dst[0] &= 0x7fff;
				const int p1 = (int)(word >> 24) & 15; if (lut_mid[p1] >= 0) dst[-1] &= 0x7fff;
				const int p2 = (int)(word >> 20) & 15; if (lut_mid[p2] >= 0) dst[-2] &= 0x7fff;
				const int p3 = (int)(word >> 16) & 15; if (lut_mid[p3] >= 0) dst[-3] &= 0x7fff;
				const int p4 = (int)(word >> 12) & 15; if (lut_mid[p4] >= 0) dst[-4] &= 0x7fff;
				const int p5 = (int)(word >> 8) & 15; if (lut_mid[p5] >= 0) dst[-5] &= 0x7fff;
				const int p6 = (int)(word >> 4) & 15; if (lut_mid[p6] >= 0) dst[-6] &= 0x7fff;
				const int p7 = (int)(word)& 15; if (lut_end[p7] >= 0) dst[-7] &= 0x7fff;
				x -= 8;
				if (end_pen != 0 && p7 == 15) break;
			}
			continue;
		}

		if (word == 0 && skip_zero_slow && (!leave_alone || (x_delta == 1 ? (x + 7 < alone_left || x > alone_right) : (x < alone_left || x - 7 > alone_right))))
		{
			int step = (x_end - x) * x_delta;
			if (step > 8) step = 8;
			x += step * x_delta;
			continue;
		}
		for (int index = 0; index < 8 && x != x_end; index++, x += x_delta)
		{
			const int *lut = (index == 0 || index == 7) ? sprite->lut_end : sprite->lut_mid;
			int pixel;

			pen = (int)(word >> (28 - 4 * index)) & 15;
			pixel = lut[pen];
			if (pixel >= 0 && x >= clip_left && x <= clip_right
				&& !(leave_alone && x >= alone_left && x <= alone_right))
			{
				if (!shadow)
					row[x] = (uint16_t)pixel;
				else
					row[x] &= 0x7fff;
			}
		}
		if (end_pen != 0 && pen == 15)
			break;
	}
}

static uint32_t sprite_rows_mask[8];

/* A sprite entry (8 words): flags, source height and width, screen height (and bank bits), screen
width, y, x, the graphics' offset in the bank, and the color. Hands back how many more entries it
takes: an indirect table kept in the list takes two. */
static int draw_sprite(uint32_t entry, int x_offset, int y_offset, const area *inside, const area *outside)
{
	static const uint16_t transparent_bits[4][4] = {
		{ 0x7fff, 0x3fff, 0x1fff, 0x0fff },
		{ 0x3fff, 0x1fff, 0x0fff, 0x07ff },
		{ 0x3fff, 0x1fff, 0x0fff, 0x07ff },
		{ 0x1fff, 0x0fff, 0x07ff, 0x03ff }
	};
	const uint8_t *latched = s32_board.sprite_control_latched;
	const uint16_t flags = sprite_word(entry);
	const uint16_t size = sprite_word(entry + 1);
	const uint16_t height_word = sprite_word(entry + 2);
	const uint16_t width_word = sprite_word(entry + 3);
	const bool table_inline = bit(flags, 12);
	const bool from_ram = bit(flags, 10);
	const bool flip_y = bit(flags, 7);
	const bool flip_x = bit(flags, 6);
	const int source_height = size >> 8;
	const int height = height_word & 0x3ff;
	const int width = width_word & 0x3ff;
	const uint32_t bank = ((width_word & 0x0800) >> 11 | (width_word & 0x4000) >> 13) % (video.sprite_banks ? video.sprite_banks : 1);
	const int taken = (bit(flags, 13) && table_inline) ? 2 : 0;
	sprite_drawing sprite;
	int source_width;
	int end_pen;
	int x;
	int y;
	int x_delta = 1;
	int y_delta = 1;
	int x_end;
	int y_end;
	int x_zoom;
	int y_zoom;
	int y_accumulator = 0;
	uint32_t address = sprite_word(entry + 6) | (uint32_t)(height_word & 0xf000) << 4;

	sprite.inside = inside;
	sprite.outside = outside;
	sprite.indirect = bit(flags, 13);
	sprite.shadow = bit(flags, 11) && bit(latched[5], 0);
	sprite.bits8 = bit(flags, 9);
	sprite.color = 0x8000 | (sprite_word(entry + 7) & (sprite.bits8 ? 0x7f00 : 0x7ff0));
	source_width = sprite.bits8 ? (size & 0x3f) : ((size >> 1) & 0x3f);
	end_pen = bit(flags, 8) ? 0 : (sprite.bits8 ? 0xff : 0x0f);
	if (source_width == 0 || source_height == 0 || width == 0 || height == 0)
		return taken;

	sprite.transparent_bits = transparent_bits[latched[4] & 3][latched[5] & 3];
	if (sprite.bits8)
		sprite.transparent_bits &= 0xfff0;
	if (sprite.indirect)
	{
		/* the table follows the entry, or is an entry of the list picked by the color word */
		const uint32_t table = table_inline ? entry + 8 : 8 * (uint32_t)(sprite_word(entry + 7) & 0x1fff);

		for (int index = 0; index < 16; index++)
			sprite.table[index] = (uint16_t)((sprite_word(table + (uint32_t)index) & (sprite.bits8 ? 0xfff0 : 0xffff)) |
			(bit(latched[5], 0) ? 0x8000 : 0));
	}

	if (s32_video_sprite_observer != NULL && !from_ram)
	{
		/* the pixel each pen puts in the buffer, as put_sprite_pixel works it out */
		uint16_t pixels[256];
		const int pens = sprite.bits8 ? 256 : 16;

		for (int pen = 0; pen < pens; pen++)
			pixels[pen] = (uint16_t)(!sprite.indirect ? (sprite.color | pen)
			: (sprite.bits8 ? sprite.table[pen >> 4] | (pen & 0x0f) : sprite.table[pen]));
		s32_video_sprite_observer(bank << 20 | (address & 0xfffff), source_width, source_height, sprite.bits8,
			end_pen == 0, pixels);
	}

	x_zoom = (((sprite.bits8 ? 4 : 8) * source_width) << 16) / width;
	y_zoom = (source_height << 16) / height;

	sprite.one_to_one = !sprite.bits8 && x_zoom == 0x10000;
	if (sprite.one_to_one)
	{
		for (int pen = 0; pen < 16; pen++)
		{
			int pixel;

			if (!sprite.indirect)
				pixel = pen != 0 ? (sprite.color | pen) : -1;
			else
			{
				pixel = sprite.table[pen];
				if ((pixel & sprite.transparent_bits) == sprite.transparent_bits)
					pixel = -1;
			}
			sprite.lut_end[pen] = pen != end_pen ? pixel : -1;
			sprite.lut_mid[pen] = pen != 0 ? pixel : -1;
		}
	}

	/* place it: the list's offset, then its alignment (0 or 3 centered, 1 by the far edge, 2 by the near) */
	x = sign_extend(sprite_word(entry + 5), 12) + (bit(flags, 4) ? x_offset : 0) + video.sprite_side;
	y = sign_extend(sprite_word(entry + 4), 12) + (bit(flags, 5) ? y_offset : 0);
	switch (flags & 3)
	{
	case 0:
	case 3: x -= (width - 1) / 2; break;
	case 1: x -= width - 1; break;
	default: break;
	}
	switch ((flags >> 2) & 3)
	{
	case 0:
	case 3: y -= (height - 1) / 2; break;
	case 1: y -= height - 1; break;
	default: break;
	}
	if (flip_x)
	{
		x += width - 1;
		x_delta = -1;
	}
	if (flip_y)
	{
		y += height - 1;
		y_delta = -1;
	}
	x_end = x + x_delta * width;
	y_end = y + y_delta * height;

	/* rows end at the sprite's width, or at the clip. (MAME tests a flipped sprite's end against the clip's
	right edge instead of its left one, so the sprite runs on to the left edge reading whatever follows
	it in the ROM: an opaque one, which ignores end codes, leaves copies of the next frames there. The
	reference, tools/reference/mame/sega/segas32_v.cpp, has the same line fixed.) */
	/* Descarte inmediato si el sprite cae completamente fuera de la pantalla */
	const int min_x = x_delta > 0 ? x : x_end + 1;
	const int max_x = x_delta > 0 ? x_end - 1 : x;
	if (max_x < inside->left || min_x > inside->right)
		return taken;

	const int min_y = y_delta > 0 ? y : y_end + 1;
	const int max_y = y_delta > 0 ? y_end - 1 : y;
	if (max_y < inside->top || min_y > inside->bottom)
		return taken;

	if (x_delta > 0 && x_end > inside->right)
		x_end = inside->right + 1;
	if (x_delta < 0 && x_end < inside->left)
		x_end = inside->left - 1;

	for (int row = y; (y_delta > 0 ? row < y_end : row > y_end); row += y_delta)
	{
		if (row >= inside->top && row <= inside->bottom)
		{
			sprite_rows_mask[row >> 5] |= (1u << (row & 31));
			sprite.row = video.sprites[video.shown_sprites ^ 1][row];
			sprite.outside_row = row >= outside->top && row <= outside->bottom;
			if (sprite.one_to_one)
				draw_sprite_row_1to1(&sprite, from_ram, bank, address, x, x_end, x_delta, end_pen);
			else
				draw_sprite_row(&sprite, from_ram, bank, address, x, x_end, x_delta, x_zoom, end_pen);
		}
		/* the zoom steps through the source rows */
		y_accumulator += y_zoom;
		address += (uint32_t)(source_width * (y_accumulator >> 16));
		y_accumulator &= 0xffff;
	}
	return taken;
}

/* The list in sprite RAM, 16 bytes an entry, its command in the top two bits of the first word: draw a
sprite, set the clips (bit 12 the one to draw in, bit 13 the one to leave alone), jump (and with
bit 13, set the offset sprites can add), or end. */
static unsigned dbg_sprites_drawn;    /* sprites dibujados desde el �ltimo informe */

static void draw_sprite_list(void)
{
	const bool wide = video.wide && !bit(s32_board.sprite_control_latched[6], 0);
	const int side = wide ? S32_VIDEO_WIDE_SIDE : 0;
	const area screen = { 0, wide || bit(s32_board.sprite_control_latched[6], 0) ? 415 : 319, 0, HEIGHT - 1 };
	area inside = screen;
	area outside = { 0, -1, 0, -1 };
	int x_offset = 0;

	video.sprite_side = side;
	int y_offset = 0;
	int number = 0;

	for (int entries = 0; entries < 0x20000 / 16; entries++)
	{
		const uint32_t entry = 8 * (uint32_t)(number & 0x1fff);
		const uint16_t command = sprite_word(entry);

		switch (command >> 14)
		{
		case 0:
			dbg_sprites_drawn++;
			number += 1 + draw_sprite(entry, x_offset, y_offset, &inside, &outside);
			break;
		case 1:
			if (bit(command, 12))
			{
				inside.left = sign_extend(sprite_word(entry + 2), 12);
				inside.right = sign_extend(sprite_word(entry + 3), 12);
				inside.top = sign_extend(command, 12);
				inside.bottom = sign_extend(sprite_word(entry + 1), 12);
				if (wide && inside.left <= 0 && inside.right >= 319)
					inside.right = screen.right;    /* (the whole screen: the wide one) */
				else
				{
					inside.left += side;
					inside.right += side;
				}
				clip_area(&inside, &screen);
			}
			if (bit(command, 13))
			{
				outside.left = sign_extend(sprite_word(entry + 6), 12) + side;
				outside.right = sign_extend(sprite_word(entry + 7), 12) + side;
				outside.top = sign_extend(sprite_word(entry + 4), 12);
				outside.bottom = sign_extend(sprite_word(entry + 5), 12);
			}
			number++;
			break;
		case 2:
			if (bit(command, 13))
			{
				y_offset = sign_extend(sprite_word(entry + 1), 12);
				x_offset = sign_extend(sprite_word(entry + 2), 12);
			}
			number = command & 0x1fff;
			break;
		default:
			return;
		}
	}
}

void s32_video_sprites(bool erase, bool draw)
{
#if defined(__CELLOS_LV2__) || defined(__SNC__) || defined(__PS3__)
	static uint64_t sprite_ticks, erase_ticks, report_frame;
	const uint64_t t0 = __mftb();
	uint64_t t_erase = t0;
#endif
	if (erase)
	{
		/* 0xffff en cada uint16_t = todos los bytes en 0xff */
		memset(&video.sprites[video.shown_sprites][0][0], 0xff, sizeof(video.sprites[0]));
#if defined(__CELLOS_LV2__) || defined(__SNC__) || defined(__PS3__)
		t_erase = __mftb();
#endif
	}
	if (draw)
	{
		memset(sprite_rows_mask, 0, sizeof(sprite_rows_mask));
		video.shown_sprites ^= 1;
		draw_sprite_list();
	}
#if defined(__CELLOS_LV2__) || defined(__SNC__) || defined(__PS3__)
	(void)t0;
	(void)t_erase;
	(void)sprite_ticks;
	(void)erase_ticks;
	(void)report_frame;
#endif
}

/* ---- the mixer ---- */

/* Which color offset a layer takes (0x3E bit 15 and the layer's bit there pick how its own flag counts) */
static uint8_t color_offsets(bool layer_bit, bool layer_flag)
{
	switch ((bit(mixer_register(0x3e), 15) ? 2 : 0) | (layer_bit ? 1 : 0))
	{
	case 1: return 2;
	case 2: return layer_flag ? 0 : 2;
	default: return layer_flag ? 0 : 1;
	}
}

/* The sprite groups a layer blends with: the group equal to a value, at most it, at least it, or all */
static uint16_t sprite_blend(int encoding)
{
	const int value = encoding & 0x0f;

	switch ((encoding >> 4) & 3)
	{
	case 0: return (uint16_t)(1 << value);
	case 1: return (uint16_t)((1 << value) | ((1 << value) - 1));
	case 2: return (uint16_t)(~((1 << value) - 1) & 0xffff);
	default: return 0xffff;
	}
}

typedef struct sprite_grouping
{
	uint8_t shift;      /* where the group is in a sprite pixel */
	uint8_t mask;
	uint8_t base;       /* the first group's priority register */
} sprite_grouping;

/* The sprite groupings register 0x4C picks */
static const sprite_grouping groupings[16] = {
	{ 14, 0x00, 0x01 }, { 14, 0x01, 0x02 }, { 13, 0x03, 0x04 }, { 12, 0x07, 0x08 },
	{ 14, 0x01, 0x00 }, { 13, 0x03, 0x00 }, { 12, 0x07, 0x00 }, { 11, 0x0f, 0x00 },
	{ 14, 0x01, 0x00 }, { 13, 0x03, 0x00 }, { 12, 0x07, 0x00 }, { 11, 0x0f, 0x00 },
	{ 13, 0x01, 0x00 }, { 12, 0x03, 0x00 }, { 11, 0x07, 0x00 }, { 10, 0x0f, 0x00 }
};

/* The first layer down the list that is not transparent there; the backdrop always is. A sprite pixel
all ones lets the layers below show, and the shadow pen darkens them. */
static const mix_layer *top_layer(const mix_layer *entry, const uint16_t *const *rows, int x, int sprite_pixel,
	int shadow_mask, int sprite_bits, int shadow_pen, int *pixel, int *shadow)
{
	for (;; entry++)
	{
		if (entry->index != LAYER_SPRITES)
		{
			*pixel = rows[entry->index][x] & 0x1fff;
			if (*pixel != 0 || entry->index == LAYER_BACKDROP)
				return entry;
			continue;
		}
		*pixel = sprite_pixel;
		*shadow = ~sprite_pixel & shadow_mask;
		if ((sprite_pixel & 0x7fff) != 0x7fff)
		{
			*pixel = sprite_pixel & sprite_bits;
			if ((*pixel & 0x7ffe) != shadow_pen)
				return entry;
			*shadow = 1;
		}
	}
}

static uint16_t palette_color(const mix_layer *entry, int pixel)
{
	return s32_board.palette[(entry->palette_base + ((pixel >> entry->shift) & 0xfff0) + (pixel & 0x0f)) & 0x3fff];
}

uint16_t s32_video_tile_pen_color(int tilemap, uint16_t color, int pen)
{
	const uint16_t control = mixer_register(0x20 + 2 * (uint32_t)(LAYER_NBG0 + tilemap));
	mix_layer layer;

	layer.palette_base = (uint16_t)((control & 0x00f0) << 6);
	layer.shift = (control >> 8) & 3;
	return palette_color(&layer, ((color & 0x1ff) << 4 | (pen & 0x0f)) & 0x1fff);
}

uint16_t s32_video_sprite_pixel_color(uint16_t pixel)
{
	const uint16_t sprite_control = mixer_register(0x4c);
	const sprite_grouping grouping = groupings[sprite_control & 0x0f];
	const int group = (pixel >> grouping.shift) & grouping.mask;
	const uint16_t control = mixer_register(2 * (uint32_t)(grouping.base | group));
	mix_layer sprites;

	sprites.palette_base = (uint16_t)((((sprite_control & 3) != 3) ? control : sprite_control) & 0x00f0) << 6;
	sprites.shift = (control >> 8) & 3;
	return palette_color(&sprites, pixel & (((1 << grouping.shift) - 1) & 0x3fff));
}

/* What the mixer mixes with, the same on every row of a frame: the layers' order under each sprite group */
typedef struct mix_frame
{
	int blend_factor;
	sprite_grouping grouping;
	int shadow_mask;
	int sprite_bits;
	int shadow_pen;
	uint8_t sprite_flips;
	int offsets[3][3];
	mix_layer orders[16][8];
} mix_frame;

static void mix_rows(void *context, int first, int last)
{
	const mix_frame *frame = (const mix_frame *)context;
	const int blend_factor = frame->blend_factor;
	const sprite_grouping grouping = frame->grouping;

	for (int y = first; y <= last; y++)
	{
		const uint16_t *rows[LAYERS];
		/* (the sprite buffer is scanned flipped as the sprite controls say) */
		const int sprite_y = bit(frame->sprite_flips, 1) ? video.visible.bottom - (y - video.visible.top) : y;
		int sprite_x = bit(frame->sprite_flips, 0) ? video.visible.right : video.visible.left;
		const int sprite_dx = bit(frame->sprite_flips, 0) ? -1 : 1;

		for (int index = LAYER_TEXT; index <= LAYER_BITMAP; index++)
			rows[index] = video.layers[index].empty[y] ? transparent_row : video.layers[index].pixels[y];
		rows[LAYER_SPRITES] = video.sprites[video.shown_sprites][sprite_y];
		rows[LAYER_BACKDROP] = video.layers[LAYER_BACKDROP].pixels[y];

		const mix_layer *fast_entries[8];
		const uint16_t *fast_rows[8];
		int fast_count = 0;
		bool fast = true;

		for (const mix_layer *entry = frame->orders[grouping.mask];; entry++)
		{
			const int *offs;

			if (entry->index == LAYER_SPRITES)
				continue;
			if (entry->index != LAYER_BACKDROP && video.layers[entry->index].empty[y])
				continue;
			offs = frame->offsets[entry->offsets];
			if (entry->blend != 0 || (offs[0] | offs[1] | offs[2]) != 0)
				fast = false;
			fast_entries[fast_count] = entry;
			fast_rows[fast_count++] = entry->index == LAYER_BACKDROP
				? video.layers[LAYER_BACKDROP].pixels[y] : video.layers[entry->index].pixels[y];
			if (entry->index == LAYER_BACKDROP)
				break;
		}

		for (int x = video.visible.left; x <= video.visible.right; x++, sprite_x += sprite_dx)
		{
			const int sprite_pixel = rows[LAYER_SPRITES][sprite_x];
			if (fast && sprite_pixel == 0xffff)
			{
				const mix_layer *top = fast_entries[fast_count - 1];
				int pixel = fast_rows[fast_count - 1][x] & 0x1fff;

				for (int k = 0; k < fast_count - 1; k++)
				{
					const int value = fast_rows[k][x] & 0x1fff;

					if (value)
					{
						pixel = value;
						top = fast_entries[k];
						break;
					}
				}
				video.frame[y][x] = palette_argb[(top->palette_base + ((pixel >> top->shift) & 0xfff0) + (pixel & 0x0f)) & 0x3fff];
				continue;
			}
			const int group = (sprite_pixel >> grouping.shift) & grouping.mask;
			int shadow = 0;
			int pixel;
			const mix_layer *first_layer = top_layer(frame->orders[group], rows, x, sprite_pixel, frame->shadow_mask,
				frame->sprite_bits, frame->shadow_pen, &pixel, &shadow);
			uint16_t color = palette_color(first_layer, pixel);
			const int *first_offsets = frame->offsets[first_layer->offsets];
			int red, green, blue;

			if (first_layer->blend == 0 && !shadow && (first_offsets[0] | first_offsets[1] | first_offsets[2]) == 0)
			{
				video.frame[y][x] = 0xFF000000u | (uint32_t)(color & 0x1f) << 19 | (uint32_t)((color >> 5) & 0x1f) << 11
					| (uint32_t)((color >> 10) & 0x1f) << 3;
				continue;
			}
			red = (color & 0x1f) + first_offsets[0];
			green = ((color >> 5) & 0x1f) + first_offsets[1];
			blue = ((color >> 10) & 0x1f) + first_offsets[2];

			if (first_layer->blend != 0)
			{
				int below;
				const mix_layer *second = top_layer(first_layer + 1, rows, x, sprite_pixel, frame->shadow_mask,
					frame->sprite_bits, frame->shadow_pen, &below, &shadow);

				if (bit(first_layer->blend, second->index)
					&& (second->index != LAYER_SPRITES || bit(first_layer->sprite_blend, group)))
				{
					color = palette_color(second, below);
					red = shift_down(red * (7 - blend_factor) + ((color & 0x1f) + frame->offsets[second->offsets][0]) * (blend_factor + 1), 3);
					green = shift_down(green * (7 - blend_factor) + (((color >> 5) & 0x1f) + frame->offsets[second->offsets][1]) * (blend_factor + 1), 3);
					blue = shift_down(blue * (7 - blend_factor) + (((color >> 10) & 0x1f) + frame->offsets[second->offsets][2]) * (blend_factor + 1), 3);
				}
			}
			if (shadow)
			{
				red = shift_down(red, 1);
				green = shift_down(green, 1);
				blue = shift_down(blue, 1);
			}
			red = red > 31 ? 31 : (red > 0 ? red : 0);
			green = green > 31 ? 31 : (green > 0 ? green : 0);
			blue = blue > 31 ? 31 : (blue > 0 ? blue : 0);
			video.frame[y][x] = 0xFF000000u | (uint32_t)red << 19 | (uint32_t)green << 11 | (uint32_t)blue << 3;
		}
	}
}

#if defined(__CELLOS_LV2__) || defined(__SNC__) || defined(__PS3__)
#define SPU_MIX_CHECK_EVERY 0 /* cada tantos frames compara con la mezcla de la PPU (0: nunca) */

static uint32_t s_palette_version = 1;

/* Mezcla las filas en los SPU (spu_mix_rows.c). false: no se pudo, que las mezcle la PPU */
static bool spu_mix_frame(const mix_frame *frame)
{
	static unsigned checked;
	spu_mix_control_t *first = spu_host_mix_ctrl(0);
	const int spus = spu_host_video_spus();
	const int rows = video.visible.bottom - video.visible.top + 1;
	int next_row = video.visible.top;

	if (!spu_host_video_ready() || video.visible.left != 0)
		return false;

	for (int layer = 0; layer < SPU_MIX_INPUT_LAYERS; layer++)
	{
		first->ea_layer_rows[layer] = (uint64_t)(uintptr_t)&video.layers[layer].pixels[0][0];
		first->ea_layer_empty[layer] = (uint64_t)(uintptr_t)&video.layers[layer].empty[0];
	}
	first->ea_backdrop = (uint64_t)(uintptr_t)&video.layers[LAYER_BACKDROP].pixels[0][0];
	first->ea_sprites = (uint64_t)(uintptr_t)&video.sprites[video.shown_sprites][0][0];
	first->ea_palette = (uint64_t)(uintptr_t)palette_argb;
	first->ea_frame = (uint64_t)(uintptr_t)&video.frame[0][0];
	first->left = video.visible.left;
	first->right = video.visible.right;
	first->top = video.visible.top;
	first->bottom = video.visible.bottom;
	first->blend_factor = frame->blend_factor;
	first->grouping_shift = frame->grouping.shift;
	first->grouping_mask = frame->grouping.mask;
	first->shadow_mask = frame->shadow_mask;
	first->sprite_bits = frame->sprite_bits;
	first->shadow_pen = frame->shadow_pen;
	first->sprite_flips = frame->sprite_flips;
	first->palette_version = s_palette_version;
	first->backdrop_control = video_register(0x5e);
	for (int i = 0; i < 8; i++)
		first->sprite_rows_mask[i] = sprite_rows_mask[i];
	for (int row = 0; row < 3; row++)
	for (int channel = 0; channel < 3; channel++)
		first->offsets[row][channel] = frame->offsets[row][channel];
	for (int group = 0; group < 16; group++)
	for (int place = 0; place < 8; place++)
	{
		const mix_layer *from = &frame->orders[group][place];
		spu_mix_layer_t *to = &first->orders[group][place];

		to->palette_base = from->palette_base;
		to->sprite_blend = from->sprite_blend;
		to->blend = from->blend;
		to->index = from->index;
		to->priority = from->priority;
		to->shift = from->shift;
		to->offsets = from->offsets;
	}

	for (int spu = 0; spu < spus; spu++)
	{
		const int count = rows / spus + (spu < rows % spus ? 1 : 0);
		spu_mix_control_t *control = spu_host_mix_ctrl(spu);

		if (spu != 0)
			memcpy(control, first, sizeof(*control));
		control->first_row = (uint32_t)next_row;
		control->row_count = (uint32_t)count;
		control->job_done = 0;
		next_row += count;
	}
	if (spu_host_video_mix() != 0)
		return false;

#if SPU_MIX_CHECK_EVERY
	if (++checked % SPU_MIX_CHECK_EVERY == 0)
	{
		static uint32_t from_spu[HEIGHT][WIDTH];
		unsigned different = 0;

		memcpy(from_spu, video.frame, sizeof(from_spu));
		mix_rows((void *)frame, video.visible.top, video.visible.bottom);
		for (int y = video.visible.top; y <= video.visible.bottom; y++)
		for (int x = video.visible.left; x <= video.visible.right; x++)
		if (from_spu[y][x] != video.frame[y][x])
			different++;
		printf("[spumix] comparacion con la PPU: %u pixeles distintos\n", different);
	}
#endif
	return true;
}
#endif

/* The frame from the layers: registers 0x00-0x1E give each sprite group its priority and palette, 0x20-0x2C
each layer, 0x30-0x3A what each blends with, 0x40-0x4A two color offsets, 0x4C the sprite grouping and
shadows, 0x4E blending */
static void mix(int drawn)
{
	const uint16_t blend_control = mixer_register(0x4e);
	const bool blending = bit(blend_control, 11);
	const uint16_t sprite_control = mixer_register(0x4c);
	const sprite_grouping grouping = groupings[sprite_control & 0x0f];
	static mix_frame frame;
	int(*offsets)[3] = frame.offsets;
	mix_layer(*orders)[8] = frame.orders;
	mix_layer sorted[8];
	int count = 0;

	frame.blend_factor = (blend_control >> 8) & 7;
	frame.grouping = grouping;
	frame.shadow_mask = bit(sprite_control, 2) ? 0x8000 : 0;
	frame.sprite_bits = ((1 << grouping.shift) - 1) & 0x3fff;
	frame.shadow_pen = 0x7ffe & frame.sprite_bits;
	frame.sprite_flips = s32_board.sprite_control_latched[2];
	for (int channel = 0; channel < 3; channel++)
	{
		offsets[0][channel] = sign_extend(mixer_register(0x40 + 2 * (uint32_t)channel), 6);
		offsets[1][channel] = sign_extend(mixer_register(0x46 + 2 * (uint32_t)channel), 6);
		offsets[2][channel] = 0;
	}

	/* the layers that are on and have a priority, then the backdrop, from the top down */
	for (int index = LAYER_TEXT; index <= LAYER_BITMAP; index++)
	{
		const uint16_t control = mixer_register(0x20 + 2 * (uint32_t)index);
		const uint16_t blend = mixer_register(0x30 + 2 * (uint32_t)index);

		if (!bit((uint32_t)drawn, index) || (control & 0x0f) == 0)
			continue;
		sorted[count].index = (uint8_t)index;
		sorted[count].priority = (uint8_t)((control & 0x0f) << 3 | (6 - index));
		sorted[count].palette_base = (uint16_t)((control & 0x00f0) << 6);
		sorted[count].shift = (control >> 8) & 3;
		sorted[count].blend = blending ? (uint8_t)((blend >> 6) & 0xff) : 0;
		sorted[count].sprite_blend = sprite_blend(blend & 0x3f);
		sorted[count].offsets = color_offsets(bit(mixer_register(0x3e), index), bit(blend, 14));
		count++;
	}
	sorted[count].index = LAYER_BACKDROP;
	sorted[count].priority = 1 << 3;
	sorted[count].palette_base = (uint16_t)((mixer_register(0x2c) & 0x00f0) << 6);
	sorted[count].shift = (mixer_register(0x2c) >> 8) & 3;
	sorted[count].blend = 0;
	sorted[count].sprite_blend = 0;
	sorted[count].offsets = color_offsets(bit(mixer_register(0x3e), 8), bit(mixer_register(0x3e), 14));
	count++;
	for (int index = 0; index < count; index++)
	for (int other = index + 1; other < count; other++)
	if (sorted[other].priority > sorted[index].priority)
	{
		const mix_layer swap = sorted[other];

		sorted[other] = sorted[index];
		sorted[index] = swap;
	}

	/* each sprite group goes in above the first layer of a lower priority */
	for (int group = 0; group <= grouping.mask; group++)
	{
		const uint16_t control = mixer_register(2 * (uint32_t)(grouping.base | group));
		const int priority = (control & 0x0f) << 3 | 7;
		int place = count;
		int copied = 0;
		mix_layer *sprites;

		for (int index = 0; index < count; index++)
		{
			if (priority > sorted[index].priority && place == count)
				place = copied++;
			orders[group][copied++] = sorted[index];
		}
		sprites = &orders[group][place];
		sprites->index = LAYER_SPRITES;
		sprites->priority = (uint8_t)priority;
		sprites->palette_base = (uint16_t)((((sprite_control & 3) != 3) ? control : sprite_control) & 0x00f0) << 6;
		sprites->shift = (control >> 8) & 3;
		sprites->blend = 0;
		sprites->sprite_blend = 0;
		sprites->offsets = color_offsets(bit(mixer_register(0x3e), 6), bit(sprite_control, 15));
	}
	static bool palette_cache_init = false;
	static uint16_t last_palette[0x4000];

	if (!palette_cache_init)
	{
		for (int i = 0; i < 0x4000; i++)
		{
			const uint16_t c = s32_board.palette[i];
			palette_argb[i] = 0xFF000000u | (uint32_t)(c & 0x1f) << 19 | (uint32_t)((c >> 5) & 0x1f) << 11 | (uint32_t)((c >> 10) & 0x1f) << 3;
			last_palette[i] = c;
		}
		palette_cache_init = true;
		s_palette_version++;
	}
	else if (memcmp(last_palette, s32_board.palette, sizeof(last_palette)) != 0)
	{
		for (int i = 0; i < 0x4000; i++)
		{
			const uint16_t c = s32_board.palette[i];
			if (c != last_palette[i])
			{
				palette_argb[i] = 0xFF000000u | (uint32_t)(c & 0x1f) << 19 | (uint32_t)((c >> 5) & 0x1f) << 11 | (uint32_t)((c >> 10) & 0x1f) << 3;
				last_palette[i] = c;
			}
		}
		s_palette_version++;
	}
#if defined(__CELLOS_LV2__) || defined(__SNC__) || defined(__PS3__)
	if (spu_mix_frame(&frame))
		return;
#endif
	s32_workers_rows(mix_rows, &frame, video.visible.top, video.visible.bottom);
}

/* ---- the frame ---- */

void s32_video_draw_frame(void)
{
	const bool board_wide = bit(video_register(0x00), 15);
	const int width = board_wide || video.wide ? 416 : 320;

	video.side = video.wide && !board_wide ? S32_VIDEO_WIDE_SIDE : 0;
	video.visible.left = 0;
	video.visible.right = width - 1;
	video.visible.top = 0;
	video.visible.bottom = HEIGHT - 1;

	/* the I/O chip's CNT1 output turns the display on */
	if (!bit(s32_board.io_cnt, 1))
	{
		for (int y = 0; y < HEIGHT; y++)
			memset(video.frame[y], 0, (size_t)width * sizeof(video.frame[y][0]));
		return;
	}
	mix(draw_layers());
}

#define BLANK_TILES_MOST 0x8000    /* 4 banks of 8192 tiles */

static uint8_t blank_tiles[BLANK_TILES_MOST];    /* by tile: 0 not looked at yet, 1 blank, 2 drawn */

bool s32_video_cell_blank(uint16_t cell)
{
	const uint32_t bank = (s32_board.tilebank_external & 1) << 1 | ((video_register(0x00) >> 10) & 1);
	const uint32_t tile = (bank << 13 | (cell & 0x1fff)) % video.tile_count % BLANK_TILES_MOST;

	if (blank_tiles[tile] == 0)
	{
		const uint8_t *bytes = &video.tiles[(size_t)tile * 128];
		int index = 0;

		while (index < 128 && bytes[index] == 0)
			index++;
		blank_tiles[tile] = index == 128 ? 1 : 2;
	}
	return blank_tiles[tile] == 1;
}

void s32_video_set_cells(const uint16_t *words, const uint8_t *marks)
{
	own_cell_words = words;
	own_cell_marks = words ? marks : NULL;
}

void s32_video_init(const uint8_t *tiles, size_t tiles_size, const uint8_t *sprites, size_t sprites_size)
{
	memset(&video, 0, sizeof(video));
	memset(blank_tiles, 0, sizeof(blank_tiles));
	video.tiles = tiles;
	video.tile_count = (uint32_t)(tiles_size / 128);
	video.sprite_rom = sprites;
	video.sprite_rom_words = (uint32_t)(sprites_size / 4);
	video.sprite_banks = video.sprite_rom_words >> 20;
	decode_tiles();
	video.visible.right = 319;
	video.visible.bottom = HEIGHT - 1;
	s32_board.sprites_due = s32_video_sprites;
	s32_board.frame_shown = s32_video_draw_frame;
}

void s32_video_set_wide(bool wide)
{
	video.wide = wide;
}

int s32_video_side(void)
{
	return video.side;
}

const uint32_t *s32_video_frame(int *width)
{
	if (width)
		*width = video.visible.right + 1;
	return &video.frame[0][0];
}

uint64_t s32_video_frame_hash(void)
{
	uint64_t hash = 0xcbf29ce484222325ull;

	for (int y = 0; y < HEIGHT; y++)
	for (int x = 0; x <= video.visible.right; x++)
	for (int shift = 0; shift < 24; shift += 8)
		hash = (hash ^ ((video.frame[y][x] >> shift) & 0xff)) * 0x100000001b3ull;
	return hash;
}
