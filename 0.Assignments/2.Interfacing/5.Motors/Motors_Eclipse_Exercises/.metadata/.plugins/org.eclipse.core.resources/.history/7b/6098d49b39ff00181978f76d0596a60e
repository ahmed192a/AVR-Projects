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

void PWM_Timer0_Init(unsigned char set_duty_cycle){
	
	TCNT0 = 0; //initial timer value
	
	OCR0  = set_duty_cycle; 
	
	DDRB  = DDRB | (1<<PB3); //set OC0 as output pin --> pin where the PWM signal is generated from MC.
	
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
	
	DDRA = DDRA & (~(1<<PA0)); // configure pin 0 of PORTA as input pin
	DDRA = DDRA & (~(1<<PA1)); // configure pin 1 of PORTA as input pin
	DDRA = DDRA & (~(1<<PA2)); // configure pin 2 of PORTA as input pin
	DDRC = DDRC | (1<<PC0);    // configure pin 3 of PORTC as output pin
	DDRC = DDRC | (1<<PC1);    // configure pin 4 of PORTC as output pin
	
	//Motor is stop at the beginning
	PORTC &= ~((1<<PC0) | (1<<PC1));
	 
    while(1)
    {
		// check if the first switch is pressed (Rotate clock wise)
		if(PINA & (1<<PA0))
		{
			PORTC = PORTC & (~(1<<PC0));
			PORTC = PORTC | (1<<PC1);
		}
		
		// check if the second switch is pressed (Rotate anti-clock wise)
		else if(PINA & (1<<PA1))
		{
			PORTC = PORTC | (1<<PC0);
			PORTC = PORTC & (~(1<<PC1));	
		}
				
		// check if the third switch is pressed (turn off the motor)
		else if(PINA & (1<<PA2))
		{
			PORTC = PORTC & (~(1<<PC0));
			PORTC = PORTC & (~(1<<PC1));
		}				    
    }
}
