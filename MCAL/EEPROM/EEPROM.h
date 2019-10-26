/*
 * EEPROM.h
 *
 * Created: 10/26/2019 09:28:18 AM
 *  Author: Mohamed Hafez
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

#include "common.h"

//REGISTER 
#define EECR_BASE       0X3C
#define EEDR_OFFESET    0X01
#define EEARL_OFFESET   0X02
#define EEARH_OFFESET   0X03
//BITS
#define EERE  0
#define EEWE  1
#define EEMWE 2
#define EERIE 3

uint8 EEPROM_read(uint8 address);

void EEPROM_write(uint8 address,uint8 data);



#endif /* EEPROM_H_ */
