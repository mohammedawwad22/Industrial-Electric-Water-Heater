/** 
 * @file    Button.c
 * @brief   Button Source File for this program 
 * @author  Mohammed Awwad
 * @date    10/7/2020
 * @version 1.0
 */ 

// ------------------ File Inclusions -------------------------------

#include "Button.h"

// ------ Public variable definitions --------------------------------

extern SSD_MODE_States_t      SSD_MODE_State;
SW_ON_OFF_States_t            SW_ON_OFF_State = OFF_WAIT;
System_States_t               System_State = System_OFF;


uint8 SW_UP_isPressed=0;
uint8 SW_DOWN_isPressed=0;

//--------------------- Public Function Definitions ----------------

void Button_Init(void)
{  	
    DIO_Set_Pin_Direction(SW_PORT,SW_ON_OFF_PIN,INPUT_PIN);  
    DIO_Set_Pin_Direction(SW_PORT,SW_DOWN_PIN,INPUT_PIN); 
    DIO_Set_Pin_Direction(SW_PORT,SW_UP_PIN,INPUT_PIN);
    
    // Set pins from 3 to 6 as output with initial value 0
    DIO_Set_Pin_Direction(SW_PORT,3,OUTPUT_PIN);
    DIO_Set_Pin_Direction(SW_PORT,4,OUTPUT_PIN);
    DIO_Set_Pin_Direction(SW_PORT,5,OUTPUT_PIN);
    DIO_Set_Pin_Direction(SW_PORT,6,OUTPUT_PIN);
   }


void Button_Update(void)
{
    switch (SW_ON_OFF_State)
    {
        case OFF_WAIT :
            System_State = System_OFF;
            if (DIO_Read_Pin_Value(SW_PORT,SW_ON_OFF_PIN) == IS_PRESSED)
            {
                SW_ON_OFF_State = ON;
            }
        break;
        case ON :
            System_State = System_OFF;
            if (DIO_Read_Pin_Value(SW_PORT,SW_ON_OFF_PIN) == IS_RELEASED)
            {
                SW_ON_OFF_State = ON_WAIT;           
            }
            
        break;
        case ON_WAIT :
            System_State = System_ON;
            if (DIO_Read_Pin_Value(SW_PORT,SW_ON_OFF_PIN) == IS_PRESSED)
            {
                SW_ON_OFF_State = OFF;
            }
             
        break;
         case OFF :
             System_State = System_ON;
               if (DIO_Read_Pin_Value(SW_PORT,SW_ON_OFF_PIN) == IS_RELEASED)
            {
                SW_ON_OFF_State = OFF_WAIT;           
            }
            
        break;     
    }
    
    if((System_State == System_ON ) && DIO_Read_Pin_Value(SW_PORT,SW_UP_PIN) == IS_PRESSED )
    {
        SSD_MODE_State = SSD_SETTING;
        SW_UP_isPressed=1;
    }
    else if((System_State == System_ON) && DIO_Read_Pin_Value(SW_PORT,SW_DOWN_PIN) == IS_PRESSED)
    {
        SSD_MODE_State = SSD_SETTING;
        SW_DOWN_isPressed=1;
    }
    else 
    {
        SW_DOWN_isPressed=0;
        SW_UP_isPressed=0;
    }

    
}


//--------------------- End of File --------------------------------