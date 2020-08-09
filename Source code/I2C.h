/**
 * @file    I2C.h
 * @brief   I2C Module Header File for this program 
 * @author  Mohammed Awwad
 * @date    10/7/2020
 * @version 1.0
 */
//--------------------- Header Guard -------------------------------
#ifndef I2C_H_
#define I2C_H_

// ------------------ File Inclusions -------------------------------

#include "std_types.h"
#include <xc.h>

// ------------------ Public Constant -------------------------------
#define SCL_PIN 3             /**< I2C Clock Pin */
#define SDA_PIN 4             /**< I2C Data Pin */
#define _XTAL_FREQ 8000000    /**< Clock Frequency */
#define I2C_BAUDRATE 9600    /**< I2C Baud Rate */

// ------  function prototypes -------------------------------
/**
 * \b Brief: This is the function to initialize ECU as Master Mode
 * @param void 
 * @return void 
 */
void I2C_Master_Init(void);


/**
 * \b Brief: This is the function to Start I2C communication protocol
 * @param void 
 * @return void 
 */
void I2C_Start(void);


/**
* \b Brief: This is the function to Stop I2C communication protocol
 * @param void 
 * @return void 
 */
void I2C_Stop(void);


/**
 * \b Brief: This is the function to Restart I2C communication protocol
 * @param void 
 * @return void 
 */
void I2C_Restart(void);



/**
 * \b Brief: This is the I2C wait function
 * @param void 
 * @return void 
 */
void I2C_Wait(void);


/**
 * \b Brief: This is the I2C not Ack function
 * @param void 
 * @return void 
 */
void I2C_NAck(void);

/**
 * \b Brief: This is function to Master write address byte with write request
 * @param address unsigned char address to select a certain address that you want to write at it
 * @return unsigned char  true when finished 
 */
uint8 I2C_Master_write_slave_address_with_write_req(uint8 address);


/**
 * \b Brief: This is function to Master write address byte with read request
 * @param address unsigned char address to select a certain address that you want to read at it
 * @return unsigned char true when finished
 */
uint8 I2C_Master_write_slave_address_with_read_req(uint8 address);


/**
 * \b Brief: This is function to Master write data byte
 * @param data unsigned char to write it  
 * @return unsigned char
 */
uint8 I2C_Master_write_byte(uint8 data);



/**
 * \b Brief: This is function to Master read data byte
 * @param void 
 * @return unsigned char data
 */
uint8 I2C_Master_read_byte(void);

#endif

//--------------------- End of File --------------------------------