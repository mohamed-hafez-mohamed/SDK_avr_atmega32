/*
 * PWM.c
 *
 * Created: 9/18/2019 02:27:36 م
 * Author : mah_h
 */ 

#include "PWM.h"


int main(void)
{
    pwm0_init();
	pwm_write(B3,250);
    while (1) 
    {
    }
}

