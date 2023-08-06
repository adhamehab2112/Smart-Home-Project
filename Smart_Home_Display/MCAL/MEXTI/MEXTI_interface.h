/*
 * MEXTI_interface.h
 *
 *  Created on: Sep 7, 2022
 *      Author: Eng. Karim
 */

#ifndef MCAL_MEXTI_MEXTI_INTERFACE_H_
#define MCAL_MEXTI_MEXTI_INTERFACE_H_

void MEXTI_voidINT0 (void);
void MEXTI_voidINT1 (void);
void MEXTI_voidINT2 (void);

void __vector_1(void) __attribute__((signal));
void __vector_2(void) __attribute__((signal));
void __vector_3(void) __attribute__((signal));

#endif /* MCAL_MEXTI_MEXTI_INTERFACE_H_ */
