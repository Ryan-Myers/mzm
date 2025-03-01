#include "rinka.h"
#include "zebetite_and_cannon.h"
#include "../syscalls.h"
#include "../../data/data.h"
#include "../globals.h"

const u32 sRinkaOrangeGFX[242];
const u16 sRinkaOrangePAL[16];
const u32 sRinkaGreenGFX[242];
const u16 sRinkaGreenPAL[16];

const u16 sRinkaOrangeOAM_Moving_Frame0[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200
};

const u16 sRinkaOrangeOAM_Moving_Frame1[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202
};

const u16 sRinkaOrangeOAM_Moving_Frame2[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204
};

const u16 sRinkaOrangeOAM_Spawning_Frame0[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20b
};

const u16 sRinkaOrangeOAM_Spawning_Frame1[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20d
};

const u16 sRinkaOrangeOAM_Spawning_Frame2[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20f
};

const u16 sRinkaOrangeOAM_Spawning_Frame3[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x211
};

const u16 sRinkaOrangeOAM_Spawning_Frame4[10] = {
    0x3,
    0xf7, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_VERTICAL | 0xf7, 0x7, OBJ_SPRITE_OAM | 0x215,
    OBJ_SHAPE_HORIZONTAL | 0x7, 0x1f7, OBJ_SPRITE_OAM | 0x233
};

const u16 sRinkaOrangeOAM_Spawning_Frame5[10] = {
    0x3,
    0xf7, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_VERTICAL | 0xf7, 0x7, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0x7, 0x1f7, OBJ_SPRITE_OAM | 0x213
};

const struct FrameData sRinkaOrangeOAM_Spawning[16] = {
    sRinkaOrangeOAM_Spawning_Frame0,
    0x4,
    sRinkaOrangeOAM_Spawning_Frame1,
    0x4,
    sRinkaOrangeOAM_Spawning_Frame2,
    0x4,
    sRinkaOrangeOAM_Spawning_Frame3,
    0x4,
    sRinkaOrangeOAM_Spawning_Frame4,
    0x4,
    sRinkaOrangeOAM_Spawning_Frame5,
    0x4,
    sRinkaOrangeOAM_Spawning_Frame3,
    0x8,
    sRinkaOrangeOAM_Moving_Frame0,
    0x6,
    sRinkaOrangeOAM_Moving_Frame1,
    0x6,
    sRinkaOrangeOAM_Moving_Frame2,
    0x6,
    sRinkaOrangeOAM_Moving_Frame1,
    0x8,
    sRinkaOrangeOAM_Moving_Frame0,
    0x7,
    sRinkaOrangeOAM_Moving_Frame1,
    0x7,
    sRinkaOrangeOAM_Moving_Frame2,
    0x7,
    sRinkaOrangeOAM_Moving_Frame1,
    0x7,
    NULL,
    0x0
};

const struct FrameData sRinkaOrangeOAM_Moving[5] = {
    sRinkaOrangeOAM_Moving_Frame0,
    0xC,
    sRinkaOrangeOAM_Moving_Frame1,
    0xC,
    sRinkaOrangeOAM_Moving_Frame2,
    0xC,
    sRinkaOrangeOAM_Moving_Frame1,
    0xC,
    NULL,
    0x0
};


const u16 sRinkaGreenOAM_Moving_Frame0[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200
};

const u16 sRinkaGreenOAM_Moving_Frame1[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202
};

const u16 sRinkaGreenOAM_Moving_Frame2[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204
};

const u16 sRinkaGreenOAM_Spawning_Frame0[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20b
};

const u16 sRinkaGreenOAM_Spawning_Frame1[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20d
};

const u16 sRinkaGreenOAM_Spawning_Frame2[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20f
};

const u16 sRinkaGreenOAM_Spawning_Frame3[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x211
};

const u16 sRinkaGreenOAM_Spawning_Frame4[10] = {
    0x3,
    0xf7, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_VERTICAL | 0xf7, 0x7, OBJ_SPRITE_OAM | 0x215,
    OBJ_SHAPE_HORIZONTAL | 0x7, 0x1f7, OBJ_SPRITE_OAM | 0x233
};

