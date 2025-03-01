#ifndef FUNCS_H
#define FUNCS_H

#include "types.h"

void dma_transfer(int dma_channel, void *src, void *dst, u32 len, u8 bit_size);
void init_sound(void);
void read_sram(void);
void start_new_demo(void);
int softreset_main(void);
int ingame_main(void);
int intro_main(void);
int titlescreen_main(void);
int fileselect_main(void);
int map_screen_main(void);
int gameover_main(void);
int chozodia_escape_main(void);
int credits_main(void);
int tourian_escape_main(void);
int cutscene_main(void);
int gallery_main(void);
int fusion_gallery_main(void);
int erase_sram_main(void);

void sub_080033dc(void);
void sub_08003fac(u16 id, u32 unk); /* TODO: unk type */
void sub_08004014(u16 id, u32 unk); /* TODO: unk type */
void sub_08004d48();
void sub_0805d034(void);

#endif /* FUNCS_H */
