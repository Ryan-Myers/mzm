#include "geron_norfair.h"
#include "../clipdata.h"
#include "../event.h"
#include "../../data/data.h"
#include "../globals.h"

const u32 sGeronNorfairGFX[270];
const u16 sGeronNorfairPAL[16];

const u16 sGeronNorfairOAM_Idle_Frame0[43] = {
    0xe,
    0xef, 0x8, OBJ_SPRITE_OAM | 0x218,
    0xe7, 0x1f1, OBJ_SPRITE_OAM | 0x238,
    0xd0, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x210,
    0xd0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xe0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x213,
    0xcf, 0x1f0, OBJ_SPRITE_OAM | 0x237,
    OBJ_SHAPE_HORIZONTAL | 0xe0, 0x1f5, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_Y_FLIP | 0x1f5, OBJ_SPRITE_OAM | 0x21a,
    0xd8, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21c,
    0xd8, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x21e,
    0xe8, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21c,
    0xe8, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x21e,
    0xce, OBJ_Y_FLIP | 0x8, OBJ_SPRITE_OAM | 0x237
};

const u16 sGeronNorfairOAM_Idle_Frame1[43] = {
    0xe,
    0xf0, 0x9, OBJ_SPRITE_OAM | 0x218,
    0xe6, 0x1f0, OBJ_SPRITE_OAM | 0x238,
    0xd0, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x210,
    0xd0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xe0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x213,
    0xd0, 0x1f0, OBJ_SPRITE_OAM | 0x237,
    OBJ_SHAPE_HORIZONTAL | 0xe0, 0x1f5, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_Y_FLIP | 0x1f5, OBJ_SPRITE_OAM | 0x21a,
    0xd8, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21c,
    0xd8, OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x21e,
    0xe8, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21c,
    0xe8, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x21e
};

const u16 sGeronNorfairOAM_Idle_Frame2[43] = {
    0xe,
    0xef, 0xa, OBJ_SPRITE_OAM | 0x238,
    0xe6, 0x1f1, OBJ_SPRITE_OAM | 0x238,
    OBJ_SHAPE_HORIZONTAL | 0xd0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xe0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x204,
    0xf0, 0x1fd, OBJ_SPRITE_OAM | 0x212,
    0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x232,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x213,
    0xd1, 0x1f0, OBJ_SPRITE_OAM | 0x237,
    OBJ_SHAPE_HORIZONTAL | 0xe0, 0x1f5, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_Y_FLIP | 0x1f5, OBJ_SPRITE_OAM | 0x21a,
    0xd8, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21c,
    0xd8, OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x21e,
    0xe7, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21c,
    0xe7, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x21e
};

const u16 sGeronNorfairOAM_Idle_Frame3[43] = {
    0xe,
    0xf0, 0x9, OBJ_SPRITE_OAM | 0x238,
    0xe5, 0x1f0, OBJ_SPRITE_OAM | 0x238,
    0xd0, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x210,
    0xd0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xe0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x213,
    0xd2, 0x1f0, OBJ_SPRITE_OAM | 0x237,
    OBJ_SHAPE_HORIZONTAL | 0xe0, 0x1f5, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_Y_FLIP | 0x1f5, OBJ_SPRITE_OAM | 0x21a,
    0xd8, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21c,
    0xd8, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x21e,
    0xe8, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21c,
    0xe8, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x21e
};

const u16 sGeronNorfairOAM_Idle_Frame4[43] = {
    0xe,
    0xef, 0x8, OBJ_SPRITE_OAM | 0x219,
    0xe6, 0x1f1, OBJ_SPRITE_OAM | 0x218,
    0xd0, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x210,
    0xd0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xe0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x213,
    OBJ_SHAPE_VERTICAL | 0xcc, 0x1f0, OBJ_SPRITE_OAM | 0x217,
    0xcd, 0x8, OBJ_SPRITE_OAM | 0x237,
    OBJ_SHAPE_HORIZONTAL | 0xe0, 0x1f5, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_Y_FLIP | 0x1f5, OBJ_SPRITE_OAM | 0x21a,
    0xd8, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21c,
    0xd8, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x21e,
    0xe8, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21c,
    0xe8, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x21e
};

const u16 sGeronNorfairOAM_Unused_Frame[43] = {
    0xe,
    0xf0, 0x8, OBJ_SPRITE_OAM | 0x219,
    0xe5, 0x1f1, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_HORIZONTAL | 0xd0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xe0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x213,
    OBJ_SHAPE_VERTICAL | 0xce, 0x1f0, OBJ_SPRITE_OAM | 0x217,
    0xce, 0x8, OBJ_SPRITE_OAM | 0x237,
    OBJ_SHAPE_HORIZONTAL | 0xe0, 0x1f5, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_Y_FLIP | 0x1f5, OBJ_SPRITE_OAM | 0x21a,
    0xd8, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21c,
    0xd8, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x21e,
    0xe8, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21c,
    0xe8, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x21e
};

const u16 sGeronNorfairOAM_Idle_Frame5[46] = {
    0xf,
    0xf0, 0x8, OBJ_SPRITE_OAM | 0x219,
    0xe5, 0x1f1, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_HORIZONTAL | 0xd0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xe0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x204,
    0xf0, 0x1fd, OBJ_SPRITE_OAM | 0x212,
    0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x232,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x213,
    0xd0, 0x1f0, OBJ_SPRITE_OAM | 0x217,
    0xd0, 0x8, OBJ_SPRITE_OAM | 0x237,
    OBJ_SHAPE_HORIZONTAL | 0xe0, 0x1f5, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_Y_FLIP | 0x1f5, OBJ_SPRITE_OAM | 0x21a,
    0xd8, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21c,
    0xd8, OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x21e,
    0xe7, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21c,
    0xe7, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x21e
};

