/**
 * @file    Scheduler.c
 * @brief   Scheduler Source File for this program 
 * @author  Mohammed Awwad
 * @date    10/7/2020
 * @version 1.0
 */
// ------------------ File Inclusions -------------------------------
#include "Scheduler.h"
#include <xc.h>

// ------ Public variable definitions ------------------------------

// The array of tasks
sTask_t SCH_tasks_G[SCH_MAX_TASKS];

//--------------------- Public Function Definitions ----------------


void SCH_Init_T1(void)
{
	// Now set up Timer 1
	// 16-bit timer function with automatic reload
	// tick time = 1ms
	Timer1_CCP1_Init();
    Timer1_CCP1_InterruptEnable();

}

void SCH_Update(void) //interrupt INTERRUPT_Timer_1_CompareMatch  
   {
   uint8 Index;
 
   // NOTE: calculations are in *TICKS* (not milliseconds)
   for (Index = 0; Index < SCH_MAX_TASKS; Index++)
      {
      // Check if there is a task at this location
      if (SCH_tasks_G[Index].pTask)
         {
         if (SCH_tasks_G[Index].Delay == 0)
            {
            // The task is due to run
            SCH_tasks_G[Index].RunMe = 1;  // Set the run flag

            if (SCH_tasks_G[Index].Period)
               {
               // Schedule periodic tasks to run again
               SCH_tasks_G[Index].Delay = SCH_tasks_G[Index].Period;
               }
            }
         else
            {
            // Not yet ready to run: just decrement the delay 
            SCH_tasks_G[Index].Delay -= 1;
            }
         }         
      }
   }   
void __interrupt() ISR(void)
{
  if ( CCP1IF )
  {
    SCH_Update();
    CCP1IF  = 0;
  }
}

uint8 SCH_Add_Task(void ( * pFunction)(),const uint16 DELAY,const uint16 PERIOD)
{
	uint8 Index = 0;
	
	// First find a gap in the array (if there is one)
	while ((SCH_tasks_G[Index].pTask != 0) && (Index < SCH_MAX_TASKS))
	{
		Index++;
	}
	
	// If we're here, there is a space in the task array
	SCH_tasks_G[Index].pTask  = pFunction;
	
	SCH_tasks_G[Index].Delay  = DELAY;
	SCH_tasks_G[Index].Period = PERIOD;

	SCH_tasks_G[Index].RunMe  = 0;

	return Index; // return position of task (to allow later deletion)
}


void SCH_Dispatch_Tasks(void)
{
	uint8 Index;

	// Dispatches (runs) the next task (if one is ready)
	for (Index = 0; Index < SCH_MAX_TASKS; Index++)
	{
		if (SCH_tasks_G[Index].RunMe > 0)
		{
			(*SCH_tasks_G[Index].pTask)();  // Run the task

			SCH_tasks_G[Index].RunMe -= 1;   // Reset / reduce RunMe flag

			// Periodic tasks will automatically run again
		}
	}
	// The scheduler enters idle mode at this point
	SCH_Go_To_Sleep();
}


void SCH_Start(void) 
{
    GIE = 1;
}


void SCH_Go_To_Sleep(void)
{
    SLEEP();
}

//--------------------- End of File --------------------------------