/*
 * GPIO_Program.c
 *
 *  Created on: Sep 18, 2023
 *      Author: Ahmed ElSayed
 */

#include "GPIO_Interface.h"


void GPIO_SetPinOutput(PORTS port, UINT8_t pin){
	switch(port){
	case PORTA:
		GPIOA_CRL->MODE0 = 1;
		GPIOA_CRL->CNF0 = 0;
		break;
	default:
		break;
	}
}
