/*
 * SPI_S.c
 *
 * Created: 9/18/2019 10:51:42 ص
 * Author : mah_h
 */ 

#include "SPI.h"
#include <avr/delay.h>
spi_cnfg myspi = {SPI_INTERRUPT_DISABLE,SPI_LSB_FIRST,
SPI_SLAVE_MODE,SPI_RAISING_EDGE,SPI_SAMPLE,SPI_FOSC_DIV4};

uint8 data[5];
int main(void)
{
	spi_cnfg_slave();
    spi_init(&myspi);
    while (1) 
    {
		uint8 count;
		for(count = 0;count < 5;count++)
		{
			data[count] = spi_receive();
		}
		
    }
}

