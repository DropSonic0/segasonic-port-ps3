/*
 * SPU Sprite Renderer Types and Shared Data Structures
 * PlayStation 3 Cell Broadband Engine
 */

#ifndef SPU_SPRITE_TYPES_H
#define SPU_SPRITE_TYPES_H

#include <stdint.h>

#define SPU_SPRITE_MAX_LINE_WIDTH 416
#define SPU_SPRITE_LINES 224

typedef struct __attribute__((aligned(128))) spu_sprite_control
{
	uint64_t ea_sprite_ram;    /* Effective address of sprite RAM in PPU memory */
	uint64_t ea_sprite_gfx;    /* Effective address of sprite graphics ROM/RAM */
	uint64_t ea_out_buffer;    /* Effective address of target sprite buffer (16-bit indexes) */

	uint32_t width;            /* 320 or 416 */
	uint32_t height;           /* 224 */
	uint32_t start_line;       /* Band start line */
	uint32_t num_lines;        /* Number of lines assigned to this SPU job */

	volatile uint32_t job_done;
	volatile uint32_t pad[3];
} spu_sprite_control_t;

#endif /* SPU_SPRITE_TYPES_H */
