/*
 * I2C_Driver.h
 *
 *  Created on: Jun 6, 2026
 *      Author: kathir
 */

#ifndef I2C_DRIVER_H_
#define I2C_DRIVER_H_
#include "bluepill.h"

void I2C_GPIO_Init(void);
void I2C_Init(void);
void I2C_Transmit(uint8_t addr,uint8_t *data,uint8_t size);

#endif /* I2C_DRIVER_H_ */
