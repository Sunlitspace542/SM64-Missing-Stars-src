#include <n64.h>
#include "explode.h"

#define BOB_OMB               0x0009
#define CASTLE_GROUNDS        0x0010
#define INSIDE_CASTLE         0x0006
#define WHOMP                 0x0018
#define COOL_COOL_MOUNTAIN    0x0005
#define JOLLY_ROGER_BAY       0x000C
#define TALL_TALL_MOUNTAIN    0x0024
#define HAZY_MAZE             0x0007
#define PEACH_SLIDE           0x001B
#define FILE1                 0x8020770C
#define FILE2                 0x8020777C
#define FILE3                 0x802077EC
#define FILE4                 0x8020785C 

    u32               *CurrentObject        = (void*)M64_CURR_OBJ_PTR;
    struct object     **Obj                 = (void*)M64_CURR_OBJ_PTR;
    struct mario_obj  *Mario                = (void*)M64_MARIO_OBJ_PTR;

void _start ( void )
{
    /* Shows how many stars you have got in this area */

    asm volatile("la $gp, _gp");

    u16 *SaveFile = (void*)0x8032DDF4;  
    u16 Save = *SaveFile;
    
    u16 *CurrentLevel = (void*)0x8032DDF8;
    u16 Level = *CurrentLevel;
    
    u8* CurrentStars;
    u32 *End = 0x8050000c;
    
    u8 StarCount = 0;
    u8 numstars = 0;
    
    u8 DontShow = 0;
    
    int SaveAddress;
    
    switch (Save)
    {
        case 1:
             SaveAddress = FILE1;
             break;
        
        case 2:
             SaveAddress = FILE2;
             break;

        case 3:
             SaveAddress = FILE3;
             break;

        case 4:
             SaveAddress = FILE4;
             break;
             
        default:
             DontShow = 1;
             break;
     }
             
     Level = *CurrentLevel;        
     
     if (Level == BOB_OMB || Level == CASTLE_GROUNDS || Level == INSIDE_CASTLE) 
     {
         CurrentStars  = (void *)SaveAddress;
         numstars = 6;
     }
     else if (Level == WHOMP) 
     {
         CurrentStars = (void *)(SaveAddress + 1);
         numstars = 4;
     }
     else if (Level == JOLLY_ROGER_BAY) 
     {
         CurrentStars = (void *)(SaveAddress + 2);
         numstars = 5;
     }
     else if (Level == COOL_COOL_MOUNTAIN) 
     {
         CurrentStars = (void *)(SaveAddress + 3);
         numstars = 3;
     }    
     else if (Level == TALL_TALL_MOUNTAIN) 
     {
         CurrentStars = (void *)(SaveAddress + 11);
         numstars = 2;
     }    
     else if (Level == HAZY_MAZE) 
     {
         CurrentStars = (void *)(SaveAddress + 5);
         numstars = 3;
     }
     else
     {
         DontShow = 1;
     }
     
     if (*End == 1) DontShow = 1; // credits

    if (DontShow == 0)
    {
        unsigned int bitwise = *CurrentStars;
 
        if (bitwise & 1)  StarCount++;
        if (bitwise & 2)  StarCount++;
        if (bitwise & 4)  StarCount++;
        if (bitwise & 8)  StarCount++;
        if (bitwise & 16) StarCount++;
        if (bitwise & 32) StarCount++;
    }

    Level = *CurrentLevel;
    
    if (DontShow == 0)
    { 
        PrintXY(75, 20,"-*  of  ");
        PrintInt(55, 20, "%d", StarCount);
        PrintInt(105, 20, "%d", numstars);
    }
    
}
