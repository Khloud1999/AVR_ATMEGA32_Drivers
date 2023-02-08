/*******************************************************/
/* Author   : Kholoud Khaled                           */
/* Date     : 3 Feb 2023                               */
/* File     : EEPROM_reg.h                             */
/* Version  : V 0.0                                    */
/*******************************************************/

#ifndef MCAL_EEPROM_EEPROM_REG_H_
#define MCAL_EEPROM_EEPROM_REG_H_

//derefrance EEAR to short OR derafrance EEARH&EEARL to char
//acess two register in one step
//#define   EEAR  *((volatile u16*)0x3E)
#define   EEARH  *((volatile uint8*)0x3F)
#define   EEARL  *((volatile uint8*)0x3E)
#define   EEDR   *((volatile uint8*)0x3D)
#define   EECR   *((volatile uint8*)0x3C)

	#define EERE  0
	#define EEWE  1
	#define EEMWE 2
	#define EERIE 3

#endif /* MCAL_EEPROM_EEPROM_REG_H_ */
