#include "unknown_item_block.h"
#include "../../data/data.h"
#include "../globals.h"

const u8 sPlasmaBeamBlockGFX[1224];
const u16 sPlasmaBeamBlockPAL[16];
const u8 sGravityBlockGFX[1212];
const u16 sGravityBlockPAL[16];
const u8 sSpaceJumpBlockGFX[1188];
const u16 sSpaceJumpBlockPAL[16];

const u16 sUnknownItemBlockOAM_Idle_Frame0[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x204
};

const u16 sUnknownItemBlockOAM_Activated_Frame1[25] = {
    0x8,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x208,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x208,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x208,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x208,
    0xf1, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x216,
    OBJ_SHAPE_HORIZONTAL | 0x1, 0x1f8, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x204
};

const u16 sUnknownItemBlockOAM_Activated_Frame2[25] = {
    0x8,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x20a,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x20a,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x20a,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x20a,
    0xf1, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_HORIZONTAL | 0x1, 0x1f8, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x204
};

const u16 sUnknownItemBlockOAM_Activated_Frame3[25] = {
    0x8,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x20c,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x20c,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x20c,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x20c,
    0xf1, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_HORIZONTAL | 0x1, 0x1f8, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x204
};

const u16 sUnknownItemBlockOAM_Exploding_Frame0[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x212
};

const u16 sUnknownItemBlockOAM_Exploding_Frame1[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xef, OBJ_SIZE_32x16 | 0x1ef, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_HORIZONTAL | 0x1, OBJ_SIZE_32x16 | 0x1ef, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_VERTICAL | 0xef, 0x9, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_VERTICAL | 0x1, 0x9, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1ef, OBJ_SPRITE_OAM | 0x212,
    0xfc, 0x9, OBJ_SPRITE_OAM | 0x212
};

const u16 sUnknownItemBlockOAM_Exploding_Frame2[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xee, OBJ_SIZE_32x16 | 0x1ee, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_HORIZONTAL | 0x2, OBJ_SIZE_32x16 | 0x1ee, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_VERTICAL | 0xee, 0xa, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_VERTICAL | 0x2, 0xa, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1ee, OBJ_SPRITE_OAM | 0x212,
    0xfc, 0xa, OBJ_SPRITE_OAM | 0x212
};

const u16 sUnknownItemBlockOAM_Exploding_Frame3[25] = {
    0x8,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_SIZE_32x16 | 0x1ed, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_HORIZONTAL | 0xfd, OBJ_SIZE_32x16 | 0x1ed, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_VERTICAL | 0xf3, 0xb, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_VERTICAL | 0xfd, 0xb, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_HORIZONTAL | 0xed, 0x1f2, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_HORIZONTAL | 0xed, 0x1fe, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_HORIZONTAL | 0xb, 0x1f2, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_HORIZONTAL | 0xb, 0x1fe, OBJ_SPRITE_OAM | 0x212
};

const u16 sUnknownItemBlockOAM_Exploding_Frame4[25] = {
    0x8,
    OBJ_SHAPE_HORIZONTAL | 0xf5, OBJ_SIZE_32x16 | 0x1eb, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_HORIZONTAL | 0xfb, OBJ_SIZE_32x16 | 0x1eb, OBJ_SPRITE_OAM | 0x212,
    0xeb, OBJ_SIZE_16x16 | 0x1f4, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_VERTICAL | 0xeb, 0x4, OBJ_SPRITE_OAM | 0x214,
    0x5, OBJ_SIZE_16x16 | 0x1f4, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_VERTICAL | 0x5, 0x4, OBJ_SPRITE_OAM | 0x214,
    0xf5, OBJ_SIZE_16x16 | 0x5, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_HORIZONTAL | 0x3, 0x5, OBJ_SPRITE_OAM | 0x212
};

const u16 sUnknownItemBlockOAM_Exploding_Frame5[19] = {
    0x6,
    0xe6, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x212,
    0xa, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1e6, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1fa, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_HORIZONTAL | 0xf3, 0x1f8, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_HORIZONTAL | 0x4, 0x1f8, OBJ_SPRITE_OAM | 0x212
};

