/** 
 * @file    Timer.h
 * @brief   Timer Module Header File for this program 
 * @author  Mohammed Awwad
 * @date    10/7/2020
 * @version 1.0
 */

//--------------------- Header Guard -------------------------------

#ifndef TIMERS_H_
#define TIMERS_H_

// ------------------ File Inclusions -------------------------------

#include "std_types.h"
#include <xc.h>

// -----------------  function prototypes -------------------------------
/**
 * \b Brief: This is Timer 1 initialization  at CCP Mode 
 * @param void 
 * @return void 
 */
void Timer1_CCP1_Init(void);
/**
 * \b Brief: This is Timer 1 Interrupt enable at CCP Mode
 * @param void 
 * @return void 
 */
void Timer1_CCP1_InterruptEnable(void);

#endif /* TIMERS_H_ */
//--------------------- End of File --------------------------------