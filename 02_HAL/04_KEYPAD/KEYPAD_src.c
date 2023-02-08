/*******************************************************/
/* Author   : Kholoud Khaled                           */
/* Date     : 29 DEC 2022                              */
/* File     : KEYPAD_src.c                             */
/* Version  : V 0.0                                    */
/*******************************************************/

#include "../../SERV/STD_TYPES.h"
#include "../../MCAL/DIO/Dio_int.h"
#include "util/delay.h"

#include "KEYPAD_cfg.h"
#include "KEYPAD_int.h"


void Keypad_voidInit (void){

	uint8 Local_u8Col ;
	uint8 Local_u8Row ;
	for (Local_u8Col = 0 ; Local_u8Col < KEYPAD_NO_COL ; Local_u8Col++) {
		DIO_u8SetPinDir(KEYPAD_au8ColPins[Local_u8Col].port ,KEYPAD_au8ColPins[Local_u8Col].pin , OUTPUT);
		//INTIAL STATE
		DIO_u8SetPinVal(KEYPAD_au8ColPins[Local_u8Col].port ,KEYPAD_au8ColPins[Local_u8Col].pin , HIGH );
	}
	for (Local_u8Row = 0 ; Local_u8Row <KEYPAD_NO_ROW ; Local_u8Row++ ){
		DIO_u8SetPinDir(KEYPAD_au8RowPins[Local_u8Row].port ,KEYPAD_au8RowPins[Local_u8Row].pin , INPUT );
		//PULLUP
		DIO_u8SetPinVal(KEYPAD_au8RowPins[Local_u8Row].port ,KEYPAD_au8RowPins[Local_u8Row].pin , HIGH );
	}
}

uint8 keypad_u8CheckPress(void){
	uint8 Local_u8KeyPressed  = NOTPRESSED;
	uint8 Local_u8RowStatus ;
	uint8 Local_u8Col ;
	uint8 Local_u8Row ;
     while(Local_u8KeyPressed ==NOTPRESSED){
			for (Local_u8Col = 0 ; Local_u8Col < KEYPAD_NO_COL ; Local_u8Col++)
			{
				//activate column
				DIO_u8SetPinVal(KEYPAD_au8ColPins[Local_u8Col].port ,KEYPAD_au8ColPins[Local_u8Col].pin , LOW );

				for (Local_u8Row = 0 ; Local_u8Row <KEYPAD_NO_ROW ; Local_u8Row++ )
				{
					//check status of current row
					DIO_u8GetPinVal(KEYPAD_au8RowPins[Local_u8Row].port ,KEYPAD_au8RowPins[Local_u8Row].pin , &Local_u8RowStatus );
					if (Local_u8RowStatus == 0 )
					{
						_delay_ms(50);
						DIO_u8GetPinVal(KEYPAD_au8RowPins[Local_u8Row].port ,KEYPAD_au8RowPins[Local_u8Row].pin , &Local_u8RowStatus );
						if (Local_u8RowStatus == 0 )
						{
							Local_u8KeyPressed = KEYPAD_au8KeyVal [Local_u8Row][Local_u8Col];
						}
					}

				}

				//Deactivate COl
				DIO_u8SetPinVal(KEYPAD_au8ColPins[Local_u8Col].port ,KEYPAD_au8ColPins[Local_u8Col].pin , HIGH );
			}
		   }
			return Local_u8KeyPressed ;

}

