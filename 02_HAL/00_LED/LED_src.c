/*******************************************************/
/* Author   : Kholoud Khaled                           */
/* Date     : 17 DEC 2022                              */
/* File     : LED_src.c                                */
/* Version  : V 0.0                                    */
/*******************************************************/

/*LIB include*/
#include "../../SERV/STD_TYPES.h"
#include "../../SERV/BIT_MATH.h"
/*driver include*/
#include "../../MCAL/DIO/Dio_int.h"
#include "LED_int.h"
#include "util/delay.h"

void LED_voidINT(uint8 u8PortIdCopy ,uint8 u8PinIdCopy){
	DIO_u8SetPinDir ( u8PortIdCopy , u8PinIdCopy,OUTPUT);
}

void LED_voidTurnOn(uint8 u8PortIdCopy ,uint8 u8PinIdCopy){
	 DIO_u8SetPinVal (u8PortIdCopy , u8PinIdCopy,HIGH);
}

void LED_voidTurnOff(uint8 u8PortIdCopy ,uint8 u8PinIdCopy){
	 DIO_u8SetPinVal (u8PortIdCopy , u8PinIdCopy,LOW);
}

void LED_voidToggle(uint8 u8PortIdCopy ,uint8 u8PinIdCopy){
	 DIO_u8SetPinVal (u8PortIdCopy , u8PinIdCopy,HIGH);
	 _delay_ms(2000);
	 DIO_u8SetPinVal (u8PortIdCopy , u8PinIdCopy,LOW);
}

