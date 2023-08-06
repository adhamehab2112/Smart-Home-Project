/*
 * main.c
 *
 *  Created on: Sep 29, 2022
 *      Author: PC
 */

#include "LIB/LIB_STD_TYPES.h"
#include "LIB/LIB_BIT_MATH.h"

#include "MCAL/MDIO/MDIO_interface.h"
#include "MCAL/MUART/MUART_interface.h"
#include "MCAL/MADC/MADC_interface.h"

#include "HAL/HCLCD/HCLCD_interface.h"
#include "HAL/HSEVEN_SEGMENT/HSEVEN_SEGMENT_interface.h"

#include <util/delay.h>

int main (void)
{
	MDIO_voidInit()  ;

	HCLCD_voidInit() ;

	MADC_voidInit();

	MUART_voidInit();

	u8 local_u8Garage_State = 0;
	//	u8 local_u8Led_Num ;
	u8 local_u8Global_Mode ;
	//	u8 local_u8Light_Intensity;

	u8 local_u8ADC_Value = 0;

	u8 local_u8Temp_Value = 0;

	while(1)
	{
			local_u8Garage_State = MUART_u8GetChar ();

			HCLCD_voidGoTo(HCLCD_ROW1, HCLCD_Column1) ;
			HCLCD_voidDisplay_String("DOOR ST:") ;

			while (local_u8Garage_State == 1)
			{
				HCLCD_voidGoTo(HCLCD_ROW1, HCLCD_Column10);
				HCLCD_voidDisplay_String("OPENED");
				local_u8Garage_State = MUART_u8GetChar();
			}

			HCLCD_voidGoTo(HCLCD_ROW1, HCLCD_Column10);
			HCLCD_voidDisplay_String("CLOSED");
			_delay_ms(2000);
			HCLCD_voidClear();

		local_u8ADC_Value = MADC_u8ReadChannel(ADC_Channel_0);

		local_u8Temp_Value = local_u8ADC_Value * 2;

		ASYSTEM_voidTemp(local_u8Temp_Value);

	}
}

//void ASYSTEM_voidDoor_State (u8 Copy_u8Garage_State)
//{
//	HCLCD_voidGoTo(HCLCD_ROW1, HCLCD_Column1) ;
//	HCLCD_voidDisplay_String("DOOR ST:") ;
//
//	while (Copy_u8Garage_State == 1)
//	{
//		HCLCD_voidGoTo(HCLCD_ROW1, HCLCD_Column10);
//		HCLCD_voidDisplay_String("OPENED");
//		Copy_u8Garage_State = MUART_u8GetChar();
//	}
//
//	HCLCD_voidGoTo(HCLCD_ROW1, HCLCD_Column10);
//	HCLCD_voidDisplay_String("CLOSED");
//	_delay_ms(2000);
//	HCLCD_voidClear();
//}

void ASYSTEM_voidTemp (u8 Copy_u8Temp)
{
	HCLCD_voidDisplay_MultiNumber(Copy_u8Temp, HCLCD_ROW2, HCLCD_Column1);
	HCLCD_voidDisplay_String("  ");
	if (Copy_u8Temp >= 0 || Copy_u8Temp < 10)
	{
		if (Copy_u8Temp == 0)
		{
			HSEVEN_SEGMENT_voidNum0(MDIO_PORTA);
			HSEVEN_SEGMENT_voidNum0(MDIO_PORTB);
		}
		else if (Copy_u8Temp == 2)
		{
			HSEVEN_SEGMENT_voidNum0(MDIO_PORTA);
			HSEVEN_SEGMENT_voidNum2(MDIO_PORTB);
		}
		else if (Copy_u8Temp == 4)
		{
			HSEVEN_SEGMENT_voidNum0(MDIO_PORTA);
			HSEVEN_SEGMENT_voidNum4(MDIO_PORTB);
		}
		else if (Copy_u8Temp == 6)
		{
			HSEVEN_SEGMENT_voidNum0(MDIO_PORTA);
			HSEVEN_SEGMENT_voidNum6(MDIO_PORTB);
		}
		else if (Copy_u8Temp == 8)
		{
			HSEVEN_SEGMENT_voidNum0(MDIO_PORTA);
			HSEVEN_SEGMENT_voidNum8(MDIO_PORTB);
		}
		else if (Copy_u8Temp == 10)
		{
			HSEVEN_SEGMENT_voidNum1(MDIO_PORTA);
			HSEVEN_SEGMENT_voidNum0(MDIO_PORTB);
		}
		else if (Copy_u8Temp == 12)
		{
			HSEVEN_SEGMENT_voidNum1(MDIO_PORTA);
			HSEVEN_SEGMENT_voidNum2(MDIO_PORTB);
		}
		else if (Copy_u8Temp == 14)
		{
			HSEVEN_SEGMENT_voidNum1(MDIO_PORTA);
			HSEVEN_SEGMENT_voidNum4(MDIO_PORTB);
		}
		else if (Copy_u8Temp == 16)
		{
			HSEVEN_SEGMENT_voidNum1(MDIO_PORTA);
			HSEVEN_SEGMENT_voidNum6(MDIO_PORTB);
		}
		else if (Copy_u8Temp == 18)
		{
			HSEVEN_SEGMENT_voidNum1(MDIO_PORTA);
			HSEVEN_SEGMENT_voidNum8(MDIO_PORTB);
		}
	}
}
