#include <n64.h>
#include "explode.h"

    struct object     **Obj                 = (void*)M64_CURR_OBJ_PTR;

void _start ( void )
{
    /* First Goomba */

    asm volatile("la $gp, _gp");
    
    u16 *NumStars = (void*)0x8033B21A;    
    u8 *DayNight = (void*)0x80400004;
    int state = *DayNight;
    
    if (state == 2)
    {
        (*Obj)->behav_param = 0x50;
        (*Obj)->x_pos = -6609;
        (*Obj)->z_pos = 3244;
    } 
    else if (state == 4)
    {
        (*Obj)->behav_param = 0x08;
        (*Obj)->x_pos = -5487;
        (*Obj)->z_pos = -1051;
    } 
    else if (state == 6)
    {
       (*Obj)->active = 0;
       /*
        (*Obj)->behav_param = 0x31;
        (*Obj)->x_pos = -860;
        (*Obj)->z_pos = -2458;
       */        
    } 
    else if (state == 8)
    {
        (*Obj)->active = 0;
    } 
    else if (state == 0)
    {
        (*Obj)->behav_param = 0x34;
        (*Obj)->x_pos = -1810;
        (*Obj)->z_pos = 6322;
    } 
    else if (state > 9)
    {
      (*Obj)->active = 0;
    }
    
    
    if ( (*NumStars) == 38)
    {
        (*Obj)->active = 0;
    }  

    

    
}
