/*
 * Exercise2.c
 *
 * Created: 11/23/2013 1:36:59 AM
 *  Author: Mohamed Tarek
 */
 
 /* Description: 
  * Control the DC Motor direction using L293D H-bridge.
  * Control The DC Motor Speed using PWM from MC. connect the
  * PWM PIN of Timer0 OC0(PB3) to the enable of the Motor. 
  * duty cycle 100% --> Maximum Speed 
  * duty cycle 50%  --> Half Maximum Speed
  * duty cycle 0%   --> Motor Stop
  */
 
#include <avr/io.h>

void PWM_Timer0_Init(unsigned char set_duty_cycle)
{
	
	TCNT0 = 0; //Set Timer Initial value
	
	OCR0  = set_duty_cycle; // Set Compare Value
	
	DDRB  = DDRB | (1<<PB3); //set PB3/OC0 as output pin --> pin where the PWM signal is generated from MC.
	
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
	PWM_Timer0_Init(128); //generate duty cycle 50% to get half motor speed
	
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
