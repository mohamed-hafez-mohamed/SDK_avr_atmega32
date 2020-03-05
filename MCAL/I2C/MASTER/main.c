/*
 * ICS.c
 *
 * Created: 9/26/2019 04:36:07 ?
 * Author : Mohamed Hafez
 */ 

#include "I2C.h"
#include <avr/delay.h>

int main(void)
{
    i2c_init(0b0000001);
	pin_dirc(B0,PIN_INPUT);
    while (1) 
    {
		if(pin_read(B0) == 1)
		{
			i2c_start();
			i2c_writeAddress(0b0000010, I2C_TX);
			i2c_write(7);
			i2c_stop();
		}
    }
}