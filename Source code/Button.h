/**
 * @file    Button.h
 * @brief   Button Header File for this program 
 * @author  Mohammed Awwad
 * @date    10/7/2020
 * @version 1.0
 */ 

//--------------------- Header Guard -------------------------------
#ifndef SWITCH_H_
#define SWITCH_H_

// ------------------ File Inclusions -------------------------------
#include"SSD.h"
#include "DIO.h"
// ------------------ Public Constant -------------------------------

#define SW_ON_OFF_PIN   1    /**<ON/OFF Button Pin */
#define SW_UP_PIN       2    /**<Up Button Pin */
#define SW_DOWN_PIN     0    /**<Down Button Pin */
#define SW_PORT         B    /**< Buttons Port */
#define IS_PRESSED      0x00 /**<button is pressed detector */
#define IS_RELEASED     0x01 /**<button is released detector */

// --------------------- Public Data Types --------------------------

typedef enum
{
    System_ON, 
    System_OFF 
}System_States_t;

typedef enum
{
    ON,
    ON_WAIT,
    OFF,
    OFF_WAIT
}SW_ON_OFF_States_t;

// ------ Public function prototypes -------------------------------

/**
 * \b Brief: This is the Button initialization  function to initialize ON/OFF button ,
 *           Up button ,Down button
 * @param void 
 * @return void 
 */
void Button_Init(void);
/**
 * \b Brief: This is the Button update Task to update system state by check ON/OFF button state
 *        and check Up button or Down button state if anyone is pressed change state of SSD form normal mode to setting mode
 * @param void 
 * @return void 
 */
void Button_Update(void);

#endif /* SWITCH_ONOFF_H_ */
//--------------------- End of File --------------------------------