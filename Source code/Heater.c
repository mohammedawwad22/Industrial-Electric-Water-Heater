/**
 * @file    Heater.c
 * @brief   Heater element Source file for this program 
 * @author  Mohammed Awwad
 * @date    10/7/2020
 * @version 1.0
 */

// ------------------ File Inclusions -------------------------------

#include"Heater.h"

//--------------------- Public Function Definitions ----------------


void Heater_OFF(void)
{
    DIO_Set_Pin_Value(HEATER_PORT,HEATER_PIN,LOW_PIN);
}
void Heater_Init(void)
{
    DIO_Set_Pin_Direction(HEATER_PORT,HEATER_PIN,OUTPUT_PIN);
    Heater_OFF();
}
void Heater_ON(void)
{
    DIO_Set_Pin_Value(HEATER_PORT,HEATER_PIN,HIGH_PIN);
}
void Heater_Update(void)
{
    Heater_ON();
    Cooler_OFF();
    LED_TOGGLE();
}
//--------------------- End of File --------------------------------