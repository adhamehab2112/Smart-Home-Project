/*
 * MTIMER_interface.h
 *
 *  Created on: Sep 10, 2022
 *      Author: emad
 */

#ifndef MCAL_MTIMER_MTIMER_INTERFACE_H_
#define MCAL_MTIMER_MTIMER_INTERFACE_H_

/*Timer0*/
void MTIMER0_voidInit(void);
void MTIMER0_voidSetOV_Value(u8 Copy_u8Value);
void MTIMER0_voidSetCTC_Value(u8 Copy_u8Value);

void MTIMER0_voidSetCallback(void (* ptrFun)(void));

/*Time0 CTC Interrupt*/
void __vector_10(void) __attribute__((signal)) ;
/*Time0 OVF Interrupt*/
void __vector_11(void) __attribute__((signal)) ;

/**********************************************************************************************************/
/*Timer1*/
void MTIMER1_voidInit(void);
void MTIMER1_voidSetICR1(u16 Copy_u16TOP);
void MTIMER1_voidSetOV(u16 Copy_u16OV);
void MTIMER1_voidSetCTC(u16 Copy_u16Value);
void MTIMER1_voidSetFastPWM_Value(u16 Copy_u16Value);

void MTIMER1_voidSetCallback(void (* ptrFun)(void));

#endif /* MCAL_MTIMER_MTIMER_INTERFACE_H_ */
