/** 
 * @file    SSD.c
 * @brief   7-Segment Display Source File for this program 
 * @author  Mohammed Awwad
 * @date    10/7/2020
 * @version 1.0
 */
// ------------------ File Inclusions -------------------------------
#include "SSD.h"

// ------ Public variable declarations -----------------------------

extern System_States_t System_State;
extern uint16 Temp;
extern uint16 Set_Point_Temp;
extern uint8 SW_UP_isPressed;
extern uint8 SW_DOWN_isPressed;

// ------ Private variables ----------------------------------------

uint8 digit0=1;
uint8 counter=0;
static uint8 flash_flag=0;
static uint8 flag_5s=0;
uint8 Temp_Updated=0;
uint8 KeepMeHere_flag=0;

Flash_State_t      Flash_State = SSD_OFF;
SSD_MODE_States_t  SSD_MODE_State = SSD_NORMAL;

//--------------------- Public Function Definitions ----------------

uint8 display7s(uint8 number)
{
  switch(number)
  {
    case 0:
      return 0x3F;
    case 1:
      return 0x06;
    case 2:
      return 0x5B;
    case 3:
      return 0x4F;
    case 4:
      return 0x66;
    case 5:
      return 0x6D;
    case 6:
      return 0x7D;
    case 7:
      return 0x07;
    case 8:
      return 0x7F;
    case 9:
      return 0x6F;
    default:
      return 0;
  }
}


void SSD_Init (void)
{
    DIO_Set_Port_Direction(SSD_CTR_PORT,0xC3);
    DIO_Set_Port_Value(SSD_CTR_PORT,0x30);
    DIO_Set_Port_Direction(SSD_DTA_PORT,OUTPUT_PORT);
    DIO_Set_Port_Value(SSD_DTA_PORT,LOW_PORT);
    
}

void SSD_Display_OFF(void)
{
    DIO_Set_Port_Value(SSD_CTR_PORT,LOW_PORT);
    SSD_MODE_State=SSD_NORMAL;
}
void SSD_Display_Current_Temp(void)
{
    if (digit0==1)
    {
        DIO_Set_Port_Value(SSD_CTR_PORT,DIGIT_1);
        DIO_Set_Port_Value(SSD_DTA_PORT,display7s(Temp/10));
        digit0=0;
    }
    else
    {
        DIO_Set_Port_Value(SSD_CTR_PORT,DIGIT_10);
        DIO_Set_Port_Value(SSD_DTA_PORT,display7s(Temp%10));
        digit0=1;
    }
}
void SSD_Display_Set_Point_Temp(void)
{
    if (digit0==1)
    {
        DIO_Set_Port_Value(SSD_CTR_PORT,DIGIT_1);
        DIO_Set_Port_Value(SSD_DTA_PORT,display7s(Set_Point_Temp/10));
        digit0=0;
    }
    else
    {
        DIO_Set_Port_Value(SSD_CTR_PORT,DIGIT_10);
        DIO_Set_Port_Value(SSD_DTA_PORT,display7s(Set_Point_Temp%10));
        digit0=1;
    }
}

void SSD_Flash(void)
{
    switch(Flash_State)
    {
        case SSD_OFF:
            DIO_Set_Port_Value(SSD_CTR_PORT,LOW_PORT);
            counter++;
            if (counter==25)
            {
                Flash_State=SSD_ON;
                counter=0;
                flag_5s++;
            }
                
        break;
        case SSD_ON:
            if(flag_5s==5)
            {
                SSD_MODE_State = SSD_NORMAL; 
                flag_5s=0;
            }
            if (digit0==1)
            {
                DIO_Set_Port_Value(SSD_CTR_PORT,DIGIT_1);
                DIO_Set_Port_Value(SSD_DTA_PORT,display7s(Set_Point_Temp/10));
                digit0=0;
            }
            else
            {
                DIO_Set_Port_Value(SSD_CTR_PORT,DIGIT_10);
                DIO_Set_Port_Value(SSD_DTA_PORT,display7s(Set_Point_Temp%10));
                digit0=1;
            }
            counter++;
            if (counter==25)
            {
                Flash_State=SSD_OFF;
                counter=0;
            }
        break;
                    
    }

   
}
void SSD_Update(void)
{
    if (System_State == System_ON)
    {  
        switch (SSD_MODE_State)
        {
            case SSD_NORMAL:
                if(Temp == Set_Point_Temp || KeepMeHere_flag == 1)
                {
                    KeepMeHere_flag=1;
                    SSD_Display_Set_Point_Temp();
                }
               else
               {
                    SSD_Display_Current_Temp();
               }
            break;
            case SSD_SETTING:
                 KeepMeHere_flag=0;
                    if (SW_UP_isPressed)
                    {
                        if (Set_Point_Temp<MAX_TEMP) 
                        {
                            Set_Point_Temp+=5;
                            Temp_Updated=1;
                            SW_UP_isPressed=0;
                            Flash_State=SSD_OFF;
                            counter=0;
                            flag_5s=0;
                        }
                        else 
                        {
                            Set_Point_Temp=MAX_TEMP;
                            SW_UP_isPressed=0;
                            Temp_Updated=0;
                            Flash_State=SSD_OFF;
                            counter=0;
                            flag_5s=0;
                        }
                    }
                    else if (SW_DOWN_isPressed)
                    {
                        if (Set_Point_Temp>MIN_TEMP)
                        {
                           Set_Point_Temp-=5;
                           Temp_Updated=1;
                           SW_DOWN_isPressed=0;
                           Flash_State=SSD_OFF;
                           counter=0;
                           flag_5s=0;
                        }
                    }
                    SSD_Flash();
            break;     
        }
    }
   else
   {
        SSD_Display_OFF();
   }
   
}
//--------------------- End of File --------------------------------