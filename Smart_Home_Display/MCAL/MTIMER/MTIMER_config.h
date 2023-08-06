/*
 * MTIMER_config.h
 *
 *  Created on: Sep 10, 2022
 *      Author: emad
 */

#ifndef MCAL_MTIMER_MTIMER_CONFIG_H_
#define MCAL_MTIMER_MTIMER_CONFIG_H_


/*
////////////////////////////////////////////TCCR0\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

   Bit	              7       6       5       4       3       2       1       0
                   ــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــ
   Bit_Name       |  FOC0 | WGM00 | COM01 | COM00 | WGM01 |  CS02 |  CS01 |  CS00 |
   Read/Write     |   W   |  R/W  |  R/W  |  R/W  |  R/W  |  R/W  |  R/W  |  R/W  |
   Initial Value  |___0___|___0___|___0___|___0___|___0___|___0___|___0___|___0___|


                   > Waveform Generation Mode <
					ـــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــ
                   | WGM01 | WGM00 |  Timer/Counter Mode  |
                   |======================================|
                   |   0   |   0   |  NORMAL              |
                   |   0   |   1   |  PHASE_CORRECT_PWM   |
                   |   1   |   0   |  CTC                 |  <--
                   |   1   |   1   |  FAST_PWM            |
                   ----------------------------------------

                   > Compare Match Output Mode <
					ـــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــ
                   | COM01 | COM00 |     Description      |
                   |======================================|
                   |   0   |   0   |  DISCONNECT_OC0      |  <--
                   |   0   |   1   |  TOGGLE_OC0          |
                   |   1   |   0   |  CLEAR_OC0           |
                   |   1   |   1   |  SET_OC0             |
                   ----------------------------------------

                   > Clock Select <
                   F = 8 MHz
					(1 / (F / Prescaller)) * 1000000
                    ـــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــ
                   | CS02 | CS01 | CS00 |    Character Size    |    Tick Time    |
                   |=============================================================|
                   |   0  |   0  |   0  |   NO_CLOCK_SCOUECE   |  Timer Stopped  |
                   |   0  |   0  |   1  |   PRESCALLER_1       |   0.125  us     |
                   |   0  |   1  |   0  |   PRESCALLER_8       |   1      us     |
                   |   0  |   1  |   1  |   PRESCALLER_64      |   8      us     |  <--
                   |   1  |   0  |   0  |   PRESCALLER_256     |   32     us     |
                   |   1  |   0  |   1  |   PRESCALLER_1024    |   128    us     |
                   ---------------------------------------------------------------

 	 ............................................*Choose from each table*............................................
 */
/**List your Selections here**/

/*Waveform Generation Mode*/
#define MTIMER0_WGM   NORMAL
/*Compare Match Output Mode*/
#define TIMER0_COM    DISCONNECT_OC0
/*Clock Select*/
#define MTIMER0_CS    PRESCALLER_1024


/*Waveform Generation Mode*/
#define MTIMER1_WGM   0b
/*Compare Match Output Mode*/
#define TIMER1_COM   DISCONNECT_OC0
/*Clock Select*/
#define MTIMER1_CS   PRESCALLER_1024

#endif /* MCAL_MTIMER_MTIMER_CONFIG_H_ */
