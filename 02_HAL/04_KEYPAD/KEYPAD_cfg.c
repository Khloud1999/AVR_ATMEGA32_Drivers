/*******************************************************/
/* Author   : Kholoud Khaled                           */
/* Date     : 29 DEC 2022                              */
/* File     : KEYPAD_cfg.c                             */
/* Version  : V 0.0                                    */
/*******************************************************/

#include "../../SERV/STD_TYPES.h"
#include "../../MCAL/DIO/dio_int.h"


typedef struct {
	uint8 port ;
	uint8 pin ;
}keypad_pin;


#define KEYPAD_NO_COL       4
#define KEYPAD_NO_ROW       4

//[ROW][COLUMN]
 uint8 KEYPAD_au8KeyVal [KEYPAD_NO_ROW][KEYPAD_NO_COL] = {
		{'1','2','3','+'},
		{'4','5','6','-'},
		{'7','8','9','*'},
		{'0', 'A','=','/'}
 };

//config port and pin to each row
 keypad_pin KEYPAD_au8RowPins[KEYPAD_NO_ROW ] =
{
		{ //R0
				PORT_C,
				PIN_0
		},
		{ //R1
				PORT_C	,
				PIN_1
		},
		{ //R2

				PORT_C	,
				PIN_2
		},

		{ //R3

				PORT_C	,
				PIN_3
		}

};

//config  port and pin to each column
 keypad_pin KEYPAD_au8ColPins[KEYPAD_NO_COL] =
{
		{ //C0
				PORT_A ,
				PIN_0
		},
		{ //C1
				PORT_A	,
				PIN_1
		},
		{ //C2

				PORT_A	,
				PIN_2
		},
		{ //C3

				PORT_A	,
				PIN_3
		}

};

