/*
 * ICS.c
 *
 * Created: 9/26/2019 04:36:07 ?
 * Author : Mohamed Hafez
 */ 

#include "I2C.h"
#include <avr/delay.h>
uint8 d;
int main(void)
{
	i2c_init(0b0000010);
	pin_dirc(B0,PIN_OUTPUT);
    while (1) 
    {
		i2c_listen();
		d = i2c_readWithNAck();
		if(d == 7)
		{
			pin_write(B0,HIGH_LEVEL);
		}
    }
}