#include <n64.h>
#include <explode.h>


/* 0x80408400 = controller for floor switch star on pre-volcano area */

    u32               *CurrentObject        = (void*)M64_CURR_OBJ_PTR;
    struct object     **Obj                 = (void*)M64_CURR_OBJ_PTR;
    struct mario_obj  *Mario                = (void*)M64_MARIO_OBJ_PTR;

void _start ( void )
{
    asm volatile("la $gp, _gp");
    
    u8 *DayNight = (void*)0x80400004;
    u8 CycleState = *DayNight;
    
    int stack; 
    u32 count = -2;
    u32 *star_flag = (void*)0x8040000C;
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
             if ( (*Obj)->action == 2) count++;
        }
        *CurrentObject = (*Obj)->next;
    }
        
    *CurrentObject = (void*)stack;

    if (count == 0 && *star_flag == 0)
    {   
        
        if (CycleState < 9 ) // star during day
        {
             // x ,z ,y 
            (*Obj)->x_pos = Mario->x_pos;
            (*Obj)->y_pos = Mario->y_pos;    
            (*Obj)->z_pos = Mario->z_pos;
            struct object *ChildObject = (void*)CreateStar(1000, 200, 200);
            ChildObject->behav_param2 = 0x03000000; // star #3
            *star_flag = 1;
            (*Obj)->active = 0;
        }
        else if (CycleState > 9 ) // boss fight during night!
        {
             // x ,z ,y 
            struct object *ChildObject = SpawnObj( (void*)(*Obj) , 0x56, 0x0E002F00);
            ChildObject->x_pos = Mario->x_pos + 250;
            ChildObject->y_pos = Mario->y_pos + 600;
            ChildObject->z_pos = Mario->z_pos + 250;
           
            *star_flag = 1;
            (*Obj)->active = 0;
        
        }
    
    }
 
}
