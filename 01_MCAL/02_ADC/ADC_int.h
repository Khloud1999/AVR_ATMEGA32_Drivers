/*******************************************************/
/* Author   : Kholoud Khaled                           */
/* Date     : 11 Jan  2023                             */
/* File     : ADC_int.h                                */
/* Version  : V 0.0                                    */
/*******************************************************/

#ifndef MCAL_ADC_ADC_INT_H_
#define MCAL_ADC_ADC_INT_H_

#define ADC0  0
#define ADC1  1
#define ADC2  2
#define ADC3  3
#define ADC4  4
#define ADC5  5
#define ADC6  6
#define ADC7  7

void ADC_voidInit(uint8 copy_u8Channel);

uint16  ADC_u16Read(void);


#endif /* MCAL_ADC_ADC_INT_H_ */
