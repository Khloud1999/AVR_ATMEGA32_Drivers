/*******************************************************/
/* Author   : Kholoud Khaled                           */
/* Date     : 19 Jan 2023                              */
/* File     : LM35_src.c                               */
/* Version  : V 0.0                                    */
/*******************************************************/

/* LIB include */
#include "../../SERV/BIT_MATH.h"
#include "../../SERV/STD_TYPES.h"

#include "../../MCAL/ADC/ADC_int.h"

/* Driver include */
#include "LM35_int.h"


void LM35_voidInit (uint8 u8Channelcopy){
	ADC_voidInit(u8Channelcopy);
}

uint16 LM35_u8Read(void){
	uint16 Local_u16Read ;

		//1'c >10mv (input to ADC)
		//2.56V (input of ADC >> 1023 (max output of ADC)
		//(10mv*1023)/2.56 =4 (out when input =10mv)
		//temp in 'c =ADC OUT /4

		Local_u16Read =ADC_u16Read()*0.25;

		return Local_u16Read ;
}
