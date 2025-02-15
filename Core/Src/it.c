/*
 * it.c
 *
 *  Created on: Feb 14, 2025
 *      Author: dinesh bobburu
 */

#include "main.h"
#include "stm32f4xx_it.h"

extern TIM_HandleTypeDef htim6;

extern UART_HandleTypeDef huart2;

void TIM6_DAC_IRQHandler(void)
{
  HAL_TIM_IRQHandler(&htim6);
}

void USART2_IRQHandler(void) {
	HAL_UART_IRQHandler(&huart2);
}


