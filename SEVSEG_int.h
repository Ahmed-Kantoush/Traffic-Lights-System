/*
 * SEVSEG_int.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: MR USER
 */

#ifndef SEVSEG_INT_H_
#define SEVSEG_INT_H_

void SEVSEG_voidInitialize(void);
void SEVSEG_voidDisplay(u8 SegNum, u8 Num);
void SEVSEG_voidEnable(u8 SegNum);
void SEVSEG_voidDisable(u8 SegNum);

#define SevSeg_0 0
#define SevSeg_1 1

#endif /* SEVSEG_INT_H_ */
