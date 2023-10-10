/*
 * IAP_Interface.h
 *
 *  Created on: Sep 11, 2023
 *      Author: Ahmed ElSayed
 */

#ifndef IAP_INTERFACE_H_
#define IAP_INTERFACE_H_

#include "std_types.h"
#include "FLASH_PROG_Interface.h"
#include "RCC_Interface.h"
#include "GPIO_interface.h"

typedef struct{
	UINT32_t PendSV_Handler;
	UINT32_t SysTick_Handler;
	UINT32_t WWDG_IRQHandler;           			/* Window Watchdog interrupt                        */
	UINT32_t PVD_IRQHandler;            			/* PVD through EXTI line detection interrupt        */
	UINT32_t TAMPER_IRQHandler;         			/* Tamper interrupt                                 */
	UINT32_t RTC_IRQHandler;            			/* RTC global interrupt                             */
	UINT32_t FLASH_IRQHandler;          			/* Flash global interrupt                           */
	UINT32_t RCC_IRQHandler;          				/* RCC global interrupt                             */
	UINT32_t EXTI0_IRQHandler;          			/* EXTI Line0 interrupt                             */
	UINT32_t EXTI1_IRQHandler;          			/* EXTI Line1 interrupt                             */
	UINT32_t EXTI2_IRQHandler;          			/* EXTI Line2 interrupt                             */
	UINT32_t EXTI3_IRQHandler;          			/* EXTI Line3 interrupt                             */
	UINT32_t EXTI4_IRQHandler;          			/* EXTI Line4 interrupt                             */
	UINT32_t DMA1_Channel1_IRQHandler;  			/* DMA1 Channel1 global interrupt                   */
	UINT32_t DMA1_Channel2_IRQHandler;  			/* DMA1 Channel2 global interrupt                   */
	UINT32_t DMA1_Channel3_IRQHandler;  			/* DMA1 Channel3 global interrupt                   */
	UINT32_t DMA1_Channel4_IRQHandler;  			/* DMA1 Channel4 global interrupt                   */
	UINT32_t DMA1_Channel5_IRQHandler;  			/* DMA1 Channel5 global interrupt                   */
	UINT32_t DMA1_Channel6_IRQHandler;  			/* DMA1 Channel6 global interrupt                   */
	UINT32_t DMA1_Channel7_IRQHandler;  			/* DMA1 Channel7 global interrupt                   */
	UINT32_t ADC1_2_IRQHandler;         			/* ADC1 and ADC2 global interrupt                   */
	UINT32_t USB_HP_CAN_TX_IRQHandler;  			/* USB High Priority or CAN TX interrupts           */
	UINT32_t USB_LP_CAN_RX0_IRQHandler; 			/* USB Low Priority or CAN RX0 interrupts           */
	UINT32_t CAN_RX1_IRQHandler;        			/* CAN RX1 interrupt                                */
	UINT32_t CAN_SCE_IRQHandler;        			/* CAN SCE interrupt                                */
	UINT32_t EXTI9_5_IRQHandler;        			/* EXTI Line[9:5] interrupts                        */
	UINT32_t TIM1_BRK_IRQHandler;       			/* TIM1 Break interrupt                             */
	UINT32_t TIM1_UP_IRQHandler;        			/* TIM1 Update interrupt                            */
	UINT32_t TIM1_TRG_COM_IRQHandler;   			/* TIM1 Trigger and Commutation interrupts          */
	UINT32_t TIM1_CC_IRQHandler;        			/* TIM1 Capture Compare interrupt                   */
	UINT32_t TIM2_IRQHandler;           			/* TIM2 global interrupt                            */
	UINT32_t TIM3_IRQHandler;           			/* TIM3 global interrupt                            */
	UINT32_t TIM4_IRQHandler;           			/* TIM4 global interrupt                            */
	UINT32_t I2C1_EV_IRQHandler;        			/* I2C1 event interrupt                             */
	UINT32_t I2C1_ER_IRQHandler;        			/* I2C1 error interrupt                             */
	UINT32_t I2C2_EV_IRQHandler;        			/* I2C2 event interrupt                             */
	UINT32_t I2C2_ER_IRQHandler;        			/* I2C2 error interrupt                             */
	UINT32_t SPI1_IRQHandler;           			/* SPI1 global interrupt                            */
	UINT32_t SPI2_IRQHandler;           			/* SPI2 global interrupt                            */
	UINT32_t USART1_IRQHandler;         			/* USART1 global interrupt                          */
	UINT32_t USART2_IRQHandler;         			/* USART2 global interrupt                          */
	UINT32_t USART3_IRQHandler;         			/* USART3 global interrupt                          */
	UINT32_t EXTI15_10_IRQHandler;      			/* EXTI Line[15:10] interrupts                      */
	UINT32_t RTCAlarm_IRQHandler;       			/* RTC Alarms through EXTI line interrupt           */
	UINT32_t ReservedDONOTACCESS;                   /* Reserved                                         */
	UINT32_t TIM8_BRK_IRQHandler;       			/* TIM8 Break interrupt                             */
	UINT32_t TIM8_UP_IRQHandler;        			/* TIM8 Update interrupt                            */
	UINT32_t TIM8_TRG_COM_IRQHandler;   			/* TIM8 Trigger and Commutation interrupts          */
	UINT32_t TIM8_CC_IRQHandler;        			/* TIM8 Capture Compare interrupt                   */
	UINT32_t ADC3_IRQHandler;           			/* ADC3 global interrupt                            */
	UINT32_t FSMC_IRQHandler;           			/* FSMC global interrupt                            */
	UINT32_t SDIO_IRQHandler;           			/* SDIO global interrupt                            */
	UINT32_t TIM5_IRQHandler;           			/* TIM5 global interrupt                            */
	UINT32_t SPI3_IRQHandler;          				/* SPI3 global interrupt                            */
	UINT32_t UART4_IRQHandler;          			/* UART4 global interrupt                           */
	UINT32_t UART5_IRQHandler;          			/* UART5 global interrupt                           */
	UINT32_t TIM6_IRQHandler;          				/* TIM6 global interrupt                            */
	UINT32_t TIM7_IRQHandler;           			/* TIM7 global interrupt                            */
	UINT32_t DMA2_Channel1_IRQHandler;  			/* DMA2 Channel1 global interrupt                   */
	UINT32_t DMA2_Channel2_IRQHandler;  			/* DMA2 Channel2 global interrupt                   */
	UINT32_t DMA2_Channel3_IRQHandler;  			/* DMA2 Channel3 global interrupt                   */
	UINT32_t DMA2_Channel4_5_IRQHandler;			/* DMA2 Channel4 and DMA2 Channel5 global interrupt */
}VECT_TABLE;
/**********************************************************/
/*GPIO registers*/
/*
#define GPIOC_CRL	*((volatile UINT32_t *) 0x40011000)
#define GPIOC_CRH	*((volatile UINT32_t *) 0x40011004)
#define GPIOC_BSRR	*((volatile UINT32_t *) 0x40011010)

#define GPIOB_CRL	*((volatile UINT32_t *) 0x40010C00)
#define GPIOB_CRH	*((volatile UINT32_t *) 0x40010C04)
#define GPIOB_BSRR	*((volatile UINT32_t *) 0x40010C10)
*/
#define AFIO_EXTICR1 *((volatile UINT32_t *) 0x40010008)

