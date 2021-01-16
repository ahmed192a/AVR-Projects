 /******************************************************************************
 *
 * Module: I2C(TWI)
 *
 * File Name: i2c.h
 *
 * Description: Header file for the I2C(TWI) AVR driver
 *
 * Author: Mohamed Tarek
 *
 *******************************************************************************/
#ifndef I2C_H_
#define I2C_H_

#include "std_types.h"
#include "common_macros.h"
#include "micro_config.h"



/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/

/* Preprocessor macros for Interrupt Mode */
#define INTERRUPT_MODE_ENABLE		(1U)
#define INTERRUPT_MODE_DISABLE		(0U)

/* Preprocessor macros for MC Address if it is in slave mode */
#define ADDRESS_OF_MC_IN_SLAVE_MODE	((0x02))

/* I2C Status Bits in the TWSR Register */
#define TW_START         0x08 // start has been sent
#define TW_REP_START     0x10 // repeated start
#define TW_MT_SLA_W_ACK  0x18 // Master transmit ( slave address + Write request ) to slave + Ack received from slave
#define TW_MT_SLA_R_ACK  0x40 // Master transmit ( slave address + Read request ) to slave + Ack received from slave
#define TW_MT_DATA_ACK   0x28 // Master transmit data and ACK has been received from Slave.
#define TW_MR_DATA_ACK   0x50 // Master received data and send ACK to slave
#define TW_MR_DATA_NACK  0x58 // Master received data but doesn't send ACK to slave


/*******************************************************************************
 *                     User Define Data Types                                    *
 *******************************************************************************/
typedef enum{

	NORMAL_MODE_100KB 		= 100000,
	FAST_MODE_400KB	  		= 400000,
	FAST_MODE_PLUS_1MB		= 1000000,
	HIGH_SPEDD_MODE_3_4MB	= 3400000,

}TWI_BitRateType;

typedef struct{

	uint8 Address;
	TWI_BitRateType BitRate;
	uint8 InterruptMode;
}TWI_ConfigType;


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

void TWI_init(const TWI_ConfigType* config_Ptr);
void TWI_start(void);
void TWI_stop(void);
void TWI_write(uint8 data);
uint8 TWI_readWithACK(void);//read with send Ack
uint8 TWI_readWithNACK(void);//read without send Ack
uint8 TWI_getStatus(void);
void TWI_setCallBack(void (*f_ptr)(void));



#endif /* I2C_H_ */