const u16 sRinkaGreenOAM_Spawning_Frame5[10] = {
    0x3,
    0xf7, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_VERTICAL | 0xf7, 0x7, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0x7, 0x1f7, OBJ_SPRITE_OAM | 0x213
};

const struct FrameData sRinkaGreenOAM_Spawning[16] = {
    sRinkaGreenOAM_Spawning_Frame0,
    0x2,
    sRinkaGreenOAM_Spawning_Frame1,
    0x2,
    sRinkaGreenOAM_Spawning_Frame2,
    0x2,
    sRinkaGreenOAM_Spawning_Frame3,
    0x2,
    sRinkaGreenOAM_Spawning_Frame4,
    0x2,
    sRinkaGreenOAM_Spawning_Frame5,
    0x2,
    sRinkaGreenOAM_Spawning_Frame3,
    0x5,
    sRinkaGreenOAM_Moving_Frame0,
    0x3,
    sRinkaGreenOAM_Moving_Frame1,
    0x3,
    sRinkaGreenOAM_Moving_Frame2,
    0x3,
    sRinkaGreenOAM_Moving_Frame1,
    0x3,
    sRinkaGreenOAM_Moving_Frame0,
    0x4,
    sRinkaGreenOAM_Moving_Frame1,
    0x4,
    sRinkaGreenOAM_Moving_Frame2,
    0x4,
    sRinkaGreenOAM_Moving_Frame1,
    0x4,
    NULL,
    0x0
};

const struct FrameData sRinkaGreenOAM_Moving[5] = {
    sRinkaGreenOAM_Moving_Frame0,
    0x8,
    sRinkaGreenOAM_Moving_Frame1,
    0x8,
    sRinkaGreenOAM_Moving_Frame2,
    0x8,
    sRinkaGreenOAM_Moving_Frame1,
    0x8,
    NULL,
    0x0
};

/**
 * @brief 3630c | 98 | Initializes a rinka sprite
 * 
 */
void RinkaInit(void)
{
    gCurrentSprite.hitboxTopOffset = -0x14;
    gCurrentSprite.hitboxBottomOffset = 0x14;
    gCurrentSprite.hitboxLeftOffset = -0x14;
    gCurrentSprite.hitboxRightOffset = 0x14;

    gCurrentSprite.drawDistanceTopOffset = 0x8;
    gCurrentSprite.drawDistanceBottomOffset = 0x8;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x8;

    gCurrentSprite.health = sPrimarySpriteStats[gCurrentSprite.spriteID][0];
    gCurrentSprite.yPosition -= (BLOCK_SIZE / 2);

    // Get spawn tile position
    gCurrentSprite.arrayOffset = (gCurrentSprite.yPosition - (BLOCK_SIZE / 2)) >> 6;
    gCurrentSprite.workVariable2 = (gCurrentSprite.xPosition - (BLOCK_SIZE / 2)) >> 6;

    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.drawOrder = 0x3;
    gCurrentSprite.bgPriority = gIORegistersBackup.BG1CNT & 0x3;
    gCurrentSprite.workVariable = 0x0;

    if (gCurrentSprite.spriteID != PSPRITE_RINKA_GREEN && gCurrentSprite.spriteID != PSPRITE_RINKA_ORANGE)
        gCurrentSprite.frozenPaletteRowOffset = 0x1;
}

/**
 * @brief 363a4 | 3c | Initializes a rinka to be spawning
 * 
 */
void RinkaSpawningInit(void)
{
    gCurrentSprite.pose = RINKA_POSE_SPAWNING;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.animationDurationCounter = 0x0;

    if (gCurrentSprite.spriteID == PSPRITE_RINKA_GREEN)
    {
        gCurrentSprite.status |= SPRITE_STATUS_MOSAIC;
        gCurrentSprite.pOam = sRinkaGreenOAM_Spawning;
    }
    else
        gCurrentSprite.pOam = sRinkaOrangeOAM_Spawning;
}

/**
 * @brief 363e0 | 94 | Handles a rinka respawning
 * 
 */
