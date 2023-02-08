/*******************************************************/
/* Author   : Kholoud Khaled                           */
/* Date     : 3 Feb 2023                               */
/* File     : EEPROM_src.c                             */
/* Version  : V 0.0                                    */
/*******************************************************/

/*LIB include*/
#include "../../SERV/STD_TYPES.h"
#include "../../SERV/BIT_MATH.h"

/*driver include*/

#include"EEPROM_int.h"
#include"EEPROM_reg.h"

void EEPROM_voidWrite(uint16 copy_u16Address ,uint8 copy_u8Data)
{
 	// address ,data,set master write enable ,set write enable

	EEARL = (uint8)copy_u16Address;
	EEARH = (uint8)(copy_u16Address >> 8);
	EEDR  = copy_u8Data;
	SET_BIT(EECR ,EEMWE);
	SET_BIT(EECR ,EEWE);
	while(GET_BIT(EECR ,EEWE)==1);

}

uint8 EEPROM_voidRead(uint16 copy_u16Address )
{
	// address , set read enable ,return data from EEDR

	EEARL = (uint8)copy_u16Address;
	EEARH = (uint8)(copy_u16Address >> 8);
	SET_BIT(EECR ,EERE);
	return EEDR;
}
