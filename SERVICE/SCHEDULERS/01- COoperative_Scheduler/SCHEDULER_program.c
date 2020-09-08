/*******************************************************************************
* Title                 :   SCHEDULER 
* Filename              :   SCHEDULER_program.c
* Author                :   Mohamed Hafez
* Origin Date           :   10/8/2020
* Version               :   1.0.0
* Compiler              :   TODO: COMPILER GOES HERE
* Target                :   TODO: MCU GOES HERE
* Notes                 :   None 
*
*****************************************************************************/
/*************** SOURCE REVISION LOG *****************************************
*
*    Date    Version   Author          Description 
*  04/08/20   1.0.0   Mohamed Hafez   Initial Release.
*
*******************************************************************************/
/** @file SCHEDULER_program.c
 *  @brief This is the source file for TODO: WHAT DO I DO? 
 */
/******************************************************************************
* Includes
*******************************************************************************/	
#include <stdlib.h>
#include <avr/interrupt.h>
#include "TIMER0.h"
#include "SCHEDULER_interface.h"
#include "SCHEDULER_config.h"
#include "SCHEDULER_private.h"

/******************************************************************************
* Module Preprocessor Constants
*******************************************************************************/

/******************************************************************************
* Module Preprocessor Macros
*******************************************************************************/

/******************************************************************************
* Module Typedefs
*******************************************************************************/

/******************************************************************************
* Module Variable Definitions
*******************************************************************************/
Queue_t ReadyQueue;
timer0_cnfg mytimer = {PRESCALING_CLK1024, CTC, Toggle_on_com};
/******************************************************************************
* Function Prototypes
*******************************************************************************/

/******************************************************************************
* Function Definitions
*******************************************************************************/

void SCHEDULER_voidInitScheduler(Queue_t * Copy_PtrQueue)
{
    Copy_PtrQueue->Queue_Front = NULL;
    Copy_PtrQueue->Queue_Rear  = NULL;
    Copy_PtrQueue->Queue_Size  = 0;
	timer0_init(&mytimer);
	ov_int(TOIE0_enable, &SCHEDULER_voidUpdateScheduler, (void *)(&ReadyQueue));
}

void SCHEDULER_voidStartScheduler(void)
{
	sei();
}

uint8 SCHEDULER_uint8AddTask(PtrStructTask_QueueENTRY  Copy_PtrQueueEntry,Queue_t * Copy_PtrQueue)
{
    QueueNode_t  * Local_PtrQueueNode = (QueueNode_t *)malloc(sizeof(QueueNode_t));
    if(! Local_PtrQueueNode)
    {
      return 0;
    }
    else
    {
      Local_PtrQueueNode->QueueNode_Entry = Copy_PtrQueueEntry;
      Local_PtrQueueNode->QueueNode_Next  = NULL;
      if(!Copy_PtrQueue->Queue_Rear)
      {
          Copy_PtrQueue->Queue_Front = Local_PtrQueueNode;
      }
      else
      {
          Copy_PtrQueue->Queue_Rear->QueueNode_Next = Local_PtrQueueNode;
      }
      Copy_PtrQueue->Queue_Rear = Local_PtrQueueNode;
      Copy_PtrQueue->Queue_Size++;
      return 1;
    }
}

uint8  SCHEDULER_uint8CreateTask(uint8 Copy_uint8Priority, uint16 Copy_uint16ReleaseTime, uint16 Copy_uint16Period, ptr_TaskCode Copy_PtrTaskCode, void * Copy_PtrTaskParameter)
{
    PtrStructTask_QueueENTRY Task = (PtrStructTask_QueueENTRY)malloc(sizeof(Task_t));
    Task->TASK_uint8Priority         = Copy_uint8Priority;
    Task->Task_uint16ReleaseTime     = Copy_uint16ReleaseTime;
    Task->Task_uint16Period          = Copy_uint16Period;
    Task->Task_uint8State            = SCHEDULER_TASK_STATE_DORMANT;
    Task->Task_PtrCode            = Copy_PtrTaskCode;
    Task->Task_PtrVoidParameter   = Copy_PtrTaskParameter;
    SCHEDULER_uint8AddTask(Task, &ReadyQueue);
	  //!<TODO: Return Status
}

