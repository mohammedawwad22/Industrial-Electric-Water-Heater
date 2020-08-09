/** 
 * @file    Timer.c
 * @brief   Timer Module Source File for this program 
 * @author  Mohammed Awwad
 * @date    10/7/2020
 * @version 1.0
 */
//--------------------- Header Guard -------------------------------

#include "Timer.h"

//--------------------- Public Function Definitions ----------------
void Timer1_CCP1_Init()
{
// -- [[ Configure Timer1 To Operate In Timer Mode ]] --
// Clear The Timer1 Register. To start counting from 0
  TMR1 = 0;
// Choose the local clock source (timer mode)
  TMR1CS = 0;
// Choose the desired prescaler ratio 2
  T1CKPS0 = 1;
  T1CKPS1 = 0;


  CCPR1=10000;
// CCP in Compare Mode, CCPx Pin Is Unchanged & Trigger Special Event
  CCP1CON =0x0B;
  TMR1ON = 1;   
}

void Timer1_CCP1_InterruptEnable()
{
// Enable CCP1 Interrupt
    CCP1IE = 1;
    PEIE = 1;
}

//--------------------- End of File --------------------------------