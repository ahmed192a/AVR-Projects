/*
 * main1.c
 *
 *  Created on: Dec 8, 2020
 *      Author: ah132
 */
/***********************************************************************
								Includes
 ***********************************************************************/

#include "micro_config.h"
#include "keypad.h"
#include "lcd.h"
#include "timer.h"
#include "uart.h"
#include "uart_communication.h"

/* the length of the password*/
#define PASS_LENGTH 5



/************************************************************************
  	  	  	  	  	  	  	 Function Prototypes
 ***********************************************************************/
void Timer1_INT();
void Start_APP();
void Main_APP();
void Enter_Pass();
void Change_Pass();
uint8 Compare (uint8 array1[],uint8 array2[]);

/************************************************************************
  	  	  	  	  	  	  	  Global Variables
 ***********************************************************************/
/* Flag to check is the two passwords are matched*/
uint8 compare = 0;

/* Seconds Counter */
volatile uint8 g_timer1_SecFlag = 0;


/************************************************************************
  	  	  	  	  	  	  	  Main Function
 ***********************************************************************/
int main(){
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


	/* LCD Initialization */
	LCD_init();

	/* Timer 1 Initialization */
	TIMER1_init(&timer1_Strut);

	/* CallBack Function for timer 1 CTC Channel A Interrupt Function */
	Timer1_setCallBack(Timer1_INT);

	/* UART Initialization */
	UART_init(&uart_Struct);

	/* Send to MC2 that MC1 is ready */
	UART_sendByte(M1_READY) ;

	/*Clear the LCD*/
	LCD_clearScreen();
	/* Start from first Pixel */
	LCD_goToRowColumn(0,0);
	/*Display welcome message*/
	LCD_displayString("Welcome ;)");
	_delay_ms(500);

	/*main code*/
	while(1){
		/*check if there is no pass before*/
		while(compare == 0){
			/*Starting from the first and enter the new password*/
			Start_APP();
		}
		/*Start the main application*/
		Main_APP();
	}



}


/************************************************************************
  	  	  	  	  	  	  	  Functions Definition
 ***********************************************************************/
void Start_APP(){
	uint8 pass[PASS_LENGTH];
	uint8 conf[PASS_LENGTH];
	uint8 key;
	uint8 i;

	/*Clear the LCD*/
	LCD_clearScreen();
	/* Start from first Pixel */
	LCD_goToRowColumn(0,0);
	LCD_displayString("ENTER password");
	/* Start from second row - first Pixel */
	LCD_goToRowColumn(1,0);

	/* Get the password from the user*/
	for (i = 0; i < PASS_LENGTH; i++){
		/*Get the pressed key from keypad*/
		key = KeyPad_getPressedKey();
		if ((key >= 0) && (key <= 9))
		{
			/*Save the key in password array*/
			pass[i] = key;
			LCD_displayStringRowColumn(1,i,"*");
			//LCD_intgerToString(key);
		}
		_delay_ms(500);
	}

	/*Clear the LCD*/
	LCD_clearScreen();
	/* Start from first Pixel */
	LCD_goToRowColumn(0,0);
	LCD_displayString("CONFIRM password");
	/* Start from second row - first Pixel */
	LCD_goToRowColumn(1,0);
	/*Get the confirmed password*/
	for (i = 0; i < PASS_LENGTH; i++){
		/*Get the pressed key from keypad*/
		key = KeyPad_getPressedKey();
		if ((key >= 0) && (key <= 9))
		{
			/*Save the key in Confirm array*/
			conf[i] = key;
			LCD_displayStringRowColumn(1,i,"*");
			//LCD_intgerToString(key);
		}
		_delay_ms(500);
	}
	/*Compare the password and the confirmed password*/
	compare = Compare(pass,conf);


	if (compare){
		/*the password and the confirmed password are matched*/
		/*Clear the LCD*/
		LCD_clearScreen();
		/* Start from first Pixel */
		LCD_goToRowColumn(0,0);
		LCD_displayString("matched :)");
		/*Send command to Store the password in the EEPROM*/
		UART_sendByte(NEW_PASSWORD);
		_delay_ms(50);
		/*Send the new password to store it*/
		for (i = 0; i < PASS_LENGTH; i++) {
			UART_sendByte(pass[i]);
			_delay_ms(100);
		}
		_delay_ms(300);
	}
	else{
		/*the password and the confirmed password are not matched*/
		/*Clear the LCD*/
		LCD_clearScreen();
		/* Start from first Pixel */
		LCD_goToRowColumn(0,0);
		LCD_displayString("not matched!!");
		_delay_ms(300);
	}


}

