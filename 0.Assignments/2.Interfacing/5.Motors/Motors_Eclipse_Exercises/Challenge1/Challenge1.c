/*
 * Challenge1.c
 *
 *  Created on: Jun 11, 2017
 *  Author: Mohamed Tarek
 */

#include <avr/io.h>
#include <util/delay.h>

#define HALF_WAVE_STEPS 8

int main()
{
	unsigned char motor_steps[HALF_WAVE_STEPS] = {8,12,4,6,2,3,1,9};
	unsigned char count = 0;
	DDRC |= 0x0F;  // Configure first 4 pins in PORTC as output pins
	PORTC &= 0xF0; // Clear first four bits in PORTC
	while(1)
	{
		// move the motor to the next step
		PORTC = (motor_steps[count] & 0x0F) | (PORTC & 0xF0);
		count++;
		if(count == HALF_WAVE_STEPS)
		{
			//start from the beginning after finish the full motor rotation.
			count = 0;
		}
		_delay_ms(500);
	}
}
