/*
 * MEXTI_program.c
 *
 *  Created on: Sep 7, 2022
 *      Author: Eng. Karim
 */

#include "../../LIB/LIB_STD_TYPES.h"

#include "../../LIB/LIB_BIT_MATH.h"

#include "MEXTI_interface.h"

#include "MEXTI_private.h"

void MEXTI_voidINT0 (void)
{
	/*Enable External Interrupt 1*/
	SET_BIT(GICR, INT0);

	/*Configure Control External Interrupt 1 Sense*/
	/*Falling Edge ONE & Zero*/
	SET_BIT(MCUCR, ISC01);
	CLR_BIT(MCUCR, ISC00);
}

void MEXTI_voidINT1 (void)
{
	/*Enable External Interrupt 1*/
	SET_BIT(GICR, INT1);

	/*Configure Control External Interrupt 1 Sense*/
	/*Falling Edge ONE & ZERO*/
	SET_BIT(MCUCR, ISC11);
	CLR_BIT(MCUCR, ISC10);
}

void MEXTI_voidINT2 (void)
{
	/*Enable External Interrupt 1*/
	SET_BIT(GICR, INT2);

	/*Configure Control External Interrupt 1 Sense*/
	/*ONE Rising Edge On INT2 Activates The Interrupt*/
	SET_BIT(MCUCR, ISC2);

	/*If We want to change it into Falling Edge We Shall Write One*/
	//CLR_BIT(MCUCR, ISC2);
}

//void __vector_1(void)
//{
//
//}

void __vector_2(void)
{

}

void __vector_3(void)
{

}
