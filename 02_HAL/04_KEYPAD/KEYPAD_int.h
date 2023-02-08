/*******************************************************/
/* Author   : Kholoud Khaled                           */
/* Date     : 29 DEC 2022                              */
/* File     : KEYPAD_int.h                             */
/* Version  : V 0.0                                    */
/*******************************************************/

#ifndef HAL_KEYPAD_KEYPAD_INT_H_
#define HAL_KEYPAD_KEYPAD_INT_H_

#define NOTPRESSED         0xff

void Keypad_voidInit (void);

uint8 keypad_u8CheckPress(void);


#endif /* HAL_KEYPAD_KEYPAD_INT_H_ */
