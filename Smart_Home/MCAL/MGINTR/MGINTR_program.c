/*
 * MGINTR_program.c
 *
 *  Created on: Sep 12, 2022
 *      Author: Eng. Karim
 */

#include "../../LIB/LIB_STD_TYPES.h"
#include "../../LIB/LIB_BIT_MATH.h"

#include "MGINTR_private.h"
#include "MGINTR_interface.h"

void MGIE_voidEnable ()
{
	SET_BIT(SREG, SREG_I);
}

void MGIE_voidDisable ()
{
	CLR_BIT(SREG, SREG_I);
}
