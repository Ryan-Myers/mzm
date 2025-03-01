#include "steam.h"
#include "../../data/data.h"
#include "../globals.h"

const u8 sSteamGFX[780];
const u16 sSteamPAL[16];

const u16 sSteamOAM_HorizontalLarge_Frame0[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200
};

const u16 sSteamOAM_HorizontalLarge_Frame1[7] = {
    0x2,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x200,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202
};

const u16 sSteamOAM_HorizontalLarge_Frame2[10] = {
    0x3,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0xb, OBJ_SPRITE_OAM | 0x200,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x2, OBJ_SPRITE_OAM | 0x202,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204
};

const u16 sSteamOAM_HorizontalLarge_Frame3[13] = {
    0x4,
    0xf8, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x18, OBJ_SPRITE_OAM | 0x200,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0xc, OBJ_SPRITE_OAM | 0x202,
    0xf8, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x204,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206
};

const u16 sSteamOAM_HorizontalLarge_Frame4[22] = {
    0x7,
    0xf8, 0x1f8, OBJ_SPRITE_OAM | 0x207,
    0xfc, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x207,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x207,
    0xf8, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x25, OBJ_SPRITE_OAM | 0x200,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1b, OBJ_SPRITE_OAM | 0x202,
    0xf8, OBJ_SIZE_16x16 | 0xe, OBJ_SPRITE_OAM | 0x204,
    0xf8, OBJ_SIZE_16x16 | 0x3, OBJ_SPRITE_OAM | 0x206
};

const u16 sSteamOAM_HorizontalLarge_Frame5[25] = {
    0x8,
    0xf8, OBJ_Y_FLIP | 0x1fb, OBJ_SPRITE_OAM | 0x208,
    0x0, 0x1fd, OBJ_SPRITE_OAM | 0x208,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x30, OBJ_SPRITE_OAM | 0x202,
    0xf8, OBJ_SIZE_16x16 | 0x20, OBJ_SPRITE_OAM | 0x204,
    0xf8, OBJ_SIZE_16x16 | 0x10, OBJ_SPRITE_OAM | 0x206,
    0xf8, OBJ_X_FLIP | 0x8, OBJ_SPRITE_OAM | 0x207,
    0xfc, 0x0, OBJ_SPRITE_OAM | 0x207,
    0x0, OBJ_Y_FLIP | 0x8, OBJ_SPRITE_OAM | 0x207
};

const u16 sSteamOAM_HorizontalLarge_Frame6[22] = {
    0x7,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | 0x3, OBJ_SPRITE_OAM | 0x208,
    0x0, OBJ_X_FLIP | 0x1, OBJ_SPRITE_OAM | 0x208,
    0xf8, OBJ_SIZE_16x16 | 0x33, OBJ_SPRITE_OAM | 0x204,
    0xf8, OBJ_SIZE_16x16 | 0x20, OBJ_SPRITE_OAM | 0x206,
    0x0, OBJ_Y_FLIP | 0xd, OBJ_SPRITE_OAM | 0x207,
    0xfc, OBJ_X_FLIP | OBJ_Y_FLIP | 0x15, OBJ_SPRITE_OAM | 0x207,
    0xf8, OBJ_X_FLIP | 0xd, OBJ_SPRITE_OAM | 0x207
};

const u16 sSteamOAM_HorizontalLarge_Frame7[19] = {
    0x6,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | 0xf, OBJ_SPRITE_OAM | 0x208,
    0x0, OBJ_X_FLIP | 0xd, OBJ_SPRITE_OAM | 0x208,
    0xf8, OBJ_SIZE_16x16 | 0x38, OBJ_SPRITE_OAM | 0x206,
    0xf8, OBJ_X_FLIP | 0x2d, OBJ_SPRITE_OAM | 0x207,
    0xfc, 0x25, OBJ_SPRITE_OAM | 0x207,
    0x0, OBJ_Y_FLIP | 0x2d, OBJ_SPRITE_OAM | 0x207
};

const u16 sSteamOAM_HorizontalLarge_Frame8[16] = {
    0x5,
    0xf7, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1a, OBJ_SPRITE_OAM | 0x208,
    0xff, OBJ_X_FLIP | 0x18, OBJ_SPRITE_OAM | 0x208,
    0x0, OBJ_Y_FLIP | 0x38, OBJ_SPRITE_OAM | 0x207,
    0xfc, OBJ_X_FLIP | OBJ_Y_FLIP | 0x40, OBJ_SPRITE_OAM | 0x207,
    0xf8, OBJ_X_FLIP | 0x38, OBJ_SPRITE_OAM | 0x207
};

