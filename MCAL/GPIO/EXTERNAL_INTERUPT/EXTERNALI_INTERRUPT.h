/*
 * EXTERNAL_INTERRUPT.h
 *
 * Created: 2/4/2020 2:37:34 PM
 *  Author: mah_h
 */ 


#ifndef EXTERNAL_INTERRUPT_H_
#define EXTERNAL_INTERRUPT_H_

#include "common.h"
#include "platform_PCfg.h"
#include <avr/interrupt.h>

#define INTBASE        0x54
#define MCUCSRA_OFFSET 0
#define MCUCRA_OFFSET  1
#define GICR_OFFSET    7
#define SET            1 
typedef enum
{
	EXT_INT0 = 6,
	EXT_INT1 = 7,
	EXT_INT2 = 5
} interruptNUM_t;

typedef enum
{
	INT_LOW_LEVEL,
	INT_ANY_LOGIC_CHANGE,
	INT_FALLING_EDGE,
	INT_RISING_EDGE
} interruptMode_t;

void enable_EXT_INT(interruptNUM_t number);

void disable_EXT_INT(interruptNUM_t number);

void extrnal_int_init(interruptNUM_t number, interruptMode_t mode, void (*ptr_ISR)());

#endif /* EXTERNAL_INTERRUPT_H_ */
