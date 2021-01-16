/*
 * main.c
 *
 *  Created on: Nov 1, 2020
 *      Author: Ahmed Mohamed
 */

#include "ADC.h"
#include "lcd.h"
#include "micro_config.h"


ISR(INT1_vect){
	/* change the direction of the motor */
	TOGGLE_BIT(PORTB,PB1);
	TOGGLE_BIT(PORTB,PB2);
}

void INT1_init(void){
	/* set PD2 as input */
	CLEAR_BIT(DDRD,PD3);

	/* generate interrupt with the falling edge */
	SET_BIT(MCUCR, ISC10);
	SET_BIT(MCUCR, ISC11);

	/* enable INT0 */
	SET_BIT(GICR, INT1);

}

void PWM_Timer0_Init()
{

	TCNT0 = 0; 			/* Set Timer Initial value */
	OCR0 = data/4; 		/* Set Compare Value */

	/* set PB3/OC0 as output pin --> pin where the PWM signal is generated from MC */
	SET_BIT(DDRB, PB3);

	/* Configure timer control register
	 * 1. Fast PWM mode FOC0=0
	 * 2. Fast PWM Mode WGM01=1 & WGM00=1
	 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
	 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
	 */
	SET_BIT(TCCR0, WGM00);
	SET_BIT(TCCR0, WGM01);
	SET_BIT(TCCR0, COM01);
	SET_BIT(TCCR0, CS01);

}





int main(void)
{
	SET_BIT(SREG,7);	/* enable I-bit */

	INT1_init();	/* initialize INTERRUPT 1 */
	LCD_init(); 	/* initialize LCD driver */
	ADC_init();		/* initialize ADC driver */

	/* READ initial potentiometer value (PWM duty cycle) */
	ADC_readchannel(PA0);

	/* initialize TIMER driver on PWM mode with duty cycle changes with the reading of the Potentiometer */
	PWM_Timer0_Init();

	/* configure pin PB1 and PB2 as output pins (control the motor direction)*/
	SET_BIT(DDRB,PB1);
	SET_BIT(DDRB,PB2);

	/* Motor is stop at the beginning */
	CLEAR_BIT(PORTB,PB1);
	SET_BIT(PORTB,PB2);

	/* clear LCD at the beginning */
	LCD_clearScreen();

	/* display this string "ADC Value = " only once at LCD */
	LCD_displayString("ADC Value = ");

    while(1)
    {
    	LCD_goToRowColumn(0,12); /* display the number every time at this position */
    	ADC_readchannel(PA0);	/* READ the ADC value */
    	LCD_intgerToString(data); /* display the ADC value on LCD screen */

    	OCR0 = data/4; /* changes the duty cycle */
    }
}



