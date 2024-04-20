/*
 * UART_Private.h
 *
 *  Created on: Oct 26, 2023
 *      Author: E-M-W-E
 */

#ifndef INCLUDE_MCAL_UART_UART_PRIVATE_H_
#define INCLUDE_MCAL_UART_UART_PRIVATE_H_

#define UDR		 (*((volatile u8 *) 0x2C))

#define UBRRH	 (*((volatile u8 *) 0x40))

#define UBRRL	 (*((volatile u8 *) 0x29))

#define UCSRC	 (*((volatile u8 *) 0x40))

#define UCSRA	 (*((volatile u8 *) 0x2B))

#define UCSRB	 (*((volatile u8 *) 0x2A))

#define BAUD_RATE_EQUATION (F_CPU/16/BAUDRATE_VALUE-1)

#endif /* INCLUDE_MCAL_UART_UART_PRIVATE_H_ */
