/* ports\ps3\spu_mix_rows.c
 * Mezclador de video en SPU: port de mix_rows (runtime\src\video.c), una banda de filas por SPU */

#include <spu_intrinsics.h>
#include <cell/dma.h>
#include <stdint.h>
#include "spu_mix_types.h"

enum
{
	LAYER_TEXT, LAYER_NBG0, LAYER_NBG1, LAYER_NBG2, LAYER_NBG3, LAYER_BITMAP,
	LAYER_SPRITES, LAYER_BACKDROP, LAYERS
};

#define TAG_CTRL 1
#define TAG_DATA 2
#define TAG_IN   4     /* 4 y 5 */
#define TAG_OUT  6     /* 6 y 7 */

static spu_mix_control_t g_ctrl __attribute__((aligned(128)));
static uint32_t g_palette[SPU_MIX_PALETTE_ENTRIES] __attribute__((aligned(128)));
static uint8_t g_empty[SPU_MIX_INPUT_LAYERS][SPU_MIX_HEIGHT] __attribute__((aligned(128)));
static uint16_t g_in[2][LAYERS][SPU_MIX_MAX_WIDTH] __attribute__((aligned(128)));   /* [buffer][capa] */
static uint32_t g_out[2][SPU_MIX_MAX_WIDTH] __attribute__((aligned(128)));
static uint16_t g_transparent[SPU_MIX_MAX_WIDTH] __attribute__((aligned(128)));     /* en ceros */

static inline int bit(uint32_t value, int number)
{
	return (value >> number) & 1;
}

/* x >> count, rounding down for negative numbers too */
static inline int shift_down(int value, int count)
{
	return value >= 0 ? value >> count : ~(~value >> count);
}

/* El color RGB555 de la paleta: se recupera exacto de palette_argb */
static inline uint16_t palette_color(const spu_mix_layer_t *entry, int pixel)
{
	const uint32_t argb = g_palette[(entry->palette_base + ((pixel >> entry->shift) & 0xfff0) + (pixel & 0x0f)) & 0x3fff];

	return (uint16_t)(((argb >> 19) & 0x1f) | (((argb >> 11) & 0x1f) << 5) | (((argb >> 3) & 0x1f) << 10));
}

