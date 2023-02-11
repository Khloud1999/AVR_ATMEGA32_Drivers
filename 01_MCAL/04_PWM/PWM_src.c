/*******************************************************/
/* Author   : Kholoud Khaled                           */
/* Date     : 11 Feb  2023                             */
/* File     : PWM_src.c                                */
/* Version  : V 0.0                                    */
/*******************************************************/

#include "../../SERV/STD_TYPES.h"
#include "../../SERV/BIT_MATH.h"
#include "../DIO/Dio_int.h"
#include "../DIO/Dio_reg.h"
#include "PWM_cfg.h"
#include "PWM_int.h"
#include "PWM_reg.h"

void T0_FastPwm(float32 duty, uint8 pulse){
	DDRB_REG = (1 << 3);

		switch(pulse)
		{
		case INVERTED :
			OCR0 = ((TOP-1)-(duty*(TOP-1)/100));
			TCCR0 = (1 << WGM00) | (1 << COM01) | (1 << COM00) | PWM_prescaller;
			break;

		case NON_INVERTED :
			OCR0 =  (duty*(TOP-1)) /100;
			TCCR0 = (1 << WGM00) | (1 << COM01) | PWM_prescaller;
			break;

		default :
			break;
		}
}

void T0_PhaseCorrectPwm(float32 duty,uint8 pulse){
	DDRB_REG = (1 << 3);

		switch(pulse)
		{
		case INVERTED :
			OCR0 = ((TOP-1)-(duty*(TOP-1)/100));
			TCCR0 = (1 << WGM00) | (1 << COM01) | (1 << COM00) | PWM_prescaller;
			break;

		case NON_INVERTED :
			OCR0 = (duty*(TOP-1))/100;
			TCCR0 = (1 << WGM00) | (1 << COM01) | PWM_prescaller;
			break;

		default :
			break;
		}
}

void T1_FastPWM_Configs(uint8 Copy_u8Prescaler ,uint8 copy_u8Mode , uint16 Copy_u16TopValue){
	// Pre-scaler selection
	switch(Copy_u8Prescaler)
	{
	case FCLK_DEV_256 :
		TCCR1B |= (4 << 0); // Clock/256
		break;
	case FCLK_DEV_64:
		TCCR1B |= (3 << 0); // Clock/64
		break;
	default :
		TCCR1B &=~(0b111 << 0); // Clock
		break;
	}

	// Mode Selection
	switch(copy_u8Mode)
	{
	case FAST_PWM_TOP_ICR1 :
		TCCR1A |=(2 << 0);  // Fast PWm mode and the Top is ICR1
		TCCR1B |=(3 << 3);
		ICR1 = Copy_u16TopValue; // write the top value to compare with
		break;
	default :
		// Normal Mode
		TCCR1A &=~(3 << 0);  // Clear the first two bits
		TCCR1B &=~(3 << 3);
		break;
	}
}

void T1_FastPWM(float32 Copy_u16DutyCycle , uint8 Copyu8_Pulse , uint8 Copy_u8ChannelNumber , uint16 Copy_u16TopValue){
	switch(Copyu8_Pulse)
		{
		case INVERTED:
			switch(Copy_u8ChannelNumber)
			{
			case TIMER1_CHANNEL_A :
				DIO_u8SetPinDir(PORT_D , PIN_5, OUTPUT);
				OCR1A = Copy_u16TopValue - ( (Copy_u16DutyCycle * Copy_u16TopValue)/100 )-1;
				TCCR1A &=~(3 << 6); // Clear the two bits first
				TCCR1A |= (3 << 6); // Select the Channel A as Inverted
				break;
			case TIMER1_CHANNEL_B:
				DIO_u8SetPinDir(PORT_D , PIN_4, OUTPUT);
				OCR1B = Copy_u16TopValue - ( (Copy_u16DutyCycle * Copy_u16TopValue)/100 )-1;
				TCCR1A &=~(3 << 4); // Clear the two bits first
				TCCR1A |= (3 << 4);	// Select the Channel B as Inverted
				break;
			default :
				OCR1A = Copy_u16TopValue - ( (Copy_u16DutyCycle * Copy_u16TopValue)/100 )-1;
				TCCR1A &=~(3 << 6); // Clear the two bits first
				TCCR1A |= (3 << 6); // Default using channel A
				break;
			}
			break;

			case NON_INVERTED:
				switch(Copy_u8ChannelNumber)
				{
				case TIMER1_CHANNEL_A :
					DIO_u8SetPinDir(PORT_D , PIN_5, OUTPUT);
					OCR1A = (Copy_u16DutyCycle * Copy_u16TopValue)/100 -1 ;
					TCCR1A &=~(3 << 6); // Clear the two bits first
					TCCR1A |= (2 << 6); // Select the Channel A as Non Inverted
					break;
				case TIMER1_CHANNEL_B:
					DIO_u8SetPinDir(PORT_D , PIN_4, OUTPUT);
					OCR1B = (Copy_u16DutyCycle * Copy_u16TopValue)/100 -1; // Inverted
					TCCR1A  &=~(3 << 4); // Clear the two bits first
					TCCR1A |= (2 << 4); // Select the Channel B as Non Inverted
					break;
				default :
					OCR1A = (Copy_u16DutyCycle * Copy_u16TopValue)/100 -1;
					TCCR1A &=~(3 << 6); // Clear the two bits first
					TCCR1A |= (2 << 6);
					break;
				}

				break;
		}
}

