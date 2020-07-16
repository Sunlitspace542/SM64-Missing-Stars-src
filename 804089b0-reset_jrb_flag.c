#include <n64.h>
#include "explode.h"

void _start ( void )
{
    asm volatile("la $gp, _gp");
    u32 *flag = (void*)0x80400020;
    *flag = 0;   
 
}