void Main_APP(){
	uint8 message;
	uint8 choice;
	/*Clear the LCD screen*/
	LCD_clearScreen();
	/*Display the options*/
	LCD_displayStringRowColumn(0,0,"1:Change Password");
	LCD_displayStringRowColumn(1,0,"2:Open Door");

	/*get the user choice */
	do{
	choice = KeyPad_getPressedKey();
	_delay_ms(400);
	}while(!(choice == 1 || choice == 2));
	/*Send to MC2 command to check the password*/
	UART_sendByte(CHECK_PASSWORD);
	/*Enter password and send it to MC2*/
	Enter_Pass();
	/*Recieve from MC2 if the password is correct or not*/
	message = UART_recieveByte();

	if(message == CORRECT_PASSWORD){
		/*password is correct*/
		switch(choice){
		case 1:
			/*change the password with new one*/
			Change_Pass();
			break;
		case 2:
			/*Open Door*/
			/*Send to MC2 to open the door*/
			UART_sendByte(OPEN_DOOR);
			/*Reset the second counter*/
			g_timer1_SecFlag = 0;
			/*Clear the LCD screen*/
			LCD_clearScreen();
			LCD_displayStringRowColumn(0,0,"CORRECT PASSWORD");
			/*wait for 22 second*/
			while(g_timer1_SecFlag< 22){}
			break;
		}
	}
	else if(message == WRONG_PASSWORD){
		/*password was wrong*/
		/*Clear the LCD screen*/
		LCD_clearScreen();
		LCD_displayStringRowColumn(0,0,"WRONG PASSWORD");
		_delay_ms(500);
	}
	else if(message == PASSWORD_WRONG_3_TIMES){
		/*password was wrong 3 times in row*/
		/*Reset the second counter*/
		g_timer1_SecFlag = 0;
		/*Clear the LCD screen*/
		LCD_clearScreen();
		LCD_displayStringRowColumn(0,0,"X--X THIEF X--X");
		/*wait for 10 second*/
		while(g_timer1_SecFlag< 10){}
	}
}

void Enter_Pass(){
	uint8 key;
	uint8 i;
	uint8 pass[PASS_LENGTH];

	/*Clear the LCD screen*/
	LCD_clearScreen();
	/* Start from first Pixel */
	LCD_goToRowColumn(0,0);
	LCD_displayString("ENTER password");
	/* Start from second row -  first Pixel */
	LCD_goToRowColumn(1,0);

	/* Get the password from the user*/
	for (i = 0; i < PASS_LENGTH; i++){
		/*Get the pressed key from keypad*/
		key = KeyPad_getPressedKey();
		if ((key >= 0) && (key <= 9))
		{
			/*Save the key in password array*/
			pass[i] = key;
			LCD_displayStringRowColumn(1,i,"*");
			//LCD_intgerToString(key);
		}
		_delay_ms(500);
	}

	/*Send password to MC2*/
	for (i = 0; i < PASS_LENGTH; i++) {
		UART_sendByte(pass[i]);
		_delay_ms(100);
	}
	_delay_ms(300);

}

void Change_Pass()
{
	uint8 pass[PASS_LENGTH];
	uint8 conf[PASS_LENGTH];
	uint8 key;
	uint8 i;
	uint8 check;

	/*Clear the LCD screen*/
	LCD_clearScreen();
	/* Start from first Pixel */
	LCD_goToRowColumn(0,0);
	LCD_displayString("ENTER THE NEW");
	/* Start from second row -  first Pixel */
	LCD_goToRowColumn(1,0);
	LCD_displayString("   PASSWORD   ");
	_delay_ms(1000);

	/*Clear the LCD screen*/
	LCD_clearScreen();
	/* Start from first Pixel */
	LCD_goToRowColumn(0,0);
	LCD_displayString("Enter Password");
	/* Start from second row -  first Pixel */
	LCD_goToRowColumn(1,0);

	/* Get the password from the user*/
	for (i = 0; i < PASS_LENGTH; i++){
		/*Get the pressed key from keypad*/
		key = KeyPad_getPressedKey();
		if ((key >= 0) && (key <= 9))
		{
			/*Save the key in password array*/
			pass[i] = key;
			LCD_displayStringRowColumn(1,i,"*");
			//LCD_intgerToString(key);
		}
		_delay_ms(500);
	}

	/*Clear the LCD screen*/
	LCD_clearScreen();
	/* Start from first Pixel */
	LCD_goToRowColumn(0,0);
	LCD_displayString("Confirm Password");
	/* Start from second row -  first Pixel */
	LCD_goToRowColumn(1,0);
	/*Get the confirmed password*/
	for (i = 0; i < PASS_LENGTH; i++){
		/*Get the pressed key from keypad*/
		key = KeyPad_getPressedKey();
		if ((key >= 0) && (key <= 9))
		{
			/*Save the key in Confirm array*/
			conf[i] = key;
			LCD_displayStringRowColumn(1,i,"*");
			//LCD_intgerToString(key);
		}
		_delay_ms(500);
	}
	/*Compare the password and the confirmed password*/
	check = Compare(pass,conf);

	if (check){
		/*the password and the confirmed password are matched*/
		/*Clear the LCD*/
		LCD_clearScreen();
		/* Start from first Pixel */
		LCD_goToRowColumn(0,0);
		LCD_displayString("changed :)");
		/*Send command to Store the password in the EEPROM*/
		UART_sendByte(NEW_PASSWORD);
		_delay_ms(50);
		/*Send the new password to store it*/
		for (i = 0; i < PASS_LENGTH; i++) {
			UART_sendByte(pass[i]);
			_delay_ms(100);
		}
		_delay_ms(300);
	}
	else{
		/*the password and the confirmed password are not matched*/
		/*Clear the LCD*/
		LCD_clearScreen();
		/* Start from first Pixel */
		LCD_goToRowColumn(0,0);
		LCD_displayString("not matched!!");
		_delay_ms(300);
	}
}

uint8 Compare (uint8 array1[],uint8 array2[]){
	uint8 i;
	/* Check if the two arrays are matched or not*/
	for (i = 0; i < PASS_LENGTH; i++){
		if(array1[i] != array2[i]){
			/*if at least one element is not matched return 0*/
			return 0;
		}
	}
	/*if they are matched return 1*/
	return 1;
}

void Timer1_INT(){
	/* increment the timer counter every one second*/
	g_timer1_SecFlag++;
}
