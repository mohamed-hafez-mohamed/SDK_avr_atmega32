/*
 * EEPROM.c
 *
 * Created: 10/26/2019 09:28:35 AM
 *  Author: Mohamed Hafez
 */ 


#include "EEPROM.h"

uint8 EEPROM_read(uint8 address)
{
	while(ACCESS_REG_8BIT(EECR_BASE) & (1 << EEWE));
	ACCESS_REG_16BIT((EECR_BASE + EEARL_OFFESET)) = address;
	ACCESS_REG_8BIT(EECR_BASE) |= (1 << EERE);
	return READ_REG_8BIT((EECR_BASE + EEDR_OFFESET));
}

void EEPROM_write(uint8 address,uint8 data)
{
	while(ACCESS_REG_8BIT(EECR_BASE) & (1 << EEWE));
	ACCESS_REG_16BIT((EECR_BASE + EEARL_OFFESET)) = address;
	WRITE_REG_8BIT((EECR_BASE + EEDR_OFFESET),data);
	ACCESS_REG_8BIT(EECR_BASE) | (1 << EEMWE);
	ACCESS_REG_8BIT(EECR_BASE) | (1 << EEWE);
}
