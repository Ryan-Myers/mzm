#include "projectile.h"
#include "sprite.h"
#include "clipdata.h"
#include "sprite_util.h"
#include "power_bomb_explosion.h"
#include "music.h"
#include "game_modes.h"
#include "../data/data.h"
#include "globals.h"

void ProjectileSetBeamParticleEffect(void)
{
    u16 yPosition;
    u16 xPosition;
    u8 effect;
    u16 direction;

    yPosition = gArmCannonY;
    xPosition = gArmCannonX;
    direction = gSamusData.direction & KEY_RIGHT;

    switch (gSamusData.armCannonDirection)
    {
        case ACD_DIAGONALLY_DOWN:
            if (direction)
                effect = PE_SHOOTING_BEAM_DIAG_DOWN_RIGHT;
            else
                effect = PE_SHOOTING_BEAM_DIAG_DOWN_LEFT;
            break;

        case ACD_DIAGONALLY_UP:
            if (direction)
                effect = PE_SHOOTING_BEAM_DIAG_UP_RIGHT;
            else
                effect = PE_SHOOTING_BEAM_DIAG_UP_LEFT;
            break;

        case ACD_DOWN:
            if (direction)
                effect = PE_SHOOTING_BEAM_DOWN_RIGHT;
            else
                effect = PE_SHOOTING_BEAM_DOWN_LEFT;
            break;
        
        case ACD_UP:
            if (direction)
                effect = PE_SHOOTING_BEAM_UP_RIGHT;
            else
                effect = PE_SHOOTING_BEAM_UP_LEFT;
            break;

        default:
        case ACD_FORWARD:
            if (direction)
                effect = PE_SHOOTING_BEAM_RIGHT;
            else
                effect = PE_SHOOTING_BEAM_LEFT;
            break;
    }

    ParticleSet(yPosition, xPosition, effect);
}

u8 ProjectileCheckNumberOfProjectiles(u8 type, u8 limit)
{
    u8 count;
    struct ProjectileData* pProj;

    count = 0x0;
    pProj = gProjectileData;

    while (pProj < gProjectileData + 16)
    {
        if (pProj->status & PROJ_STATUS_EXISTS && pProj->type == type)
        {
            count++;
            if (count >= limit)
                return FALSE;
        }
        pProj++;
    }

    return TRUE;
}

/**
 * @brief 4ede4 | a4 | Tries to initialize a projectile with the given parameters
 * 
 * @param type Proectile Type
 * @param yPosition Y Position
 * @param xPosition X Position
 * @return u8 1 if could init, 0 otherwise
 */
u8 ProjectileInit(u8 type, u16 yPosition, u16 xPosition)
{
    struct ProjectileData* pProj;
    struct SamusData* pData;
    u8 status;
    u8 hitbox;

    for (pProj = gProjectileData; pProj < gProjectileData + 16; pProj++)
    {
        hitbox = 0x1;
        pData = &gSamusData;
        if (!(pProj->status & PROJ_STATUS_EXISTS))
        {
            if (type > PROJ_TYPE_SUPER_MISSILE)
                status = (PROJ_STATUS_EXISTS | PROJ_STATUS_ON_SCREEN | PROJ_STATUS_NOT_DRAWN);
            else // Bomb, power bomb
                status = (PROJ_STATUS_EXISTS | PROJ_STATUS_ON_SCREEN | PROJ_STATUS_NOT_DRAWN | PROJ_STATUS_CAN_AFFECT_ENVIRONMENT);

            if (pData->direction & KEY_RIGHT)
                status |= PROJ_STATUS_XFLIP;

            pProj->status = status;
            pProj->type = type;
            pProj->yPosition = yPosition;
            pProj->xPosition = xPosition;
            pProj->hitboxTopOffset = -0x1;
            pProj->hitboxBottomOffset = hitbox;
            pProj->hitboxLeftOffset = -0x1;
            pProj->hitboxRightOffset = hitbox;
            pProj->movementStage = 0x0;
            pProj->timer = pProj->movementStage;
            pProj->direction = pData->armCannonDirection;
            return TRUE;
        }
    }
    
    return FALSE;
}

void ProjectileUpdate(void)
{
    // https://decomp.me/scratch/jEGx8

    /*i32 count;
    u8 checks;
    u8 projType;
    u16 beamSound;
    u16 beams;
    struct ParticleEffect* pParticle;
    struct ProjectileData* pProj;

    if (gGameModeSub1 != SUB_GAME_MODE_PLAYING)
        return;
    
    SamusCallUpdateArmCannonPositionOffset();
    gArmCannonY = (((gSamusData.yPosition / 4)) + gSamusPhysics.armCannonYPositionOffset) * 0x4;
    gArmCannonX = (((gSamusData.xPosition / 4)) + gSamusPhysics.armCannonXPositionOffset) * 0x4;

    if (gSamusWeaponInfo.chargeCounter == 0x10 && gEquipment.suitType != SUIT_SUITLESS)
    {
        checks = FALSE;
        count = 0x0;
        
        pParticle = gParticleEffects; // /!\ Swapped instructions

        do
        {
            if (pParticle->status & PARTICLE_STATUS_EXISTS && pParticle->effect == PE_CHARGING_BEAM)
            {
                checks++;
                break;
            }

            pParticle++;
            count++;
        } while (count < 0x10);

        if (!checks)
            ParticleSet(gArmCannonY, gArmCannonX, PE_CHARGING_BEAM);
    }

    switch (gSamusWeaponInfo.newProjectile)
    {
        case PROJECTILE_CHARGED_BEAM:
            if (gEquipment.suitType == SUIT_SUITLESS)
            {
                if (ProjectileCheckNumberOfProjectiles(PROJ_TYPE_CHARGED_PISTOL, 0x2) && ProjectileInit(PROJ_TYPE_CHARGED_PISTOL, gArmCannonY, gArmCannonX))
                {
                    gSamusWeaponInfo.cooldown = 0x7;
                    ProjectileSetBeamParticleEffect();
                    gSamusWeaponInfo.beamReleasePaletteTimer = 0x4;
                    SoundPlay(0xA0); // Charged pistol shot
                }
            }
            else
            {
                beams = gEquipment.beamBombsActivation;
                if (beams & BBF_PLASMA_BEAM)
                {
                    projType = PROJ_TYPE_CHARGED_PLASMA_BEAM;
                    if (beams & BBF_WAVE_BEAM)
                    {
                        if (beams & BBF_LONG_BEAM)
                        {
                            if (beams & BBF_ICE_BEAM)
                                beamSound = 0xF7;
                            else
                                beamSound = 0xF5;
                        }
                        else
                        {
                            if (beams & BBF_ICE_BEAM)
                                beamSound = 0xF6;
                            else
                                beamSound = 0xF4;
                        }
                    }
                    else
                    {
                        if (beams & BBF_LONG_BEAM)
                        {
                            if (beams & BBF_ICE_BEAM)
                                beamSound = 0xF3;
                            else
                                beamSound = 0xF1;
                        }
                        else
                        {
                            if (beams & BBF_ICE_BEAM)
                                beamSound = 0xF2;
                            else
                                beamSound = 0xF0;
                        }
                    }
                }
                else
                {
                    if (beams & BBF_WAVE_BEAM)
                    {
                        projType = PROJ_TYPE_CHARGED_WAVE_BEAM;
                        if (beams & BBF_LONG_BEAM)
                        {
                            if (beams & BBF_ICE_BEAM)
                                beamSound = 0xEF;
                            else
                                beamSound = 0xED;
                        }
                        else
                        {
                            if (beams & BBF_ICE_BEAM)
                                beamSound = 0xEE;
                            else
                                beamSound = 0xEC;
                        }
                    }
                    else
                    {
                        if (beams & BBF_ICE_BEAM)
                        {
                            projType = PROJ_TYPE_CHARGED_ICE_BEAM;
                            if (beams & BBF_LONG_BEAM)
                                beamSound = 0xEB;
                            else
                                beamSound = 0xEA;
                        }
                        else
                        {
                            if (beams & BBF_LONG_BEAM)
                            {
                                projType = PROJ_TYPE_CHARGED_LONG_BEAM;
                                beamSound = 0xE9;
                            }
                            else
                            {
                                projType = PROJ_TYPE_CHARGED_BEAM;
                                beamSound = 0xE8;
                            }
                        }
                    }
                }

                if (ProjectileCheckNumberOfProjectiles(projType, 0x2) && ProjectileInit(projType, gArmCannonY, gArmCannonX))
                {
                    gSamusWeaponInfo.cooldown = 0x7;
                    ProjectileSetBeamParticleEffect();
                    gSamusWeaponInfo.beamReleasePaletteTimer = 0x4;
                    SoundPlay(beamSound);
                }
            }
            gSamusWeaponInfo.newProjectile = PROJECTILE_NONE;
            break;

        case PROJECTILE_BEAM:
            if (gEquipment.suitType == SUIT_SUITLESS)
            {
                if (ProjectileCheckNumberOfProjectiles(PROJ_TYPE_PISTOL, 0x6) && ProjectileInit(PROJ_TYPE_PISTOL, gArmCannonY, gArmCannonX))
                {
                    gSamusWeaponInfo.cooldown = 0x7;
                    ProjectileSetBeamParticleEffect();
                    gSamusWeaponInfo.beamReleasePaletteTimer = 0x4;
                    SoundPlay(0x9F); // Pistol shot
                }
            }
            else
            {
                beams = gEquipment.beamBombsActivation;
                if (beams & BBF_PLASMA_BEAM)
                {
                    projType = PROJ_TYPE_PLASMA_BEAM;
                    if (beams & BBF_WAVE_BEAM)
                    {
                        if (beams & BBF_LONG_BEAM)
                        {
                            if (beams & BBF_ICE_BEAM)
                                beamSound = 0xD7;
                            else
                                beamSound = 0xD5;
                        }
                        else
                        {
                            if (beams & BBF_ICE_BEAM)
                                beamSound = 0xD6;
                            else
                                beamSound = 0xD4;
                        }
                    }
                    else
                    {
                        if (beams & BBF_LONG_BEAM)
                        {
                            if (beams & BBF_ICE_BEAM)
                                beamSound = 0xD3;
                            else
                                beamSound = 0xD1;
                        }
                        else
                        {
                            if (beams & BBF_ICE_BEAM)
                                beamSound = 0xD2;
                            else
                                beamSound = 0xD0;
                        }
                    }
                }
                else
                {
                    if (beams & BBF_WAVE_BEAM)
                    {
                        projType = PROJ_TYPE_WAVE_BEAM;
                        if (beams & BBF_LONG_BEAM)
                        {
                            if (beams & BBF_ICE_BEAM)
                                beamSound = 0xCF;
                            else
                                beamSound = 0xCD;
                        }
                        else
                        {
                            if (beams & BBF_ICE_BEAM)
                                beamSound = 0xCE;
                            else
                                beamSound = 0xCC;
                        }
                    }
                    else
                    {
                        if (beams & BBF_ICE_BEAM)
                        {
                            projType = PROJ_TYPE_ICE_BEAM;
                            if (beams & BBF_LONG_BEAM)
                                beamSound = 0xCB;
                            else
                                beamSound = 0xCA;
                        }
                        else
                        {
                            if (beams & BBF_LONG_BEAM)
                            {
                                projType = PROJ_TYPE_LONG_BEAM;
                                beamSound = 0xC9;
                            }
                            else
                            {
                                projType = PROJ_TYPE_BEAM;
                                beamSound = 0xC8;
                            }
                        }
                    }
                }

                if (ProjectileCheckNumberOfProjectiles(projType, 0x6) && ProjectileInit(projType, gArmCannonY, gArmCannonX))
                {
                    gSamusWeaponInfo.cooldown = 0x7;
                    ProjectileSetBeamParticleEffect();
                    gSamusWeaponInfo.beamReleasePaletteTimer = 0x4;
                    SoundPlay(beamSound);
                }
            }
            gSamusWeaponInfo.newProjectile = PROJECTILE_NONE;
            break;

        case PROJECTILE_MISSILE:
            if (ProjectileCheckNumberOfProjectiles(PROJ_TYPE_MISSILE, 0x4) && ProjectileInit(PROJ_TYPE_MISSILE, gArmCannonY, gArmCannonX))
            {
                gSamusWeaponInfo.cooldown = 0x9;
                SoundPlay(0xF8); // Missile shot
                SoundPlay(0xF9); // Missile thrust
            }
            gSamusWeaponInfo.newProjectile = PROJECTILE_NONE;
            break;

        case PROJECTILE_SUPER_MISSILE:
            if (ProjectileCheckNumberOfProjectiles(PROJ_TYPE_SUPER_MISSILE, 0x4) && ProjectileInit(PROJ_TYPE_SUPER_MISSILE, gArmCannonY, gArmCannonX))
            {
                gSamusWeaponInfo.cooldown = 0xB;
                SoundPlay(0xFB); // Super missile shot
                SoundPlay(0xFC); // Super missile thrust
            }
            gSamusWeaponInfo.newProjectile = PROJECTILE_NONE;
            break;

        case PROJECTILE_BOMB:
            if (ProjectileCheckNumberOfProjectiles(PROJ_TYPE_BOMB, 0x4) && ProjectileInit(PROJ_TYPE_BOMB, gSamusData.yPosition, gSamusData.xPosition))
                gSamusWeaponInfo.cooldown = 0x7;
            gSamusWeaponInfo.newProjectile = PROJECTILE_NONE;
            break;

        case PROJECTILE_POWER_BOMB:
            if (ProjectileCheckNumberOfProjectiles(PROJ_TYPE_POWER_BOMB, 0x1) && gCurrentPowerBomb.animationState == 0x0
                && ProjectileInit(PROJ_TYPE_POWER_BOMB, gSamusData.yPosition, gSamusData.xPosition))
                gSamusWeaponInfo.cooldown = 0x5;
            gSamusWeaponInfo.newProjectile = PROJECTILE_NONE;
            break;
    }

    ProjectileCheckHittingSprite();

    for (pProj = gProjectileData; pProj < gProjectileData + 16; pProj++)
    {
        if (pProj->status & PROJ_STATUS_EXISTS)
        {
            process_projectile_functions_pointers[pProj->type](pProj);
            ProjectileUpdateAnimation(pProj);
            ProjectileCheckDespawn(pProj);
        }
    }*/
}

