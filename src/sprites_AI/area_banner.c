#include "area_banner.h"
#include "../../data/data.h"
#include "../globals.h"

const u8 sAreaBannerGFX[260];
const u16 sAreaBannerPAL[16];
const u16 sAreaBannerLocationTextPAL[16];

const u16 sAreaBannerOAM_SpawnMiddle_Frame0[7] = {
    0x2,
    0xfc, 0x1f8, OBJ_SPRITE_OAM | 0x21c,
    0xfc, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x21c
};

const u16 sAreaBannerOAM_SpawnMiddle_Frame1[13] = {
    0x4,
    0xfc, 0x1d8, OBJ_SPRITE_OAM | 0x21c,
    0xfc, OBJ_X_FLIP | 0x20, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1e0, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x0, OBJ_SPRITE_OAM | 0x23c
};

const u16 sAreaBannerOAM_SpawnMiddle_Frame2[19] = {
    0x6,
    0xfc, 0x1b8, OBJ_SPRITE_OAM | 0x21c,
    0xfc, OBJ_X_FLIP | 0x40, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1e0, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x20, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x0, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1c0, OBJ_SPRITE_OAM | 0x23c
};

const u16 sAreaBannerOAM_SpawnMiddle_Frame3[25] = {
    0x8,
    0xfc, 0x198, OBJ_SPRITE_OAM | 0x21c,
    0xfc, OBJ_X_FLIP | 0x60, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x0, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x40, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x20, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1a0, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1e0, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1c0, OBJ_SPRITE_OAM | 0x23c
};

const u16 sAreaBannerOAM_SpawnMiddle_Frame4[28] = {
    0x9,
    0xfc, 0x188, OBJ_SPRITE_OAM | 0x21c,
    0xfc, OBJ_X_FLIP | 0x70, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x190, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1b0, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1d0, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x10, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x30, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x50, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x23c
};

const u16 sAreaBannerOAM_SpawnMiddle_Frame5[55] = {
    0x12,
    0xfb, 0x188, OBJ_SPRITE_OAM | 0x21d,
    0xfb, OBJ_X_FLIP | 0x70, OBJ_SPRITE_OAM | 0x21d,
    0xfd, 0x188, OBJ_SPRITE_OAM | 0x21e,
    0xfd, OBJ_X_FLIP | 0x70, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xfb, OBJ_SIZE_32x8 | 0x190, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xfb, OBJ_SIZE_32x8 | 0x1b0, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xfb, OBJ_SIZE_32x8 | 0x1d0, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xfb, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xfb, OBJ_SIZE_32x8 | 0x10, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xfb, OBJ_SIZE_32x8 | 0x30, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xfb, OBJ_SIZE_32x8 | 0x50, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xfd, OBJ_SIZE_32x8 | 0x190, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xfd, OBJ_SIZE_32x8 | 0x1b0, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xfd, OBJ_SIZE_32x8 | 0x1d0, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xfd, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xfd, OBJ_SIZE_32x8 | 0x10, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xfd, OBJ_SIZE_32x8 | 0x30, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xfd, OBJ_SIZE_32x8 | 0x50, OBJ_SPRITE_OAM | 0x23c
};

const u16 sAreaBannerOAM_SpawnMiddle_Frame6[55] = {
    0x12,
    0xfa, 0x188, OBJ_SPRITE_OAM | 0x21d,
    0xfa, OBJ_X_FLIP | 0x70, OBJ_SPRITE_OAM | 0x21d,
    0xfe, 0x188, OBJ_SPRITE_OAM | 0x21e,
    0xfe, OBJ_X_FLIP | 0x70, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x8 | 0x190, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x8 | 0x1b0, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x8 | 0x1d0, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x8 | 0x10, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x8 | 0x30, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x8 | 0x50, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x8 | 0x190, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x8 | 0x1b0, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x8 | 0x1d0, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x8 | 0x10, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x8 | 0x30, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x8 | 0x50, OBJ_SPRITE_OAM | 0x23c
};

