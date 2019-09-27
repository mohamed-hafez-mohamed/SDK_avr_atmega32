/*
 * ADC.c
 *
 * Created: 9/8/2019 05:24:45 م
 * Author : mah_h
 */ 

#include "ADC.h"
#include "LCD.h"
#include <avr/delay.h>
volatile float vin;
uint16 vd;
lcdcnfg_t mylcd = {{D0,D1,D2,D3},C0,C1};

void print_vin(uint16 vd)
{
	vin = vd * (VREF / MAX_LEVEL_NUM);
	/*lcd_setCursor(&mylcd,0,0);
	lcd_num(&mylcd,vin);*/
}


int main(void)
{
    lcd_init(&mylcd);
    adc_init(AVCC,FREE_RUNNING_MODE,CLK_ADC_DIV_128,&print_vin);
    while (1) 
    {
		vd = adc_read(CHANNEL0);
		_delay_ms(10);
		vin = vd * (VREF/ MAX_LEVEL_NUM);
		lcd_setCursor(&mylcd,0,0);
		lcd_num(&mylcd,vin);
    }
}

