/*
 * Button_Driver.h
 *
 *  Created on: Jun 6, 2026
 *      Author: kathir
 */

#ifndef BUTTON_DRIVER_H_
#define BUTTON_DRIVER_H_
#include "SYSCFG_Driver.h"
#include "bluepill.h"
#include "EXTI_Driver.h"



void Button_Init(void);
uint8_t Button_ON_OFF_Read(void);
uint8_t Button_Mode_Read(void);
uint8_t Button_Blink_Read(void);


#endif /* BUTTON_DRIVER_H_ */
