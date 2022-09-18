/*
 * External_EEPROM_I2C.c
 *
 * Created: 3/12/2014 12:05:19 PM
 *  Author: Mohamed Tarek
 */
#include "micro_config.h"
#include "external_eeprom.h"

#define d  1


int main(void){
#if (d == 0)

	uint8 val = 0;

	DDRD  = 0xFF;
	PORTD = 0x01;


	EEPROM_init();

	EEPROM_writeByte(0x0311, 0x0F);
	_delay_ms(10);
	EEPROM_readByte(0x0311, &val);
	while(1)
	{
		PORTD = val;
	}

#else
	uint8 pass[5]={1,2,3,4,5};
	uint8 cp[5]={0};
	uint16 add = 0x0000;

	EEPROM_init();



	DDRD  = 0xFF;
	PORTD = 0x01;

	EEPROM_init();



	for (char i =0;i<5;i++){
		EEPROM_writeByte(add+4*i, pass[i]);
		_delay_ms(10);

	}

	for (char i =0;i<5;i++){
		EEPROM_readByte(add+4*i, &cp[i]);
		_delay_ms(10);

	}


	while(1)
	{
		for (char i =0;i<5;i++){
			PORTD = cp[i];
			_delay_ms(500);
		}
	}
}

#endif

#if 0
int main(void)
{
	uint8 val = 0;
	
	DDRD  = 0xFF;
	PORTD = 0x00;

	/* Init EEPROM */
	EEPROM_init();

	EEPROM_writeByte(0x0311, 0x0F); /* Write 0x0F in the external EEPROM */
	_delay_ms(10);
	EEPROM_readByte(0x0311, &val);  /* Read 0x0F from the external EEPROM */
	while(1)
	{
		PORTD = val; /* out the read value from the external EEPROM */
	}
	return 0;
}
#endif