const u16 sUnknownItemBlockOAM_Exploding_Frame6[25] = {
    0x8,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_VERTICAL | 0x0, 0x1fc, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_VERTICAL | 0x10, 0x1fc, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1e0, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1f0, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x0, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x10, OBJ_SPRITE_OAM | 0x212
};

const u16 sUnknownItemBlockOAM_Exploding_Frame7[37] = {
    0xc,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1d0, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1e0, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1f0, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x0, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x10, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x20, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x20e,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x20e,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x20e,
    OBJ_SHAPE_VERTICAL | 0x0, 0x1fc, OBJ_SPRITE_OAM | 0x20e,
    OBJ_SHAPE_VERTICAL | 0x10, 0x1fc, OBJ_SPRITE_OAM | 0x20e,
    OBJ_SHAPE_VERTICAL | 0x20, 0x1fc, OBJ_SPRITE_OAM | 0x20e
};

const u16 sUnknownItemBlockOAM_Exploding_Frame8[31] = {
    0xa,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x0, OBJ_SPRITE_OAM | 0x230,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x10, OBJ_SPRITE_OAM | 0x230,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x20, OBJ_SPRITE_OAM | 0x230,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x30, OBJ_SPRITE_OAM | 0x230,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x40, OBJ_SPRITE_OAM | 0x230,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x20f,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x20f,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x20f,
    OBJ_SHAPE_VERTICAL | 0xc0, 0x1fc, OBJ_SPRITE_OAM | 0x20f,
    OBJ_SHAPE_VERTICAL | 0xb0, 0x1fc, OBJ_SPRITE_OAM | 0x20f
};

const u16 sUnknownItemBlockOAM_Exploding_Frame9[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x50, OBJ_SPRITE_OAM | 0x230,
    OBJ_SHAPE_VERTICAL | 0xa0, 0x1fc, OBJ_SPRITE_OAM | 0x20f
};

const u16 sUnknownItemBlockLightOAM_Idle_Frame0[31] = {
    0xa,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | 0x1f0, OBJ_SPRITE_OAM | 0x230,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | 0x1e0, OBJ_SPRITE_OAM | 0x230,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | 0x1d0, OBJ_SPRITE_OAM | 0x230,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | 0x1c0, OBJ_SPRITE_OAM | 0x230,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | 0x1b0, OBJ_SPRITE_OAM | 0x230,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20f,
    OBJ_SHAPE_VERTICAL | 0x10, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20f,
    OBJ_SHAPE_VERTICAL | 0x20, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20f,
    OBJ_SHAPE_VERTICAL | 0x30, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20f,
    OBJ_SHAPE_VERTICAL | 0x40, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20f
};

const u16 sUnknownItemBlockLightOAM_Idle_Frame1[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | 0x1a0, OBJ_SPRITE_OAM | 0x230,
    OBJ_SHAPE_VERTICAL | 0x50, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20f
};

