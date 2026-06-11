/*
 * NVIC_Driver.c
 *
 *  Created on: Jun 6, 2026
 *      Author: kathir
 */

#include "NVIC_Driver.h"


void NVIC_EnableIRQ(uint8_t IRQn)
{
    NVIC_ISER[IRQn / 32] = (1 << (IRQn % 32));
}

void NVIC_DisableIRQ(uint8_t IRQn)
{
    NVIC_ICER[IRQn / 32] = (1 << (IRQn % 32));
}

void NVIC_SetPendingIRQ(uint8_t IRQn)
{
    NVIC_ISPR[IRQn / 32] = (1 << (IRQn % 32));
}

void NVIC_ClearPendingIRQ(uint8_t IRQn)
{
    NVIC_ICPR[IRQn / 32] = (1 << (IRQn % 32));
}

bool NVIC_ReadActiveIRQ(uint8_t IRQn)
{
    return ((NVIC_IABR[IRQn / 32] & (1 << (IRQn % 32))) != 0);
}

void NVIC_SetIRQPriority(uint8_t IRQn, uint8_t Priority)
{
    NVIC_IPR[IRQn] = (Priority & 0x0F) << 4;
}
