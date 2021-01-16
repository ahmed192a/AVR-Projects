 /******************************************************************************
 *
 * Module: I2C(TWI)
 *
 * File Name: i2c.c
 *
 * Description: Source file for the I2C(TWI) AVR driver
 *
 * Author: Mohamed Tarek
 *
 *******************************************************************************/


#include "i2c.h"

/*******************************************************************************
 *                           Global Variables                                  *
 *******************************************************************************/
/* Global Variable to hold address of the call back funtion of TWI Interrupt */
static volatile void (*g_callBackPtrTWI)(void) = NULL_PTR;


/*******************************************************************************
 *                       Interrupt Service Routines                            *
 *******************************************************************************/
ISR(TWI_vect){
	if(g_callBackPtrTWI != NULL_PTR){

		/* Call the Call Back function for TWI Interrupt */
		(*g_callBackPtrTWI)();
	}
}


/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void TWI_init(const TWI_ConfigType* config_Ptr){

	uint8 bitRateCalculation;
	/* Clear all registers before doing  anything */
/*	TWBR &= 0x00;
	TWCR &= 0x00;
	TWDR &= 0x00;
	TWAR &= 0x00;
*/
	/* Bit rate calculations */
	bitRateCalculation = ( ( (F_CPU) - ( (config_Ptr -> BitRate) * 16) ) / (2 * (config_Ptr -> BitRate) ) );

	/* Check if number is Bigger than zero or not */
	if(bitRateCalculation >= 0){
		/*Bit Rate calculation proper with this clock*/
		TWBR = bitRateCalculation;
	}

	/*
	 * Check if BitRate calculation value < 0
	 * Also check if processor clock is bigger than 1 MHz
	 * which is the proper one for calculations here
	*/
	else if ( (F_CPU > 1000000) && (bitRateCalculation < 0) )
	{
		/* Reduce BitRate to Normal Mode  */
		bitRateCalculation = ( ( (F_CPU) - ( (NORMAL_MODE_100KB) * 16) ) / (2 * (NORMAL_MODE_100KB) ) );
		TWBR = bitRateCalculation;
	}

	/* Zero Prescaler */
	TWSR = 0x00;

    /*
     * Two Wire Bus address my address
     * if any master device want to call me: 0x1
     * (used in case this MC is a slave device)
     *  General Call Recognition: Off
    */
    TWAR = ( (config_Ptr -> Address) & 0xFE);

    /* Choose Operating mode (Interrupt or polling) */
    TWCR = ( (config_Ptr -> InterruptMode) );

    /* Enable TWI Module */
    TWCR = (1<<TWEN);

}

void TWI_start(void)
{
    /*
	 * Clear the TWINT flag before sending the start bit TWINT=1
	 * send the start bit by TWSTA=1
	 * Enable TWI Module TWEN=1
	 */
    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);

    /* Wait for TWINT flag set in TWCR Register (start bit is send successfully) */
    while(BIT_IS_CLEAR(TWCR,TWINT));
}

void TWI_stop(void)
{
    /*
	 * Clear the TWINT flag before sending the stop bit TWINT=1
	 * send the stop bit by TWSTO=1
	 * Enable TWI Module TWEN=1
	 */
    TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);
}

void TWI_write(uint8 data)
{
    /* Put data On TWI data Register */
    TWDR = data;
    /*
	 * Clear the TWINT flag before sending the data TWINT=1
	 * Enable TWI Module TWEN=1
	 */
    TWCR = (1 << TWINT) | (1 << TWEN);
    /* Wait for TWINT flag set in TWCR Register(data is send successfully) */
    while(BIT_IS_CLEAR(TWCR,TWINT));
}

uint8 TWI_readWithACK(void)
{
	/*
	 * Clear the TWINT flag before reading the data TWINT=1
	 * Enable sending ACK after reading or receiving data TWEA=1
	 * Enable TWI Module TWEN=1
	 */
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
    /* Wait for TWINT flag set in TWCR Register (data received successfully) */
    while(BIT_IS_CLEAR(TWCR,TWINT));
    /* Read Data */
    return TWDR;
}

uint8 TWI_readWithNACK(void)
{
	/*
	 * Clear the TWINT flag before reading the data TWINT=1
	 * Enable TWI Module TWEN=1
	 */
    TWCR = (1 << TWINT) | (1 << TWEN);
    /* Wait for TWINT flag set in TWCR Register (data received successfully) */
    while(BIT_IS_CLEAR(TWCR,TWINT));
    /* Read Data */
    return TWDR;
}

uint8 TWI_getStatus(void)
{
    uint8 status;
    /* masking to eliminate first 3 bits and get the last 5 bits (status bits) */
    status = TWSR & 0xF8;
    return status;
}



void TWI_setCallBack(void (*f_ptr)(void)){
	g_callBackPtrTWI = f_ptr;
}
