 /******************************************************************************
 *
 * Module: UART
 *
 * File Name: uart.c
 *
 * Description: Source file for the UART AVR driver
 *
 * Author: Mohamed Tarek
 *
 *******************************************************************************/


#include "uart.h"

/*******************************************************************************
 *                           Global Variables                                  *
 *******************************************************************************/

/* Global variables to hold the address of the call back function for UART Rx Interrupt in the application */
static volatile void (*g_callBackPtrUartRx)(void) = NULL_PTR;

/* Global variables to hold the address of the call back function for UART Tx Interrupt in the application */
static volatile void (*g_callBackPtrUartTx)(void) = NULL_PTR;


/*******************************************************************************
 *                       Interrupt Service Routines                            *
 *******************************************************************************/
ISR(USART_RXC_vect)
{
	if(g_callBackPtrUartRx != NULL_PTR){
		 /* Call the Call Back function for UART Rx Interrupt */
		(*g_callBackPtrUartRx)();
	}
}

ISR(USART_TXC_vect)
{
	if(g_callBackPtrUartRx != NULL_PTR){

		 /* Call the Call Back function for UART Tx Interrupt */
		(*g_callBackPtrUartTx)();
	}
}

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
void UART_init(const UART_ConfigType* config_Ptr)
{
	/* Initialize All registers with zeros */
/*	UCSRA &= 0x00;
	UCSRB &= 0x00;
	UCSRC &= 0x00;
	UBRRH &= 0x00;
	UBRRL &= 0x00;
*/

	/* U2X = 1 for double transmission speed */
	UCSRA = (1 << U2X);

	/* Enable UART Tx, Rx */
	UCSRB = (1 << RXEN) | (1 << TXEN);

	/* Chose the interrupt mode*/
	UCSRB = ( (UCSRB & 0x3F) | ( (config_Ptr -> InterruptMode) << TXCIE) );

	/*
	 * Enable UCSRC Register
	 * Choose Asyncronous Mode
	*/
	UCSRC = (1 << URSEL);

	/* Choose Parity Mode*/
	UCSRC = ( (UCSRC & 0xCF) | ( (config_Ptr -> ParityMode) << UPM0) );

	/* Choose number of stop bits number (1 or 2) */
	UCSRC = ( (UCSRC & 0xF7) | ( (config_Ptr -> StopBit) << USBS) );

	/* Choose 8 bit mode */
	UCSRC = ( (UCSRC & 0xF9) | (EIGHT_BIT_CHAR_SIZE << UCSZ0) );

	/* First 8 bits from the BAUD_PRESCALE inside UBRRL and last 4 bits in UBRRH*/
	UBRRH = ( ( ( (F_CPU / ( (config_Ptr -> BaudRate)* 8UL) ) ) - 1) >> 8 );
	UBRRL = ( ( (F_CPU / ( (config_Ptr -> BaudRate)* 8UL) ) ) - 1);
}

void UART_sendByte(const uint8 data)
{
	/* UDRE flag is set when the Tx buffer (UDR) is empty and ready for
	 * transmitting a new byte so wait until this flag is set to one */
	while(BIT_IS_CLEAR(UCSRA,UDRE)){}
	/* Put the required data in the UDR register and it also clear the UDRE flag as
	 * the UDR register is not empty now */
	UDR = data;
	/************************* Another Method *************************
	UDR = data;
	while(BIT_IS_CLEAR(UCSRA,TXC)){} // Wait until the transimission is complete TXC = 1
	SET_BIT(UCSRA,TXC); // Clear the TXC flag
	*******************************************************************/
}

uint8 UART_recieveByte(void)
{
	/* RXC flag is set when the UART receive data so wait until this
	 * flag is set to one */
	while(BIT_IS_CLEAR(UCSRA,RXC)){}
	/* Read the received data from the Rx buffer (UDR) and the RXC flag
	   will be cleared after read this data */
    return UDR;
}

void UART_sendString(const uint8 *Str)
{
	uint8 i = 0;
	while(Str[i] != '\0')
	{
		UART_sendByte(Str[i]);
		i++;
	}
	/************************* Another Method *************************
	while(*Str != '\0')
	{
		UART_sendByte(*Str);
		Str++;
	}
	*******************************************************************/
}

void UART_receiveString(uint8 *Str)
{
	uint8 i = 0;
	Str[i] = UART_recieveByte();
	while(Str[i] != '#')
	{
		i++;
		Str[i] = UART_recieveByte();
	}
	Str[i] = '\0';
}

void UART_setCallBackTx(void (*f_ptr)(void)){
	/* Save the address of the Call back function in a global variable */
	g_callBackPtrUartTx = f_ptr;
}

void UART_setCallBackRx(void (*f_ptr)(void)){
	/* Save the address of the Call back function in a global variable */
	g_callBackPtrUartRx = f_ptr;
}
