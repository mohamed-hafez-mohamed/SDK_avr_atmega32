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
	ACCESS_REG_8BIT((ICBASE + ADDRESS_OFFSET))  = 0b00000010;//it's address if any master device want to call me
	ACCESS_REG_8BIT((ICBASE + CONTROL_OFFSET)) |= (SET << TWEN); //enable I2C
}

void  i2c_start(void)
{
	/* Clear the TWINT flag before sending the start bit TWINT=1 "MUST"
	 * send the start bit by TWSTA=1
	 * Enable TWI Module TWEN=1 
	 */
	ACCESS_REG_8BIT((ICBASE + CONTROL_OFFSET)) = (SET << TWEN) | (SET << TWINT) | (SET << TWSTA);
	// Wait for TWINT flag set in TWCR Register (start bit is send successfully)
	while(I2C_BUSY);
}

void  i2c_stop(void)
{
	/* Clear the TWINT flag before sending the stop bit TWINT=1 
	 * send the stop bit by TWSTO=1 
	 * Enable TWI Module TWEN=1 
	 */
	ACCESS_REG_8BIT((ICBASE + CONTROL_OFFSET)) = (SET << TWEN) | (SET << TWINT) | (SET << TWSTO);
	while(I2C_BUSY);
}

void  i2c_writeAddress(uint8 adress)
{
	// Put address On TWI Register
	ACCESS_REG_8BIT((ICBASE + DATA_OFFSET))  = adress;
	/* Clear the TWINT flag before sending the data TWINT=1
	 * Enable TWI Module TWEN=1 
	 */ 
	ACCESS_REG_8BIT((ICBASE + CONTROL_OFFSET)) = (SET << TWEN) | (SET << TWINT);
	// Wait for TWINT flag set in TWCR Register(data is send successfully)
	while(I2C_BUSY);
}

void  i2c_write(uint8 data)
{
	// Put data On TWI Register
	ACCESS_REG_8BIT((ICBASE + DATA_OFFSET))  = data;
	/* Clear the TWINT flag before sending the data TWINT=1
	 * Enable TWI Module TWEN=1 
	 */ 
	ACCESS_REG_8BIT((ICBASE + CONTROL_OFFSET)) = (SET << TWEN) | (SET << TWINT);
	// Wait for TWINT flag set in TWCR Register(data is send successfully)
	while(I2C_BUSY);
}

uint8 i2c_read(void)
{
	/* Clear the TWINT flag before reading the data TWINT=1
	 * enable sending ACK TWEA=1
	 * Enable TWI Module TWEN=1 
	 */ 
	ACCESS_REG_8BIT((ICBASE + CONTROL_OFFSET)) = (SET << TWEN) | (SET << TWINT) | (SET << TWEA);
	// Wait for TWINT flag set in TWCR Register (data received successfully) 
	while(I2C_BUSY);
	return ACCESS_REG_8BIT((ICBASE + DATA_OFFSET));
}

uint8 i2c_reaWithNAck(void)
{
	/* Clear the TWINT flag before reading the data TWINT=1
	 * enable sending ACK TWEA=1
	 * Enable TWI Module TWEN=1 
	 */
	ACCESS_REG_8BIT((ICBASE + CONTROL_OFFSET)) = (SET << TWEN) | (SET << TWINT);
	// Wait for TWINT flag set in TWCR Register (data received successfully)
	while(I2C_BUSY);
	return ACCESS_REG_8BIT((ICBASE + DATA_OFFSET));
}

uint8 i2c_getStatus(void)
{
	uint8 status;
	status = ACCESS_REG_8BIT((ICBASE + STATUS_OFFSET)) & 0xF8; //masking to eliminate first 3 bits 
	return status;
}
