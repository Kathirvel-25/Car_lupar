/*
 * ADC_Driver.h
 *
 *  Created on: Jun 7, 2026
 *      Author: kathir
 */

#ifndef ADC_DRIVER_H_
#define ADC_DRIVER_H_
#include "bluepill.h"

void ADC1_GPIO_Init(void);
void ADC1_Init(void);
uint16_t ADC1_Read(uint8_t channel);


#endif /* ADC_DRIVER_H_ */
