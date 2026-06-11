/*
 * PCA_Driver.h
 *
 *  Created on: Jun 6, 2026
 *      Author: kathir
 */

#ifndef PCA_DRIVER_H_
#define PCA_DRIVER_H_
#include "bluepill.h"
#include "I2C_Driver.h"






void PCA_Write(uint8_t reg,uint8_t data);
void PCA_Init(void);
void PCA_SetPWM(uint8_t channel,uint16_t on,uint16_t off);
void servo_angle(uint8_t channel,uint8_t angel);
void servo_speed(uint8_t channel,uint16_t speed);
void delay_ms(uint32_t ms);


#endif /* PCA_DRIVER_H_ */