const u16 sSteamOAM_HorizontalLarge_Frame9[7] = {
    0x2,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | 0x32, OBJ_SPRITE_OAM | 0x208,
    0x0, OBJ_X_FLIP | 0x30, OBJ_SPRITE_OAM | 0x208
};

const u16 sSteamOAM_VerticalLarge_Frame1[7] = {
    0x2,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202
};

const u16 sSteamOAM_VerticalLarge_Frame2[10] = {
    0x3,
    0xe2, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xed, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204
};

const u16 sSteamOAM_VerticalLarge_Frame3[13] = {
    0x4,
    0xd3, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xe0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    0xec, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206
};

const u16 sSteamOAM_VerticalLarge_Frame4[22] = {
    0x7,
    0xf8, 0x1f8, OBJ_SPRITE_OAM | 0x207,
    0xfc, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x207,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x207,
    0xc8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xd5, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    0xdf, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204,
    0xef, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206
};

const u16 sSteamOAM_VerticalLarge_Frame5[25] = {
    0x8,
    0xf8, OBJ_Y_FLIP | 0x1fb, OBJ_SPRITE_OAM | 0x208,
    0x0, 0x1fd, OBJ_SPRITE_OAM | 0x208,
    0xc0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    0xd0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204,
    0xd8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206,
    0xe8, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x207,
    0xec, 0x1f8, OBJ_SPRITE_OAM | 0x207,
    0xf0, OBJ_Y_FLIP | 0x0, OBJ_SPRITE_OAM | 0x207
};

const u16 sSteamOAM_VerticalLarge_Frame6[22] = {
    0x7,
    0xed, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x208,
    0xf5, OBJ_X_FLIP | 0x1fa, OBJ_SPRITE_OAM | 0x208,
    0xbe, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204,
    0xcc, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206,
    0xe4, OBJ_Y_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x207,
    0xe0, OBJ_X_FLIP | OBJ_Y_FLIP | 0x0, OBJ_SPRITE_OAM | 0x207,
    0xdc, OBJ_X_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x207
};

const u16 sSteamOAM_VerticalLarge_Frame7[19] = {
    0x6,
    0xe5, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fd, OBJ_SPRITE_OAM | 0x208,
    0xed, OBJ_X_FLIP | 0x1fb, OBJ_SPRITE_OAM | 0x208,
    0xbb, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206,
    0xd8, OBJ_X_FLIP | OBJ_Y_FLIP | 0x0, OBJ_SPRITE_OAM | 0x207,
    0xd4, OBJ_Y_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x207,
    0xd0, 0x0, OBJ_SPRITE_OAM | 0x207
};

const u16 sSteamOAM_VerticalLarge_Frame8[16] = {
    0x5,
    0xda, OBJ_Y_FLIP | 0x1fb, OBJ_SPRITE_OAM | 0x208,
    0xe2, 0x1fd, OBJ_SPRITE_OAM | 0x208,
    0xc8, OBJ_Y_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x207,
    0xc4, OBJ_X_FLIP | OBJ_Y_FLIP | 0x0, OBJ_SPRITE_OAM | 0x207,
    0xc0, OBJ_X_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x207
};

const u16 sSteamOAM_VerticalLarge_Frame9[7] = {
    0x2,
    0xcc, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fd, OBJ_SPRITE_OAM | 0x208,
    0xd4, OBJ_X_FLIP | 0x1fb, OBJ_SPRITE_OAM | 0x208
};

const u16 sSteamOAM_HorizontalSmall_Frame0[4] = {
    0x1,
    0xf8, OBJ_X_FLIP | 0x1fd, OBJ_SPRITE_OAM | 0x209
};

const u16 sSteamOAM_HorizontalSmall_Frame1[7] = {
    0x2,
    0xf8, OBJ_X_FLIP | 0x4, OBJ_SPRITE_OAM | 0x209,
    0xf8, 0x1ff, OBJ_SPRITE_OAM | 0x209
};

const u16 sSteamOAM_HorizontalSmall_Frame2[10] = {
    0x3,
    0xf8, 0xb, OBJ_SPRITE_OAM | 0x209,
    0xfa, OBJ_X_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20b,
    0xf8, 0x3, OBJ_SPRITE_OAM | 0x209
};

