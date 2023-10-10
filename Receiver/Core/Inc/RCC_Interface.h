/*
 * RCC_Interface.h
 *
 *  Created on: Sep 12, 2023
 *      Author: Ahmed ElSayed
 */

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

#include "std_types.h"

typedef enum{
	HSE,
	HSI,
	PLL,
}clk_src;

typedef enum{
	PLL_HSI,
	PLL_HSE
}pll_clk_src;
/*
typedef enum{
	ADC1,
	ADC2,
	ADC3
}peripheral_adc;
*/
typedef enum{
	TIMER1,
	TIMER2,
	TIMER3,
	TIMER4,
	TIMER5
}peripheral_timer;

typedef enum{
	IOPORTA,
	IOPORTB,
	IOPORTC
}peripheral_ioport;
#ifdef ayka
typedef enum{
	SPI1,
	SPI2,
	SPI3
}peripheral_spi;

typedef enum{
	USART1,
	USART2,
	USART3,
	USART4
}peripheral_usart;

typedef enum{
	I2C1,
	I2C2
}peripheral_i2c;
#endif
typedef struct{
	state HIGH_SPEED_EXT_CLK;
	state HIGH_SPEED_INT_CLK;
	state LOW_SPEED_INT_CLK;
	state LOW_SPEED_EXT_CLK;
	state PHASE_LOCK_LOOP;
	state CLOCK_SECURITY_SYSTEM;
	clk_src CLK_SOURCE;
	pll_clk_src PLL_CLK_SOURCE;
	state PLL_EXT_CLK_PRESCALE;
	UINT8_t PLL_MULTIPLIER;
	UINT8_t MCO_PIN_OUT;
}RCC_CONFIG;

void RCC_Init(RCC_CONFIG* cfg);
//void RCC_ADCClockControl(peripheral_adc peripheral, state mode);
void RCC_TimerClockControl(peripheral_timer peripheral, state mode);
void RCC_IOPORTClockControl(peripheral_ioport peripheral, state mode);
//void RCC_SPIClockControl(peripheral_spi peripheral, state mode);
//void RCC_USARTClockControl(peripheral_usart peripheral, state mode);
//void RCC_I2CClockControl(peripheral_i2c peripheral, state mode);
void RCC_AFIOClockControl(state mode);
void RCC_CANClockControl(state mode);

#endif /* RCC_INTERFACE_H_ */
