 /******************************************************************************
 *
 * Module: Timer
 *
 * File Name: timer.h
 *
 * Description: Header file for the timer driver
 *
 * Author: Ahmed Mohamed
 *
 *******************************************************************************/

#ifndef TIMER_H_
#define TIMER_H_

#include "std_types.h"
#include "micro_config.h"
#include "common_macros.h"


/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
typedef enum
{
	NO_CLOCK,F_CPU_CLOCK,F_CPU_8,F_CPU_64,F_CPU_256,F_CPU_1024,EXTERNAL_FALLING,EXTERNAL_RISING
}Timer_Clock;

typedef enum
{
	NORMAL_MODE,
	CTC_MODE,
	CTC_MODE_CHANNEL_A,
	CTC_MODE_CHANNEL_B
}Timer_Mode;


typedef enum{

	NONE,
	OC0  = PB3,
	OC1B = PD4,
	OC1A = PD5,
	OC2  = PD7

}Timer_OutputComparePinsType;

typedef enum
{
	NORMAL,TOGGLE_ON_COMPARE,CLEAR_ON_COMPARE,SET_ON_COMPARE
}C_Output_Mode;


typedef struct
{
	Timer_Clock clock;
	Timer_Mode mode;
	C_Output_Mode compare_output;
	Timer_OutputComparePinsType OutputPin;
	uint16 initial;
	uint16 compare_value ;



}Timer_ConfigType;


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void TIMER0_init(const Timer_ConfigType * Config_Ptr);
void TIMER1_init(const Timer_ConfigType * Config_Ptr);
void TIMER2_init(const Timer_ConfigType * Config_Ptr);
void Timer0_setCallBack(void(*a_ptr)(void));
void Timer1_setCallBack(void(*a_ptr)(void));
void Timer2_setCallBack(void(*a_ptr)(void));

void Timer0_Stop();

void Timer1_Stop();

void Timer2_Stop();

#endif /* TIMER_H_ */
