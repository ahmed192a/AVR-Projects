/*
 * main2.c
 *
 *  Created on: Dec 8, 2020
 *      Author: ah132
 */

/***********************************************************************
								Includes
 ***********************************************************************/
#include "micro_config.h"
#include "timer.h"
#include "uart.h"
#include "uart_communication.h"
#include "external_eeprom.h"
#include "motor.h"

/* the length of the password*/
#define PASS_LENGTH 5


/************************************************************************
  	  	  	  	  	  	  	 Function Prototypes
 ***********************************************************************/
/* the call back function for timer1 interrupt*/
void Timer1_INT();

/************************************************************************
  	  	  	  	  	  	  	  Global Variables
 ***********************************************************************/
/* Flag to check how many times in row the password was entered wrong */
uint8 Wrong = 0;

/* Seconds Counter */
volatile uint8 g_timer1_SecFlag = 0;

/************************************************************************
  	  	  	  	  	  	  	  Main Function
 ***********************************************************************/
int main(){
	uint8 pass[5];
	uint8 check;
	uint8 message;
	uint8 flag;
	/* Enable Global Interrupt */
	SREG |= (1<<7);

	/* UART Structure for its configurations */
	UART_ConfigType uart_Struct;
	uart_Struct.BaudRate			= 9600;
	uart_Struct.InterruptMode		= POLLING;
	uart_Struct.ParityMode			= NO_PARIT_BITS;
	uart_Struct.StopBit				= STOP_BIT_1_BIT;

	/* Timer Structure for timer 1 configurations */
	/* Configure Timer1 to count for 1 Second*/
	Timer_ConfigType timer1_Strut;
	timer1_Strut.mode				= CTC_MODE_CHANNEL_A;
	timer1_Strut.compare_output		= NORMAL;
	timer1_Strut.OutputPin			= NONE;
	timer1_Strut.clock				= F_CPU_1024;
	timer1_Strut.initial			= 0;
	timer1_Strut.compare_value		= 7900;

	/*Buzzer Initialization*/
	SET_BIT(DDRC,2);
	CLEAR_BIT(PORTC,2);

	/*Motor Initialization*/
	motor_init();

	/* EEPROM Initialization */
	EEPROM_init();

	/* Timer 1 Initialization */
	TIMER1_init(&timer1_Strut);

	/* CallBack Function for timer 1 CTC Channel A Interrupt Function */
	Timer1_setCallBack(Timer1_INT);

	/* UART Initialization */
	UART_init(&uart_Struct);


	/* Wait till MC1 is ready */
	while(UART_recieveByte() != M1_READY){}



	while(1){
		flag = 1;
		/* Wait and Recieve for the message from MC1 */
		message = UART_recieveByte();
		_delay_ms(50);
		/*Check which Case to do*/
		switch (message){

		case NEW_PASSWORD:
			/*Get the new password form MC1 and Store it in EEPROM*/
			for(uint8 i = 0; i < 5; i++){
				/*Recieve one byte from the password*/
				message = UART_recieveByte();
				/*Write the password in the EEPROM*/
				EEPROM_writeByte( 0x0A+1+i , message);
				_delay_ms(100);
			}
			break;

		case CHECK_PASSWORD:
			/*Compare between the Recieved password and the Password Stored in the EEPROM*/
			for(uint8 i = 0; i < 5; i++){
				/*Recive one byte from the password from MC1*/
				check = UART_recieveByte();
				/* Get one Byte from the password from the EEPROM*/
				EEPROM_readByte(0x0A+1+i,&pass[i]);
				_delay_ms(50);
				/*Compare the PASSWORDS*/
				if(check != pass[i])
				{
					/*If the two passwords are not matched the flag will be 0 */
					/*if the two passwords are matched the flag will remain 1 */
					flag = 0;
				}
			}

			/* check if matched or not*/
			if(flag){
				/*Send that the two passwords are matched*/
				UART_sendByte(CORRECT_PASSWORD);
				Wrong = 0;
			}
			else{
				/*PASSWORDS not matched*/
				/*increase the wrong tries counter*/
				Wrong ++;
				/*if the passwords were not matched 3 times in row turn on the buzzer*/
				if(Wrong == 3){
					/*Send to MC1 that the password was entered wrong 3 times in row */
					UART_sendByte(PASSWORD_WRONG_3_TIMES);
					/*reset the wrong counter*/
					Wrong = 0;
					/*Reset the second counter*/
					g_timer1_SecFlag = 0;
					/*turn on the buzzer*/
					SET_BIT(PORTC,2);
					/*Wait for 10 seconds*/
					while(g_timer1_SecFlag<10){}
					/*turn off the buzzer*/
					CLEAR_BIT(PORTC,2);
				}
				else{
					/*Send wwrong password to MC1 if passwords not matched and the wrong counter < 3*/
					UART_sendByte(WRONG_PASSWORD);
				}
			}
			break;

		case OPEN_DOOR:
			/*Reset the second counter*/
			g_timer1_SecFlag = 0;
			/*Start the motor Clockwise*/
			motor_CW();
			/*Wait for 10 seconds*/
			while(g_timer1_SecFlag<10){}
			/*Stop the motor*/
			motor_stop();
			/*Wait for 2 seconds*/
			while(g_timer1_SecFlag<12){}
			/*Start the motor Anti Clockwise*/
			motor_ACW();
			/*Wait for 10 seconds*/
			while(g_timer1_SecFlag<22){}
			/*Stop the motor*/
			motor_stop();
			break;
		}
	}
}

/************************************************************************
  	  	  	  	  	  	  	  Functions Definition
 ***********************************************************************/
void Timer1_INT(){
	/* increment the timer counter every one second*/
	g_timer1_SecFlag++;
}


