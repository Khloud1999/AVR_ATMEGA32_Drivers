/*******************************************************/
/* Author   : Kholoud Khaled                           */
/* Date     : 2 Feb 2023                               */
/* File     : UART_int.h                               */
/* Version  : V 0.0                                    */
/*******************************************************/

#ifndef MCAL_UART_UART_INT_H_
#define MCAL_UART_UART_INT_H_

#include "../../SERV/STD_TYPES.h"
#include "../../SERV/BIT_MATH.h"

//prototype
void USART_voidInit(uint32 copy_uint8BaudRate);

void USART_voidSend(uint8 copy_uint8DataSend);

uint8 USART_u8Recieve(void);

void USART_voidSendNumberu32(uint32 copy_uint32DataSend);

uint32 USART_u32RecieveNumberu32(void);

void UART_vSendstring( uint8 *ptr);

#endif /* MCAL_UART_UART_INT_H_ */
