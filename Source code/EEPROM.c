/** 
 * @file    EEPROM.c
 * @brief   EEPROM Module Source File for this program 
 * @author  Mohammed Awwad
 * @date    10/7/2020
 * @version 1.0
 */
// ------------------ File Inclusions -------------------------------

#include"EEPROM.h"

//--------------------- Public Function Definitions ----------------

void EEPROM_Init(void)
{
  I2C_Master_Init();  
}

void EEPROM_Write(uint8 address, uint8 data) 
{
    I2C_Start();
    while(I2C_Master_write_slave_address_with_write_req(EEPROM_ADDRESS))
    I2C_Restart();
    I2C_Master_write_byte((uint8) address);
    I2C_Master_write_byte(data);
    I2C_Stop();
}

uint8 EEPROM_Read(uint8 address)
{
    uint8 data;
    I2C_Start();
    while(I2C_Master_write_slave_address_with_write_req(EEPROM_ADDRESS))
    I2C_Restart();
    I2C_Master_write_byte((uint8) address);
    I2C_Restart();
    I2C_Master_write_slave_address_with_read_req(EEPROM_ADDRESS);
    data = I2C_Master_read_byte();
    I2C_NAck();
    I2C_Stop();
    return data;
}
//--------------------- End of File --------------------------------