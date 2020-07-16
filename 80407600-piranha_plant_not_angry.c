
#include <n64.h>
#include "explode.h"

    struct object     **Obj                 = (void*)M64_CURR_OBJ_PTR;

void _start ( void )
{
    /* 0x80407200 = Piranha Plant (near house) */

    asm volatile("la $gp, _gp");
    
    u8 *DayNight = (void*)0x80400004;
    u16 *NumStars = (void*)0x8033B21A;
    
    int state = *DayNight;
    
    if (state == 2)
    {
        (*Obj)->behav_param = 34; 
        (*Obj)->x_pos = -4167;
        (*Obj)->z_pos = 753;
        
        if ( (*NumStars) > 4)
        {
            (*Obj)->behav_param = 33; 
        }
    } 
    else if (state == 4) 
    {
        (*Obj)->behav_param =  0x5b;
        (*Obj)->x_pos = 6562;
        (*Obj)->z_pos = 2472;
    } 
    else if (state == 6)
    {
         
         (*Obj)->active = 0;
         /* 
         (*Obj)->behav_param = 0x5C;
        (*Obj)->x_pos = -1198;
        (*Obj)->z_pos = -2003;
        */
    } 
    else if (state == 8)
    {
         (*Obj)->active = 0;
    } 
    else if (state == 0)
    {
        (*Obj)->behav_param = 0x5E;
        (*Obj)->x_pos = 3437;
        (*Obj)->z_pos = -6955;
    } 
    else if (state > 9)
    {
      (*Obj)->active = 0;
    }
    
    if ( (*NumStars) == 38)
    {
        (*Obj)->behav_param = 154; 
        (*Obj)->x_pos = -3582;
        (*Obj)->z_pos = 3738;
        (*Obj)->active = 1;  /* for nighttime */
    }  
    
}
