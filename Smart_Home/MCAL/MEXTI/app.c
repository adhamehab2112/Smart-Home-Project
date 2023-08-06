#include <avr/io.h>
#include <avr/interrupt.h> // sei(); -> global interrupt
#include <util/delay.h>
#define F_CPU 800000000ul
#include "MEXTI_interface.h"

void IRQ_Handller(void)
{
	// to be executed in ISR 
}

int main()
{
	MCAL_EXTI_voidINT0();
	ptr_to_func = IRQ_Handller ; 
	sei();
	while(1)
	{
	 // loop for ever 	
	}
	return 0 ; 
}