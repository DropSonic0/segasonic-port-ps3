/* ports\ps3\spu_host.c */
/* ports\ps3\spu_host.c */
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <ppu_intrinsics.h>
#include <sys/spu_initialize.h>
#include <sys/spu_image.h>
#include <sys/spu_thread.h>
#include <sys/spu_thread_group.h>
#include <sys/sys_time.h>
#include "spu_host.h"

#define SPU_MSG_RUN     1u
#define SPU_MSG_QUIT    0xFFFFFFFFu
#define NUM_VIDEO_SPUS  4
#define WAIT_TIMEOUT_MS 200
#define FIRST_JOB_MS    3000     /* el primer trabajo tarda ~400 ms: arranque de los hilos */

extern char _binary_spu_renderer_spu_elf_start[];
extern char _binary_spu_sound_spu_elf_start[];

static sys_spu_thread_group_t g_audio_grp, g_video_grp;
static sys_spu_thread_t g_audio_thr, g_video_thr[NUM_VIDEO_SPUS];
static spu_audio_control_t g_audio_ctrl __attribute__((aligned(128)));
static spu_mix_control_t   g_mix_ctrl[NUM_VIDEO_SPUS] __attribute__((aligned(128)));
static int g_spu_ready = 0;
static int g_video_ready = 0;

static int spu_host_start_group(const void *elf, int nthreads, const char *name,
	sys_spu_thread_group_t *grp, sys_spu_thread_t *thr,
	void **ctrl_ptrs)
{
	sys_spu_image_t img;
	sys_spu_thread_group_attribute_t gattr;
	sys_spu_thread_attribute_t tattr;
	sys_spu_thread_argument_t targ;
	int ret;

	ret = sys_spu_image_import(&img, elf, SYS_SPU_IMAGE_PROTECT);
	if (ret != CELL_OK) { printf("[spu] %s: image_import = 0x%x\n", name, ret); return -1; }

	sys_spu_thread_group_attribute_initialize(gattr);
	sys_spu_thread_group_attribute_name(gattr, name);
	ret = sys_spu_thread_group_create(grp, nthreads, 100, &gattr);
	if (ret != CELL_OK) { printf("[spu] %s: group_create = 0x%x\n", name, ret); return -1; }

	for (int i = 0; i < nthreads; i++)
	{
		const uint64_t ea = (uint64_t)(uintptr_t)ctrl_ptrs[i];

		/* la dirección va en los 4 argumentos: así llega sin importar cuál lea el main del SPU */
		targ.arg1 = ea;
		targ.arg2 = ea;
		targ.arg3 = ea;
		targ.arg4 = ea;
		sys_spu_thread_attribute_initialize(tattr);
		sys_spu_thread_attribute_name(tattr, name);
		ret = sys_spu_thread_initialize(&thr[i], *grp, i, &img, &tattr, &targ);
		if (ret != CELL_OK) { printf("[spu] %s: thread_initialize(%d) = 0x%x\n", name, i, ret); return -1; }
	}
	ret = sys_spu_thread_group_start(*grp);
	if (ret != CELL_OK) { printf("[spu] %s: group_start = 0x%x\n", name, ret); return -1; }
	return 0;
}

int spu_host_init(void)
{
	void *actrl[1] = { &g_audio_ctrl };
	void *vctrl[NUM_VIDEO_SPUS];

	for (int i = 0; i < NUM_VIDEO_SPUS; i++)
		vctrl[i] = &g_mix_ctrl[i];

	/* (si ya llamás sys_spu_initialize en otro lado, sacá esta línea) */
	sys_spu_initialize(6, 0);

	memset(&g_audio_ctrl, 0, sizeof(g_audio_ctrl));
	memset(g_mix_ctrl, 0, sizeof(g_mix_ctrl));

	if (spu_host_start_group(_binary_spu_sound_spu_elf_start, 1, "spu_audio", &g_audio_grp, &g_audio_thr, actrl))
		return -1;
	if (spu_host_start_group(_binary_spu_renderer_spu_elf_start, NUM_VIDEO_SPUS, "spu_video", &g_video_grp, g_video_thr, vctrl))
		return -1;
	g_spu_ready = 1;
	return 0;
}

