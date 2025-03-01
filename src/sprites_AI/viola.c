#include "viola.h"
#include "../../data/data.h"
#include "../globals.h"

const u32 sViolaBlueGFX[302];
const u16 sViolaBluePAL[16];
const u32 sViolaOrangeGFX[305];
const u16 sViolaOrangePAL[16];

const u16 sViolaOAM_Moving_Frame0[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200
};

const u16 sViolaOAM_Moving_Frame1[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202
};

const u16 sViolaOAM_Moving_Frame2[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204
};

const u16 sViolaOAM_Moving_Frame3[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206
};

const u16 sViolaOAM_Moving_Frame4[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x208
};

const u16 sViolaOAM_Moving_Frame5[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20a
};

const u16 sViolaOAM_Moving_Frame6[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20c
};

const u16 sViolaOAM_Moving_Frame7[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20e
};

const u16 sViolaOAM_Moving_Frame8[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x210
};

const u16 sViolaOAM_MovingOffsetUp_Frame0[4] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200
};

const u16 sViolaOAM_MovingOffsetUp_Frame1[4] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202
};

const u16 sViolaOAM_MovingOffsetUp_Frame2[4] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204
};

const u16 sViolaOAM_MovingOffsetUp_Frame3[4] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206
};

const u16 sViolaOAM_MovingOffsetUp_Frame4[4] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x208
};

const u16 sViolaOAM_MovingOffsetUp_Frame5[4] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20a
};

const u16 sViolaOAM_MovingOffsetUp_Frame6[4] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20c
};

const u16 sViolaOAM_MovingOffsetUp_Frame7[4] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20e
};

const u16 sViolaOAM_MovingOffsetUp_Frame8[4] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x210
};

const u16 sViolaOAM_MovingOffsetRight_Frame0[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0xf8, OBJ_SPRITE_OAM | 0x200
};

const u16 sViolaOAM_MovingOffsetRight_Frame1[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0xf8, OBJ_SPRITE_OAM | 0x202
};

const u16 sViolaOAM_MovingOffsetRight_Frame2[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0xf8, OBJ_SPRITE_OAM | 0x204
};

const u16 sViolaOAM_MovingOffsetRight_Frame3[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0xf8, OBJ_SPRITE_OAM | 0x206
};

const u16 sViolaOAM_MovingOffsetRight_Frame4[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0xf8, OBJ_SPRITE_OAM | 0x208
};

const u16 sViolaOAM_MovingOffsetRight_Frame5[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0xf8, OBJ_SPRITE_OAM | 0x20a
};

const u16 sViolaOAM_MovingOffsetRight_Frame6[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0xf8, OBJ_SPRITE_OAM | 0x20c
};

const u16 sViolaOAM_MovingOffsetRight_Frame7[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0xf8, OBJ_SPRITE_OAM | 0x20e
};

const u16 sViolaOAM_MovingOffsetRight_Frame8[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0xf8, OBJ_SPRITE_OAM | 0x210
};

const u16 sViolaOAM_MovingOffsetDown_Frame0[4] = {
    0x1,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200
};

const u16 sViolaOAM_MovingOffsetDown_Frame1[4] = {
    0x1,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202
};

const u16 sViolaOAM_MovingOffsetDown_Frame2[4] = {
    0x1,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204
};

const u16 sViolaOAM_MovingOffsetDown_Frame3[4] = {
    0x1,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206
};

const u16 sViolaOAM_MovingOffsetDown_Frame4[4] = {
    0x1,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x208
};

const u16 sViolaOAM_MovingOffsetDown_Frame5[4] = {
    0x1,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20a
};

const u16 sViolaOAM_MovingOffsetDown_Frame6[4] = {
    0x1,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20c
};

const u16 sViolaOAM_MovingOffsetDown_Frame7[4] = {
    0x1,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20e
};

const u16 sViolaOAM_MovingOffsetDown_Frame8[4] = {
    0x1,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x210
};

