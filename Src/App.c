/*
 * App.c
 *
 *  Created on: Dec 25, 2023
 *      Author: E-M-W-E
 */
#include "../Include/LIB/BIT_MATH.h"
#include "../Include/LIB/STD_TYPES.h"

#include "../Include/MCAL/TIMER/TIMER_Interface.h"

#include "../Include/MCAL/DIO/DIO_Interface.h"

#include "../Include/MCAL/GI/GI_interface.h"

#include "../Include/MCAL/UART/UART_Interface.h"

#include "../Include/HAL/Final_Project/Final_Project_Interface.h"

#include <util/delay.h>

#define F_CPU 8000000UL

int main ()
{
	MDIO_voidInit();
	MUART_voidInit();
	MTIMER0_voidInit();
	MGI_voidEnable();
	H_voidHomePageLogOrReg();

	while (1)
	{

    }

}
