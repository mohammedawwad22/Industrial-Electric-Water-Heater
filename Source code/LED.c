/**
 * @file    LED.c
 * @brief   LED Module Source File for this program 
 * @author  Mohammed Awwad
 * @date    10/7/2020
 * @version 1.0
 */
// ------------------ File Inclusions -------------------------------

#include"LED.h"

//--------------------- Public Function Definitions ----------------
void LED_OFF(void)
{

   DIO_Set_Pin_Value(LED_PORT,LED_PIN,LOW_PIN);
}
void LED_Init(void)
{

    DIO_Set_Pin_Direction(LED_PORT,LED_PIN,OUTPUT_PIN);
    LED_OFF();
}

void LED_TOGGLE(void)
{
    TOGGLE_BIT(PORTB,LED_PIN);
}



