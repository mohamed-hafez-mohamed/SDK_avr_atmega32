/*
 * EXTERNAL_INTERRUPT.c
 *
 * Created: 9/10/2019 10:15:47 م
 *  Author: mah_h
 */ 

#include <avr/interrupt.h>
#include "GPIO.h"
#include "EXTERNAL_INTERRUPT.h"
#define GLOBAL_INT_ENABLE sei()

static void (*ptr_CallBackFromExtISR[3]) (void);

ISR(INT0_vect)
{
	ptr_CallBackFromExtISR[INT0]();
}

ISR(INT1_vect)
{
	ptr_CallBackFromExtISR[INT1]();
}

ISR(INT2_vect)
{
	ptr_CallBackFromExtISR[INT2]();
}

void extrnal_int_init(interruptNUM_t number,interruptMode_t mode,void (*ptr_ISR)())
{
	switch(number)
	{
		case EXT_INT0 :
		   pin_write(D2,LOW_LEVEL);
		   ACCESS_REG_8BIT((INTBASE + MCUCRA_OFFSET)) |= (mode << ISC00);
		   ptr_CallBackFromExtISR[INT0] = ptr_ISR;
		break;
		case EXT_INT1 :
		   pin_write(D3,LOW_LEVEL);
		   ACCESS_REG_8BIT((INTBASE + MCUCRA_OFFSET)) |= (mode << ISC10);
		   ptr_CallBackFromExtISR[INT1] = ptr_ISR;
		break;
		case EXT_INT2 :
		   pin_write(B2,LOW_LEVEL);
		   if(mode == INT_FALLING_EDGE)
		   {
			   ACCESS_REG_8BIT((INTBASE + MCUCSRA_OFFSET)) &= ~(SET << ISC2);
		   }
		   else if(mode == INT_RISING_EDGE)
		   {
			   ACCESS_REG_8BIT((INTBASE + MCUCSRA_OFFSET)) |= (SET << ISC2);
		   }
		   ptr_CallBackFromExtISR[INT2] = ptr_ISR;
	}
}

void enable_EXT_INT(interruptNUM_t number)
{
	ACCESS_REG_8BIT((INTBASE + GICR_OFFSET)) |= (SET << number);
}

void disable_EXT_INT(interruptNUM_t number)
{
	ACCESS_REG_8BIT((INTBASE + GICR_OFFSET)) &= ~(SET << number);
}