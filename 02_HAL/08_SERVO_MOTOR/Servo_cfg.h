/*******************************************************/
/* Author   : Kholoud Khaled                           */
/* Date     : 11 Feb  2023                             */
/* File     : Servo_cfg.h                              */
/* Version  : V 0.0                                    */
/*******************************************************/

#ifndef SERVO_CFG_H_
#define SERVO_CFG_H_

#define SERVO_PWM_MODE		         FAST_PWM_TOP_ICR1

#define SERVO_TIMER1_PWM_PRESCALER	 FCLK_DEV_64

#define TIMER1_TOP_VALUE			 2500

#define TIMER1_PULSE_TYPE			 INVERTED

#define SERVO_TIMER0_CHANNEL		 TIMER1_CHANNEL_A

#endif  /*SERVO_CFG_H_ */
