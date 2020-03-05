/*
 * SPI_S.c
 *
 * Created: 9/18/2019 10:51:42 ?
 * Author : mah_h
 */ 

#include "SPI.h"
#include <avr/delay.h>
spi_cnfg myspi = { 	
SPI_MSB_FIRST,
SPI_MASTER_MODE,
SAMPLE_RAISING_EDGE,
SPI_FOSC_DIV4
};

uint8 data[5] = {1,2,3,4,5};
int main(void)
{
    spi_init(&myspi);
    while (1) 
    {
		uint8 count;
		for(count = 0;count < 5;count++)
		{
			spi_transmit(data[count]);
		}
		
    }
}