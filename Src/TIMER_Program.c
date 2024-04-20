/*
 * TIMER_Program.c
 *
 *  Created on: Oct 9, 2023
 *      Author: E-M-W-E
 */
#include "../Include/LIB/BIT_MATH.h"
#include "../Include/LIB/STD_TYPES.h"

#include "../Include/MCAL/TIMER/TIMER_Interface.h"
#include "../Include/MCAL/TIMER/TIIMER_Private.h"
#include "../Include/MCAL/TIMER/TIMER_Cfg.h"

void (*TIMER0_OVF_CALLBACK)(void) = NULL;
void (*TIMER0_CTC_CALLBACK)(void) = NULL;

void MTIMER0_voidInit (void)
{
	#if TIMER0_MODE == NORMAL_MODE
		// Set Wave Generation Mode to Normal Mode
		CLR_BIT(TCCR0,3);
		CLR_BIT(TCCR0,6);

		// Enable OVF Interrupt
		SET_BIT(TIMSK,0);
		CLR_BIT(TIMSK,1);

		// Start Timer by setting its clock
		TCCR0 &= 0b11111000;
		TCCR0 |= TIMER0_CLK;

	#elif TIMER0_MODE == PHASE_CORRECT_MODE
		// Set Wave Generation Mode to CTC Mode
		SET_BIT(TCCR0,3);
		CLR_BIT(TCCR0,6);

		// DISAPLE Interrupts
		CLR_BIT(TIMSK,1);
		CLR_BIT(TIMSK,0);

		//Set OCR0 VALUE
		OCR0 = OCR0_VALUE;

		// SET OC0 and Start Timer by setting its clock
		TCCR0 &= TIEMR0_CLK_OC0_MASK ;
		TCCR0 |= (TIMER0_CLK|(PHASE_CORRECT_OC0_MODE<<4)) ;

	#elif TIMER0_MODE == CTC_MODE

		// Set Wave Generation Mode to CTC Mode
		CLR_BIT(TCCR0,3);
		SET_BIT(TCCR0,6);

		// Enable CTC Interrupt
		SET_BIT(TIMSK,1);
		CLR_BIT(TIMSK,0);

		//Set OCR0 VALUE
		OCR0 = OCR0_VALUE;

		// Start Timer by setting its clock
		TCCR0 &= 0b11001000;
		TCCR0 |= (TIMER0_CLK|(CTC_0C0_MODE<<4)) ;

	#elif TIMER0_MODE == FAST_PWM_MODE
		// Set Wave Generation Mode to FAST PWM Mode
		SET_BIT(TCCR0,3);
		SET_BIT(TCCR0,6);

		// DISAPLE Interrupts
		CLR_BIT(TIMSK,1);
		CLR_BIT(TIMSK,0);

		//Set OCR0 VALUE
		OCR0 = OCR0_VALUE;

		// SET OC0 and Start Timer by setting its clock
		TCCR0 &= TIEMR0_CLK_OC0_MASK ;
		TCCR0 |= (TIMER0_CLK|(FAST_PWM_OC0_MODE<<4)) ;

	#endif
}

void MTIMER0_voidSetOCR0Value(u8 A_u8NoOfTicks)
{
	OCR0=A_u8NoOfTicks;
}

void MTIMER0_voidSetPreloadValue (u8 A_u8NoOfTicks)
{
	TCNT0 = A_u8NoOfTicks;
}

void MTIMER0_voidStopTimer (void)
{
	TCCR0 &= 0b11111000;
}

void MTIMER0_voidSetOVFCallback (void (*A_PtrToFunc)(void))
{
	if (A_PtrToFunc != NULL)
	{
		TIMER0_OVF_CALLBACK = A_PtrToFunc;
	}
}

void MTIMER0_voidSetCTCCallback (void (*A_PtrToFunc)(void))
{
	if (A_PtrToFunc != NULL)
	{
		TIMER0_CTC_CALLBACK = A_PtrToFunc;
	}
}

void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
	if (TIMER0_OVF_CALLBACK != NULL)
	{
		TIMER0_OVF_CALLBACK();
	}
}

void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	if (TIMER0_CTC_CALLBACK != NULL)
	{
		TIMER0_CTC_CALLBACK();
	}
}

void MTIMER1_voidInit()
{
	// Select TIMER 1 MODE ==> 14
	CLR_BIT(TCCR1A,0);
	SET_BIT(TCCR1A,1);
	SET_BIT(TCCR1B,3);
	SET_BIT(TCCR1B,4);

	// Non-Inverting Mode for OC1A
	CLR_BIT(TCCR1A,6);
	SET_BIT(TCCR1A,7);

	// ICR1 = 19999
	ICR1 = 19999;

	//OCR1A
	OCR1A = 1500;

	// Start Timer
	CLR_BIT(TCCR1B,2);
	SET_BIT(TCCR1B,1);
	CLR_BIT(TCCR1B,0);
}

void MTIMER1_voidSetOCR1AValue (u16 A_u16Value)
{
	OCR1A = A_u16Value;
}

void MTIMER1_voidInitSWICU()
{
	// Start Timer by setting its clock pre-scaler
	CLR_BIT(TCCR1B,0);
	SET_BIT(TCCR1B,1);
	CLR_BIT(TCCR1B,2);
}
void MTIMER1_voidSetTimerValue (u16 A_u16Value)
{
	TCNT1=A_u16Value;
}

u16 MTIMER1_u16ReadTimerValue(void)
{
	return TCNT1;
}
