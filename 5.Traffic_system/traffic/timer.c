 /******************************************************************************
 *
 * Module: Timer
 *
 * File Name: timer.c
 *
 * Description: Source file for the timer driver
 *
 * Author: Ahmed Mohamed
 *
 *******************************************************************************/

#include "timer.h"

/*******************************************************************************
 *                           Global Variables                                  *
 *******************************************************************************/

/* Global variables to hold the address of the call back function in the application */
static volatile void (*timer0_callBackPtr)(void) = NULL_PTR;
static volatile void (*timer1_callBackPtr)(void) = NULL_PTR;
static volatile void (*timer2_callBackPtr)(void) = NULL_PTR;

/*******************************************************************************
 *                       Interrupt Service Routines                            *
 *******************************************************************************/

ISR(TIMER0_OVF_vect)
{
	if(timer0_callBackPtr != NULL_PTR)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*timer0_callBackPtr)();
	}
}

ISR(TIMER0_COMP_vect)
{
	if(timer0_callBackPtr != NULL_PTR)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*timer0_callBackPtr)();
	}
}

ISR(TIMER1_OVF_vect)
{
	if(timer1_callBackPtr != NULL_PTR)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*timer1_callBackPtr)();
	}
}

ISR(TIMER1_COMPA_vect)
{
	if(timer1_callBackPtr != NULL_PTR)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*timer1_callBackPtr)();
	}
}

ISR(TIMER1_COMPB_vect)
{
	if(timer1_callBackPtr != NULL_PTR)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*timer1_callBackPtr)();
	}
}

ISR(TIMER2_OVF_vect)
{
	if(timer2_callBackPtr != NULL_PTR)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*timer2_callBackPtr)();
	}
}

ISR(TIMER2_COMP_vect)
{
	if(timer2_callBackPtr != NULL_PTR)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*timer2_callBackPtr)();
	}
}

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
void TIMER0_init(const Timer_ConfigType * Config_Ptr)
{
	/* Clear Registers before do anything */
	/*TCCR0 &= 0x00;
	TCNT0 &= 0x00;
	OCR0  &= 0x00;
*/
	/* non PWM Mode */
	TCCR0 = (1<<FOC0);
	/*set initial value */
	TCNT0 = Config_Ptr->initial;
	/*set compare value for compare mode*/
	OCR0 = Config_Ptr->compare_value;


	if((Config_Ptr->OutputPin) == OC0){
		// configure the output pin PB3 in compare mode
		DDRB |= (1 << OC0);
	}

	if( (Config_Ptr -> mode ) == NORMAL_MODE) {
		/*Enable interrupt for overflow mode*/
		TIMSK |= (1 << TOIE0);
	}
	else if ( (Config_Ptr -> mode) == CTC_MODE){
		/*Enable interrupt for compare mode*/
		TIMSK |= (1 << OCIE0);
	}

	/*configure the mode of the timer*/
	TCCR0 =  (TCCR0 & ~(0x48) ) | ( ( (Config_Ptr->mode) << WGM00) & 0x48 ) ;
	/* Choose the operation that should be done in compare match occurs*/
	TCCR0 = (TCCR0 & 0XCF) | ( ( (Config_Ptr->compare_output) & 0X03) << COM00 );
	/* choose the timer clock (F_CPU / prescaler)*/
	TCCR0 = (TCCR0 & 0XF8) | (Config_Ptr->clock & 0X07);
}

