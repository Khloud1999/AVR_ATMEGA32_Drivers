/*******************************************************/
/* Author   : Kholoud Khaled                           */
/* Date     : 19 Jan 2023                              */
/* File     : LM35_int.h                               */
/* Version  : V 0.0                                    */
/*******************************************************/

#ifndef HAL_LM35_LM35_INT_H_
#define HAL_LM35_LM35_INT_H_

#define ADC0  0
#define ADC1  1
#define ADC2  2
#define ADC3  3
#define ADC4  4
#define ADC5  5
#define ADC6  6
#define ADC7  7

void LM35_voidInit (uint8 u8Channelcopy);

uint16 LM35_u8Read(void);


#endif /* HAL_LM35_LM35_INT_H_ */
