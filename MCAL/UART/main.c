/*
 * UART.c
 *
 * Created: 9/16/2019 04:15:29 م
 * Author : mah_h
 */ 

#include <avr/delay.h>
#include<stdio.h>
#include <stdlib.h>
#include "UART.h"
#include "lcd.h"
uint8 x;
lcdcnfg_t mylcd = {{A4,A5,A6,A7},B0,B1};
int main(void)
{
	lcd_init(&mylcd);
	uart_cnfg();
    uart_baudrate(baudrate_2400);
	uart_setframe(_8BIT,DISABLED,_1STOPBIT);
    uart_init(TRANSMIT,Asynchronous_Operation,RISINGTX);
	uart_init(RECEIVE,Asynchronous_Operation,RISINGTX);
    while (1) 
    {
		uart_transmit('a',_8BIT);
		_delay_ms(1500);
		x = uart_receive(_8BIT);
	}
}

