/*
 * DIO_Prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: MR USER
 */

#include "avr/io.h"
#include "std_types.h"
#include "bitmath.h"
#include "DIO_Priv.h"
#include "DIO_Config.h"
#include "DIO_int.h"

void DIO_voidInitialize(void)
{
	DDRA = conc(PIN_7DIR, PIN_6DIR, PIN_5DIR, PIN_4DIR, PIN_3DIR, PIN_2DIR, PIN_1DIR, PIN_0DIR);
	DDRB = conc(PIN_15DIR, PIN_14DIR, PIN_13DIR, PIN_12DIR, PIN_11DIR, PIN_10DIR, PIN_9DIR, PIN_8DIR);
	DDRC = conc(PIN_23DIR, PIN_22DIR, PIN_21DIR, PIN_20DIR, PIN_19DIR, PIN_18DIR, PIN_17DIR, PIN_16DIR);
	DDRD = conc(PIN_31DIR, PIN_30DIR, PIN_29DIR, PIN_28DIR, PIN_27DIR, PIN_26DIR, PIN_25DIR, PIN_24DIR);
}

void DIO_voidSetPin(u8 PinNum, u8 value)
{
	if (value == HIGH)
	{
		if ((PinNum >= 0) && (PinNum < 8))
			setbit(PORTA, PinNum);
		else if ((PinNum >= 8) && (PinNum < 16))
			setbit(PORTB, PinNum-8);
		else if ((PinNum >= 16) && (PinNum < 23))
			setbit(PORTC, PinNum-16);
		else if ((PinNum >= 24) && (PinNum < 32))
			setbit(PORTD, PinNum-24);
	}
	else if (value == LOW)
	{
		if ((PinNum >= 0) && (PinNum < 8))
			clrbit(PORTA, PinNum);
		else if ((PinNum >= 8) && (PinNum < 16))
			clrbit(PORTB, PinNum-8);
		else if ((PinNum >= 16) && (PinNum < 23))
			clrbit(PORTC, PinNum-16);
		else if ((PinNum >= 24) && (PinNum < 32))
			clrbit(PORTD, PinNum-24);
	}
}

u8 DIO_u8GetPin(u8 PinNum)
{
	u8 x;
	if ((PinNum >= 0) && (PinNum < 8))
		x = getbit(PINA, PinNum);
	else if ((PinNum >= 8) && (PinNum < 16))
		x = getbit(PINB, PinNum-8);
	else if ((PinNum >= 16) && (PinNum < 24))
		x = getbit(PINC, PinNum-16);
	else if ((PinNum >= 24) && (PinNum < 32))
		x = getbit(PIND, PinNum-24);
	return x;
}

void DIO_voidTogglePin(u8 PinNum)
{
	if ((PinNum >= 0) && (PinNum < 8))
			togbit(PORTA, PinNum);
		else if ((PinNum >= 8) && (PinNum < 16))
			togbit(PORTB, PinNum-8);
		else if ((PinNum >= 16) && (PinNum < 24))
			togbit(PORTC, PinNum-16);
		else if ((PinNum >= 24) && (PinNum < 32))
			togbit(PORTD, PinNum-24);
}
