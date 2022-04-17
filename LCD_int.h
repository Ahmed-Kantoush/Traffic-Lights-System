/*
 * LCD_int.h
 *
 *  Created on: 24 Aug 2019
 *      Author: Ahmed
 */

#ifndef LCD_INT_H_
#define LCD_INT_H_

void LCD_voidInitialize();
void LCD_voidWriteChar(u8 Data);
void LCD_voidWriteCmd(u8 Cmd);
void LCD_ClrScreen();
void LCD_voidGoTo(u8 x, u8 y);
void LCD_voidWriteString(char* x);
void LCD_voidPrintf(char* format, ...);

#define CLR_DISP 1
#define RETURN_HOME 2

#endif /* LCD_INT_H_ */
