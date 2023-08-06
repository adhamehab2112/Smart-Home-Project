/*
 * MEXTI_interface.h
 *
 *  Created on: Sep 7, 2022
 *      Author: Eng. Karim
 */

#ifndef MCAL_MEXTI_MEXTI_INTERFACE_H_
#define MCAL_MEXTI_MEXTI_INTERFACE_H_
#include<avr/io.h>
#include "comm_macros.h"
#include "std_types.h"

void MCAL_EXTI_voidINT0 (void);
void MCAL_EXTI_voidINT1 (void);
void MCAL_EXTI_voidINT2 (void);

void (* ptr_to_func)(void) ;

/**** ISR Prototyping *****/
void __vector_1(void) __attribute__((signal));
void __vector_2(void) __attribute__((signal));
void __vector_3(void) __attribute__((signal));

#endif /* MCAL_MEXTI_MEXTI_INTERFACE_H_ */

