#include <n64.h>
#include "explode.h"

void _start ( void )
{
   
    asm volatile("la $gp, _gp");
    
    /* Levels shown during credits. Couldn't find a table which determines which levels/areas 
    are shown so this was my only option. */
    
    // whomp  -> bob/omb again
    u32 *WhompJump = (void*)SegmentedToVirtual(0x15000588);
    *WhompJump = 0x01200000;  
    WhompJump++;
    *WhompJump = 0x01235000;
    WhompJump++;
    *WhompJump = 0x0E0009F0;  
    
    // jolly roger bay
    
    u32 *JRBJump = (void*)SegmentedToVirtual(0x15000498);
    *JRBJump = 0x004ac4b0;  // jump to "Thank You" screen to avoid crashing the game
    JRBJump++;
    *JRBJump = 0x004ac570;
    JRBJump++;
    *JRBJump = 0x0E000000;  
    
    
    // hook

    // .ORG 802B35E4      ; ROM 0x6e5e4
    // JAL 0x80407c00
    // NOP

    
    
}