const u16 sAreaBannerOAM_SpawnMiddle_Frame7[55] = {
    0x12,
    0xf9, 0x188, OBJ_SPRITE_OAM | 0x21d,
    0xf9, OBJ_X_FLIP | 0x70, OBJ_SPRITE_OAM | 0x21d,
    0xff, 0x188, OBJ_SPRITE_OAM | 0x21e,
    0xff, OBJ_X_FLIP | 0x70, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xf9, OBJ_SIZE_32x8 | 0x190, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xf9, OBJ_SIZE_32x8 | 0x1b0, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xf9, OBJ_SIZE_32x8 | 0x1d0, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xf9, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xf9, OBJ_SIZE_32x8 | 0x10, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xf9, OBJ_SIZE_32x8 | 0x30, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xf9, OBJ_SIZE_32x8 | 0x50, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_SIZE_32x8 | 0x190, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_SIZE_32x8 | 0x1b0, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_SIZE_32x8 | 0x1d0, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_SIZE_32x8 | 0x10, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_SIZE_32x8 | 0x30, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_SIZE_32x8 | 0x50, OBJ_SPRITE_OAM | 0x23c
};

const u16 sAreaBannerOAM_StaticMiddle_Frame0[62] = {
    0xb,
    0xf8, 0x188, OBJ_SPRITE_OAM | 0x21d,
    0xf8, OBJ_X_FLIP | 0x70, OBJ_SPRITE_OAM | 0x21d,
    0x0, 0x188, OBJ_SPRITE_OAM | 0x21e,
    0x0, OBJ_X_FLIP | 0x70, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x190, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1b0, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1d0, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x10, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x30, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x50, OBJ_SPRITE_OAM | 0x218
};

const u16 sAreaBannerOAM_SpawnBottom_Frame0[28] = {
    0x9,
    OBJ_SHAPE_HORIZONTAL | 0x6, OBJ_SIZE_32x16 | 0x190, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x6, OBJ_SIZE_32x16 | 0x1b0, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0x6, OBJ_SIZE_32x16 | 0x1d0, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0x6, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0x6, OBJ_SIZE_32x16 | 0x10, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0x6, OBJ_SIZE_32x16 | 0x30, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_HORIZONTAL | 0x6, OBJ_SIZE_32x16 | 0x50, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_VERTICAL | 0x6, 0x70, OBJ_SPRITE_OAM | 0x21f,
    OBJ_SHAPE_VERTICAL | 0x6, 0x188, OBJ_SPRITE_OAM | 0x21f
};

const u16 sAreaBannerOAM_SpawnBottom_Frame1[28] = {
    0x9,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x190, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x1b0, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x1d0, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x10, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x30, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x50, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_VERTICAL | 0x4, 0x70, OBJ_SPRITE_OAM | 0x21f,
    OBJ_SHAPE_VERTICAL | 0x4, 0x188, OBJ_SPRITE_OAM | 0x21f
};

const u16 sAreaBannerOAM_SpawnBottom_Frame2[28] = {
    0x9,
    OBJ_SHAPE_HORIZONTAL | 0x2, OBJ_SIZE_32x16 | 0x190, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x2, OBJ_SIZE_32x16 | 0x1b0, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0x2, OBJ_SIZE_32x16 | 0x1d0, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0x2, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0x2, OBJ_SIZE_32x16 | 0x10, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0x2, OBJ_SIZE_32x16 | 0x30, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_HORIZONTAL | 0x2, OBJ_SIZE_32x16 | 0x50, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_VERTICAL | 0x2, 0x70, OBJ_SPRITE_OAM | 0x21f,
    OBJ_SHAPE_VERTICAL | 0x2, 0x188, OBJ_SPRITE_OAM | 0x21f
};

const u16 sAreaBannerOAM_SpawnBottom_Frame3[28] = {
    0x9,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x190, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x1b0, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x1d0, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x10, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x30, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x50, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_VERTICAL | 0x0, 0x188, OBJ_SPRITE_OAM | 0x21f,
    OBJ_SHAPE_VERTICAL | 0x0, 0x70, OBJ_SPRITE_OAM | 0x21f
};

const u16 sAreaBannerOAM_SpawnBottom_Frame4[28] = {
    0x9,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x16 | 0x190, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x16 | 0x1b0, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x16 | 0x1d0, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x16 | 0x10, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x16 | 0x30, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x16 | 0x50, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_VERTICAL | 0xfe, 0x70, OBJ_SPRITE_OAM | 0x21f,
    OBJ_SHAPE_VERTICAL | 0xfe, 0x188, OBJ_SPRITE_OAM | 0x21f
};

