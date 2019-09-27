/*
 * ADC.c
 *
 * Created: 9/3/2019 09:23:59 م
 *  Author: mah_h
 */ 

//#include <avr/interrupt.h>
#include "ADC.h"
#include <avr/interrupt.h>

#define  ADC_BUSY IS_BIT_SET((ADCBASE + CSRA_OFFSET),ADIF)
#define  V_IN	  ACCESS_REG_16BIT((ADCBASE + LOW_OFFSET))

static void (*ptr_callBackFun)(uint16);

ISR(ADC_vect)
{
	ptr_callBackFun(V_IN);
}

void   adc_init(vref_selectType vref,mode_selectType mod,clk_selectType clk,void (*ptr_fu)(uint16))
{
	ACCESS_REG_8BIT((ADCBASE + CSRA_OFFSET))  = CLEAR_REGISTER;       //clear ADCSRA REG
	ACCESS_REG_8BIT((ADCBASE + MUX_OFFSET))   = CLEAR_REGISTER;       //clear ADCMUX REG
	ACCESS_REG_8BIT((ADCBASE + MUX_OFFSET))   |= (vref << REFS0);     //V REFERENCE (REFS0,REFS1) (bit6,bit7) in ADMUX REG
	ACCESS_REG_8BIT((ADCBASE + CSRA_OFFSET))  |= (clk  << ADPS0);     //clock conversion (ADPS0,ADPS1,ADPS2) in ADCSRA REG
	ACCESS_REG_8BIT((ADCBASE + SFIOR_OFFSET)) |= (mod  << ADTS0);     //mode (ADTS0,ADTS1,ADTS2)(bit 5,6,7) in SFIOR   REG
	if(mod != FREE_RUNNING_MODE)
	{
		SET_BIT((ADCBASE + CSRA_OFFSET),ADATE);                       //set trigger mode (ADATE BIT5)in ADCSRA REG
	}
	SET_BIT((ADCBASE + CSRA_OFFSET),ADEN);                              //SET EN BIT IN ACSRA REG
	ptr_callBackFun = ptr_fu;
}

uint16 adc_read(channel_selectType channel)
{
	ACCESS_REG_8BIT((ADCBASE + MUX_OFFSET))   &= ~CLEAR_MUX_BITS;       //clear (MUX0,MUX1,MUX2,MUX3,MUX4) at ADMUX REG
	ACCESS_REG_8BIT((ADCBASE + MUX_OFFSET))   |= (channel<<MUX0);
	SET_BIT((ADCBASE + CSRA_OFFSET),ADSC);                              //start conversion (ADSC BIT 6) at ACSRA REG
	while(!(ADC_BUSY));                                                 // check (ADC Interrupt Flag BIT 4) in ACSRA REG
	return V_IN;
	(ptr_callBackFun)(V_IN);
}

void adc_intEnable(void (*F_callBack)(uint16 val),channel_selectType channel)
{
	ptr_callBackFun = F_callBack;
	SET_BIT((ADCBASE + ADCSRA),ADIE);
	ACCESS_REG_8BIT((ADCBASE + MUX_OFFSET)) |= (channel<<MUX0);				// set channel
	SET_BIT((ADCSRA+ADCBASE),ADSC);									       // start conversion for one shoot
}
