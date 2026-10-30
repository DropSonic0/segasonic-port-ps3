/* ports\ps3\spu_mix_types.h
 * Datos compartidos PPU <-> SPU del mezclador de video (mix_rows de runtime\src\video.c) */
#ifndef SPU_MIX_TYPES_H
#define SPU_MIX_TYPES_H

#include <stdint.h>

#define SPU_MIX_MAX_WIDTH        416
#define SPU_MIX_HEIGHT           224
#define SPU_MIX_PALETTE_ENTRIES  0x4000
#define SPU_MIX_INPUT_LAYERS     6      /* TEXT, NBG0..NBG3, BITMAP */

/* = mix_layer de video.c, con relleno */
typedef struct spu_mix_layer
{
	uint16_t palette_base;
	uint16_t sprite_blend;
	uint8_t  blend;
	uint8_t  index;
	uint8_t  priority;
	uint8_t  shift;
	uint8_t  offsets;
	uint8_t  pad[3];
} spu_mix_layer_t;

typedef struct __attribute__((aligned(128))) spu_mix_control
{
	uint64_t ea_layer_rows[SPU_MIX_INPUT_LAYERS];   /* &video.layers[i].pixels[0][0] */
	uint64_t ea_layer_empty[SPU_MIX_INPUT_LAYERS];  /* &video.layers[i].empty[0] */
	uint64_t ea_backdrop;                           /* &video.layers[LAYER_BACKDROP].pixels[0][0] */
	uint64_t ea_sprites;                            /* &video.sprites[shown][0][0] */
	uint64_t ea_palette;                            /* palette_argb */
	uint64_t ea_frame;                              /* &video.frame[0][0] */

	int32_t  left, right, top, bottom;              /* video.visible */
	uint32_t first_row;                             /* la banda de este SPU */
	uint32_t row_count;                             /* 0 = no hace nada */

	int32_t  blend_factor;
	int32_t  grouping_shift;
	int32_t  grouping_mask;
	int32_t  shadow_mask;
	int32_t  sprite_bits;
	int32_t  shadow_pen;
	uint32_t sprite_flips;
	int32_t  offsets[3][3];

	spu_mix_layer_t orders[16][8];

	volatile uint32_t job_done;
	uint32_t pad[3];
} spu_mix_control_t;

#endif /* SPU_MIX_TYPES_H */