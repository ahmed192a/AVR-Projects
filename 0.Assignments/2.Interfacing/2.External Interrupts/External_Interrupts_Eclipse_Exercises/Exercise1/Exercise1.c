/*
 * Exercise1.c
 *
 * Created: 3/3/2014 9:45:25 PM
 * Author: Mohamed Tarek
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

/* External INT0 Interrupt Service Routine */
ISR(INT0_vect)
{
	PORTC = PORTC ^ (1<<PC0); //Toggle value of PIN 0 in PORTC (Led Toggle)
}

/* External INT0 enable and configuration function */
void INT0_Init(void)
{
	SREG  &= ~(1<<7);                   // Disable interrupts by clearing I-bit
	DDRD  &= (~(1<<PD2));               // Configure INT0/PD2 as input pin
	GICR  |= (1<<INT0);                 // Enable external interrupt pin INT0
	MCUCR |= (1<<ISC00) | (1<<ISC01);   // Trigger INT0 with the raising edge
	SREG  |= (1<<7);                    // Enable interrupts by setting I-bit
}

int main(void)
{
	INT0_Init();              // Enable external INT0

	DDRC  = DDRC | (1<<PC0);  // Configure pin PC0 in PORTC as output pin
	PORTC = PORTC | (1<<PC0); // Set Value of PIN 0 in PORTC to 1 at the beginning (LED OFF)
	
    while(1)
    {
							
	}					
}
