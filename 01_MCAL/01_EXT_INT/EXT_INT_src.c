/*******************************************************/
/* Author   : Kholoud Khaled                           */
/* Date     : 9 Jan 2023                               */
/* File     : EXT_INT_src.c                            */
/* Version  : V 0.0                                    */
/*******************************************************/


#include "../../SERV/STD_TYPES.h"
#include "../../SERV/BIT_MATH.h"
#include "../../MCAL/DIO/Dio_int.h"
#include "avr/interrupt.h"

#include "../EXT_INT/EXT_INT_int.h"
#include "../EXT_INT/EXT_INT_reg.h"
#include "../EXT_INT/EXT_INT_cfg.h"

void(*Global_CBINTO)(void);
void(*Global_CBINT1)(void);
void(*Global_CBINT2)(void);



void EXT_INT_voidInit(uint8 u8IntNumcopy,void(* copy_CB)(void))
{


	switch(u8IntNumcopy){

		case EXTI_INT0 :
			SET_BIT	(CLCR_REG,INT0);
			SET_BIT	(GIFR_REG,INTF0);
			CLR_BIT(DDRD_REG,2);
			#if   EXTINT_SENSE_MODE ==  EXTINT_LOW_LEVEL
				CLR_BIT(MCUCR_REG , 0);
				CLR_BIT(MCUCR_REG , 1);
			#elif EXTINT_SENSE_MODE ==  EXTINT_IOC
				SET_BIT(MCUC_REG , 0);
				CLR_BIT(MCUCR_REG , 1);
			#elif EXTINT_SENSE_MODE ==  EXTINT_FALLING_EDGE
				CLR_BIT(MCUCR_REG , 0);
				SET_BIT(MCUCR_REG , 1);
			#elif EXTINT_SENSE_MODE ==  EXTINT_RISING_EDGE
				SET_BIT(MCUCR_REG , 0);
				SET_BIT(MCUCR_REG , 1);
			#endif
			 Global_CBINTO =copy_CB;
			break;
		case EXTI_INT1 :
			SET_BIT	(CLCR_REG,INT1);
			SET_BIT	(GIFR_REG,INTF1);
			CLR_BIT(DDRD_REG,3);
			Global_CBINT1 =copy_CB;
			#if EXTI_SENSE_MODE ==  EXTI_LOW_LEVEL
				CLR_BIT(MCUCR_REG , 2);
				CLR_BIT(MCUCR_REG , 3);
			#elif EXTI_SENSE_MODE ==  EXTI_IOC
				SET_BIT(MCUCR_REG , 2);
				CLR_BIT(MCUCR_REG, 3);
			#elif EXTI_SENSE_MODE ==  EXTI_FALLING_EDGE
				CLR_BIT(MCUCR_REG , 2);
				SET_BIT(MCUCR_REG , 3);
			#elif EXTI_SENSE_MODE ==  EXTI_RISING_EDGE
				SET_BIT(MCUCR_REG, 2);
				SET_BIT(MCUCR_REG , 3);
			#endif
			break;
		case EXTI_INT2 :
			SET_BIT	(CLCR_REG,INT2);
			SET_BIT	(GIFR_REG,INTF2);
			CLR_BIT(DDRB_REG,2);
			Global_CBINT2 =*copy_CB;
			#if EXTI_SENSE_MODE ==  EXTI_FALLING_EDGE
				CLR_BIT(MCUCSR_REG , 6);
			#elif EXTI_SENSE_MODE ==  EXTI_RISING_EDGE
				SET_BIT(MCUCSR_REG , 6);
			#endif
			break;
		default :
			break;
	}
	SET_BIT(SREG_REG,GI);
}

 ISR(INT0_vect){
	(*Global_CBINTO)();
}

 ISR(INT1_vect){
	(*Global_CBINT1)();
}


 ISR(INT2_vect){
	(*Global_CBINT2)();
}
