
#include <n64.h>
#include "explode.h"

    struct object     **Obj                 = (void*)M64_CURR_OBJ_PTR;

void _start ( void )
{
    u16 *NumStars = (void*)0x8033B21A;
    
    if ( (*NumStars) != 38)
    {
         (*Obj)->active = 0;
    }  
    
}
