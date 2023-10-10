/*
 * GPIO_Interface.h
 *
 *  Created on: Sep 18, 2023
 *      Author: Ahmed ElSayed
 */

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

#include "GPIO_Private.h"

typedef enum{
	PORTA,
	PORTB,
	PORTC
}PORTS;

void GPIO_SetPinOutput(PORTS port, UINT8_t pin);

#endif /* GPIO_INTERFACE_H_ */
