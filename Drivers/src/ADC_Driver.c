/*
 * ADC_Driver.c
 *
 *  Created on: Jun 7, 2026
 *      Author: kathir
 */


#include "bluepill.h"


void ADC1_GPIO_Init(void){

	RCC->AHB1ENR |= (1<<0);

	GPIOA->MODER &= ~((0b11<<0)|(0b11<<2));

	GPIOA->MODER |= ((0b11<<0)| (0b11<<2));

}
void ADC1_Init(void){

	RCC->APB2ENR |= (1<<8);

	ADC1_C->CCR &= ~(3<<16);
	ADC1_C->CCR |= (0b01<<16);

	ADC1->CR1 &= ~(3<<24);

	ADC1->CR2 &= ~(1<<11);

	ADC1->SMPR2 &= ~(7<<0);
	ADC1->SMPR2 &= ~(7<<3);

	ADC1->SMPR2 |= (7<<0);
	ADC1->SMPR2 |= (7<<3);  //480 clockcycle

	ADC1->CR2 |= (1<<0);

}

uint16_t ADC1_Read(uint8_t channel){

	ADC1->SQR3 = channel;

	ADC1->CR2 |= (1<<30);

	while(!(ADC1->SR & (1<<1)));

	return ADC1->DR;

}
