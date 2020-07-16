
#include <n64.h>
#include "explode.h"

    struct object     **Obj                 = (void*)M64_CURR_OBJ_PTR;

void _start ( void )
{
    /* Peach */

    asm volatile("la $gp, _gp");
    
    u8 *DayNight = (void*)0x80400004;
    u16 *NumStars = (void*)0x8033B21A;
    
    
    int state = *DayNight;
    
    if (state == 2)
    {
        (*Obj)->behav_param = 0x52; /* story  */
        (*Obj)->x_pos = 5454;
        (*Obj)->z_pos = -520;
    } 
    else if (state == 4)  /* about star pieces */
    {
        (*Obj)->active = 0;
    } 
    else if (state == 6)
    {
        (*Obj)->active = 0;
    } 
    else if (state == 8)     /* It's getting late. */
    {
        (*Obj)->behav_param = 0x57;
        (*Obj)->x_pos = -7463;
        (*Obj)->z_pos = 5470;
    } 
    else if (state == 0)
    {
        (*Obj)->behav_param = 0x56;   /* Good morning, Mario! */
        (*Obj)->x_pos = -3050;
        (*Obj)->z_pos = 2345;
    } 
    else if (state > 9)
    {
      (*Obj)->active = 0;
    }
    
    if ( (*NumStars) == 38)
    {
        (*Obj)->behav_param = 153; 
        (*Obj)->x_pos = -4775;
        (*Obj)->z_pos = 3813;
        (*Obj)->active = 1;
    }  
    

    
}
