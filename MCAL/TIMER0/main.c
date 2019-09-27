/*
 * TIMER0.c
 *
 * Created: 9/10/2019 02:18:13 م
 * Author : mah_h
 */ 

#include "GPIO.h"
#include "TIMER0.h"
#include <avr/delay.h>

void led_trigger(void)
{
	TOGGLE_BIT((Base_D + OUTPUT_OFFEST),0);
	_delay_ms(1000);
}

int main(void)
{
    timer0_cnfg mytimer = {PRESCALING_CLK1024, Normal, TOIE0_disable, OCIE0_disable};
	timer0_init(&mytimer);
	pin_dirc(D0,PIN_OUTPUT);
    while (1) 
    {
		if(IS_BIT_SET((TIMER0BASE + FLAG_OFFSET), 0))
		{
			led_trigger();
		}
    }
}

