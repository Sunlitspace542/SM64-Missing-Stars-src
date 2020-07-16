#include <n64.h>
#include <explode.h>

    u32               *CurrentObject        = (void*)M64_CURR_OBJ_PTR;
    struct object     **Obj                 = (void*)M64_CURR_OBJ_PTR;


void _start ( void )
{
    asm volatile("la $gp, _gp");

    int stack; 
    static int visible = 0;
    int i;
        
    stack = *CurrentObject;  /* Saving because this global variable will be messed up */    
    
    int col_switch = SegmentedToVirtual(0x0800C7A8);
    
    /* Preparing to traverse objects circular list */
    *CurrentObject = (void*)M64_FIRST_OBJ_STRUCT;

    /* Traverse all objects linked-list and checks if floor switch is pressed */
    for (i = 0; i < 240; i++)
    {          
        if ( (*Obj)->collision_ptr == col_switch )
        {
             if ( (*Obj)->action == 2 ) visible = 1;
             if ( (*Obj)->action == 0 ) visible = 0;
        }
        *CurrentObject = (*Obj)->next;
    }
        
    *CurrentObject = (void*)stack;  /* Back to star */

    if (visible == 1) (*Obj)->y_pos = 924;       // show star along with hidden blocks
    if (visible == 0) (*Obj)->y_pos = -2000;     // hide star

 
}
