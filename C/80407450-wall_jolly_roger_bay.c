#include <n64.h>
#include <explode.h>

/* works along with 80406750-switch_jolly_roger_bay.c function */

    struct object     **Obj                 = (void*)M64_CURR_OBJ_PTR;

void _start ( void )
{
    asm volatile("la $gp, _gp");
    
    u8 *switch_action = (void*)0x80400050;

    if ( *switch_action == 2 )
    {
        if ( (*Obj)->y_pos != -1200 )
        {
             (*Obj)->y_pos -= -1;
        }
    }
    else if ( *switch_action == 0 )
    {

        if ( (*Obj)->y_pos != -888 )
        {
             (*Obj)->y_pos += 1;
        }
         
    }

 
}
