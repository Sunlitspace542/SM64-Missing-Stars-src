/* 0x80406100 function: forces OBJ to use yoshi animations */

#include <n64.h>
#include <mario64.h>

    struct object     **Obj                 = (void*)M64_CURR_OBJ_PTR;

void _start (void)
{
     asm volatile("la $gp, _gp");
     
     (*Obj)->animation = SegmentedToVirtual (0x05023f34); // Yoshi walking
     (*Obj)->action 2; // start running right away, don't wait for Mario to get close
      
}
