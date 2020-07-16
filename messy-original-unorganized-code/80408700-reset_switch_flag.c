#include <n64.h>
#include <explode.h>


void _start ( void )
{
    asm volatile("la $gp, _gp");

    u32 *star_flag = 0x8040000C;
    
    *star_flag = 0; // reset flag

 
}