void ProjectileUpdateAnimation(struct ProjectileData* pProj)
{
    u32 adc;

    adc = pProj->animationDurationCounter + 0x1;
    pProj->animationDurationCounter = adc;
    if ((u8)pProj->pOam[pProj->currentAnimationFrame].timer < (u8)adc)
    {
        pProj->animationDurationCounter = 0x1;
        pProj->currentAnimationFrame++;
        if ((u8)pProj->pOam[pProj->currentAnimationFrame].timer == 0x0)
            pProj->currentAnimationFrame = 0x0;
    }
}

void ProjectileDrawAllStatusFalse(void)
{

}

void ProjectileDrawAllStatusTrue(void)
{

}

void ProjectileDraw(struct ProjectileData* pProj)
{

}

void ProjectileCheckDespawn(struct ProjectileData* pProj)
{
    /*u16 x_pos;
    u16 y_pos;
    u16 draw_distance;

    if ((pProj->status & PROJ_STATUS_EXISTS) == 0x0) return;

    y_pos = pProj->yPosition;
    x_pos = pProj->xPosition;
    draw_distance = pProj->draw_distance_offset;

    if ((gBG1XPosition + 0x100) - draw_distance < x_pos + 0x100 &&
        (x_pos + 0x100 < gBG1XPosition + 0x100 + draw_distance + 0x3C0) &&
        ((gBG1YPosition + 0x100) - draw_distance < y_pos + 0x100) &&
        (y_pos + 0x100 < gBG1YPosition + 0x100 + draw_distance + 0x280))
        pProj->status |= PROJ_STATUS_ON_SCREEN;
    else
    {
        pProj->status &= (PROJ_STATUS_EXISTS | PROJ_STATUS_NOT_DRAWN | PROJ_STATUS_HIGH_PRIORITY | PROJ_STATUS_CAN_AFFECT_ENVIRONMENT | PROJ_STATUS_YFLIP | PROJ_STATUS_XFLIP | PROJ_STATUS_UNKNOWN);
        if (PROJ_TYPE_SUPER_MISSILE < pProj->type) return;

        draw_distance = gSamusData.yPosition - 0x48;
        if (draw_distance < y_pos)
            y_pos -= draw_distance;
        else
            y_pos = draw_distance - y_pos;
        
        if (gSamusData.xPosition < x_pos)
            x_pos -= gSamusData.xPosition;
        else
            x_pos = gSamusData.xPosition - x_pos;
        
        if (y_pos < 0x301 && x_pos < 0x281) return;

        pProj->status = 0x0;
    }*/
}

void ProjectileLoadGraphics(void)
{

}

void ProjectileCallLoadGraphicsAndClearProjectiles(void)
{
    struct ProjectileData* pProj;

    ProjectileLoadGraphics();

    if (gPauseScreenFlag == 0x0)
    {
        pProj = gProjectileData;
        while (pProj < gProjectileData + 16)
        {
            pProj->status = 0x0;
            pProj++;
        }
    }
}

void ProjectileMove(struct ProjectileData* pProj, u8 distance)
{
    /*i16 xVelocity;
    i32 xVelocity_;
    
    switch (pProj->direction)
    {
        case ACD_UP:
            pProj->yPosition -= distance;
            return;

        case ACD_DOWN:
            pProj->yPosition += distance;
            return;

        case ACD_DIAGONALLY_UP:
            distance = (distance * 0x7) / 0xA;
            pProj->yPosition -= distance;
            if (pProj->status & PROJ_STATUS_XFLIP)
                pProj->xPosition += distance;
            else
                pProj->xPosition -= distance;
            break;

        case ACD_DIAGONALLY_DOWN:
            distance = (distance * 0x7) / 0xA;
            pProj->yPosition += distance;
            if (pProj->status & PROJ_STATUS_XFLIP)
                pProj->xPosition += distance;
            else
                pProj->xPosition -= distance;
            break;

        default:
            if (pProj->status & PROJ_STATUS_XFLIP)
                pProj->xPosition += distance;
            else
                pProj->xPosition -= distance;
    }

    xVelocity = (u16)gSamusData.xVelocity;
    xVelocity_ = xVelocity >> 0x3;
    if (pProj->status & PROJ_STATUS_XFLIP)
    {
        if (xVelocity >= 0x1)
            pProj->xPosition += xVelocity >> 0x3;
    }
    else
    {
        if (xVelocity < 0x0)
            pProj->xPosition += xVelocity_;
    }*/
}

u32 ProjectileCheckHittingSolidBlock(u32 yPosition, u32 xPosition)
{
    u32 collision;
    
    collision = ClipdataProcess(yPosition, xPosition);

    if (collision & CLIPDATA_TYPE_SOLID_FLAG)
        return TRUE;
    else
        return FALSE;
}

u8 ProjectileCheckVerticalCollisionAtPosition(struct ProjectileData* pProj)
{

}

/**
 * 4fc38 | a8 | 
 * Sets a trail for the projectile using the effect in parameter 
 * 
 * @param pProj Projectile Data Pointer to the projectile concerned
 * @param effect Particle effect to play
 * @param delay Delay between each particle
 */
void ProjectileSetTrail(struct ProjectileData* pProj, u8 effect, u8 delay)
{
    // https://decomp.me/scratch/4n6pN

    /*u16 xPosition;
    u16 yPosition;
    u16 movement;
    u8 status;

    if (gFrameCounter8Bit & delay)
        return;

    movement = 0x20;

    yPosition = pProj->yPosition;
    xPosition = pProj->xPosition;

    switch (pProj->direction)
    {
        case ACD_UP:
            yPosition += 0x20;
            break;

        case ACD_DOWN:
            yPosition -= 0x20;
            break;

        case ACD_DIAGONALLY_UP:
            status = PROJ_STATUS_XFLIP;
            yPosition += 0x18;
            if (status & pProj->status)
                xPosition -= 0x18;
            else
                xPosition += 0x18;
            break;

        case ACD_DIAGONALLY_DOWN:
            status = PROJ_STATUS_XFLIP;
            yPosition -= 0x18;
            if (status & pProj->status)
                xPosition -= 0x18;
            else
                xPosition += 0x18;
            break;

        default:
            if (pProj->status & PROJ_STATUS_XFLIP)
                xPosition -= movement;
            else
                xPosition += movement;
            break;
    }

    ParticleSet(yPosition, xPosition, effect);*/
}

/**
 * 4fce0 | 68 | 
 * Handles a projectile moving when tumbling
 * 
 * @param pProj Projectile Data Pointer to the concerned projectile
 */
void ProjectileMoveTumbling(struct ProjectileData* pProj)
{
    u8 timer;
    i16 movement;
    u32 new_pos;

    if ((pProj->status & PROJ_STATUS_ON_SCREEN) == 0x0)
        pProj->status = 0x0;
    else
    {
        timer = pProj->timer;
        movement = tumbling_missile_speed[timer];
        if (movement == SPRITE_ARRAY_TERMINATOR)
            new_pos = tumbling_missile_speed[timer - 1] + pProj->yPosition;
        else
        {
            pProj->timer = timer + 1;
            new_pos = pProj->yPosition + movement;
        }
        pProj->yPosition = new_pos;

        if (pProj->status & PROJ_STATUS_XFLIP)
            new_pos = pProj->xPosition + 0x4;
        else
            new_pos = pProj->xPosition - 0x4;
        pProj->xPosition = new_pos;
    }
}

void ProjectileCheckHitBlock(struct ProjectileData* pProj, u8 ccaa, u8 effect)
{
    u16 yPosition;
    u16 xPosition;

    gCurrentClipdataAffectingAction = ccaa;
    yPosition = pProj->yPosition;
    xPosition = pProj->xPosition;
    if (pProj->direction == ACD_FORWARD)
    {
        if (pProj->status & PROJ_STATUS_XFLIP)
            xPosition -= 0x8;
        else
            xPosition += 0x8;
    }

    if (ProjectileCheckHittingSolidBlock(yPosition, xPosition))
    {
        pProj->status = 0x0;
        ParticleSet(pProj->yPosition, pProj->xPosition, effect);
    }
}

