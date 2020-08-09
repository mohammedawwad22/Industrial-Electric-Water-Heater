/** 
 * @file    Temp.h
 * @brief   Temperature Header File for this program 
 * @author  Mohammed Awwad
 * @date    10/7/2020
 * @version 1.0
 */
//--------------------- Header Guard -------------------------------

#ifndef Temp_H_
#define Temp_H_

// ------------------ File Inclusions -------------------------------

#include "ADC.h"
#include"EEPROM.h"
#include"Button.h"
#include "LED.h"
#include"Heater.h"
#include"Cooler.h"

// ------------------ Public Constant -------------------------------

#define NOT_WRITTEN_BEFOR (0xFF) /**< this constant used to check if there is stord ste point temperature */

//--------------------- Public Data Types --------------------------

typedef enum 
{
    Temp_Min_State,
    Temp_Set_Point_State,
    Temp_Max_State
}Temp_States_t;

// ------  Function Prototypes -------------------------------

/**
 * \b Brief: This is the Temperature initialization function to initialize ADC , Heater ,
 *        Cooler , EEPROM then check if the system has run never run run before initialize 
 *        set point temp by 60
 * @param void 
 * @return void 
 */
void Temp_Init(void);


/**
 * \b Brief: This is the Temperature Update Task to update temperature value every 1000ms 
 *        by using cooler and heater elements and check every change in temp at setting mode 
 *        write it at certain address at EEPROM
 * @param void 
 * @return void 
 */
void Temp_Update(void);


/**
 * \b Brief: This is the get Temperature Task to get sample of temperature every 100ms 
 *        and calculate the average to update temperature value in Temp_Update Function
 * @param void 
 * @return void 
 */
void Temp_Get(void);




#endif
//--------------------- End of File --------------------------------