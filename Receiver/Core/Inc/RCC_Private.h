/*
 * RCC_Private.h
 *
 *  Created on: Sep 12, 2023
 *      Author: Ahmed ElSayed
 */

#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_

#include "std_types.h"

#define RCC_CR			*((volatile UINT32_t *) 0x40021000)
#define RCC_CFGR		*((volatile UINT32_t *) 0x40021004)
#define RCC_CIR			*((volatile UINT32_t *) 0x40021008)
#define RCC_APB2RSTR	*((volatile UINT32_t *) 0x4002100C)
#define RCC_APB1RSTR	*((volatile UINT32_t *) 0x40021010)
#define RCC_AHBENR		*((volatile UINT32_t *) 0x40021014)
#define RCC_APB2ENR		*((volatile UINT32_t *) 0x40021018)
#define RCC_APB1ENR		*((volatile UINT32_t *) 0x4002101C)
#define RCC_BDCR		*((volatile UINT32_t *) 0x40021020)
#define RCC_CSR			*((volatile UINT32_t *) 0x40021024)

/*Control register bits*/
#define RCC_CR_HSION		0
#define RCC_CR_HSIRDY		1
#define RCC_CR_HSITRIM		3
#define RCC_CR_HSEON		16
#define RCC_CR_HSERDY		17
#define RCC_CR_CSSON		19
#define RCC_CR_PLLON		24
#define RCC_CR_PLLRDY		25

/*Configuration register bits*/
#define RCC_CFGR_SW			0
#define RCC_CFGR_SWS		2
#define RCC_CFGR_HPRE		4
#define RCC_CFGR_PPRE		8
#define RCC_CFGR_PPRE2		11
#define RCC_CFGR_ADCPRE		14
#define RCC_CFGR_PLLSRC		16
#define RCC_CFGR_PLLXTPRE	17
#define RCC_CFGR_PLLMUL		18
#define RCC_CFGR_USBPRE		22
#define RCC_CFGR_MCO		24

/*Clock interrupt register bits*/
#define RCC_CIR_LSIRDYF		0
#define RCC_CIR_LSERDYF		1
#define RCC_CIR_HSIRDYF		2
#define RCC_CIR_HSERDYF		3
#define RCC_CIR_PLLRDYF		4
#define RCC_CIR_CSSF		7
#define RCC_CIR_LSIRDYIE	8
#define RCC_CIR_LSERDYIE	9
#define RCC_CIR_HSIRDYIE	10
#define RCC_CIR_HSERDYIE	11
#define RCC_CIR_PLLRDYIE	12
#define RCC_CIR_LSIRDYC		16
#define RCC_CIR_LSERDYC		17
#define RCC_CIR_HSIRDYC		18
#define RCC_CIR_HSERDYC		19
#define RCC_CIR_PLLRDYC		20
#define RCC_CIR_CSSC		23

/*APB2 reset register bits*/
#define RCC_APB2RSTR_AFIORST	0
#define RCC_APB2RSTR_IOPARST	2
#define RCC_APB2RSTR_IOPBRST	3
#define RCC_APB2RSTR_IOPCRST	4
#define RCC_APB2RSTR_ADC1RST	9
#define RCC_APB2RSTR_ADC2RST	10
#define RCC_APB2RSTR_TIM1RST	11
#define RCC_APB2RSTR_SPI1RST	12
#define RCC_APB2RSTR_USART1RST	14
#define RCC_APB2RSTR_ADC3RST	15

/*APB1 reset register bits*/
#define RCC_APB1RSTR_TIM2RST	0
#define RCC_APB1RSTR_TIM3RST	1
#define RCC_APB1RSTR_TIM4RST	2
#define RCC_APB1RSTR_TIM5RST	3
#define RCC_APB1RSTR_WWDGRST	11
#define RCC_APB1RSTR_SPI2RST	14
#define RCC_APB1RSTR_SPI3RST	15
#define RCC_APB1RSTR_USART2RST	17
#define RCC_APB1RSTR_USART3RST	18
#define RCC_APB1RSTR_USART4RST	19
#define RCC_APB1RSTR_I2C1RST	21
#define RCC_APB1RSTR_I2C2RST	22
#define RCC_APB1RSTR_USBRST		23
#define RCC_APB1RSTR_CANRST		25
#define RCC_APB1RSTR_BKPRST		27
#define RCC_APB1RSTR_PWRRST		28

/*AHB enable register bits*/
#define RCC_AHBENR_DMA1EN		0
#define RCC_AHBENR_DMA2EN		1
#define RCC_AHBENR_SRAMEN		2
#define RCC_AHBENR_FLITFEN		4
#define RCC_AHBENR_CRCEN		6

/*APB2 enable register bits*/
#define RCC_APB2ENR_AFIOEN		0
#define RCC_APB2ENR_IOPAEN		2
#define RCC_APB2ENR_IOPBEN		3
#define RCC_APB2ENR_IOPCEN		4
#define RCC_APB2ENR_ADC1EN		9
#define RCC_APB2ENR_ADC2EN		10
#define RCC_APB2ENR_TIM1EN		11
#define RCC_APB2ENR_SPI1EN		12
#define RCC_APB2ENR_USART1EN	14
#define RCC_APB2ENR_ADC3EN		15

/*APB1 enable register bits*/
#define RCC_APB1ENR_TIM2EN		0
#define RCC_APB1ENR_TIM3EN		1
#define RCC_APB1ENR_TIM4EN		2
#define RCC_APB1ENR_TIM5EN		3
#define RCC_APB1ENR_WWDGEN		11
#define RCC_APB1ENR_SPI2EN		14
#define RCC_APB1ENR_SPI3EN		15
#define RCC_APB1ENR_USART2EN	17
#define RCC_APB1ENR_USART3EN	18
#define RCC_APB1ENR_USART4EN	19
#define RCC_APB1ENR_I2C1EN		21
#define RCC_APB1ENR_I2C2EN		22
#define RCC_APB1ENR_USBEN		23
#define RCC_APB1ENR_CANEN		25
#define RCC_APB1ENR_BKPEN		27
#define RCC_APB1ENR_PWREN		28

/*Backup domain control register bits*/
#define RCC_BDCR_LSEON		0
#define RCC_BDCR_LSERDY		1
#define RCC_BDCR_LSEBYP		2
#define RCC_BDCR_RTCSEL		8
#define RCC_BDCR_RTCEN		15
#define RCC_BDCR_BDRST		16

/*Control/Status register bits*/
#define RCC_CSR_LSION		0
#define RCC_CSR_LSIRDY		1

#define MAX_PLL_MUL				16
#define MAX_PLL_MUL_WITH_HSE	9
#endif /* RCC_PRIVATE_H_ */
