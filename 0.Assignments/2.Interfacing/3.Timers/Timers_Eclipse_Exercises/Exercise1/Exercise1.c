/*
 * Exercise1_Normal_Mode.c
 *
 * Created: 1/21/2014 11:29:49 PM
 *  Author: Mohamed Tarek
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

#define NUMBER_OF_OVERFLOWS_PER_HALF_SECOND 2

/* global variable contain the ticks count of the timer */
unsigned char g_tick = 0;

ISR(TIMER0_OVF_vect)
{
	g_tick++;
	if(g_tick == NUMBER_OF_OVERFLOWS_PER_HALF_SECOND)
	{
		PORTC = PORTC ^ (1<<PC0); //toggle led every 0.5 second
		g_tick = 0; //clear the tick counter again to count a new 0.5 second
	}
}

/* Description : 
 * For clock=1Mhz and prescale F_CPU/1024 every count will take 1ms
 * so put initial timer counter = 0  0 --> 255 (256ms per overflow)
 * so we need timer to overflow 2 times to get a 0.5 second 
 */
void timer0_init_normal_mode(void)
{
	TCNT0 = 0; //Set Timer initial value to 0
	TIMSK |= (1<<TOIE0); // Enable Timer0 Overflow Interrupt
	/* Configure the timer control register
	 * 1. Non PWM mode FOC0=1
	 * 2. Normal Mode WGM01=0 & WGM00=0
	 * 3. Normal Mode COM00=0 & COM01=0 
	 * 4. clock = F_CPU/1024 CS00=1 CS01=0 CS02=1
	 */
	TCCR0 = (1<<FOC0) | (1<<CS02) | (1<<CS00);
}

int main(void)
{
	DDRC  |= (1<<PC0);  // Configure the led pin as output pin.
	PORTC &= ~(1<<PC0); // LED is OFF at the beginning (Positive Logic).
	SREG  |= (1<<7);    //Enable global interrupts in MC by setting the I-Bit.
	timer0_init_normal_mode(); //start the timer.
    while(1)
    {			
       
    }
}
