/*******************************************************/
/* Author   : Kholoud Khaled                           */
/* Date     : 29 Jan  2023                             */
/* File     : TIMER0_src.h                             */
/* Version  : V 0.0                                    */
/*******************************************************/

#include "../../SERV/STD_TYPES.h"
#include "../../SERV/BIT_MATH.h"

/* Driver include */
#include "TIMER0_int.h"
#include "TIMER0_cfg.h"
#include "TIMER0_private.h"
#include "avr/interrupt.h"

uint8 flag=0;
uint32 TOV_Counter = 0;
void (*Global_CBTOV)(void);
void (*Global_CBCTC)(void);

void TMR0_voidInit(void)
{
/*********************Enable Global Interrupt************/
	SET_BIT(SREG , 7);
/***********************Adjust Mode *********************/
    #if  TMR0_MODE == 0  //Normal (Overflow) Mode
	    CLR_BIT(TCCR0 , WGM00);
	    CLR_BIT(TCCR0 , WGM01);
    #elif TMR0_MODE == 1 // Phase PWM Mode
		SET_BIT(TCCR0,WGM00);
		CLR_BIT(TCCR0,WGM01);
    #elif TMR0_MODE == 2 | TMR0_MODE == 4 // CTC Mode or nonPWM
		CLR_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
    #elif TMR0_MODE == 3 // Fast PWM Mode
		SET_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
    #endif

/*****************Adjust FOC0************************/
	#if  TMR0_FOC0 == 0
		CLR_BIT(TCCR0, FOC0); // Disable FOC0
	#else
		SET_BIT(TCCR0, FOC0); // Enable FOC0
	#endif
/*****************Adjust TOV Interrupt *******************/
	#if  TMR0_TOVINTERRUPT == 0
		CLR_BIT(TIMASK, TOIE0); // Disable TOV Interrupt
	#else
		SET_BIT(TIMASK, TOIE0); // Enable TOV Interrupt
	#endif
/***************** Adjust OCF Interrupt *******************/
	#if  TTMR0_TOCFINTERRUPT == 0
		CLR_BIT(TIMASK, OCIE0); // Disable OCF Interrupt
	#else
		SET_BIT(TIMASK,OCIE0);    // Enable OCF Interrupt
	#endif
}

void TMR0_voidStart(uint8 copy_u8Prescaler)
{
	flag =0;
/*********** Adjust Clock Prescaler******************/
	TCCR0 &= 0xF8; //1111 1000
	TCCR0 |= copy_u8Prescaler;
}

void TMR0_voidSetTCNT0(uint8 copy_u8InitValue)
{
	TCNT0 = copy_u8InitValue;
}

uint32 TMR0_u32Read(void)
{
	uint32 Return_Val;
	Return_Val=((TOV_Counter*256)+TCNT0);
	return Return_Val;
}

//for normal mode
void TMR0_voidSetNormalIntrrupt(void(*copy_CB)(void))
{
	if(copy_CB != 0)
	{
		flag =1;
		Global_CBTOV = copy_CB;
	}

}

//for CTC mode
void TMR0_CTC_voidSetOCR(uint8 copy_u8InitValue,uint8 copy_u8Mode)
{
	if (copy_u8Mode==CTC_TOGGLE_OC0){
		SET_BIT(TCCR0,COM00);
		CLR_BIT(TCCR0,COM01);
	}
	else if (copy_u8Mode==CTC_CLR_OC0){
		CLR_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
	}
	else if (copy_u8Mode==CTC_SET_OC0){
		SET_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
	}

	OCR0=copy_u8InitValue;
}

void TMR0_voidSetCTCIntrrupt(void(*copy_CB)(void))
{

	if(copy_CB != 0)
	{
		flag =1;
		Global_CBCTC = copy_CB;
	}
}

//for all modes
void TMR0_voidStopTMR0(void)
{
	// Make CS bit Zeros
	TCCR0 &= 0xF8;
}

//set TCCR0 =0x00
void TMR0_voidDInit(void)
{
	TCCR0 &= 0x00;
}

//for fast PWM mode
void TMR0_GenerateFastPWM(uint8 copy_u8DutyCycle,uint8 copy_u8pulse){

	/* set OC0 as output pin */
	SET_BIT(DDRB,3);
	/* Set OC0 on compare match, clear OC0 at BOTTOM,(inverting mode)*/
	if ( copy_u8pulse==INVERTED){
		OCR0 = TOP-(TOP* (copy_u8DutyCycle/100))-1;
		SET_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
	}
	/* Set OC0 on compare match, clear OC0 at BOTTOM,(NON inverting mode)*/
	else if ( copy_u8pulse==NON_INVERTED){
		OCR0 = (TOP-copy_u8DutyCycle*TOP)-1;
		SET_BIT(TCCR0,COM01);
	}


}

//for correct PMW mode

void TMR0_GeneratePhaseCorrectPWM(uint8 copy_u8DutyCycle,uint8 copy_u8pulse){
	/* set OC0 as output pin */
	SET_BIT(DDRB,3);
	/* Set OC0 on compare match when up-counting. Clear OC0 on compare match when down counting.*/
	if ( copy_u8pulse==INVERTED){
		OCR0 = ((TOP-1)-(copy_u8DutyCycle*(TOP-1)/100));
		SET_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
	}
	/* Clear OC0 on compare match when up-counting. SET OC0 on compare match when down counting*/
	else if ( copy_u8pulse==NON_INVERTED){
		OCR0 = (copy_u8DutyCycle*(TOP-1))/100;
		SET_BIT(TCCR0,COM01);
	}

}


ISR(TIMER0_OVF_vect)
{
	TOV_Counter++;
	if(flag !=0)
	{
		(*Global_CBTOV)();
	}
}

ISR(TIMER0_COMP_vect)
{
	(*Global_CBCTC)();
	SET_BIT(TIFR,OCF0);
}