const u16 sSteamOAM_HorizontalSmall_Frame3[13] = {
    0x4,
    0xf8, OBJ_X_FLIP | 0x11, OBJ_SPRITE_OAM | 0x209,
    0xfa, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x20b,
    0xf8, 0x8, OBJ_SPRITE_OAM | 0x209,
    0xf8, OBJ_X_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20c
};

const u16 sSteamOAM_HorizontalSmall_Frame4[16] = {
    0x5,
    0xf9, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x20d,
    0xf8, OBJ_X_FLIP | 0xc, OBJ_SPRITE_OAM | 0x20b,
    0xf8, OBJ_X_FLIP | 0x8, OBJ_SPRITE_OAM | 0x20c,
    0xf8, OBJ_X_FLIP | 0x1a, OBJ_SPRITE_OAM | 0x209,
    0xf8, OBJ_X_FLIP | 0x13, OBJ_SPRITE_OAM | 0x209
};

const u16 sSteamOAM_HorizontalSmall_Frame5[16] = {
    0x5,
    0xf8, OBJ_X_FLIP | 0x3, OBJ_SPRITE_OAM | 0x20d,
    0xf8, OBJ_X_FLIP | 0x16, OBJ_SPRITE_OAM | 0x20b,
    0xf7, OBJ_X_FLIP | 0xf, OBJ_SPRITE_OAM | 0x20c,
    0xf7, OBJ_X_FLIP | 0xa, OBJ_SPRITE_OAM | 0x20d,
    0xf8, OBJ_X_FLIP | 0x1e, OBJ_SPRITE_OAM | 0x20b
};

const u16 sSteamOAM_HorizontalSmall_Frame6[13] = {
    0x4,
    0xf8, OBJ_X_FLIP | 0x24, OBJ_SPRITE_OAM | 0x20c,
    0xf8, OBJ_Y_FLIP | 0x1a, OBJ_SPRITE_OAM | 0x20c,
    0xf8, OBJ_X_FLIP | 0xc, OBJ_SPRITE_OAM | 0x20d,
    0xf7, 0x11, OBJ_SPRITE_OAM | 0x20d
};

const u16 sSteamOAM_HorizontalSmall_Frame7[10] = {
    0x3,
    0xf8, OBJ_Y_FLIP | 0x1e, OBJ_SPRITE_OAM | 0x20d,
    0xf8, OBJ_X_FLIP | 0x28, OBJ_SPRITE_OAM | 0x20d,
    0xf7, OBJ_X_FLIP | 0x13, OBJ_SPRITE_OAM | 0x20d
};

const u16 sSteamOAM_VerticalSmall_Frame1[7] = {
    0x2,
    0xf1, OBJ_X_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x209,
    0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x209
};

const u16 sSteamOAM_VerticalSmall_Frame2[10] = {
    0x3,
    0xec, 0x1fb, OBJ_SPRITE_OAM | 0x209,
    0xfa, OBJ_X_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20b,
    0xf2, 0x1fb, OBJ_SPRITE_OAM | 0x209
};

const u16 sSteamOAM_VerticalSmall_Frame3[13] = {
    0x4,
    0xe7, OBJ_X_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x209,
    0xee, 0x1fc, OBJ_SPRITE_OAM | 0x209,
    0xf4, OBJ_X_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20b,
    0xf8, OBJ_X_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20c
};

const u16 sSteamOAM_VerticalSmall_Frame4[16] = {
    0x5,
    0xe1, OBJ_X_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x209,
    0xe8, OBJ_X_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x209,
    0xf7, OBJ_X_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20d,
    0xec, OBJ_X_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20b,
    0xf1, OBJ_X_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20c
};

const u16 sSteamOAM_VerticalSmall_Frame5[16] = {
    0x5,
    0xf6, 0x1fc, OBJ_SPRITE_OAM | 0x20d,
    0xe4, OBJ_X_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20b,
    0xea, OBJ_X_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20c,
    0xf0, OBJ_X_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20d,
    0xdd, OBJ_X_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20b
};

const u16 sSteamOAM_VerticalSmall_Frame6[13] = {
    0x4,
    0xda, OBJ_X_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20c,
    0xe2, 0x1fc, OBJ_SPRITE_OAM | 0x20c,
    0xf2, OBJ_X_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20d,
    0xe7, 0x1fc, OBJ_SPRITE_OAM | 0x20d
};

