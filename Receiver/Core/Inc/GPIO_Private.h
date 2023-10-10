/*
 * GPIO_Private.h
 *
 *  Created on: Sep 18, 2023
 *      Author: Ahmed ElSayed
 */

#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_
#include "std_types.h"

/*PortA registers*/
//#define GPIOA_CRL	*((volatile UINT32_t *) 0x40010800)
#define GPIOA_CRH	*((volatile UINT32_t *) 0x40010804)
#define GPIOA_IDR	*((volatile UINT16_t *) 0x40010808)
#define GPIOA_ODR	*((volatile UINT16_t *) 0x4001080C)
#define GPIOA_BSRR	*((volatile UINT32_t *) 0x40010810)
#define GPIOA_BRR	*((volatile UINT16_t *) 0x40010814)

/*PortB registers*/
#define GPIOB_CRL	*((volatile UINT32_t *) 0x40010C00)
#define GPIOB_CRH	*((volatile UINT32_t *) 0x40010C04)
#define GPIOB_IDR	*((volatile UINT16_t *) 0x40010C08)
#define GPIOB_ODR	*((volatile UINT16_t *) 0x40010C0C)
#define GPIOB_BSRR	*((volatile UINT32_t *) 0x40010C10)
#define GPIOB_BRR	*((volatile UINT16_t *) 0x40010C14)

/*PortC registers*/
#define GPIOC_CRL	*((volatile UINT32_t *) 0x40011000)
#define GPIOC_CRH	*((volatile UINT32_t *) 0x40011004)
#define GPIOC_IDR	*((volatile UINT16_t *) 0x40011008)
#define GPIOC_ODR	*((volatile UINT16_t *) 0x4001100C)
#define GPIOC_BSRR	*((volatile UINT32_t *) 0x40011010)
#define GPIOC_BRR	*((volatile UINT16_t *) 0x40011014)


typedef struct{
	UINT8_t MODE0 : 2;
	UINT8_t CNF0 : 2;
	UINT8_t MODE1 : 2;
	UINT8_t CNF1 : 2;
	UINT8_t MODE2 : 2;
	UINT8_t CNF2 : 2;
	UINT8_t MODE3 : 2;
	UINT8_t CNF3 : 2;
	UINT8_t MODE4 : 2;
	UINT8_t CNF4 : 2;
	UINT8_t MODE5 : 2;
	UINT8_t CNF5 : 2;
	UINT8_t MODE6 : 2;
	UINT8_t CNF6 : 2;
	UINT8_t MODE7 : 2;
	UINT8_t CNF7 : 2;
}config_reg_bits;

#define GPIOA_CRL	((config_reg_bits *) 0x40010800)


#endif /* GPIO_PRIVATE_H_ */
