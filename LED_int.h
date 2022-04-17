/*
 * LED_int.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: MR USER
 */

#ifndef LED_INT_H_
#define LED_INT_H_

void LED_voidInitialize();
void LED_voidOn(u8 LedName);
void LED_voidOff(u8 LedName);
void LED_voidToggle(u8 LedName);

#define LED_0 0
#define LED_1 1
#define LED_2 2
#define LED_3 3
#define LED_4 4
#define LED_5 5
#define LED_6 6
#define LED_7 7

#endif /* LED_INT_H_ */
