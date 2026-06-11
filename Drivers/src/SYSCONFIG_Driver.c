/*
 * SYSCONFIG_Driver.c
 *
 *  Created on: Jun 7, 2026
 *      Author: kathir
 */


#include "SYSCFG_Driver.h"



void  SYSCFG_EXTI(uint8_t EXTINum,uint8_t PortNum){


	RCC->APB2ENR |= (1<<14);

	uint8_t bitpose;
	uint8_t regIndex;

	regIndex = EXTINum/4;
	bitpose = (EXTINum % 4)*4;


	SYSCFG->EXTICR[regIndex] &= ~(0x0F<<bitpose);
    SYSCFG->EXTICR[regIndex] |= ((PortNum & 0x0F)<<bitpose);


}
