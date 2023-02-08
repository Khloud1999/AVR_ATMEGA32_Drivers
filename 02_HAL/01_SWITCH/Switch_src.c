/*******************************************************/
/* Author   : Kholoud Khaled                           */
/* Date     : 17 DEC 2022                              */
/* File     : Switch_src.c                             */
/* Version  : V 0.0                                    */
/*******************************************************/

#include "../../SERV/STD_TYPES.h"
#include "../../SERV/BIT_MATH.h"
/*driver include*/
#include "../../MCAL/DIO/Dio_int.h"
#include "Switch_int.h"
#include "util/delay.h"

void SWITCH_voidInit(uint8 u8PortIdCopy ,uint8 u8PinIdCopy){
	 DIO_u8SetPinDir ( u8PortIdCopy , u8PinIdCopy,INPUT);
	#if PULLUP_RES==0    // write in port =1 to active internal pullup
	 	 DIO_u8SetPinVal (u8PortIdCopy , u8PinIdCopy,HIGH);
	#endif
}

uint8 SWITCH_u8Read(uint8 u8PortIdCopy ,uint8 u8PinIdCopy){
	uint8 Local_u8ReturnValue;
	_delay_ms(50);  // to protect from  bouncing
	Local_u8ReturnValue=DIO_u8GetPinVal(u8PortIdCopy , u8PinIdCopy,&Local_u8ReturnValue);
	return Local_u8ReturnValue;
}