/*This function will be invocked inside tin timer overflow ISR*/
void SCHEDULER_voidUpdateScheduler(void * Copy_voidPtrQueue)
{
	  Queue_t * Copy_PtrQueue = (Queue_t *)Copy_voidPtrQueue;
    QueueNode_t *Local_PtrQueueNode;
    for(Local_PtrQueueNode = Copy_PtrQueue -> Queue_Front;Local_PtrQueueNode;Local_PtrQueueNode = Local_PtrQueueNode -> QueueNode_Next)
    {
        /*!<Check if there is a task at this location*/
        if(Local_PtrQueueNode->QueueNode_Entry->Task_PtrCode)
        {
            if(Local_PtrQueueNode->QueueNode_Entry->Task_uint16ReleaseTime == SCHEDULER_TASK_READY_TO_RUN)
            {
                /*!<The task is ready to run*/
               Local_PtrQueueNode->QueueNode_Entry->Task_uint8State = SCHEDULER_TASK_STATE_READY_TO_RUN;
               if(Local_PtrQueueNode->QueueNode_Entry->Task_uint16Period)
               {
                    /*!<Schedule periodic tasks to run again*/
                    Local_PtrQueueNode->QueueNode_Entry->Task_uint16ReleaseTime = Local_PtrQueueNode->QueueNode_Entry->Task_uint16Period;
               }
            }
            else
            {
                /*!<Not yet ready to run: just decrement the delay*/
                Local_PtrQueueNode->QueueNode_Entry->Task_uint16ReleaseTime -= 1;
            }
        }
    }
}

void SCHEDULER_voidSuspendTask(uint8 Copy_uint8TaskPosition,Queue_t * Copy_PtrQueue)
{
    uint8 Local_uint8Counter;
    QueueNode_t * Local_PtrQueueNode;
    if(Copy_uint8TaskPosition == 0)
    {
        Copy_PtrQueue->Queue_Front->QueueNode_Entry->Task_uint8State = SCHEDULER_TASK_STATE_SUSPENDED;
    }
    else if(Copy_uint8TaskPosition > 0)
    {
        for(Local_PtrQueueNode = Copy_PtrQueue->Queue_Front,Local_uint8Counter = 0;Local_uint8Counter < Copy_uint8TaskPosition - 1;Local_uint8Counter++)
       {
           Local_PtrQueueNode = Local_PtrQueueNode->QueueNode_Next;
       }
       
       Local_PtrQueueNode->QueueNode_Next->QueueNode_Entry->Task_uint8State = SCHEDULER_TASK_STATE_SUSPENDED;
    }
    else
    {
        //!<TODO: Error Code
    }

}

void SCHEDULER_voidResumeTask(uint8 Copy_uint8TaskPosition,Queue_t * Copy_PtrQueue)
{
    uint8 Local_uint8Counter;
    QueueNode_t * Local_PtrQueueNode;
    if(Copy_uint8TaskPosition == 0)
    {
        Copy_PtrQueue->Queue_Front->QueueNode_Entry->Task_uint8State = SCHEDULER_TASK_STATE_READY;
    }
    else if(Copy_uint8TaskPosition > 0)
    {
        for(Local_PtrQueueNode = Copy_PtrQueue->Queue_Front,Local_uint8Counter = 0;Local_uint8Counter < Copy_uint8TaskPosition - 1;Local_uint8Counter++)
       {
           Local_PtrQueueNode = Local_PtrQueueNode->QueueNode_Next;
       }
       
       Local_PtrQueueNode->QueueNode_Next->QueueNode_Entry->Task_uint8State = SCHEDULER_TASK_STATE_READY;
    }
    else
    {
        //!<TODO: Error Code
    }
}

void SCHEDULER_voidServeTask(PtrStructTask_QueueENTRY * Copy_PtrQueueEntry, Queue_t * Copy_PtrQueue)
{
    QueueNode_t * Local_PtrQueueNode = Copy_PtrQueue->Queue_Front;
    *Copy_PtrQueueEntry = Local_PtrQueueNode->QueueNode_Entry;
    if(!Copy_PtrQueue->Queue_Front)
    {
        Copy_PtrQueue->Queue_Rear = NULL;
    }
}

void SCHEDULER_voidServeDleteTask(PtrStructTask_QueueENTRY * Copy_PtrQueueEntry, Queue_t * Copy_PtrQueue)
{
    QueueNode_t *Local_PtrQueueNode = Copy_PtrQueue->Queue_Front;
    *Copy_PtrQueueEntry = Local_PtrQueueNode->QueueNode_Entry;
    Copy_PtrQueue->Queue_Front = Local_PtrQueueNode->QueueNode_Next;
    free(Local_PtrQueueNode->QueueNode_Entry);
    free(Local_PtrQueueNode);
    if(!Copy_PtrQueue->Queue_Front)
    {
        Copy_PtrQueue->Queue_Rear = NULL;
    }
    Copy_PtrQueue->Queue_Size--;
}

