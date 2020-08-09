/** 
 * @file    DIO.c
 * @brief   DIO Module Source File for this program 
 * @author  Mohammed Awwad
 * @date    10/7/2020
 * @version 1.0
 */
// ------------------ File Inclusions -------------------------------

#include "DIO.h"

//--------------------- Public Function Definitions ----------------

void DIO_Set_Port_Direction (uint8 portNumber, uint8 direction) 
{
	switch (portNumber) 
    {
        case 0:
            TRISA = direction;
        break;
        case 1:
            TRISB = direction;
        break;
        case 2:
            TRISC = direction;
		break;
        case 3:
            TRISD = direction;
		break;
        case 4:
            TRISE = direction;
		break;
	}
}


void DIO_Set_Port_Value (uint8 portNumber, uint8 value)
{
	switch (portNumber) 
    {
        case 0:
            PORTA = value;
        break;
        case 1:
            PORTB = value;
        break;
        case 2:
            PORTC = value;
        break;
        case 3:
            PORTD = value;
        break;
        case 4:
            PORTE = value;
        break;
	}
}

uint8 DIO_Read_Port_Value (uint8 portNumber)
{
	switch (portNumber) 
    {
        case 0:
            return PORTA;
        break;
        case 1:
            return PORTB;
        break;
        case 2:
            return PORTC;
        break;
        case 3:
            return PORTD;
        break;
        case 4:
            return PORTE;
        break;
	}
	return 0;
}


uint8 DIO_Read_Pin_Value (uint8 portNumber, uint8 index)
{
	uint8 port = DIO_Read_Port_Value(portNumber);
	return GET_BIT(port, index);
}

void DIO_Set_Pin_Value (uint8 portNumber, uint8 index, uint8 value) 
{
	switch (portNumber) 
    {
	case 0:
		if (value == 1)
			SET_BIT(PORTA, index);
		else if (value == 0)
			CLEAR_BIT(PORTA, index);
		break;
	case 1:
		if (value == 1)
			SET_BIT(PORTB, index);
		else if (value == 0)
			CLEAR_BIT(PORTB, index);
		break;
	case 2:
		if (value == 1)
			SET_BIT(PORTC, index);
		else if (value == 0)
			CLEAR_BIT(PORTC, index);
		break;
	case 3:
		if (value == 1)
			SET_BIT(PORTD, index);
		else if (value == 0)
			CLEAR_BIT(PORTD, index);
		break;
	case 4:
		if (value == 1)
			SET_BIT(PORTE, index);
		else if (value == 0)
			CLEAR_BIT(PORTE, index);
		break;
	}
}


void DIO_Set_Pin_Direction (uint8 portNumber, uint8 index, uint8 direction)
{
	switch (portNumber) 
    {
	case 0:
		if (direction == 1)
			SET_BIT(TRISA, index);
		else if (direction == 0)
			CLEAR_BIT(TRISA, index);
		break;
	case 1:
		if (direction == 1)
			SET_BIT(TRISB, index);
		else if (direction == 0)
			CLEAR_BIT(TRISB, index);
		break;
	case 2:
		if (direction == 1)
			SET_BIT(TRISC, index);
		else if (direction == 0)
			CLEAR_BIT(TRISC, index);
		break;
	case 3:
		if (direction == 1)
			SET_BIT(TRISD, index);
		else if (direction == 0)
			CLEAR_BIT(TRISD, index);
		break;
	case 4:
		if (direction == 1)
			SET_BIT(TRISE, index);
		else if (direction == 0)
			CLEAR_BIT(TRISE, index);
		break;
	}
}
//--------------------- End of File --------------------------------