const u16 sSteamOAM_VerticalSmall_Frame7[10] = {
    0x3,
    0xe4, OBJ_X_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20d,
    0xd7, OBJ_X_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20d,
    0xef, 0x1fc, OBJ_SPRITE_OAM | 0x20d
};

const u16 sSteamDiagonalOAM_Large_Frame1[7] = {
    0x2,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x200,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202
};

const u16 sSteamDiagonalOAM_Large_Frame2[10] = {
    0x3,
    0xe8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0xb, OBJ_SPRITE_OAM | 0x200,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x2, OBJ_SPRITE_OAM | 0x202,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204
};

const u16 sSteamDiagonalOAM_Large_Frame3[13] = {
    0x4,
    0xe0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x18, OBJ_SPRITE_OAM | 0x200,
    0xe8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0xc, OBJ_SPRITE_OAM | 0x202,
    0xf0, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x204,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206
};

const u16 sSteamDiagonalOAM_Large_Frame4[22] = {
    0x7,
    0xf8, 0x1f8, OBJ_SPRITE_OAM | 0x207,
    0xfc, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x207,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x207,
    0xd8, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x25, OBJ_SPRITE_OAM | 0x200,
    0xe0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x19, OBJ_SPRITE_OAM | 0x202,
    0xe8, OBJ_SIZE_16x16 | 0xe, OBJ_SPRITE_OAM | 0x204,
    0xf0, OBJ_SIZE_16x16 | 0x3, OBJ_SPRITE_OAM | 0x206
};

const u16 sSteamDiagonalOAM_Large_Frame5[25] = {
    0x8,
    0xf8, OBJ_Y_FLIP | 0x1fb, OBJ_SPRITE_OAM | 0x208,
    0x0, 0x1fd, OBJ_SPRITE_OAM | 0x208,
    0xd0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x30, OBJ_SPRITE_OAM | 0x202,
    0xd8, OBJ_SIZE_16x16 | 0x20, OBJ_SPRITE_OAM | 0x204,
    0xe4, OBJ_SIZE_16x16 | 0x10, OBJ_SPRITE_OAM | 0x206,
    0xf0, OBJ_X_FLIP | 0x8, OBJ_SPRITE_OAM | 0x207,
    0xf4, 0x0, OBJ_SPRITE_OAM | 0x207,
    0xf8, OBJ_Y_FLIP | 0x8, OBJ_SPRITE_OAM | 0x207
};

const u16 sSteamDiagonalOAM_Large_Frame6[22] = {
    0x7,
    0xf0, OBJ_X_FLIP | OBJ_Y_FLIP | 0x3, OBJ_SPRITE_OAM | 0x208,
    0xf8, OBJ_X_FLIP | 0x1, OBJ_SPRITE_OAM | 0x208,
    0xcc, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x33, OBJ_SPRITE_OAM | 0x204,
    0xd8, OBJ_SIZE_16x16 | 0x1f, OBJ_SPRITE_OAM | 0x206,
    0xed, OBJ_Y_FLIP | 0xd, OBJ_SPRITE_OAM | 0x207,
    0xe9, OBJ_X_FLIP | OBJ_Y_FLIP | 0x15, OBJ_SPRITE_OAM | 0x207,
    0xe5, OBJ_X_FLIP | 0xd, OBJ_SPRITE_OAM | 0x207
};

const u16 sSteamDiagonalOAM_Large_Frame7[19] = {
    0x6,
    0xe8, OBJ_X_FLIP | OBJ_Y_FLIP | 0xf, OBJ_SPRITE_OAM | 0x208,
    0xf0, OBJ_X_FLIP | 0xd, OBJ_SPRITE_OAM | 0x208,
    0xc8, OBJ_SIZE_16x16 | 0x38, OBJ_SPRITE_OAM | 0x206,
    0xd5, OBJ_X_FLIP | 0x2b, OBJ_SPRITE_OAM | 0x207,
    0xd9, 0x23, OBJ_SPRITE_OAM | 0x207,
    0xdd, OBJ_Y_FLIP | 0x2b, OBJ_SPRITE_OAM | 0x207
};

