
#include <n64.h>
#include "explode.h"

    struct object     **Obj                 = (void*)M64_CURR_OBJ_PTR;
    u32               *CurrentObject        = (void*)M64_CURR_OBJ_PTR;
    struct mario_obj  *Mario                = (void*)M64_MARIO_OBJ_PTR;    

void _start ( void )
{
    asm volatile("la $gp, _gp");
    
    int pseudostack; 
    int i;
    int star_behav = SegmentedToVirtual(0x0E002EB0);
    u32 StarCount = -20;

    pseudostack = *CurrentObject;
    *CurrentObject = (void*)M64_FIRST_OBJ_STRUCT;

     for (i = 0; i < 240; i++)
     {          
         if ( (*Obj)->behavior_script_entry == star_behav && (*Obj)->active != 0)
         {
             StarCount++;
         }
         *CurrentObject = (*Obj)->next;
     }
         
    *CurrentObject = (void*)pseudostack;
    
    PrintXY(135, 40, "Collected:   of 20");
    PrintInt(148, 40, "%d", -StarCount);
    
    if (StarCount == -20)
    {
        (*Obj)->x_pos = Mario->x_pos;
        (*Obj)->y_pos = Mario->y_pos;
        (*Obj)->z_pos = Mario->z_pos;  
        CreateStar(-7375,400,2397);
        (*Obj)->active = 0;
        
        /* note:
        
        Since the CreateStar function creates a child object from the parent X,Y,Z position,
        it's important to copy the position from Mario so that it can be spawned correctly.
        It returns a pointer, so if you want further control over it you can do something
        like:
             
        struct object *ChildStar = CreateStar(x,y,z);
        ChildStar->offset = something;
                
        */
   }

}
