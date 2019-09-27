/*
 * delay.h
 *
 * Created: 8/26/2019 09:55:56 ص
 *  Author: Mohamed Hafez
 */ 


#ifndef DELAY_H_
#define DELAY_H_


#define clock 1000000
#define msec 1000
#define error_ratio 30
uint32_t counter;
//delay implementation
#define delay(x)\
for(counter = ((clock / msec) * x / error_ratio);counter > 0;counter--)\
{\
	__asm("NOP");\
}


#endif /* DELAY_H_ */