const struct FrameData sViolaOAM_Moving[17] = {
    sViolaOAM_Moving_Frame0,
    0xA,
    sViolaOAM_Moving_Frame1,
    0xA,
    sViolaOAM_Moving_Frame2,
    0xA,
    sViolaOAM_Moving_Frame3,
    0xA,
    sViolaOAM_Moving_Frame4,
    0xA,
    sViolaOAM_Moving_Frame5,
    0xA,
    sViolaOAM_Moving_Frame6,
    0xA,
    sViolaOAM_Moving_Frame7,
    0xA,
    sViolaOAM_Moving_Frame8,
    0xA,
    sViolaOAM_Moving_Frame7,
    0xA,
    sViolaOAM_Moving_Frame6,
    0xA,
    sViolaOAM_Moving_Frame5,
    0xA,
    sViolaOAM_Moving_Frame4,
    0xA,
    sViolaOAM_Moving_Frame3,
    0xA,
    sViolaOAM_Moving_Frame2,
    0xA,
    sViolaOAM_Moving_Frame1,
    0xA,
    NULL,
    0x0
};

const struct FrameData sViolaOAM_MovingOffsetUp[17] = {
    sViolaOAM_MovingOffsetUp_Frame0,
    0xA,
    sViolaOAM_MovingOffsetUp_Frame1,
    0xA,
    sViolaOAM_MovingOffsetUp_Frame2,
    0xA,
    sViolaOAM_MovingOffsetUp_Frame3,
    0xA,
    sViolaOAM_MovingOffsetUp_Frame4,
    0xA,
    sViolaOAM_MovingOffsetUp_Frame5,
    0xA,
    sViolaOAM_MovingOffsetUp_Frame6,
    0xA,
    sViolaOAM_MovingOffsetUp_Frame7,
    0xA,
    sViolaOAM_MovingOffsetUp_Frame8,
    0xA,
    sViolaOAM_MovingOffsetUp_Frame7,
    0xA,
    sViolaOAM_MovingOffsetUp_Frame6,
    0xA,
    sViolaOAM_MovingOffsetUp_Frame5,
    0xA,
    sViolaOAM_MovingOffsetUp_Frame4,
    0xA,
    sViolaOAM_MovingOffsetUp_Frame3,
    0xA,
    sViolaOAM_MovingOffsetUp_Frame2,
    0xA,
    sViolaOAM_MovingOffsetUp_Frame1,
    0xA,
    NULL,
    0x0
};

const struct FrameData sViolaOAM_MovingOffsetRight[17] = {
    sViolaOAM_MovingOffsetRight_Frame0,
    0xA,
    sViolaOAM_MovingOffsetRight_Frame1,
    0xA,
    sViolaOAM_MovingOffsetRight_Frame2,
    0xA,
    sViolaOAM_MovingOffsetRight_Frame3,
    0xA,
    sViolaOAM_MovingOffsetRight_Frame4,
    0xA,
    sViolaOAM_MovingOffsetRight_Frame5,
    0xA,
    sViolaOAM_MovingOffsetRight_Frame6,
    0xA,
    sViolaOAM_MovingOffsetRight_Frame7,
    0xA,
    sViolaOAM_MovingOffsetRight_Frame8,
    0xA,
    sViolaOAM_MovingOffsetRight_Frame7,
    0xA,
    sViolaOAM_MovingOffsetRight_Frame6,
    0xA,
    sViolaOAM_MovingOffsetRight_Frame5,
    0xA,
    sViolaOAM_MovingOffsetRight_Frame4,
    0xA,
    sViolaOAM_MovingOffsetRight_Frame3,
    0xA,
    sViolaOAM_MovingOffsetRight_Frame2,
    0xA,
    sViolaOAM_MovingOffsetRight_Frame1,
    0xA,
    NULL,
    0x0
};

