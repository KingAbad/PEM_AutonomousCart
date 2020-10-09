#include "project.h"  
#include <stdio.h>  
#include <stdlib.h>

short afstand = 0;



    
int main(void)  
{  
    CyGlobalIntEnable; /* Enable global interrupts. */  
    
    UART_Start();  
    PWM_Start(); 
    Timer_Start();
  
    PWM_WritePeriod(255);
    PWM_WriteCompare(127);
  
 
    char string[1];
    for(;;)
    {
          if(Echo_Read() == 1)
         {        
          afstand = (Timer_ReadCounter()/100);
          itoa(afstand,string,10);
          UART_UartPutString("Afstand in cm: ");
          UART_UartPutString(string);
          UART_UartPutString("\n\r");
          Timer_WriteCounter(0);
          CyDelay(500);
        }
              
         //CyBle_ProcessEvents();  /* Place your application code here.*/
    }  
      
}  