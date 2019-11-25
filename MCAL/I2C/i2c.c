/*
 * I2C.c
 *
 * Created: 9/26/2019 09:08:14 ص
 *  Author: Mohamed Hafez
 */ 

#include "I2CMA.h"

#define I2C_BUSY (IS_BIT_CLEAR((ICBASE + CONTROL_OFFSET), TWINT)) 

void  i2c_init()
{
	ACCESS_REG_8BIT((ICBASE + STATUS_OFFSET))   = 0x00;
	ACCESS_REG_8BIT((ICBASE + BITRATE_OFFSET))  = 0x02;
	ACCESS_REG_8BIT((ICBASE + ADDRESS_OFFSET))  = 0b00000010;
	ACCESS_REG_8BIT((ICBASE + CONTROL_OFFSET)) |= (SET << TWEN);
}

void  i2c_start(void)
{
	ACCESS_REG_8BIT((ICBASE + CONTROL_OFFSET)) = (SET << TWEN) | (SET << TWINT) | (SET << TWSTA);
	while(I2C_BUSY);
}

void  i2c_stop(void)
{
	ACCESS_REG_8BIT((ICBASE + CONTROL_OFFSET)) = (SET << TWEN) | (SET << TWINT) | (SET << TWSTO);
	while(I2C_BUSY);
}

void  i2c_writeAddress(uint8 adress)
{
	ACCESS_REG_8BIT((ICBASE + DATA_OFFSET))  = adress;
	ACCESS_REG_8BIT((ICBASE + CONTROL_OFFSET)) = (SET << TWEN) | (SET << TWINT);
	while(I2C_BUSY);
}

void  i2c_write(uint8 data)
{
	ACCESS_REG_8BIT((ICBASE + DATA_OFFSET))  = data;
	ACCESS_REG_8BIT((ICBASE + CONTROL_OFFSET)) = (SET << TWEN) | (SET << TWINT);
	while(I2C_BUSY);
}

uint8 i2c_read(void)
{
	ACCESS_REG_8BIT((ICBASE + CONTROL_OFFSET)) = (SET << TWEN) | (SET << TWINT) | (SET << TWEA);
	while(I2C_BUSY);
	return ACCESS_REG_8BIT((ICBASE + DATA_OFFSET));
}

uint8 i2c_reaWithNAck(void)
{
	ACCESS_REG_8BIT((ICBASE + CONTROL_OFFSET)) = (SET << TWEN) | (SET << TWINT);
	while(I2C_BUSY);
	return ACCESS_REG_8BIT((ICBASE + DATA_OFFSET));
}

uint8 i2c_getStatus(void)
{
	uint8 status;
	status = ACCESS_REG_8BIT((ICBASE + STATUS_OFFSET)) & 0xF8;
	return status;
}
