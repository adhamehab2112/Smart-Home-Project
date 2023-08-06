/*
 * HSEVEN_SEGMENT_program.c
 *
 *  Created on: Oct 1, 2022
 *      Author: Eng. Karim
 */


#include "../../LIB/LIB_STD_TYPES.h"
#include "../../LIB/LIB_BIT_MATH.h"
#include "../../MCAL/MDIO/MDIO_interface.h"
#include "../../MCAL/MADC/MADC_interface.h"
#include "HSEVEN_SEGMENT_config.h"
#include "HSEVEN_SEGMENT_interface.h"

void HSEVEN_SEGMENT_voidNum0(u8 Copy_u8Port)
{
	MDIO_voidSetPinValue(Copy_u8Port, PIN_A, MDIO_PIN_HIGH);
	MDIO_voidSetPinValue(Copy_u8Port, PIN_B, MDIO_PIN_HIGH);
	MDIO_voidSetPinValue(Copy_u8Port, PIN_C, MDIO_PIN_HIGH);
	MDIO_voidSetPinValue(Copy_u8Port, PIN_D, MDIO_PIN_HIGH);
	MDIO_voidSetPinValue(Copy_u8Port, PIN_E, MDIO_PIN_HIGH);
	MDIO_voidSetPinValue(Copy_u8Port, PIN_F, MDIO_PIN_HIGH);
	MDIO_voidSetPinValue(Copy_u8Port, PIN_G, MDIO_PIN_LOW);

}

void HSEVEN_SEGMENT_voidNum1(u8 Copy_u8Port)
{
	MDIO_voidSetPinValue(Copy_u8Port, PIN_A, MDIO_PIN_LOW);
	MDIO_voidSetPinValue(Copy_u8Port, PIN_B, MDIO_PIN_HIGH);
	MDIO_voidSetPinValue(Copy_u8Port, PIN_C, MDIO_PIN_HIGH);
	MDIO_voidSetPinValue(Copy_u8Port, PIN_D, MDIO_PIN_LOW);
	MDIO_voidSetPinValue(Copy_u8Port, PIN_E, MDIO_PIN_LOW);
	MDIO_voidSetPinValue(Copy_u8Port, PIN_F, MDIO_PIN_LOW);
	MDIO_voidSetPinValue(Copy_u8Port, PIN_G, MDIO_PIN_LOW);
}

void HSEVEN_SEGMENT_voidNum2(u8 Copy_u8Port)
{
	MDIO_voidSetPinValue(Copy_u8Port, PIN_A, MDIO_PIN_HIGH);
	MDIO_voidSetPinValue(Copy_u8Port, PIN_B, MDIO_PIN_HIGH);
	MDIO_voidSetPinValue(Copy_u8Port, PIN_C, MDIO_PIN_LOW);
	MDIO_voidSetPinValue(Copy_u8Port, PIN_D, MDIO_PIN_HIGH);
	MDIO_voidSetPinValue(Copy_u8Port, PIN_E, MDIO_PIN_HIGH);
	MDIO_voidSetPinValue(Copy_u8Port, PIN_F, MDIO_PIN_LOW);
	MDIO_voidSetPinValue(Copy_u8Port, PIN_G, MDIO_PIN_HIGH);
}

void HSEVEN_SEGMENT_voidNum3(u8 Copy_u8Port)
{
	MDIO_voidSetPinValue(Copy_u8Port, PIN_A, MDIO_PIN_HIGH);
	MDIO_voidSetPinValue(Copy_u8Port, PIN_B, MDIO_PIN_HIGH);
	MDIO_voidSetPinValue(Copy_u8Port, PIN_C, MDIO_PIN_HIGH);
	MDIO_voidSetPinValue(Copy_u8Port, PIN_D, MDIO_PIN_HIGH);
	MDIO_voidSetPinValue(Copy_u8Port, PIN_E, MDIO_PIN_LOW);
	MDIO_voidSetPinValue(Copy_u8Port, PIN_F, MDIO_PIN_LOW);
	MDIO_voidSetPinValue(Copy_u8Port, PIN_G, MDIO_PIN_HIGH);
}

void HSEVEN_SEGMENT_voidNum4(u8 Copy_u8Port)
{
	MDIO_voidSetPinValue(Copy_u8Port, PIN_A , MDIO_PIN_LOW);
	MDIO_voidSetPinValue(Copy_u8Port, PIN_B , MDIO_PIN_HIGH);
	MDIO_voidSetPinValue(Copy_u8Port, PIN_C , MDIO_PIN_HIGH);
	MDIO_voidSetPinValue(Copy_u8Port, PIN_D , MDIO_PIN_LOW);
	MDIO_voidSetPinValue(Copy_u8Port, PIN_E , MDIO_PIN_LOW);
	MDIO_voidSetPinValue(Copy_u8Port, PIN_F , MDIO_PIN_HIGH);
	MDIO_voidSetPinValue(Copy_u8Port, PIN_G , MDIO_PIN_HIGH);

}

