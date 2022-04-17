/*********************************************/
/* Author : Mario Ramzy                      */
/* Date : 10/3/2018		                     */
/* version : V01		                     */

#include "std_types.h"

#include "bitmath.h"

#include "TIM0_int.h"
#include "RTO_priv.h"
#include "RTO_config.h"

#include "RTO_int.h"
#include "DIO_int.h"
static u16 ov_counter ;
static u16 Current_tick;
u8 flag = 0;
/***********************************************************************/

task* SysTasks[RTO_u8_TASKS_NUM];


void RTO_voidInitialize(void)
{
	ov_counter = 0;
	Current_tick = 0;
	TIM0_voidSetRegister(RTO_u8_TIM_INIT);
	TIM0_voidSetCallBack(Kernel);
}

static void Kernel(void)
{
	ov_counter++;
	if (ov_counter == RTO_u16_max_ov)
	{
		ov_counter = 0;
		TIM0_voidSetRegister(RTO_u8_TIM_INIT);
		Current_tick++;
		flag = 1;
	}
}

void Scheduler(void)
{
	u8 i;

	for(i=0; i<RTO_u8_TASKS_NUM; i++)
	{
		// Check Task periodicity
		if(( (Current_tick % SysTasks[i]->Periodicity) == 0) && (SysTasks[i]->State == 1))
		{
			SysTasks[i]->TaskHandler();
		}
	}
}

void RTO_voidCreateTask(task* Ptask, u8 periority)
{
	SysTasks[periority] = Ptask;
}

void RTO_voidSuspendTask(u8 periority)
{
	SysTasks[periority]->State = 0;
}

void RTO_voidContinueTask(u8 periority)
{
	SysTasks[periority]->State = 1;
}
