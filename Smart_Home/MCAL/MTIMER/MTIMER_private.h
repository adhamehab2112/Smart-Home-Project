/*
 * MTIMER_private.h
 *
 *  Created on: Sep 10, 2022
 *      Author: emad
 */

#ifndef MCAL_MTIMER_MTIMER_PRIVATE_H_
#define MCAL_MTIMER_MTIMER_PRIVATE_H_


/*Timer0 Registers */
 #define TCCR0             *((volatile u8*)0x53)       /*Timer0 control register*/
 #define OCR0              *((volatile u8*)0x5C)       /*Output compare register 0*/
 #define TIMSK             *((volatile u8*)0x59)       /*Timer mask*/
 #define TCNT0             *((volatile u8*)0x52)       /*Timer Counter*/

/*Timer0 Clock Selection*/
#define NO_CLOCK_SCOUECE   0b00000000
#define PRESCALLER_1       0b00000001
#define PRESCALLER_8       0b00000010
#define PRESCALLER_64      0b00000011
#define PRESCALLER_256     0b00000100
#define PRESCALLER_1024    0b00000101

/*Timer0 Mode*/
#define NORMAL             0b00000000
#define PHASE_CORRECT_PWM  0b01000000
#define CTC                0b00001000
#define FAST_PWM           0b01001000

/*Timer0 OC0*/
#define DISCONNECT_OC0     0b00000000
#define TOGGLE_OC0         0b00010000
#define CLEAR_OC0          0b00100000
#define SET_OC0            0b00110000




/*Timer1 Registers */

#define TCCR1A              *((volatile u8*)0x4F)
#define TCCR1B              *((volatile u8*)0x4E)
#define ICR1                *((volatile u16*)0x46)
#define OCR1A               *((volatile u16*)0x4A)
#define TCNT1               *((volatile u16*)0x4C)
#define OCR1B               *((volatile u16*)0x48)
/*Bits*/
#define TCCR1A_COM1A1       7
#define TCCR1A_COM1A0       6
#define TCCR1A_COM1B1       5
#define TCCR1A_COM1B0       4
#define TCCR1A_FOC1B 		2
#define TCCR1A_WGM11        1
#define TCCR1A_WGM10        0


#define TCCR1B_WGM13        4
#define TCCR1B_WGM12        3
#define TCCR1B_CS12         2         /*prescaler bit2*/
#define TCCR1B_CS11         1         /*prescaler bit1*/
#define TCCR1B_CS10         0         /*prescaler bit0*/





#endif /* MCAL_MTIMER_MTIMER_PRIVATE_H_ */
