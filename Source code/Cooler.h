/**
 * @file    Cooler.h
 * @brief   Cooler Element Header file for this program 
 * @author  Mohammed Awwad
 * @date    10/7/2020
 * @version 1.0
 */

//--------------------- Header Guard -------------------------------

#ifndef COOLER_H_
#define COOLER_H_

// ------------------ File Inclusions -------------------------------
#include "DIO.h"
#include "LED.h"
#include"Heater.h"

// ------------------ Public Constant -------------------------------

#define COOLER_PIN 2  /**< Cooler Pin */
#define COOLER_PORT C  /**< Cooler Port */

// ----------------  function prototypes -------------------------------
/**
 * \b Brief: This is function to Turn Cooler OFF
 * @param void 
 * @return void 
 */
void Cooler_OFF(void);
/**
 * \b Brief: This is function to Set Cooler port direction as output with OFF State  
 * @param void 
 * @return void 
 */
void Cooler_Init(void);
/**
 * \b Brief: This is function to Turn Cooler ON
 * @param void 
 * @return void 
 */
void Cooler_ON(void);
/**
 * \b Brief: This is function to Turn Cooler ON and Turn Heater OFF and Turn LED OFF
 * @param void 
 * @return void 
 */
void Cooler_Update(void);

#endif
//--------------------- End of File --------------------------------