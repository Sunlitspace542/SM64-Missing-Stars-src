#include <n64.h>
#include "explode.h"

void _start ( void )
{
     
    int i;     
    u32 *flag = (void*)0x80500000;

    asm volatile("la $gp, _gp");
    
    for (i = 0; i < 10; i++)
    {
       *flag = 0;  
        flag++;
    }

 
}