const u16 sSteamDiagonalOAM_Large_Frame8[16] = {
    0x5,
    0xd8, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1a, OBJ_SPRITE_OAM | 0x208,
    0xe0, OBJ_X_FLIP | 0x18, OBJ_SPRITE_OAM | 0x208,
    0xca, OBJ_Y_FLIP | 0x3e, OBJ_SPRITE_OAM | 0x207,
    0xc6, OBJ_X_FLIP | OBJ_Y_FLIP | 0x46, OBJ_SPRITE_OAM | 0x207,
    0xc2, OBJ_X_FLIP | 0x3e, OBJ_SPRITE_OAM | 0x207
};

const u16 sSteamDiagonalOAM_Large_Frame9[7] = {
    0x2,
    0xc8, OBJ_X_FLIP | OBJ_Y_FLIP | 0x32, OBJ_SPRITE_OAM | 0x208,
    0xd0, OBJ_X_FLIP | 0x30, OBJ_SPRITE_OAM | 0x208
};

const u16 sSteamDiagonalOAM_Small_Frame1[7] = {
    0x2,
    0xf4, OBJ_X_FLIP | 0x4, OBJ_SPRITE_OAM | 0x209,
    0xf8, 0x1ff, OBJ_SPRITE_OAM | 0x209
};

const u16 sSteamDiagonalOAM_Small_Frame2[10] = {
    0x3,
    0xee, 0xb, OBJ_SPRITE_OAM | 0x209,
    0xfa, OBJ_X_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20b,
    0xf4, 0x3, OBJ_SPRITE_OAM | 0x209
};

const u16 sSteamDiagonalOAM_Small_Frame3[13] = {
    0x4,
    0xea, OBJ_X_FLIP | 0x11, OBJ_SPRITE_OAM | 0x209,
    0xf6, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x20b,
    0xf0, 0x8, OBJ_SPRITE_OAM | 0x209,
    0xf8, OBJ_X_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20c
};

const u16 sSteamDiagonalOAM_Small_Frame4[16] = {
    0x5,
    0xf9, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x20d,
    0xf2, OBJ_X_FLIP | 0x7, OBJ_SPRITE_OAM | 0x20b,
    0xf5, OBJ_X_FLIP | 0x4, OBJ_SPRITE_OAM | 0x20c,
    0xe5, OBJ_X_FLIP | 0x17, OBJ_SPRITE_OAM | 0x209,
    0xeb, OBJ_X_FLIP | 0xe, OBJ_SPRITE_OAM | 0x209
};

const u16 sSteamDiagonalOAM_Small_Frame5[16] = {
    0x5,
    0xf8, OBJ_X_FLIP | 0x3, OBJ_SPRITE_OAM | 0x20d,
    0xe9, OBJ_X_FLIP | 0x13, OBJ_SPRITE_OAM | 0x20b,
    0xee, OBJ_X_FLIP | 0xe, OBJ_SPRITE_OAM | 0x20c,
    0xf3, OBJ_X_FLIP | 0xa, OBJ_SPRITE_OAM | 0x20d,
    0xe2, OBJ_X_FLIP | 0x1c, OBJ_SPRITE_OAM | 0x20b
};

const u16 sSteamDiagonalOAM_Small_Frame6[13] = {
    0x4,
    0xdc, OBJ_X_FLIP | 0x22, OBJ_SPRITE_OAM | 0x20c,
    0xe4, OBJ_Y_FLIP | 0x19, OBJ_SPRITE_OAM | 0x20c,
    0xf0, OBJ_X_FLIP | 0xc, OBJ_SPRITE_OAM | 0x20d,
    0xeb, 0x11, OBJ_SPRITE_OAM | 0x20d
};

const u16 sSteamDiagonalOAM_Small_Frame7[10] = {
    0x3,
    0xe0, OBJ_Y_FLIP | 0x1c, OBJ_SPRITE_OAM | 0x20d,
    0xd9, OBJ_X_FLIP | 0x26, OBJ_SPRITE_OAM | 0x20d,
    0xe5, OBJ_X_FLIP | 0x13, OBJ_SPRITE_OAM | 0x20d
};

const u16 sSteamOAM_HorizontalLarge_Frame10[4] = {
    0x1,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x20e
};

