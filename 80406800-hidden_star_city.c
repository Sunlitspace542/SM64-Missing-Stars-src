#include <n64.h>
#include <explode.h>


/* unused, I tried this to make the floor switch less CPU intensive, but 
it didn't work due to hardcoded behavior pointers */


    struct object     **Obj                 = (void*)M64_CURR_OBJ_PTR;


void _start ( void )
{
    asm volatile("la $gp, _gp");
    
    u8 *visible = (void*)0x804000a0;

    if (*visible == 1) (*Obj)->y_pos = 924;       // show star along with hidden blocks
    if (*visible == 0) (*Obj)->y_pos = -2000;     // hide star

 
}