const u16 sGeronNorfairOAM_Idle_Frame6[46] = {
    0xf,
    0xf0, 0x8, OBJ_SPRITE_OAM | 0x238,
    0xe7, 0x1f1, OBJ_SPRITE_OAM | 0x239,
    0xd0, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x210,
    0xd0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xe0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x213,
    0xcf, OBJ_Y_FLIP | 0x8, OBJ_SPRITE_OAM | 0x237,
    0xd2, 0x8, OBJ_SPRITE_OAM | 0x237,
    OBJ_SHAPE_HORIZONTAL | 0xe0, 0x1f5, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_Y_FLIP | 0x1f5, OBJ_SPRITE_OAM | 0x21a,
    0xd8, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21c,
    0xd8, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x21e,
    0xe8, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21c,
    0xe8, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x21e
};

const u16 sGeronNorfairOAM_Idle_Frame7[40] = {
    0xd,
    0xf0, 0x8, OBJ_SPRITE_OAM | 0x218,
    0xe5, 0x1f1, OBJ_SPRITE_OAM | 0x218,
    0xd0, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x210,
    0xd0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xe0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x213,
    OBJ_SHAPE_VERTICAL | 0xcd, 0x8, OBJ_SPRITE_OAM | 0x217,
    OBJ_SHAPE_HORIZONTAL | 0xe0, 0x1f5, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_Y_FLIP | 0x1f5, OBJ_SPRITE_OAM | 0x21a,
    0xd8, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21c,
    0xd8, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x21e,
    0xe8, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21c,
    0xe8, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x21e
};

const u16 sGeronNorfairOAM_Idle_Frame8[43] = {
    0xe,
    0xf0, 0x8, OBJ_SPRITE_OAM | 0x239,
    0xe4, 0x1f1, OBJ_SPRITE_OAM | 0x238,
    0xd0, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x210,
    0xd0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xe0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x213,
    0xce, OBJ_Y_FLIP | 0x8, OBJ_SPRITE_OAM | 0x237,
    0xd6, 0x8, OBJ_SPRITE_OAM | 0x237,
    OBJ_SHAPE_HORIZONTAL | 0xe0, 0x1f5, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_Y_FLIP | 0x1f5, OBJ_SPRITE_OAM | 0x21a,
    0xd8, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21c,
    0xd8, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x21e,
    0xe8, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21c,
    0xe8, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x21e
};

const u16 sGeronNorfairOAM_Idle_Frame9[43] = {
    0xe,
    0xf0, 0x8, OBJ_SPRITE_OAM | 0x239,
    0xe5, 0x1f1, OBJ_SPRITE_OAM | 0x238,
    0xd0, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x210,
    0xd0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xe0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x213,
    0xce, 0x1f0, OBJ_SPRITE_OAM | 0x237,
    OBJ_SHAPE_HORIZONTAL | 0xe0, 0x1f5, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_Y_FLIP | 0x1f5, OBJ_SPRITE_OAM | 0x21a,
    0xd8, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21c,
    0xd8, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x21e,
    0xe8, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21c,
    0xe8, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x21e,
    0xd1, OBJ_Y_FLIP | 0x8, OBJ_SPRITE_OAM | 0x237
};

const struct FrameData sGeronNorfairOAM_Idle[11] = {
    sGeronNorfairOAM_Idle_Frame0,
    0xC,
    sGeronNorfairOAM_Idle_Frame1,
    0xC,
    sGeronNorfairOAM_Idle_Frame2,
    0xC,
    sGeronNorfairOAM_Idle_Frame3,
    0xC,
    sGeronNorfairOAM_Idle_Frame4,
    0xC,
    sGeronNorfairOAM_Idle_Frame5,
    0xC,
    sGeronNorfairOAM_Idle_Frame6,
    0xC,
    sGeronNorfairOAM_Idle_Frame7,
    0xC,
    sGeronNorfairOAM_Idle_Frame8,
    0xC,
    sGeronNorfairOAM_Idle_Frame9,
    0xC,
    NULL,
    0x0
};

/**
 * 40178 | b8 | Geron Norfair AI
 * 
 */
void GeronNorfair(void)
{
    u8 caa;
    u16 yPosition;
    u16 xPosition;

    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    if (gCurrentSprite.pose == 0x0)
    {
        if (EventFunction(EVENT_ACTION_CHECKING, EVENT_POWER_GRIP_OBTAINED))
            gCurrentSprite.status = 0x0;
        else
        {
            gCurrentSprite.drawDistanceTopOffset = 0x30;
            gCurrentSprite.drawDistanceBottomOffset = 0x0;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x14;

            gCurrentSprite.hitboxTopOffset = -0xC0;
            gCurrentSprite.hitboxBottomOffset = 0x0;
            gCurrentSprite.hitboxLeftOffset = -0x30;
            gCurrentSprite.hitboxRightOffset = 0x30;

            gCurrentSprite.drawOrder = 0x5;
            gCurrentSprite.currentAnimationFrame = 0x0;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.samusCollision = SSC_NONE;

            gCurrentSprite.pose = 0x9;
            gCurrentSprite.health = 0x1;
            gCurrentSprite.pOam = sGeronNorfairOAM_Idle;

            yPosition = gCurrentSprite.yPosition - 0x20;
            xPosition = gCurrentSprite.xPosition;
            caa = CAA_MAKE_SOLID3;
            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition, xPosition);
            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition - 0x40, xPosition);
            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition - 0x80, xPosition);
        }
    }
}