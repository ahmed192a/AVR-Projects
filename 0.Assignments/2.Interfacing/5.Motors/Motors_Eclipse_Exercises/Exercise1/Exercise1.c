/*
 * Exercise1.c
 *
 * Created: 11/23/2013 1:36:59 AM
 * Author: Mohamed Tarek
 */

#include <avr/io.h>

int main(void)
{
	/* configure pin PA0, PA1 and PA2 as input pins */ 
	DDRA &= 0xF8;
	
	/* configure pin PC0 and PC1 as output pins */
	DDRC |= 0x03;
	
	/* Motor is stop at the beginning */
	PORTC &= 0xFC;
	 
    while(1)
    {
		/* check if the first push button at PA0 is pressed/not */
		if(PINA & (1<<PA0))
		{
			// Rotate the motor --> clock wise
			PORTC &= (~(1<<PC0));
			PORTC |= (1<<PC1);
		}
		
		/* check if the second push button at PA1 is pressed/not */
		else if(PINA & (1<<PA1))
		{
			// Rotate the motor --> anti-clock wise
			PORTC |= (1<<PC0);
			PORTC &= (~(1<<PC1));	
		}
				
		/* check if the third push button at PA2 is pressed/not */
		else if(PINA & (1<<PA2))
		{
			// Stop the motor
			PORTC &= (~(1<<PC0));
			PORTC &= (~(1<<PC1));
		}				    
    }
}
