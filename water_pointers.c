#include <n64.h>

// recheck pointers

int return_pointer(u16 argument)   /*  0x802D0C84, used for water boxes (and something else?)  */
{
    
    asm volatile("la $gp, _gp");

    u32 pointer;

    if (argument >= 0x1602)
    {
        switch (argument)
        {
            case 0x2202:
                pointer = 0x07038780;
                break;   
                
            case 0x2301:
                pointer = 0x0701fcb4;
                break;   
    
            case 0x2302:
                pointer = 0x0701fd00;
                break;   
    
            case 0x2401:
                pointer = 0x07011e08;
                break;   
    
            case 0x2601:
                pointer = 0x07006e6c;
                break;   
    
            case 0x3601:
                pointer = 0x07017124;
                break;   
                
        }
    }
    else if (argument >= 0x1103)
    {

        switch (argument)
        {
    
            case 0x1201:
                pointer = 0x0701d2cc;
                break;   
                
            case 0x1202:
                pointer = 0x0701d304;
                break; 
                
            case 0x1205:
                pointer = 0x0701139c;
                break; 
                
            case 0x1301:
                pointer = 0x0701e31c;
                break;   
    
            case 0x1302:
                pointer = 0x0701e39c;
                break; 
                
            case 0x1601:
                pointer = 0x07011738;
                break;   
                
        }
    }
    else if (argument >= 0x0702)
    {

        switch (argument)
        {
    
            case 0x0702:
                pointer = 0x0703b950;
                break;   
                
            case 0x0801:
                pointer = 0x07012778;
                break; 
                
            case 0x0851:
                pointer = 0x070127c8;
                break;   
    
            case 0x1001:
                pointer = 0x0701fa70;
                break; 
                
            case 0x1101:
                pointer = 0x07028748;
                break;   
                
            case 0x1102:
                pointer = 0x07028778;
                break;
        }
    }
    else
    {
        
        switch (argument)
        {
                
            case 0x0400:
                pointer = 0x07026e24;
                break;   
                
            case 0x0401:
                pointer = 0x07026e34;
                break; 
                
            case 0x0501:
                pointer = 0x07016708;
                break; 

            case 0x0600:
                pointer = 0x070890f0;
                break;   
                
            case 0x0612:
                pointer = 0x07089100;
                break;   
                
            case 0x0701:
                pointer = 0x0703b900;
                break;   
                
        }
         
    }

    return pointer;
}
