/*******************************************************/
/* Author   : Kholoud Khaled                           */
/* Date     : 9 Jan 2023                               */
/* File     : EXT_INT_int.h                            */
/* Version  : V 0.0                                    */
/*******************************************************/

#ifndef MCAL_EXT_INT_EXT_INT_INT_H_
#define MCAL_EXT_INT_EXT_INT_INT_H_

	#define EXTI_INT0  0
	#define EXTI_INT1  1
	#define EXTI_INT2  2



void EXT_INT_voidInit(uint8 u8IntNumcopy,void(* copy_CB)(void));


#endif /* MCAL_EXT_INT_EXT_INT_INT_H_ */
