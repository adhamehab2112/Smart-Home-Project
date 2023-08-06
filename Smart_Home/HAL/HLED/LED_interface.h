/*
 * LED_interface.h
 *
 *  Created on: Sep 16, 2022
 *      Author: Eng. Karim
 */

#ifndef HAL_HLED_LED_INTERFACE_H_
#define HAL_HLED_LED_INTERFACE_H_

void HLED_voidOn (u8 Copy_u8Port, u8 Copy_u8Pin);
void HLED_voidOff (u8 Copy_u8Port, u8  Copy_u8Pin);
void HLED_voidToggle (u8 Copy_u8Port, u8  Copy_u8Pin);
void HLED_voidBlinking (u8 Copy_u8Port, u8  Copy_u8Pin);

#endif /* HAL_HLED_LED_INTERFACE_H_ */
