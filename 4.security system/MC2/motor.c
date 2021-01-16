/*
 * motor.c
 *
 *  Created on: Dec 8, 2020
 *      Author: ah132
 */
#include "motor.h"


void motor_init(){
	SET_BIT(DDRB,1);
	SET_BIT(DDRB,2);
	SET_BIT(DDRB,3);

	CLEAR_BIT(PORTB,1);
	CLEAR_BIT(PORTB,2);
	SET_BIT(PORTB,3);
}

void motor_CW(){
	SET_BIT(PORTB,1);
	CLEAR_BIT(PORTB,2);
}
void motor_ACW()
{
	CLEAR_BIT(PORTB,1);
	SET_BIT(PORTB,2);
}
void motor_stop(){
	CLEAR_BIT(PORTB,1);
	CLEAR_BIT(PORTB,2);
}

