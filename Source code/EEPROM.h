/**
 * @file    EEPROM.h
 * @brief   EEPROM Module header file for this program 
 * @author  Mohammed Awwad
 * @date    10/7/2020
 * @version 1.0
 */
//--------------------- Header Guard -------------------------------
#ifndef EEPROM_H_
#define EEPROM_H_

// ------------------ File Inclusions -------------------------------

#include "I2C.h"

// ------------------ Public Constant -------------------------------

#define EEPROM_ADDRESS 0x50  /**< EEPROM Address */

// ------  function prototypes -------------------------------
/**
 * \b Brief:  This is the Initialization of EEPROM function to Intialize ECU as Maseter 
 * @param  void 
 * @return void 
 */
void EEPROM_Init(void);


/**
 * \b Brief: This is the External EEPROM Write function to write a certain data at certain address of external EEPROM
 * @param address unsigned char address to select a certain address that you want to write at it 
 * @param data unsigned char data to write data at certain address  
 * @return void 
 */
void EEPROM_Write(uint8 address, uint8 data);


/**
 * \b Brief: This is the External EEPROM Write function to write a certain data at certain address of external EEPROM
 * @param address unsigned char address to select a certain address that you want to read from it 
 * @return unsigned char data at this certain address  
 */
uint8 EEPROM_Read(uint8 address);
#endif

//--------------------- End of File --------------------------------