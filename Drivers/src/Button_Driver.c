/*
 * Button_Driver.c
 *
 *  Created on: Jun 6, 2026
 *      Author: kathir
 */


#include "Button_Driver.h"



void Button_Init(void){

	RCC->AHB1ENR |= (1 << 0);

	GPIOA->MODER &= ~((3<<4)|(3<<6)|(3<<8));

	GPIOA->PUPDR |= ((1<<4)|(1<<6)|(1<<8));

	SYSCFG_EXTI(2, 0);
	SYSCFG_EXTI(3, 0);
	SYSCFG_EXTI(4, 0);

	   EXTI_EnableInterrupt(2, EXTI_TRIGGER_RISING);
	   EXTI_EnableInterrupt(3, EXTI_TRIGGER_RISING);
	   EXTI_EnableInterrupt(4, EXTI_TRIGGER_RISING);


}
uint8_t Button_ON_OFF_Read(void){

	return !(GPIOA->IDR & (1<<2));


}

uint8_t Button_Mode_Read(void){

	return !(GPIOA->IDR & (1<<3));

}

uint8_t Button_Blink_Read(void){

	return !(GPIOA->IDR & (1<<4));


}
