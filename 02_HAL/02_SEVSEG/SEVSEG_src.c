/*******************************************************/
/* Author   : Kholoud Khaled                           */
/* Date     : 18 DEC 2022                              */
/* File     : SEVSEG_src.c                             */
/* Version  : V 0.0                                    */
/*******************************************************/

#include "../../SERV/STD_TYPES.h"
#include "../../SERV/BIT_MATH.h"
/*driver include*/
#include "../../MCAL/DIO/Dio_int.h"
#include"SEVSEG_int.h"

//(cc)for comman cathode & (ca)for comand anode
#define cc

void SEVSEG_voidInit(uint8 u8PortIdCopy)
{
	DIO_u8SetPortDir(u8PortIdCopy,OUTPUT);
}

void SEVSEG_voidDisplayNum(uint8 u8PortIdCopy, uint8 u8ValCopy)
{
	#if defined cc
		uint8 local_u8num[10]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
	#elif defined ca
		//increment the array of comman cathode to be array for comman anode
		uint8 local_u8num[10]={~0x3F, ~0x06, ~0x5B, ~0x4F, ~0x66, ~0x6D, ~0x7D, ~0x07, ~0x7F, ~0x6F};
	#endif
	DIO_u8SetPortVal(u8PortIdCopy ,local_u8num[u8ValCopy]);
}

void SEVSEG_voidBCDInit(uint8 u8PortIdCopy, uint8 u8NibbleCopy)
{
	if(u8NibbleCopy== LOW_NIBBLE)
	{
		DIO_voidSetLowNibbleDir(u8PortIdCopy,0x0f);
	}
	else
	{
		DIO_voidSetHighNibbleDir(u8PortIdCopy,0xf0);
	}
}

void SEVSEG_voidBCDWrite(uint8 u8PortIdCopy, uint8 u8NibbleCopy,uint8 u8DisplayCopy)
{
	if(u8NibbleCopy== LOW_NIBBLE)
	{
		DIO_voidWriteLowNibble( u8PortIdCopy,u8DisplayCopy);
	}
	else
	{
		DIO_voidWritHighNibble( u8PortIdCopy,u8DisplayCopy);
	}
}