void TIMER1_init(const Timer_ConfigType * Config_Ptr)
{
	/* Clear Registers before do anything */
/*			TCCR1A = 0x00;
			TCCR1B = 0x00;
*/
			/* 16 bit Registers */
/*			TCNT1  = 0;
			OCR1A  = 0;
			OCR1B  = 0;
*/
	/*set the initial value*/
	TCNT1 = ( (Config_Ptr -> initial) );
	/*  Non PWM Mode */
	TCCR1A = (1 << FOC1A) | (1 << FOC1B) ;
	if((Config_Ptr -> OutputPin) == OC1A){
	// configure the output pin PD5 in compare mode
		DDRD |= (1 << OC1A);
	}

	/* Check for OC1B */
	else if ((Config_Ptr -> OutputPin) == OC1B){
		// configure the output pin PD4 in compare mode
		DDRD |= (1 << OC1B);
	}
	if( (Config_Ptr->mode ) == NORMAL_MODE)
	{
		/* Enable interrupt FOR normal mode */
		TIMSK |= (1 << TOIE1);
	}
	else if ((Config_Ptr->mode) == CTC_MODE_CHANNEL_A)
	{
		/*set compare value for compare mode channel A*/
		OCR1A  = ((Config_Ptr->compare_value));
		/* Enable interrupt for compare mode channel A */
		TIMSK |= (1 << OCIE1A);
		/* Choose the operation that should be done in compare match occurs in channel A */
		TCCR1A = ( (TCCR1A & 0x3F) | ( (Config_Ptr -> compare_output) << COM1A0) );
	}

	else if ( (Config_Ptr->mode) == CTC_MODE_CHANNEL_B){
		/*set compare value for compare mode channel B*/
		OCR1B  = ((Config_Ptr -> compare_value));

		/* Enable interrupt for compare mode channel B */
		TIMSK |= (1 << OCIE1B);
		/* Choose the operation that should be done in compare match occurs in channel B */
		TCCR1A = ( (TCCR1A & 0xCF) | ( (Config_Ptr -> compare_output) << COM1B0) );

	}

	/*configure the mode of the timer*/
	TCCR1B = ( ( TCCR1B & 0xE7 ) |  ( ( (Config_Ptr -> mode) >> 1) << WGM12)  );
		/* choose the timer clock (F_CPU / prescaler)*/
	TCCR1B = ( ( TCCR1B & 0xF8 ) | (Config_Ptr -> clock) );
}

void TIMER2_init(const Timer_ConfigType * Config_Ptr)
{
	/* Clear Registers before do anything */
/*	TCCR2 &= 0x00;
	TCNT2 &= 0x00;
*/
	/*set the initail value of the timer*/
	TCNT2 = Config_Ptr->initial;
	/*set the compare value of the compare mode timer*/
	OCR2 = Config_Ptr->compare_value;
	/*non PWM mode*/
	TCCR2 = (1<<FOC2);

	/* Check which timer mode is chosen */
	if( (Config_Ptr -> mode ) == NORMAL_MODE) {
	/*	Enable interrupt for normal mode */
		TIMSK |= (1 << TOIE2);
	}
	else if ( (Config_Ptr -> mode) == CTC_MODE){

		/*	 Enable interrupt for compare mode */
		TIMSK |= (1 << OCIE2);
	}
	/*configure the mode of the timer*/
	TCCR2 = (TCCR2 & 0XB7) | ((Config_Ptr->mode & 0X48)<< WGM20);
	/* Choose the operation that should be done in compare match occurs*/
	TCCR2 = (TCCR2 & 0XCF) | ((Config_Ptr->compare_output & 0X03)<<COM20);
	/* choose the timer clock (F_CPU / prescaler)*/
	TCCR2 = (TCCR2 & 0XF8) | (Config_Ptr->clock & 0X07);
}

void Timer0_Stop()
{
	TCCR0 &= 0b11111000; // stop the clock
}

void Timer1_Stop(){
	TCCR1B &= 0b11111000; // stop the clock
}

void Timer2_Stop(){
	TCCR2 &= 0b11111000; // stop the clock
}



void Timer0_setCallBack(void(*a_ptr)(void))
{
	/* Save the address of the Call back function in a global variable */
	timer0_callBackPtr = a_ptr;
}
void Timer1_setCallBack(void(*a_ptr)(void))
{
	/* Save the address of the Call back function in a global variable 1*/
	timer1_callBackPtr = a_ptr;
}
void Timer2_setCallBack(void(*a_ptr)(void))
{
	/* Save the address of the Call back function in a global variable 2*/
	timer2_callBackPtr = a_ptr;
}