const struct FrameData sSteamOAM_HorizontalLarge[12] = {
    sSteamOAM_HorizontalLarge_Frame0,
    0x2,
    sSteamOAM_HorizontalLarge_Frame1,
    0x2,
    sSteamOAM_HorizontalLarge_Frame2,
    0x2,
    sSteamOAM_HorizontalLarge_Frame3,
    0x2,
    sSteamOAM_HorizontalLarge_Frame4,
    0x2,
    sSteamOAM_HorizontalLarge_Frame5,
    0x2,
    sSteamOAM_HorizontalLarge_Frame6,
    0x3,
    sSteamOAM_HorizontalLarge_Frame7,
    0x3,
    sSteamOAM_HorizontalLarge_Frame8,
    0x4,
    sSteamOAM_HorizontalLarge_Frame9,
    0x4,
    sSteamOAM_HorizontalLarge_Frame10,
    0x28,
    NULL,
    0x0
};

const struct FrameData sSteamOAM_VerticalLarge[12] = {
    sSteamOAM_HorizontalLarge_Frame0,
    0x2,
    sSteamOAM_VerticalLarge_Frame1,
    0x2,
    sSteamOAM_VerticalLarge_Frame2,
    0x2,
    sSteamOAM_VerticalLarge_Frame3,
    0x2,
    sSteamOAM_VerticalLarge_Frame4,
    0x2,
    sSteamOAM_VerticalLarge_Frame5,
    0x2,
    sSteamOAM_VerticalLarge_Frame6,
    0x3,
    sSteamOAM_VerticalLarge_Frame7,
    0x3,
    sSteamOAM_VerticalLarge_Frame8,
    0x4,
    sSteamOAM_VerticalLarge_Frame9,
    0x4,
    sSteamOAM_HorizontalLarge_Frame10,
    0x1E,
    NULL,
    0x0
};

const struct FrameData sSteamOAM_HorizontalSmall[10] = {
    sSteamOAM_HorizontalSmall_Frame0,
    0x2,
    sSteamOAM_HorizontalSmall_Frame1,
    0x2,
    sSteamOAM_HorizontalSmall_Frame2,
    0x2,
    sSteamOAM_HorizontalSmall_Frame3,
    0x2,
    sSteamOAM_HorizontalSmall_Frame4,
    0x2,
    sSteamOAM_HorizontalSmall_Frame5,
    0x3,
    sSteamOAM_HorizontalSmall_Frame6,
    0x3,
    sSteamOAM_HorizontalSmall_Frame7,
    0x3,
    sSteamOAM_HorizontalLarge_Frame10,
    0x14,
    NULL,
    0x0
};

const struct FrameData sSteamOAM_VerticalSmall[10] = {
    sSteamOAM_HorizontalSmall_Frame0,
    0x2,
    sSteamOAM_HorizontalSmall_Frame1,
    0x2,
    sSteamOAM_HorizontalSmall_Frame2,
    0x2,
    sSteamOAM_HorizontalSmall_Frame3,
    0x2,
    sSteamOAM_HorizontalSmall_Frame4,
    0x2,
    sSteamOAM_HorizontalSmall_Frame5,
    0x3,
    sSteamOAM_HorizontalSmall_Frame6,
    0x3,
    sSteamOAM_HorizontalSmall_Frame7,
    0x3,
    sSteamOAM_HorizontalLarge_Frame10,
    0xA,
    NULL,
    0x0
};

const struct FrameData sSteamDiagonalOAM_Large[12] = {
    sSteamOAM_HorizontalLarge_Frame0,
    0x2,
    sSteamDiagonalOAM_Large_Frame1,
    0x2,
    sSteamDiagonalOAM_Large_Frame2,
    0x2,
    sSteamDiagonalOAM_Large_Frame3,
    0x2,
    sSteamDiagonalOAM_Large_Frame4,
    0x2,
    sSteamDiagonalOAM_Large_Frame5,
    0x2,
    sSteamDiagonalOAM_Large_Frame6,
    0x3,
    sSteamDiagonalOAM_Large_Frame7,
    0x3,
    sSteamDiagonalOAM_Large_Frame8,
    0x4,
    sSteamDiagonalOAM_Large_Frame9,
    0x4,
    sSteamOAM_HorizontalLarge_Frame10,
    0x23,
    NULL,
    0x0
};