void SCHEDULER_voidDeleteTask(uint8 Copy_uint8TaskPosition,Queue_t * Copy_PtrQueue)
{
    uint8 Local_uint8Counter;
    QueueNode_t * Local_PtrQueueNodeTemp;
    QueueNode_t * Local_PtrQueueNode;
    if(Copy_uint8TaskPosition == 0)
    {
        Local_PtrQueueNodeTemp = Copy_PtrQueue->Queue_Front->QueueNode_Next;
        free(Copy_PtrQueue->Queue_Front->QueueNode_Entry);
        free(Copy_PtrQueue->Queue_Front);
        Copy_PtrQueue->Queue_Front = Local_PtrQueueNodeTemp;
    }
    else
    {
       for(Local_PtrQueueNode = Copy_PtrQueue->Queue_Front,Local_uint8Counter = 0;Local_uint8Counter < Copy_uint8TaskPosition - 1;Local_uint8Counter++)
       {
           Local_PtrQueueNode = Local_PtrQueueNode->QueueNode_Next;
       }
       Local_PtrQueueNodeTemp = Local_PtrQueueNode->QueueNode_Next->QueueNode_Next;
       free(Local_PtrQueueNode->QueueNode_Next->QueueNode_Entry);
       free(Local_PtrQueueNode->QueueNode_Next);
       Local_PtrQueueNode->QueueNode_Next = Local_PtrQueueNodeTemp;
    }
    Copy_PtrQueue->Queue_Size--;
}

void SCHEDULER_voidReplaceTask(uint8 Copy_uint8TaskPosition, PtrStructTask_QueueENTRY * Copy_PtrQueueEntry, Queue_t * Copy_PtrQueue)
{
    uint8 Local_uint8Counter;
    QueueNode_t * Local_PtrQueueNode;
    if(Copy_uint8TaskPosition == 0)
    {
        Copy_PtrQueue->Queue_Front->QueueNode_Entry = *Copy_PtrQueueEntry;
    }
    else
    {
        for(Local_PtrQueueNode = Copy_PtrQueue->Queue_Front, Local_uint8Counter = 0;Local_uint8Counter < Copy_uint8TaskPosition;Local_uint8Counter++)
       {
           Local_PtrQueueNode = Local_PtrQueueNode->QueueNode_Next;
       }
       Local_PtrQueueNode->QueueNode_Entry = *Copy_PtrQueueEntry;
    }

}

uint8  SCHEDULER_uint8IsQueueEmpty(Queue_t * Copy_PtrQueue)
{
    return !Copy_PtrQueue->Queue_Size;
}

uint8  SCHEDULER_uint8IsQueueFull(Queue_t * Copy_PtrQueue)
{
    return 0;
}

uint8  SCHEDULER_uint8QueueSize(Queue_t * Copy_PtrQueue)
{
    return Copy_PtrQueue->Queue_Size;
}


void SCHEDULER_voidClearQueue(Queue_t * Copy_PtrQueue)
{
    while(Copy_PtrQueue->Queue_Front)
    {
        Copy_PtrQueue->Queue_Rear = Copy_PtrQueue->Queue_Front->QueueNode_Next;
        free(Copy_PtrQueue -> Queue_Front);
        Copy_PtrQueue->Queue_Front = Copy_PtrQueue->Queue_Rear;
    }
    Copy_PtrQueue->Queue_Size = 0;
}

void SCHEDULER_voidTraverseQueue(Queue_t * Copy_PtrQueue, void (*PF)(PtrStructTask_QueueENTRY Copy_QueueEntry))
{
    QueueNode_t *Local_PtrQueueNode;
    for(Local_PtrQueueNode = Copy_PtrQueue -> Queue_Front;Local_PtrQueueNode;Local_PtrQueueNode = Local_PtrQueueNode -> QueueNode_Next)
    {
        (*PF)(Local_PtrQueueNode -> QueueNode_Entry);
    }
}

/*!<Dispatch function*/
void SCHEDULER_voidDispatchTasks(Queue_t * Copy_PtrQueue)
{
    QueueNode_t *Local_PtrQueueNode;
    uint8 Local_uint8TaskPosition = 0;
    for(Local_PtrQueueNode = Copy_PtrQueue -> Queue_Front;Local_PtrQueueNode;Local_PtrQueueNode = Local_PtrQueueNode -> QueueNode_Next)
    {
        if(Local_PtrQueueNode->QueueNode_Entry->Task_uint8State == SCHEDULER_TASK_STATE_READY_TO_RUN)
        {
            Local_PtrQueueNode->QueueNode_Entry->Task_uint8State = SCHEDULER_TASK_STATE_RUNNING;
            /*!<Run the task */
            Local_PtrQueueNode->QueueNode_Entry->Task_PtrCode(Local_PtrQueueNode->QueueNode_Entry->Task_PtrVoidParameter);        
            Local_PtrQueueNode->QueueNode_Entry->Task_uint8State = SCHEDULER_TASK_STATE_READY;                                                           
            /*!<Periodic tasks will automatically run again*/
            /*!<if this is a 'one shot' task, remove it from the array*/
            if(Local_PtrQueueNode->QueueNode_Entry->Task_uint16Period == SCHEDULER_ONE_SHOT_TASK)
            {
                SCHEDULER_voidDeleteTask(Local_uint8TaskPosition,Copy_PtrQueue);
            }
        }
        Local_uint8TaskPosition++;
    }
    /*!<Report system status*/
    //SCH_Report_Status();
    /*!<The scheduler enters idle mode at this point*/
    //SCH_Go_To_Sleep();
}


/*************** END OF FUNCTIONS ***************************************************************************/
