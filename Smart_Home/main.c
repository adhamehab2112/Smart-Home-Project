/*
 * main.c
 *
 *  Created on: Sep 29, 2022
 *      Author: PC
 */

#include "LIB/LIB_STD_TYPES.h"
#include "LIB/LIB_BIT_MATH.h"

#include "MCAL/MDIO/MDIO_interface.h"
#include "MCAL/MTIMER/MTIMER_interface.h"
#include "MCAL/MUART/MUART_interface.h"
#include "MCAL/MADC/MADC_interface.h"
#include "MCAL/MEXTI/MEXTI_interface.h"
#include "MCAL/MGINTR/MGINTR_interface.h"

#include "HAL/HCLCD/HCLCD_interface.h"
#include "HAL/HKEY_PAD/HKEY_PAD_interface.h"
#include "HAL/HKEY_PAD/HKEY_PAD_config.h"
#include "HAL/HLED/LED_interface.h"
#include "HAL/HSERVO/HSERVO_interface.h"
#include "Application/ASmart_interface.h"

#include "avr/delay.h"
#define F_CPU 8000000UL

u8   global_Mode = 3;

extern u8 Global_u8Led_Number;
extern u8 Global_u8Door_State;
extern u8 Global_u8Light_Intensity;

void main (void)
{
	MDIO_voidInit()  ;

	HCLCD_voidInit() ;

	MTIMER1_voidInit();

	MEXTI_voidINT0();

	MADC_voidInit();

	MUART_voidInit();

	MGIE_voidEnable();

	while(1)
	{

		if (global_Mode == 1)
		{
			HCLCD_voidClear();

			while (global_Mode == 1)
			{
				ASMART_voidLight();

				HCLCD_voidGoTo(HCLCD_ROW1, HCLCD_Column1);
				HCLCD_voidDisplay_String("LED NUM:") ;
				HCLCD_voidGoTo(HCLCD_ROW1, HCLCD_Column10) ;
				HCLCD_voidDisplay_Number(Global_u8Led_Number);

				HCLCD_voidGoTo(HCLCD_ROW2, HCLCD_Column1) ;
				HCLCD_voidDisplay_String("LIGHT INT:") ;
				HCLCD_voidDisplay_MultiNumber(Global_u8Light_Intensity, HCLCD_ROW2, HCLCD_Column12);
				HCLCD_voidGoTo(HCLCD_ROW2, HCLCD_Column15);
				HCLCD_voidDisplay_Char('%');
			}

		}
		else if (global_Mode == 2)
		{
			ASMART_voidGarage();

			MUART_voidSendChar(Global_u8Door_State);
		}
		else { /* DO NOTHING*/ }
	}
}

void __vector_11(void)
{
	static u16 local_u16Counter = 0;
	local_u16Counter ++;
	if (local_u16Counter == 306)
	{
		MTIMER0_voidSetOV_Value(45);
		local_u16Counter = 0;
		HServo_Motor_voidOFF();
		Global_u8Door_State = 0;
		MUART_voidSendChar(Global_u8Door_State);
	}
	else { /*DO NOTHING*/ }
}

void __vector_1(void)
{
	global_Mode = Asmart_u8Mode_Selection();
//	MUART_voidSendChar(global_Mode);
}
