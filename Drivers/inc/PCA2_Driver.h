/*
 * PCA2_Driver.h
 *
 *  Created on: Jun 10, 2026
 *      Author: kathir
 */

#ifndef PCA2_DRIVER_H_
#define PCA2_DRIVER_H_
#include "bluepill.h"
#include "I2C2_Driver.h"


void PCA2_Write(uint8_t reg,uint8_t data);
void PCA2_Init(void);
void PCA2_SetPWM(uint8_t channel,uint16_t on,uint16_t off);
void servo2_angle(uint8_t channel,uint8_t angel);
void servo2_speed(uint8_t channel,uint16_t speed);
void delay2_ms(uint32_t ms);



#endif /* PCA2_DRIVER_H_ */
