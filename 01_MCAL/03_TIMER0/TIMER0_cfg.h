/*******************************************************/
/* Author   : Kholoud Khaled                           */
/* Date     : 29 Jan  2023                             */
/* File     : TIMER0_cfg.h                             */
/* Version  : V 0.0                                    */
/*******************************************************/

#ifndef MCAL_TIMER0_TIMER0_CFG_H_
#define MCAL_TIMER0_TIMER0_CFG_H_


/* Options : 0 for Normal mode
			 1 for Phase PWM mode
			 2 for CTC Mode
			 3 for Fast PWM mode
			 4 for NON-PWM mode
*/
#define  TMR0_MODE  3


/* Options : 0 for Disable FOC0
			 1 for Enable  FOC0
*/
#define  TMR0_FOC0  0

/* Options : 0 for Disable Overflow Interrupt
			 1 for Enable  Overflow Interrupt
*/
#define TMR0_TOVINTERRUPT   0


/* Options : 0 for Disable Compare match Interrupt
			 1 for Enable  Compare match Interrupt
*/
#define TMR0_TOCFINTERRUPT 0


#endif /* MCAL_TIMER0_TIMER0_CFG_H_ */
