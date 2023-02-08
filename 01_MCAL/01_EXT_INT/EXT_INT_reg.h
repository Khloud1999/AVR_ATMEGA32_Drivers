/*******************************************************/
/* Author   : Kholoud Khaled                           */
/* Date     : 9 Jan 2023                               */
/* File     : EXT_INT_reg.h                            */
/* Version  : V 0.0                                    */
/*******************************************************/

#ifndef MCAL_EXT_INT_EXT_INT_REG_H_
#define MCAL_EXT_INT_EXT_INT_REG_H_



/*Steps of Init EXT_INT */
/*
  1-Select pin input or output
  2-Active pullup for INTx
  3-Select sense control for INTX
  4-Enable PIE for INTX
  5-Enable GIE

 */


	//Status register
	#define   SREG_REG    *((volatile uint8*)0x5F)
		#define GI     7
	//General interrupt flag register
	#define   GIFR_REG   *((volatile uint8*)0x5A)
		#define INTF1  7
		#define INTF0  6
		#define INTF2  5
	//MCU Sense control  register for INT2
	#define   MCUCSR_REG  *((volatile uint8*)0x54)
		#define ISC2  6

	//MCU Sense control register INT1 &INT0
	#define   MCUCR_REG   *((volatile uint8*)0x55)
		#define ISC11  3
		#define ISC10  2
		#define ISC01  1
		#define ISC00  0

	//General interrupt control register
    #define   CLCR_REG    *((volatile uint8*)0x5B)
		#define INT1   7
		#define INT0   6
		#define INT2   5
	//DIO
	#define DDRB_REG *((volatile uint8*)0x37)
	#define DDRD_REG *((volatile uint8*)0x31)

#endif /* MCAL_EXT_INT_EXT_INT_REG_H_ */
