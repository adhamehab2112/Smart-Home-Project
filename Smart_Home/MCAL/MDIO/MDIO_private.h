/*
 * MDIO_private.h
 *
 *  Created on: Sep 4, 2022
 *      Author: emad
 */

#ifndef MCAL_MDIO_PRIVATE_H_
#define MCAL_MDIO_PRIVATE_H_

#define PORTA  (*(volatile u8 *)0x3B)
#define DDRA   (*(volatile u8 *)0x3A)
#define PINA   (*(volatile u8 *)0x39)

#define PORTB  (*(volatile u8 *)0x38)
#define DDRB   (*(volatile u8 *)0x37)
#define PINB   (*(volatile u8 *)0x36)

#define PORTC  (*(volatile u8 *)0x35)
#define DDRC   (*(volatile u8 *)0x34)
#define PINC   (*(volatile u8 *)0x33)

#define PORTD  (*(volatile u8 *)0x32)
#define DDRD   (*(volatile u8 *)0x31)
#define PIND   (*(volatile u8 *)0x30)




#define CONC(b7,b6,b5,b4,b3,b2,b1,b0)			CONC_HELPER(b7,b6,b5,b4,b3,b2,b1,b0)
#define CONC_HELPER(b7,b6,b5,b4,b3,b2,b1,b0)	0b##b7##b6##b5##b4##b3##b2##b1##b0
/*Concatenate DIO DDR Direction*/
#define MDIO_DDRA_DIRECTION 	CONC(MDIO_DDRA_PIN7,MDIO_DDRA_PIN6,MDIO_DDRA_PIN5,MDIO_DDRA_PIN4,MDIO_DDRA_PIN3,MDIO_DDRA_PIN2,MDIO_DDRA_PIN1,MDIO_DDRA_PIN0)
#define MDIO_DDRB_DIRECTION 	CONC(MDIO_DDRB_PIN7,MDIO_DDRB_PIN6,MDIO_DDRB_PIN5,MDIO_DDRB_PIN4,MDIO_DDRB_PIN3,MDIO_DDRB_PIN2,MDIO_DDRB_PIN1,MDIO_DDRB_PIN0)
#define MDIO_DDRC_DIRECTION 	CONC(MDIO_DDRC_PIN7,MDIO_DDRC_PIN6,MDIO_DDRC_PIN5,MDIO_DDRC_PIN4,MDIO_DDRC_PIN3,MDIO_DDRC_PIN2,MDIO_DDRC_PIN1,MDIO_DDRC_PIN0)
#define MDIO_DDRD_DIRECTION 	CONC(MDIO_DDRD_PIN7,MDIO_DDRD_PIN6,MDIO_DDRD_PIN5,MDIO_DDRD_PIN4,MDIO_DDRD_PIN3,MDIO_DDRD_PIN2,MDIO_DDRD_PIN1,MDIO_DDRD_PIN0)

/*Concatenate DIO PORT Values*/
#define MDIO_PORTA_VALUE        CONC(MDIO_PORTA_PIN7,MDIO_PORTA_PIN6,MDIO_PORTA_PIN5,MDIO_PORTA_PIN4,MDIO_PORTA_PIN3,MDIO_PORTA_PIN2,MDIO_PORTA_PIN1,MDIO_PORTA_PIN0)
#define MDIO_PORTB_VALUE        CONC(MDIO_PORTB_PIN7,MDIO_PORTB_PIN6,MDIO_PORTB_PIN5,MDIO_PORTB_PIN4,MDIO_PORTB_PIN3,MDIO_PORTB_PIN2,MDIO_PORTB_PIN1,MDIO_PORTB_PIN0)
#define MDIO_PORTC_VALUE        CONC(MDIO_PORTC_PIN7,MDIO_PORTC_PIN6,MDIO_PORTC_PIN5,MDIO_PORTC_PIN4,MDIO_PORTC_PIN3,MDIO_PORTC_PIN2,MDIO_PORTC_PIN1,MDIO_PORTC_PIN0)
#define MDIO_PORTD_VALUE        CONC(MDIO_PORTD_PIN7,MDIO_PORTD_PIN6,MDIO_PORTD_PIN5,MDIO_PORTD_PIN4,MDIO_PORTD_PIN3,MDIO_PORTD_PIN2,MDIO_PORTD_PIN1,MDIO_PORTD_PIN0)


#endif /* MCAL_MDIO_PRIVATE_H_ */
