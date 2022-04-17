/*********************************************/
/* Author : Mario Ramzy                      */
/* Date : 24/2/2018		                     */
/* version : V01		                     */

#ifndef _RTO_INIT_H
#define _RTO_INIT_H

typedef struct
{
	void (*TaskHandler) (void);
	u8 Periodicity;
	u8 State;
}task;

extern u8 flag;

void RTO_voidInitialize(void);

void RTO_voidCreateTask(task* Ptask, u8 periority);

void RTO_voidSuspendTask(u8 periority);

void RTO_voidContinueTask(u8 periority);

void Scheduler(void);

#endif
