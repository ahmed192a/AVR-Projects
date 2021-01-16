/*
 * main.c
 *
 *  Created on: Dec 8, 2020
 *      Author: ah132
 */


#include "micro_config.h"
#include "timer.h"
#include "lcd.h"



uint8 g_edgeCount = 0;
uint16 g_timeHigh = 0;
uint16 g_timePeriod = 0;
uint16 g_timePeriodPlusHigh = 0;



ISR(INT0_vect){
	g_edgeCount++;
	switch (g_edgeCount){
	case 1:
		TCNT1 = 0;
		TOGGLE_BIT(MCUCR,ISC00);
		break;
	case 2:
		g_timeHigh = TCNT1;
		TOGGLE_BIT(MCUCR,ISC00);
		break;
	case 3:
		g_timePeriod = TCNT1;
		TOGGLE_BIT(MCUCR,ISC00);
		break;
	case 4:
		g_timePeriodPlusHigh = TCNT1;
		TOGGLE_BIT(MCUCR,ISC00);
		TCNT1 = 0;
		break;
	}

}

int main(){
	uint32 dutyCycle = 0;

	/* Timer Structure for timer 1 configurations */
	Timer_ConfigType timer1_Strut;

	timer1_Strut.mode				= NORMAL;
	timer1_Strut.compare_output		= NORMAL;
	timer1_Strut.OutputPin			= NONE;
	timer1_Strut.clock				= F_CPU_CLOCK;
	timer1_Strut.initial			= 0;

	TIMER1_init(&timer1_Strut);
	LCD_init();

	SET_BIT(MCUCR,ISC01);
	SET_BIT(MCUCR,ISC00);
	SET_BIT(GICR,INT0);
	SET_BIT(SREG,7);



	while(1){

		if(g_edgeCount == 4)
		{
			g_edgeCount = 0;
			LCD_clearScreen();
			LCD_goToRowColumn(0,0);
			LCD_displayString("Duty = ");
			/* calculate the dutyCycle */
			dutyCycle = ((float)(g_timePeriodPlusHigh-g_timePeriod) / (g_timePeriodPlusHigh - g_timeHigh)) * 100;
			/* display the dutyCycle on LCD screen */
			LCD_intgerToString(dutyCycle);
			LCD_displayCharacter('%');

		}

	}
}

