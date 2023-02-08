/*******************************************************/
/* Author   : Kholoud Khaled                           */
/* Date     : 15 DEC 2022                              */
/* File     : Dio_int.h                                */
/* Version  : V 0.0                                    */
/*******************************************************/

#ifndef DIO_INT_H_
#define DIO_INT_H_

#define PORT_A   0
#define PORT_B   1
#define PORT_C   2
#define PORT_D   3

#define PIN_0    0
#define PIN_1    1
#define PIN_2    2
#define PIN_3    3
#define PIN_4    4
#define PIN_5    5
#define PIN_6    6
#define PIN_7    7

#define INPUT    0
#define OUTPUT   1

#define FULL_INPUT  0X00
#define FULL_OUTPUT 0XFF

#define LOW      0
#define HIGH     1

#define PUE      1

#define E_OK     0
#define E_NOK    1



uint8 DIO_u8SetPortDir (uint8 u8PortIdCopy ,uint8 u8DirCopy);
uint8 DIO_u8SetPortVal (uint8 u8PortIdCopy ,uint8 u8ValCopy);
uint8 DIO_u8GetPortVal (uint8 u8PortIdCopy ,uint8 * u8pValCopy);

uint8 DIO_u8SetPinDir (uint8 u8PortIdCopy ,uint8 u8PinIdCopy,uint8 u8DirCopy );
uint8 DIO_u8SetPinVal (uint8 u8PortIdCopy ,uint8 u8PinIdCopy,uint8 u8ValCopy );
uint8 DIO_u8GetPinVal (uint8 u8PortIdCopy ,uint8 u8PinIdCopy ,uint8 * u8pValCopy);
void  DIO_u8TogglePin(uint8 u8PortIdCopy	,uint8 u8PinIdCopy );


void DIO_voidSetLowNibbleDir (uint8 u8PortIdCopy, uint8 u8DirCopy);
void DIO_voidSetHighNibbleDir (uint8 u8PortIdCopy, uint8 u8DirCopy);
void DIO_voidWriteLowNibble(uint8 u8PortIdCopy ,uint8 u8ValCopy);
void DIO_voidWritHighNibble(uint8 u8PortIdCopy ,uint8 u8ValCopy);




#endif /* DIO_INT_H_ */
