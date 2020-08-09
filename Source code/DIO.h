/**
 * @file    DIO.h
 * @brief   DIO Module Header File for this program 
 * @author  Mohammed Awwad
 * @date    10/7/2020
 * @version 1.0
 */

//--------------------- Header Guard -------------------------------
#ifndef DIO_H_
#define DIO_H_

// ------------------ File Inclusions -------------------------------
#include "std_types.h"
#include "common_macros.h"
#include <xc.h>

// ------------------ Public Constant -------------------------------
typedef enum {
	A,
	B,
	C,
	D,
    E
}PORTS_t;

#define OUTPUT_PORT 0x00  /**< Port is Output Direction */
#define INPUT_PORT  0xFF  /**< Port is Input Direction */

#define OUTPUT_PIN  0x00  /**< Pin is Output Direction */
#define INPUT_PIN   0x01  /**< Pin is Input Direction */

#define HIGH_PORT   0xFF  /**< Port is High Voltage */
#define LOW_PORT    0x00  /**< Port is Low Voltage */

#define HIGH_PIN    0x01  /**< Pin is High Voltage */
#define LOW_PIN     0x00  /**< Pin is Low Voltage */

// ------------------  function prototypes -------------------------------

/**
 * \b Brief: This is function to set certain port of ports (A,B,C,D,E) direction (OUTPUT , INPUT)
 * @param portNumber unsigned char portNumber to select port
 * @param direction unsigned char direction to select direction of port 
 * @return void 
 */
void DIO_Set_Port_Direction (uint8 portNumber, uint8 direction);


/**
 * \b Brief: This is function to set certain port of ports (A,B,C,D,E) value (LOW , HIGH , any value)
 * @param portNumber unsigned char portNumber to select port
 * @param value unsigned char direction to set value 
 * @return void 
 */
void DIO_Set_Port_Value (uint8 portNumber, uint8 value);


/**
 * \b Brief: This is function to select certain port of ports (A,B,C,D,E) to get the value
 * @param portNumber unsigned char portNumber to select port
 * @return unsigned char to get value of port  
 */
uint8 DIO_Read_Port_Value (uint8 portNumber);


/**
 * \b Brief: This is function to select certain pin of pins (0->7) of port of ports (A,B,C,D,E) to get the value
 * @param portNumber unsigned char portNumber to select port
 * @param index unsigned char index to select pin 
 * @return unsigned char to get value of pin  
 */
uint8 DIO_Read_Pin_Value (uint8 portNumber, uint8 index);


/**
 * \b Brief: This is function to select certain pin of pins (0->7) of port of ports (A,B,C,D,E) to set the value (LOW , HIGH , any value)
 * @param portNumber unsigned char portNumber to select port
 * @param index unsigned char index to select pin 
 * @param  value unsigned char value to value 
 * @return void 
 */
void DIO_Set_Pin_Value (uint8 portNumber, uint8 index, uint8 value);


/**
 * \b Brief: This is function to set certain pin of pins (0->7) of port of ports (A,B,C,D,E) direction (OUTPUT , INPUT)
 * @param portNumber unsigned char portNumber to select port
 * @param index unsigned char index to select pin 
 * @param direction unsigned char  direction to select direction of pin 
 * @return void 
 */
void DIO_Set_Pin_Direction (uint8 portNumber, uint8 index, uint8 direction);

#endif /* DIO_H_ */


