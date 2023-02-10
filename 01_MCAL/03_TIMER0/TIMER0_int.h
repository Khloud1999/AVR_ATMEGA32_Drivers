/*******************************************************/
/* Author   : Kholoud Khaled                           */
/* Date     : 29 Jan  2023                             */
/* File     : TIMER0_int.h                             */
/* Version  : V 0.0                                    */
/*******************************************************/

#ifndef MCAL_TIMER0_TIMER0_INT_H_
#define MCAL_TIMER0_TIMER0_INT_H_

#define INVERTED       1
#define NON_INVERTED   2

#define PRESCALER_1		1
#define PRESCALER_8		2
#define PRESCALER_64	3
#define PRESCALER_256	4
#define PRESCALER_1024	5


#define CTC_TOGGLE_OC0    1
#define CTC_CLR_OC0       2
#define CTC_SET_OC0    	  3


//for all modes
void TMR0_voidInit(void);
void TMR0_voidStart(uint8 copy_u8Prescaler);
void TMR0_voidSetTCNT0(uint8 copy_u8InitValue);
uint32 TMR0_u32Read(void);

//for normal mode
void TMR0_voidSetNormalIntrrupt(void(*copy_CB)(void));

//for CTC mode
void TMR0_CTC_voidSetOCR(uint8 copy_u8InitValue,uint8 copy_u8Mode);
void TMR0_voidSetCTCIntrrupt(void(*copy_CB)(void));

//for all modes
void TMR0_voidStopTMR0(void);
//set TCCR0 =0x00
void TMR0_voidDInit(void);

//for fast PWM mode
void TMR0_GeneratePhaseCorrectPWM(uint8 copy_u8DutyCycle,uint8 copy_u8pulse);

//for correct PMW mode

void TMR0_GeneratePhaseCorrectPWM(uint8 copy_u8DutyCycle,uint8 copy_u8pulse);


#endif /* MCAL_TIMER0_TIMER0_INT_H_ */
