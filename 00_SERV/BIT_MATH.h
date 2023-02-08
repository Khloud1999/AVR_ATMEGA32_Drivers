/*******************************************************/
/* Author   : Kholoud Khaled                           */
/* Date     : 12 DEC 2022                              */
/* File     : BIT_MATH                                 */
/* Version  : V 1.0                                    */
/*******************************************************/


#ifndef  _BIT_MATH_H
#define  _BIT_MATH_H


#define   SET_BIT(reg,bit)   reg |= (1 << bit)
#define   CLR_BIT(reg,bit)   reg &= (~ ( 1 << bit))
#define   TOG_BIT(reg,bit)   reg ^= (1 << bit)
#define   GET_BIT(reg,bit)   ((reg >> bit) & 0x01 ) //(reg&(1<<bit))>>bit

#endif
