/*******************************************************/
/* Author   : Kholoud Khaled                           */
/* Date     : 20 DEC 2022                              */
/* File     : LCD_src.c                                */
/* Version  : V 0.0                                    */
/*******************************************************/

#include "stdio.h"
#include "../../SERV/STD_TYPES.h"
#include "../../MCAL/DIO/Dio_int.h"
#include "util/delay.h"
#include "lcd_int.h"
#include "lcd_cfg.h"
#include "lcd_prv.h"

void LCD_voidInit(void){
	_delay_ms(300);
	DIO_u8SetPinDir(LCD_RS_PORT , LCD_RS_PIN , OUTPUT);
	DIO_u8SetPinDir(LCD_RW_PORT , LCD_RW_PIN , OUTPUT);
	DIO_u8SetPinDir(LCD_EN_PORT , LCD_EN_PIN , OUTPUT);
	#if LCD_MODE == 0
		DIO_u8SetPortDir(LCD_PORT , FULL_OUTPUT);
		LCD_voidWriteCmd(LCD_Function_8BIT_2Lines);
		_delay_ms(1);
		LCD_voidWriteCmd(LCD_DISP_ON_CURSOR_ON);
		_delay_ms(1);
		LCD_voidWriteCmd(LCD_CLEAR_SCREEN);
		_delay_ms(10);
		LCD_voidWriteCmd(LCD_ENTRY_MODE);
		_delay_ms(1);
	#elif LCD_MODE == 1
		#if LCD_NIBBLE ==0
			DIO_u8SetPortDir(LCD_PORT , 0x0f);
			LCD_voidWriteCmd(LCD_RETURN_HOME);
			_delay_ms(15);
			LCD_voidWriteCmd(LCD_Function_4BIT_2Lines);
			_delay_ms(1);
			LCD_voidWriteCmd(LCD_DISP_ON_CURSOR_ON);
			_delay_ms(1);
			LCD_voidWriteCmd(LCD_CLEAR_SCREEN);
			_delay_ms(10);
			LCD_voidWriteCmd(LCD_ENTRY_MODE);
			_delay_ms(1);
		#elif LCD_NIBBLE ==1
			DIO_u8SetPortDir(LCD_PORT , 0xf0);
			LCD_voidWriteCmd(LCD_RETURN_HOME);
			_delay_ms(15);
			LCD_voidWriteCmd(LCD_Function_4BIT_2Lines);
			_delay_ms(1);
			LCD_voidWriteCmd(LCD_DISP_ON_CURSOR_ON);
			_delay_ms(1);
			LCD_voidWriteCmd(LCD_CLEAR_SCREEN);
			_delay_ms(10);
			LCD_voidWriteCmd(LCD_ENTRY_MODE);
			_delay_ms(1);
	#endif

#endif
}

void LCD_voidWriteCmd(uint8 u8CommandCopy){
	#if LCD_MODE==0
		DIO_u8SetPortVal(LCD_PORT ,u8CommandCopy) ;
		DIO_u8SetPinVal(LCD_RW_PORT , LCD_RW_PIN , LOW);   //write
		DIO_u8SetPinVal(LCD_RS_PORT , LCD_RS_PIN , LOW);   //CMD
		LCD_voidSendEnPulse();
	#elif LCD_MODE==1
		#if LCD_NIBBLE ==0
		    DIO_voidWriteLowNibble(LCD_PORT ,u8CommandCopy>>4);
			DIO_u8SetPinVal(LCD_RW_PORT , LCD_RW_PIN , LOW);   //write
			DIO_u8SetPinVal(LCD_RS_PORT , LCD_RS_PIN , LOW);   //CMD
			LCD_voidSendEnPulse();
			DIO_voidWriteLowNibble(LCD_PORT ,u8CommandCopy);
			DIO_u8SetPinVal(LCD_RW_PORT , LCD_RW_PIN , LOW);   //write
			DIO_u8SetPinVal(LCD_RS_PORT , LCD_RS_PIN , LOW);   //CMD
			LCD_voidSendEnPulse();
			_delay_ms(2);
		#elif LCD_NIBBLE ==1
			DIO_voidWritHighNibble(LCD_PORT ,u8CommandCopy);
			DIO_u8SetPinVal(LCD_RW_PORT , LCD_RW_PIN , LOW);   //write
			DIO_u8SetPinVal(LCD_RS_PORT , LCD_RS_PIN , LOW);   //CMD
			LCD_voidSendEnPulse();
			DIO_voidWritHighNibble(LCD_PORT ,u8CommandCopy<<4);
			DIO_u8SetPinVal(LCD_RW_PORT , LCD_RW_PIN , LOW);   //write
			DIO_u8SetPinVal(LCD_RS_PORT , LCD_RS_PIN , LOW);   //CMD
			LCD_voidSendEnPulse();
			_delay_ms(2);

		#endif

	#endif
}

