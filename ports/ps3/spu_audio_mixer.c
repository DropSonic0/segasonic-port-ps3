/*
* SPU Audio Mixer
* Remuestreo lineal de los tres chips a 48 kHz + mezcla + conversión a float
*/

#include <spu_intrinsics.h>
#include <cell/dma.h>
#include <stdint.h>
#include "spu_audio_types.h"

#define TAG_CTRL 1
#define TAG_CHIP 2     /* 2, 3 y 4 */
#define TAG_OUT  5

static spu_audio_control_t g_ctrl __attribute__((aligned(128)));
static int32_t g_src[3][SPU_AUDIO_MAX_SRC_FRAMES * 2] __attribute__((aligned(128)));
static float g_out[SPU_AUDIO_MAX_FRAMES * 2] __attribute__((aligned(128)));

void spu_mix_audio_block(uint64_t ctrl_ea)
{
	uint32_t lead[3] = { 0, 0, 0 };
	uint32_t mask = 0;
	uint32_t made;

	cellDmaGet(&g_ctrl, ctrl_ea, sizeof(g_ctrl), TAG_CTRL, 0, 0);
	cellDmaWaitTagStatusAll(1 << TAG_CTRL);

	g_ctrl.error = 0;
	made = g_ctrl.made;
	if (made > SPU_AUDIO_MAX_FRAMES)
	{
		g_ctrl.error = 1;
		made = 0;
	}

	/* Trae de cada chip las muestras que va a usar (el DMA se alinea a 16 bytes) */
	for (uint32_t c = 0; c < 3 && made != 0; c++)
	{
		const uint32_t kmax = (uint32_t)(g_ctrl.frac[c] + (float)(made - 1) * g_ctrl.step[c]) + 1;
		const uint32_t nframes = kmax + 1;
		const uint64_t byte_start = g_ctrl.ea_chip[c] + (uint64_t)g_ctrl.first[c] * 8;
		const uint64_t ea_aligned = byte_start & ~15ull;
		uint32_t bytes;

		lead[c] = (uint32_t)((byte_start - ea_aligned) >> 3);
		bytes = ((lead[c] + nframes) * 8 + 15) & ~15u;
		if (g_ctrl.first[c] + kmax >= g_ctrl.count[c] || bytes > sizeof(g_src[c]))
		{
			g_ctrl.error = 1;
			break;
		}
		cellDmaGet(g_src[c], ea_aligned, bytes, TAG_CHIP + c, 0, 0);
		mask |= 1u << (TAG_CHIP + c);
	}
	if (mask)
		cellDmaWaitTagStatusAll(mask);

	if (made != 0 && !g_ctrl.error)
	{
		const float volume = g_ctrl.volume;

		for (uint32_t i = 0; i < made; i++)
		{
			float mixed[3][2];

			for (uint32_t c = 0; c < 3; c++)
			{
				const float position = g_ctrl.frac[c] + (float)i * g_ctrl.step[c];
				const uint32_t index = (uint32_t)position;
				const float fraction = position - (float)index;
				const int32_t *s = &g_src[c][(lead[c] + index) * 2];

				for (uint32_t side = 0; side < 2; side++)
				{
					const float here = (float)s[side];
					const float next = (float)s[2 + side];

					mixed[c][side] = here + (next - here) * fraction;
				}
			}
			for (uint32_t side = 0; side < 2; side++)
			{
				const float value = volume * (0.30f * (mixed[0][side] + mixed[1][side]) + 0.40f * mixed[2][side]);
				float out = value * (1.0f / 32768.0f);

				if (out > 1.0f) out = 1.0f;
				if (out < -1.0f) out = -1.0f;
				g_out[i * 2 + side] = out;
			}
		}
		if (made & 1)
		{
			g_out[made * 2] = 0.0f;       /* (el DMA va en múltiplos de 16 bytes) */
			g_out[made * 2 + 1] = 0.0f;
		}
		cellDmaPut(g_out, g_ctrl.ea_out, ((made + 1) & ~1u) * 8, TAG_OUT, 0, 0);
		cellDmaWaitTagStatusAll(1 << TAG_OUT);
	}

	g_ctrl.spu_heartbeat++;
	g_ctrl.block_done = 1;
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
		spu_mix_audio_block(ctrl_ea);
	}
	return 0;
}