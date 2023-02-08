/*******************************************************/
/* Author   : Kholoud Khaled                           */
/* Date     : 31 Dec 2022                              */
/* File     : RELAY_src.c                              */
/* Version  : V 0.0                                    */
/*******************************************************/

/*LIB include*/
#include "../../SERV/STD_TYPES.h"
/*driver include*/
#include"../../MCAL/DIO/Dio_int.h"
#include"RELAY_int.h"

void RELAY_voidTurnOn(uint8 u8PortIdCopy ,uint8 u8PinIdCopy){

	DIO_u8SetPinDir(u8PortIdCopy , u8PinIdCopy ,OUTPUT);
	DIO_u8SetPinVal(u8PortIdCopy , u8PinIdCopy ,HIGH);

	}
void RELAY_voidTurnOff(uint8 u8PortIdCopy ,uint8 u8PinIdCopy){

	DIO_u8SetPinDir(u8PortIdCopy , u8PinIdCopy ,OUTPUT);
	DIO_u8SetPinVal(u8PortIdCopy , u8PinIdCopy ,LOW);
}