const struct FrameData sUnknownItemBlockOAM_Idle[2] = {
    sUnknownItemBlockOAM_Idle_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sUnknownItemBlockOAM_Activated[7] = {
    sUnknownItemBlockOAM_Idle_Frame0,
    0x8,
    sUnknownItemBlockOAM_Activated_Frame1,
    0x8,
    sUnknownItemBlockOAM_Activated_Frame2,
    0x8,
    sUnknownItemBlockOAM_Activated_Frame3,
    0x8,
    sUnknownItemBlockOAM_Activated_Frame2,
    0x8,
    sUnknownItemBlockOAM_Activated_Frame1,
    0x8,
    NULL,
    0x0
};

const struct FrameData sUnknownItemBlockOAM_Exploding[11] = {
    sUnknownItemBlockOAM_Exploding_Frame0,
    0x2,
    sUnknownItemBlockOAM_Exploding_Frame1,
    0x2,
    sUnknownItemBlockOAM_Exploding_Frame2,
    0x2,
    sUnknownItemBlockOAM_Exploding_Frame3,
    0x2,
    sUnknownItemBlockOAM_Exploding_Frame4,
    0x2,
    sUnknownItemBlockOAM_Exploding_Frame5,
    0x2,
    sUnknownItemBlockOAM_Exploding_Frame6,
    0x2,
    sUnknownItemBlockOAM_Exploding_Frame7,
    0x2,
    sUnknownItemBlockOAM_Exploding_Frame8,
    0x2,
    sUnknownItemBlockOAM_Exploding_Frame9,
    0x2,
    NULL,
    0x0
};

const struct FrameData sUnknownItemBlockLightOAM_Idle[3] = {
    sUnknownItemBlockLightOAM_Idle_Frame0,
    0x2,
    sUnknownItemBlockLightOAM_Idle_Frame1,
    0x2,
    NULL,
    0x0
};


/**
 * @brief 4a930 | 70 | Updates the clipdata of the 4 blocks of the unknown item block
 * 
 * @param caa 
 */
void UnkownItemBlockChangeCCAA(u8 caa)
{
    u16 yPosition;
    u16 xPosition;

    yPosition = gCurrentSprite.yPosition - (BLOCK_SIZE / 2);
    xPosition = gCurrentSprite.xPosition - (BLOCK_SIZE / 2);

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition); // Top left
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition + BLOCK_SIZE); // Top right
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition + BLOCK_SIZE, xPosition); // Bottom left
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition + BLOCK_SIZE, xPosition + BLOCK_SIZE); // Bottom right
}

/**
 * @brief 4a9a0 | 22c | Unknown item block AI
 * 
 */
