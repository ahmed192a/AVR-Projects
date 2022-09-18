/*
 * Challenge2.c
 *
 *  Created on: Mar 25, 2019
 *  Author: Mohamed Tarek
 */

#include <avr/io.h>
#include <avr/interrupt.h>

/* global variable contain the ticks count of the timer */
unsigned char g_tick = 0;

/* Interrupt Service Routine for timer0 compare mode */
ISR(TIMER0_COMP_vect)
{
	g_tick++;

	PORTC ^= (1<<PC0);     /* Toggle PC0 Pin to generate a 10Khz Clock */

	if(g_tick == 2)
	{
		PORTC ^= (1<<PC1); /* Toggle PC1 Pin to generate a 5Khz Clock */
	}
	else if(g_tick == 4)
	{
		PORTC ^= (1<<PC1); /* Toggle PC1 Pin to generate a 5Khz Clock */
		PORTC ^= (1<<PC2); /* Toggle PC2 Pin to generate a 2.5Khz Clock */
		g_tick = 0;
	}
}

void Timer0_CTC_Square_Wave_Init(void)
{
	TCNT0 = 0; // Set Timer Initial Value 0
	OCR0 = 50; // Set Compare Value

	TIMSK |= (1<<OCIE0); // Enable Timer0 Compare Interrupt

	/* Configure timer control register
	 * 1. Non PWM mode FOC0=1
	 * 2. CTC Mode WGM01=1 & WGM00=0
	 * 3. No need for OC0 in this example so COM00=0 & COM01=0
	 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
	 */
	TCCR0 = (1<<FOC0) | (1<<WGM01) | (1<<CS01);
}

int main(void)
{
	DDRC |= 0x07;   /* Configure PC0, PC1 and PC2 as output pins */
	PORTC &= 0xF8;  /* Clear PC0, PC1 and PC2 pins */

	SREG |= (1<<7); /* Enable global interrupts in MC */

	Timer0_CTC_Square_Wave_Init();

    while(1)
    {

    }
}
