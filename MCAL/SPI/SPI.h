/*
 * SPI.h
 *
 * Created: 9/17/2019 10:33:00 م
 *  Author: mah_h
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "spi_cnfg.h"
#include "GPIO.h"

typedef enum
{
	SPI_INTERRUPT_DISABLE,
	SPI_INTERRUPT_ENABLE
} Spi_InterruptType;

typedef enum
{
	SPI_LSB_FIRST,
	SPI_MSB_FIRST
} Spi_DataOrderType;

typedef enum
{
	SPI_SLAVE_MODE,
	SPI_MASTER_MODE
} Spi_ModeSelectType;

typedef enum
{
	SPI_RAISING_EDGE,
	SPI_FALLING_EDGE
} Spi_ClockPolarityType;


typedef enum
{
	SPI_SAMPLE,
	SPI_SETUP,
} Spi_ClockPhaseType;

typedef enum
{
	SPI_FOSC_DIV4,
	SPI_FOSC_DIV16,
	SPI_FOSC_DIV64,
	SPI_FOSC_DIV128,
} Spi_ClockSelectType;

typedef struct
{
	Spi_InterruptType		Interrupt;
	Spi_DataOrderType		DataOrder;
	Spi_ModeSelectType		ModeSelect;
	Spi_ClockPolarityType   ClockPolarity;
	Spi_ClockPhaseType		ClockPhase;
	Spi_ClockSelectType		ClockSelect;
} spi_cnfg;

void  spi_init(spi_cnfg* ptr);

uint8 spi_exchangeData(uint8 data);

uint8 spi_receive();

void  spi_transmit(uint8 data);

void  Spi_assignCallBack(void(*ptr_CallBackFun)(uint8));

void  spi_interruptDisable();






#endif /* SPI_H_ */