/*
 * LCD.c
 *
 * Created: 8/31/2019 04:12:58 م
 * Author : mah_h
 */ 


#include "lcd.h"
#include <util/delay.h>
int main(void)
{
    lcdcnfg_t mylcd = {{0,1,2,3},4,5};
		lcd_init(&mylcd);
		
    while (1) 
    {
		lcd_setCursor(&mylcd,0,0);
		lcd_chr(&mylcd,'h');
    }
}