const struct FrameData sViolaOAM_MovingOffsetDown[17] = {
    sViolaOAM_MovingOffsetDown_Frame0,
    0xA,
    sViolaOAM_MovingOffsetDown_Frame1,
    0xA,
    sViolaOAM_MovingOffsetDown_Frame2,
    0xA,
    sViolaOAM_MovingOffsetDown_Frame3,
    0xA,
    sViolaOAM_MovingOffsetDown_Frame4,
    0xA,
    sViolaOAM_MovingOffsetDown_Frame5,
    0xA,
    sViolaOAM_MovingOffsetDown_Frame6,
    0xA,
    sViolaOAM_MovingOffsetDown_Frame7,
    0xA,
    sViolaOAM_MovingOffsetDown_Frame8,
    0xA,
    sViolaOAM_MovingOffsetDown_Frame7,
    0xA,
    sViolaOAM_MovingOffsetDown_Frame6,
    0xA,
    sViolaOAM_MovingOffsetDown_Frame5,
    0xA,
    sViolaOAM_MovingOffsetDown_Frame4,
    0xA,
    sViolaOAM_MovingOffsetDown_Frame3,
    0xA,
    sViolaOAM_MovingOffsetDown_Frame2,
    0xA,
    sViolaOAM_MovingOffsetDown_Frame1,
    0xA,
    NULL,
    0x0
};


/**
 * @brief 3743c | 120 | Initializes a viola sprite
 * 
 */
void ViolaInit(void)
{
    SpriteUtilChooseRandomXDirection();
    gCurrentSprite.yPosition -= (BLOCK_SIZE / 2);

    // Check for solid blocks around
    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition +(BLOCK_SIZE / 2), gCurrentSprite.xPosition);
    if (gPreviousCollisionCheck & 0xF0)
    {
        gCurrentSprite.yPosition += 0x8;
        gCurrentSprite.pose = VIOLA_POSE_MOVE_RIGHT;
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - 0x24, gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck & 0xF0)
        {
            gCurrentSprite.yPosition -= 0x8;
            gCurrentSprite.pose = VIOLA_POSE_MOVE_LEFT;
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition - 0x24);
            if (gPreviousCollisionCheck & 0xF0)
            {
                gCurrentSprite.xPosition -= 0x8;
                gCurrentSprite.pose = VIOLA_POSE_MOVE_DOWN;
            }
            else
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition + 0x24);
                if (gPreviousCollisionCheck & 0xF0)
                {
                    gCurrentSprite.xPosition += 0x8;
                    gCurrentSprite.pose = VIOLA_POSE_MOVE_UP;
                }
                else
                {
                    gCurrentSprite.status = 0x0;
                    return;
                }
            }
        }
    }

    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;

    gCurrentSprite.pOam = sViolaOAM_Moving;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.health = sPrimarySpriteStats[gCurrentSprite.spriteID][0];

    gCurrentSprite.drawDistanceTopOffset = 0x10;
    gCurrentSprite.drawDistanceBottomOffset = 0x10;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

    gCurrentSprite.hitboxTopOffset = -0x14;
    gCurrentSprite.hitboxBottomOffset = 0x14;
    gCurrentSprite.hitboxLeftOffset = -0x14;
    gCurrentSprite.hitboxRightOffset = 0x14;

    // Set speed
    if (gCurrentSprite.spriteID == PSPRITE_VIOLA_ORANGE)
        gCurrentSprite.workVariable2 = 0x4;
    else
        gCurrentSprite.workVariable2 = 0x2;
}

/**
 * @brief 3755c | 1a8 | Handles the viola moving to the right
 * 
 */
