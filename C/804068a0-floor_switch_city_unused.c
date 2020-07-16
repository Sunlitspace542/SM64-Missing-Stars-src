#include <n64.h>
#include <explode.h>

/* unused, I tried this to make the floor switch less CPU intensive, but 
it didn't work due to hardcoded behavior pointers */

    struct object     **Obj                 = (void*)M64_CURR_OBJ_PTR;


void _start ( void )
{
    asm volatile("la $gp, _gp");
    
    u8 *visible = (void*)0x804000a0;

    if ( (*Obj)->action == 2 )
    {
        *visible = 1;
    }
    else
    {
        *visible = 0;
    }
 
}
