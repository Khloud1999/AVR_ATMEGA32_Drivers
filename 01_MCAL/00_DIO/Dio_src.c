/*******************************************************/
/* Author   : Kholoud Khaled                           */
/* Date     : 15 DEC 2022                              */
/* File     : Dio_src.c                                */
/* Version  : V 0.0                                    */
/*******************************************************/

#include "../../SERV/STD_TYPES.h"
#include "../../SERV/BIT_MATH.h"
#include "Dio_reg.h"
#include "Dio_int.h"

uint8 DIO_u8SetPortDir (uint8 u8PortIdCopy ,uint8 u8DirCopy){
	uint8 errStatus =E_OK;
	switch(u8PortIdCopy){
		case PORT_A :DDRA_REG =u8DirCopy ; break;
		case PORT_B :DDRB_REG =u8DirCopy ; break;
		case PORT_C :DDRC_REG =u8DirCopy ; break;
		case PORT_D :DDRD_REG =u8DirCopy ; break;
		default     : errStatus =E_NOK   ; break;  	
	}
	return errStatus;
}
uint8 DIO_u8SetPortVal (uint8 u8PortIdCopy ,uint8 u8ValCopy){
	uint8 errStatus =E_OK;
	switch(u8PortIdCopy){
		case PORT_A :PORTA_REG =u8ValCopy ; break;
		case PORT_B :PORTB_REG =u8ValCopy ; break;
		case PORT_C :PORTC_REG =u8ValCopy ; break;
		case PORT_D :PORTD_REG =u8ValCopy ; break;
		default     : errStatus =E_NOK    ; break;  	
	}
	return errStatus;
}
uint8 DIO_u8GetPortVal (uint8 u8PortIdCopy ,uint8 * u8pValCopy){
	uint8 errStatus =E_OK;
	switch(u8PortIdCopy){
		case PORT_A :* u8pValCopy=PINA_REG  ; break;
		case PORT_B :* u8pValCopy=PINB_REG  ; break;
		case PORT_C :* u8pValCopy=PINC_REG  ; break;
		case PORT_D :* u8pValCopy=PIND_REG  ; break;
		default     : errStatus =E_NOK      ; break;  	
	}
	return errStatus;
}

uint8 DIO_u8SetPinDir (uint8 u8PortIdCopy ,uint8 u8PinIdCopy,uint8 u8DirCopy ){
	uint8 errStatus =E_OK;
	if (u8PinIdCopy>=PIN_0&&u8PinIdCopy<=PIN_7){
		if(u8DirCopy==INPUT){
			switch(u8PortIdCopy){
				case PORT_A :CLR_BIT(DDRA_REG,u8PinIdCopy); break;
				case PORT_B :CLR_BIT(DDRB_REG,u8PinIdCopy); break;
				case PORT_C :CLR_BIT(DDRC_REG,u8PinIdCopy); break;
				case PORT_D :CLR_BIT(DDRD_REG,u8PinIdCopy); break;
				default     :errStatus =E_NOK             ; break;
			}
		}
		else if (u8DirCopy==OUTPUT){
			switch(u8PortIdCopy){
				case PORT_A :SET_BIT(DDRA_REG,u8PinIdCopy); break;
				case PORT_B :SET_BIT(DDRB_REG,u8PinIdCopy); break;
				case PORT_C :SET_BIT(DDRC_REG,u8PinIdCopy); break;
				case PORT_D :SET_BIT(DDRD_REG,u8PinIdCopy); break;
				default     :errStatus =E_NOK             ; break;
			}
		}
		else {
			errStatus =E_NOK;
		}
	}

	return errStatus;
}

