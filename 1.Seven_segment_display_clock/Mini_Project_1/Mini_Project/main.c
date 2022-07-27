/*
 * main.c
 *
 *  Created on: Oct 16, 2020
 *      Author: Ahmed Mohamed
 */


#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define time 50				// time for the delay

unsigned char sec = 0;		// seconds counter
unsigned char min = 0;		// minutes counter
unsigned char hours = 0;	// hours counter

// configure the timing variables
/**
 * @brief Construct a new ISR Method for Timer1 Compare Match A to increment the seconds counter,
 * 			 the minutes counter if the seconds counter reaches 60 seconds and the minutes counter reaches 60 minutes.
 * 
 */
ISR(TIMER1_COMPA_vect){
	sec++;
	if(sec == 60){
		sec = 0;
		min++;
	}
	if(min == 60){
		min = 0;
		hours++;
	}
	if(hours == 24){
		hours = 0;
	}
}

//reset the timer
/**
 * @brief Construct a new ISR Method for INT0 to reset the timer and the counters.
 * 
 */
ISR(INT0_vect){
	sec = 0;
	min = 0;
	hours = 0;
	TCNT1 = 0; // reset the timer counter
	TCCR1B |= (1<<CS12);  // resume the clock
}

// stop the timer
/**
 * @brief Construct a new ISR Method for INT1 to stop the timer and the counters.
 * 
 */
ISR(INT1_vect){
	TCCR1B &= ~(1<<CS12); //stop the clock
}

// resume the timer
/**
 * @brief Construct a new ISR Method for INT2 to resume the timer and the counters.
 * 
 */
ISR(INT2_vect){
	TCCR1B |= (1<<CS12); // resume the clock
}

/**
 * @brief Timer1 Initialization
 * 
 */
void TIMER1_init(void){
	TCCR1A = (1<<FOC1A) | (1<<FOC1B);	// non PWM 
	TCCR1B = (1<<WGM12) | (1<<CS12); 	// set the mode to CTC and the prescaler to 256
	TCNT1 = 0;							// start from 0
	OCR1A = 3907;						// top = 3907
	TIMSK = (1<<OCIE1A);				// enable timer interrupt
}

/**
 * @brief INT0 Initialization
 * 
 */
void INT0_init(void){
	DDRD &= ~(1<<PD2);		// set PD2 as input 
	PORTD |= (1<<PD2);		// enable internal pull down
	MCUCR |= (1<<ISC01);	// generate inturrpt with the falling edge	
	GICR |= (1<<INT0);		// enable INT0
}

/**
 * @brief INT1 Initialization
 * 
 */
void INT1_init(void){
	DDRD &= ~(1<<PD3);					// set PD3 as input 
	MCUCR |= (1<<ISC11) | (1<<ISC10);	// generate inturrpt with the rising edge
	GICR |= (1<<INT1);					// enable INT1

}

/**
 * @brief INT2 Initialization
 * 
 */
void INT2_init(void){
	DDRB &= ~(1<<PB2);		// set PB2 as input
	PORTB |= (1<<PB2);		// enable internal pull down
	MCUCSR &= ~(1<<ISC2);	// generate inturrpt with the falling edge
	GICR |= (1<<INT2);		// enable INT2
}

/**
 * @brief Main Function
 * 
 * @return int 0 to indicate success and 1 to indicate failure
 */
int main(void){
	SREG = (1<<7);		// enable I-bit	for the global interrupt
	TIMER1_init();		// initialize the timer
	INT0_init();		// initialize the INT0
	INT1_init();		// initialize the INT1
	INT2_init();		// initialize the INT2

	DDRA = 0x3F;		// Set PORTA as output (0 - 5)
	PORTA = 0xFF;		// At first enable all 7segments

	DDRC = 0x0F; 		// set first four pins in PORTC as outputs
	PORTC = 0; 			// At first display 0

	_delay_us(time);	// delay for the time

	while(1){

		//DISPLAY

		PORTA = 0x01; 		// enable 1st 7 segment
		PORTC = sec%10;		// Display 1st digit of seconds
		_delay_us(time);	// wait for 50 us

		PORTA = (PORTA<<1); // enable 2nd 7 segment
		PORTC =(sec)/10; 	// Display 2st digit of seconds
		_delay_us(time); 	// wait for 50 us

		PORTA = (PORTA<<1);// enable 3rd 7 segment
		PORTC = min%10;		// Display 1st digit of minutes
		_delay_us(time);	// wait for 50 us

		PORTA = (PORTA<<1);	// enable 4th 7 segment
		PORTC =(min)/10;	// Display 2st digit of minutes
		_delay_us(time);	// wait for 50 us

		PORTA = (PORTA<<1);	// enable 5th 7 segment
		PORTC = hours%10;	// Display 1st digit of hours
		_delay_us(time);	// wait for 50 us

		PORTA = (PORTA<<1);	// enable 6th 7 segment
		PORTC =(hours)/10;	// Display 2st digit of hours
		_delay_us(time);	// wait for 50 us
	}
}