void ProjectileCheckHittingSprite(void)
{
    // https://decomp.me/scratch/Sk02A

    /*struct Equipment* pEquipment;
    struct SpriteData* pSprite;
    struct SpriteData* pSprite_next;
    struct ProjectileData* pProj;
    u16 status;
    
    u8 statusProj;
    u16 projY;
    u16 projX;
    u16 projTop;
    u16 projBottom;
    u16 projLeft;
    u16 projRight;
    
    u16 spriteY;
    u16 spriteX;
    u16 spriteTop;
    u16 spriteBottom;
    u16 spriteLeft;
    u16 spriteRight;
    
    u8 count;
    u8 drawOrder;
    u32 drawOrder_next;

    pEquipment = &gEquipment;
    if (gCurrentPowerBomb.animationState != 0x0 && pEquipment->maxPowerBombs != 0x0)
    {
        projY = gCurrentPowerBomb.yPosition;
        projX = gCurrentPowerBomb.xPosition;
        projTop = projY + gCurrentPowerBomb.hitboxTopOffset;
        projBottom = projY + gCurrentPowerBomb.hitboxBottomOffset;
        projLeft = projX + gCurrentPowerBomb.hitboxLeftOffset;
        projRight = projX + gCurrentPowerBomb.hitboxRightOffset;
        status = (SPRITE_STATUS_EXISTS | SPRITE_STATUS_IGNORE_PROJECTILES);
        pSprite = gSpriteData;
        while (pSprite < gSpriteData + 24)
        {
            if ((pSprite->status & status) == SPRITE_STATUS_EXISTS && pSprite->health != 0x0 && (pSprite->invicibilityStunFlashTimer & 0x80) == 0x0)
            {
                spriteY = pSprite->yPosition;
                spriteX = pSprite->xPosition;
                spriteTop = spriteY + pSprite->hitboxTopOffset;
                spriteBottom = spriteY + pSprite->hitboxBottomOffset;
                spriteLeft = spriteX + pSprite->hitboxLeftOffset;
                spriteRight = spriteX + pSprite->hitboxRightOffset;
                if (SpriteUtilCheckObjectsTouching(spriteTop, spriteBottom, spriteLeft, spriteRight, projTop, projBottom, projLeft, projRight))
                    ProjectilePowerBombDealDamage(pSprite);
            }
            pSprite++;
        }
    }
    status = (SPRITE_STATUS_EXISTS | SPRITE_STATUS_IGNORE_PROJECTILES);
    count = 0x0;
    pSprite = gSpriteData;
    while (pSprite < gSpriteData + 24)
    {
        if ((pSprite->status & status) == SPRITE_STATUS_EXISTS && pSprite->health != 0x0)
            gSpriteDrawOrder[count] = pSprite->drawOrder;
        else
            gSpriteDrawOrder[count] = 0x0;
        count++;
        pSprite++;
    }
    drawOrder = 0x1;
    do {
        count = 0x0;
        pSprite = gSpriteData;
        drawOrder_next = drawOrder + 0x1;
        while (pSprite < gSpriteData + 24)
        {
            pSprite_next = pSprite + 0x1;
            if (gSpriteDrawOrder[count] == drawOrder)
            {
                spriteY = pSprite->yPosition;
                spriteX = pSprite->xPosition;
                spriteTop = spriteY + pSprite->hitboxTopOffset;
                spriteBottom = spriteY + pSprite->hitboxBottomOffset;
                spriteLeft = spriteX + pSprite->hitboxLeftOffset;
                spriteRight = spriteX + pSprite->hitboxRightOffset;
                statusProj = PROJ_STATUS_EXISTS | PROJ_STATUS_CAN_AFFECT_ENVIRONMENT;
                pProj = gProjectileData;
                while (pProj < gProjectileData + 16)
                {
                    if ((pProj->status & statusProj) == statusProj)
                    {
                        projY = pProj->yPosition;
                        projX = pProj->xPosition;
                        if (SpriteUtilCheckObjectsTouching(spriteTop, spriteBottom, spriteLeft, spriteRight, projY + pProj->hitboxTopOffset, projY + pProj->hitboxBottomOffset, projX + pProj->hitboxLeftOffset, projX + pProj->hitboxRightOffset))
                        {
                            switch (pProj->type)
                            {
                                case PROJ_TYPE_BEAM:
                                    ProjectileHitSprite(pSprite, projY, projX, 0x2, PE_HITTING_SOMETHING_WITH_BASE_BEAM);
                                    pProj->status = 0x0;
                                    break;

                                case PROJ_TYPE_LONG_BEAM:
                                    ProjectileHitSprite(pSprite, projY, projX, 0x3, PE_HITTING_SOMETHING_WITH_LONG_BEAM);
                                    pProj->status = 0x0;
                                    break;

                                case PROJ_TYPE_ICE_BEAM:
                                    if (pEquipment->beamBombsActivation & BBF_LONG_BEAM)
                                        ProjectileIceBeamHittingSprite(pSprite, projY, projX, 0x4, PE_HITTING_SOMETHING_WITH_ICE_BEAM);
                                    else
                                        ProjectileIceBeamHittingSprite(pSprite, projY, projX, 0x3, PE_HITTING_SOMETHING_WITH_ICE_BEAM);
                                    pProj->status = 0x0;
                                    break;

                                case PROJ_TYPE_WAVE_BEAM:
                                    if (pEquipment->beamBombsActivation & BBF_LONG_BEAM)
                                    {
                                        if (pEquipment->beamBombsActivation & BBF_ICE_BEAM)
                                            ProjectileIceBeamHittingSprite(pSprite, projY, projX, 0x5, PE_HITTING_SOMETHING_WITH_FULL_BEAM_NO_PLASMA);
                                        else
                                            ProjectileHitSprite(pSprite, projY, projX, 0x4, PE_HITTING_SOMETHING_WITH_WAVE_BEAM);
                                    }
                                    else
                                    {
                                        if (pEquipment->beamBombsActivation & BBF_ICE_BEAM)
                                            ProjectileIceBeamHittingSprite(pSprite, projY, projX, 0x4, PE_HITTING_SOMETHING_WITH_FULL_BEAM_NO_PLASMA);
                                        else
                                            ProjectileHitSprite(pSprite, projY, projX, 0x3, PE_HITTING_SOMETHING_WITH_WAVE_BEAM);
                                    }
                                    pProj->status = 0x0;
                                    break;

                                case PROJ_TYPE_PLASMA_BEAM:
                                    if (pEquipment->beamBombsActivation & BBF_LONG_BEAM)
                                    {
                                        if (pEquipment->beamBombsActivation & BBF_ICE_BEAM)
                                        {
                                            if (pEquipment->beamBombsActivation & BBF_WAVE_BEAM)
                                                ProjectileIceBeamHittingSprite(pSprite, projY, projX, 0x6, PE_HITTING_SOMETHING_WITH_FULL_BEAM);
                                            else
                                                ProjectileIceBeamHittingSprite(pSprite, projY, projX, 0x5, PE_HITTING_SOMETHING_WITH_FULL_BEAM);
                                        }
                                        else
                                        {
                                            if (pEquipment->beamBombsActivation & BBF_WAVE_BEAM)
                                                ProjectileHitSprite(pSprite, projY, projX, 0x5, PE_HITTING_SOMETHING_WITH_PLASMA_BEAM);
                                            else
                                                ProjectileHitSprite(pSprite, projY, projX, 0x4, PE_HITTING_SOMETHING_WITH_PLASMA_BEAM);
                                        }
                                    }
                                    else
                                    {
                                        if (pEquipment->beamBombsActivation & BBF_ICE_BEAM)
                                        {
                                            if (pEquipment->beamBombsActivation & BBF_WAVE_BEAM)
                                                ProjectileIceBeamHittingSprite(pSprite, projY, projX, 0x5, PE_HITTING_SOMETHING_WITH_FULL_BEAM);
                                            else
                                                ProjectileIceBeamHittingSprite(pSprite, projY, projX, 0x4, PE_HITTING_SOMETHING_WITH_FULL_BEAM);
                                        }
                                        else
                                        {
                                            if (pEquipment->beamBombsActivation & BBF_WAVE_BEAM)
                                                ProjectileHitSprite(pSprite, projY, projX, 0x4, PE_HITTING_SOMETHING_WITH_PLASMA_BEAM);
                                            else
                                                ProjectileHitSprite(pSprite, projY, projX, 0x3, PE_HITTING_SOMETHING_WITH_PLASMA_BEAM);
                                        }
                                    }
                                    break;

                                case PROJ_TYPE_PISTOL:
                                    ProjectileHitSpriteImmuneToProjectiles(pSprite);
                                    ParticleSet(projY, projX, PE_HITTING_SOMETHING_INVINCIBLE);
                                    pProj->status = 0x0;
                                    break;

                                case PROJ_TYPE_CHARGED_BEAM:
                                    ProjectileNonIceChargedHitSprite(pSprite, projY, projX, 0x8, PE_HITTING_SOMETHING_WITH_BASE_BEAM);
                                    pProj->status = 0x0;
                                    break;

                                case PROJ_TYPE_CHARGED_LONG_BEAM:
                                    ProjectileNonIceChargedHitSprite(pSprite, projY, projX, 0xC, PE_HITTING_SOMETHING_WITH_LONG_BEAM);
                                    pProj->status = 0x0;
                                    break;

                                case PROJ_TYPE_CHARGED_ICE_BEAM:
                                    if (pEquipment->beamBombsActivation & BBF_LONG_BEAM)
                                        ProjectileChargedIceBeamHittingSprite(pSprite, projY, projX, 0x10, PE_HITTING_SOMETHING_WITH_ICE_BEAM);
                                    else
                                        ProjectileChargedIceBeamHittingSprite(pSprite, projY, projX, 0xC, PE_HITTING_SOMETHING_WITH_ICE_BEAM);
                                    pProj->status = 0x0;
                                    break;

                                case PROJ_TYPE_CHARGED_WAVE_BEAM:
                                    if (pEquipment->beamBombsActivation & BBF_LONG_BEAM)
                                    {
                                        if (pEquipment->beamBombsActivation & BBF_ICE_BEAM)
                                            ProjectileChargedIceBeamHittingSprite(pSprite, projY, projX, 0x14, PE_HITTING_SOMETHING_WITH_FULL_BEAM_NO_PLASMA);
                                        else
                                            ProjectileNonIceChargedHitSprite(pSprite, projY, projX, 0x10, PE_HITTING_SOMETHING_WITH_WAVE_BEAM);
                                    }
                                    else
                                    {
                                        if (pEquipment->beamBombsActivation & BBF_ICE_BEAM)
                                            ProjectileChargedIceBeamHittingSprite(pSprite, projY, projX, 0x10, PE_HITTING_SOMETHING_WITH_FULL_BEAM_NO_PLASMA);
                                        else
                                            ProjectileNonIceChargedHitSprite(pSprite, projY, projX, 0xC, PE_HITTING_SOMETHING_WITH_WAVE_BEAM);
                                    }
                                    pProj->status = 0x0;
                                    break;

                                case PROJ_TYPE_CHARGED_PLASMA_BEAM:
                                    if (pEquipment->beamBombsActivation & BBF_LONG_BEAM)
                                    {
                                        if (pEquipment->beamBombsActivation & BBF_ICE_BEAM)
                                        {
                                            if (pEquipment->beamBombsActivation & BBF_WAVE_BEAM)
                                                ProjectileChargedIceBeamHittingSprite(pSprite, projY, projX, 0x18, PE_HITTING_SOMETHING_WITH_FULL_BEAM);
                                            else
                                                ProjectileChargedIceBeamHittingSprite(pSprite, projY, projX, 0x14, PE_HITTING_SOMETHING_WITH_FULL_BEAM);
                                        }
                                        else
                                        {
                                            if (pEquipment->beamBombsActivation & BBF_WAVE_BEAM)
                                                ProjectileNonIceChargedHitSprite(pSprite, projY, projX, 0x14, PE_HITTING_SOMETHING_WITH_PLASMA_BEAM);
                                            else
                                                ProjectileNonIceChargedHitSprite(pSprite, projY, projX, 0x10, PE_HITTING_SOMETHING_WITH_PLASMA_BEAM);
                                        }
                                    }
                                    else
                                    {
                                        if (pEquipment->beamBombsActivation & BBF_ICE_BEAM)
                                        {
                                            if (pEquipment->beamBombsActivation & BBF_WAVE_BEAM)
                                                ProjectileChargedIceBeamHittingSprite(pSprite, projY, projX, 0x14, PE_HITTING_SOMETHING_WITH_FULL_BEAM);
                                            else
                                                ProjectileChargedIceBeamHittingSprite(pSprite, projY, projX, 0x10, PE_HITTING_SOMETHING_WITH_FULL_BEAM);
                                        }
                                        else
                                        {
                                            if (pEquipment->beamBombsActivation & BBF_WAVE_BEAM)
                                                ProjectileNonIceChargedHitSprite(pSprite, projY, projX, 0x10, PE_HITTING_SOMETHING_WITH_PLASMA_BEAM);
                                            else
                                                ProjectileNonIceChargedHitSprite(pSprite, projY, projX, 0xC, PE_HITTING_SOMETHING_WITH_PLASMA_BEAM);
                                        }
                                    }
                                    break;

                                case PROJ_TYPE_CHARGED_PISTOL:
                                    if (pSprite->samusCollision == SSC_SPACE_PIRATE)
                                    {
                                        pSprite->standingOnSprite = FALSE;
                                        pSprite->freezeTimer = 0x3C;
                                        pSprite->paletteRow = 0x1;
                                        pSprite->absolutePaletteRow = 0x1;
                                        ParticleSet(projY, projX, PE_HITTING_SOMETHING_WITH_LONG_BEAM);
                                    }
                                    else
                                        ProjectileNonIceChargedHitSprite(pSprite, projY, projX, 0xC, PE_HITTING_SOMETHING_WITH_LONG_BEAM);
                                    pProj->status = 0x0;
                                    break;

                                case PROJ_TYPE_MISSILE:
                                    ProjectileMissileHitSprite(pSprite, pProj, projY, projX);
                                    break;

                                case PROJ_TYPE_SUPER_MISSILE:
                                    ProjectileSuperMissileHitSprite(pSprite, pProj, projY, projX);
                                    break;

                                case PROJ_TYPE_BOMB:
                                    ProjectileBombMissileHitSprite(pSprite, projY, projX);
                            }
                        }
                    }
                    pProj++;
                }
            }
            count++;
            pSprite = pSprite_next;
        }
        drawOrder = drawOrder_next;
    } while (drawOrder <= 0x10);*/
}

