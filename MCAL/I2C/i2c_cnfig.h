/*
 * i2c_cnfg.h
 *
 * Created: 9/26/2019 02:06:49 م
 *  Author: Mohamed Hafez
 */ 


#ifndef I2C_CNFG_H_
#define I2C_CNFG_H_

#define SET            1

#define	ICBASE         0x20
#define BITRATE_OFFSET 0x00
#define CONTROL_OFFSET 0x36
#define STATUS_OFFSET  0x01
#define ADDRESS_OFFSET 0x02
#define DATA_OFFSET    0x03

#define TWBR0          0
#define TWINT          7
#define TWEA           6
#define TWSTA          5
#define TWSTO          4
#define TWWCF          3
#define TWEN           2
#define TWIE           0
#define TWS3           3
#define TWPS0          0
#define TWGCE          0

#endif /* I2C_CNFG_H_ */
