/**
 * @file    main.c
 * @brief   main Source File for this program 
 * @author  Mohammed Awwad
 * @date    10/7/2020
 * @version 1.0
 */

// ------------------ File Inclusions -------------------------------
#include "config.h"
#include "SSD.h"
#include "Scheduler.h"
#include "Temp.h"

// ------------------ Public Constant -------------------------------

#define _XTAL_FREQ 8000000

//--------------------- Public Function Definitions ----------------

void main(void)
{
	SCH_Init_T1();
	Button_Init();
    SSD_Init();
    Temp_Init();

	SCH_Add_Task(Button_Update, 0, 15);
    SCH_Add_Task(SSD_Update, 0, 1);
    SCH_Add_Task(Temp_Update, 0, 100);
    SCH_Add_Task(Temp_Get, 0, 10);
	SCH_Start();
	while(1)
	{
		SCH_Dispatch_Tasks();
	}
}

//--------------------- End of File --------------------------------