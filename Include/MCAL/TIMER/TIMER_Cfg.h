/*
 * TIMER_Cfg.h
 *
 *  Created on: Oct 9, 2023
 *      Author: E-M-W-E
 */

#ifndef INCLUDE_MCAL_TIMER_TIMER_CFG_H_
#define INCLUDE_MCAL_TIMER_TIMER_CFG_H_

#define TIMER0_MODE  FAST_PWM_MODE



/*
*0b000 No clock source (Timer/Counter stopped).
*0b001 clkI/O (No prescaling)
*0b010 clkI/O/8 (From prescaler)
*0b011 clkI/O/64 (From prescaler)
*0b100 clkI/O/256 (From prescaler)
*0b101 clkI/O/1024 (From prescaler)
*0b110 External clock source on T0 pin. Clock on falling edge.
*0b111 External clock source on T0 pin. Clock on rising edge
*/
#define TIMER0_CLK 0b010



/*
*0b00 Normal port operation, OC0 disconnected.
*0b01 Toggle OC0 on compare match
*0b10 Clear OC0 on compare match
*0b11 Set OC0 on compare match
*/


#define CTC_0C0_MODE 0b00

/*
* 0b00 --> Normal DIO
* 0b10 --> Non Inverting mode
* 0b11 --> Inverting mode
 */
#define FAST_PWM_OC0_MODE		 0b10

#define PHASE_CORRECT_OC0_MODE	 0b10

//OCR0_VALUEMSEC =  No_Of_Ticks
#define OCR0_VALUE 	0


#endif /* INCLUDE_MCAL_TIMER_TIMER_CFG_H_ */