static const spu_mix_layer_t *top_layer(const spu_mix_layer_t *entry, const uint16_t *const *rows, int x, int sprite_pixel,
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

static void fetch_row(int b, int y, int width)
{
	const uint32_t bytes = (uint32_t)width * 2;
	const int sprite_y = bit(g_ctrl.sprite_flips, 1) ? g_ctrl.bottom - (y - g_ctrl.top) : y;

	for (int layer = 0; layer < SPU_MIX_INPUT_LAYERS; layer++)
		if (!g_empty[layer][y])
			cellDmaGet(g_in[b][layer], g_ctrl.ea_layer_rows[layer] + (uint64_t)y * SPU_MIX_MAX_WIDTH * 2,
				bytes, TAG_IN + b, 0, 0);
	cellDmaGet(g_in[b][LAYER_SPRITES], g_ctrl.ea_sprites + (uint64_t)sprite_y * SPU_MIX_MAX_WIDTH * 2,
		bytes, TAG_IN + b, 0, 0);
	cellDmaGet(g_in[b][LAYER_BACKDROP], g_ctrl.ea_backdrop + (uint64_t)y * SPU_MIX_MAX_WIDTH * 2,
		bytes, TAG_IN + b, 0, 0);
}

static void mix_row(int b, int y)
{
	const uint16_t *rows[LAYERS];
	uint32_t *out = g_out[b];
	const int blend_factor = g_ctrl.blend_factor;
	const int grouping_shift = g_ctrl.grouping_shift;
	const int grouping_mask = g_ctrl.grouping_mask;
	const int shadow_mask = g_ctrl.shadow_mask;
	const int sprite_bits = g_ctrl.sprite_bits;
	const int shadow_pen = g_ctrl.shadow_pen;
	const int flip_x = bit(g_ctrl.sprite_flips, 0);
	const int sprite_dx = flip_x ? -1 : 1;
	int sprite_x = flip_x ? g_ctrl.right : g_ctrl.left;
	const spu_mix_layer_t *fast_entries[8];
	const uint16_t *fast_rows[8];
	int fast_count = 0;
	int fast = 1;

	for (int index = LAYER_TEXT; index <= LAYER_BITMAP; index++)
		rows[index] = g_empty[index][y] ? g_transparent : g_in[b][index];
	rows[LAYER_SPRITES] = g_in[b][LAYER_SPRITES];
	rows[LAYER_BACKDROP] = g_in[b][LAYER_BACKDROP];

	for (const spu_mix_layer_t *entry = g_ctrl.orders[grouping_mask];; entry++)
	{
		const int *offs;

		if (entry->index == LAYER_SPRITES)
			continue;
		if (entry->index != LAYER_BACKDROP && g_empty[entry->index][y])
			continue;
		offs = g_ctrl.offsets[entry->offsets];
		if (entry->blend != 0 || (offs[0] | offs[1] | offs[2]) != 0)
			fast = 0;
		fast_entries[fast_count] = entry;
		fast_rows[fast_count++] = g_in[b][entry->index];
		if (entry->index == LAYER_BACKDROP)
			break;
	}

	for (int x = g_ctrl.left; x <= g_ctrl.right; x++, sprite_x += sprite_dx)
	{
		const int sprite_pixel = rows[LAYER_SPRITES][sprite_x];
		int group, shadow, pixel;
		const spu_mix_layer_t *first_layer;
		const int *first_offsets;
		uint16_t color;
		int red, green, blue;

		if (fast && sprite_pixel == 0xffff)
		{
			const spu_mix_layer_t *top = fast_entries[fast_count - 1];

			pixel = fast_rows[fast_count - 1][x] & 0x1fff;
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
			out[x] = g_palette[(top->palette_base + ((pixel >> top->shift) & 0xfff0) + (pixel & 0x0f)) & 0x3fff];
			continue;
		}
		group = (sprite_pixel >> grouping_shift) & grouping_mask;
		shadow = 0;
		first_layer = top_layer(g_ctrl.orders[group], rows, x, sprite_pixel, shadow_mask, sprite_bits, shadow_pen,
			&pixel, &shadow);
		color = palette_color(first_layer, pixel);
		first_offsets = g_ctrl.offsets[first_layer->offsets];

		if (first_layer->blend == 0 && !shadow && (first_offsets[0] | first_offsets[1] | first_offsets[2]) == 0)
		{
			out[x] = 0xFF000000u | (uint32_t)(color & 0x1f) << 19 | (uint32_t)((color >> 5) & 0x1f) << 11
				| (uint32_t)((color >> 10) & 0x1f) << 3;
			continue;
		}
		red = (color & 0x1f) + first_offsets[0];
		green = ((color >> 5) & 0x1f) + first_offsets[1];
		blue = ((color >> 10) & 0x1f) + first_offsets[2];

		if (first_layer->blend != 0)
		{
			int below;
			const spu_mix_layer_t *second = top_layer(first_layer + 1, rows, x, sprite_pixel, shadow_mask, sprite_bits,
				shadow_pen, &below, &shadow);

			if (bit(first_layer->blend, second->index)
				&& (second->index != LAYER_SPRITES || bit(first_layer->sprite_blend, group)))
			{
				const int *second_offsets = g_ctrl.offsets[second->offsets];

				color = palette_color(second, below);
				red = shift_down(red * (7 - blend_factor) + ((color & 0x1f) + second_offsets[0]) * (blend_factor + 1), 3);
				green = shift_down(green * (7 - blend_factor) + (((color >> 5) & 0x1f) + second_offsets[1]) * (blend_factor + 1), 3);
				blue = shift_down(blue * (7 - blend_factor) + (((color >> 10) & 0x1f) + second_offsets[2]) * (blend_factor + 1), 3);
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
		out[x] = 0xFF000000u | (uint32_t)red << 19 | (uint32_t)green << 11 | (uint32_t)blue << 3;
	}
}

void spu_mix_job(uint64_t ctrl_ea)
{
	cellDmaGet(&g_ctrl, ctrl_ea, sizeof(g_ctrl), TAG_CTRL, 0, 0);
	cellDmaWaitTagStatusAll(1 << TAG_CTRL);

	if (g_ctrl.row_count != 0 && g_ctrl.left == 0)
	{
		const int width = g_ctrl.right - g_ctrl.left + 1;
		const int first = (int)g_ctrl.first_row;
		const int count = (int)g_ctrl.row_count;

		for (int part = 0; part < 4; part++)
			cellDmaGet((uint8_t *)g_palette + part * 16384, g_ctrl.ea_palette + (uint64_t)part * 16384, 16384,
				TAG_DATA, 0, 0);
		for (int layer = 0; layer < SPU_MIX_INPUT_LAYERS; layer++)
			cellDmaGet(g_empty[layer], g_ctrl.ea_layer_empty[layer], SPU_MIX_HEIGHT, TAG_DATA, 0, 0);
		cellDmaWaitTagStatusAll(1 << TAG_DATA);

		fetch_row(0, first, width);
		for (int n = 0; n < count; n++)
		{
			const int b = n & 1;
			const int y = first + n;

			if (n + 1 < count)
				fetch_row(b ^ 1, y + 1, width);
			cellDmaWaitTagStatusAll(1 << (TAG_IN + b));
			cellDmaWaitTagStatusAll(1 << (TAG_OUT + b));    /* el DMA de salida anterior de este buffer */
			mix_row(b, y);
			cellDmaPut(g_out[b], g_ctrl.ea_frame + (uint64_t)y * SPU_MIX_MAX_WIDTH * 4, (uint32_t)width * 4,
				TAG_OUT + b, 0, 0);
		}
		cellDmaWaitTagStatusAll((1 << TAG_OUT) | (1 << (TAG_OUT + 1)));
	}

	g_ctrl.job_done = 1;
	cellDmaPut(&g_ctrl, ctrl_ea, sizeof(g_ctrl), TAG_CTRL, 0, 0);
	cellDmaWaitTagStatusAll(1 << TAG_CTRL);
}

int main(unsigned long long spe_id, unsigned long long argp, unsigned long long envp)
{
	const uint64_t ctrl_ea = (uint64_t)argp;

	(void)spe_id;
	(void)envp;

	while (1)
	{
		const uint32_t msg = spu_read_in_mbox();

		if (msg == 0xFFFFFFFF)
			break;
		spu_mix_job(ctrl_ea);
	}
	return 0;
}