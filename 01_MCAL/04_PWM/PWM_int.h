/*******************************************************/
/* Author   : Kholoud Khaled                           */
/* Date     : 11 Feb  2023                             */
/* File     : PWM_int.c                                */
/* Version  : V 0.0                                    */
/*******************************************************/

#ifndef PWM_INT_H_
#define PWM_INT_H_

#define INVERTED       1
#define NON_INVERTED   2

#define FAST_PWM_TOP_ICR1	0

#define FCLK_DEV_256		1
#define FCLK_DEV_64			2


#define TIMER1_CHANNEL_A	0
#define TIMER1_CHANNEL_B	1

//This Functions is used to control the intensity of Voltage by changing the duty cycle.


// in case non_inverted : Duty cycle=[OCR+1 /(2^n)]
// in case inverted : Duty cycle=[1-(OCR+1 /(2^n))]
// This Function gives Output RMS = Amplitude * sqrt(duty Cycle)
//      in case inverted the pulse starts from low.
//   	in case non_inverted the pulse starts from high.

void T0_FastPwm(float32 duty, uint8 pulse);

//in case non_inverted : Duty cycle=[OCR/(2^n -1)]
// in case inverted : Duty cycle=[1- OCR/(2^n -1)]
//      in case inverted the pulse starts from low.
//  	in case non_inverted the pulse starts from high.

void T0_PhaseCorrectPwm(float32 duty,uint8 pulse);

void T1_FastPWM_Configs(uint8 Copy_u8Prescaler ,uint8 copy_u8Mode , uint16 Copy_u16TopValue);

void T1_FastPWM(float32 Copy_u16DutyCycle , uint8 Copyu8_Pulse , uint8 Copy_u8ChannelNumber , uint16 Copy_u16TopValue);

#endif /* PWM_INT_H_ */
