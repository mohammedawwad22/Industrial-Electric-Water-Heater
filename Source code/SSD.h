/**
 * @file    SSD.h
 * @brief   7-Segment Display Header File for this program 
 * @author  Mohammed Awwad
 * @date    10/7/2020
 * @version 1.0
 */
//--------------------- Header Guard -------------------------------
#ifndef SSD_H_
#define SSD_H_

// ------------------ File Inclusions -------------------------------

#include "EEPROM.h"
#include "Button.h"


// ------------------ Public Constant -------------------------------

#define SSD_CTR_PORT A      /**< SSD Control Port */
#define SSD_DTA_PORT D      /**< SSD Data Port */
#define DIGIT_1      0x10   /**< SSD Enable 1 digit */
#define DIGIT_10     0x20   /**< SSD Enable 10 digit */
#define MAX_TEMP     75     /**< Maximum temperature can be reach */
#define MIN_TEMP     35     /**< Minimum temperature can be reach */
//--------------------- Public Data Types --------------------------

typedef enum{
    SSD_OFF,
    SSD_ON
}Flash_State_t;

typedef enum
{
    SSD_NORMAL,
    SSD_SETTING
}SSD_MODE_States_t;

// ------  Functions Prototypes -------------------------------
/**
 * \b Brief: This is the Function to display number on 7 segment
 * @param nubmer unsigned char 
 * @return unsigned char 
 */
uint8 display7s(uint8 nubmer);
/**
 * \b Brief: This is the SSD initialization function to initialize the direction of SSD port
 * @param void 
 * @return void 
 */
void SSD_Init (void);
/**
 * \b Brief: This is the SSD Update Task to update the SSD Mode every 25 ms 
 * @param void 
 * @return void 
 */
void SSD_Update (void);
/**
 * \b Brief: This is the Function to blink set point temperature every 1 sec when SSD at SSD setting mode
 * @param void 
 * @return void 
 */
void SSD_Display_Temp(void);
/**
 * \b Brief: This is the Function to blink set point temperature every 1 sec when SSD at SSD setting mode
 * @param void 
 * @return void 
 */
void SSD_Flash(void);
/**
 * \b Brief: This is the Function to display set point temperature when current water temperature at set point interval
 * @param void 
 * @return void 
 */
void SSD_Display_Set_Point(void);



#endif

//--------------------- End of File --------------------------------