uint8 DIO_u8SetPinVal (uint8 u8PortIdCopy ,uint8 u8PinIdCopy,uint8 u8ValCopy ){
	uint8 errStatus =E_OK;
		if (u8PinIdCopy>=PIN_0&&u8PinIdCopy<=PIN_7){
		if(u8ValCopy ==LOW){
			switch(u8PortIdCopy){
				case PORT_A :CLR_BIT(PORTA_REG,u8PinIdCopy); break;
				case PORT_B :CLR_BIT(PORTB_REG,u8PinIdCopy); break;
				case PORT_C :CLR_BIT(PORTC_REG,u8PinIdCopy); break;
				case PORT_D :CLR_BIT(PORTD_REG,u8PinIdCopy); break;
				default     :errStatus =E_NOK              ;  break;
			}
		}
		else if (u8ValCopy ==HIGH){
			switch(u8PortIdCopy){
				case PORT_A :SET_BIT(PORTA_REG,u8PinIdCopy); break;
				case PORT_B :SET_BIT(PORTB_REG,u8PinIdCopy); break;
				case PORT_C :SET_BIT(PORTC_REG,u8PinIdCopy); break;
				case PORT_D :SET_BIT(PORTD_REG,u8PinIdCopy); break;
				default     :errStatus =E_NOK              ; break;
			}
		}
		else {
			errStatus =E_NOK;
		}
	}

	return errStatus;

}
uint8 DIO_u8GetPinVal (uint8 u8PortIdCopy ,uint8 u8PinIdCopy ,uint8 * u8pValCopy){
	uint8 errStatus =E_OK;
	switch(u8PortIdCopy){
		case PORT_A :* u8pValCopy=GET_BIT(PINA_REG,u8PinIdCopy); break;
	    case PORT_B :* u8pValCopy=GET_BIT(PINB_REG,u8PinIdCopy); break;
        case PORT_C :* u8pValCopy=GET_BIT(PINC_REG,u8PinIdCopy); break;
		case PORT_D :* u8pValCopy=GET_BIT(PIND_REG,u8PinIdCopy); break;
		default     :errStatus =E_NOK                          ; break;
	}	
	return errStatus;
}

void  DIO_u8TogglePin(uint8 u8PortIdCopy	,uint8 u8PinIdCopy ){
	switch(u8PortIdCopy){

		case PORT_A:
            TOG_BIT(PORTA_REG,u8PinIdCopy);
			break;

	    case PORT_B:
            TOG_BIT(PORTB_REG,u8PinIdCopy);
			break;

	    case PORT_C:
            TOG_BIT(PORTC_REG,u8PinIdCopy);
			break;

		case PORT_D:
            TOG_BIT(PORTD_REG,u8PinIdCopy);
			break;
 }
}

void DIO_voidSetLowNibbleDir (uint8 u8PortIdCopy, uint8 u8DirCopy){
	for (uint8 i=0;i<=3 ;i++){
		DIO_u8SetPinDir ( u8PortIdCopy , i ,u8DirCopy );
		}
}
void DIO_voidSetHighNibbleDir (uint8 u8PortIdCopy, uint8 u8DirCopy){
	for (uint8 i=4;i<=7 ;i++){
			DIO_u8SetPinDir ( u8PortIdCopy , i ,u8DirCopy );
			}
}
void DIO_voidWriteLowNibble(uint8 u8PortIdCopy ,uint8 u8ValCopy){
	u8ValCopy&=0x0f; ////to save four low bites make most =0
	switch (u8PortIdCopy)
	{
		case PORT_A :
			PORTA_REG &=0xf0;
			PORTA_REG|=u8ValCopy;
			break;
		case PORT_B :
			PORTB_REG &=0xf0;
			PORTB_REG |=u8ValCopy;
			break;
		case PORT_C:
			PORTC_REG &=0xf0;
			PORTC_REG |=u8ValCopy;
			break;
		case PORT_D :
			PORTD_REG &=0xf0;
			PORTD_REG |=u8ValCopy;
			break;
		default :
		   break;
	}
}
void DIO_voidWritHighNibble(uint8 u8PortIdCopy ,uint8 u8ValCopy){
	u8ValCopy&=0xf0; ////to save four most bites make low =0
	switch (u8PortIdCopy)
	{
		case PORT_A :
			PORTA_REG &=0x0f;
			PORTA_REG|=u8ValCopy;
			break;
		case PORT_B :
			PORTB_REG &=0x0f;
			PORTB_REG |=u8ValCopy;
			break;
		case PORT_C:
			PORTC_REG &=0x0f;
			PORTC_REG |=u8ValCopy;
			break;
		case PORT_D :
			PORTD_REG &=0x0f;
			PORTD_REG |=u8ValCopy;
			break;
		default :
		   break;
	}
}