void RinkaRespawn(void)
{
    // Set spawn position
    gCurrentSprite.yPosition = (gCurrentSprite.arrayOffset * BLOCK_SIZE) + (BLOCK_SIZE / 2);
    gCurrentSprite.xPosition = (gCurrentSprite.workVariable2 * BLOCK_SIZE) + (BLOCK_SIZE / 2);

    RinkaSpawningInit();
    gCurrentSprite.health = sPrimarySpriteStats[gCurrentSprite.spriteID][0];
    gCurrentSprite.invicibilityStunFlashTimer = 0x0;
    gCurrentSprite.paletteRow = 0x0;
    gCurrentSprite.frozenPaletteRowOffset = 0x0;
    gCurrentSprite.absolutePaletteRow = 0x0;

    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    gCurrentSprite.freezeTimer = 0x0;

    // Set spawn delay
    if (gCurrentSprite.status & SPRITE_STATUS_MOSAIC)
        gCurrentSprite.workVariable = 0x14; // Green rinka
    else
        gCurrentSprite.workVariable = 0x3C; // Orange rinka

    gCurrentSprite.status |= (SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_IGNORE_PROJECTILES);
    // Duplicated code
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
}

/**
 * @brief 36474 | 118 | Handles a rinka spawning
 * 
 */
void RinkaSpawning(void)
{
    u16 samusY;
    u16 samusX;
    u16 spriteY;
    u16 spriteX;

    // Spawn delay
    if (gCurrentSprite.workVariable != 0x0)
    {
        gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
        gCurrentSprite.workVariable--;
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_NOT_DRAWN)
        {
            gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
            if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            {
                gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
                gCurrentSprite.currentAnimationFrame = 0x0;
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.timer = 0xB;
            }
        }
        else
        {
            // Vulnerability delay
            if (gCurrentSprite.timer != 0x0)
            {
                gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
                gCurrentSprite.timer--;
                if (gCurrentSprite.timer == 0x0)
                    gCurrentSprite.status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;
            }
            else if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                if (gCurrentSprite.spriteID == PSPRITE_RINKA_GREEN)
                    gCurrentSprite.pOam = sRinkaGreenOAM_Moving;
                else
                    gCurrentSprite.pOam = sRinkaOrangeOAM_Moving;

                gCurrentSprite.pose = RINKA_POSE_MOVING;
                gCurrentSprite.currentAnimationFrame = 0x0;
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.oamScaling = 0x0;

                samusY = gSamusData.yPosition - 0x3C;
                samusX = gSamusData.xPosition;
                spriteY = gCurrentSprite.yPosition;
                spriteX = gCurrentSprite.xPosition;

                // Set destination position
                gCurrentSprite.yPositionSpawn = samusY;
                gCurrentSprite.xPositionSpawn = samusX;

                // Set direction
                if (samusY < spriteY)
                    gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN2;
                else
                    gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;

                    
                if (samusX < spriteX)
                    gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                else
                    gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
            }
        }
    }
}

/**
 * @brief 3658c | 234 | Handles a rinka moving
 * 
 */
