/*
 * I2C.h
 *
 * Created: 9/26/2019 09:07:50 ص
 *  Author: Mohamed Hafez
 */ 


#ifndef I2C_H_
#define I2C_H_

#include "i2c_cnfg.h"
#include "GPIO.h"

//if i use status table
#define TW_START         0x08 // start has been sent
#define TW_REP_START     0x10 // repeated start
#define TW_MT_SLA_W_ACK  0x18 // ( slave address + Write have been sent ) + Ack received from slave
#define TW_MT_SLA_R_ACK  0x40 // ( slave address + Read have been sent ) + Ack received from slave
#define TW_MT_DATA_ACK   0x28 // Data byte has been transmitted and ACK has been received from Slave.
#define TW_MR_DATA_ACK   0x50 // Master received data and send ACK
#define TW_MR_DATA_NACK  0x58 // MAster received data but don't send ACK

typedef enum
{
	I2C_TX,
	I2C_RX
}i2c_status;

void  i2c_init(i2c_status status);

void  i2c_start(void);

void  i2c_stop(void);

void  i2c_writeAddress(uint8 adress);

void  i2c_write(uint8 data);

uint8 i2c_read(void);

#endif /* I2C_H_ */