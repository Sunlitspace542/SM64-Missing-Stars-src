#include <n64.h>
#include "explode.h"

    struct object     **Obj                 = (void*)M64_CURR_OBJ_PTR;

void _start ( void )
{
    asm volatile("la $gp, _gp");
    
    u8 *DayNight = (void*)0x80400004;
    
    if (*DayNight == 0 || *DayNight == 4 || *DayNight == 8)
    {
         (*Obj)->active = 0; // kill it during some parts of the day to avoid slowdowns
    } 
    
}
