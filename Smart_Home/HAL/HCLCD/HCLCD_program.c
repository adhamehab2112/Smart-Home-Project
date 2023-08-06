/*
 * HCLCD_program.c
 *
 *  Created on: Sep 16, 2022
 *      Author: Eng. Karim
 */

#include "../../LIB/LIB_STD_TYPES.h"
#include "../../LIB/LIB_BIT_MATH.h"
#include <util/delay.h>

#include "../../MCAL/MDIO/MDIO_interface.h"

#include "HCLCD_config.h"
#include "HCLCD_interface.h"

/*Do not forget to change your pin configuration to OUTPUT in MDIO_config*/

void HCLCD_voidInit ()
{
	_delay_ms(40);
	/*Function Set*/
	HCLCD_voidSend_Command (0b00111000); /*Lines : 2 , Fonts : 5x7 */
	/*Display ON/OFF Control*/
	HCLCD_voidSend_Command (0b00001100);
	/*Display Clear*/
	HCLCD_voidSend_Command (0b00000001);
	/*Entry Mode*/
	HCLCD_voidSend_Command (0b00000110);
}
/*****************************************************************************************************/
void HCLCD_voidSend_Command (u8 Copy_u8CMD)
{
	MDIO_voidSetPinValue (HCLCD_CMD_PORT, HCLCD_RS_PIN, MDIO_PIN_LOW);

	MDIO_voidSetPinValue (HCLCD_CMD_PORT, HCLCD_RW_PIN, MDIO_PIN_LOW);

	MDIO_voidSetPortValue(HCLCD_DATA_PORT, Copy_u8CMD);

	MDIO_voidSetPinValue (HCLCD_CMD_PORT, HCLCD_E_PIN, MDIO_PIN_HIGH);
	_delay_ms(2);
	MDIO_voidSetPinValue (HCLCD_CMD_PORT, HCLCD_E_PIN, MDIO_PIN_LOW);
}
/*****************************************************************************************************/
void HCLCD_voidSend_Data (u8 Copy_u8DATA)
{
	MDIO_voidSetPinValue (HCLCD_CMD_PORT, HCLCD_RS_PIN, MDIO_PIN_HIGH);

	MDIO_voidSetPinValue (HCLCD_CMD_PORT, HCLCD_RW_PIN, MDIO_PIN_LOW);

	MDIO_voidSetPortValue(HCLCD_DATA_PORT, Copy_u8DATA);

	MDIO_voidSetPinValue (HCLCD_CMD_PORT, HCLCD_E_PIN, MDIO_PIN_HIGH);
	_delay_ms(2);
	MDIO_voidSetPinValue (HCLCD_CMD_PORT, HCLCD_E_PIN, MDIO_PIN_LOW);
}
/*****************************************************************************************************/
void HCLCD_voidClear ()
{
	HCLCD_voidSend_Command(1);
}
/*****************************************************************************************************/
void HCLCD_voidDisplay_Char (u8 Copy_u8Char)
{
	HCLCD_voidSend_Data(Copy_u8Char);
}
/*****************************************************************************************************/
void HCLCD_voidDisplay_String (u8 *Copy_pu8String)
{
	u8 local_u8Iterator = 0;
	while(Copy_pu8String[local_u8Iterator] != '\0')
	{
		HCLCD_voidSend_Data(Copy_pu8String[local_u8Iterator]);
		local_u8Iterator ++;
	}
}
/*****************************************************************************************************/
void HCLCD_voidDisplay_Number (u8 Copy_u8Num)
{
	HCLCD_voidSend_Data(Copy_u8Num + 48);
}
/*****************************************************************************************************/
void HCLCD_voidDisplay_MultiNumber (u32 Copy_u32Num, u8 Copy_u8RowPos, u8 Copy_u8ColPos)
{
	u8 local_u8Remainder = 0;

	if (Copy_u32Num == 0)
	{
		HCLCD_voidGoTo(Copy_u8RowPos, Copy_u8ColPos);
		HCLCD_voidSend_Data(Copy_u32Num + 48);
	}
	else
	{
		while (Copy_u32Num > 0)
		{
			local_u8Remainder = Copy_u32Num % 10;

			if (Copy_u32Num > 99999)
			{
				HCLCD_voidGoTo(Copy_u8RowPos, Copy_u8ColPos + 5);
				HCLCD_voidSend_Data(local_u8Remainder + 48);
			}
			else if (Copy_u32Num > 9999)
			{
				HCLCD_voidGoTo(Copy_u8RowPos, Copy_u8ColPos + 4);
				HCLCD_voidSend_Data(local_u8Remainder + 48);
			}
			else if (Copy_u32Num > 999)
			{
				HCLCD_voidGoTo(Copy_u8RowPos, Copy_u8ColPos + 3);
				HCLCD_voidSend_Data(local_u8Remainder + 48);
			}
			else if (Copy_u32Num > 99)
			{
				HCLCD_voidGoTo(Copy_u8RowPos, Copy_u8ColPos + 2);
				HCLCD_voidSend_Data(local_u8Remainder + 48);
			}
			else if (Copy_u32Num > 9)
			{
				HCLCD_voidGoTo(Copy_u8RowPos, Copy_u8ColPos + 1);
				HCLCD_voidSend_Data(local_u8Remainder + 48);
			}
			else if (Copy_u32Num >= 0)
			{
				HCLCD_voidGoTo(Copy_u8RowPos, Copy_u8ColPos);
				HCLCD_voidSend_Data(Copy_u32Num + 48);
			}
			else {/*DO NOTHING*/}

			Copy_u32Num = Copy_u32Num / 10;
		}
	}
}
/*****************************************************************************************************/
void HCLCD_voidGoTo (u8 Copy_u8RowPos, u8 Copy_u8ColPos)
{
	u8 local_CursorPos = 0;
	/*First Row*/
	if (Copy_u8RowPos == 0)
	{
		/*Address of first character is 0x0*/
		local_CursorPos = 0x0 + Copy_u8ColPos;
	}
	/*Second Row*/
	else if (Copy_u8RowPos == 1)
	{
		/*Address of first character is 0x40*/
		local_CursorPos = 0x40 + Copy_u8ColPos;
	}
	else { /*DO NOTHING*/ }

	HCLCD_voidSend_Command(local_CursorPos + 128);
}
/*****************************************************************************************************/
void HCLCD_voidBlinkCursor ()
{
	HCLCD_voidSend_Command(0b00001111);
}
/*****************************************************************************************************/
void HCLCD_voidShift_Right ()
{
	HCLCD_voidSend_Command(0b00011100);
}
/*****************************************************************************************************/
void HCLCD_voidShift_Left ()
{
	HCLCD_voidSend_Command(0b00011000);
}
/*****************************************************************************************************/
/*Write & Display*/
void HCLCD_voidSpecial_Char (u8 Copy_u8SpCharlocation, u8 *Copy_pu8SpCharArr, u8 Copy_u8RowPos, u8 Copy_u8ColPos)
{
	u8 local_u8Lines = 0;

	local_u8Lines = Copy_u8SpCharlocation * 8;

	HCLCD_voidSend_Command(local_u8Lines + 64);

	for (u8 local_u8Iteration = 0; local_u8Iteration < 8; local_u8Iteration ++)
	{
		HCLCD_voidSend_Data(Copy_pu8SpCharArr[local_u8Iteration]);
	}

	HCLCD_voidGoTo(Copy_u8RowPos, Copy_u8ColPos);

	HCLCD_voidSend_Data(Copy_u8SpCharlocation);
}
/*****************************************************************************************************/
