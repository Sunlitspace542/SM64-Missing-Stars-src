/************************************************
* Generic Header - Include this before anything *
************************************************/
#ifndef __N64_H
#define __N64_H

/* Standard definitions */
#define NULL (void*)0
typedef enum { FALSE, TRUE } bool;

/* Data types */
typedef unsigned long long 	u64;
typedef unsigned int 		u32;
typedef unsigned short 		u16;
typedef unsigned char 		u8;
typedef long long 			s64;
typedef int 				s32;
typedef short 				s16;
typedef char 				s8;
typedef u32			 		size_t;
typedef float				f32;

/* Macros */
#define CHECK_BUTTONS(addr, buttons)		 (*((u16*)addr) == ((u16)(buttons)))
#define CHECK_BUTTONS_LENIENT(addr, buttons) (*((u16*)addr) & ((u16)(buttons)))

/* Controller input values */
enum
{
	BUTTON_C_RIGHT = 0x0001,
	BUTTON_C_LEFT  = 0x0002,
	BUTTON_C_DOWN  = 0x0004,
	BUTTON_C_UP    = 0x0008,
	BUTTON_R       = 0x0010,
	BUTTON_L       = 0x0020,
	BUTTON_D_RIGHT = 0x0100,
	BUTTON_D_LEFT  = 0x0200,
	BUTTON_D_DOWN  = 0x0400,
	BUTTON_D_UP    = 0x0800,
	BUTTON_START   = 0x1000,
	BUTTON_Z       = 0x2000,
	BUTTON_B       = 0x4000,
	BUTTON_A       = 0x8000
};

void _start   ( void );

#endif
