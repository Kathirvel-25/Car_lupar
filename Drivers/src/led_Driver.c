/*
 * led_Driver.c
 *
 *  Created on: Jun 10, 2026
 *      Author: kathir
 */


#include "led_Driver.h"



void LED_Init(void){

	GPIOA->MODER &= ~((3<<20)|(3<<22)|(3<<24));
	GPIOA->MODER |= ((1<<20)|(1<<22)|(1<<24));
}
void LED_White_On(void){
	GPIOA->ODR |= (1<<11);
}
void LED_WhiteOff(void){
	GPIOA->ODR &= ~(1<<11);
}
void LED_Blue_On(void){
	GPIOA->ODR |= (1<<12);
}
void LED_Blue_Off(void){
	GPIOA->ODR &= ~(1<<12);
}
void LED_Green_On(void){
	GPIOA->ODR |= (1<<10);
}
void LED_Green_Off(void){
	GPIOA->ODR &= ~(1<<10);
}
