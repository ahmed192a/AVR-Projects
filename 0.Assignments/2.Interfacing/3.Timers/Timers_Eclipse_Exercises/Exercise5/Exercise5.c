/*
 * Exercise5.c
 *
 *  Created on: Jun 20, 2017
 *  Author: Mohamed Tarek
 */

#include <avr/io.h>
#include <util/delay.h>

void Timer0_PWM_Init(unsigned char set_duty_cycle)
{
	TCNT0 = 0; // Set Timer Initial Value to 0

	OCR0  = set_duty_cycle; //Set Compare value

	DDRB  = DDRB | (1<<PB3); // Configure PB3/OC0 as output pin --> pin where the PWM signal is generated from MC

	/* Configure timer control register
	 * 1. Fast PWM mode FOC0=0
	 * 2. Fast PWM Mode WGM01=1 & WGM00=1
	 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
	 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
	 */
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
}

int main(void)
{
	unsigned char duty;
	while(1)
	{
		for(duty = 0 ; duty < 255 ; duty++)
		{
			/*increase the LED light intensity*/
			Timer0_PWM_Init(duty);
			_delay_ms(10);
		}
		_delay_ms(100);
		for(duty = 255 ; duty > 0 ; duty--)
		{
			/*decrease the LED light intensity*/
			Timer0_PWM_Init(duty);
			_delay_ms(10);
		}
	}
}