/**
 * 50370 | 30 | 
 * Gets the weakness for the sprite given in parameter
 * 
 * @param pSprite The sprite concerned
 * @return The weakness of the sprite
 */
u16 ProjectileGetSpriteWeakness(struct SpriteData* pSprite)
{
    if (pSprite->properties & SP_SECONDARY_SPRITE) // Check wheter secondary or primary
        return sPrimarySpriteStats[pSprite->spriteID][2]; // Offset 2 is weakness
    else
        return sSecondarySpriteStats[pSprite->spriteID][2];
}

/**
 * 503a0 | 84 | Handles the ice beam dealing damage to a sprite
 * 
 * @param pSprite The sprite concerned
 * @param damage Damage to inflict
 * @return The freeze timer
 */
u8 ProjectileIceBeamDealDamage(struct SpriteData* pSprite, u16 damage)
{
    u8 freeze_timer;

    freeze_timer = 0x0;
    if (pSprite->health > damage)
    {
        pSprite->health -= damage;
        freeze_timer = 0xF0;
    }
    else
    {
        pSprite->health = 0x0;
        pSprite->properties |= SP_DESTROYED;
        pSprite->freezeTimer = 0x0;
        pSprite->paletteRow = 0x0;
        if (pSprite->standingOnSprite != FALSE && gSamusData.standingStatus == STANDING_ENEMY)
        {
            gSamusData.standingStatus = STANDING_MIDAIR;
            pSprite->standingOnSprite = FALSE;
        }
        pSprite->pose = 0x62;
        pSprite->ignoreSamusCollisionTimer = 0x1;
    }

    pSprite->invicibilityStunFlashTimer = pSprite->invicibilityStunFlashTimer & 0x80 | 0x11;
    pSprite->properties |= SP_DAMAGED;
    return freeze_timer;
}

/**
 * 50424 | 88 | 
 * Handles a projectile dealing damage to a sprite
 * 
 * @param pSprite Sprite Data Pointer to the sprite concerned
 * @param damage Damage to inflict 
 * @return 1 if dead, 0 otherwise
 */
u8 ProjectileDealDamage(struct SpriteData* pSprite, u16 damage)
{
    u8 isDead;

    isDead = FALSE;
    if (pSprite->health > damage)
        pSprite->health -= damage;
    else
    {
        pSprite->health = 0x0;
        pSprite->properties |= SP_DESTROYED;
        pSprite->freezeTimer = 0x0;
        pSprite->paletteRow = 0x0;
        if (pSprite->standingOnSprite && gSamusData.standingStatus == STANDING_ENEMY)
        {
            gSamusData.standingStatus = STANDING_MIDAIR;
            pSprite->standingOnSprite = FALSE;
        }
        pSprite->pose = 0x62;
        pSprite->ignoreSamusCollisionTimer = 0x1;
        isDead++;
    }

    pSprite->invicibilityStunFlashTimer &= 0x80; 
    pSprite->invicibilityStunFlashTimer |= 0x11;
    pSprite->properties |= SP_DAMAGED;
    return isDead;
}

/**
 * 504ac | 20 | Handles a projectile hitting a sprite immune to projectiles
 * 
 * @param pSprite Sprite Data Pointer to the sprite concerned 
 * @return The parameter
 */
struct SpriteData* ProjectileHitSpriteImmuneToProjectiles(struct SpriteData* pSprite)
{
    u8 isft;

    isft = 0x2; // Needed to force a bcs
    if ((pSprite->invicibilityStunFlashTimer & 0x7F) < isft)
    {
        pSprite->invicibilityStunFlashTimer &= 0x80;
        pSprite->invicibilityStunFlashTimer |= 0x2;
    } // Return is implicit
}

/**
 * 504cc | 20 | Handles a projectile hitting a solid sprite
 * 
 * @param pSprite Sprite Data Pointer to the sprite concerned
 * @return The parameter
 */
struct SpriteData* ProjectileHitSolidSprite(struct SpriteData* pSprite)
{
    u8 isft;

    isft = 0x3; // Needed to force a bcs
    if ((pSprite->invicibilityStunFlashTimer & 0x7F) < isft)
    {
        pSprite->invicibilityStunFlashTimer &= 0x80;
        pSprite->invicibilityStunFlashTimer |= 0x3;
    } // Return is implicit
}

/**
 * 504ec | c0 | Handles a power bomb dealing damage to a sprite
 * 
 * @param pSprite Sprite Data Pointer to the sprite concerned 
 */
void ProjectilePowerBombDealDamage(struct SpriteData* pSprite)
{
    u8 isft;

    if (pSprite->properties & SP_IMMUNE_TO_PROJECTILES)
        ProjectileHitSpriteImmuneToProjectiles(pSprite);
    else
    {
        if (pSprite->properties & SP_SOLID_FOR_PROJECTILES)
            ProjectileHitSolidSprite(pSprite);
        else
        {
            if (ProjectileGetSpriteWeakness(pSprite) & WEAKNESS_POWER_BOMB)
            {
                if (pSprite->health > 0x32)
                    pSprite->health -= 0x32;
                else
                {
                    pSprite->health = 0x0;
                    pSprite->properties |= SP_DESTROYED;
                    pSprite->freezeTimer = 0x0;
                    pSprite->paletteRow = 0x0;
                    if (pSprite->standingOnSprite && gSamusData.standingStatus == STANDING_ENEMY)
                    {
                        gSamusData.standingStatus = STANDING_MIDAIR;
                        pSprite->standingOnSprite = FALSE;
                    }
                    pSprite->pose = 0x62;
                    pSprite->ignoreSamusCollisionTimer = 0x1;
                }
                isft = 0x11;
            }
            else
                isft = 0x3;

            if ((pSprite->invicibilityStunFlashTimer & 0x7F) < isft)
                pSprite->invicibilityStunFlashTimer = isft | 0x80;
            else
                pSprite->invicibilityStunFlashTimer |= 0x80;
            pSprite->properties |= SP_DAMAGED;
        }
    }
}

/**
 * 505ac | a8 | Handles a projectile dealing damage to a sprite
 * 
 * @param pSprite Sprite Data Pointer to the concerned sprite
 * @param yPosition Y Position of the projectile
 * @param xPosition X Position of the projectile
 * @param damage Damage inflicted
 * @param effect Particle effect to play
 */
void ProjectileHitSprite(struct SpriteData* pSprite, u16 yPosition, u16 xPosition, u16 damage, u8 effect)
{
    u16 weakness;

    if ((pSprite->properties & SP_SOLID_FOR_PROJECTILES) != 0x0)
    {
        ProjectileHitSolidSprite(pSprite);
        ParticleSet(yPosition, xPosition, effect);
    }
    else
    {
        if ((pSprite->properties & SP_IMMUNE_TO_PROJECTILES) != 0x0)
        {
            ProjectileHitSpriteImmuneToProjectiles(pSprite);
            ParticleSet(yPosition, xPosition, PE_HITTING_SOMETHING_INVINCIBLE);
        }
        else
        {
            weakness = ProjectileGetSpriteWeakness(pSprite);
            if ((weakness & WEAKNESS_BEAM_BOMBS) != 0x0)
            {
                ProjectileDealDamage(pSprite, damage);
                ParticleSet(yPosition, xPosition, effect);
            }
            else
            {
                ProjectileHitSolidSprite(pSprite);
                ParticleSet(yPosition, xPosition, PE_HITTING_SOMETHING_INVINCIBLE);
            }
        }
    }
}

/**
 * 50654 | a8 | 
 * Handles a charged beam (without ice) dealing damage to a sprite
 * 
 * @param pSprite Sprite Data Pointer to the sprite concerned
 * @param yPosition Y Position of the projectile
 * @param xPosition X Position of the projectile
 * @param damage Damage inflicted
 * @param effect Particle effect to play
 */
void ProjectileNonIceChargedHitSprite(struct SpriteData* pSprite, u16 yPosition, u16 xPosition, u16 damage, u8 effect)
{
    u16 weakness;

    if ((pSprite->properties & SP_SOLID_FOR_PROJECTILES) != 0x0)
    {
        ProjectileHitSolidSprite(pSprite);
        ParticleSet(yPosition, xPosition, effect);
    }
    else
    {
        if ((pSprite->properties & SP_IMMUNE_TO_PROJECTILES) != 0x0)
        {
            ProjectileHitSpriteImmuneToProjectiles(pSprite);
            ParticleSet(yPosition, xPosition, PE_HITTING_SOMETHING_INVINCIBLE);
        }
        else
        {
            weakness = ProjectileGetSpriteWeakness(pSprite);
            if ((weakness & (WEAKNESS_CHARGE_BEAM_PISTOL | WEAKNESS_BEAM_BOMBS)) != 0x0)
            {
                ProjectileDealDamage(pSprite, damage);
                ParticleSet(yPosition, xPosition, effect);
            }
            else
            {
                ProjectileHitSolidSprite(pSprite);
                ParticleSet(yPosition, xPosition, PE_HITTING_SOMETHING_INVINCIBLE);
            }
        }
    }
}

/**
 * 506fc | 28 | 
 * Freezes the sprite with the parameters
 * 
 * @param pSprite Sprite Data Pointer to the sprite concerned
 * @param freeze_timer Freeze timer to apply
 */
void ProjectileFreezeSprite(struct SpriteData* pSprite, u8 freeze_timer)
{
    pSprite->freezeTimer = freeze_timer;
    pSprite->paletteRow = 0xF - (pSprite->spritesetGFXSlot + pSprite->frozenPaletteRowOffset);
    SoundPlayNotAlreadyPlaying(0x140);
}

void ProjectileIceBeamHittingSprite(struct SpriteData* pSprite, u16 yPosition, u16 xPosition, u16 damage, u8 effect)
{

}

void ProjectileChargedIceBeamHittingSprite(struct SpriteData* pSprite, u16 yPosition, u16 xPosition, u16 damage, u8 effect)
{

}

/**
 * 50914 | 60 | 
 * Sets the projectile to a tumbling state (reserved for missile and super missile)
 * 
 * @param pSprite Sprite Data Pointer to the concerned sprite
 * @param pProj Projectile Data Pointer to the concerned projectile
 * @param type The type of the projectile
 */
