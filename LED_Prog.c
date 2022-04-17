/*
 * LED_Prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: MR USER
 */

#include "std_types.h"
#include "bitmath.h"
#include "DIO_int.h"
#include "LED_Priv.h"
#include "LED_Config.h"
#include "LED_int.h"

void LED_voidInitialize()
{
	LED_voidOff(LED_0);
	LED_voidOff(LED_1);
	LED_voidOff(LED_2);
	LED_voidOff(LED_3);
	LED_voidOff(LED_4);
	LED_voidOff(LED_5);
	LED_voidOff(LED_6);
	LED_voidOff(LED_7);
}

void LED_voidOn(u8 LedNum)
{
	switch (LedNum)
	{
	case LED_0:
		#if (LED_0_Mode == Forward)
			DIO_voidSetPin(LED_0_PIN, HIGH);
		#elif (LED_0_Mode == Backward)
			DIO_voidSetPin(LED_0_PIN, LOW);
		#else
			#error "Wrong mode"
		#endif
	break;

	case LED_1:
		#if (LED_1_Mode == Forward)
			DIO_voidSetPin(LED_1_PIN, HIGH);
		#elif (LED_1_Mode == Backward)
			DIO_voidSetPin(LED_1_PIN, LOW);
		#else
			#error "Wrong mode"
		#endif
	break;

	case LED_2:
		#if (LED_2_Mode == Forward)
			DIO_voidSetPin(LED_2_PIN, HIGH);
		#elif (LED_2_Mode == Backward)
			DIO_voidSetPin(LED_2_PIN, LOW);
		#else
			#error "Wrong mode"
		#endif
	break;

	case LED_3:
		#if (LED_3_Mode == Forward)
			DIO_voidSetPin(LED_3_PIN, HIGH);
		#elif (LED_3_Mode == Backward)
			DIO_voidSetPin(LED_3_PIN, LOW);
		#else
			#error "Wrong mode"
		#endif
	break;

	case LED_4:
		#if (LED_4_Mode == Forward)
			DIO_voidSetPin(LED_4_PIN, HIGH);
		#elif (LED_4_Mode == Backward)
			DIO_voidSetPin(LED_4_PIN, LOW);
		#else
			#error "Wrong mode"
		#endif
	break;

	case LED_5:
		#if (LED_5_Mode == Forward)
			DIO_voidSetPin(LED_5_PIN, HIGH);
		#elif (LED_5_Mode == Backward)
			DIO_voidSetPin(LED_5_PIN, LOW);
		#else
			#error "Wrong mode"
		#endif
	break;

	case LED_6:
		#if (LED_6_Mode == Forward)
			DIO_voidSetPin(LED_6_PIN, HIGH);
		#elif (LED_6_Mode == Backward)
			DIO_voidSetPin(LED_6_PIN, LOW);
		#else
			#error "Wrong mode"
		#endif
	break;

	case LED_7:
		#if (LED_7_Mode == Forward)
			DIO_voidSetPin(LED_7_PIN, HIGH);
		#elif (LED_7_Mode == Backward)
			DIO_voidSetPin(LED_7_PIN, LOW);
		#else
			#error "Wrong mode"
		#endif
	break;

	}
}

void LED_voidOff(u8 LedNum)
{

	switch(LedNum)
	{
	case LED_0:
		#if (LED_0_Mode == Forward)
			DIO_voidSetPin(LED_0_PIN, LOW);
		#elif (LED_0_Mode == Backward)
			DIO_voidSetPin(LED_0_PIN, HIGH);
		#else
			#error "Wrong mode"
		#endif
	break;

	case LED_1:
		#if (LED_1_Mode == Forward)
			DIO_voidSetPin(LED_1_PIN, LOW);
		#elif (LED_1_Mode == Backward)
			DIO_voidSetPin(LED_1_PIN, HIGH);
		#else
			#error "Wrong mode"
		#endif
	break;

	case LED_2:
		#if (LED_2_Mode == Forward)
			DIO_voidSetPin(LED_2_PIN, LOW);
		#elif (LED_2_Mode == Backward)
			DIO_voidSetPin(LED_2_PIN, HIGH);
		#else
			#error "Wrong mode"
		#endif
	break;

	case LED_3:
		#if (LED_3_Mode == Forward)
			DIO_voidSetPin(LED_3_PIN, LOW);
		#elif (LED_3_Mode == Backward)
			DIO_voidSetPin(LED_3_PIN, HIGH);
		#else
			#error "Wrong mode"
		#endif
	break;

	case LED_4:
		#if (LED_4_Mode == Forward)
			DIO_voidSetPin(LED_4_PIN, LOW);
		#elif (LED_4_Mode == Backward)
			DIO_voidSetPin(LED_4_PIN, HIGH);
		#else
			#error "Wrong mode"
		#endif
	break;

	case LED_5:
		#if (LED_5_Mode == Forward)
			DIO_voidSetPin(LED_5_PIN, LOW);
		#elif (LED_5_Mode == Backward)
			DIO_voidSetPin(LED_5_PIN, HIGH);
		#else
			#error "Wrong mode"
		#endif
	break;

	case LED_6:
		#if (LED_6_Mode == Forward)
			DIO_voidSetPin(LED_6_PIN, LOW);
		#elif (LED_6_Mode == Backward)
			DIO_voidSetPin(LED_6_PIN, HIGH);
		#else
			#error "Wrong mode"
		#endif
	break;

	case LED_7:
		#if (LED_7_Mode == Forward)
			DIO_voidSetPin(LED_7_PIN, LOW);
		#elif (LED_7_Mode == Backward)
			DIO_voidSetPin(LED_7_PIN, HIGH);
		#else
			#error "Wrong mode"
		#endif
	break;
	}
}

void LED_voidToggle(u8 LedNum)
{
	switch(LedNum)
	{
	case LED_0:
		DIO_voidTogglePin(LED_0_PIN);
	break;

	case LED_1:
		DIO_voidTogglePin(LED_1_PIN);
	break;

	case LED_2:
		DIO_voidTogglePin(LED_2_PIN);
	break;

	case LED_3:
		DIO_voidTogglePin(LED_3_PIN);
	break;

	case LED_4:
		DIO_voidTogglePin(LED_4_PIN);
	break;

	case LED_5:
		DIO_voidTogglePin(LED_5_PIN);
	break;

	case LED_6:
		DIO_voidTogglePin(LED_6_PIN);
	break;

	case LED_7:
		DIO_voidTogglePin(LED_7_PIN);
	break;
	}
}
