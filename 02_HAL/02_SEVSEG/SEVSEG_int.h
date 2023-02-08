/*******************************************************/
/* Author   : Kholoud Khaled                           */
/* Date     : 18 DEC 2022                              */
/* File     : SEVSEG_int.h                             */
/* Version  : V 0.0                                    */
/*******************************************************/

#ifndef SEVSEG_INT_H_
#define SEVSEG_INT_H_

#define LOW_NIBBLE  0
#define HIGH_NIBBLE 1
#define POV         2

void SEVSEG_voidInit(uint8 u8PortIdCopy);

void SEVSEG_voidDisplayNum(uint8 u8PortIdCopy, uint8 u8ValCopy);

void SEVSEG_voidBCDInit(uint8 u8PortIdCopy, uint8 u8NibbleCopy);

void SEVSEG_voidBCDWrite(uint8 u8PortIdCopy, uint8 u8NibbleCopy,uint8 u8DisplayCopy);

//void SEVSEG_voidPOVWrite();

#endif /* SEVSEG_INT_H_ */
