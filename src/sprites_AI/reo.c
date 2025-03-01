#include "reo.h"
#include "../sprite_util.h"
#include "../globals.h"

void ReoInit(void)
{
    gCurrentSprite.drawDistanceTopOffset = 0x18;
    gCurrentSprite.drawDistanceBottomOffset = 0x18;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x18;
    gCurrentSprite.hitboxTopOffset = -0x20;
    gCurrentSprite.hitboxBottomOffset = 0x20;
    gCurrentSprite.hitboxLeftOffset = -0x38;
    gCurrentSprite.hitboxRightOffset = 0x38;
    gCurrentSprite.pOam = reo_oam_2ce214;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.health = sPrimarySpriteStats[gCurrentSprite.spriteID][0];
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    SpriteUtilChooseRandomXDirection();
    if (0x8 < gSpriteRNG)
        gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;
    gCurrentSprite.pose = 0x8;
}

void ReoRNG(void)
{
    gCurrentSprite.pose = 0x9;
    gCurrentSprite.workVariable2 = (gSpriteRNG << 0x1A) >> 0x18;
    gCurrentSprite.arrayOffset = gCurrentSprite.workVariable2;
}

void ReoSamusDetection(void)
{
    i16 movement;
    u8 offset;

    offset = gCurrentSprite.arrayOffset;
    movement = reo_idle_anim_yPosition_offsets[offset];
    if (movement == SPRITE_ARRAY_TERMINATOR)
    {
        movement = reo_idle_anim_yPosition_offsets[0];
        offset = 0x0;
    }
    gCurrentSprite.arrayOffset = offset + 0x1;
    gCurrentSprite.yPosition += movement;
    
    offset = gCurrentSprite.workVariable2;
    movement = reo_idle_anim_xPosition_offsets[offset];
    if (movement == SPRITE_ARRAY_TERMINATOR)
    {
        movement = reo_idle_anim_xPosition_offsets[0];
        offset = 0x0;
    }
    gCurrentSprite.workVariable2 = offset + 0x1;
    gCurrentSprite.xPosition += movement;

    if (SpriteUtilCheckSamusNearSpriteLeftRight(0x200, 0x1C0) != NSLR_OUT_OF_RANGE)
        gCurrentSprite.pose = 0x22;
}

void ReoSamusDetected(void)
{

}

void ReoMove(void)
{

}

void Reo(void)
{
    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(0x159);
    }

    if (gCurrentSprite.freezeTimer != 0x0)
        SpriteUtilUpdateFreezeTimer();
    else
    {
        if (!SpriteUtilIsSpriteStunned())
        {
            switch (gCurrentSprite.pose)
            {
                case 0x0:
                    ReoInit();
                    break;
                case 0x8:
                    ReoRNG();
                    break;
                case 0x9:
                    ReoSamusDetection();
                    break;
                case 0x22:
                    ReoSamusDetected();
                case 0x23:
                    ReoMove();
                    break;
                default:
                    SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_BIG);
            }
        }
    }
}