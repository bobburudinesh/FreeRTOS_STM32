/*
 * msp.c
 *
 *  Created on: Feb 14, 2025
 *      Author: dinesh bobburu
 */


#include "main.h"
#include "FreeRTOS.h"

void HAL_MspInit(void)
{

  __HAL_RCC_SYSCFG_CLK_ENABLE();
  __HAL_RCC_PWR_CLK_ENABLE();
  vInitPrioGroupValue();
}

void HAL_UART_MspInit(UART_HandleTypeDef *huart) {
	__HAL_RCC_USART2_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();
	GPIO_InitTypeDef gpio_uart;
	gpio_uart.Alternate = GPIO_AF7_USART2;
	gpio_uart.Mode = GPIO_MODE_AF_PP;
	gpio_uart.Pull = GPIO_PULLUP;
	gpio_uart.Speed = GPIO_SPEED_FAST;

	gpio_uart.Pin = GPIO_PIN_2 | GPIO_PIN_3;


	HAL_GPIO_Init(GPIOA, &gpio_uart);
	HAL_NVIC_EnableIRQ(USART2_IRQn);
	HAL_NVIC_SetPriority(USART2_IRQn, 15, 0);
}

