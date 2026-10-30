/*
* SPU Audio Mixer: datos compartidos PPU <-> SPU
* Remuestrea los tres chips (FM0, FM1, PCM) a 48 kHz, los mezcla y deja float estéreo
*/

#ifndef SPU_AUDIO_TYPES_H
#define SPU_AUDIO_TYPES_H

#include <stdint.h>

#define SPU_AUDIO_MAX_FRAMES      800     /* PS3_OUTPUT_RATE / 60 */
#define SPU_AUDIO_MAX_SRC_FRAMES  1536    /* frames de entrada que caben por chip en el local store */

typedef struct __attribute__((aligned(128))) spu_audio_control
{
	uint64_t ea_chip[3];       /* int32 estéreo entrelazado (frame * 2 + lado) de FM0, FM1, PCM */
	uint64_t ea_out;           /* float estéreo de salida, alineado a 16 */

	uint32_t count[3];         /* frames disponibles en cada chip */
	uint32_t first[3];         /* parte entera de la posición inicial */
	float    frac[3];          /* parte fraccionaria de la posición inicial */
	float    step[3];          /* avance por muestra de salida */

	float    volume;
	uint32_t made;             /* frames de salida a producir (0 = no hace nada) */

	volatile uint32_t block_done;
	volatile uint32_t error;
	volatile uint32_t spu_heartbeat;
} spu_audio_control_t;

#endif /* SPU_AUDIO_TYPES_H */