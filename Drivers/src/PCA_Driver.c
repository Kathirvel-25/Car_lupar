/*
 * PCA_Driver.c
 *
 *  Created on: Jun 6, 2026
 *      Author: kathir
 */


#include "PCA_Driver.h"

#define PCA9685_ADDR  0x40
#define MODE1     0x00
#define PRESCALE  0xFE
#define LED0_ON_L  0X06


void delay_ms(uint32_t ms){
    volatile uint32_t i,j;

    for(i = 0; i < ms; i++)
    {
        for(j = 0; j < 8000; j++)
        {
        }

}
}

void PCA_Write(uint8_t reg,uint8_t data){

	uint8_t buf[2];

    buf[0] = reg;
    buf[1] = data;

    I2C_Transmit(PCA9685_ADDR, buf,2);

}


void PCA_Init(void){

	PCA_Write(MODE1, 0x10); //sleep
	delay_ms(10);

	PCA_Write(PRESCALE,121);  //50hz
	delay_ms(10);

	PCA_Write(MODE1, 0x20); //wake up
	delay_ms(10);

}

void PCA_SetPWM(uint8_t channel,uint16_t on,uint16_t off){

	uint8_t buf[5];

	buf[0] = LED0_ON_L + (4 * channel);
	buf[1] = on & 0xFF;
	buf[2] = on >> 8;
	buf[3] = off & 0xFF;
	buf[4] = off >> 8;

	I2C_Transmit(PCA9685_ADDR,buf,5);


}

void servo_angle(uint8_t channel,uint8_t angel){

	uint16_t pulse;

	pulse = 102 + ((angel * 410)/180);

	PCA_SetPWM(channel,0,pulse);

}

void servo_speed(uint8_t channel,uint16_t speed){

	PCA_SetPWM(channel, 0, speed);

}

