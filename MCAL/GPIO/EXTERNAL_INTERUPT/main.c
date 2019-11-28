/*
 * EXTERNAL_INTERRUPT.c
 *
 * Created: 9/10/2019 10:13:28 م
 * Author : mah_h
 */ 

#include <avr/delay.h>
#include "GPIO.h"
#include "EXTERNAL_INTERRUPT.h"

void led_trigger(void)
{
	pin_write(B0,HIGH_LEVEL);
	_delay_ms(1000);
}

int main(void)
{
    extrnal_int_init(EXT_INT0,INT_FALLING_EDGE,led_trigger);
    while (1) 
    {
		enable_EXT_INT(EXT_INT0);
	}
}

