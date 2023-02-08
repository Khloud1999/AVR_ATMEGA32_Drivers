/*******************************************************/
/* Author   : Kholoud Khaled                           */
/* Date     : 2 Feb 2023                               */
/* File     : UART_src.c                               */
/* Version  : V 0.0                                    */
/*******************************************************/



/* LIB include */
#include "../../SERV/STD_TYPES.h"
#include "../../SERV/BIT_MATH.h"
/* Driver Include */
#include "UART_reg.h"
#include "UART_cfg.h"
#include "UART_int.h"

#include "util/delay.h"

#define F_CPU 8000000UL


void USART_voidInit(uint32 copy_uint8BaudRate)
{
	//BaudRate  9600
	uint16 Local_UBRR;
	//adjust mode
	CLR_BIT(USCRC,URSEL);
#if    USART_MODE == 0
	SET_BIT(USCRC,URSEL);
	CLR_BIT(USCRC,UMSEL);
	Local_UBRR = (F_CPU/((uint64)16*copy_uint8BaudRate))-1;
#elif  USART_MODE == 2
	CLR_BIT(USCRC,UMSEL);
	SET_BIT(USCRA,U2X);
	Local_UBRR = (F_CPU/((uint64)8*copy_uint8BaudRate))-1;
#else
	SET_BIT(USCRC,UMSEL);
	Local_UBRR = (F_CPU/((uint64)2*copy_uint8BaudRate))-1;
#endif

	/* Adjust UBRR */
	SET_BIT(USCRC,URSEL);
	UBRRH = (uint8)(Local_UBRR >> 8);
	UBRRL = (uint8)(Local_UBRR);

	/* Adjust Word Size */
#if   USART_WORDSIZE == 0
	CLR_BIT(USCRC,UCSZ0);
	CLR_BIT(USCRC,UCSZ1);
	CLR_BIT(USCRB,UCSZ2);
#elif USART_WORDSIZE == 1
	SET_BIT(USCRC,UCSZ0);
	CLR_BIT(USCRC,UCSZ1);
	CLR_BIT(USCRB,UCSZ2);
#elif USART_WORDSIZE == 2
	CLR_BIT(USCRC,UCSZ0);
	SET_BIT(USCRC,UCSZ1);
	CLR_BIT(USCRB,UCSZ2);
#elif USART_WORDSIZE == 3
	SET_BIT(USCRC,UCSZ0);
	SET_BIT(USCRC,UCSZ1);
	CLR_BIT(USCRB,UCSZ2);
#else
	SET_BIT(USCRC,UCSZ0);
	SET_BIT(USCRC,UCSZ1);
	SET_BIT(USCRB,UCSZ2);
#endif

	/* Adjust Parity */
#if   USART_PARITY  == 0
	CLR_BIT(USCRC,UPM0);
	CLR_BIT(USCRC,UPM1);
#elif USART_PARITY  == 1
	CLR_BIT(USCRC,UPM0);
	SET_BIT(USCRC,UPM1);
#else
	SET_BIT(USCRC,UPM0);
	SET_BIT(USCRC,UPM1);
#endif

	/* Adjust Stop bit */
#if  USART_STOPBIT == 0
	CLR_BIT(USCRC,USBS);
#else
	SET_BIT(USCRC,USBS);
#endif

	/* Enable TX and RX */
	SET_BIT(USCRB,TXEN);
	SET_BIT(USCRB,RXEN);

}

void USART_voidSend(uint8 copy_uint8DataSend)
{
	//Wait for UDR transmit buffer to be empty
	while(GET_BIT(USCRA,UDRE)==0);
	//Put data to UDR transmit buffer transmit
	UDR = copy_uint8DataSend ;
}

uint8 USART_u8Recieve(void)
{
	//Wait for UDR receive buffer to be filled with data
	while(GET_BIT(USCRA,RXC)==0);
	//Receive data from UDR receive buffer
	return UDR;
}

void USART_voidSendNumberu32(uint32 copy_uint32DataSend)
{
	uint8 Data;
	//USART_voidSend ((uint8)num);
	//USART_voidSend ((uint8)(num>>8));
	//USART_voidSend ((uint8)(num>>16));
	uint8 counter;
	for(counter = 0; counter <=3 ; counter ++)
	{
		Data = (uint8)(copy_uint32DataSend >> (8*counter));
		USART_voidSend(Data);
	}
}

uint32 USART_u32RecieveNumberu32(void)
{
	uint32 Data;
	uint8 counter;
	for(counter = 0; counter <=3 ; counter ++)
	{
		Data |=(USART_u8Recieve() << (8* counter));
	}
	return Data;
}


void UART_vSendstring( uint8 *ptr)
{
	while(*ptr!=0)
	{
		USART_voidSend(*ptr);
		ptr++;
		_delay_ms(100);
	}
}

