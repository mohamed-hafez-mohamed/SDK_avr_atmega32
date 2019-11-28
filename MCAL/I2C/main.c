/*
 * I2C.c
 *
 * Created: 9/26/2019 08:55:28 ص
 * Author : Mohamed Hafez
 */ 


#include "I2CMA.h"
#include <avr/delay.h>

int main(void)
{
	i2c_init();
	
	while (1)
	{
		i2c_start();
		i2c_writeAddress(0b00000100);
		_delay_ms(10); // wait
		i2c_write(0x07);
		i2c_stop();
	}
}

