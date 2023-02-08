/*******************************************************/
/* Author   : Kholoud Khaled                           */
/* Date     : 2 Feb 2023                               */
/* File     : UART_reg.h                               */
/* Version  : V 0.0                                    */
/*******************************************************/

#ifndef MCAL_UART_UART_REG_H_
#define MCAL_UART_UART_REG_H_


#define  UDR    *((volatile uint8*)0x2C)
#define  USCRA  *((volatile uint8*)0x2B)
	#define RXC    7
	#define TXC    6
	#define UDRE   5
	#define FE     4
	#define DOR    3
	#define PE     2
	#define U2X    1
	#define MPCM   0
#define  USCRB  *((volatile uint8*)0x2A)
	#define RXCIE    7
	#define TXCIE    6
	#define UDRIE    5
	#define RXEN     4
	#define TXEN     3
	#define UCSZ2    2
	#define RXB8     1
	#define TXB8     0
#define  USCRC  *((volatile uint8*)0x40)
	#define URSEL    7
	#define UMSEL    6
	#define UPM1     5
	#define UPM0     4
	#define USBS     3
	#define UCSZ1    2
	#define UCSZ0    1
	#define UCPOL    0
#define  UBRRL  *((volatile uint8*)0x29)
#define  UBRRH  *((volatile uint8*)0x40)



#endif /* MCAL_UART_UART_REG_H_ */
