/*
 * MEXTI_private.h
 *
 *  Created on: Sep 7, 2022
 *      Author: Eng. Karim
 */

#ifndef MCAL_MEXTI_MEXTI_PRIVATE_H_
#define MCAL_MEXTI_MEXTI_PRIVATE_H_

#define GICR       (*(volatile u8*)0x5B)
#define GIFR       (*(volatile u8*)0x5A)
#define MCUCR      (*(volatile u8*)0x55)
#define MCUCSR     (*(volatile u8*)0x54)

#define I_BIT      7

#define INT1       7
#define ISC11      3
#define ISC10      2

#define INT0       6
#define ISC01      1
#define ISC00      0

#define INT2       5
#define ISC2       1

#endif /* MCAL_MEXTI_MEXTI_PRIVATE_H_ */
