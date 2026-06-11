/*
 * I2C_Driver.c
 *
 *  Created on: Jun 6, 2026
 *      Author: kathir
 */

#include "ADC_Driver.h"

void I2C_GPIO_Init(void)
{
	RCC->AHB1ENR |= (1<<1);

	GPIOB->MODER &= ~((0b11<<12) | (0b11<<14));
	GPIOB->MODER |= ((0b10<<12) | (0b10<<14));

	GPIOB->OTYPER |= ((1<<6)|(1<<7));

	GPIOB->PUPDR &= ~((0b11<<12) | (0b11<<14));
	GPIOB->PUPDR |=  ((0b01<<12) | (0b01<<14));

	GPIOB->AFRL &= ~((0x0F<<24)|(0x0F<<28));
	GPIOB->AFRL |= ((4<<24)|(4<<28));


}
void I2C_Init(void)
{

	RCC->APB1ENR |= (1<<21);

    I2C1->CR1 |= (1 << 15);
    I2C1->CR1 &= ~(1 << 15);

	I2C1->CR2 = 42;

	I2C1->CCR = 210;

	I2C1->TRISE = 43;

	I2C1->CR1 |= (1<<0);


}

void I2C_Transmit(uint8_t addr,uint8_t *data,uint8_t size)
{

	I2C1->CR1 |= (1<<8);

	while(!(I2C1->SR1 & (1<<0)));

	I2C1->DR = (addr<<1)|0;

	while (!(I2C1->SR1 & (1<<1)));

	volatile uint32_t temp;
	temp = I2C1->SR1;
	temp = I2C1->SR2;
	(void)temp;

	while(size){

		while(!(I2C1->SR1 & (1<<7)));

		I2C1->DR = *data++;

		size--;
	}

	while(!(I2C1->SR1 & (1<<2)));

	I2C1->CR1 |= (1<<9);

}
