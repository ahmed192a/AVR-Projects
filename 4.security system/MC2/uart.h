 /******************************************************************************
 *
 * Module: UART
 *
 * File Name: uart.h
 *
 * Description: Header file for the UART AVR driver
 *
 * Author: Mohamed Tarek
 *
 *******************************************************************************/

#ifndef UART_H_
#define UART_H_

#include "micro_config.h"
#include "std_types.h"
#include "common_macros.h"



#define STOP_BIT_1_BIT			(0U)
#define STOP_BIT_2_BITS			(1U)

#define EIGHT_BIT_CHAR_SIZE 	(3U)


/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
typedef enum{

	POLLING,
	TX_INT_ENABLE,
	RX_INT_ENABLE,
	TX_RX_INT_ENABLE

}UART_InterruptModeType;

typedef enum{

	NO_PARIT_BITS,
	EVEN_PARITY = 2,
	ODD_PARITY

}UART_ParityModeType;

typedef struct{
	UART_InterruptModeType	InterruptMode;
	uint8 StopBit;
	UART_ParityModeType	ParityMode;
	uint32	BaudRate;
}UART_ConfigType;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void UART_init(const UART_ConfigType* config_Ptr);

void UART_setCallBackRx(void (*f_ptr)(void));
void UART_setCallBackTx(void (*f_ptr)(void));

void UART_sendByte(const uint8 data);

uint8 UART_recieveByte(void);

void UART_sendString(const uint8 *Str);

void UART_receiveString(uint8 *Str); // Receive until #

#endif /* UART_H_ */
