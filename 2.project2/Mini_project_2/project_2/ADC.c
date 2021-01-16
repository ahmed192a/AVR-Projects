/*
 * ADC.c
 *
 *  Created on: Oct 31, 2020
 *      Author: Ahmed
 */


#include "ADC.h"

volatile uint16 data;

ISR(ADC_vect){
	data = ADC;
}

void ADC_init(void){
	ADMUX = 0;	// set Vref = AREF
	ADCSRA = 0;
	SET_BIT(ADCSRA,ADEN); // Enable ADC
	SET_BIT(ADCSRA,ADPS1); // Prescaler Fcpu/8
	SET_BIT(ADCSRA,ADPS0); // Prescaler Fcpu/8
	SET_BIT(ADCSRA,ADIE);



}

void ADC_readchannel(uint8 channel_num){
	ADMUX = (ADMUX & 0xE0) | (channel_num & 0x03); // set channel number
	SET_BIT(ADCSRA,ADSC); //start conversion
	//while(BIT_IS_CLEAR(ADCSRA,ADIF)); // Polling until flag = 1
	//SET_BIT(ADCSRA,ADIF);	//clear flag
	//return ADC; // return data

}



