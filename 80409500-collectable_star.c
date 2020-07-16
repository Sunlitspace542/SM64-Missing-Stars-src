#include <n64.h>
#include "explode.h"

    struct object     **Obj                 = (void*)M64_CURR_OBJ_PTR;

void _start ( void )
{
    asm volatile("la $gp, _gp");
    
    if ( (*Obj)->distance_from_mario < 100 )
    {
         (*Obj)->active = 0;
          PlaySound(0x40140011);  // Possible improvement: find better sound
    }    

}