void ViolaMoveRight(void)
{
    u16 velocity;
    u16 yPosition;
    u16 xPosition;
    u32 topEdge;

    velocity = gCurrentSprite.workVariable2;
    yPosition = gCurrentSprite.yPosition + 0x18;
    xPosition = gCurrentSprite.xPosition;

    // Check should fall
    SpriteUtilCheckCollisionAtPosition(yPosition, xPosition + 0x1C);
    if (gPreviousCollisionCheck == COLLISION_AIR)
    {
        SpriteUtilCheckCollisionAtPosition(yPosition, xPosition - 0x20);
        if (gPreviousCollisionCheck == COLLISION_AIR)
        {
            gCurrentSprite.pose = VIOLA_POSE_FALLING_INIT;
            return;
        }
    }

    // Handle slope movement
    topEdge = SpriteUtilCheckVerticalCollisionAtPosition(yPosition - 0x4, xPosition);
    if ((gPreviousVerticalCollisionCheck & 0xF) > 0x1)
        gCurrentSprite.yPosition = topEdge - 0x18;
    else
    {
        topEdge = SpriteUtilCheckVerticalCollisionAtPosition(yPosition, xPosition);
        if ((gPreviousVerticalCollisionCheck & 0xF) > 0x1)
            gCurrentSprite.yPosition = topEdge - 0x18;
        else
        {
            topEdge = SpriteUtilCheckVerticalCollisionAtPosition(yPosition + 0x4, xPosition);
            if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
                gCurrentSprite.yPosition = topEdge - 0x18;
        }
    }

    // Check should change direction or not
    yPosition = gCurrentSprite.yPosition + 0x18;
    if (gPreviousVerticalCollisionCheck == COLLISION_AIR || (gPreviousVerticalCollisionCheck & 0xF0))
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        {
            SpriteUtilCheckCollisionAtPosition(yPosition, xPosition - 0x18);
            if (gPreviousCollisionCheck == COLLISION_AIR)
            {
                SpriteUtilCheckCollisionAtPosition(yPosition, xPosition + 0x18);
                if (gPreviousCollisionCheck == COLLISION_AIR)
                {
                    gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                    gCurrentSprite.pose = VIOLA_POSE_MOVE_DOWN;
                }
                else
                    gCurrentSprite.xPosition += velocity;
            }
            else
            {
                SpriteUtilCheckCollisionAtPosition(yPosition - 0x4, xPosition + 0x18);
                if (gPreviousCollisionCheck == COLLISION_SOLID)
                {
                    gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                    gCurrentSprite.pose = VIOLA_POSE_MOVE_UP;
                }
                else
                    gCurrentSprite.xPosition += velocity;
            }
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(yPosition, xPosition + 0x14);
            if (gPreviousCollisionCheck == COLLISION_AIR)
            {
                SpriteUtilCheckCollisionAtPosition(yPosition, xPosition - 0x1C);
                if (gPreviousCollisionCheck == COLLISION_AIR)
                {
                    gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                    gCurrentSprite.pose = VIOLA_POSE_MOVE_UP;
                }
                else
                    gCurrentSprite.xPosition -= velocity;
            }
            else
            {
                SpriteUtilCheckCollisionAtPosition(yPosition - 0x4, xPosition - 0x1C);
                if (gPreviousCollisionCheck == COLLISION_SOLID)
                {
                    gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                    gCurrentSprite.pose = VIOLA_POSE_MOVE_DOWN;
                }
                else
                    gCurrentSprite.xPosition -= velocity;
            }
        }
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            gCurrentSprite.xPosition += velocity;
        else
            gCurrentSprite.xPosition -= velocity;
    }
}

/**
 * @brief 37704 | 148 | Handles the viola moving left
 * 
 */
void ViolaMoveLeft(void)
{
    u16 velocity;
    u16 yPosition;
    u16 xPosition;
    u32 blockY;

    blockY = gCurrentSprite.yPosition &= 0xFFC0;
    gCurrentSprite.yPosition += 0x18;

    velocity = gCurrentSprite.workVariable2;
    yPosition = blockY - 0x4;
    xPosition = gCurrentSprite.xPosition;

    // Check should fall
    SpriteUtilCheckCollisionAtPosition(yPosition, xPosition + 0x1C);
    if (gPreviousCollisionCheck == COLLISION_AIR)
    {
        SpriteUtilCheckCollisionAtPosition(yPosition, xPosition - 0x20);
        if (gPreviousCollisionCheck == COLLISION_AIR)
        {
            gCurrentSprite.pose = VIOLA_POSE_FALLING_INIT;
            return;
        }
    }

    // Check should change direction or not
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        SpriteUtilCheckCollisionAtPosition(yPosition, xPosition - 0x18);
        if (!(gPreviousCollisionCheck & 0xF))
        {
            SpriteUtilCheckCollisionAtPosition(yPosition, xPosition + 0x18);
            if (gPreviousCollisionCheck == COLLISION_AIR)
            {
                gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.pose = VIOLA_POSE_MOVE_DOWN;
            }
            else
                gCurrentSprite.xPosition += velocity;
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(yPosition + 0x4, xPosition + 0x18);
            if (gPreviousCollisionCheck == COLLISION_SOLID)
            {
                gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.pose = VIOLA_POSE_MOVE_UP;
            }
            else
                gCurrentSprite.xPosition += velocity;
        }
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(yPosition, xPosition + 0x14);
        if (!(gPreviousCollisionCheck & 0xF))
        {
            SpriteUtilCheckCollisionAtPosition(yPosition, xPosition - 0x1C);
            if (gPreviousCollisionCheck == COLLISION_AIR)
            {
                gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.pose = VIOLA_POSE_MOVE_UP;
            }
            else
                gCurrentSprite.xPosition -= velocity;
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(yPosition + 0x4, xPosition - 0x1C);
            if (gPreviousCollisionCheck == COLLISION_SOLID)
            {
                gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.pose = VIOLA_POSE_MOVE_DOWN;
            }
            else
                gCurrentSprite.xPosition -= velocity;
        }
    }
}

