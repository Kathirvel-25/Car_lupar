/*
 * I2C2_Driver.h
 *
 *  Created on: Jun 10, 2026
 *      Author: kathir
 */

#ifndef I2C2_DRIVER_H_
#define I2C2_DRIVER_H_
#include "bluepill.h"


void I2C2_GPIO_Init(void);
void I2C2_Init(void);
void I2C2_Transmit(uint8_t addr,uint8_t *data,uint8_t size);


#endif /* I2C2_DRIVER_H_ */
