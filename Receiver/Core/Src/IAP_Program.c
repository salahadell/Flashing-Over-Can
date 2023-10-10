/*
 * IAP_Program.c
 *
 *  Created on: Sep 11, 2023
 *      Author: Ahmed ElSayed
 */
#include "main.h"
#include "IAP_Interface.h"
bool EOF_Flag = FALSE;
bool RDY_Flag = FALSE;
UINT16_t buffer_index = 0;
UINT16_t Index = 0;

extern UINT8_t APP2sh[1096];
extern UINT8_t newindex;
extern UINT8_t RxData[8];
extern UINT8_t ResetFlag;

extern void HAL_NVIC_SystemReset(void);

/****************************************************************************/
/*	1 -> High speed external clock control
	2 -> High speed internal clock control
	3 -> Low speed internal clock control
	4 -> High speed external clock control
	5 -> Phase Lock Loop (PLL) control
	6 -> Clock Security System (CSS) control
	7 -> System clock source
	8 -> PLL clock source
	9 -> PLL external clock prescaler
	10 -> PLL multiplier
	11 -> Microcontroller Output Pin (MCO) control
 */

void Nasr_SystemInit(){
	/**********************1   2   3    4    5    6    7      8      9  10 11*****/
	RCC_CONFIG usr_cfg = {ON, ON, OFF, OFF,	OFF, OFF, HSE, PLL_HSI, OFF, 1, 0};
	/*Initialize system clock*/
	RCC_Init(&usr_cfg);

	/*enable port b clock*/
	RCC_IOPORTClockControl(IOPORTB, ON);
	RCC_IOPORTClockControl(IOPORTC, ON);
	RCC_CANClockControl(ON);
	RCC_AFIOClockControl(ON);
	/*set port c to output with open drain*/
	GPIOB_CRL = 0x44144444;
	GPIOC_CRH = 0x14144444;
}

void IAP_Init(){
	/*enable port c clock*/

	/*set port c to output with open drain*/
	//GPIOC_CRH = 0x14144444;
	/*set pin C13 to high*/
	GPIOC_BSRR |= (1 << 13);
}

void IAP_WriteUsrProgram(UINT16_t arrSize, UINT32_t *prog_arr){
	RUN_MODE loaded_usr_app = BTLDR;
	UINT32_t write_addr = 0;
	UINT16_t index = 0;

	loaded_usr_app = FLASH_ReadDataOptionByte(DATA1);

	/*Disable interrupts*/
	asm("CPSID i");
	/*Initialize and unlock the flash memory*/
	FLASH_Init();
	FLASH_Unlock();
	/***************Memory preparation section***************/

	if((BTLDR == loaded_usr_app) || (APP2 == loaded_usr_app)){
		/*Prepare application 1 memory location for writing*/
		for(index = APP1_START_PAGE; index <= APP1_END_PAGE; ++index){
			Nasr_FLASH_PageErase(index);
		}
		/*Calculate first address in start page*/
		write_addr = FLASH_BASE_ADDR + (NASR_FLASH_PAGE_SIZE * APP1_START_PAGE);
	}else if(APP1 == loaded_usr_app){
		/*Prepare application 2 memory location for writing*/
		for(index = APP2_START_PAGE; index <= APP2_END_PAGE; ++index){
			Nasr_FLASH_PageErase(index);

		}
		/*Calculate first address in start page*/
		write_addr = FLASH_BASE_ADDR + (NASR_FLASH_PAGE_SIZE * APP2_START_PAGE);
	}else{
		/*Handle errors*/
	}
	/*Enable interrupts*/
	asm("CPSIE i");
	/***************Application FLASHING section***************/
	/*Loop till end of application*/
	while(FALSE == EOF_Flag){
		/*Wait for CAN to transfer a program block*/
		while(FALSE == RDY_Flag);

		if(1 == ResetFlag)
		{
			HAL_NVIC_SystemReset();
		}

		if(TRUE == EOF_Flag)
		{
			asm("CPSIE i");
			break;
		}
		else
		{
			/*Do Nothing*/
		}
		/*Disable interrupts*/
		asm("CPSID i");
		/*Write program block into FLASH*/
		for(index = 0; index < arrSize; ++index){
			FLASH_WriteWord(write_addr , prog_arr[index]);
			write_addr += 4;
		}
		/*Reset ready flag*/
		RDY_Flag = FALSE;
		/*Enable interrupts*/
		asm("CPSIE i");
	}
	/***************Option byte setting section***************/
	/*Disable interrupts*/
	asm("CPSID i");
	FLASH_ClearOptionBytes();
	if((BTLDR == loaded_usr_app) || (APP2 == loaded_usr_app)){
		/*To load the application after reset*/
		FLASH_WriteDataOptionByte(DATA0, APP1_DATA_VAL);
		/*To switch between both applications*/
		FLASH_WriteDataOptionByte(DATA1, APP1_DATA_VAL);
	}else if(APP1 == loaded_usr_app){
		/*To load the application after reset*/
		FLASH_WriteDataOptionByte(DATA0, APP2_DATA_VAL);
		/*To switch between both applications*/
		FLASH_WriteDataOptionByte(DATA1, APP2_DATA_VAL);
	}else{
		/*Handle errors*/
	}
	/*Enable interrupts*/
	asm("CPSIE i");
	/*To prevent unintended modifications*/
	FLASH_Lock();
	/*Software reset*/
	HAL_NVIC_SystemReset();
}

void IAP_RunBootloader(){
	RUN_MODE loaded_usr_app = BTLDR;
	loaded_usr_app = FLASH_ReadDataOptionByte(DATA1);

	IAP_WriteUsrProgram(2, RxData);


}
/***************************Interrupt Handlers***************************/

void Shift_VECT_TAB_ADDRESS(void)
{
		RUN_MODE active_app = BTLDR;

	   active_app = FLASH_ReadDataOptionByte(DATA0);

	  	if(APP1 == active_app){
	  		SCB->VTOR = 0x3000;
	  	}else if(APP2 == active_app){
	  		SCB->VTOR = 0x6000;
	  	}
}

