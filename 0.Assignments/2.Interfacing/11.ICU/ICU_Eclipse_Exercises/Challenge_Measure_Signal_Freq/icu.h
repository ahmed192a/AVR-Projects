 /******************************************************************************
 *
 * Module: ICU
 *
 * File Name: icu.h
 *
 * Description: Header file for the AVR ICU driver
 *
 * Author: Mohamed Tarek
 *
 *******************************************************************************/

#ifndef ICU_H_
#define ICU_H_

#include "std_types.h"
#include "common_macros.h"
#include "micro_config.h"

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
typedef enum
{
	NO_CLOCK,F_CPU_CLOCK,F_CPU_8,F_CPU_64,F_CPU_256,F_CPU_1024
}Icu_Clock;

typedef enum
{
	FALLING,RISING
}Icu_EdgeType;

typedef struct
{
	Icu_Clock clock;
	Icu_EdgeType edge;
}Icu_ConfigType;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * Description : Function to initialize the ICU driver
 * 	1. Set the required clock.
 * 	2. Set the required edge detection.
 * 	3. Enable the Input Capture Interrupt.
 * 	4. Initialize Timer1 Registers
 */
void Icu_init(const Icu_ConfigType * Config_Ptr);

/*
 * Description: Function to set the Call Back function address.
 */
void Icu_setCallBack(void(*a_ptr)(void));

/*
 * Description: Function to set the required edge detection.
 */
void Icu_setEdgeDetectionType(const Icu_EdgeType edgeType);

/*
 * Description: Function to get the Timer1 Value when the input is captured
 *              The value stored at Input Capture Register ICR1
 */
uint16 Icu_getInputCaptureValue(void);

/*
 * Description: Function to clear the Timer1 Value to start count from ZERO
 */
void Icu_clearTimerValue(void);

/*
 * Description: Function to disable the Timer1 to stop the ICU Driver
 */
void Icu_DeInit(void);

#endif /* ICU_H_ */