void ProjectileStartTumblingMissile(struct SpriteData* pSprite, struct ProjectileData* pProj, u8 type)
{
    pProj->movementStage = 0x7; // Tumbling
    pProj->timer = 0x0;
    pProj->status &= ~PROJ_STATUS_CAN_AFFECT_ENVIRONMENT;
    pProj->status |= PROJ_STATUS_HIGH_PRIORITY;
    pProj->animationDurationCounter = 0x0;
    pProj->currentAnimationFrame = 0x0;
    if (pProj->xPosition > pSprite->xPosition)
        pProj->status |= PROJ_STATUS_XFLIP;
    else
        pProj->status &= ~PROJ_STATUS_XFLIP;

    if (type == PROJ_TYPE_SUPER_MISSILE)
    {
        pProj->pOam = super_missile_tumbling_oam; // Spinning/tumbling
        SoundStop(0xFC);
    }
    else
    {
        pProj->pOam = missile_tumbling_oam; // Spinning/tumbling
        SoundStop(0xF9);
    }
}

/**
 * 50974 | 68 | 
 * Sets the projectile to a tumbling state (reserved for missile and super missile, uses the current sprite)
 * 
 * @param pProj Projectile Data Pointer to the concerned projectile
 * @param type The type of the projectile
 */
void ProjectileStartTumblingMissileCurrentSprite(struct ProjectileData* pProj, u8 type)
{    
    pProj->movementStage = 0x7; // Tumbling
    pProj->timer = 0x0;
    pProj->status &= ~PROJ_STATUS_CAN_AFFECT_ENVIRONMENT;
    pProj->status |= PROJ_STATUS_HIGH_PRIORITY;
    pProj->animationDurationCounter = 0x0;
    pProj->currentAnimationFrame = 0x0;
    if (pProj->xPosition > gCurrentSprite.xPosition)
        pProj->status |= PROJ_STATUS_XFLIP;
    else
        pProj->status &= ~PROJ_STATUS_XFLIP;

    if (type == PROJ_TYPE_SUPER_MISSILE)
    {
        pProj->pOam = super_missile_tumbling_oam; // Spinning/tumbling
        SoundStop(0xFC);
    }
    else
    {
        pProj->pOam = missile_tumbling_oam; // Spinning/tumbling
        SoundStop(0xF9);
    }
}

void ProjectileMissileHitSprite(struct SpriteData* pSprite, struct ProjectileData* pProj, u16 yPosition, u16 xPosition)
{
    /*if (pSprite->properties & SP_SOLID_FOR_PROJECTILES)
    {
        ProjectileHitSolidSprite(pSprite);
        ParticleSet(yPosition, xPosition, PE_HITTING_SOMETHING_WITH_MISSILE);
        if (pProj->movementStage == 0x0)
            ProjectileDecrementMissileCounter(pProj);
        pProj->status = 0x0;
        return;
    }
    else
    {
        if (pSprite->properties & SP_IMMUNE_TO_PROJECTILES)
            ProjectileHitSpriteImmuneToProjectiles(pSprite);
        else
        {
            if (ProjectileGetSpriteWeakness(pSprite) & WEAKNESS_MISSILES)
            {
                ProjectileDealDamage(pSprite, 0x14);
                ParticleSet(yPosition, xPosition, PE_HITTING_SOMETHING_WITH_MISSILE);
                if (pProj->movementStage == 0x0)
                    ProjectileDecrementMissileCounter(pProj);
                pProj->status = 0x0;
                return;
            }
            else
            {
                ProjectileHitSolidSprite(pSprite);
            }
        }
        ParticleSet(yPosition, xPosition, PE_HITTING_SOMETHING_INVINCIBLE);
        ProjectileStartTumblingMissile(pSprite, pProj, PROJ_TYPE_MISSILE);
    }*/
}

void ProjectileSuperMissileHitSprite(struct SpriteData* pSprite, struct ProjectileData* pProj, u16 yPosition, u16 xPosition)
{

}

void ProjectileBombHitSprite(struct SpriteData* pSprite, u16 yPosition, u16 xPosition)
{
    if ((pSprite->properties & SP_IMMUNE_TO_PROJECTILES) != 0x0)
    {
        ProjectileHitSpriteImmuneToProjectiles(pSprite);
    }
    else
    {
        if ((pSprite->properties & SP_SOLID_FOR_PROJECTILES) != 0x0)
        {
            ProjectileHitSolidSprite(pSprite);
        }
        else
        {
            if ((ProjectileGetSpriteWeakness(pSprite) & WEAKNESS_BEAM_BOMBS) != 0x0)
                ProjectileDealDamage(pSprite, 0x8);
            else
                ProjectileHitSolidSprite(pSprite);
        }
    }
}

/**
 * 50b64 | f8 | Subroutine for the normal beam projectile, further detail is commented in the function
 * 
 * @param pProj Projectile Data Pointer to the concerned normal beam
 */
void ProjectileProcessNormalBeam(struct ProjectileData* pProj)
{
    /*
    Movement Stage :
      0x0 = Initialization
      0x1 = Spawn
      0x2 = Moving
    */
    if (pProj->movementStage == 0x2)
    {
        gCurrentClipdataAffectingAction = CAA_BEAM;
        if (ProjectileCheckVerticalCollisionAtPosition(pProj) != 0x0) // Check for collision
        {
            pProj->status = 0x0;
            ParticleSet(pProj->yPosition, pProj->xPosition, PE_HITTING_SOMETHING_WITH_BASE_BEAM);
            return;
        }
        else
        {
            ProjectileMove(pProj, 0x14);
        }
    }
    else if (pProj->movementStage == 0x1)
    {
        gCurrentClipdataAffectingAction = CAA_BEAM;
        if (ProjectileCheckVerticalCollisionAtPosition(pProj) != 0x0) // Check for collision
        {
            pProj->status = 0x0;
            ParticleSet(pProj->yPosition, pProj->xPosition, PE_HITTING_SOMETHING_WITH_BASE_BEAM);
            return;
        }
        else
        {
            pProj->movementStage++;
            ProjectileMove(pProj, 0x10);
        }
    }
    else
    {
        switch (pProj->direction) // Set OAM/Flip depending on direction
        {
            case ACD_DIAGONALLY_DOWN:
                pProj->status |= PROJ_STATUS_YFLIP;
            case ACD_DIAGONALLY_UP:
                pProj->pOam = normal_beam_oam_diagonal;
                break;
            case ACD_DOWN:
                pProj->status |= PROJ_STATUS_YFLIP;
            case ACD_UP:
                pProj->pOam = normal_beam_oam_up_down;
                break;
            default:
            case ACD_FORWARD:
                pProj->pOam = normal_beam_oam_forward;
        }

        pProj->draw_distance_offset = 0x40;
        pProj->status &= ~PROJ_STATUS_NOT_DRAWN;
        pProj->animationDurationCounter = 0x0;
        pProj->currentAnimationFrame = 0x0;
        pProj->hitboxTopOffset = -0x8;
        pProj->hitboxBottomOffset = 0x8;
        pProj->hitboxLeftOffset = -0x8;
        pProj->hitboxRightOffset = 0x8;
        pProj->movementStage = 0x1;
        ProjectileCheckHitBlock(pProj, CAA_BEAM, PE_HITTING_SOMETHING_WITH_BASE_BEAM);
    }

    pProj->timer++;
    if (pProj->timer > 0xC) // Check if projectile should be killed when going further enough
        pProj->status = 0x0;
}

/**
 * 50c5c | ec | Subroutine for the long beam projectile, further detail is commented in the function
 * 
 * @param pProj Projectile Data Pointer to the concerned long beam
 */
void ProjectileProcessLongBeam(struct ProjectileData* pProj)
{
    /*
    Movement Stage :
      0x0 = Initialization
      0x1 = Spawn
      0x2 = Moving
    */
   if (pProj->movementStage == 0x2)
   {
       gCurrentClipdataAffectingAction = CAA_BEAM;
       if (ProjectileCheckVerticalCollisionAtPosition(pProj) != 0x0) // Check for collision
       {
           pProj->status = 0x0;
           ParticleSet(pProj->yPosition, pProj->xPosition, PE_HITTING_SOMETHING_WITH_LONG_BEAM);
       }
       else
       {
           ProjectileMove(pProj, 0x18);
           pProj->timer++;
       }
   }
   else if (pProj->movementStage == 0x1)
   {
       gCurrentClipdataAffectingAction = CAA_BEAM;
       if (ProjectileCheckVerticalCollisionAtPosition(pProj) != 0x0) // Check for collision
       {
           pProj->status = 0x0;
           ParticleSet(pProj->yPosition, pProj->xPosition, PE_HITTING_SOMETHING_WITH_LONG_BEAM);
       }
       else
       {
           pProj->movementStage++;
           ProjectileMove(pProj, 0x10);
           pProj->timer++;
       }
   }
   else
   {
       switch (pProj->direction) // Set OAM/Flip depending on direction
       {
            case ACD_DIAGONALLY_DOWN:
                pProj->status |= PROJ_STATUS_YFLIP;
            case ACD_DIAGONALLY_UP:
                pProj->pOam = long_beam_oam_diagonal;
                break;
            case ACD_DOWN:
                pProj->status |= PROJ_STATUS_YFLIP;
            case ACD_UP:
                pProj->pOam = long_beam_oam_up_down;
                break;
            default:
            case ACD_FORWARD:
                pProj->pOam = long_beam_oam_forward;
       }

       pProj->draw_distance_offset = 0x40;
       pProj->status &= ~PROJ_STATUS_NOT_DRAWN;
       pProj->animationDurationCounter = 0x0;
       pProj->currentAnimationFrame = 0x0;
       pProj->hitboxTopOffset = -0xC;
       pProj->hitboxBottomOffset = 0xC;
       pProj->hitboxLeftOffset = -0xC;
       pProj->hitboxRightOffset = 0xC;
       pProj->movementStage = 0x1;
       ProjectileCheckHitBlock(pProj, CAA_BEAM, PE_HITTING_SOMETHING_WITH_LONG_BEAM);
       pProj->timer++;
   }
}

/**
 * 50d48 | 124 | Subroutine for the ice beam projectile, further detail is commented in the function
 * 
 * @param pProj Projectile Data Pointer to the concerned ice beam
 */
void ProjectileProcessIceBeam(struct ProjectileData* pProj)
{
    /*
    Movement Stage :
      0x0 = Initialization
      0x1 = Spawn
      0x2 = Moving
    */
    if (pProj->movementStage == 0x2)
    {
        gCurrentClipdataAffectingAction = CAA_BEAM;
        if (ProjectileCheckVerticalCollisionAtPosition(pProj) != 0x0) // Check for collision
        {
            pProj->status = 0x0;
            ParticleSet(pProj->yPosition, pProj->xPosition, PE_HITTING_SOMETHING_WITH_ICE_BEAM);
            return;
        }
        else
        {
            ProjectileMove(pProj, 0x1A);
            if (pProj->status & PROJ_STATUS_XFLIP)
                ProjectileSetTrail(pProj, PE_BEAM_TRAILING_LEFT, 0x3);
            else
                ProjectileSetTrail(pProj, PE_BEAM_TRAILING_RIGHT, 0x3);
        }
    }
    else if (pProj->movementStage == 0x1)
    {
        gCurrentClipdataAffectingAction = CAA_BEAM;
        if (ProjectileCheckVerticalCollisionAtPosition(pProj) != 0x0) // Check for collision
        {
            pProj->status = 0x0;
            ParticleSet(pProj->yPosition, pProj->xPosition, PE_HITTING_SOMETHING_WITH_ICE_BEAM);
            return;
        }
        else
        {
            pProj->movementStage++;
            ProjectileMove(pProj, 0x10);
        }
    }
    else
    {
        switch (pProj->direction) // Set OAM/Flip depending on direction
        {
            case ACD_DIAGONALLY_DOWN:
                pProj->status |= PROJ_STATUS_YFLIP;
            case ACD_DIAGONALLY_UP:
                pProj->pOam = ice_beam_oam_diagonal;
                break;
            case ACD_DOWN:
                pProj->status |= PROJ_STATUS_YFLIP;
            case ACD_UP:
                pProj->pOam = ice_beam_oam_up_down;
                break;
            default:
            case ACD_FORWARD:
                pProj->pOam = ice_beam_oam_forward;
        }

        pProj->draw_distance_offset = 0x40;
        pProj->status &= ~PROJ_STATUS_NOT_DRAWN;
        pProj->animationDurationCounter = 0x0;
        pProj->currentAnimationFrame = 0x0;
        pProj->hitboxTopOffset = -0x14;
        pProj->hitboxBottomOffset = 0x14;
        pProj->hitboxLeftOffset = -0x14;
        pProj->hitboxRightOffset = 0x14;
        pProj->movementStage = 0x1;
        ProjectileCheckHitBlock(pProj, CAA_BEAM, PE_HITTING_SOMETHING_WITH_ICE_BEAM);
    }

    pProj->timer++;
    if (!(gEquipment.beamBombsActivation & BBF_LONG_BEAM) && pProj->timer > 0xC)
        pProj->status = 0x0;
}

