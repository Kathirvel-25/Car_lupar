/*
 * EXTI_Driver.c
 *
 *  Created on: Jun 6, 2026
 *      Author: kathir
 */


#include "EXTI_Driver.h"



void EXTI_EnableInterrupt(uint8_t EXTI_LineNum, EXTI_TriggerType TriggerType ){

	EXTI->IMR |= (1<<EXTI_LineNum);

		switch(TriggerType){

		case EXTI_TRIGGER_RISING:
			EXTI->RTSR |= ( 1<< EXTI_LineNum);
			EXTI->FTSR &= ~(1 << EXTI_LineNum);
			break;

		case EXTI_TRIGGER_FALLING:
			EXTI->FTSR |= (1<<EXTI_LineNum);
			EXTI->RTSR &= ~(1<<EXTI_LineNum);
			break;

		case EXTI_TRIGGER_BOTH:
			EXTI->RTSR |= (1<<EXTI_LineNum);
			EXTI->FTSR |= (1<<EXTI_LineNum);
			break;

		default:
			break;
		}

}

void EXTI_EnableEvent(uint8_t EXTI_LineNum, EXTI_TriggerType TriggerType){


	EXTI->EMR |= (1<<EXTI_LineNum);

	switch(TriggerType){

	case EXTI_TRIGGER_RISING:
		EXTI->RTSR |= ( 1<< EXTI_LineNum);
		EXTI->FTSR &= ~(1 << EXTI_LineNum);
		break;

	case EXTI_TRIGGER_FALLING:
		EXTI->FTSR |= (1<<EXTI_LineNum);
		EXTI->RTSR &= ~(1<<EXTI_LineNum);
		break;

	case EXTI_TRIGGER_BOTH:
		EXTI->RTSR |= (1<<EXTI_LineNum);
		EXTI->FTSR |= (1<<EXTI_LineNum);
		break;

	default:
		break;
	}

}

void EXTI_ClearPending(uint8_t EXTI_LineNum){

	EXTI->PR |= (1<<EXTI_LineNum);

}

bool EXTI_isPending(uint8_t EXTI_LineNum){

	return (EXTI->PR & (1<<EXTI_LineNum)) ? 1:0;

}
