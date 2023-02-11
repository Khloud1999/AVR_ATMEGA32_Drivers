/*******************************************************/
/* Author   : Kholoud Khaled                           */
/* Date     : 11 Feb  2023                             */
/* File     : Servo_src.h                              */
/* Version  : V 0.0                                    */
/*******************************************************/


/*LIB include*/
#include "../../SERV/STD_TYPES.h"
#include "../../SERV/BIT_MATH.h"
/*driver include*/
#include "../../MCAL/DIO/Dio_int.h"
#include"../../MCAL/PWM/PWM_int.h"

#include"Servo_cfg.h"
#include"Servo_int.h"


void SERVO_voidInit(void){
	T1_FastPWM_Configs (SERVO_TIMER1_PWM_PRESCALER,  SERVO_PWM_MODE , TIMER1_TOP_VALUE );
}

void SERVO_voidMoveAngle(uint8 Copy_u8Degree){
	uint8 Local_u8DutyCycle = 0;
		switch(Copy_u8Degree)
		{
		case 0 	 : Local_u8DutyCycle = 5; break;
		case 90  : Local_u8DutyCycle = 7.5; break;
		case 180 : Local_u8DutyCycle = 10; break;
		}
		T1_FastPWM( Local_u8DutyCycle, TIMER1_PULSE_TYPE, SERVO_TIMER0_CHANNEL, TIMER1_TOP_VALUE);
}
