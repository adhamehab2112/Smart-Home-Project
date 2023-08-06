/*
 * LED_program.c
 *
 *  Created on: Sep 16, 2022
 *      Author: Eng. Karim
 */

#include "../../LIB/LIB_STD_TYPES.h"
#include "../../LIB/LIB_BIT_MATH.h"
#include <util/delay.h>

#include "../../MCAL/MDIO/MDIO_interface.h"
#include "LED_interface.h"

/*Do not forget to change your pin configuration to OUTPUT in MDIO_config*/

void HLED_voidOn (u8 Copy_u8Port, u8 Copy_u8Pin)
{
	MDIO_voidSetPinValue(Copy_u8Port, Copy_u8Pin, MDIO_PIN_HIGH);
}

void HLED_voidOff (u8 Copy_u8Port, u8  Copy_u8Pin)
{
	MDIO_voidSetPinValue(Copy_u8Port, Copy_u8Pin, MDIO_PIN_LOW);
}

void HLED_voidToggle (u8 Copy_u8Port, u8  Copy_u8Pin)
{
	if (MDIO_u8GetPinValue(Copy_u8Port, Copy_u8Pin) == MDIO_PIN_HIGH)
	{
		MDIO_voidSetPinValue(Copy_u8Port, Copy_u8Pin, MDIO_PIN_LOW);
		_delay_ms(100);
	}
	else if (MDIO_u8GetPinValue(Copy_u8Port, Copy_u8Pin) == MDIO_PIN_LOW)
	{
		MDIO_voidSetPinValue(Copy_u8Port, Copy_u8Pin, MDIO_PIN_HIGH);
		_delay_ms(100);
	}
	else { /*DO NOTHING*/ }
}

void HLED_voidBlinking (u8 Copy_u8Port, u8  Copy_u8Pin)
{
	for (u8 local_u8Iterator = 0; local_u8Iterator < 10; local_u8Iterator++)
	{
		MDIO_voidSetPinValue(Copy_u8Port, Copy_u8Pin, MDIO_PIN_HIGH);
		_delay_ms(100);
		MDIO_voidSetPinValue(Copy_u8Port, Copy_u8Pin, MDIO_PIN_LOW);
		_delay_ms(100);
	}
}
