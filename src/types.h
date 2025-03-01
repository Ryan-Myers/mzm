#ifndef TYPES_H
#define TYPES_H

#define TRUE 1
#define FALSE 0
#define NULL ((void *)0)

typedef unsigned char u8;
typedef signed char i8;
typedef unsigned short u16;
typedef signed short i16;
typedef unsigned int u32;
typedef signed int i32;
typedef volatile unsigned char vu8;
typedef volatile signed char vi8;
typedef volatile unsigned short vu16;
typedef volatile signed short vi16;
typedef volatile unsigned int vu32;
typedef volatile signed int vi32;

#define BLOCK_SIZE 0x40
#define BLOCK_POSITION_FLAG (~BLOCK_SIZE + 1)
#define SUB_PIXEL_POSITION_FLAG (BLOCK_SIZE - 1)

struct RawCoordsX {
    u16 x;
    u16 y;
};

struct RawCoordsY {
    u16 y;
    u16 x;
};

typedef void (*Func_T)(void);

#endif /* TYPES_H */
