/*
 * FLASH_PROG_Private.h
 *
 *  Created on: Sep 9, 2023
 *      Author: Ahmed ElSayed
 */

#ifndef FLASH_MEMORY_DRIVER_INC_FLASH_PROG_PRIVATE_H_
#define FLASH_MEMORY_DRIVER_INC_FLASH_PROG_PRIVATE_H_

#include "std_types.h"



/*to be added to RCC driver*/
#define RCC_CR			*((volatile UINT32_t *)0x40021000)
#define RCC_CR_HSI		0
#define RCC_CR_HSIRDY	1
/***************************/

/*FPEC registers*/
#define FLASH_ACR		*((volatile UINT32_t *)0x40022000)
#define FLASH_KEYR		*((volatile UINT32_t *)0x40022004)
#define FLASH_OPTKEYR	*((volatile UINT32_t *)0x40022008)
#define FLASH_SR		*((volatile UINT32_t *)0x4002200C)
#define FLASH_CR		*((volatile UINT32_t *)0x40022010)
#define FLASH_AR		*((volatile UINT32_t *)0x40022014)
#define FLASH_OBR		*((volatile UINT32_t *)0x4002201C)
#define FLASH_WRPR		*((volatile UINT32_t *)0x40022020)

/*FPEC unlock keys*/
#define FLASH_KEY_1			0x45670123
#define FLASH_KEY_2			0xCDEF89AB
#define FLASH_RDPRT_KEY		0x00A5

/*Access control register pins*/
#define FLASH_ACR_LATENCY0	0
#define FLASH_ACR_LATENCY1	1
#define FLASH_ACR_LATENCY2	2
#define FLASH_ACR_HFCYA		3
#define FLASH_ACR_PRFTBE	4
#define FLASH_ACR_PRFTBS	5

/*Status register pins*/
#define FLASH_SR_BSY		0
#define FLASH_SR_PGERR		2
#define FLASH_SR_WRPRTERR	4
#define FLASH_SR_EOP		5

/*Control register pins*/
#define FLASH_CR_PG		0
#define FLASH_CR_PER	1
#define FLASH_CR_MER	2
#define FLASH_CR_OPTPG	4
#define FLASH_CR_OPTER	5
#define FLASH_CR_STRT	6
#define FLASH_CR_LOCK	7
#define FLASH_CR_OPTWRE	9
#define FLASH_CR_ERRIE	10
#define FLASH_CR_EOPIE	12


#endif /* FLASH_MEMORY_DRIVER_INC_FLASH_PROG_PRIVATE_H_ */