void RinkaMove(void)
{
    u16 velocity;
    u32 spawnY;
    u32 spawnX;
    u8 respawn;
    u16 distanceYDown;
    u16 distanceYUp;
    u16 distanceXLeft;
    u16 distanceXRight;
    i32 totalDistance;
    u16 samusY;
    u16 spriteY;
    u16 acceleration;

    respawn = FALSE;
    if (gCurrentSprite.status & SPRITE_STATUS_MOSAIC)
        velocity = 0x5;
    else
        velocity = 0x4;

    acceleration = ++gCurrentSprite.oamScaling;
    velocity *= (acceleration);

    spawnY = gCurrentSprite.arrayOffset * BLOCK_SIZE + (BLOCK_SIZE / 2);
    spawnX = gCurrentSprite.workVariable2 * BLOCK_SIZE + (BLOCK_SIZE / 2);

    if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
        distanceYUp = gCurrentSprite.yPositionSpawn - spawnY;
    else
        distanceYDown = spawnY - gCurrentSprite.yPositionSpawn;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        distanceXRight = gCurrentSprite.xPositionSpawn - spawnX;
    else
        distanceXLeft = spawnX - gCurrentSprite.xPositionSpawn;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
        {
            totalDistance = (u16)(u16)Sqrt(distanceXRight * distanceXRight + distanceYUp * distanceYUp);
            if (totalDistance != 0x0)
            {
                gCurrentSprite.yPosition = spawnY + ((velocity * ((i32)(distanceYUp << 0xA) / totalDistance) >> 0xA));
                gCurrentSprite.xPosition = spawnX + ((velocity * ((i32)(distanceXRight << 0xA) / totalDistance) >> 0xA));
            }
        }
        else
        {
            totalDistance = (u16)Sqrt(distanceXRight * distanceXRight + distanceYDown * distanceYDown);
            if (totalDistance != 0x0)
            {
                gCurrentSprite.yPosition = spawnY - ((velocity * ((i32)(distanceYDown << 0xA) / totalDistance) >> 0xA));
                gCurrentSprite.xPosition = spawnX + ((velocity * ((i32)(distanceXRight << 0xA) / totalDistance) >> 0xA));
            }
        }
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
        {
            totalDistance = (u16)Sqrt(distanceXLeft * distanceXLeft + distanceYUp * distanceYUp);
            if (totalDistance != 0x0)
            {
                gCurrentSprite.yPosition = spawnY + ((velocity * ((i32)(distanceYUp << 0xA) / totalDistance) >> 0xA));
                gCurrentSprite.xPosition = spawnX - ((velocity * ((i32)(distanceXLeft << 0xA) / totalDistance) >> 0xA));
            }
        }
        else
        {
            totalDistance = (u16)Sqrt(distanceXLeft * distanceXLeft + distanceYDown * distanceYDown);
            if (totalDistance != 0x0)
            {
                gCurrentSprite.yPosition = spawnY - ((velocity * ((i32)(distanceYDown << 0xA) / totalDistance) >> 0xA));
                gCurrentSprite.xPosition = spawnX - ((velocity * ((i32)(distanceXLeft << 0xA) / totalDistance) >> 0xA));
            }
        }
    }

    if (!(gCurrentSprite.xPosition & 0x8000))
    {
        if (gCurrentSprite.xPosition > gSamusData.xPosition)
        {
            if ((gCurrentSprite.xPosition - gSamusData.xPosition) > 0x400)
                respawn++;
        }
        else
        {
            if ((gSamusData.xPosition - gCurrentSprite.xPosition) > 0x400)
                respawn++;
        }
    }
    else
        respawn++;

    if (!(gCurrentSprite.yPosition & 0x8000))
    {
        if (gCurrentSprite.yPosition > gSamusData.yPosition)
        {
            if ((gCurrentSprite.yPosition - gSamusData.yPosition) > 0x400)
                respawn++;
        }
        else
        {
            if ((gSamusData.yPosition - gCurrentSprite.yPosition) > 0x400)
                respawn++;
        }
    }
    else
        respawn++;

    if (respawn)
        RinkaRespawn();
}

/**
 * @brief 367c0 | 20 | Initializes a rinka mother brain to be spawning
 * 
 */
void RinkaMotherBrainSpawningInit(void)
{
    gCurrentSprite.pose = RINKA_POSE_SPAWNING;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.pOam = sRinkaMotherBrainOAM_Spawning;
}

/**
 * @brief 367e0 | 184 | Handles a rinka mother brain respawning
 * 
 */
