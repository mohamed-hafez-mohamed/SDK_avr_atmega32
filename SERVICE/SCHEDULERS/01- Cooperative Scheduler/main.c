/*
 * CoOperativeScheduler.c
 *
 * Created: 8/30/2020 4:24:01 PM
 * Author : Mohamed_Hafez
 */ 

#include <stdlib.h>
#include <util/delay.h>
#include "common.h"
#include "platform_PCfg.h"
#include "GPIO.h"
#include "SCHEDULER_interface.h"

extern Queue_t ReadyQueue;
static uint8 Global_uint8SwitchState = 0;
static uint8 Global_uint8LedStatus1;
static uint8 Global_uint8LedStatus2;
static uint8 Global_uint8LedStatus3;

void ledtog1(void * x)
{
	if(Global_uint8LedStatus1 == 0)
	{
	    pin_write(A0, HIGH_LEVEL);
		Global_uint8LedStatus1 = 1;
	}
	else

    {
	    pin_write(A0, LOW_LEVEL);
		Global_uint8LedStatus1 = 0;
	}
		
}

void ledtog2(void * x)
{
	if(Global_uint8LedStatus2 == 0)
	{
	    pin_write(A1, HIGH_LEVEL);
		Global_uint8LedStatus2 = 1;
	}
	else

    {
	    pin_write(A1, LOW_LEVEL);
		Global_uint8LedStatus2 = 0;
	}
	if(Global_uint8SwitchState)
	{
		Global_uint8SwitchState = 0;
		SCHEDULER_voidDeleteTask(2, &ReadyQueue);
	}
		
}

void ledtog3(void * x)
{
	if(Global_uint8LedStatus3 == 0)
	{
	    pin_write(A2, HIGH_LEVEL);
		Global_uint8LedStatus3 = 1;
	}
	else

    {
	    pin_write(A2, LOW_LEVEL);
		Global_uint8LedStatus3 = 0;
	}	
}


uint16 main(void)
{
	pin_dirc(A0, PIN_OUTPUT);
	pin_dirc(A1, PIN_OUTPUT);
	pin_dirc(A2, PIN_OUTPUT);
	pin_dirc(B0, PIN_INPUT);
	SCHEDULER_voidInitScheduler(&ReadyQueue);
	SCHEDULER_uint8CreateTask(0, 0  , 1000, &ledtog1, NULL);
	SCHEDULER_uint8CreateTask(1, 200, 200 , &ledtog2, NULL);
	SCHEDULER_uint8CreateTask(2, 600, 400 , &ledtog3, NULL);
	SCHEDULER_voidStartScheduler();
	while (1)
	{
		SCHEDULER_voidDispatchTasks(&ReadyQueue);
		Global_uint8SwitchState = pin_read(B0);
	}
}


