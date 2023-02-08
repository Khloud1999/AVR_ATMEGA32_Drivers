/*******************************************************/
/* Author   : Kholoud Khaled                           */
/* Date     : 29 DEC 2022                              */
/* File     : KEYPAD_cfg.h                             */
/* Version  : V 0.0                                    */
/*******************************************************/

#ifndef HAL_KEYPAD_KEYPAD_CFG_H_
#define HAL_KEYPAD_KEYPAD_CFG_H_

typedef struct {
	uint8 port ;
	uint8 pin ;
}keypad_pin;



#define KEYPAD_NO_COL       4
#define KEYPAD_NO_ROW       4

extern uint8 KEYPAD_au8KeyVal[KEYPAD_NO_ROW][KEYPAD_NO_COL];
extern keypad_pin KEYPAD_au8RowPins[KEYPAD_NO_ROW ];
extern keypad_pin KEYPAD_au8ColPins[KEYPAD_NO_COL];

#endif /* HAL_KEYPAD_KEYPAD_CFG_H_ */
