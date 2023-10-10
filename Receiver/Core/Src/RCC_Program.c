/*
 * RCC_Program.c
 *
 *  Created on: Sep 13, 2023
 *      Author: Ahmed ElSayed
 */


#include "RCC_Interface.h"
#include "RCC_Private.h"

void RCC_Init(RCC_CONFIG* cfgPtr){
	UINT32_t RCC_CR_Setting = 0;
	UINT32_t RCC_CFGR_Setting = 0;
	UINT32_t RCC_CSR_Setting = 0;

	/*Enable clock sources and PLL*/
	RCC_CR_Setting |= (cfgPtr->HIGH_SPEED_EXT_CLK << RCC_CR_HSEON);
	RCC_CR_Setting |= (cfgPtr->HIGH_SPEED_INT_CLK << RCC_CR_HSION);
	RCC_CR_Setting |= (cfgPtr->CLOCK_SECURITY_SYSTEM << RCC_CR_CSSON);
	RCC_CR_Setting |= (cfgPtr->PHASE_LOCK_LOOP << RCC_CR_PLLON);
	RCC_CSR_Setting |= (cfgPtr->LOW_SPEED_INT_CLK << RCC_CSR_LSION);

	/*Configure system clock source*/
	RCC_CFGR_Setting |= (cfgPtr->CLK_SOURCE << RCC_CFGR_SW);
	/*Configure PLL clock source if PLL is enabled*/
	if(ON == cfgPtr->PHASE_LOCK_LOOP){
		RCC_CFGR_Setting |= (cfgPtr->PLL_CLK_SOURCE << RCC_CFGR_PLLSRC);
		/*Configure HSE prescaler for PLL*/
		if(PLL_HSE == cfgPtr->PLL_CLK_SOURCE){
			RCC_CFGR_Setting |= (cfgPtr->PLL_EXT_CLK_PRESCALE << RCC_CFGR_PLLXTPRE);
			/*Configure PLL prescale*/
			if(OFF == cfgPtr->PLL_EXT_CLK_PRESCALE){
				/*To maintain a maximum clock speed of 72 MHz*/
				if(MAX_PLL_MUL_WITH_HSE >= cfgPtr->PLL_MULTIPLIER){
					RCC_CFGR_Setting |= (cfgPtr->PLL_MULTIPLIER << RCC_CFGR_PLLMUL);
				}else{
					RCC_CFGR_Setting |= (MAX_PLL_MUL << RCC_CFGR_PLLMUL);
				}
			}else{
				/*To avoid inserting an invalid value as PLL multiplier*/
				if(MAX_PLL_MUL >= cfgPtr->PLL_MULTIPLIER){
					RCC_CFGR_Setting |= (cfgPtr->PLL_MULTIPLIER << RCC_CFGR_PLLMUL);
				}else{
					RCC_CFGR_Setting |= (MAX_PLL_MUL << RCC_CFGR_PLLMUL);
				}
			}
		}else{
			/*Do nothing*/;
		}
	}else{
		/*Do nothing*/
	}
	/*Configure Microcontroller Clock Output pin*/
	RCC_CFGR_Setting |= (cfgPtr->MCO_PIN_OUT << RCC_CFGR_MCO);

	/*Register loading*/
	RCC_CR = RCC_CR_Setting;
	RCC_CFGR = RCC_CFGR_Setting;
	RCC_CSR = RCC_CSR_Setting;
}
/*
void RCC_ADCClockControl(peripheral_adc peripheral, state mode){
	switch(peripheral){
	case ADC1:
		RCC_APB2ENR |= (mode << RCC_APB2ENR_ADC1EN);
		break;
	case ADC2:
		RCC_APB2ENR |= (mode << RCC_APB2ENR_ADC2EN);
		break;
	case ADC3:
		RCC_APB2ENR |= (mode << RCC_APB2ENR_ADC3EN);
		break;
	default:
		break;
	}
}
*/
void RCC_TimerClockControl(peripheral_timer peripheral, state mode){
	switch(peripheral){
	case TIMER1:
		RCC_APB2ENR |= (mode << RCC_APB2ENR_TIM1EN);
		break;
	case TIMER2:
		RCC_APB1ENR |= (mode << RCC_APB1ENR_TIM2EN);
		break;
	case TIMER3:
		RCC_APB1ENR |= (mode << RCC_APB1ENR_TIM3EN);
		break;
	case TIMER4:
		RCC_APB1ENR |= (mode << RCC_APB1ENR_TIM4EN);
		break;
	case TIMER5:
		RCC_APB1ENR |= (mode << RCC_APB1ENR_TIM5EN);
		break;
	default:
		break;
	}
}

void RCC_IOPORTClockControl(peripheral_ioport peripheral, state mode){
	switch(peripheral){
	case IOPORTA:
		RCC_APB2ENR |= (mode << RCC_APB2ENR_IOPAEN);
		break;
	case IOPORTB:
		RCC_APB2ENR |= (mode << RCC_APB2ENR_IOPBEN);
		break;
	case IOPORTC:
		RCC_APB2ENR |= (mode << RCC_APB2ENR_IOPCEN);
		break;
	default:
		/*Do nothing*/
		break;
	}
}/*

void RCC_SPIClockControl(peripheral_spi peripheral, state mode){
	switch(peripheral){
	case SPI1:
		RCC_APB2ENR |= (mode << RCC_APB2ENR_SPI1EN);
		break;
	case SPI2:
		RCC_APB1ENR |= (mode << RCC_APB1ENR_SPI2EN);
		break;
	case SPI3:
		RCC_APB1ENR |= (mode << RCC_APB1ENR_SPI3EN);
		break;
	default:
		break;
	}
}*/
/*
void RCC_USARTClockControl(peripheral_usart peripheral, state mode){
	switch(peripheral){
	case USART1:
		RCC_APB2ENR |= (mode << RCC_APB2ENR_USART1EN);
		break;
	case USART2:
		RCC_APB1ENR |= (mode << RCC_APB1ENR_USART2EN);
		break;
	case USART3:
		RCC_APB1ENR |= (mode << RCC_APB1ENR_USART3EN);
		break;
	case USART4:
		RCC_APB1ENR |= (mode << RCC_APB1ENR_USART4EN);
		break;
	default:
		break;
	}
}*/
/*
void RCC_I2CClockControl(peripheral_i2c peripheral, state mode){
	switch(peripheral){
	case I2C1:
		RCC_APB1ENR |= (mode << RCC_APB1ENR_I2C1EN);
		break;
	case I2C2:
		RCC_APB1ENR |= (mode << RCC_APB1ENR_I2C2EN);
		break;
	default:
		break;
	}
}
*/
void RCC_AFIOClockControl(state mode){
	RCC_APB2ENR |= (mode << RCC_APB2ENR_AFIOEN);
}

void RCC_CANClockControl(state mode){
	RCC_APB1ENR |= (mode << RCC_APB1ENR_CANEN);
}
