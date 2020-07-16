#include <n64.h>
#include "explode.h"

    struct object     **Obj                 = (void*)M64_CURR_OBJ_PTR;
    u32               *CurrentObject        = (void*)M64_CURR_OBJ_PTR;

void _start ( void )
{
    asm volatile("la $gp, _gp");
    
    u8 *ObjectFlag = (void*)0x80400020;   // this could be changed to some unused variable in the object struct
    int pseudostack; 
    int i;
    u32 GoombaCount = -4;

    if (*ObjectFlag == 0)
    {
        (*Obj)->behav_param = 0x9e;  // message = asking for help
        
        if ( (*Obj)->distance_from_mario < 200 )
        {
            PrintXY(150, 130, "HELP");
        }
        
        pseudostack = *CurrentObject;
        int goomba_behav = SegmentedToVirtual(0x0E002EB0);
        *CurrentObject = (void*)M64_FIRST_OBJ_STRUCT;

        for (i = 0; i < 240; i++)
        {          
            if ( (*Obj)->behavior_script_entry == goomba_behav && (*Obj)->active != 0 && (*Obj)->action != 64 )
            {
                 GoombaCount++;
            }
            *CurrentObject = (*Obj)->next;
        }
        
        PrintInt(100, 100, "%d", GoombaCount);
            
        *CurrentObject = (void*)pseudostack;
        
        if (GoombaCount == -4)
        {
            *ObjectFlag = 1;
        }
        
    }
    else if (*ObjectFlag == 1 || *ObjectFlag == 2)
    {
        (*Obj)->behav_param = 0x9f;
        
        if ( (*Obj)->action == 3)  // if dialog is active
        {
            *ObjectFlag = 2; // set this so in the next run it will create a star
        }
        
        if ( (*Obj)->action == 0 && *ObjectFlag == 2) // dialog has ended
        {
            
            struct object *ChildObject = CreateStar(1000,2498,3315);
            ChildObject->behav_param2 = 0x02000000;  /* make it star #2 */
            
            *ObjectFlag = 3;
            
        }
    }
    else if (*ObjectFlag == 3)
    {
        (*Obj)->behav_param = 0xA0;  // another message after you've saved him
        *ObjectFlag = 4;
    }
    
}
