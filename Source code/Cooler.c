/**
 * @file    Cooler.c
 * @brief   Cooler Element Source File for this program 
 * @author  Mohammed Awwad
 * @date    10/7/2020
 * @version 1.0
 */

// ------------------ File Inclusions -------------------------------

#include"Cooler.h"

//--------------------- Public Function Definitions ----------------
void Cooler_OFF(void)
{
     DIO_Set_Pin_Value(COOLER_PORT,COOLER_PIN,LOW_PIN);
}

void Cooler_Init(void)
{
     DIO_Set_Pin_Direction(COOLER_PORT,COOLER_PIN,OUTPUT_PIN);
  Cooler_OFF();

}

void Cooler_ON(void)
{
    DIO_Set_Pin_Value(COOLER_PORT,COOLER_PIN,HIGH_PIN);
}

void Cooler_Update(void)
{
    Cooler_ON();
    Heater_OFF();
    LED_OFF();
}
//--------------------- End of File --------------------------------