/**
 * @brief Handles the collision of the wave beam (bigger hitbox because of the wavy pattern)
 * 
 * @param pProj Projectile Data Pointer
 * @return u32 Numbers of block getting touched
 */
u32 ProjectileCheckWaveBeamHittingBlocks(struct ProjectileData* pProj)
{
    u16 yPosition;
    u16 xPosition;
    u8 nbrBlocks;
    u8 ccaa;

    nbrBlocks = 0x0;
    ccaa = CAA_BEAM;
    yPosition = pProj->yPosition;
    xPosition = pProj->xPosition;

    switch (pProj->direction)
    {
        case ACD_DIAGONALLY_DOWN:
            if (pProj->status & PROJ_STATUS_XFLIP)
            {
                gCurrentClipdataAffectingAction = ccaa;
                if (ProjectileCheckHittingSolidBlock(yPosition, xPosition))
                    nbrBlocks++;

                gCurrentClipdataAffectingAction = ccaa;
                if (ProjectileCheckHittingSolidBlock(yPosition - 0x2D, xPosition + 0x2D))
                    nbrBlocks++;

                gCurrentClipdataAffectingAction = ccaa;
                if (ProjectileCheckHittingSolidBlock(yPosition + 0x2D, xPosition - 0x2D))
                    nbrBlocks++;
            }
            else
            {
                gCurrentClipdataAffectingAction = ccaa;
                if (ProjectileCheckHittingSolidBlock(yPosition, xPosition))
                    nbrBlocks++;

                gCurrentClipdataAffectingAction = ccaa;
                if (ProjectileCheckHittingSolidBlock(yPosition - 0x2D, xPosition - 0x2D))
                    nbrBlocks++;

                gCurrentClipdataAffectingAction = ccaa;
                if (ProjectileCheckHittingSolidBlock(yPosition + 0x2D, xPosition + 0x2D))
                    nbrBlocks++;
            }
            break;

        case ACD_DIAGONALLY_UP:
            if (pProj->status & PROJ_STATUS_XFLIP)
            {
                gCurrentClipdataAffectingAction = ccaa;
                if (ProjectileCheckHittingSolidBlock(yPosition, xPosition))
                    nbrBlocks++;

                gCurrentClipdataAffectingAction = ccaa;
                if (ProjectileCheckHittingSolidBlock(yPosition - 0x2D, xPosition - 0x2D))
                    nbrBlocks++;

                gCurrentClipdataAffectingAction = ccaa;
                if (ProjectileCheckHittingSolidBlock(yPosition + 0x2D, xPosition + 0x2D))
                    nbrBlocks++;
            }
            else
            {
                gCurrentClipdataAffectingAction = ccaa;
                if (ProjectileCheckHittingSolidBlock(yPosition, xPosition))
                    nbrBlocks++;

                gCurrentClipdataAffectingAction = ccaa;
                if (ProjectileCheckHittingSolidBlock(yPosition - 0x2D, xPosition + 0x2D))
                    nbrBlocks++;

                gCurrentClipdataAffectingAction = ccaa;
                if (ProjectileCheckHittingSolidBlock(yPosition + 0x2D, xPosition - 0x2D))
                    nbrBlocks++;
            }
            break;

        case ACD_UP:
        case ACD_DOWN:
            gCurrentClipdataAffectingAction = ccaa;
            if (ProjectileCheckHittingSolidBlock(yPosition, xPosition))
                nbrBlocks++;

            gCurrentClipdataAffectingAction = ccaa;
            if (ProjectileCheckHittingSolidBlock(yPosition, xPosition + 0x40))
                nbrBlocks++;

            gCurrentClipdataAffectingAction = ccaa;
            if (ProjectileCheckHittingSolidBlock(yPosition, xPosition - 0x40))
                nbrBlocks++;
            break;

        case ACD_FORWARD:
        default:
            gCurrentClipdataAffectingAction = ccaa;
            if (ProjectileCheckHittingSolidBlock(yPosition, xPosition))
                nbrBlocks++;
            gCurrentClipdataAffectingAction = ccaa;
            if (ProjectileCheckHittingSolidBlock(yPosition + 0x40, xPosition))
                nbrBlocks++;
            gCurrentClipdataAffectingAction = ccaa;
            if (ProjectileCheckHittingSolidBlock(yPosition - 0x40, xPosition))
                nbrBlocks++;
            break;
    }

    return nbrBlocks;
}

/**
 * 51068 | 130 | Subroutine for the wave beam projectile, further detail is commented in the function
 * 
 * @param pProj Projectile Data Pointer to the concerned wave beam
 */
void ProjectileProcessWaveBeam(struct ProjectileData* pProj)
{
    ProjectileCheckWaveBeamHittingBlocks(pProj); // Check collision
    if (pProj->movementStage == 0x2)
    {
        ProjectileMove(pProj, 0x1C);
        if (gEquipment.beamBombsActivation & BBF_ICE_BEAM)
        {
            if (pProj->status & PROJ_STATUS_XFLIP)
                ProjectileSetTrail(pProj, PE_BEAM_TRAILING_LEFT, 0x3);
            else
                ProjectileSetTrail(pProj, PE_BEAM_TRAILING_RIGHT, 0x3);
        }
    }
    else if (pProj->movementStage == 0x1)
    {
        pProj->movementStage++;
        ProjectileMove(pProj, 0x10);
    }
    else
    {
        switch (pProj->direction) // Set OAM/Flip/Hitbox depending on direction
        {
            case ACD_DIAGONALLY_DOWN:
                pProj->status |= PROJ_STATUS_YFLIP;
            case ACD_DIAGONALLY_UP:
                pProj->pOam = wave_beam_oam_diagonal;
                pProj->hitboxTopOffset = -0x10;
                pProj->hitboxBottomOffset = 0x40;
                pProj->hitboxLeftOffset = -0x28;
                pProj->hitboxRightOffset = 0x28;
                break;
            case ACD_DOWN:
                pProj->status |= PROJ_STATUS_YFLIP;
            case ACD_UP:
                pProj->pOam = wave_beam_oam_up_down;
                pProj->hitboxTopOffset = -0x14;
                pProj->hitboxBottomOffset = 0x14;
                pProj->hitboxLeftOffset = -0x40;
                pProj->hitboxRightOffset = 0x40;
                break;
            default:
            case ACD_FORWARD:
                pProj->pOam = wave_beam_oam_forward;
                pProj->hitboxTopOffset = -0x40;
                pProj->hitboxBottomOffset = 0x40;
                pProj->hitboxLeftOffset = -0x14;
                pProj->hitboxRightOffset = 0x14;
        }

        pProj->draw_distance_offset = 0xA0;
        pProj->status &= ~PROJ_STATUS_NOT_DRAWN;
        pProj->animationDurationCounter = 0x0;
        pProj->currentAnimationFrame = 0x0;
        pProj->movementStage = 0x1;
    }

    pProj->timer++;
    if ((gEquipment.beamBombsActivation & BBF_LONG_BEAM) == 0x0 && pProj->timer > 0xC) // Check despawn
        pProj->status = 0x0;
}

/**
 * 51198 | 1bc | Subroutine for the plasma beam projectile, further detail is commented in the function
 * 
 * @param pProj Projectile Data Pointer to the concerned plasma beam
 */
void ProjectileProcessPlasmaBeam(struct ProjectileData* pProj)
{
    u8 has_wave;

    has_wave = gEquipment.beamBombsActivation & BBF_WAVE_BEAM;
    if (!has_wave)
    {
        gCurrentClipdataAffectingAction = CAA_BEAM;
        if (ProjectileCheckVerticalCollisionAtPosition(pProj) != 0x0)
        {
            pProj->status = 0x0;
            ParticleSet(pProj->yPosition, pProj->xPosition, PE_HITTING_SOMETHING_WITH_PLASMA_BEAM);
            return;
        }
        else
            ProjectileCheckWaveBeamHittingBlocks(pProj);
    }

    if (pProj->movementStage == 0x2)
    {
        ProjectileMove(pProj, 0x20);
        if (gEquipment.beamBombsActivation & BBF_ICE_BEAM)
        {
            if (pProj->status & PROJ_STATUS_XFLIP)
                ProjectileSetTrail(pProj, PE_BEAM_TRAILING_LEFT, 0x3);
            else
                ProjectileSetTrail(pProj, PE_BEAM_TRAILING_RIGHT, 0x3);
        }
    }
    else if (pProj->movementStage == 0x1)
    {
        pProj->movementStage++;
        ProjectileMove(pProj, 0x10);
    }
    else
    {
        switch (pProj->direction)
        {
            case ACD_DIAGONALLY_DOWN:
                pProj->status |= PROJ_STATUS_YFLIP;
            case ACD_DIAGONALLY_UP:
                if (has_wave)
                {
                    pProj->pOam = plasma_beam_wave_oam_diagonal;
                    pProj->hitboxTopOffset = -0x10;
                    pProj->hitboxBottomOffset = 0x40;
                    pProj->hitboxLeftOffset = -0x30;
                    pProj->hitboxRightOffset = 0x30;
                }
                else
                    pProj->pOam = plasma_beam_no_wave_oam_diagonal;
                break;

            case ACD_DOWN:
                pProj->status |= PROJ_STATUS_YFLIP;
            case ACD_UP:
                if (has_wave)
                {
                    pProj->pOam = plasma_beam_wave_oam_up_down;
                    pProj->hitboxTopOffset = -0x20;
                    pProj->hitboxBottomOffset = 0x20;
                    pProj->hitboxLeftOffset = -0x40;
                    pProj->hitboxRightOffset = 0x40;
                }
                else
                    pProj->pOam = plasma_beam_no_wave_oam_up_down;
                break;

            case ACD_FORWARD:
                if (has_wave)
                {
                    pProj->pOam = plasma_beam_wave_oam_forward;
                    pProj->hitboxTopOffset = -0x40;
                    pProj->hitboxBottomOffset = 0x40;
                    pProj->hitboxLeftOffset = -0x20;
                    pProj->hitboxRightOffset = 0x20;
                }
                else
                    pProj->pOam = plasma_beam_no_wave_oam_forward;
        }

        if (has_wave)
        {
            pProj->draw_distance_offset = 0xA0;
            pProj->status |= PROJ_STATUS_HIGH_PRIORITY;
        }
        else
        {
            pProj->draw_distance_offset = 0x50;
            pProj->hitboxTopOffset = -0x14;
            pProj->hitboxBottomOffset = 0x14;
            pProj->hitboxLeftOffset = -0x14;
            pProj->hitboxRightOffset = 0x14;
        }

        pProj->status &= ~PROJ_STATUS_NOT_DRAWN;
        pProj->animationDurationCounter = 0x0;
        pProj->currentAnimationFrame = 0x0;
        pProj->movementStage = 0x1;
    }

    pProj->timer++;
    if ((gEquipment.beamBombsActivation & BBF_LONG_BEAM) == 0x0 && pProj->timer > 0xC)
        pProj->status = 0x0;
}

