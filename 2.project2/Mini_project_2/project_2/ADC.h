/*
 * ADC.h
 *
 *  Created on: Oct 31, 2020
 *      Author: Ahmed
 */



#ifndef ADC_H_
#define ADC_H_

#include "common_macros.h"
#include "micro_config.h"
#include "std_types.h"

extern volatile uint16 data;

void ADC_init(void);
void ADC_readchannel(uint8 channel_num);


#endif /* ADC_H_ */
