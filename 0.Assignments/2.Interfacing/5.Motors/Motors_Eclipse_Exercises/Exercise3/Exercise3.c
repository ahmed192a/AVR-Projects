/*
 * Exercise3.c
 *
 *  Created on: Jun 11, 2017
 *  Author: Mohamed Tarek
 */

#include <avr/io.h>
#include <util/delay.h>

#define FULL_WAVE_STEPS 4

int main()
{
	unsigned char motor_steps[FULL_WAVE_STEPS] = {12,6,3,9};
	unsigned char count = 0;
	DDRA &= ~(1<<PA2); // Configure PA2 as input pin
	DDRC |= 0x0F;      // Configure first 4 pins in PORTC as output pins
	PORTC &= 0xF0;     // Clear first four bits in PORTC
	while(1)
	{
		if(PINA & (1<<PA2)) // check if the button is pressed/not
		{
			_delay_ms(30);
			// second check for the de-bounce
			if(PINA & (1<<PA2))
			{
				// move the motor to the next step
				PORTC = (motor_steps[count] & 0x0F) | (PORTC & 0xF0);
				count++;
				if(count == FULL_WAVE_STEPS)
				{
					//start from the beginning after finish the full motor rotation.
					count = 0;
				}
			}
			while(PINA & (1<<PA2)); // wait until the push button is released
		}
	}
}
