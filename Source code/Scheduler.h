/**
 * @file    Scheduler.h
 * @brief   Scheduler Header File for this program 
 * @author  Mohammed Awwad
 * @date    10/7/2020
 * @version 1.0
 */
//--------------------- Header Guard -------------------------------
#ifndef SCHEDULER_H_
#define SCHEDULER_H_

// ------------------ File Inclusions -------------------------------

#include <xc.h> 
#include "Timer.h"

// ------------------ Public Constant -------------------------------
/*
 * The maximum number of tasks required at any one time during the execution of the program 
 * MUST BE ADJUSTED FOR EACH NEW PROJECT
 */
#define SCH_MAX_TASKS   (4)  /**< The maximum number of tasks required at any one time during the execution of the program */


// ------------- Public data type declarations ----------------------------

// Store in DATA area, if possible, for rapid access
// Total memory per task is 7 bytes
typedef struct
{
	void (*pTask)(void); /**< Pointer to the task (must be a 'void (void)' function) */

	uint16 Delay; /**< Delay (ticks) until the function will (next) be run */

	uint16 Period; /**< Interval (ticks) between subsequent runs. */

	uint8 RunMe; /**< Incremented (by scheduler) when task is due to execute*/
} sTask_t;

// ----------------  function prototypes -------------------------------

// Core scheduler functions

/**
 * \b Brief: This is the Scheduler initialization function.
 *        Prepares scheduler data structures and sets up timer interrupts at required rate.
 *        You must call this function before using the scheduler.
 * @param void 
 * @return void 
 */
void  SCH_Init_T1(void);



/**
 * \b Brief: This is the the scheduler ISR. 
 *        It is called at a rate determined by the timer settings in SCH_Init_T1().
 *        This version is triggered by Timer 1 interrupts:
 * @param void 
 * @return void 
 */
void  SCH_Update(void);

/**
 * \b Brief: This is the the SCH_Add_Task
 *        Causes a task (function) to be executed at regular intervals or after a user-defined delay
 * @param pointer to function - The name of the function which is to be scheduled.
 *                    NOTE: All scheduled functions must be 'void, void' - that is, they must take no parameters, and have  a void return type. 
 *              
 * @param DELAY  - The interval (TICKS) before the task is first executed
 * 
 * @param PERIOD - If 'PERIOD' is 0, the function is only called once, at the time determined by 'DELAY'.
 *                 If PERIOD is non-zero,then the function is called repeatedly at an interval determined by the value of PERIOD 
 *
 * @return Returns the position in the task array at which the task has been added.
 *         If the return value is SCH_MAX_TASKS then the task could not be added to the array (there was insufficient space).
 *         If the return value is < SCH_MAX_TASKS, then the task was added successfully.  
 */
uint8 SCH_Add_Task(void (*pFunction) (void), const uint16, const uint16);


/**
 * \b Brief: This is the 'dispatcher' function.  When a task (function) is due to run, SCH_Dispatch_Tasks() will run it.
 *        This function must be called (repeatedly) from the main loop.
 * @param void 
 * @return void 
 */
void  SCH_Dispatch_Tasks(void);


/**
 * \b Brief: This is the Scheduler start function. Starts the scheduler, by enabling interrupts.
 *       NOTE: Usually called after all regular tasks are added,to keep the tasks synchronized.
 *       NOTE: ONLY THE SCHEDULER INTERRUPT SHOULD BE ENABLED!!!
 * @param void 
 * @return void 
 */
void  SCH_Start(void);


/**
 * \b Brief: This is the Go to Sleep function. This scheduler enters 'idle mode' between clock ticks to save power.
 *        The next clock tick will return the processor to the normal operating state.
 *        Note: a slight performance improvement is possible if this function is implemented as a macro, or if the code here is simply 
 *              pasted into the 'dispatch' function.  
 *        *** ADAPT AS REQUIRED FOR YOUR HARDWARE ***
 * @param void 
 * @return void 
 */
void  SCH_Go_To_Sleep(void);



#endif

//--------------------- End of File --------------------------------