void HSEVEN_SEGMENT_voidNum5(u8 Copy_u8Port)
{
	MDIO_voidSetPinValue(Copy_u8Port, PIN_A, MDIO_PIN_HIGH);
	MDIO_voidSetPinValue(Copy_u8Port, PIN_B, MDIO_PIN_LOW);
	MDIO_voidSetPinValue(Copy_u8Port, PIN_C, MDIO_PIN_HIGH);
	MDIO_voidSetPinValue(Copy_u8Port, PIN_D, MDIO_PIN_HIGH);
	MDIO_voidSetPinValue(Copy_u8Port, PIN_E, MDIO_PIN_LOW);
	MDIO_voidSetPinValue(Copy_u8Port, PIN_F, MDIO_PIN_HIGH);
	MDIO_voidSetPinValue(Copy_u8Port, PIN_G, MDIO_PIN_HIGH);
}

void HSEVEN_SEGMENT_voidNum6(u8 Copy_u8Port)
{
	MDIO_voidSetPinValue(Copy_u8Port, PIN_A, MDIO_PIN_HIGH);
	MDIO_voidSetPinValue(Copy_u8Port, PIN_B, MDIO_PIN_LOW);
	MDIO_voidSetPinValue(Copy_u8Port, PIN_C, MDIO_PIN_HIGH);
	MDIO_voidSetPinValue(Copy_u8Port, PIN_D, MDIO_PIN_HIGH);
	MDIO_voidSetPinValue(Copy_u8Port, PIN_E, MDIO_PIN_HIGH);
	MDIO_voidSetPinValue(Copy_u8Port, PIN_F, MDIO_PIN_HIGH);
	MDIO_voidSetPinValue(Copy_u8Port, PIN_G, MDIO_PIN_HIGH);
}

void HSEVEN_SEGMENT_voidNum7(u8 Copy_u8Port)
{
	MDIO_voidSetPinValue(Copy_u8Port, PIN_A, MDIO_PIN_HIGH);
	MDIO_voidSetPinValue(Copy_u8Port, PIN_B, MDIO_PIN_HIGH);
	MDIO_voidSetPinValue(Copy_u8Port, PIN_C, MDIO_PIN_HIGH);
	MDIO_voidSetPinValue(Copy_u8Port, PIN_D, MDIO_PIN_LOW);
	MDIO_voidSetPinValue(Copy_u8Port, PIN_E, MDIO_PIN_LOW);
	MDIO_voidSetPinValue(Copy_u8Port, PIN_F, MDIO_PIN_LOW);
	MDIO_voidSetPinValue(Copy_u8Port, PIN_G, MDIO_PIN_LOW);
}

void HSEVEN_SEGMENT_voidNum8(u8 Copy_u8Port)
{
	MDIO_voidSetPinValue(Copy_u8Port, PIN_A, MDIO_PIN_HIGH);
	MDIO_voidSetPinValue(Copy_u8Port, PIN_B, MDIO_PIN_HIGH);
	MDIO_voidSetPinValue(Copy_u8Port, PIN_C, MDIO_PIN_HIGH);
	MDIO_voidSetPinValue(Copy_u8Port, PIN_D, MDIO_PIN_HIGH);
	MDIO_voidSetPinValue(Copy_u8Port, PIN_E, MDIO_PIN_HIGH);
	MDIO_voidSetPinValue(Copy_u8Port, PIN_F, MDIO_PIN_HIGH);
	MDIO_voidSetPinValue(Copy_u8Port, PIN_G, MDIO_PIN_HIGH);
}

void HSEVEN_SEGMENT_voidNum9(u8 Copy_u8Port)
{
	MDIO_voidSetPinValue(Copy_u8Port, PIN_A, MDIO_PIN_HIGH);
	MDIO_voidSetPinValue(Copy_u8Port, PIN_B, MDIO_PIN_HIGH);
	MDIO_voidSetPinValue(Copy_u8Port, PIN_C, MDIO_PIN_HIGH);
	MDIO_voidSetPinValue(Copy_u8Port, PIN_D, MDIO_PIN_HIGH);
	MDIO_voidSetPinValue(Copy_u8Port, PIN_E, MDIO_PIN_LOW);
	MDIO_voidSetPinValue(Copy_u8Port, PIN_F, MDIO_PIN_HIGH);
	MDIO_voidSetPinValue(Copy_u8Port, PIN_G, MDIO_PIN_HIGH);
}