const u16 sAreaBannerOAM_SpawnBottom_Frame5[28] = {
    0x9,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x16 | 0x190, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x16 | 0x1b0, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x16 | 0x1d0, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x16 | 0x10, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x16 | 0x30, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x16 | 0x50, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_VERTICAL | 0xfc, 0x188, OBJ_SPRITE_OAM | 0x21f,
    OBJ_SHAPE_VERTICAL | 0xfc, 0x70, OBJ_SPRITE_OAM | 0x21f
};

const u16 sAreaBannerOAM_SpawnBottom_Frame6[28] = {
    0x9,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x16 | 0x190, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x16 | 0x1b0, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x16 | 0x1d0, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x16 | 0x10, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x16 | 0x30, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x16 | 0x50, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_VERTICAL | 0xfa, 0x70, OBJ_SPRITE_OAM | 0x21f,
    OBJ_SHAPE_VERTICAL | 0xfa, 0x188, OBJ_SPRITE_OAM | 0x21f
};

const u16 sAreaBannerOAM_StaticBottom_Frame0[28] = {
    0x9,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x190, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1b0, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1d0, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x10, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x30, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x50, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x188, OBJ_SPRITE_OAM | 0x21f,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x70, OBJ_SPRITE_OAM | 0x21f
};

const struct FrameData sAreaBannerOAM_StaticMiddle[2] = {
    sAreaBannerOAM_StaticMiddle_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sAreaBannerOAM_SpawnMiddle[9] = {
    sAreaBannerOAM_SpawnMiddle_Frame0,
    0x1,
    sAreaBannerOAM_SpawnMiddle_Frame1,
    0x1,
    sAreaBannerOAM_SpawnMiddle_Frame2,
    0x1,
    sAreaBannerOAM_SpawnMiddle_Frame3,
    0x1,
    sAreaBannerOAM_SpawnMiddle_Frame4,
    0x2,
    sAreaBannerOAM_SpawnMiddle_Frame5,
    0x2,
    sAreaBannerOAM_SpawnMiddle_Frame6,
    0x2,
    sAreaBannerOAM_SpawnMiddle_Frame7,
    0x2,
    NULL,
    0x0
};

const struct FrameData sAreaBannerOAM_RemovingMiddle[9] = {
    sAreaBannerOAM_SpawnMiddle_Frame7,
    0x1,
    sAreaBannerOAM_SpawnMiddle_Frame6,
    0x1,
    sAreaBannerOAM_SpawnMiddle_Frame5,
    0x1,
    sAreaBannerOAM_SpawnMiddle_Frame4,
    0x1,
    sAreaBannerOAM_SpawnMiddle_Frame3,
    0x1,
    sAreaBannerOAM_SpawnMiddle_Frame2,
    0x1,
    sAreaBannerOAM_SpawnMiddle_Frame1,
    0x1,
    sAreaBannerOAM_SpawnMiddle_Frame0,
    0x1,
    NULL,
    0x0
};

const struct FrameData sAreaBannerOAM_StaticBottom[2] = {
    sAreaBannerOAM_StaticBottom_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sAreaBannerOAM_SpawnBottom[8] = {
    sAreaBannerOAM_SpawnBottom_Frame0,
    0x1,
    sAreaBannerOAM_SpawnBottom_Frame1,
    0x1,
    sAreaBannerOAM_SpawnBottom_Frame2,
    0x1,
    sAreaBannerOAM_SpawnBottom_Frame3,
    0x1,
    sAreaBannerOAM_SpawnBottom_Frame4,
    0x2,
    sAreaBannerOAM_SpawnBottom_Frame5,
    0x2,
    sAreaBannerOAM_SpawnBottom_Frame6,
    0x2,
    NULL,
    0x0
};

const struct FrameData sAreaBannerOAM_RemovingBottom[8] = {
    sAreaBannerOAM_SpawnBottom_Frame6,
    0x2,
    sAreaBannerOAM_SpawnBottom_Frame5,
    0x2,
    sAreaBannerOAM_SpawnBottom_Frame4,
    0x1,
    sAreaBannerOAM_SpawnBottom_Frame3,
    0x1,
    sAreaBannerOAM_SpawnBottom_Frame2,
    0x1,
    sAreaBannerOAM_SpawnBottom_Frame1,
    0x1,
    sAreaBannerOAM_SpawnBottom_Frame0,
    0x1,
    NULL,
    0x0
};

/**
 * @brief 3c704 | a4 | Initializes an area banner sprite
 * 
 */
void AreaBannerInit(void)
{
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;

    gCurrentSprite.drawDistanceTopOffset = 0x10;
    gCurrentSprite.drawDistanceBottomOffset = 0x10,
    gCurrentSprite.drawDistanceHorizontalOffset = 0x80;

    gCurrentSprite.hitboxTopOffset = -0x4;
    gCurrentSprite.hitboxBottomOffset = 0x4;
    gCurrentSprite.hitboxLeftOffset = -0x4;
    gCurrentSprite.hitboxRightOffset = 0x4;

    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.pose = AREA_BANNER_POSE_SPAWN;

    if (gCurrentSprite.roomSlot < LT_MOTHERSHIP)
    {
        // Area name, spawn at bottom
        gCurrentSprite.pOam = sAreaBannerOAM_SpawnBottom;
        gCurrentSprite.workVariable = TRUE;
        gCurrentSprite.yPosition = 0x98;
        gCurrentSprite.xPosition = 0x78;
    }
    else if ((gCurrentSprite.roomSlot == LT_SAVE_ROOM || gCurrentSprite.roomSlot == LT_MAP_ROOM) && gAlarmTimer != 0x0)
        gCurrentSprite.status = 0x0; // Don't spawn save/map if alarm is active
    else
    {
        // Spawn in middle
        gCurrentSprite.pOam = sAreaBannerOAM_SpawnMiddle;
        gCurrentSprite.workVariable = FALSE;
        gCurrentSprite.yPosition = 0x36;
        gCurrentSprite.xPosition = 0x78;
    }
}

/**
 * @brief 3c7a8 | 20 | Handles the area banner spawning
 * 
 */
void AreaBannerSpawn(void)
{
    gCurrentSprite.animationDurationCounter--;
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN; // Remove not drawn
    gCurrentSprite.pose = AREA_BANNER_POSE_SCROLLING_UP;
}

/**
 * @brief 3c7c8 | 60 | Handles the area banner scrolling up, determines the static behavior
 * 
 */
void AreaBannerScrollingUp(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.pose = AREA_BANNER_POSE_STATIC;

        // Set OAM and timer for how long the message stays
        if (gCurrentSprite.workVariable) // Position flag, 1 = on bottom, 0 = in middle
        {
            gCurrentSprite.pOam = sAreaBannerOAM_StaticBottom;
            gCurrentSprite.timer = 0x78;
        }
        else
        {
            gCurrentSprite.pOam = sAreaBannerOAM_StaticMiddle;
            if (gCurrentSprite.roomSlot == LT_SAVE_ROOM || gCurrentSprite.roomSlot == LT_MAP_ROOM)
                gCurrentSprite.timer = 0x32;
            else
                gCurrentSprite.timer = 0x5A;
        }
    }
}

/**
 * @brief 3c828 | 44 | Handles the area banner being static
 * 
 */
void AreaBannerStatic(void)
{
    gCurrentSprite.timer--; // Timer for how long it stays
    if (gCurrentSprite.timer == 0x0)
    {
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.pose = AREA_BANNER_POSE_REMOVING;

        // Set OAM
        if (gCurrentSprite.workVariable)
            gCurrentSprite.pOam = sAreaBannerOAM_RemovingBottom;
        else
            gCurrentSprite.pOam = sAreaBannerOAM_RemovingMiddle;
    }
}

/**
 * @brief 3c86c | 18 | Checks if the removing anim ended
 * 
 */
void AreaBannerCheckRemovingAnimEnded(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
        gCurrentSprite.status = 0x0; // Kill sprite
}

/**
 * @brief 3c884 | e0 | Area banner AI
 * 
 */
void AreaBanner(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            AreaBannerInit();
            break;

        case AREA_BANNER_POSE_SPAWN:
            AreaBannerSpawn();
            break;
        
        case AREA_BANNER_POSE_SCROLLING_UP:
            AreaBannerScrollingUp();
            break;

        case AREA_BANNER_POSE_STATIC:
            AreaBannerStatic();
            break;

        case AREA_BANNER_POSE_REMOVING:
            AreaBannerCheckRemovingAnimEnded();
            break;
    }
}