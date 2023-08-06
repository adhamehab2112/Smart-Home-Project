/*
 * HSERVO_program.c
 *
 *  Created on: Sep 28, 2022
 *      Author: Eng. Karim
 */

#include "../../LIB/LIB_STD_TYPES.h"
#include "../../LIB/LIB_BIT_MATH.h"

#include "../../MCAL/MDIO/MDIO_interface.h"
#include "../../MCAL/MTIMER/MTIMER_interface.h"


void HServo_Motor_voidOFF ()
{
	MTIMER1_voidSetFastPWM_Value(124);
}

void HServo_Motor_voidON ()
{
	MTIMER1_voidSetFastPWM_Value(250);
}
