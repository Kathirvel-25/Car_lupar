#ifndef STM32F401XX_H
#define STM32F401XX_H

#include <stdint.h>

/* ============================================================
 * BASE ADDRESSES
 * ============================================================ */

#define RCC_BASEADDR        0x40023800U

#define GPIOA_BASEADDR      0x40020000U
#define GPIOB_BASEADDR      0x40020400U
#define GPIOC_BASEADDR      0x40020800U
#define GPIOD_BASEADDR      0x40020C00U
#define GPIOE_BASEADDR      0x40021000U

#define I2C1_BASEADDR       0x40005400U
#define I2C2_BASEADDR       0x40005800U
#define I2C3_BASEADDR       0x40005C00U

#define ADC1_BASEADDR       0x40012000U
#define ADC_C_BASEADDR      0x40012300U

#define SYSCFG_BASEADDR     0x40013800U
#define EXTI_BASEADDR       0x40013C00U

#define NVIC_ISER_BASE      0xE000E100U
#define NVIC_ICER_BASE      0xE000E180U
#define NVIC_ISPR_BASE      0xE000E200U
#define NVIC_ICPR_BASE      0xE000E280U
#define NVIC_IABR_BASE      0xE000E300U
#define NVIC_IPR_BASE       0xE000E400U

/* ============================================================
 * RCC REGISTERS
 * ============================================================ */

typedef struct
{
    volatile uint32_t CR;
    volatile uint32_t PLLCFGR;
    volatile uint32_t CFGR;
    volatile uint32_t CIR;
    volatile uint32_t AHB1RSTR;
    volatile uint32_t AHB2RSTR;
    volatile uint32_t AHB3RSTR;
    volatile uint32_t RESERVED0;
    volatile uint32_t APB1RSTR;
    volatile uint32_t APB2RSTR;
    volatile uint32_t RESERVED1[2];
    volatile uint32_t AHB1ENR;
    volatile uint32_t AHB2ENR;
    volatile uint32_t AHB3ENR;
    volatile uint32_t RESERVED2;
    volatile uint32_t APB1ENR;
    volatile uint32_t APB2ENR;

} RCC_RegDef_t;

/* ============================================================
 * GPIO REGISTERS
 * ============================================================ */

typedef struct
{
    volatile uint32_t MODER;
    volatile uint32_t OTYPER;
    volatile uint32_t OSPEEDR;
    volatile uint32_t PUPDR;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
    volatile uint32_t BSRR;
    volatile uint32_t LCKR;
    volatile uint32_t AFRL;
    volatile uint32_t AFRH;

} GPIO_RegDef_t;

/* ============================================================
 * I2C REGISTERS
 * ============================================================ */

typedef struct
{
    volatile uint32_t CR1;
    volatile uint32_t CR2;
    volatile uint32_t OAR1;
    volatile uint32_t OAR2;
    volatile uint32_t DR;
    volatile uint32_t SR1;
    volatile uint32_t SR2;
    volatile uint32_t CCR;
    volatile uint32_t TRISE;

} I2C_RegDef_t;

/* ============================================================
 * ADC REGISTERS
 * ============================================================ */

typedef struct
{
    volatile uint32_t SR;
    volatile uint32_t CR1;
    volatile uint32_t CR2;
    volatile uint32_t SMPR1;
    volatile uint32_t SMPR2;
    volatile uint32_t JOFR1;
    volatile uint32_t JOFR2;
    volatile uint32_t JOFR3;
    volatile uint32_t JOFR4;
    volatile uint32_t HTR;
    volatile uint32_t LTR;
    volatile uint32_t SQR1;
    volatile uint32_t SQR2;
    volatile uint32_t SQR3;
    volatile uint32_t JSQR;
    volatile uint32_t JDR1;
    volatile uint32_t JDR2;
    volatile uint32_t JDR3;
    volatile uint32_t JDR4;
    volatile uint32_t DR;

} ADC_RegDef_t;

/* ============================================================
 * SYSCFG REGISTERS
 * ============================================================ */

typedef struct
{
    volatile uint32_t MEMRMP;
    volatile uint32_t PMC;
    volatile uint32_t EXTICR[4];
    volatile uint32_t RESERVED[2];
    volatile uint32_t CMPCR;

} SYSCFG_RegDef_t;

/* ============================================================
 * EXTI REGISTERS
 * ============================================================ */

typedef struct
{
    volatile uint32_t IMR;
    volatile uint32_t EMR;
    volatile uint32_t RTSR;
    volatile uint32_t FTSR;
    volatile uint32_t SWIER;
    volatile uint32_t PR;

} EXTI_RegDef_t;

/* ============================================================
 * I2C REGISTERS
 * ============================================================ */

typedef struct{

	volatile uint32_t CSR;
	volatile uint32_t CCR;

}ADC_COMMON_RegDef_t;

/* ============================================================
 * PERIPHERAL DEFINITIONS
 * ============================================================ */

#define RCC      ((RCC_RegDef_t *)RCC_BASEADDR)

#define GPIOA    ((GPIO_RegDef_t *)GPIOA_BASEADDR)
#define GPIOB    ((GPIO_RegDef_t *)GPIOB_BASEADDR)
#define GPIOC    ((GPIO_RegDef_t *)GPIOC_BASEADDR)
#define GPIOD    ((GPIO_RegDef_t *)GPIOD_BASEADDR)
#define GPIOE    ((GPIO_RegDef_t *)GPIOE_BASEADDR)

#define I2C1     ((I2C_RegDef_t *)I2C1_BASEADDR)
#define I2C2     ((I2C_RegDef_t *)I2C2_BASEADDR)
#define I2C3     ((I2C_RegDef_t *)I2C3_BASEADDR)

#define ADC1     ((ADC_RegDef_t *)ADC1_BASEADDR)
#define ADC1_C   ((ADC_COMMON_RegDef_t *)ADC_C_BASEADDR)

#define SYSCFG   ((SYSCFG_RegDef_t *)SYSCFG_BASEADDR)

#define EXTI     ((EXTI_RegDef_t *)EXTI_BASEADDR)

/* ============================================================
 * NVIC
 * ============================================================ */

#define NVIC_ISER   ((volatile uint32_t *)NVIC_ISER_BASE)
#define NVIC_ICER   ((volatile uint32_t *)NVIC_ICER_BASE)
#define NVIC_ISPR   ((volatile uint32_t *)NVIC_ISPR_BASE)
#define NVIC_ICPR   ((volatile uint32_t *)NVIC_ICPR_BASE)
#define NVIC_IABR   ((volatile uint32_t *)NVIC_IABR_BASE)
#define NVIC_IPR    ((volatile uint32_t *)NVIC_IPR_BASE)

/* ============================================================
 * EXTI IRQ NUMBERS
 * ============================================================ */

#define EXTI0_IRQn     6
#define EXTI1_IRQn     7
#define EXTI2_IRQn     8
#define EXTI3_IRQn     9
#define EXTI4_IRQn     10

#endif