const struct FrameData sSteamDiagonalOAM_Small[10] = {
    sSteamOAM_HorizontalSmall_Frame0,
    0x2,
    sSteamDiagonalOAM_Small_Frame1,
    0x2,
    sSteamDiagonalOAM_Small_Frame2,
    0x2,
    sSteamDiagonalOAM_Small_Frame3,
    0x2,
    sSteamDiagonalOAM_Small_Frame4,
    0x2,
    sSteamDiagonalOAM_Small_Frame5,
    0x3,
    sSteamDiagonalOAM_Small_Frame6,
    0x3,
    sSteamDiagonalOAM_Small_Frame7,
    0x3,
    sSteamOAM_HorizontalLarge_Frame10,
    0xF,
    NULL,
    0x0
};


/**
 * @brief 4a5e4 | 208 | Steam AI
 * 
 */
void Steam(void)
{
    u8 isLarge;

    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    isLarge = FALSE;

    if (gCurrentSprite.pose == 0x0)
    {
        gCurrentSprite.pose = 0x9;

        // Check is large
        if (gCurrentSprite.spriteID == PSPRITE_STEAM_LARGE)
            isLarge = TRUE;

        gCurrentSprite.workVariable = isLarge;

        // Check for walls
        if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition) &
            (COLLISION_PASS_THROUGH_BOTTOM | 0x20 | 0x40 | 0x80))
        {
            // Steam on ground
            gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN2;

            if (isLarge)
            {
                gCurrentSprite.drawDistanceTopOffset = 0x48;
                gCurrentSprite.drawDistanceBottomOffset = 0x8;
                gCurrentSprite.drawDistanceHorizontalOffset = 0x8;
            }
            else
            {
                gCurrentSprite.drawDistanceTopOffset = 0x28;
                gCurrentSprite.drawDistanceBottomOffset = 0x4;
                gCurrentSprite.drawDistanceHorizontalOffset = 0x8;
            }
        }
        else
        {
            if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - (BLOCK_SIZE + 4), gCurrentSprite.xPosition) &
                (COLLISION_PASS_THROUGH_BOTTOM | 0x20 | 0x40 | 0x80))
            {
                // Steam on ceiling
                gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN2;
                gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
                gCurrentSprite.yPosition -= BLOCK_SIZE;

                if (isLarge)
                {
                    gCurrentSprite.drawDistanceTopOffset = 0x8;
                    gCurrentSprite.drawDistanceBottomOffset = 0x48;
                    gCurrentSprite.drawDistanceHorizontalOffset = 0x8;
                }
                else
                {
                    gCurrentSprite.drawDistanceTopOffset = 0x4;
                    gCurrentSprite.drawDistanceBottomOffset = 0x28;
                    gCurrentSprite.drawDistanceHorizontalOffset = 0x8;
                }
            }
            else
            {
                if (isLarge)
                {
                    gCurrentSprite.drawDistanceTopOffset = 0x8;
                    gCurrentSprite.drawDistanceBottomOffset = 0x8;
                    gCurrentSprite.drawDistanceHorizontalOffset = 0x48;
                }
                else
                {
                    gCurrentSprite.drawDistanceTopOffset = 0x8;
                    gCurrentSprite.drawDistanceBottomOffset = 0x8;
                    gCurrentSprite.drawDistanceHorizontalOffset = 0x30;
                }

                if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - (BLOCK_SIZE / 2), gCurrentSprite.xPosition - ((BLOCK_SIZE / 2 + 4))) &
                    (COLLISION_PASS_THROUGH_BOTTOM | 0x20 | 0x40 | 0x80))
                {
                    // Steam on left wall
                    gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;
                    gCurrentSprite.yPosition -= (BLOCK_SIZE / 2);
                    gCurrentSprite.xPosition -= (BLOCK_SIZE / 2);
                }
                else
                {
                    if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - (BLOCK_SIZE / 2), gCurrentSprite.xPosition + (BLOCK_SIZE / 2)) &
                        (COLLISION_PASS_THROUGH_BOTTOM | 0x20 | 0x40 | 0x80))
                    {
                        // Steam on right wall
                        gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;
                        gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
                        gCurrentSprite.yPosition -= (BLOCK_SIZE / 2);
                        gCurrentSprite.xPosition += (BLOCK_SIZE / 2);
                    }
                    else
                    {
                        // Steam in the air, kill
                        gCurrentSprite.status = 0x0;
                        return;
                    }
                }
            }
        }

        // Set OAM
        if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
        {
            if (isLarge)
                gCurrentSprite.pOam = sSteamOAM_HorizontalLarge;
            else
                gCurrentSprite.pOam = sSteamOAM_HorizontalSmall;
        }
        else
        {
            if (isLarge)
                gCurrentSprite.pOam = sSteamOAM_VerticalLarge;
            else
                gCurrentSprite.pOam = sSteamOAM_VerticalSmall;
        }

        gCurrentSprite.animationDurationCounter = 0x0;
        // Animation starts at the random frame
        // desyncs the steams and allows them to be already blowing on room load
        gCurrentSprite.currentAnimationFrame = gSpriteRNG & 0x7;
        
        gCurrentSprite.hitboxTopOffset = 0x0;
        gCurrentSprite.hitboxBottomOffset = 0x0;
        gCurrentSprite.hitboxLeftOffset = 0x0;
        gCurrentSprite.hitboxRightOffset = 0x0;

        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;

    }

    if (gCurrentSprite.currentAnimationFrame == 0x0 && gCurrentSprite.animationDurationCounter == 0x2
        && gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
    {
        if (gCurrentSprite.workVariable) // Is large flag
            SoundPlayNotAlreadyPlaying(0x278);
        else
            SoundPlayNotAlreadyPlaying(0x279);
    }
}

