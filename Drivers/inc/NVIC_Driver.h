/*
 * NVIC_Driver.h
 *
 *  Created on: Jun 6, 2026
 *      Author: kathir
 */

#ifndef NVIC_DRIVER_H_
#define NVIC_DRIVER_H_
#include "bluepill.h"
#include "stdbool.h"


void NVIC_EnableIRQ(uint8_t IRQn);
void NVIC_DisableIRQ(uint8_t IRQn);
void NVIC_SetPendingIRQ(uint8_t IRQn);
void NVIC_ClearPendingIRQ(uint8_t IRQn);
bool NVIC_ReadActiveIRQ(uint8_t IRQn);
void NVIC_SetIRQPriority(uint8_t IRQn, uint8_t Priority);


#endif /* NVIC_DRIVER_H_ */
