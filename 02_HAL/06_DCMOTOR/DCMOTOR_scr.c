/*******************************************************/
/* Author   : Kholoud Khaled                           */
/* Date     : 31 Dec 2022                              */
/* File     : DCMOTOR_src.c                            */
/* Version  : V 0.0                                    */
/*******************************************************/

/*LIB include*/
#include "../../SERV/STD_TYPES.h"
#include "../../SERV/BIT_MATH.h"
/*driver include*/
#include "../../MCAL/DIO/Dio_int.h"
#include "DCMOTOR_int.h"
#include "DCMOTOR_cfg.h"

void DCMOTOR_voidINT(void){
	DIO_u8SetPinDir ( PORT1 , PIN1 ,OUTPUT);
	DIO_u8SetPinDir ( PORT2 , PIN2 ,OUTPUT);
}

void DCMOTOR_voidStop(void){
	 DIO_u8SetPinVal (PORT1 , PIN1 ,LOW);
	 DIO_u8SetPinVal (PORT2 , PIN2 ,LOW);
}
void DCMOTOR_voidCW(void){
	 DIO_u8SetPinVal (PORT1 , PIN1 ,HIGH);
	 DIO_u8SetPinVal (PORT2 , PIN2 ,LOW);
}
void DCMOTOR_voidCCW(void){
	 DIO_u8SetPinVal (PORT1 , PIN1 ,LOW);
	 DIO_u8SetPinVal (PORT2 , PIN2 ,HIGH);
}

