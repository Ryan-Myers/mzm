#ifndef SYSCALL_WRAPPERS_H
#define SYSCALL_WRAPPERS_H

#include "types.h"

void CallLZ77UncompVRAM(void *src, void *dst);
void CallLZ77UncompWRAM(void *src, void *dst);
void TestDivarmSqrt(void);
void CallSoundbias(void);
int CallMultiboot(void *mbp);
void CallVBlankIntrWait(void);

#endif /* SYSCALL_WRAPPERS_H */