void RinkaMotherBrainRespawn(void)
{
    u16 spriteY;
    u16 spriteX;
    u16 samusX;
    i32 offset;
    u8* pSprite;

    spriteY = gCurrentSprite.arrayOffset * BLOCK_SIZE + (BLOCK_SIZE / 2);
    spriteX = gCurrentSprite.workVariable2 * BLOCK_SIZE + (BLOCK_SIZE / 2);
    samusX = gSamusData.xPosition;

    // Check should be first or second place
    switch (gCurrentSprite.spriteID)
    {
        case PSPRITE_RINKA_MOTHER_BRAIN2:
            offset = 0x28;
            if (samusX < spriteX && (i32)(spriteX - samusX) > (offset * (BLOCK_SIZE / 2)))
            {
                gCurrentSprite.status |= SPRITE_STATUS_SAMUS_COLLIDING;
                spriteY += BLOCK_SIZE;
                spriteX -= (BLOCK_SIZE * 40);
            }
            else
                gCurrentSprite.status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
            break;

        case PSPRITE_RINKA_MOTHER_BRAIN3:
            offset = 0x22;
            if (samusX < spriteX && (i32)(spriteX - samusX) > (offset * (BLOCK_SIZE / 2)))
            {
                gCurrentSprite.status |= SPRITE_STATUS_SAMUS_COLLIDING;
                spriteY -= BLOCK_SIZE;
                spriteX -= (BLOCK_SIZE * 34);
            }
            else
                gCurrentSprite.status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
            break;

        case PSPRITE_RINKA_MOTHER_BRAIN4:
            offset = 0x18;
            if (samusX < spriteX && (i32)(spriteX - samusX) > (offset * (BLOCK_SIZE / 2)))
            {
                gCurrentSprite.status |= SPRITE_STATUS_SAMUS_COLLIDING;
                spriteX -= (BLOCK_SIZE * 24);
            }
            else
                gCurrentSprite.status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
            break;

        case PSPRITE_RINKA_MOTHER_BRAIN5:
            offset = 0x1E;
            if (samusX < spriteX && (i32)(spriteX - samusX) > (offset * (BLOCK_SIZE / 2)))
            {
                gCurrentSprite.status |= SPRITE_STATUS_SAMUS_COLLIDING;
                spriteX -= (BLOCK_SIZE * 30);
            }
            else
                gCurrentSprite.status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
            break;

        case PSPRITE_RINKA_MOTHER_BRAIN6:
            offset = 0x14;
            if (samusX < spriteX && (i32)(spriteX - samusX) > (offset * (BLOCK_SIZE / 2)))
            {
                gCurrentSprite.status |= SPRITE_STATUS_SAMUS_COLLIDING;
                spriteX -= (BLOCK_SIZE * 20);
            }
            else
                gCurrentSprite.status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
            break;
    }

    gCurrentSprite.yPosition = spriteY;
    gCurrentSprite.xPosition = spriteX;
    RinkaMotherBrainSpawningInit();
    gCurrentSprite.health = sPrimarySpriteStats[gCurrentSprite.spriteID][0];
    gCurrentSprite.invicibilityStunFlashTimer = 0x0;
    gCurrentSprite.paletteRow = 0x0;
    gCurrentSprite.frozenPaletteRowOffset = 0x1;
    gCurrentSprite.absolutePaletteRow = 0x0;
    pSprite = &gCurrentSprite.ignoreSamusCollisionTimer;
    gCurrentSprite.freezeTimer = 0x0;
    gCurrentSprite.workVariable = 0x3C;
    gCurrentSprite.status |= (SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_IGNORE_PROJECTILES);
    *pSprite = 0x1;
}

/**
 * @brief 36964 | 110 | Handles a rinka mother brain spawning
 * 
 */
void RinkaMotherBrainSpawning(void)
{
    u16 samusY;
    u16 samusX;
    u16 spriteY;
    u16 spriteX;

    // Spawn delay
    if (gCurrentSprite.workVariable != 0x0)
    {
        gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
        gCurrentSprite.workVariable--;
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_NOT_DRAWN)
        {
            gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
            if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            {
                gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
                gCurrentSprite.currentAnimationFrame = 0x0;
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.timer = 0xB;
            }
            else
                RinkaMotherBrainRespawn();
        }
        else
        {
            // Vulnerability delay
            if (gCurrentSprite.timer != 0x0)
            {
                gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
                gCurrentSprite.timer--;
                if (gCurrentSprite.timer == 0x0)
                    gCurrentSprite.status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;
            }
            else if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                gCurrentSprite.pOam = sRinkaMotherBrainOAM_Moving;

                gCurrentSprite.pose = RINKA_POSE_MOVING;
                gCurrentSprite.currentAnimationFrame = 0x0;
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.oamScaling = 0x0;

                samusY = gSamusData.yPosition - 0x3C;
                samusX = gSamusData.xPosition;
                spriteY = gCurrentSprite.yPosition;
                spriteX = gCurrentSprite.xPosition;

                // Set destination position
                gCurrentSprite.yPositionSpawn = samusY;
                gCurrentSprite.xPositionSpawn = samusX;

                // Set direction
                if (samusY < spriteY)
                    gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN2;
                else
                    gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;

                    
                if (samusX < spriteX)
                    gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                else
                    gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
            }
        }
    }
}

