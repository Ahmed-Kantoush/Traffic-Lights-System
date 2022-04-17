/*
 * SEVSEG_Prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: MR USER
 */


#include "std_types.h"
#include "bitmath.h"
#include "DIO_int.h"
#include "SEVSEG_Config.h"
#include "SEVSEG_Priv.h"
#include "SEVSEG_int.h"

void SEVSEG_voidInitialize()
{
	SEVSEG_voidDisplay(SevSeg_0, 0);
	SEVSEG_voidDisplay(SevSeg_1, 0);
}

u8 segC[10][7] = {
	{HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,LOW},
	{LOW,HIGH,HIGH,LOW,LOW,LOW,LOW},
	{HIGH,HIGH,LOW,HIGH,HIGH,LOW,HIGH},
	{HIGH,HIGH,HIGH,HIGH,LOW,LOW,HIGH},
	{LOW,HIGH,HIGH,LOW,LOW,HIGH,HIGH},
	{HIGH,LOW,HIGH,HIGH,LOW,HIGH,HIGH},
	{HIGH,LOW,HIGH,HIGH,HIGH,HIGH,HIGH},
	{HIGH,HIGH,HIGH,LOW,LOW,LOW,LOW},
	{HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH},
	{HIGH,HIGH,HIGH,HIGH,LOW,HIGH,HIGH}
};

u8 segA[10][7] = {
	{LOW,LOW,LOW,LOW,LOW,LOW,HIGH},
	{HIGH,LOW,LOW,HIGH,HIGH,HIGH,HIGH},
	{LOW,LOW,HIGH,LOW,LOW,HIGH,LOW},
	{LOW,LOW,LOW,LOW,HIGH,HIGH,LOW},
	{HIGH,LOW,LOW,HIGH,HIGH,LOW,LOW},
	{LOW,HIGH,LOW,LOW,HIGH,LOW,LOW},
	{LOW,HIGH,LOW,LOW,LOW,LOW,LOW},
	{LOW,LOW,LOW,HIGH,HIGH,HIGH,HIGH},
	{LOW,LOW,LOW,LOW,LOW,LOW,LOW},
	{LOW,LOW,LOW,LOW,HIGH,LOW,LOW}
};


void SEVSEG_voidDisplay(u8 SegNum, u8 Num)
{
	switch(SegNum)
	{
	case SevSeg_0:
		#if (SEVSEG_0_TYPE == COM_CATHODE)
			DIO_voidSetPin(SEVSEG_0_PIN_A, segC[Num][0]);
			DIO_voidSetPin(SEVSEG_0_PIN_B, segC[Num][1]);
			DIO_voidSetPin(SEVSEG_0_PIN_C, segC[Num][2]);
			DIO_voidSetPin(SEVSEG_0_PIN_D, segC[Num][3]);
			DIO_voidSetPin(SEVSEG_0_PIN_E, segC[Num][4]);
			DIO_voidSetPin(SEVSEG_0_PIN_F, segC[Num][5]);
			DIO_voidSetPin(SEVSEG_0_PIN_G, segC[Num][6]);
		#elif(SEVSEG_0_TYPE == COM_ANODE)
			DIO_voidSetPin(SEVSEG_0_PIN_A, segA[Num][0]);
			DIO_voidSetPin(SEVSEG_0_PIN_B, segA[Num][1]);
			DIO_voidSetPin(SEVSEG_0_PIN_C, segA[Num][2]);
			DIO_voidSetPin(SEVSEG_0_PIN_D, segA[Num][3]);
			DIO_voidSetPin(SEVSEG_0_PIN_E, segA[Num][4]);
			DIO_voidSetPin(SEVSEG_0_PIN_F, segA[Num][5]);
			DIO_voidSetPin(SEVSEG_0_PIN_G, segA[Num][6]);
		#elif (SEVSEG_0_TYPE == DISABLE)
		#else
			#error "Wrong type"
		#endif
	break;
	case SevSeg_1:
		#if (SEVSEG_1_TYPE == COM_CATHODE)
			DIO_voidSetPin(SEVSEG_1_PIN_A, segC[Num][0]);
			DIO_voidSetPin(SEVSEG_1_PIN_B, segC[Num][1]);
			DIO_voidSetPin(SEVSEG_1_PIN_C, segC[Num][2]);
			DIO_voidSetPin(SEVSEG_1_PIN_D, segC[Num][3]);
			DIO_voidSetPin(SEVSEG_1_PIN_E, segC[Num][4]);
			DIO_voidSetPin(SEVSEG_1_PIN_F, segC[Num][5]);
			DIO_voidSetPin(SEVSEG_1_PIN_G, segC[Num][6]);
		#elif(SEVSEG_1_TYPE == COM_ANODE)
			DIO_voidSetPin(SEVSEG_1_PIN_A, segA[Num][0]);
			DIO_voidSetPin(SEVSEG_1_PIN_B, segA[Num][1]);
			DIO_voidSetPin(SEVSEG_1_PIN_C, segA[Num][2]);
			DIO_voidSetPin(SEVSEG_1_PIN_D, segA[Num][3]);
			DIO_voidSetPin(SEVSEG_1_PIN_E, segA[Num][4]);
			DIO_voidSetPin(SEVSEG_1_PIN_F, segA[Num][5]);
			DIO_voidSetPin(SEVSEG_1_PIN_G, segA[Num][6]);
		#elif (SEVSEG_1_TYPE == DISABLE)
		#else
			#error "Wrong type"
		#endif
	break;
	}
}

void SEVSEG_voidEnable(u8 SegNum)
{
	switch(SegNum)
	{
	case SevSeg_0:
		#if (SEVSEG_0_TYPE == COM_CATHODE)
			DIO_voidSetPin(SEVSEG_0_PIN_Enable, LOW);
		#elif (SEVSEG_0_TYPE == COM_ANODE)
			DIO_voidSetPin(SEVSEG_0_PIN_Enable, HIGH);
		#elif (SEVSEG_0_TYPE == DISABLE)
		#else
			#error "Wrong type"
		#endif
	break;
	case SevSeg_1:
			#if (SEVSEG_1_TYPE == COM_CATHODE)
				DIO_voidSetPin(SEVSEG_1_PIN_Enable, LOW);
			#elif (SEVSEG_1_TYPE == COM_ANODE)
				DIO_voidSetPin(SEVSEG_1_PIN_Enable, HIGH);
			#elif (SEVSEG_1_TYPE == DISABLE)
			#else
				#error "Wrong type"
			#endif
	break;
	}
}

void SEVSEG_voidDisable(u8 SegNum)
{
	switch(SegNum)
	{
	case SevSeg_0:
		#if (SEVSEG_0_TYPE == COM_CATHODE)
			DIO_voidSetPin(SEVSEG_0_PIN_Enable, HIGH);
		#elif (SEVSEG_0_TYPE == COM_ANODE)
			DIO_voidSetPin(SEVSEG_0_PIN_Enable, LOW);
		#elif (SEVSEG_0_TYPE == DISABLE)
		#else
			#error "Wrong type"
		#endif
	break;
	case SevSeg_1:
			#if (SEVSEG_1_TYPE == COM_CATHODE)
				DIO_voidSetPin(SEVSEG_1_PIN_Enable, HIGH);
			#elif (SEVSEG_1_TYPE == COM_ANODE)
				DIO_voidSetPin(SEVSEG_1_PIN_Enable, LOW);
			#elif (SEVSEG_1_TYPE == DISABLE)
			#else
				#error "Wrong type"
			#endif
	break;
	}
}
