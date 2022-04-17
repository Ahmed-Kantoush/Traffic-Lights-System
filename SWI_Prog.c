/*
 * SWI_Prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: MR USER
 */

#include "std_types.h"
#include "bitmath.h"
#include "DIO_int.h"
#include "SWI_Priv.h"
#include "SWI_Config.h"
#include "SWI_int.h"

void SWI_voidInitialize()
{

}

s8 SWI_s8GetState(u8 SWINum)
{
	switch(SWINum)
	{
	case SWITCH_0:
		#if (SWITCH_0_Mode == PULL_UP)
			if (DIO_u8GetPin(SWITCH_0_PIN) == HIGH)
				return unPressed;
			else
				return Pressed;
		#elif (SWITCH_0_Mode == PULL_DOWN)
			if (DIO_u8GetPin(SWITCH_0_PIN) == LOW)
				return unPressed;
			else
				return Pressed;
		#else
			#error "Wrong Mode!"
		#endif
	break;

	case SWITCH_1:
		#if (SWITCH_1_Mode == PULL_UP)
			if (DIO_u8GetPin(SWITCH_1_PIN) == HIGH)
				return unPressed;
			else
				return Pressed;
		#elif (SWITCH_1_Mode == PULL_DOWN)
			if (DIO_u8GetPin(SWITCH_1_PIN) == LOW)
				return unPressed;
			else
				return Pressed;
		#else
			#error "Wrong Mode!"
		#endif
	break;

	case SWITCH_2:
		#if (SWITCH_2_Mode == PULL_UP)
			if (DIO_u8GetPin(SWITCH_2_PIN) == HIGH)
				return unPressed;
			else
				return Pressed;
		#elif (SWITCH_2_Mode == PULL_DOWN)
			if (DIO_u8GetPin(SWITCH_2_PIN) == LOW)
				return unPressed;
			else
				return Pressed;
		#else
			#error "Wrong Mode!"
		#endif
	break;

	case SWITCH_3:
		#if (SWITCH_3_Mode == PULL_UP)
			if (DIO_u8GetPin(SWITCH_3_PIN) == HIGH)
				return unPressed;
			else
				return Pressed;
		#elif (SWITCH_3_Mode == PULL_DOWN)
			if (DIO_u8GetPin(SWITCH_3_PIN) == LOW)
				return unPressed;
			else
				return Pressed;
		#else
			#error "Wrong Mode!"
		#endif
	break;

	default:
		return -1;
	break;
	}
}