static int spu_wait_flag(volatile uint32_t *flag)
{
	const uint64_t limit = (uint64_t)sys_time_get_timebase_frequency() * WAIT_TIMEOUT_MS / 1000;
	const uint64_t start = __mftb();

	while (!*flag)
	{
		if (__mftb() - start > limit)
			return -1;
		__db16cyc();
	}
	__lwsync();
	return 0;
}

spu_audio_control_t *spu_host_audio_ctrl(void) { return &g_audio_ctrl; }

int spu_host_audio_mix_block(void)
{
	if (!g_spu_ready) return -1;
	g_audio_ctrl.block_done = 0;
	__lwsync();
	sys_spu_thread_write_spu_mb(g_audio_thr, SPU_MSG_RUN);
	return spu_wait_flag(&g_audio_ctrl.block_done);
}

int spu_host_video_ready(void) { return g_video_ready; }
int spu_host_video_spus(void) { return NUM_VIDEO_SPUS; }
spu_mix_control_t *spu_host_mix_ctrl(int spu) { return &g_mix_ctrl[spu]; }

/* Lanza un trabajo en cada SPU de video (cada control ya tiene su banda) y espera a los cuatro a la vez */
static int spu_run_video_jobs(uint32_t limit_ms)
{
	const uint64_t limit = (uint64_t)sys_time_get_timebase_frequency() * limit_ms / 1000;
	int done[NUM_VIDEO_SPUS];
	int pending = NUM_VIDEO_SPUS;
	uint64_t start;

	for (int i = 0; i < NUM_VIDEO_SPUS; i++)
	{
		g_mix_ctrl[i].job_done = 0;
		done[i] = 0;
	}
	__lwsync();
	start = __mftb();
	for (int i = 0; i < NUM_VIDEO_SPUS; i++)
	{
		const int ret = sys_spu_thread_write_spu_mb(g_video_thr[i], SPU_MSG_RUN);

		if (ret != CELL_OK)
			printf("[spu] write_spu_mb(%d) = 0x%x\n", i, ret);
	}
	while (pending && __mftb() - start < limit)
	{
		for (int i = 0; i < NUM_VIDEO_SPUS; i++)
		if (!done[i] && g_mix_ctrl[i].job_done)
		{
			done[i] = 1;
			pending--;
		}
		__db16cyc();
	}
	__lwsync();
	return pending ? -1 : 0;
}

int spu_host_video_mix(void)
{
	int result;

	if (!g_video_ready)
		return -1;
	result = spu_run_video_jobs(WAIT_TIMEOUT_MS);
	if (result)
	{
		g_video_ready = 0;    /* no responde: de acá en adelante mezcla la PPU */
		printf("[spu] los SPU de video no respondieron; sigue la PPU\n");
	}
	return result;
}

/* Prueba: trabajos vacíos (row_count = 0). Calienta los hilos y mide lo que cuesta despertar los cuatro SPU */
int spu_host_selftest(void)
{
	const double freq = (double)sys_time_get_timebase_frequency();
	uint64_t t0, t1;

	if (!g_spu_ready) return -1;
	for (int i = 0; i < NUM_VIDEO_SPUS; i++)
		g_mix_ctrl[i].row_count = 0;

	t0 = __mftb();
	if (spu_run_video_jobs(FIRST_JOB_MS))
	{
		printf("[spu] selftest: los SPU de video no respondieron en %d ms\n", FIRST_JOB_MS);
		return -1;
	}

	for (int i = 0; i < 60; i++)
	if (spu_run_video_jobs(WAIT_TIMEOUT_MS))
	{
		printf("[spu] selftest: timeout en el trabajo %d\n", i);
		return -1;
	}
	g_video_ready = 1;
	return 0;
}

void spu_host_shutdown(void)
{
	int cause, status;

	if (!g_spu_ready) return;
	sys_spu_thread_write_spu_mb(g_audio_thr, SPU_MSG_QUIT);
	for (int i = 0; i < NUM_VIDEO_SPUS; i++)
		sys_spu_thread_write_spu_mb(g_video_thr[i], SPU_MSG_QUIT);
	sys_spu_thread_group_join(g_audio_grp, &cause, &status);
	sys_spu_thread_group_join(g_video_grp, &cause, &status);
	g_spu_ready = 0;
	g_video_ready = 0;
}