/**
 * @brief 36a74 | 2c0 | Handles the movement of a rinka mother brain
 * 
 */
void RinkaMotherBrainMove(void)
{
    u16 velocity;
    u8 tileY;
    u8 tileX;
    u16 spawnY;
    u16 spawnX;
    u16 distanceYDown;
    u16 distanceYUp;
    u16 distanceXLeft;
    u16 distanceXRight;
    u8 respawn;
    i32 totalDistance;
    u16 samusY;
    u16 spriteY;
    u16 acceleration;

    respawn = FALSE;

    acceleration = ++gCurrentSprite.oamScaling;
    velocity = acceleration * 4;

    tileX = gCurrentSprite.workVariable2;
    tileY = gCurrentSprite.arrayOffset;

    // Check spawn at second place
    switch (gCurrentSprite.spriteID)
    {
        case PSPRITE_RINKA_MOTHER_BRAIN2:
            if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
            {
                tileX -= 0x28;
                tileY += 0x1;
            }
            break;

        case PSPRITE_RINKA_MOTHER_BRAIN3:
            if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
            {
                tileX -= 0x22;
                tileY -= 0x1;
            }
            break;

        case PSPRITE_RINKA_MOTHER_BRAIN4:
            if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
                tileX -= 0x18;
            break;

        case PSPRITE_RINKA_MOTHER_BRAIN5:
            if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
                tileX -= 0x1E;
            break;

        case PSPRITE_RINKA_MOTHER_BRAIN6:
            if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
                tileX -= 0x14;
            break;
    }

    spawnY = tileY * BLOCK_SIZE + (BLOCK_SIZE / 2);
    spawnX = tileX * BLOCK_SIZE + (BLOCK_SIZE / 2);

    if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
        distanceYUp = gCurrentSprite.yPositionSpawn - spawnY;
    else
        distanceYDown = spawnY - gCurrentSprite.yPositionSpawn;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        distanceXRight = gCurrentSprite.xPositionSpawn - spawnX;
    else
        distanceXLeft = spawnX - gCurrentSprite.xPositionSpawn;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
        {
            totalDistance = (u16)Sqrt(distanceXRight * distanceXRight + distanceYUp * distanceYUp);
            if (totalDistance != 0x0)
            {
                gCurrentSprite.yPosition = spawnY + ((velocity * ((i32)(distanceYUp << 0xA) / totalDistance) >> 0xA));
                gCurrentSprite.xPosition = spawnX + ((velocity * ((i32)(distanceXRight << 0xA) / totalDistance) >> 0xA));
            }
        }
        else
        {
            totalDistance = (u16)Sqrt(distanceXRight * distanceXRight + distanceYDown * distanceYDown);
            if (totalDistance != 0x0)
            {
                gCurrentSprite.yPosition = spawnY - ((velocity * ((i32)(distanceYDown << 0xA) / totalDistance) >> 0xA));
                gCurrentSprite.xPosition = spawnX + ((velocity * ((i32)(distanceXRight << 0xA) / totalDistance) >> 0xA));
            }
        }
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
        {
            totalDistance = (u16)Sqrt(distanceXLeft * distanceXLeft + distanceYUp * distanceYUp);
            if (totalDistance != 0x0)
            {
                gCurrentSprite.yPosition = spawnY + ((velocity * ((i32)(distanceYUp << 0xA) / totalDistance) >> 0xA));
                gCurrentSprite.xPosition = spawnX - ((velocity * ((i32)(distanceXLeft << 0xA) / totalDistance) >> 0xA));
            }
        }
        else
        {
            totalDistance = (u16)Sqrt(distanceXLeft * distanceXLeft + distanceYDown * distanceYDown);
            if (totalDistance != 0x0)
            {
                gCurrentSprite.yPosition = spawnY - ((velocity * ((i32)(distanceYDown << 0xA) / totalDistance) >> 0xA));
                gCurrentSprite.xPosition = spawnX - ((velocity * ((i32)(distanceXLeft << 0xA) / totalDistance) >> 0xA));
            }
        }
    }

    if (!(gCurrentSprite.xPosition & 0x8000))
    {
        if (gCurrentSprite.xPosition > gSamusData.xPosition)
        {
            if ((gCurrentSprite.xPosition - gSamusData.xPosition) > 0x400)
                respawn++;
        }
        else
        {
            if ((gSamusData.xPosition - gCurrentSprite.xPosition) > 0x400)
                respawn++;
        }
    }
    else
        respawn++;

    if (!(gCurrentSprite.yPosition & 0x8000))
    {
        if (gCurrentSprite.yPosition > gSamusData.yPosition)
        {
            if ((gCurrentSprite.yPosition - gSamusData.yPosition) > 0x400)
                respawn++;
        }
        else
        {
            if ((gSamusData.yPosition - gCurrentSprite.yPosition) > 0x400)
                respawn++;
        }
    }
    else
        respawn++;

    if (respawn)
        RinkaRespawn();
}