/**
 * @brief 3784c | 148 | Handles a viola moving down
 * 
 */
void ViolaMoveDown(void)
{
    u16 velocity;
    u16 yPosition;
    u16 xPosition;
    u32 blockX;

    blockX = gCurrentSprite.xPosition &= 0xFFC0;
    gCurrentSprite.xPosition += 0x18;

    velocity = gCurrentSprite.workVariable2;
    yPosition = gCurrentSprite.yPosition;
    xPosition = blockX - 0x4;

    // Check should fall
    SpriteUtilCheckCollisionAtPosition(yPosition + 0x1C, xPosition);
    if (gPreviousCollisionCheck == COLLISION_AIR)
    {
        SpriteUtilCheckCollisionAtPosition(yPosition - 0x20, xPosition);
        if (gPreviousCollisionCheck == COLLISION_AIR)
        {
            gCurrentSprite.pose = VIOLA_POSE_FALLING_INIT;
            return;
        }
    }

    // Check should change direction or not
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        SpriteUtilCheckCollisionAtPosition(yPosition - 0x18, xPosition);
        if (!(gPreviousCollisionCheck & 0xF0))
        {
            SpriteUtilCheckCollisionAtPosition(yPosition + 0x18, xPosition);
            if (gPreviousCollisionCheck == COLLISION_AIR)
            {
                gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.pose = VIOLA_POSE_MOVE_LEFT;
            }
            else
                gCurrentSprite.yPosition += velocity;
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(yPosition + 0x18, xPosition + 0x4);
            if (gPreviousCollisionCheck == COLLISION_SOLID)
            {
                gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.pose = VIOLA_POSE_MOVE_RIGHT;
            }
            else
                gCurrentSprite.yPosition += velocity;
        }
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(yPosition + 0x14, xPosition);
        if (!(gPreviousCollisionCheck & 0xF0))
        {
            SpriteUtilCheckCollisionAtPosition(yPosition - 0x1C, xPosition);
            if (gPreviousCollisionCheck == COLLISION_AIR)
            {
                gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.pose = VIOLA_POSE_MOVE_RIGHT;
            }
            else
                gCurrentSprite.yPosition -= velocity;
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(yPosition - 0x1C, xPosition + 0x4);
            if (gPreviousCollisionCheck == COLLISION_SOLID)
            {
                gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.pose = VIOLA_POSE_MOVE_LEFT;
            }
            else
                gCurrentSprite.yPosition -= velocity;
        }
    }
}

/**
 * @brief 37994 | 14c | Handles the viola moving up
 * 
 */
