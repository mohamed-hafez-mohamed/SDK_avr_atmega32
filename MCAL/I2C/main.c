/*
 * ICS.c
 *
 * Created: 9/26/2019 04:36:07 م
 * Author : Mohamed Hafez
 */ 

#include "I2CS.h"
#include <avr/delay.h>
uint8 d;
int main(void)
{
    i2c_init();
	pin_dirc(B0,PIN_OUTPUT);
    while (1) 
    {
		d = i2c_read();
		if(d == 0x07)
		{
			pin_write(B0,HIGH_LEVEL);
		}
    }
}

