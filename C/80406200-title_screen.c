
#include <n64.h>
#include <mario64.h>

void _start ( void )
{
    asm volatile("la $gp, _gp");
    
     /* note to myself: a static int won't work as a Gameshark code
     because it will get replaced everytime the Gameshark commit the
     code to memory. In Nemu, a good workaround is to enable the cheat
     code so that it gets to N64 RAM and them disabling it.
     */
    
    
    static int x1 = 150;
    static int x2 = 150;
    static int y1 = 180;
    static int y2 = 155;
    static int y3 = 155;
    static int y4 = 130;
    static int y5 = 130;
    static int y6 = 105;    
    
    /* horizontal */
    PrintXY(x1, 180,  "- - - - - - - - - -  ");
    
    PrintXY(150, 155, "   Super Mario 64    ");
    PrintXY(150, 130, "  The Missing Stars  ");
    
    /* vertical */
    PrintXY(150, y1,  "                    -");
    PrintXY(150, y2,  "                    -");    
    PrintXY(150, y5,  "                    -");    

    /* vertical */    
    PrintXY(150, y3,  "-                    ");
    PrintXY(150, y4,  "-                    ");    
    PrintXY(150, y6,  "-                    ");        
    
    /* horizontal */    
    PrintXY(x2, 105,  "  - - - - - - - - - -");
    
    x1++;
    x2--;
    y1--;
    y2--;
    y3++;
    y4++;
    y5--;    
    y6++;

    if (x1 == 150 + 25) x1 = 150;
    if (x2 == 150 - 25) x2 = 150;
    if (y1 == 180 - 25) y1 = 180;
    if (y2 == 155 - 25) y2 = 155;    
    if (y3 == 155 + 25) y3 = 155;
    if (y4 == 130 + 25) y4 = 130;
    if (y5 == 130 - 25) y5 = 130;
    if (y6 == 105 + 25) y6 = 105;
 
}