void LCD_voidWriteChar(uint8 u8CharacterCopy){
#if LCD_MODE==0
	DIO_u8SetPortVal(LCD_PORT ,u8CharacterCopy) ;
	DIO_u8SetPinVal(LCD_RW_PORT , LCD_RS_PIN , HIGH);   //char
	DIO_u8SetPinVal(LCD_RS_PORT , LCD_RW_PIN , LOW );   //read
	LCD_voidSendEnPulse();
#elif LCD_MODE==1
	#if LCD_NIBBLE ==0
	    DIO_voidWriteLowNibble(LCD_PORT ,u8CharacterCopy>>4);
		DIO_u8SetPinVal(LCD_RW_PORT , LCD_RS_PIN , HIGH);   //char
		DIO_u8SetPinVal(LCD_RS_PORT , LCD_RW_PIN , LOW);   //read
		LCD_voidSendEnPulse();
		DIO_voidWriteLowNibble(LCD_PORT ,u8CharacterCopy);
		DIO_u8SetPinVal(LCD_RW_PORT , LCD_RS_PIN , HIGH);  //char
		DIO_u8SetPinVal(LCD_RS_PORT , LCD_RW_PIN ,LOW);   //read
		LCD_voidSendEnPulse();
		_delay_ms(2);
	#elif LCD_NIBBLE ==1
		DIO_voidWritHighNibble(LCD_PORT ,u8CharacterCopy);
		DIO_u8SetPinVal(LCD_RW_PORT , LCD_RS_PIN , HIGH);   //char
		DIO_u8SetPinVal(LCD_RS_PORT , LCD_RW_PIN ,LOW);   //read
		LCD_voidSendEnPulse();
		DIO_voidWritHighNibble(LCD_PORT ,u8CharacterCopy<<4);
		DIO_u8SetPinVal(LCD_RW_PORT , LCD_RS_PIN , HIGH);  //char
		DIO_u8SetPinVal(LCD_RS_PORT , LCD_RW_PIN , LOW);   //read
		LCD_voidSendEnPulse();
		_delay_ms(2);

	#endif

#endif
}

void LCD_voidClearScreen (void){
	LCD_voidWriteCmd (LCD_CLEAR_SCREEN);
	_delay_ms(10);
}

void LCD_voidShiftLeft (void){
	LCD_voidWriteCmd (LCD_MOVE_CURSOR_LIFT);
	_delay_ms(10);
}

void LCD_voidShiftRight (void){
	LCD_voidWriteCmd (LCD_MOVE_CURSOR_RIGHT);
	_delay_ms(10);
}

void LCD_voidMoveCursor (uint8 u8RowCopy ,uint8 u8ColoumnCopy){
	uint8 copy_u8data;
	//cases un valied
	if(((u8RowCopy<1) ||(u8RowCopy>2)) || (u8ColoumnCopy<1) ||(u8ColoumnCopy>16))
	{
		//cursor in first position >>10000000 //load aderess counter with zero
		copy_u8data = 0x80;
	}
	else if(u8RowCopy ==1)
	{
		//first row in any coloumn
		copy_u8data= 0x80 +(u8ColoumnCopy -1);
	}
	else if(u8RowCopy ==2)
	{
		//first row in any coloumn
		copy_u8data= 0xc0 +(u8ColoumnCopy -1);
	}
	LCD_voidWriteCmd(copy_u8data);
	_delay_ms(1);
}

void LCD_voidWriteString(uint8 *u8stringCopy){

	while((*u8stringCopy)!= '\0'){
		LCD_voidWriteChar(*u8stringCopy);
			u8stringCopy++;
		}
}

void LCD_voidWriteNumber(uint32 u32NumberCopy){
	uint8 str[10];
	//transfer the number into string then display
	sprintf(str ,"%lu" ,u32NumberCopy);
	LCD_voidWriteString(str);
}

void LCD_voidWriteRealNumber(float32  f32NumberCopy){
	    uint8 str [16];
		uint8 *tmpsign=(f32NumberCopy < 0)? "-" :"" ;
		float32 tmpval =(f32NumberCopy < 0)? -f32NumberCopy : f32NumberCopy ;
		sint32 tempint1 = tmpval;
	    float32 tmpfrac = tmpval - tempint1;
	    sint32 tempint2 = tmpfrac*10000;
		sprintf(str ,"%s%d.%04d",tmpsign ,tempint1 ,tempint2);
		LCD_voidWriteString(str);
}

static LCD_voidSendEnPulse(){

	DIO_u8SetPinVal(LCD_EN_PORT , LCD_EN_PIN , HIGH); //ENABLE high
	_delay_ms(2);
	DIO_u8SetPinVal(LCD_EN_PORT , LCD_EN_PIN , LOW); //ENABLE high

}

