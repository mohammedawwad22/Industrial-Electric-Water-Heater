/** 
 * @file    Temp.c
 * @brief   Temperature Source File for this program 
 * @author  Mohammed Awwad
 * @date    10/7/2020
 * @version 1.0
 */
// ------------------ File Inclusions -------------------------------

#include"Temp.h"

// ---------------- Public variable definitions --------------------------------
extern System_States_t System_State;
extern uint8 Temp_Updated;

uint16 Temp; 
static uint16 Sum=0; 
uint8 Flag=0;
uint16 Set_Point_Temp=60;
uint8 Last_Set_Point_Temp;
static uint16 arr[10]={0};
static uint8 i=0;
Temp_States_t Temp_State = Temp_Min_State;

//--------------------- Public Function Definitions ----------------

void Temp_Init(void)
{
    ADC_Init();
    Heater_Init();
    Cooler_Init();
    LED_Init();
    EEPROM_Init();
    Last_Set_Point_Temp= EEPROM_Read(0x0000) ;
   if (Last_Set_Point_Temp != NOT_WRITTEN_BEFOR)
    {
        Set_Point_Temp = Last_Set_Point_Temp;
    }
}
void Temp_Get(void)
{
    if( System_State==System_ON)
    {
      arr[i]=(ADC_ReadChannel(2)/2);
      Sum+=arr[i];
       i++;
       if (i==10)
      {
         Temp=Sum/10;
         i=0;
         Sum=0;
       }
    }
}

void Temp_Update(void)
{
    if(System_State == System_ON )
    {
         if (Temp_Updated == 1)
       {
           
           EEPROM_Write(0x0000,Set_Point_Temp);
             Temp_Updated =0;
           
       }  
       switch (Temp_State)
       {  
           case Temp_Min_State:
               if (Flag == 0)
               {
                   Cooler_Update();
                   if (Temp < (Set_Point_Temp-5))
                   {
                        Heater_Update();
                       Flag =1;
                   }
               }
               if (Flag == 1)
               {
                   Temp_State=Temp_Set_Point_State;
               }
               
           break;
           case Temp_Set_Point_State:
               if (Flag==1)
               {
                   Temp_State=Temp_Max_State;
               }
               if (Flag == 0)
               {
                   Temp_State=Temp_Min_State;
               }
           break;
           case Temp_Max_State:
               if (Flag==1)
               {
                   Heater_Update();
                   if (Temp > (Set_Point_Temp+5))
                   {
                       Flag=0;
                        Cooler_Update();
                   }
               }
               if (Flag == 0)
               {
                   Temp_State=Temp_Set_Point_State;
               }
           break;
       } 
    }
    else
    {
        Heater_OFF();
        Cooler_OFF();
        LED_OFF();
    }
}

//--------------------- End of File --------------------------------