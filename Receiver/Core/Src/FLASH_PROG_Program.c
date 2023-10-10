/*
 * FLASH_PROG.c
 *
 *  Created on: Sep 9, 2023
 *      Author: Ahmed ElSayed
 */

#include "FLASH_PROG_Private.h"
#include "FLASH_PROG_Interface.h"

#define CLEAR_CONTROL_REG ~(0x77)

void FLASH_Init(){
	/*Check if the internal clock is active and stable*/
	if(0 == (((RCC_CR >> RCC_CR_HSIRDY) & 1) & ((RCC_CR >> RCC_CR_HSI) & 1))){
		/*Turn on int. osc*/
		RCC_CR |= (1 << RCC_CR_HSI);
		/*Wait for int. osc to be stable*/
		while(!((RCC_CR >> RCC_CR_HSIRDY) & 1));
	} else{
		;
	}
}

void FLASH_ClearOptionBytes(){
	/*Clear all control operations*/
	FLASH_CR &= CLEAR_CONTROL_REG;
	FLASH_SR |= (1 << FLASH_SR_EOP);
	/*Unlock option byte programming*/
	FLASH_OPTKEYR = FLASH_KEY_1;
	FLASH_OPTKEYR = FLASH_KEY_2;
	/*Clear option bytes*/
	FLASH_CR |= (1 << FLASH_CR_OPTER);
	FLASH_CR |= (1 << FLASH_CR_STRT);
	/*Clear all control operations*/
	FLASH_CR &= CLEAR_CONTROL_REG;
	FLASH_SR |= (1 << FLASH_SR_EOP);
	/*Wait for memory to be ready*/
	while (FALSE != ((FLASH_SR >> FLASH_SR_BSY) & 1));

	/*Clear all control operations*/
	FLASH_CR &= CLEAR_CONTROL_REG;
	FLASH_SR |= (1 << FLASH_SR_EOP);

	FLASH_CR |= (1 << FLASH_CR_OPTPG);

	*((volatile UINT16_t *) 0x1FFFF800) = FLASH_RDPRT_KEY;

	/*Wait for memory to be ready*/
	while (FALSE != ((FLASH_SR >> FLASH_SR_BSY) & 1));
	FLASH_CR &= ~(1 << FLASH_CR_OPTPG);
}

void FLASH_WriteDataOptionByte(USR_DATA_OPTBYTE dataByte, UINT16_t data){
	//FLASH_ClearOptionBytes();
	/*Clear all control operations*/
	FLASH_CR &= CLEAR_CONTROL_REG;
	FLASH_SR |= (1 << FLASH_SR_EOP);
	/*Set control register to option byte programming*/
	FLASH_CR |= (1 << FLASH_CR_OPTPG);
	/*Check which data byte to load*/
	switch(dataByte){
	case DATA0:
		/*Load data*/
		*((volatile UINT16_t *) 0x1FFFF804) = data;
		break;
	case DATA1:
		/*Load data*/
		*((volatile UINT16_t *) 0x1FFFF806) = data;
		break;
	default:
		/*handle errors*/
		break;
	}
	/*Wait for memory to be ready*/
	while (FALSE != ((FLASH_SR >> FLASH_SR_BSY) & 1));
	FLASH_CR &= ~(1 << FLASH_CR_OPTPG);
}

UINT8_t FLASH_ReadDataOptionByte(USR_DATA_OPTBYTE dataByte){
	UINT8_t data = 0;
	switch(dataByte){
	case DATA0:
		data = (FLASH_OBR >> 10) & 0xFF;
		break;
	case DATA1:
		data = (FLASH_OBR >> 18) & 0xFF;
		break;
	default:
		break;
	}
	return data;
}

void FLASH_WriteHalfword(UINT32_t address, UINT16_t halfword_data){
	/*Clear all control operations*/
	FLASH_CR &= CLEAR_CONTROL_REG;
	/*Set FPEC to programming mode*/
	FLASH_CR |= (1 << FLASH_CR_PG);
	/*Write data to ROM*/
	*((volatile UINT16_t *) address) = halfword_data;
	/*Wait for memory to be ready*/
	while (FALSE != ((FLASH_SR >> FLASH_SR_BSY) & 1));
	/*Clear programming bit*/
	FLASH_CR &= ~(1 << FLASH_CR_PG);
	/*Clear end of operation bit*/
	if(FALSE != ((FLASH_SR >> FLASH_SR_EOP) & 1)){
		FLASH_SR |= (1 << FLASH_SR_EOP);
	}else{
		/*handle error*/
	}
}


void FLASH_WriteWord(UINT32_t address, UINT32_t word_data){
	/*Write least significant byte to ROM*/
	FLASH_WriteHalfword(address, word_data);
	/*Write most significant byte to ROM*/
	FLASH_WriteHalfword(address + 2, (word_data >> 16));
}

/*CAUTION: It is recommended not to use this function as it will
 * erase the application.*/
void FLASH_MassErase(){
	#warning "DO NOT USE MASS ERASE FUNCTION UNLESS ABSOLUTELY NECESSARY"
	/*erase the whole FLASH memory*/
	FLASH_CR |= (1 << FLASH_CR_MER);
	FLASH_CR |= (1 << FLASH_CR_STRT);
}

void Nasr_FLASH_PageErase(UINT8_t page_num){
	/*calculate that page start address*/
	FLASH_AR = FLASH_BASE_ADDR + (1024 * page_num);
	/*start erase operation*/
	FLASH_CR |= (1 << FLASH_CR_PER);
	FLASH_CR |= (1 << FLASH_CR_STRT);
}

void FLASH_Lock(){
	if(0 == ((FLASH_CR >> FLASH_CR_LOCK) & 1)){
		FLASH_CR |= (1 << FLASH_CR_LOCK);
	} else{
		/*return already locked*/
	}
}

void FLASH_Unlock(){
	if(0 != ((FLASH_CR >> FLASH_CR_LOCK) & 1)){
		/*Unlock the flash control register*/
		FLASH_KEYR = FLASH_KEY_1;
		FLASH_KEYR = FLASH_KEY_2;
	} else{
		/*return flash already unlocked*/
	}
}