/**
* 51354 | ec | Subroutine for the pistol projectile, further detail is commented in the function
*
* @param pProj Projectile Data Pointer to the concerned pistol
*/
void ProjectileProcessPistol(struct ProjectileData* pProj)
{
    /*
    Movement Stage :
      0x0 = Initialization
      0x1 = Spawn
      0x2 = Moving
    */
    if (pProj->movementStage == 0x2)
    {
        gCurrentClipdataAffectingAction = CAA_BOMB_PISTOL;
        if (ProjectileCheckVerticalCollisionAtPosition(pProj) != 0x0) // Check for collision
        {
            pProj->status = 0x0;
            ParticleSet(pProj->yPosition, pProj->xPosition, PE_HITTING_SOMETHING_WITH_BASE_BEAM);
        }
        else
        {
            ProjectileMove(pProj, 0x16);
            pProj->timer++;
        }
    }
    else if (pProj->movementStage == 0x1)
    {
        gCurrentClipdataAffectingAction = CAA_BOMB_PISTOL;
        if (ProjectileCheckVerticalCollisionAtPosition(pProj) != 0x0) // Check for collision
        {
            pProj->status = 0x0;
            ParticleSet(pProj->yPosition, pProj->xPosition, PE_HITTING_SOMETHING_WITH_BASE_BEAM);
        }
        else
        {
            pProj->movementStage++;
            ProjectileMove(pProj, 0x10);
            pProj->timer++;
        }
    }
    else
    {
        switch (pProj->direction) // Set OAM/Flip depending on direction
        {           
            case ACD_DIAGONALLY_DOWN:
                pProj->status |= PROJ_STATUS_YFLIP;
            case ACD_DIAGONALLY_UP:
                pProj->pOam = pistol_oam_diagonal;
                break;
            case ACD_DOWN:
                pProj->status |= PROJ_STATUS_YFLIP;
            case ACD_UP:
                pProj->pOam = pistol_oam_up_down;
                break;
            default:
            case ACD_FORWARD:
                pProj->pOam = pistol_oam_forward;
        }

        pProj->draw_distance_offset = 0x40;
        pProj->status &= ~PROJ_STATUS_NOT_DRAWN;
        pProj->animationDurationCounter = 0x0;
        pProj->currentAnimationFrame = 0x0;
        pProj->hitboxTopOffset = -0x4;
        pProj->hitboxBottomOffset = 0x4;
        pProj->hitboxLeftOffset = -0x4;
        pProj->hitboxRightOffset = 0x4;
        pProj->movementStage = 0x1;
        ProjectileCheckHitBlock(pProj, CAA_BOMB_PISTOL, PE_HITTING_SOMETHING_WITH_BASE_BEAM);
        pProj->timer++;
    }
}

void ProjectileProcessChargedNormalBeam(struct ProjectileData* pProj)
{

}

void ProjectileProcessChargedLongBeam(struct ProjectileData* pProj)
{

}

void ProjectileProcessChargedIceBeam(struct ProjectileData* pProj)
{

}

void ProjectileProcessChargedWaveBeam(struct ProjectileData* pProj)
{

}

void ProjectileProcessChargedPlasmaBeam(struct ProjectileData* pProj)
{

}

/**
 * 51a7c | f8 | Subroutine for the charged pistol projectile, further detail is commented in the function
 * 
 * @param pProj Projectile Data Pointer to the concerned charged pistol
 */
void ProjectileProcessChargedPistol(struct ProjectileData* pProj)
{
    /*
    Movement Stage :
      0x0 = Initialization
      0x1 = Spawn
      0x2 = Moving
    */
    if (pProj->movementStage == 0x2)
    {
        gCurrentClipdataAffectingAction = CAA_BOMB_PISTOL;
        if (ProjectileCheckVerticalCollisionAtPosition(pProj) != 0x0) // Check for collision
        {
            pProj->status = 0x0;
            ParticleSet(pProj->yPosition, pProj->xPosition, PE_HITTING_SOMETHING_WITH_LONG_BEAM);
        }
        else
        {
            ProjectileMove(pProj, 0x16);
            ProjectileSetTrail(pProj, PE_CHARGED_PISTOL_TRAIL, 0x7);
            pProj->timer++;
        }
    }
    else if (pProj->movementStage == 0x1)
    {
        gCurrentClipdataAffectingAction = CAA_BOMB_PISTOL;
        if (ProjectileCheckVerticalCollisionAtPosition(pProj) != 0x0) // Check for collision
        {
            pProj->status = 0x0;
            ParticleSet(pProj->yPosition, pProj->xPosition, PE_HITTING_SOMETHING_WITH_LONG_BEAM);
        }
        else
        {
            pProj->movementStage++;
            ProjectileMove(pProj, 0x10);
            pProj->timer++;
        }
    }
    else
    {
        switch (pProj->direction) // Set OAM/Flip depending on direction
        {           
            case ACD_DIAGONALLY_DOWN:
                pProj->status |= PROJ_STATUS_YFLIP;
            case ACD_DIAGONALLY_UP:
                pProj->pOam = charged_pistol_oam_diagonal;
                break;
            case ACD_DOWN:
                pProj->status |= PROJ_STATUS_YFLIP;
            case ACD_UP:
                pProj->pOam = charged_pistol_oam_up_down;
                break;
            default:
            case ACD_FORWARD:
                pProj->pOam = charged_pistol_oam_forward;
        }

        pProj->draw_distance_offset = 0x80;
        pProj->status &= ~PROJ_STATUS_NOT_DRAWN;
        pProj->animationDurationCounter = 0x0;
        pProj->currentAnimationFrame = 0x0;
        pProj->hitboxTopOffset = -0xC;
        pProj->hitboxBottomOffset = 0xC;
        pProj->hitboxLeftOffset = -0xC;
        pProj->hitboxRightOffset = 0xC;
        pProj->movementStage = 0x1;
        ProjectileCheckHitBlock(pProj, CAA_BOMB_PISTOL, PE_HITTING_SOMETHING_WITH_LONG_BEAM);
        pProj->timer++;
    }
}

void ProjectileDecrementMissileCounter(struct ProjectileData* pProj)
{
    if (gEquipment.currentMissiles != 0x0)
    {
        gEquipment.currentMissiles--;
        if (gEquipment.currentMissiles == 0x0)
            gSamusWeaponInfo.weaponHighlighted ^= WH_MISSILE;
    }

    pProj->draw_distance_offset = 0x40;
    pProj->status &= 0xFB;
}

/**
* 51bac | 118 | Subroutine for the missile projectile, further detail is commented in the function
* @param pProj Projectile Data Pointer to the concerned missile
*/
void ProjectileProcessMissile(struct ProjectileData* pProj)
{
    /*
    Movement Stage :
      0x0 = Initialization
      0x1 = Spawn
      0x2 = Moving
      0x7 = Tumbling
    */
    if (pProj->movementStage == 0x2)
    {
        gCurrentClipdataAffectingAction = CAA_MISSILE;
        if (ProjectileCheckVerticalCollisionAtPosition(pProj) == 0x0) // Check for collision
        {
            ProjectileMove(pProj, pProj->timer + 0x8);
            if (pProj->timer < 0xC)
                pProj->timer++;
            ProjectileSetTrail(pProj, PE_MISSILE_TRAIL, 0x7);
        }
        else
        {
            pProj->status = 0x0;
            ParticleSet(pProj->yPosition, pProj->xPosition, PE_HITTING_SOMETHING_WITH_MISSILE);
        }
    }
    else if (pProj->movementStage == 0x1)
    {
        gCurrentClipdataAffectingAction = CAA_MISSILE;
        if (ProjectileCheckVerticalCollisionAtPosition(pProj) != 0x0) // Check for collision
        {
            pProj->status = 0x0;
            ParticleSet(pProj->yPosition, pProj->xPosition, PE_HITTING_SOMETHING_WITH_MISSILE);
        }
        else
        {
            pProj->movementStage++;
            ProjectileMove(pProj, 0x30);
        }
    }
    else if (pProj->movementStage == 0x0)
    {
        switch (pProj->direction) // Set OAM/Flip depending on direction
        {
            case ACD_DIAGONALLY_DOWN:
                pProj->status |= PROJ_STATUS_YFLIP;
            case ACD_DIAGONALLY_UP:
                pProj->pOam = missile_oam_diagonal;
                break;
            case ACD_DOWN:
                pProj->status |= PROJ_STATUS_YFLIP;
            case ACD_UP:
                pProj->pOam = missile_oam_up_down;
                break;
            default:
            case ACD_FORWARD:
                pProj->pOam = missile_oam_forward;
        }

        ProjectileDecrementMissileCounter(pProj);
        pProj->animationDurationCounter = 0x0;
        pProj->currentAnimationFrame = 0x0;
        pProj->hitboxTopOffset = -0x8;
        pProj->hitboxBottomOffset = 0x8;
        pProj->hitboxLeftOffset = -0x8;
        pProj->hitboxRightOffset = 0x8;
        pProj->movementStage++;
        ProjectileCheckHitBlock(pProj, CAA_MISSILE, PE_HITTING_SOMETHING_WITH_MISSILE);
    }
    else // When tumbling
    {
        if (pProj->status & PROJ_STATUS_NOT_DRAWN)
            ProjectileDecrementMissileCounter(pProj); // Not sure why this is here ?
        ProjectileMoveTumbling(pProj);
    }
}

void ProjectileDecrementSuperMissileCounter(struct ProjectileData* pProj)
{
    if (gEquipment.currentSuperMissiles != 0x0)
    {
        gEquipment.currentSuperMissiles--;
        if (gEquipment.currentSuperMissiles == 0x0)
            gSamusWeaponInfo.weaponHighlighted ^= WH_SUPER_MISSILE;
    }

    pProj->draw_distance_offset = 0x40;
    pProj->status &= 0xFB;
}

