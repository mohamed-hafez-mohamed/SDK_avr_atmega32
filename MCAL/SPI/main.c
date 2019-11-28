/*
 * SPI.c
 *
 * Created: 9/17/2019 10:27:47 م
 * Author : mah_h
 */ 

#include "SPI.h"
#include <avr/delay.h>

spi_cnfg myspi = {SPI_INTERRUPT_DISABLE,SPI_LSB_FIRST,
SPI_MASTER_MODE,SPI_RAISING_EDGE,SPI_SAMPLE,SPI_FOSC_DIV4};

uint8 a[5] = {'a','v',3,4,'y'};
int main(void)
{
    spi_cnfg_master();
	spi_init(&myspi);
    while (1) 
    {
		uint8 count;
		for(count = 0;count < 5;count++)
		{
			spi_transmit(a[count]);
			_delay_ms(10);
		}
		
    }
}

