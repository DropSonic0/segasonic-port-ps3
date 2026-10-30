/* ports\ps3\spu_host.h */
#ifndef SPU_HOST_H
#define SPU_HOST_H

#include <stdint.h>
#include "spu_audio_types.h"
#include "spu_mix_types.h"

int  spu_host_init(void);
void spu_host_shutdown(void);
int  spu_host_selftest(void);                    /* 0 = los SPU de video responden */

spu_audio_control_t *spu_host_audio_ctrl(void);
int  spu_host_audio_mix_block(void);             /* 0 = ok, -1 = timeout */

int  spu_host_video_ready(void);
int  spu_host_video_spus(void);
spu_mix_control_t *spu_host_mix_ctrl(int spu);   /* el control de cada SPU de video */
int  spu_host_video_mix(void);                   /* lanza los trabajos y espera: 0 = ok */

#endif