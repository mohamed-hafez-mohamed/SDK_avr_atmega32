/*
 * SPI.c
 *
 * Created: 9/17/2019 10:33:23 م
 *  Author: Mohamed Hafez
 */ 

#include "SPI.h"
#include "avr/interrupt.h"

#define dummy_data 0x52
static void(*static_PtrCallBackFun)(uint8); // the passed data in call_back work only for receiving
static spi_cnfg* static_ptr;

ISR(SPI_STC_vect)
{ // check for collision and read register if there !!
	
	static_PtrCallBackFun((READ_REG_8BIT((SPIBASE+SPDR_OFFSET))));
}


void spi_init(spi_cnfg* ptr)
{
	static_ptr = ptr;
	//check pointer not null
	ACCESS_REG_8BIT((SPIBASE+SPCR_OFFSET))  =  0; //clear register then set config
	ACCESS_REG_8BIT((SPIBASE+SPCR_OFFSET))
	|=  (ptr->Interrupt     << SPIE) 
	|   (ptr->DataOrder     << DORD) 
	|   (ptr->ModeSelect    << MSTR) 
	|   (ptr->ClockPolarity << CPOL) 
	|   (ptr->ClockPhase    << CPHA) 
	|   (ptr->ClockSelect   << SPR0);
	ACCESS_REG_8BIT((SPIBASE+SPCR_OFFSET)) |= (1 << SPE);	// wake up spi to work
	pin_write(B4,LOW_LEVEL);
}


void spi_interruptDisable()
{
	CLEAR_BIT((SPIBASE+SPCR_OFFSET),SPIE);
}

uint8 spi_exchangeData(uint8 data)
{  // check if slave it will be stucked here
	WRITE_REG_8BIT((SPIBASE+SPDR_OFFSET),data);
	while (IS_BIT_CLEAR((SPIBASE+SPSR_OFFSET),SPIF));
	return READ_REG_8BIT((SPIBASE + SPDR_OFFSET));
}

uint8 spi_receive()
{
	while (IS_BIT_CLEAR((SPIBASE+SPSR_OFFSET),SPIF));
	return READ_REG_8BIT((SPIBASE + SPDR_OFFSET));
}

void spi_transmit(uint8 data)
{
	WRITE_REG_8BIT((SPIBASE + SPDR_OFFSET),data);
	while (IS_BIT_CLEAR((SPIBASE+SPSR_OFFSET),SPIF));
}

void Spi_assignCallBack(void(*ptr_CallBackFun)(uint8))
{
	static_PtrCallBackFun= ptr_CallBackFun ;
}

