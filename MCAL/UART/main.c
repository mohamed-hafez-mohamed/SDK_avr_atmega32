/*
 * UART.c
 *
 * Created: 9/16/2019 04:15:29 م
 * Author : mah_h
 */ 

#include <avr/delay.h>
#include "UART.h"
#include "lcd.h"

volatile uint8 data;
lcdcnfg_t mylcd = {{A4,A5,A6,A7},B0,B1};
int main(void)
{
	lcd_init(&mylcd);
	uart_cnfg();
    uart_baudrate(baudrate_2400);
	uart_setframe(_8BIT,DISABLED,_1STOPBIT);
    uart_init(RECEIVE,Asynchronous_Operation,RISINGTX);
    while (1) 
    {
		 data = uart_receive(_8BIT);
		 lcd_chr(&mylcd,data);
    }
}

