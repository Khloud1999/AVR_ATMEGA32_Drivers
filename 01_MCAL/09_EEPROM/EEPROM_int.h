/*******************************************************/
/* Author   : Kholoud Khaled                           */
/* Date     : 3 Feb 2023                               */
/* File     : EEPROM_int.h                             */
/* Version  : V 0.0                                    */
/*******************************************************/

#ifndef MCAL_EEPROM_EEPROM_INT_H_
#define MCAL_EEPROM_EEPROM_INT_H_


  void EEPROM_voidWrite(uint16 copy_u16Address ,uint8 copy_u8Data);
  uint8 EEPROM_voidRead(uint16 copy_u16Address );


#endif /* MCAL_EEPROM_EEPROM_INT_H_ */
