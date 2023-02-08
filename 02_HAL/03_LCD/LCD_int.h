/*******************************************************/
/* Author   : Kholoud Khaled                           */
/* Date     : 20 DEC 2022                              */
/* File     : LCD_int.h                                */
/* Version  : V 0.0                                    */
/*******************************************************/

#ifndef LCD_INT_H_
#define LCD_INT_H_

void LCD_voidInit(void);
void LCD_voidWriteCmd(uint8 u8CommandCopy);
void LCD_voidWriteChar(uint8 u8CharacterCopy);
void LCD_voidClearScreen (void);

void LCD_voidShiftLeft (void);
void LCD_voidShiftRight (void);

void LCD_voidMoveCursor (uint8 u8RowCopy ,uint8 u8ColoumnCopy);
void LCD_voidWriteNumber(uint32 u32NumberCopy);
void LCD_voidWriteString(uint8 *u8stringCopy);
void LCD_voidWriteRealNumber(float32  f32NumberCopy);



#endif /* LCD_INT_H_ */
