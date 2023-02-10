/*
 * TIIMER0_private.h
 *
 *  Created on: Jan 29, 2023
 *      Author: kholoud
 */

#ifndef MCAL_TIMER0_TIMER0_PRIVATE_H_
#define MCAL_TIMER0_TIMER0_PRIVATE_H_


#define TOP     256


#define TCNT0    *((volatile uint8*)0x52)
#define OCR0     *((volatile uint8*)0x5C)
#define TCCR0    *((volatile uint8*)0x53)
    #define CS00  0
	#define CS01  1
	#define CS02  2
	#define WGM01 3
	#define COM00 4
	#define COM01 5
	#define WGM00 6
	#define FOC0  7
#define TIMASK   *((volatile uint8*)0x59)
	#define TOIE0 0
	#define OCIE0 0
#define TIFR     *((volatile uint8*)0x58)
	#define TOV0  0
	#define OCF0  1

// Global Interrupt Register
#define SREG     *((volatile uint8*)0x5F)
// OC0 Data Direction Register
#define DDRB     *((volatile uint8*)0x37)



#endif /* MCAL_TIMER0_TIMER0_PRIVATE_H_ */