void ViolaMoveUp(void)
{
    u16 velocity;
    u16 yPosition;
    u16 xPosition;
    u32 blockX;

    blockX = gCurrentSprite.xPosition &= 0xFFC0;
    gCurrentSprite.xPosition += 0x28;

    velocity = gCurrentSprite.workVariable2;
    yPosition = gCurrentSprite.yPosition;
    xPosition = blockX + BLOCK_SIZE;

    // Check should fall
    SpriteUtilCheckCollisionAtPosition(yPosition + 0x1C, xPosition);
    if (gPreviousCollisionCheck == COLLISION_AIR)
    {
        SpriteUtilCheckCollisionAtPosition(yPosition - 0x20, xPosition);
        if (gPreviousCollisionCheck == COLLISION_AIR)
        {
            gCurrentSprite.pose = VIOLA_POSE_FALLING_INIT;
            return;
        }
    }

    // Check should change direction or not
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        SpriteUtilCheckCollisionAtPosition(yPosition - 0x18, xPosition);
        if (!(gPreviousCollisionCheck & 0xF0))
        {
            SpriteUtilCheckCollisionAtPosition(yPosition + 0x18, xPosition);
            if (gPreviousCollisionCheck == COLLISION_AIR)
            {
                gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.pose = VIOLA_POSE_MOVE_LEFT;
            }
            else
                gCurrentSprite.yPosition += velocity;
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(yPosition + 0x18, xPosition - 0x4);
            if (gPreviousCollisionCheck == COLLISION_SOLID)
            {
                gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.pose = VIOLA_POSE_MOVE_RIGHT;
            }
            else
                gCurrentSprite.yPosition += velocity;
        }
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(yPosition + 0x14, xPosition);
        if (!(gPreviousCollisionCheck & 0xF0))
        {
            SpriteUtilCheckCollisionAtPosition(yPosition - 0x1C, xPosition);
            if (gPreviousCollisionCheck == COLLISION_AIR)
            {
                gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.pose = VIOLA_POSE_MOVE_RIGHT;
            }
            else
                gCurrentSprite.yPosition -= velocity;
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(yPosition - 0x1C, xPosition - 0x4);
            if (gPreviousCollisionCheck == COLLISION_SOLID)
            {
                gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.pose = VIOLA_POSE_MOVE_LEFT;
            }
            else
                gCurrentSprite.yPosition -= velocity;
        }
    }
}

/**
 * @brief 37ae0 | 18 | Initializes a viola to be falling
 * 
 */
void ViolaFallingInit(void)
{
    gCurrentSprite.pose = VIOLA_POSE_FALLING;
    gCurrentSprite.arrayOffset = 0x0;
}

/**
 * @brief 37af8 | 78 | Handles a viola falling
 * 
 */
void ViolaFalling(void)
{
    u8 offset;
    i32 movement;
    u32 topEdge;

    topEdge = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition + 0x18, gCurrentSprite.xPosition);
    if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
    {
        gCurrentSprite.yPosition = topEdge - 0x18;
        gCurrentSprite.pose = VIOLA_POSE_MOVE_RIGHT;
        SpriteUtilChooseRandomXDirection();
    }
    else
    {
        offset = gCurrentSprite.arrayOffset;
        movement = sSpritesFallingSpeed[offset];
        if (movement == SPRITE_ARRAY_TERMINATOR)
        {
            movement = sSpritesFallingSpeed[offset - 1];
            gCurrentSprite.yPosition += movement;
        }
        else
        {
            gCurrentSprite.arrayOffset = offset + 0x1;
            gCurrentSprite.yPosition += movement;
        }
    }
}

/**
 * @brief 37b70 | 14c | Viola AI
 * 
 */
void Viola(void)
{
    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(0x178);
    }

    if (gCurrentSprite.freezeTimer != 0x0)
        SpriteUtilUpdateFreezeTimer();
    else
    {
        if (SpriteUtilIsSpriteStunned())
            return;

        switch (gCurrentSprite.pose)
        {
            case 0x0:
                ViolaInit();
                break;

            case VIOLA_POSE_MOVE_RIGHT:
                ViolaMoveRight();
                break;

            case VIOLA_POSE_MOVE_LEFT:
                ViolaMoveLeft();
                break;

            case VIOLA_POSE_MOVE_DOWN:
                ViolaMoveDown();
                break;

            case VIOLA_POSE_MOVE_UP:
                ViolaMoveUp();
                break;

            case VIOLA_POSE_FALLING_INIT:
                ViolaFallingInit();

            case VIOLA_POSE_FALLING:
                ViolaFalling();
                break;

            default:
                SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
        }
    }
}