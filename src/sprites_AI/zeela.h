#ifndef ZEELA_AI_H
#define ZEELA_AI_H

#include "../types.h"

void ZeelaSpawnEyes(void);
u8 ZeelaCheckCollidingWithAir(void);
void ZeelaHitboxInit(void);
void ZeelaGFXInit(void);
void ZeelaNormalDirectionGFXInit(void);
void ZeelaInit(void);
void ZeelaCallGFXInit(void);
void ZeelaMove(void);
void ZeelaGFXRotationUpdate(void);
void ZeelaTurning(void);
void Zeela_Unused(void);
void ZeelaBackOnGround(void);
void ZeelaStartFalling(void);
void ZeelaFalling(void);
void ZeelaDeath(void);
void ZeelaEyesInit(void);
void ZeelaEyesMove(void);
void ZeelaEyesGroundCollision(void);
void ZeelaCheckExplosionAnimEnded(void);
void Zeela(void);
void ZeelaEyes(void);

#endif /* ZEELA_AI_H */