void UnkownItemBlock(void)
{
    u32 spriteID;
    u8 activated;

    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    activated = FALSE;
    spriteID = gCurrentSprite.spriteID;

    switch (gCurrentSprite.pose)
    {
        case 0x0:
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            gCurrentSprite.drawOrder = 0x1;

            gCurrentSprite.hitboxTopOffset = -0x44;
            gCurrentSprite.hitboxBottomOffset = 0x44;
            gCurrentSprite.hitboxLeftOffset = -0x44;
            gCurrentSprite.hitboxRightOffset = 0x44;

            gCurrentSprite.drawDistanceTopOffset = 0x10;
            gCurrentSprite.drawDistanceBottomOffset = 0x10;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

            gCurrentSprite.pOam = sUnknownItemBlockLightOAM_Idle;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;

            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.health = 0x1;
            gCurrentSprite.pose = UNKNOWN_ITEM_BLOCK_POSE_CHECK_ACTIVATE;

            gCurrentSprite.yPosition -= BLOCK_SIZE;
            gCurrentSprite.xPosition += (BLOCK_SIZE / 2);
            UnkownItemBlockChangeCCAA(CAA_MAKE_SOLID_GRIPPABLE);

        case UNKNOWN_ITEM_BLOCK_POSE_CHECK_ACTIVATE:
            // Check activate block
            if (spriteID == PSPRITE_PLASMA_BEAM_BLOCK)
            {
                if (EventFunction(EVENT_ACTION_CHECKING, EVENT_PLASMA_BEAM_OBTAINED))
                    activated++;
            }
            else if (spriteID == PSPRITE_GRAVITY_SUIT_BLOCK)
            {
                if (EventFunction(EVENT_ACTION_CHECKING, EVENT_GRAVITY_SUIT_OBTAINED))
                    activated++;
            }
            else if (spriteID == PSPRITE_SPACE_JUMP_BLOCK)
            {
                if (EventFunction(EVENT_ACTION_CHECKING, EVENT_SPACE_JUMP_OBTAINED))
                    activated++;
            }

            if (activated)
            {
                // Set activated behavior
                gCurrentSprite.pOam = sUnknownItemBlockOAM_Activated;
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.currentAnimationFrame = 0x0;
                gCurrentSprite.status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;
                gCurrentSprite.pose = UNKNOWN_ITEM_BLOCK_POSE_WAIT_FOR_PROJECITLE;
            }
            break;

        case UNKNOWN_ITEM_BLOCK_POSE_WAIT_FOR_PROJECITLE:
            break; // No behavior (don't go to default)

        case UNKNOWN_ITEM_BLOCK_POSE_EXPLODING:
            if (SpriteUtilCheckEndCurrentSpriteAnim())
                gCurrentSprite.status = 0x0;
            else
            {
                // Update draw distances
                if (gCurrentSprite.currentAnimationFrame == 0x1)
                {
                    gCurrentSprite.drawDistanceTopOffset = 0x30;
                    gCurrentSprite.drawDistanceBottomOffset = 0x30;
                }
                else if (gCurrentSprite.currentAnimationFrame == 0x8)
                {
                    gCurrentSprite.drawDistanceTopOffset = 0x60;
                    gCurrentSprite.drawDistanceBottomOffset = 0x0;
                }
                else if (gCurrentSprite.currentAnimationFrame == 0x7 && gCurrentSprite.animationDurationCounter == 0x2)
                {
                    // Spawn light
                    activated = SpriteSpawnSecondary(SSPRITE_UNKNOWN_ITEM_BLOCK_LIGHT, 0x0, gCurrentSprite.spritesetGFXSlot,
                        gCurrentSprite.primarySpriteRAMSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);

                    if (activated < 0x18)
                    {
                        // Initialize light
                        gSpriteData[activated].status &= ~SPRITE_STATUS_NOT_DRAWN;
                        gSpriteData[activated].bgPriority = gIORegistersBackup.BG1CNT & 0x3;
                        gSpriteData[activated].drawOrder = 0x1;
                        
                        gSpriteData[activated].hitboxTopOffset = 0x0;
                        gSpriteData[activated].hitboxBottomOffset = 0x0;
                        gSpriteData[activated].hitboxLeftOffset = 0x0;
                        gSpriteData[activated].hitboxRightOffset = 0x0;

                        gSpriteData[activated].drawDistanceTopOffset = 0x0;
                        gSpriteData[activated].drawDistanceBottomOffset = 0x50;
                        gSpriteData[activated].drawDistanceHorizontalOffset = 0x60;

                        gSpriteData[activated].pOam = sUnknownItemBlockLightOAM_Idle;
                        gSpriteData[activated].animationDurationCounter = 0x0;
                        gSpriteData[activated].currentAnimationFrame = 0x0;

                        gSpriteData[activated].samusCollision = SSC_NONE;
                        gSpriteData[activated].pose = 0x9;
                    }
                }
            }
            break;

        default:
            // Hit by something, set exploding behavior
            gCurrentSprite.pose = UNKNOWN_ITEM_BLOCK_POSE_EXPLODING;
            gCurrentSprite.bgPriority = gIORegistersBackup.BG1CNT & 0x3;

            gCurrentSprite.pOam = sUnknownItemBlockOAM_Exploding;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x60;

            UnkownItemBlockChangeCCAA(CAA_REMOVE_SOLID); // Remove collision

            // Play sound, most likely planned to have a different sound for each block
            if (spriteID == PSPRITE_PLASMA_BEAM_BLOCK)
                SoundPlayNotAlreadyPlaying(0x13B);
            else if (spriteID == PSPRITE_GRAVITY_SUIT_BLOCK)
                SoundPlayNotAlreadyPlaying(0x13B);
            else if (spriteID == PSPRITE_SPACE_JUMP_BLOCK)
                SoundPlayNotAlreadyPlaying(0x13B);
            break;
    }
}

/**
 * @brief 4abcc | 34 | Unknown item block light AI
 * 
 */
void UnkownItemBlockLight(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    if (gCurrentSprite.currentAnimationFrame != 0x0)
    {
        gCurrentSprite.drawDistanceTopOffset = 0x0;
        gCurrentSprite.drawDistanceBottomOffset = 0x60;
    }

    if (SpriteUtilCheckEndCurrentSpriteAnim())
        gCurrentSprite.status = 0x0;
}