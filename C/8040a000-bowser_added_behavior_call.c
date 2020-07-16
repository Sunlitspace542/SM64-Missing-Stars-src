#include <n64.h>
#include "explode.h"


    struct object     **Obj                 = (void*)M64_CURR_OBJ_PTR;

void _start ( void )
{

    asm volatile("la $gp, _gp");

    struct object     **Obj                 = (void*)M64_CURR_OBJ_PTR;

    u32 *Hits   = (void*)0x80500000;
    u32 *BowserFlag = (void*)0x80500060;
    
    if (*Hits > 8)
    {
       if ( (*Obj)->action == 0x0e && *BowserFlag != 1) 
       {
            (*Obj)->action = 0x10;  // invisible
            *BowserFlag = 1;
       }
       else if (*BowserFlag == 1 && (*Obj)->action != 0x10)
       {
            (*Obj)->action = 0x07; // run after mario
            *BowserFlag = 0;
       }
       
    }
    
}
