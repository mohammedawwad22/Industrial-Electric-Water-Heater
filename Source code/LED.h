/**
 * @file    LED.h
 * @brief   LED Module Header File for this program 
 * @author  Mohammed Awwad
 * @date    10/7/2020
 * @version 1.0
 */

//--------------------- Header Guard -------------------------------
#ifndef LED_H_
#define LED_H_
// ------------------ File Inclusions -------------------------------

#include "DIO.h"

// ------------------ Public Constant -------------------------------

#define LED_PIN  7  /**< LED Pin */
#define LED_PORT B  /**< LED Port */

// ------  function prototypes -------------------------------
/**
 * \b Brief: This is function to Turn LED OFF
 * @param void 
 * @return void 
 */
void LED_OFF(void);
/**
 * \b Brief: This is function to Set LED port direction as OUTPUT
 * @param void 
 * @return void 
 */
void LED_Init(void);
/**
 * \b Brief: This is function to toggle state of LED
 * @param void 
 * @return void 
 */
void LED_TOGGLE(void);

#endif

//--------------------- End of File --------------------------------