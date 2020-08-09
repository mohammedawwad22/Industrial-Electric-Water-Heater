/**
 * @file    ADC.c
 * @brief   ADC Module Source file for this program 
 * @author  Mohammed Awwad
 * @date    10/7/2020
 * @version 1.0
 */
// ------------------ File Inclusions -------------------------------

#include "ADC.h"

//--------------------- Public Function Definitions ----------------
void ADC_Init(void)
{
   TRISA=0x07;
   ADCON1=0x02;
   ADCON0 = 0x41;  // Turn ADC ON, Select AN0 Channel, ADC Clock = Fosc/8
  
}

uint16 ADC_ReadChannel(uint8 channel)
{
     switch(channel)
    {
      case 0:
        ADCON0=0x01;
        break;
      case 1:
        ADCON0=0x09;
        break;
      case 2:
        ADCON0=0x11;
        break;
    }   
   

    ADCON0bits.GO=1;
    while(ADCON0bits.GO == 1);

   return ((((unsigned int)ADRESH)<<2)|(ADRESL>>6));
}
//--------------------- End of File --------------------------------