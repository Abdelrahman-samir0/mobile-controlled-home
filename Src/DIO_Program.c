/*
 * DIO_Program.c
 *
 *  Created on: Sep 9, 2023
 *      Author: abdelrahmanhossam
 */



/*
 * Including Order
 * ------------------
 * 1- LIB --> STD_TYPES.h BIT_MATH.h
 * 2- MCAL --> DIO --> _Interface.h
 * 				   --> _Private.h
 * 				   --> _Cfg.h
 */

#include "../Include/LIB/STD_TYPES.h"
#include "../Include/LIB/BIT_MATH.h"

#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/MCAL/DIO/DIO_Private.h"
#include "../Include/MCAL/DIO/DIO_Cfg.h"

//MDIO_voidSetPinDirection (DIO_PORTA, PIN5, DIO_OUTPUT);

void MDIO_voidSetPinDirection (DIO_PORT_e A_portID, DIO_PIN_e A_pinID, DIO_DIRECTION_e A_Direction)
{
	// Input Validation
	if ( (A_portID <= DIO_PORTD) && (A_pinID <= DIO_PIN7) && (A_Direction <= DIO_OUTPUT) )
	{
		switch (A_portID)
		{
		case DIO_PORTA:
			switch (A_Direction)
			{
			case DIO_INPUT:
				CLR_BIT(DDRA_REG,A_pinID);
				break;
			case DIO_OUTPUT:
				SET_BIT(DDRA_REG,A_pinID);
				break;
			}
			break;
		case DIO_PORTB:
			switch (A_Direction)
			{
			case DIO_INPUT:
				CLR_BIT(DDRB_REG,A_pinID);
				break;
			case DIO_OUTPUT:
				SET_BIT(DDRB_REG,A_pinID);
				break;
			}
			break;
		case DIO_PORTC:
			switch (A_Direction)
			{
			case DIO_INPUT:
				CLR_BIT(DDRC_REG,A_pinID);
				break;
			case DIO_OUTPUT:
				SET_BIT(DDRC_REG,A_pinID);
				break;
			}
			break;
		case DIO_PORTD:
			switch (A_Direction)
			{
			case DIO_INPUT:
				CLR_BIT(DDRD_REG,A_pinID);
				break;
			case DIO_OUTPUT:
				SET_BIT(DDRD_REG,A_pinID);
				break;
			}
			break;
		default :
			break;
		}
	}
	else
	{
		// Do Nothing
	}
}

void MDIO_voidSetPinValue (DIO_PORT_e A_portID, DIO_PIN_e A_pinID, DIO_VALUE_e A_Value)
{
	// Input Validation
	if ( (A_portID <= DIO_PORTD) && (A_pinID <= DIO_PIN7) && (A_Value <= DIO_SET) )
	{
		switch (A_portID)
		{
		case DIO_PORTA:
			switch (A_Value)
			{
			case DIO_RESET:
				CLR_BIT(PORTA_REG,A_pinID);
				break;
			case DIO_SET:
				SET_BIT(PORTA_REG,A_pinID);
				break;
			}
			break;
		case DIO_PORTB:
			switch (A_Value)
			{
			case DIO_RESET:
				CLR_BIT(PORTB_REG,A_pinID);
				break;
			case DIO_SET:
				SET_BIT(PORTB_REG,A_pinID);
				break;
			}
			break;
		case DIO_PORTC:
			switch (A_Value)
			{
			case DIO_RESET:
				CLR_BIT(PORTC_REG,A_pinID);
				break;
			case DIO_SET:
				SET_BIT(PORTC_REG,A_pinID);
				break;
			}
			break;
		case DIO_PORTD:
			switch (A_Value)
			{
			case DIO_RESET:
				CLR_BIT(PORTD_REG,A_pinID);
				break;
			case DIO_SET:
				SET_BIT(PORTD_REG,A_pinID);
				break;
			}
			break;
		default :
			break;
		}
	}
	else
	{
		// Do Nothing
	}
}


DIO_VALUE_e MDIO_GetPinValue (DIO_PORT_e A_portID, DIO_PIN_e A_pinID)
{
	DIO_VALUE_e local_Value;
	if ( (A_portID <= DIO_PORTD) && (A_pinID <= DIO_PIN7) )
	{
		switch (A_portID)
		{
		case DIO_PORTA:
			local_Value = GET_BIT(PINA_REG,A_pinID);
			break;
		case DIO_PORTB:
			local_Value = GET_BIT(PINB_REG,A_pinID);
			break;
		case DIO_PORTC:
			local_Value = GET_BIT(PINC_REG,A_pinID);
			break;
		case DIO_PORTD:
			local_Value = GET_BIT(PIND_REG,A_pinID);
			break;
		}
	}
	return local_Value;
}

