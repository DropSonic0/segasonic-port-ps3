/*
 * SPU Sprite Renderer Implementation
 * PlayStation 3 Cell Broadband Engine SPU Core
 */

#if defined(__SPU__) || defined(__CELLOS_LV2__)

#if defined(__SPU__)
#include <spu_intrinsics.h>
#include <cell/dma.h>
#include <stddef.h>
#else
#include <stdint.h>
#include <string.h>
#include <stddef.h>
#endif

#include "spu_sprite_types.h"

#define TAG_CTRL 1
#define TAG_SRAM 2
#define TAG_GFX  3
#define TAG_OUT  4

static spu_sprite_control_t g_sprite_ctrl __attribute__((aligned(128)));
static uint16_t g_line_buf[SPU_SPRITE_MAX_LINE_WIDTH] __attribute__((aligned(128)));

void spu_render_sprite_band(uint64_t ctrl_ea)
{
#if defined(__SPU__)
	cellDmaGet(&g_sprite_ctrl, ctrl_ea, sizeof(spu_sprite_control_t), TAG_CTRL, 0, 0);
	cellDmaWaitTagStatusAll(1 << TAG_CTRL);

	uint32_t width = g_sprite_ctrl.width;
	if (width > SPU_SPRITE_MAX_LINE_WIDTH) width = SPU_SPRITE_MAX_LINE_WIDTH;

	for (uint32_t line = 0; line < g_sprite_ctrl.num_lines; line++) {
		for (uint32_t x = 0; x < width; x++) {
			g_line_buf[x] = 0xffff;
		}

		uint64_t line_ea = g_sprite_ctrl.ea_out_buffer + (g_sprite_ctrl.start_line + line) * SPU_SPRITE_MAX_LINE_WIDTH * 2;
		cellDmaPut(g_line_buf, line_ea, width * 2, TAG_OUT, 0, 0);
		cellDmaWaitTagStatusAll(1 << TAG_OUT);
	}

	g_sprite_ctrl.job_done = 1;
	cellDmaPut(&g_sprite_ctrl, ctrl_ea, sizeof(spu_sprite_control_t), TAG_CTRL, 0, 0);
	cellDmaWaitTagStatusAll(1 << TAG_CTRL);
#else
	(void)ctrl_ea;
#endif
}

#if defined(__SPU__)
int main(unsigned long long spe_id, unsigned long long argp, unsigned long long envp)
{
	(void)spe_id;
	(void)envp;

	uint32_t ctrl_ea = (uint32_t)argp;

	while (1) {
		uint32_t msg = spu_read_in_mbox();
		if (msg == 0xFFFFFFFF) {
			break;
		}

		spu_render_sprite_band((uint64_t)ctrl_ea);
	}

	return 0;
}
#endif

#endif /* __SPU__ || __CELLOS_LV2__ */
