/*
 * FLASH_PROG_Interface.h
 *
 *  Created on: Sep 9, 2023
 *      Author: Ahmed ElSayed
 */

#ifndef FLASH_MEMORY_DRIVER_INC_FLASH_PROG_INTERFACE_H_
#define FLASH_MEMORY_DRIVER_INC_FLASH_PROG_INTERFACE_H_

#include "std_types.h"

typedef enum{
	DATA0,
	DATA1
}USR_DATA_OPTBYTE;

#define FLASH_BASE_ADDR 	0x08000000
#define NASR_FLASH_PAGE_SIZE		1024

void FLASH_Init(void);
void FLASH_ClearOptionBytes(void);
void FLASH_WriteDataOptionByte(USR_DATA_OPTBYTE dataByte, UINT16_t data);
UINT8_t FLASH_ReadDataOptionByte(USR_DATA_OPTBYTE dataByte);
void FLASH_WriteHalfword(UINT32_t address, UINT16_t halfword_data);
void FLASH_WriteWord(UINT32_t address, UINT32_t word_data);
void Nasr_FLASH_PageErase(UINT8_t page_num);
void FLASH_MassErase(void);
void FLASH_Lock(void);
void FLASH_Unlock(void);

#endif /* FLASH_MEMORY_DRIVER_INC_FLASH_PROG_INTERFACE_H_ */