void ProjectileProcessSuperMissile(struct ProjectileData* pProj)
{
    /*
    Movement Stage :
      0x0 = Initialization
      0x1 = Spawn
      0x2 = Moving
      0x7 = Tumbling
    */
    if (pProj->movementStage == 0x2)
    {
        gCurrentClipdataAffectingAction = CAA_SUPER_MISSILE;
        if (ProjectileCheckVerticalCollisionAtPosition(pProj) == 0x0) // Check for collision
        {
            ProjectileMove(pProj, pProj->timer + 0xC);
            if (pProj->timer < 0x10)
                pProj->timer++;
            ProjectileSetTrail(pProj, PE_SUPER_MISSILE_TRAIL, 0x3);
        }
        else
        {
            pProj->status = 0x0;
            ParticleSet(pProj->yPosition, pProj->xPosition, PE_HITTING_SOMETHING_WITH_SUPER_MISSILE);
        }
    }
    else if (pProj->movementStage == 0x1)
    {
        gCurrentClipdataAffectingAction = CAA_SUPER_MISSILE;
        if (ProjectileCheckVerticalCollisionAtPosition(pProj) != 0x0) // Check for collision
        {
            pProj->status = 0x0;
            ParticleSet(pProj->yPosition, pProj->xPosition, PE_HITTING_SOMETHING_WITH_SUPER_MISSILE);
        }
        else
        {
            pProj->movementStage++;
            ProjectileMove(pProj, 0x30);
        }
    }
    else if (pProj->movementStage == 0x0)
    {
        switch (pProj->direction) // Set OAM/Flip depending on direction
        {
            case ACD_DIAGONALLY_DOWN:
                pProj->status |= PROJ_STATUS_YFLIP;
            case ACD_DIAGONALLY_UP:
                pProj->pOam = super_missile_oam_diagonal;
                break;
            case ACD_DOWN:
                pProj->status |= PROJ_STATUS_YFLIP;
            case ACD_UP:
                pProj->pOam = super_missile_oam_up_down;
                break;
            default:
            case ACD_FORWARD:
                pProj->pOam = super_missile_oam_forward;
        }

        ProjectileDecrementSuperMissileCounter(pProj);
        pProj->animationDurationCounter = 0x0;
        pProj->currentAnimationFrame = 0x0;
        pProj->hitboxTopOffset = -0xC;
        pProj->hitboxBottomOffset = 0xC;
        pProj->hitboxLeftOffset = -0xC;
        pProj->hitboxRightOffset = 0xC;
        pProj->movementStage++;
        ProjectileCheckHitBlock(pProj, CAA_SUPER_MISSILE, PE_HITTING_SOMETHING_WITH_SUPER_MISSILE);
    }
    else // When tumbling
    {
        if (pProj->status & PROJ_STATUS_NOT_DRAWN)
            ProjectileDecrementSuperMissileCounter(pProj); // Not sure why this is here ?
        ProjectileMoveTumbling(pProj);
    }
}

/**
 * 51e14 | b8 | Checks if samus is in place to be launched by the morph ball launcher, if yes sets pose to Delay before ballsparking 
 * 
 * @param pProj Projectile Data Pointer to the concerned bomb
 */
void ProjectileMorphballLauncherCheckLaunchSamus(struct ProjectileData* pProj)
{
    u16 samusY;
    u16 samusX;
    u16 samusTop;
    u16 samusBottom;
    u16 samusLeft;
    u16 samusRight;
    u16 projY;
    u16 projX;
    u16 projTop;
    u16 projBottom;
    u16 projLeft;
    u16 projRight;

    samusY = gSamusData.yPosition;
    samusX = gSamusData.xPosition;
    samusTop = samusY + gSamusPhysics.drawDistanceTopOffset;
    samusBottom = samusY + gSamusPhysics.drawDistanceBottomOffset;
    samusLeft = samusX + gSamusPhysics.drawDistanceLeftOffset;
    samusRight = samusX + gSamusPhysics.drawDistanceRightOffset;

    projY = pProj->yPosition;
    projX = pProj->xPosition;
    projTop = projY + pProj->hitboxTopOffset;
    projBottom = projY + pProj->hitboxBottomOffset;
    projLeft = projX + pProj->hitboxLeftOffset;
    projRight = projX + pProj->hitboxRightOffset;

    if (SpriteUtilCheckObjectsTouching(samusTop, samusBottom, samusLeft, samusRight, projTop, projBottom, projLeft, projRight) && gSamusData.invincibilityTimer != 0x0)
    {
        switch (gSamusData.pose)
        {
            case SPOSE_ROLLING:
            case SPOSE_MORPH_BALL:
                gSamusData.forcedMovement = FORCED_MOVEMENT_LAUNCHED_BY_CANNON;
                SamusSetPose(SPOSE_DELAY_BEFORE_BALLSPARKING);
        }
    }
}

void ProjectileCheckSamusBombBounce(struct ProjectileData* pProj)
{

}

/**
* 51ff8 | 1f8 | Subroutine for the bomb projectile, further detail is commented in the function
*
* @param pProj Projectile Data Pointer to the concerned bomb
*/
void ProjectileProcessBomb(struct ProjectileData* pProj)
{
    u32 timer;
    u32 yPosition;

    switch (pProj->movementStage)
    {
        case BOMB_STAGE_INIT:
            pProj->pOam = bomb_oam_normal; // Bomb spinning at normal speed
            pProj->animationDurationCounter = 0x0;
            pProj->currentAnimationFrame = 0x0;
            pProj->draw_distance_offset = 0x20;
            pProj->hitboxTopOffset = -0x3C;
            pProj->hitboxBottomOffset = 0x30;
            pProj->hitboxLeftOffset = -0x30;
            pProj->hitboxRightOffset = 0x30;
            pProj->status &= ~(PROJ_STATUS_NOT_DRAWN | PROJ_STATUS_XFLIP); // Clear Not Drawn and X Flip status, X Flip is cleared to make it always face the same way, cancelling the automatic X Flip if samus is facing right
            pProj->status |= PROJ_STATUS_HIGH_PRIORITY;
            pProj->timer = 0x10; // Timer before the bomb starts spinning faster
            pProj->movementStage++;
            SoundPlay(0xFE); // Placing bomb sound
            break;

        case BOMB_STAGE_EXPLODING:
            
            if (pProj->timer-- != 0x1)
            {
                if (pProj->timer == 0xF)
                {
                    gCurrentClipdataAffectingAction = CAA_BOMB_PISTOL;
                    yPosition = pProj->yPosition - 0x8;
                    ClipdataProcess(yPosition, pProj->xPosition); // Block center
                    ProjectileCheckSamusBombBounce(pProj); // Checks if samus can bounce
                    pProj->status &= ~PROJ_STATUS_CAN_AFFECT_ENVIRONMENT; // Clear Can Affect Environement status
                }
                else if (pProj->timer == 0xE)
                {
                    gCurrentClipdataAffectingAction = CAA_BOMB_PISTOL;
                    ClipdataProcess(pProj->yPosition + 0x38, pProj->xPosition); // Block bottom middle
                }
                else if (pProj->timer == 0xD)
                {
                    gCurrentClipdataAffectingAction = CAA_BOMB_PISTOL;
                    ClipdataProcess(pProj->yPosition - 0x8, pProj->xPosition + 0x30); // Block right middle
                }
                else if (pProj->timer == 0xC)
                {
                    gCurrentClipdataAffectingAction = CAA_BOMB_PISTOL;
                    ClipdataProcess(pProj->yPosition - 0x8, pProj->xPosition - 0x30); // Block left middle
                }
                else if (pProj->timer == 0xB)
                {
                    gCurrentClipdataAffectingAction = CAA_BOMB_PISTOL;
                    ClipdataProcess(pProj->yPosition + 0x38, pProj->xPosition + 0x24); // Block right bottom
                }
                else if (pProj->timer == 0xA)
                {
                    gCurrentClipdataAffectingAction = CAA_BOMB_PISTOL;
                    ClipdataProcess(pProj->yPosition + 0x38, pProj->xPosition - 0x24); // Block left bottom
                }
                else if (pProj->timer == 0x9)
                {
                    gCurrentClipdataAffectingAction = CAA_BOMB_PISTOL;
                    ClipdataProcess(pProj->yPosition - 0x48, pProj->xPosition); // Block top middle
                }
                else if (pProj->timer == 0x8)
                {
                    gCurrentClipdataAffectingAction = CAA_BOMB_PISTOL;
                    ClipdataProcess(pProj->yPosition - 0x48, pProj->xPosition + 0x24); // Block right top
                }
                else if (pProj->timer == 0x7)
                {
                    gCurrentClipdataAffectingAction = CAA_BOMB_PISTOL;
                    ClipdataProcess(pProj->yPosition - 0x48, pProj->xPosition - 0x24); // Block left top
                }
            }
            else
                pProj->status = 0x0;
            break;

        case BOMB_STAGE_PLACED_ON_LAUNCHER:
            pProj->pOam = bomb_oam_normal; // Bomb spinning at normal speed
            pProj->animationDurationCounter = 0x0;
            pProj->currentAnimationFrame = 0x0;
            pProj->timer = 0x10;
            pProj->movementStage++;
            break;

        case BOMB_STAGE_FIRST_SPIN:
        case BOMB_STAGE_FIRST_SPIN_ON_LAUNCHER:
            pProj->timer--;
            if (pProj->timer == 0x0)
            {
                pProj->pOam = bomb_oam_fast; // Bomb spinning fast
                pProj->animationDurationCounter = 0x0;
                pProj->currentAnimationFrame = 0x0;
                pProj->timer = 0x10;
                pProj->movementStage++;
            }
            break;

        case BOMB_STAGE_FAST_SPIN:
        case BOMB_STAGE_FAST_SPIN_ON_LAUNCHER:
            pProj->timer--;
            if (pProj->timer == 0x0)
            {
                pProj->timer = 0x10;
                pProj->movementStage++;
                pProj->status |= (PROJ_STATUS_NOT_DRAWN | PROJ_STATUS_CAN_AFFECT_ENVIRONMENT);
                ParticleSet(pProj->yPosition - 0x10, pProj->xPosition, PE_BOMB);
            }
            break;

        case BOMB_STAGE_EXPLODING_ON_LAUNCHER:
            ProjectileMorphballLauncherCheckLaunchSamus(pProj); // Calls the launching samus handler
            pProj->status = 0x0;
    }
}

/**
 * 521f0 | 4 | Empty function, purpose unknown (most likely a cancelled projectile)
 * 
 * @param pProj Projectile Data Pointer
 */
void ProjectileProcess_Empty(struct ProjectileData* pProj)
{
    return;
}

/**
* 521f4 | 114 | Subroutine for the power bomb projectile, further detail is commented in the function
* @param pProj Projectile Data Pointer to the concerned power bomb
*/
void ProjectileProcessPowerBomb(struct ProjectileData* pProj)
{
    /*
    Movement Stage :
      0x0 = Initialization
      0x1 = Check first timer ended (power bomb spinning at normal speed)
      0x2 = Check second timer ended and starts the explosion (power bomb spinning fast)
    */
    struct SpriteData* pSprite;
    u16 status;
    u8 isft;

    switch (pProj->movementStage)
    {
        case 0x0:
            if (gEquipment.currentPowerBombs != 0x0)
            {
                gEquipment.currentPowerBombs--;
                if (gEquipment.currentPowerBombs == 0x0)
                    gSamusWeaponInfo.weaponHighlighted ^= WH_POWER_BOMB;
            }
            pProj->pOam = power_bomb_oam_normal;
            pProj->animationDurationCounter = 0x0;
            pProj->currentAnimationFrame = 0x0;
            pProj->draw_distance_offset = 0x20;
            pProj->hitboxTopOffset = -0x10;
            pProj->hitboxBottomOffset = 0x10;
            pProj->hitboxLeftOffset = -0x10;
            pProj->hitboxRightOffset = 0x10;
            pProj->status &= ~(PROJ_STATUS_NOT_DRAWN | PROJ_STATUS_XFLIP);
            pProj->status |= PROJ_STATUS_HIGH_PRIORITY;
            pProj->timer = 0x36;
            pProj->movementStage++;

            pSprite = gSpriteData;
            while (pSprite < gSpriteData + 24)
            {
                if (pSprite->status & SPRITE_STATUS_EXISTS)
                    pSprite->invicibilityStunFlashTimer &= 0x7F;
                pSprite++;
            }
            SoundPlay(0x100);
            gCurrentPowerBomb.powerBombPlaced = TRUE;
            break;

        case 0x1:
            pProj->timer--;
            if (pProj->timer == 0x0)
            {
                pProj->pOam = power_bomb_oam_fast;
                pProj->animationDurationCounter = 0x0;
                pProj->currentAnimationFrame = 0x0;
                pProj->timer = 0x28;
                pProj->movementStage++;
            }
            break;

        case 0x2:
            if (gGameModeSub1 == SUB_GAME_MODE_PLAYING)
            {
                pProj->timer--;
                if (pProj->timer == 0x0)
                {
                    PowerBombExplosionStart(pProj->xPosition, pProj->yPosition, 0x0);
                    pProj->status = 0x0;
                }
            }
    }
}