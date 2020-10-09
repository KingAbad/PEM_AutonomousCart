/*******************************
 *   CODE BY: Abad Sethi       * 
 *                             *
 *  RFID reader with i2c LCD   *
 *                             *
 ******************************/

#include "project.h"
#include "RC522.h"
#include "LiquidCrystal_I2C.h"

uint32_t Addr = 0x27;

unsigned char status;

void Beep(uint16 Milliseconds)
{
	PWM_1_Start();
	CyDelay(Milliseconds);
	PWM_1_Stop();
}
void GreenLed(uint16 Milliseconds)
{
	PWM_2_Start();
	CyDelay(Milliseconds);
	PWM_2_Stop();
}

void GreenLedBlink()
{
	GreenLed(250);
    CyDelay(250);
    GreenLed(250);
    CyDelay(250);
    GreenLed(250);
    CyDelay(250);
    GreenLed(250);
    CyDelay(250);
}


int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    SPI_Start();
    I2C_Start();
    LiquidCrystal_I2C_init(Addr,16,2,0);
    PCD_Init();
    begin();
    //RED_Write(0U);
    
    //PWM_1_Start();
    //PWM_1_WriteCompare(5);
    //PWM_1_WriteCompare((int)PWM_1_ReadPeriod/2);
    
      //LCD_Position(0,0);  LCD_PrintString("Version: "); 
      //LCD_PrintHexUint8(PCD_ReadRegister(VersionReg));   // test PCD_ReadRegister()
    
        
    PCD_AntennaOn() ; PCD_ReadRegister(TxControlReg);   // for test PCD_WriteRegister()
    PCD_AntennaOff(); PCD_ReadRegister(TxControlReg);
    
    
    for(;;)
    {
        
    clear();
    LCD_print("READ YOUR CARD");
    CyDelay(1000);
    clear();
    CyDelay(500);
    PCD_Reset();
    PCD_Init();  
    PCD_WriteRegister(BitFramingReg,     0x07); //BitFraming

    PCD_WriteRegister(CommIEnReg,        0xF7);      //CommIEn
    PCD_ClearRegisterBitMask( ComIrqReg, 0x80);     // ComIrq
    PCD_SetRegisterBitMask( FIFOLevelReg,0x80);     //immediately clears the internal FIFO   buffer’s   and   pointers
    PCD_WriteRegister(CommandReg,        0x00);     // idle
    //fill Tx  buffer 
    PCD_WriteRegister( FIFODataReg,        0x26); 
    // end fill Tx  buffer 
    PCD_WriteRegister( CommandReg,        0x0C);    //send data, activate read
    PCD_SetRegisterBitMask( BitFramingReg,0x80);    //  buffer
    status=PCD_ReadRegister(ComIrqReg) & 0b0100000;
   
  
    
    // end   while
    if(status) {
        Beep(150);
        LCD_print("Verified user");
        GreenLed(2000);
        clear();
        LCD_print("Access granted");
        CyDelay(2000);
        clear();
        LCD_print("Welcome:");
        CyDelay(1400);
        setCursor(0,1);
        LCD_print("Abad Sethi");
        CyDelay(2000);
        clear();
        setCursor(0,0);
        LCD_print("Buggy starts in");
        CyDelay(1000);
        setCursor(0,1);
        LCD_print("3..");
        CyDelay(1000);
        LCD_print("2..");
        CyDelay(1000);
        LCD_print("1..");
        CyDelay(1000);
        clear();
        LCD_print("BUGGY STARTED");
        setCursor(0,1);
        LCD_print("SUCESSFULLY");
        GreenLedBlink();
        } 
    /*else{  
        LCD_print("OZI IS A LORD");
        BLUE_Write(1); }
    CyDelay(500);
    }*/
}
}
/* [] END OF FILE */
