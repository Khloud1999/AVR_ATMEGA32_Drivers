/*******************************************************/
/* Author   : Kholoud Khaled                           */
/* Date     : 17 DEC 2022                              */
/* File     : LED_int.h                                */
/* Version  : V 0.0                                    */
/*******************************************************/

#ifndef LED_INT_H_
#define LED_INT_H_

/* options : PORT_A
			 PORT_B
             PORT_C
             PORT_D
*/

/*OPTION  : PIN_0~7 */

void LED_voidINT(uint8 u8PortIdCopy ,uint8 u8PinIdCopy);
void LED_voidTurnOn(uint8 u8PortIdCopy ,uint8 u8PinIdCopy);
void LED_voidTurnOff(uint8 u8PortIdCopy ,uint8 u8PinIdCopy);
void LED_voidToggle(uint8 u8PortIdCopy ,uint8 u8PinIdCopy);


#endif /* LED_INT_H_ */
