/*
 * ADC.c
 *
 * Created: 9/8/2019 05:24:45 ?
 * Author : mah_h
 */ 

#include "ADC.h"
#include "LCD.h"
#include <avr/delay.h>
volatile float v_in;
volatile float temp;
volatile uint16 vd;
lcdcnfg_t mylcd = {{D0,D1,D2,D3},C0,C1};
ADC_cnfg myadc  =
{
	AVCC,
	CLK_ADC_DIV_128,
	FREE_RUNNING_MODE,
	ADC_DISABLE,
};
void print_vin(uint16 vd)
{
	v_in = vd * (VREF / MAX_LEVEL_NUM);
	if(temp == v_in)
	{
		
	}
	else
	{
		lcd_setCursor(&mylcd,0,0);
		lcd_fnum(&mylcd,v_in);
		temp = v_in;
	}
}


int main(void)
{
    lcd_init(&mylcd);
    adc_init(&myadc,print_vin);
	lcd_setCursor(&mylcd,0,0);
	lcd_fnum(&mylcd,v_in);
	sei();
    while (1) 
    {
		//adc_int(CHANNEL0, print_vin);
		vd = adc_read(CHANNEL0);
    }
}
