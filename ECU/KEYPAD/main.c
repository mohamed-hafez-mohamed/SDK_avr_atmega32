/*
 * KEYPAD.c
 *
 * Created: 9/2/2019 10:19:52 م
 * Author : mah_h
 */ 

#include <util/delay.h>
#include "LCD.h"
#include "KEYPAD.h"

lcdcnfg_t mylcd       = {{D4,D5,D6,D7},C0,C1};
keypadcnfg_t mykeypad = {{A0,A1,A2,A3},{A4,A5,A6,A7}};

void print_num(char chr)
{
	lcd_chr(&mylcd,chr);
}

int main(void)
{
	lcd_init(&mylcd);
	keypad_init(&mykeypad, &print_num);
    while (1) 
    {
		keypad_mainFun(&mykeypad);
    }
}

