/**
 * @file    I2C.c
 * @brief   I2C Module Source File for this program 
 * @author  Mohammed Awwad
 * @date    10/7/2020
 * @version 1.0
 */
// -------------------- File Inclusions -------------------------------

#include "I2C.h"

//--------------------- Public Function Definitions ----------------

void I2C_Master_Init(void) 
{
    TRISC3 = 1;
    TRISC4 = 1;
    
    SSPCON2 = 0x00;
    SSPSTAT = 0x00;

    /* Enables the serial port and configures the SDA and SCL pins as the serial port pins*/
    SSPEN  = 1;

    /* I2C Master mode, clock = FOSC/(4 * (SSPADD + 1))*/
    SSPM3 = 1;
    SSPM2 = 0;
    SSPM1 = 0;
    SSPM0 = 0;

    /*Baud rate*/
    SSPADD = ((_XTAL_FREQ / 4) / I2C_BAUDRATE) - 1;
}

void I2C_Start(void) 
{
    I2C_Wait();
    /*Initiate Start condition on SDA and SCL pins. */
    SEN = 1;
}

void I2C_Stop(void) 
{
    I2C_Wait();
    /*Initiate Stop condition on SDA and SCL pins. */
    PEN = 1;
}

void I2C_Restart(void) 
{
    I2C_Wait();
    /*Initiate Repeated Start condition on SDA and SCL pins. */
    RSEN = 1;
}

void I2C_Wait(void) 
{
    while ((SSPSTAT & 0x04) || (SSPCON2 & 0x1F));
}


void I2C_NAck(void) 
{
    ACKDT = 1;
    I2C_Wait();
    ACKEN = 1;
}

uint8 I2C_Master_write_slave_address_with_write_req(uint8 address) 
{
    I2C_Wait();
    /*address + write bit(0)*/
    SSPBUF = (address << 1);
    /*Wait Until Completion Flag*/
    while(!SSPIF);
    /*Clear flag*/
    SSPIF = 0;
    return ACKSTAT;
}

uint8 I2C_Master_write_slave_address_with_read_req(uint8 address) 
{
    I2C_Wait();
    /*address + read bit(1)*/
    SSPBUF = ( (address << 1) | 1);
    /*Wait Until Completion Flag*/
    while(!SSPIF);
    /*Clear flag*/
    SSPIF = 0;
    return ACKSTAT;
}

uint8 I2C_Master_write_byte(uint8 data) 
{
    I2C_Wait();
    SSPBUF = data;
    /*Wait Until Completion Flag*/
    while(!SSPIF);
    /*Clear flag*/
    SSPIF = 0;
    return ACKSTAT;
}

uint8 I2C_Master_read_byte(void) 
{
    I2C_Wait();
    /*Enable & Start Receive*/
    RCEN = 1;
    /*Wait Until Completion Flag*/
    while(!SSPIF);
    /*Clear flag*/
    SSPIF = 0;
    I2C_Wait();
    return SSPBUF;
}