void MDIO_voidTogglePinValue (DIO_PORT_e A_portID, DIO_PIN_e A_pinID)
{
	if ( (A_portID <= DIO_PORTD) && (A_pinID <= DIO_PIN7) )
	{
		switch (A_portID)
		{
		case DIO_PORTA:
			TOGGLE_BIT(PORTA_REG,A_pinID);
			break;
		case DIO_PORTB:
			TOGGLE_BIT(PORTB_REG,A_pinID);
			break;
		case DIO_PORTC:
			TOGGLE_BIT(PORTC_REG,A_pinID);
			break;
		case DIO_PORTD:
			TOGGLE_BIT(PORTD_REG,A_pinID);
			break;
		}
	}
}


void MDIO_voidSetPortDirection (DIO_PORT_e A_portID, u8 A_u8Direction)
{
	if ( (A_portID <= DIO_PORTD) )
	{
		switch (A_portID)
		{
		case DIO_PORTA:
			DDRA_REG = A_u8Direction;
			break;
		case DIO_PORTB:
			DDRB_REG = A_u8Direction;
			break;
		case DIO_PORTC:
			DDRC_REG = A_u8Direction;
			break;
		case DIO_PORTD:
			DDRD_REG = A_u8Direction;
			break;
		}
	}
}

void MDIO_voidSetPortValue (DIO_PORT_e A_portID, u8 A_u8Value)
{
	if ( (A_portID <= DIO_PORTD) )
	{
		switch (A_portID)
		{
		case DIO_PORTA:
			PORTA_REG = A_u8Value;
			break;
		case DIO_PORTB:
			PORTB_REG = A_u8Value;
			break;
		case DIO_PORTC:
			PORTC_REG = A_u8Value;
			break;
		case DIO_PORTD:
			PORTD_REG = A_u8Value;
			break;
		}
	}
}


void MDIO_voidInit()
{
	DDRA_REG = CONC_BIT(PA7_INITIAL_DIRECTION,PA6_INITIAL_DIRECTION,
						PA5_INITIAL_DIRECTION,PA4_INITIAL_DIRECTION,
						PA3_INITIAL_DIRECTION,PA2_INITIAL_DIRECTION,
						PA1_INITIAL_DIRECTION,PA0_INITIAL_DIRECTION);

	DDRB_REG = CONC_BIT(PB7_INITIAL_DIRECTION,PB6_INITIAL_DIRECTION,
						PB5_INITIAL_DIRECTION,PB4_INITIAL_DIRECTION,
						PB3_INITIAL_DIRECTION,PB2_INITIAL_DIRECTION,
						PB1_INITIAL_DIRECTION,PB0_INITIAL_DIRECTION);

	DDRC_REG = CONC_BIT(PC7_INITIAL_DIRECTION,PC6_INITIAL_DIRECTION,
						PC5_INITIAL_DIRECTION,PC4_INITIAL_DIRECTION,
						PC3_INITIAL_DIRECTION,PC2_INITIAL_DIRECTION,
						PC1_INITIAL_DIRECTION,PC0_INITIAL_DIRECTION);

	DDRD_REG = CONC_BIT(PD7_INITIAL_DIRECTION,PD6_INITIAL_DIRECTION,
						PD5_INITIAL_DIRECTION,PD4_INITIAL_DIRECTION,
						PD3_INITIAL_DIRECTION,PD2_INITIAL_DIRECTION,
						PD1_INITIAL_DIRECTION,PD0_INITIAL_DIRECTION);

	PORTA_REG = CONC_BIT(PA7_INITIAL_VALUE,PA6_INITIAL_VALUE,
						 PA5_INITIAL_VALUE,PA4_INITIAL_VALUE,
						 PA3_INITIAL_VALUE,PA2_INITIAL_VALUE,
						 PA1_INITIAL_VALUE,PA0_INITIAL_VALUE);

	PORTB_REG = CONC_BIT(PB7_INITIAL_VALUE,PB6_INITIAL_VALUE,
						 PB5_INITIAL_VALUE,PB4_INITIAL_VALUE,
						 PB3_INITIAL_VALUE,PB2_INITIAL_VALUE,
						 PB1_INITIAL_VALUE,PB0_INITIAL_VALUE);

	PORTC_REG = CONC_BIT(PC7_INITIAL_VALUE,PC6_INITIAL_VALUE,
						 PC5_INITIAL_VALUE,PC4_INITIAL_VALUE,
						 PC3_INITIAL_VALUE,PC2_INITIAL_VALUE,
						 PC1_INITIAL_VALUE,PC0_INITIAL_VALUE);

	PORTD_REG = CONC_BIT(PD7_INITIAL_VALUE,PD6_INITIAL_VALUE,
						 PD5_INITIAL_VALUE,PD4_INITIAL_VALUE,
						 PD3_INITIAL_VALUE,PD2_INITIAL_VALUE,
						 PD1_INITIAL_VALUE,PD0_INITIAL_VALUE);
}




