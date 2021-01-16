/*
 * motor.h
 *
 *  Created on: Dec 8, 2020
 *      Author: ah132
 */

#ifndef MOTOR_H_
#define MOTOR_H_
#include "std_types.h"
#include "common_macros.h"
#include "micro_config.h"

void motor_init();
void motor_CW();
void motor_ACW();
void motor_stop();


#endif /* MOTOR_H_ */
