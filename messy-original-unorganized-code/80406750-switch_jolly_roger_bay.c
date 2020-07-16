#include <n64.h>
#include <explode.h>

    struct object     **Obj                 = (void*)M64_CURR_OBJ_PTR;


void _start ( void )
{
    asm volatile("la $gp, _gp");
    
    u8 *switch_action = (void*)0x80400050;

    if ( (*Obj)->action == 2 ) *switch_action = 2;
    if ( (*Obj)->action != 2 ) *switch_action = 0;
 
}
