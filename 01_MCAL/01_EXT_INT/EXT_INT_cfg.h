/*******************************************************/
/* Author   : Kholoud Khaled                           */
/* Date     : 9 Jan 2023                               */
/* File     : EXT_INT_cfg.h                            */
/* Version  : V 0.0                                    */
/*******************************************************/

#ifndef  EXTINT0_CFG_H
#define  EXTINT0_CFG_H

/*
 available choices for Modes
	EXTINT_LOW_LEVEL
	EXTINT_IOC
	EXTINT_FALLING_EDGE
	EXTINT_RISING_EDGE
*/

/*********************************************************************
 * notes															 *
 * 1) IF INTx is disabled don't care about it's mode				 *
 * 2) for INT2 : it has only two modes (Falling_edge or Rising_edge).*
 *********************************************************************/

#define EXTINT_SENSE_MODE  EXTINT_FALLING_EDGE


#endif
