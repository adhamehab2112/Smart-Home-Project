/*
 * MTIMER_program.c
 *
 *  Created on: Sep 10, 2022
 *      Author: emad
 */


#include "../../LIB/LIB_STD_TYPES.h"
#include "../../LIB/LIB_BIT_MATH.h"

#include "MTIMER_config.h"
#include "MTIMER_private.h"
#include "MTIMER_interface.h"

void (*MTIMER0_PtrFun)(void);
void (*MTIMER1_PtrFun)(void);

void MTIMER0_voidInit(void)
{
	TCCR0 = TIMER0_COM | MTIMER0_WGM  | MTIMER0_CS;
	SET_BIT(TIMSK,0); /*Enable OV Interrupt*/
}

void MTIMER0_voidSetOV_Value(u8 Copy_u8Value)
{
	TCNT0 = 256 - Copy_u8Value;
}

void MTIMER0_voidSetCTC_Value(u8 Copy_u8Value)
{
	OCR0 = Copy_u8Value;
}

void MTIMER0_voidSetCallback(void (* PtrFun)(void))
{
	MTIMER0_PtrFun = PtrFun;
}

/*Time0 CTC Interrupt*/
void __vector_10(void)
{
	MTIMER0_PtrFun();
}
/*Time0 OVF Interrupt*/
//void __vector_11(void)
//{
//	MTIMER0_PtrFun();
//}
/********************** Timer 1 ******************************/

void MTIMER1_voidInit(void)
{
	/*Select FAST_PWM Mode*/
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	SET_BIT(TCCR1B,TCCR1B_WGM13);

	/*Clear channel B1 when up counting*/
	CLR_BIT(TCCR1A,TCCR1A_COM1B0);
	SET_BIT(TCCR1A,TCCR1A_COM1B1);

	/*Setting the prescaler 64 (the clock)*/
	SET_BIT(TCCR1B,TCCR1B_CS10);
	SET_BIT(TCCR1B,TCCR1B_CS11);
	CLR_BIT(TCCR1B,TCCR1B_CS12);

	/*TCCR1A_COM1B0 */
	SET_BIT(TCCR1A, TCCR1A_FOC1B);

	ICR1 = 2500;
}

void MTIMER1_voidSetOV(u16 Copy_u16OV)
{
	TCNT1= 65536 - Copy_u16OV;
}

void MTIMER1_voidSetICR1(u16 Copy_u16TOP)
{
	ICR1= Copy_u16TOP;
}

void MTIMER1_voidSetCTC(u16 Copy_u16Value)
{
	OCR1A = Copy_u16Value;
}

void MTIMER1_voidSetFastPWM_Value(u16 Copy_u16Value)
{
	OCR1B = Copy_u16Value;
}
