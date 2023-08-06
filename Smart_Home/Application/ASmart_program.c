/*
 * ASmart_program.c
 *
 *  Created on: Sep 29, 2022
 *      Author: PC
 */

#include "../LIB/LIB_STD_TYPES.h"
#include "../LIB/LIB_BIT_MATH.h"

#include "../MCAL/MDIO/MDIO_interface.h"
#include "../MCAL/MTIMER/MTIMER_interface.h"
#include "../MCAL/MADC/MADC_interface.h"
#include "../MCAL/MGINTR/MGINTR_interface.h"

#include "../HAL/HCLCD/HCLCD_interface.h"
#include "../HAL/HKEY_PAD/HKEY_PAD_interface.h"
#include "../HAL/HKEY_PAD/HKEY_PAD_config.h"
#include "../HAL/HSERVO/HSERVO_interface.h"
#include "../HAL/HLED/LED_interface.h"

#include "ASmart_interface.h"

#include "avr/delay.h"

u8 Global_u8Led_Number = 0;
u8 Global_u8Door_State = 0;
u8 Global_u8Light_Intensity = 0;
u8 local_u8Check_Counter_false = 0;

u8 ASmart_u8PassCode ()
{
	u8 local_u8Pass_DefaultArr [12] = {9,8,7,6,5,4,3,2,1,9,8,7}; // PASSWOED SET
	u8 local_u8PASS_EnterArr [12];

	u8 local_u8False_Flag = 1;
	u8 local_u8Pass_digits_counter = 0;
	u8 local_u8PressedKey = HKYP_NOT_PRESSED;

	HCLCD_voidClear ();
	HCLCD_voidGoTo(HCLCD_ROW1, HCLCD_Column1) ;
	HCLCD_voidDisplay_String("Enter Pass :") ;
	_delay_ms(200);
	HCLCD_voidGoTo(HCLCD_ROW2, HCLCD_Column1);
	/***************************************Pass Enter***************************************/
	while(local_u8Pass_digits_counter < 12)
	{
		while(local_u8PressedKey == HKYP_NOT_PRESSED)
		{
			local_u8PressedKey = HKYP_u8GetPressedKey(); // wait until user press any key
		}

		local_u8PASS_EnterArr [ local_u8Pass_digits_counter ] = local_u8PressedKey ;

		HCLCD_voidDisplay_Number(local_u8PressedKey);
		_delay_ms(200);

		HCLCD_voidGoTo(HCLCD_ROW2, (local_u8Pass_digits_counter)) ;
		HCLCD_voidDisplay_Char('*');
		_delay_ms(50);

		local_u8Pass_digits_counter ++ ;
		local_u8PressedKey = HKYP_NOT_PRESSED ;
	}
	HCLCD_voidClear ();


	/***************************************Pass Check***************************************/

	for ( u8 local_u8Itr = 0 ; local_u8Itr < 12 ; local_u8Itr ++ )
	{
		if(local_u8PASS_EnterArr [local_u8Itr] == local_u8Pass_DefaultArr[local_u8Itr])
		{
			/*DO NOTHING AND Continue */
		}
		else if (local_u8PASS_EnterArr [local_u8Itr] != local_u8Pass_DefaultArr[local_u8Itr])
		{
			local_u8False_Flag = 0 ;
		}
	}

	if (local_u8False_Flag == 1)// true
	{
		local_u8Check_Counter_false = 0;
		HLED_voidOff(MDIO_PORTD, MDIO_PIN3);

		return 1 ;/*Right Pass*/
	}
	else if (local_u8False_Flag == 0)//false
	{

		if (local_u8Check_Counter_false == 2)
		{
			HCLCD_voidClear();
			HCLCD_voidDisplay_String("  SYSTEM BLOCK");
			HLED_voidBlinking(MDIO_PORTD, MDIO_PIN3);

			return 0 ;/*Three Fails*/
		}
		else
		{
			HLED_voidOn(MDIO_PORTD, MDIO_PIN3);
			HCLCD_voidClear();
			HCLCD_voidDisplay_String("  Wrong Pass!!");
			HCLCD_voidGoTo(HCLCD_ROW2, HCLCD_Column1);
			HCLCD_voidDisplay_String("    TRY AGAIN");
			local_u8Check_Counter_false ++;
			_delay_ms(2000);
			ASmart_u8PassCode ();/*Enter your Passcode Again*/
		}
	}
}