#define EXTI_IMR	*((volatile UINT32_t *) 0x40010400)
#define EXTI_FTSR	*((volatile UINT32_t *) 0x4001040C)
#define EXTI_RTSR	*((volatile UINT32_t *) 0x40010408)
#define EXTI_PR		*((volatile UINT32_t *) 0x40010414)

#define NVIC_ISER0 	*((volatile UINT32_t *) 0xE000E100)
#define NVIC_ICPR0	*((volatile UINT32_t *) 0xE000E280)
#define NVIC_IPR1	*((volatile UINT32_t *) 0xE000E404)

#define SCB_AIRCR	*((volatile UINT32_t *) 0xE000ED0C)
/*********************************************************/
#define APP1_START_PAGE		12
#define APP1_END_PAGE		23

#define APP2_START_PAGE		24
#define APP2_END_PAGE		40

#define APP1_DATA_VAL	0xFF00
#define APP2_DATA_VAL	0xFD01

#define APP1_ISR	((VECT_TABLE *) 0x08002038)
#define APP2_ISR	((VECT_TABLE *) 0x08011038)

typedef enum{
	APP1,
	APP2,
	BTLDR = 0xFF
}RUN_MODE;

void IAP_Init(void);
void IAP_RunBootloader(void);
void IAP_WriteUsrProgram(UINT16_t arrSize, UINT32_t *prog_arr);


#endif /* IAP_INTERFACE_H_ */
