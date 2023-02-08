/*******************************************************/
/* Author   : Kholoud Khaled                           */
/* Date     : 11 Jan  2023                             */
/* File     : ADC_src.c                                */
/* Version  : V 0.0                                    */
/*******************************************************/

#include "../../SERV/BIT_MATH.h"
#include"../../SERV/STD_TYPES.h"

#include "ADC_cfg.h"
#include "ADC_reg.h"
#include "ADC_int.h"

void ADC_voidInit(uint8 copy_u8Channel)
{
	//1- select Channel: max(0:4) in ADmux register
	//make it input: CLR_BIT(DDRA , copy_u8Channel(0:7))
	switch(copy_u8Channel)
	{
		case ADC0:
			ADMUX_REG &=0xE0;
			CLR_BIT(DDRA_REG,0);
			break;
		case ADC1:
			ADMUX_REG |=0x01;
			CLR_BIT(DDRA_REG,1);
			break;
		case ADC2:
			ADMUX_REG |=0x02;
			CLR_BIT(DDRA_REG,2);
			break;
		case ADC3:
			ADMUX_REG |=0x03;
			CLR_BIT(DDRA_REG,3);
			break;
		case ADC4:
			ADMUX_REG |=0x04;
			CLR_BIT(DDRA_REG,4);
			break;
		case ADC5:
			ADMUX_REG |=0x05;
			CLR_BIT(DDRA_REG,5);
			break;
		case ADC6:
			ADMUX_REG |=0x06;
			CLR_BIT(DDRA_REG,6);
			break;
		case ADC7:
			ADMUX_REG |=0x07;
			CLR_BIT(DDRA_REG,7);
			break;
		default:
			break;
	}
	    //2- Select Conversion Speed (prescaler) of ADC
		//from bits(0:2) in ADCSRA register
		#if   ADC_PRESCALER == 0
			  ADCSRA_REG &= 0xF8;
		#elif ADC_PRESCALER == 2
			  ADCSRA_REG &= 0xF8;
			  ADCSRA_REG |= 0x02;
		#elif ADC_PRESCALER == 3
			  ADCSRA_REG &= 0xF8;
			  ADCSRA_REG |= 0x03;
		#elif ADC_PRESCALER == 4
			  ADCSRA_REG &= 0xF8;
			  ADCSRA_REG |= 0x04;
		#elif ADC_PRESCALER == 5
			  ADCSRA_REG &= 0xF8;
			  ADCSRA_REG |= 0x05;
		#elif ADC_PRESCALER == 6
			  ADCSRA_REG &= 0xF8;
			  ADCSRA_REG |= 0x06;
		#elif ADC_PRESCALER == 7
			  ADCSRA_REG &= 0xF8;
			  ADCSRA_REG |= 0x07;
		#endif

		//3- Select Voltage reference for ADC
		// From bits(7,6) in ADMAX register
		#if   ADC_VOLT_REF == 0
			  ADMUX_REG &= 0x3F;
		#elif ADC_VOLT_REF == 1
			  CLR_BIT(ADMUX_REG, REFS1);
			  SET_BIT(ADMUX_REG, REFS0);
		#elif ADC_VOLT_REF == 3
			  SET_BIT(ADMUX_REG, REFS1);
			  SET_BIT(ADMUX_REG, REFS0);
		#endif

		//4- Select Type of Storing of the output
		//from bit 5 (ADLAR) in ADMUX register
		#if ADC_STORE == 0
			CLR_BIT(ADMUX_REG, ADLAR);
		#else
			SET_BIT(ADMUX_REG, ADLAR);
		#endif

		//5- Turn on ADC (bit 7) in ADCSRA register
		SET_BIT(ADCSRA_REG, ADEN);
}

uint16  ADC_u16Read(void){
	uint16 Local_u8val;
	//1- Activate Start of Conversion(bit6 in ADCSRA)
	SET_BIT(ADCSRA_REG, ADSC);
	//2- Wait until conversion Ended
	while(GET_BIT(ADCSRA_REG, ADIF)==0);
	//3- Clear Interrupt Flag after Ended(bit4 in ADCSRA)
	SET_BIT(ADCSRA_REG, ADIF);
	//4- Read ADCL then ADCH in order
	#if ADC_STORE == 0
		Local_u8val = ADCL_REG;
		Local_u8val |= (ADCH_REG << 8);
    #else
		Local_u8val = (ADCH_REG << 2);
	#endif
	return Local_u8val;

}
