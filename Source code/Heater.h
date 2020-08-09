/**
 * @file    Heater.h
 * @brief   Heater Element Header File for this program 
 * @author  Mohammed Awwad
 * @date    10/7/2020
 * @version 1.0
 */

//--------------------- Header Guard -------------------------------

#ifndef Heater_H_
#define Heater_H_

// ------------------ File Inclusions -------------------------------

#include "DIO.h"
#include"Cooler.h"
#include"LED.h"


// ------------------ Public Constant -------------------------------

#define HEATER_PIN  5  /**< Heater Pin */
#define HEATER_PORT C  /**< Heater Port */

// ------------  function prototypes -------------------------------

/**
 * \b Brief: This is function to Turn Heater OFF
 * @param void 
 * @return void 
 */
void Heater_OFF(void);
/**
 * \b Brief: This is function to Set Heater port direction as output with OFF State 
 * @param void 
 * @return void 
 */
void Heater_Init(void);
/**
 * \b Brief: This is function to Turn Cooler ON
 * @param void 
 * @return void 
 */
void Heater_ON(void);
/**
 * \b Brief: This is function to Turn Heater ON and Turn Cooler OFF and Turn LED ON
 * @param void 
 * @return void 
 */
void Heater_Update(void);

#endif
//--------------------- End of File --------------------------------