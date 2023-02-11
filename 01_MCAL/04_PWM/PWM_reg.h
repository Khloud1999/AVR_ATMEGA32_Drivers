/*******************************************************/
/* Author   : Kholoud Khaled                           */
/* Date     : 11 Feb  2023                             */
/* File     : PWM_reg.c                                */
/* Version  : V 0.0                                    */
/*******************************************************/

#ifndef MCAL_PWM_PWM_REG_H_
#define MCAL_PWM_PWM_REG_H_


#define TCCR0  *((volatile uint8*)0x53)
#define TCNT0  *((volatile uint8*)0x52)
#define TIFR   *((volatile uint8*)0x58)
#define OCR0   *((volatile uint8*)0x5c)
#define TIMSK  *((volatile uint8*)0x59)

#define TCCR1A 	*((volatile uint8*)0x4F)
#define TCCR1B 	*((volatile uint8*)0x4E)
#define TCNT1	*((volatile uint16*)0x4C)
#define ICR1 	*((volatile uint16*)0x46)
#define OCR1B	*((volatile uint16*)0x48)
#define OCR1A	*((volatile uint16*)0x4A)

//TCCR0 BITS
#define CS00 0
#define CS01 1
#define CS02 2
#define WGM01 3
#define COM00 4
#define COM01 5
#define WGM00 6
#define FOC0  7


#define TOP     256

#define     PWM_pre_1				   	(0b001)
#define     PWM_pre_8                   (0b010)
#define     PWM_pre_64                   (0b011)
#define     PWM_pre_256                  (0b100)
#define     PWM_pre_1024                 (0b101)


#endif /* MCAL_PWM_PWM_REG_H_ */
