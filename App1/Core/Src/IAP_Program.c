/*
 * IAP_Program.c
 *
 *  Created on: Sep 11, 2023
 *      Author: Ahmed ElSayed
 */
#include "main.h"
#include "IAP_Interface.h"

void Shift_VECT_TAB_ADDRESS(void)
{
	SCB->VTOR = 0x3000;
/*
	RUN_MODE active_app = BTLDR;

	active_app = FLASH_ReadDataOptionByte(DATA0);

	if(APP1 == active_app){
		SCB->VTOR = 0x3000;
	}else if(APP2 == active_app){
		SCB->VTOR = 0x11000;
	}*/
}