u8 Asmart_u8Mode_Selection ()
{
	HCLCD_voidClear();
	HCLCD_voidGoTo(HCLCD_ROW1, HCLCD_Column1);
	HCLCD_voidDisplay_String("  Welcome Home");
	_delay_ms(2000);

	HCLCD_voidClear ();

	HCLCD_voidDisplay_String("Chose Your Mode :") ;
	_delay_ms(1000);

	HCLCD_voidClear ();

	HCLCD_voidGoTo(HCLCD_ROW1, HCLCD_Column1) ;
	HCLCD_voidDisplay_String("ONE   >Light<") ;

	HCLCD_voidGoTo(HCLCD_ROW2, HCLCD_Column1) ;
	HCLCD_voidDisplay_String("TWO   >Garage<") ;

	u8 local_u8PressedKey = HKYP_NOT_PRESSED  ;

	while(local_u8PressedKey == HKYP_NOT_PRESSED)
	{
		local_u8PressedKey = HKYP_u8GetPressedKey(); // wait until user press any key
	}

	if(local_u8PressedKey == 1 )
	{
		HCLCD_voidClear ();
		HCLCD_voidGoTo(HCLCD_ROW1, HCLCD_Column1) ;
		HCLCD_voidDisplay_String("    >Light<") ;
		_delay_ms(2000);
		return local_u8PressedKey;
	}
	else if (local_u8PressedKey == 2 )
	{
		HCLCD_voidClear ();
		HCLCD_voidGoTo(HCLCD_ROW2, HCLCD_Column1) ;
		HCLCD_voidDisplay_String("   >Garage<") ;
		_delay_ms(2000);
		return local_u8PressedKey;
	}
	local_u8PressedKey = HKYP_NOT_PRESSED ;

}

void ASMART_voidGarage ()
{
	u8 local_u8Pass_Result = ASmart_u8PassCode();

	if (local_u8Pass_Result == 1)
	{
		HServo_Motor_voidON();
		Global_u8Door_State = 1;
		MTIMER0_voidSetOV_Value(45);
		MTIMER0_voidInit();
		MGIE_voidEnable();
		HCLCD_voidClear();
		HCLCD_voidDisplay_String("Garage System ON");
	}

	else if (local_u8Pass_Result ==0)
	{
		HLED_voidBlinking(MDIO_PORTD, MDIO_PIN3);
	}
	else { /* DO NOTHING*/ }
}

void ASMART_voidLight (void)
{
	u8 local_u8ADCValue = 0;
	local_u8ADCValue = MADC_u8ReadChannel(ADC_Channel_0);
	if (local_u8ADCValue >= 0 && local_u8ADCValue < 12)
	{
		HLED_voidOn(MDIO_PORTA,MDIO_PIN5);
		HLED_voidOn(MDIO_PORTA,MDIO_PIN6);
		HLED_voidOn(MDIO_PORTA,MDIO_PIN7);
		Global_u8Led_Number = 3;
		Global_u8Light_Intensity = 100;
	}
	else if (local_u8ADCValue >= 12 && local_u8ADCValue < 42)
	{
		HLED_voidOn(MDIO_PORTA,MDIO_PIN5);
		HLED_voidOn(MDIO_PORTA,MDIO_PIN6);
		HLED_voidOff(MDIO_PORTA,MDIO_PIN7);
		Global_u8Led_Number = 2;
		Global_u8Light_Intensity = 75;
		HCLCD_voidGoTo(HCLCD_ROW2, HCLCD_Column14);
		HCLCD_voidDisplay_String(" ");
	}
	else if (local_u8ADCValue >= 42 && local_u8ADCValue < 170)
	{
		HLED_voidOn(MDIO_PORTA,MDIO_PIN5);
		HLED_voidOff(MDIO_PORTA,MDIO_PIN6);
		HLED_voidOff(MDIO_PORTA,MDIO_PIN7);
		Global_u8Led_Number = 1;
		Global_u8Light_Intensity = 50;
		HCLCD_voidGoTo(HCLCD_ROW2, HCLCD_Column14);
		HCLCD_voidDisplay_String(" ");
	}
	else if (local_u8ADCValue == 170)
	{
		HLED_voidOff(MDIO_PORTA,MDIO_PIN5);
		HLED_voidOff(MDIO_PORTA,MDIO_PIN6);
		HLED_voidOff(MDIO_PORTA,MDIO_PIN7);
		Global_u8Led_Number = 0;
		Global_u8Light_Intensity = 0;
		HCLCD_voidGoTo(HCLCD_ROW2, HCLCD_Column13);
		HCLCD_voidDisplay_String("  ");
	}

	else { /*DO NOTHING*/ }
}
