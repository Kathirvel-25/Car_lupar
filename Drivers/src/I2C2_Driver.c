/*
 * I2C2_Driver.c
 *
 *  Created on: Jun 10, 2026
 *      Author: kathir
 */


#include "I2C2_Driver.h"



void I2C2_GPIO_Init(void)
{
	RCC->AHB1ENR |= (1<<1);

	GPIOB->MODER &= ~((3<<20)|(3<<6));
	GPIOB->MODER |= ((2<<20)|(2<<6));

	GPIOB->OTYPER |= ((1<<10)|(1<<3));

	GPIOB->PUPDR &= ~((3<<20)|(3<<6));
	GPIOB->PUPDR |= ((1<<20)|(1<<6));


	GPIOB->AFRH &= ~(0x0F<<8);
	GPIOB->AFRH |= (4<<8);

	GPIOB->AFRL &= ~(0x0F<<12);
	GPIOB->AFRL |= (9<<12);

}

void I2C2_Init(void){

	RCC->APB1ENR |= (1<<22);

	I2C2->CR1 |= (1<<15);
	I2C2->CR1 &= ~(1<<15);

	I2C2->CR2 = 42;

	I2C2->CCR = 210;

	I2C2->TRISE = 43;

	I2C2->CR1 |= (1<<0);

}

void I2C2_Transmit(uint8_t addr,uint8_t *data,uint8_t size)
{
	I2C2->CR1 |= (1<<8);

	while(!(I2C2->SR1 & (1<<0)));

	I2C2->DR = (addr<<1)|0;

	while(!(I2C2->SR1 & (1<<1)));

	volatile uint32_t temp;

	temp = I2C2->SR1;
	temp = I2C2->SR2;

	(void)temp;

	while(size){
		while(!(I2C2->SR1 & (1<<7)));

		I2C2->DR = *data++;

		size--;
	}

	while(!(I2C2->SR1 & (1<<2)));

	I2C2->CR1 |= (1<<9);

}
