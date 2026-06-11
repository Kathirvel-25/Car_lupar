/*
 * EXTI_Driver.h
 *
 *  Created on: Jun 6, 2026
 *      Author: kathir
 */

#ifndef EXTI_DRIVER_H_
#define EXTI_DRIVER_H_
#include "bluepill.h"
#include "SYSCFG_Driver.h"
#include "stdbool.h"


typedef enum
{
	EXTI_TRIGGER_RISING,
	EXTI_TRIGGER_FALLING,
	EXTI_TRIGGER_BOTH

}EXTI_TriggerType;

void EXTI_EnableInterrupt(uint8_t EXTI_LineNum, EXTI_TriggerType TriggerType );
void EXTI_EnableEvent(uint8_t EXTI_LineNum, EXTI_TriggerType TriggerType);
void EXTI_ClearPending(uint8_t EXTI_LineNum);
bool EXTI_isPending(uint8_t EXTI_LineNum);


#endif /* EXTI_DRIVER_H_ */
