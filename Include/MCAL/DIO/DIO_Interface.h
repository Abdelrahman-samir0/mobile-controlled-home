/*
 * DIO_Interface.h
 *
 *  Created on: Sep 9, 2023
 *      Author: abdelrahmanhossam
 */

#ifndef INCLUDE_MCAL_DIO_DIO_INTERFACE_H_
#define INCLUDE_MCAL_DIO_DIO_INTERFACE_H_

typedef enum{
	DIO_PORTA=0,
	DIO_PORTB,
	DIO_PORTC,
	DIO_PORTD
}DIO_PORT_e;

typedef enum{
	DIO_PIN0=0,
	DIO_PIN1,
	DIO_PIN2,
	DIO_PIN3,
	DIO_PIN4,
	DIO_PIN5,
	DIO_PIN6,
	DIO_PIN7,
}DIO_PIN_e;

typedef enum{
	DIO_INPUT=0,
	DIO_OUTPUT
}DIO_DIRECTION_e;

typedef enum{
	DIO_RESET=0,
	DIO_SET
}DIO_VALUE_e;

// Port name , Pin Number , i/p or o/p
void MDIO_voidSetPinDirection (DIO_PORT_e A_portID, DIO_PIN_e A_pinID, DIO_DIRECTION_e A_Direction);
void MDIO_voidSetPinValue (DIO_PORT_e A_portID, DIO_PIN_e A_pinID, DIO_VALUE_e A_Value);
DIO_VALUE_e MDIO_GetPinValue (DIO_PORT_e A_portID, DIO_PIN_e A_pinID);
void MDIO_voidTogglePinValue (DIO_PORT_e A_portID, DIO_PIN_e A_pinID);
void MDIO_voidSetPortValue (DIO_PORT_e A_portID, u8 A_u8Value);
void MDIO_voidSetPortDirection (DIO_PORT_e A_portID, u8 A_u8Direction);
void MDIO_voidInit();

#endif /* INCLUDE_MCAL_DIO_DIO_INTERFACE_H_ */
