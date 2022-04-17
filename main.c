/*
 * main.c
 *
 *  Created on: 10 Mar 2018
 *      Author: MarioSonlord
 */

#include "std_types.h"
#include "DIO_int.h"
#include "GIE_int.h"
#include "TIM0_int.h"
#include "RTO_int.h"
#include "LCD_int.h"
#include "LED_int.h"
#include "SWI_int.h"
#include "SEVSEG_int.h"

enum color {Red, Yellow, Green};
enum color state = 0;
u8 c, j, x, y;
s8 i = 9;

void counter()
{
	if (c == 1)
	{
		LCD_ClrScreen();
		SEVSEG_voidDisplay(SevSeg_0, j);
		if (j == 0)
		{
			c = 0;
			LED_voidOff(LED_2);
			SEVSEG_voidDisplay(SevSeg_0, i);
			i--;
			if (state == Red)
			{
				RTO_voidContinueTask(2);
				LED_voidOn(LED_0);
			}
			else
				LED_voidOn(LED_1);
		}
		else
			j--;
	}
	else
	{
		if (state == Red)
		{
			if (i == 9)
			{
				RTO_voidContinueTask(2);
				x = 0;
				y = 0;
				LED_voidOff(LED_2);
				LED_voidOn(LED_0);
			}
			SEVSEG_voidDisplay(SevSeg_0, i);
			i--;
			if (i <= -1)
			{
				state = Yellow;
				i = 5;
			}
		}
		else if(state == Yellow)
		{
			if (i == 5)
			{
				RTO_voidSuspendTask(2);
				LCD_ClrScreen();
				LED_voidOff(LED_0);
				LED_voidOn(LED_1);
			}
			SEVSEG_voidDisplay(SevSeg_0, i);
			i--;
			if (i <= -1)
			{
			state = Green;
				i = 9;
			}
		}
		else
		{
			if (i == 9)
			{
				LED_voidOff(LED_1);
				LED_voidOn(LED_2);
			}
			SEVSEG_voidDisplay(SevSeg_0, i);
			i--;
			if (i == 0)
			{
				state = Red;
				i = 9;
			}
		}
	}
}

void check()
{
	if ((SWI_s8GetState(SWITCH_0) == Pressed) && (state != Green) && (c == 0))
	{
		c = 1;
		j = 5;
		if (state == Red)
		{
			RTO_voidSuspendTask(2);
			LED_voidOff(LED_0);
		}
		else
			LED_voidOff(LED_1);
		LED_voidOn(LED_2);
	}
}

void adv()
{
	LCD_ClrScreen();
	LCD_voidGoTo(x, y);
	LCD_voidWriteString("Coca-Cola");
	if (x == 6)
	{
		x = 0;
		y ^= 1;
	}
	else
		x++;
}

int main(void)
{
	DIO_voidInitialize();
	GIE_voidEnable();
	task task1 = {counter, 5, 1};
	task task2 = {check, 2, 1};
	task task3 = {adv, 1, 0};
	RTO_voidCreateTask(&task1 , 1);
	RTO_voidCreateTask(&task2 , 0);
	RTO_voidCreateTask(&task3 , 2);
	TIM0_voidInitialize();
	TIM0_voidEnableInt();
	RTO_voidInitialize();
	SEVSEG_voidInitialize();
	SWI_voidInitialize();
	LED_voidInitialize();
	LCD_voidInitialize();

	while(1)
	{
		if (flag == 1)
		{
			Scheduler();
			flag = 0;
		}
	}
}
