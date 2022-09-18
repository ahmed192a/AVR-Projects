/*
 * SPI.h
 *
 * Created: 3/10/2014 9:30:41 PM
 * Author: Mohamed Tarek
 */ 

#ifndef SPI_H_
#define SPI_H_

#include "std_types.h"
#include "micro_config.h"
#include "common_macros.h"

void SPI_initMaster(void); 
void SPI_initSlave(void);
void SPI_sendByte(const uint8 data);
uint8 SPI_recieveByte(void);
void SPI_sendString(const uint8 *Str);
void SPI_receiveString(char *Str);

#endif