/**
 * @brief 4a7ec | 144 | Steam (diagonal) AI
 * 
 */
void SteamDiagonal(void)
{
    u8 collision;

    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;

    if (gCurrentSprite.pose == 0x0)
    {
        gCurrentSprite.pose = 0x9;
        gCurrentSprite.workVariable = FALSE; // Not large by default

        collision = SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - (BLOCK_SIZE / 2), gCurrentSprite.xPosition - ((BLOCK_SIZE / 2) + 4));
        if (!(collision & (COLLISION_PASS_THROUGH_BOTTOM | 0x20 | 0x40 | 0x80)))
            gCurrentSprite.status |= SPRITE_STATUS_XFLIP; // Flip if wall on left

        if (gCurrentSprite.spriteID == PSPRITE_STEAM_LARGE_DIAGONAL_UP)
        {
            gCurrentSprite.workVariable = TRUE; // Is large flag
            gCurrentSprite.drawDistanceTopOffset = 0x40;
            gCurrentSprite.drawDistanceBottomOffset = 0x8;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x50;
            gCurrentSprite.pOam = sSteamDiagonalOAM_Large;
        }
        else if (gCurrentSprite.spriteID == PSPRITE_STEAM_SMALL_DIAGONAL_UP)
        {
            gCurrentSprite.drawDistanceTopOffset = 0x28;
            gCurrentSprite.drawDistanceBottomOffset = 0x4;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x30;
            gCurrentSprite.pOam = sSteamDiagonalOAM_Small;
        }
        else if (gCurrentSprite.spriteID == PSPRITE_STEAM_LARGE_DIAGONAL_DOWN)
        {
            gCurrentSprite.workVariable = TRUE; // Is large flag
            gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
            gCurrentSprite.drawDistanceTopOffset = 0x8;
            gCurrentSprite.drawDistanceBottomOffset = 0x40;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x50;
            gCurrentSprite.pOam = sSteamDiagonalOAM_Large;
        }
        else if (gCurrentSprite.spriteID == PSPRITE_STEAM_SMALL_DIAGONAL_DOWN)
        {
            gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
            gCurrentSprite.drawDistanceTopOffset = 0x4;
            gCurrentSprite.drawDistanceBottomOffset = 0x28;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x30;
            gCurrentSprite.pOam = sSteamDiagonalOAM_Small;
        }
        else
        {
            gCurrentSprite.status = 0x0;
            return;
        }

        gCurrentSprite.animationDurationCounter = 0x0;
        // Animation starts at the random frame
        // desyncs the steams and allows them to be already blowing on room load
        gCurrentSprite.currentAnimationFrame = gSpriteRNG & 0x7;

        gCurrentSprite.hitboxTopOffset = 0x0;
        gCurrentSprite.hitboxBottomOffset = 0x0;
        gCurrentSprite.hitboxLeftOffset = 0x0;
        gCurrentSprite.hitboxRightOffset = 0x0;

        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;
    }
    
    if (gCurrentSprite.currentAnimationFrame == 0x0 && gCurrentSprite.animationDurationCounter == 0x2
        && gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
    {
        if (gCurrentSprite.workVariable) // Is large flag
            SoundPlayNotAlreadyPlaying(0x278);
        else
            SoundPlayNotAlreadyPlaying(0x279);
    }
}