/**
 * @brief 36d34 | 9c | Rinka AI
 * 
 */
void Rinka(void)
{
    if (gCurrentSprite.freezeTimer != 0x0)
        SpriteUtilUpdateFreezeTimer();
    else
    {
        if (SpriteUtilIsSpriteStunned())
            return;

        switch (gCurrentSprite.pose)
        {
            case 0x0:
                RinkaInit();
                
            case RINKA_POSE_SPAWNING_INIT:
                RinkaSpawningInit();

            case RINKA_POSE_SPAWNING:
                rinkamother();
                break;

            case RINKA_POSE_MOVING:
                RinkaMove();
                break;

            default:
                if (SpriteUtilCheckHasDrops())
                {
                    SpriteUtilSpriteDeath(DEATH_NO_DEATH_OR_RESPAWNING_ALREADY_HAS_DROP, gCurrentSprite.yPosition,
                        gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
                }
                else
                {
                    SpriteUtilSpriteDeath(DEATH_RESPAWNING, gCurrentSprite.yPosition, gCurrentSprite.xPosition,
                        TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
                }
                RinkaRespawn();
        }
    }
}

/**
 * @brief 36dd0 | f4 | Rinka mother brain AI
 * 
 */
void RinkaMotherBrain(void)
{
    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_MOTHER_BRAIN_KILLED))
    {
        // Kill if mother brain is dead
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        {
            if (!(gCurrentSprite.status & SPRITE_STATUS_NOT_DRAWN))
                ParticleSet(gCurrentSprite.yPosition, gCurrentSprite.xPosition, PE_SPRITE_EXPLOSION_SMALL);
        }

        if (gCurrentSprite.standingOnSprite && gSamusData.standingStatus == STANDING_ENEMY)
        {
            gSamusData.standingStatus = STANDING_MIDAIR;
            gCurrentSprite.standingOnSprite = FALSE;
        }

        gCurrentSprite.status = 0x0;
    }
    else
    {
        if (gCurrentSprite.freezeTimer != 0x0)
            SpriteUtilUpdateFreezeTimer();
        else
        {
            if (SpriteUtilIsSpriteStunned())
                return;

            switch (gCurrentSprite.pose)
            {
                case 0x0:
                    RinkaInit();
                    
                case RINKA_POSE_SPAWNING_INIT:
                    RinkaMotherBrainSpawningInit();

                case RINKA_POSE_SPAWNING:
                    RinkaMotherBrainSpawning();
                    break;

                case RINKA_POSE_MOVING:
                    RinkaMotherBrainMove();
                    break;

                default:
                    if (SpriteUtilCheckHasDrops())
                    {
                        SpriteUtilSpriteDeath(DEATH_NO_DEATH_OR_RESPAWNING_ALREADY_HAS_DROP, gCurrentSprite.yPosition,
                            gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
                    }
                    else
                    {
                        SpriteUtilSpriteDeath(DEATH_RESPAWNING, gCurrentSprite.yPosition, gCurrentSprite.xPosition,
                            TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
                    }
                    RinkaMotherBrainRespawn();
            }
        }
    }
}