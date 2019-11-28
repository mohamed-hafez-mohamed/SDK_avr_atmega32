/*
 * testuart.c
 *
 * Created: 10/28/2019 03:32:53 م
 * Author : mah_h
 */ 

#include <avr/delay.h>
#include<stdio.h>
#include <stdlib.h>
#include "UART.h"
#include "lcd.h"

volatile uint8 data[3] = {1,5,9};
lcdcnfg_t mylcd = {{A4,A5,A6,A7},B0,B1};
uint8 va;
int main(void)
{
	lcd_init(&mylcd);
	uart_cnfg();
	uart_baudrate(baudrate_2400);
	uart_setframe(_8BIT,DISABLED,_1STOPBIT);
	uart_init(RECEIVE,Asynchronous_Operation,RISINGTX);
	uart_init(TRANSMIT,Asynchronous_Operation,RISINGTX);
	while (1)
	{
		va = uart_receive(_8BIT);
		_delay_ms(1500);
		uart_transmit('v',_8BIT);
	}
}

