/*
 * E6_Btn_ISR_Task_Notify.c
 *
 *  Created on: Apr 25, 2025
 *      Author: Dinesh Bobburu
 */

#include<main.h>
#include<FreeRTOS.h>
#include<task.h>

void Error_Handler(void);
void Sys_Clock_Config(void);
void GPIO_LED_Config(void);
void GPIO_Button_Config(void);
void button_Interrupt_Handler(void);

static void task_Handler_Led_Green(void* parameters);
static void task_Handler_Led_Red(void* parameters);
static void task_Handler_Led_Orange(void* parameters);
static void task_Handler_Button(void* parameters);



UART_HandleTypeDef huart2;
TaskHandle_t	task_handle_Green;
TaskHandle_t	task_handle_Red;
TaskHandle_t	task_handle_Orange;
TaskHandle_t	task_handle_Button;

TaskHandle_t 	next_task_handle;
BaseType_t	status;

int main(void) {

	HAL_Init();
	Sys_Clock_Config();

	GPIO_LED_Config();
	GPIO_Button_Config();
	status = xTaskCreate(task_Handler_Led_Green, "LED_GREEN", 200, "LED_GREEN - Task 1", 1, &task_handle_Green);
	configASSERT(status == pdPASS);
	status = xTaskCreate(task_Handler_Led_Orange, "LED_ORANGE", 200, "LED_ORANGE - Task 2", 1, &task_handle_Orange);
	configASSERT(status == pdPASS);
	status = xTaskCreate(task_Handler_Led_Red, "LED_RED", 200, "LED_RED - Task 3", 1, &task_handle_Red);
	configASSERT(status == pdPASS);
	status = xTaskCreate(task_Handler_Button, "BUTTON", 200, "BUTTON - Task 4", 2, &task_handle_Button);
	configASSERT(status == pdPASS);

	vTaskStartScheduler();

	while(1);
	return 1;
}

void Sys_Clock_Config(void) {
	RCC_OscInitTypeDef	osc_init = {0};
	RCC_ClkInitTypeDef	clk_Init = {0};

	osc_init.OscillatorType = RCC_OSCILLATORTYPE_HSI;
	osc_init.HSIState = RCC_HSI_ON;
	osc_init.PLL.PLLSource = RCC_PLLSOURCE_HSI;
	osc_init.PLL.PLLState = RCC_PLL_ON;
	osc_init.PLL.PLLM = 16;
	osc_init.PLL.PLLN = 32;
	osc_init.PLL.PLLP = 2;
	osc_init.PLL.PLLQ = 2;

	if(HAL_RCC_OscConfig(&osc_init) != HAL_OK){
		Error_Handler();
	}

	clk_Init.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	clk_Init.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	clk_Init.AHBCLKDivider = RCC_SYSCLK_DIV1;
	clk_Init.APB1CLKDivider = RCC_HCLK_DIV1;
	clk_Init.APB2CLKDivider = RCC_HCLK_DIV1;
	if(HAL_RCC_ClockConfig(&clk_Init, FLASH_LATENCY_0) != HAL_OK){
			Error_Handler();
		}

}


void GPIO_LED_Config(void) {
	__HAL_RCC_GPIOD_CLK_ENABLE();
	GPIO_InitTypeDef	led_gpio;
	led_gpio.Pin = GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15;
	led_gpio.Mode = GPIO_MODE_OUTPUT_PP;
	led_gpio.Pull = GPIO_NOPULL;
	led_gpio.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOD, &led_gpio);
}

void GPIO_Button_Config(void) {
	__HAL_RCC_GPIOA_CLK_ENABLE();
	GPIO_InitTypeDef	btn_gpio;
	btn_gpio.Pin = GPIO_PIN_0;
	btn_gpio.Speed = GPIO_SPEED_FREQ_LOW;
	btn_gpio.Mode = GPIO_MODE_IT_RISING;
	btn_gpio.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOA, &btn_gpio);
	HAL_NVIC_SetPriority(EXTI0_IRQn, 6, 0);
	HAL_NVIC_EnableIRQ(EXTI0_IRQn);

}

void button_Interrupt_Handler(void) {

}

static void task_Handler_Led_Green(void* parameters) {
	while(1) {
		printf("task_Handler_Led_Green - 1");
		HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12);
		vTaskDelay(pdMS_TO_TICKS(1000));
	}
}

static void task_Handler_Led_Orange(void* parameters) {
	while(1) {
		printf("task_Handler_Led_Orange - 2");
		HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_13);
		vTaskDelay(pdMS_TO_TICKS(800));
	}
}

static void task_Handler_Led_Red(void* parameters) {
	while(1) {
		printf("task_Handler_Led_Red - 3");
		HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_14);
		vTaskDelay(pdMS_TO_TICKS(400));
	}
}

static void task_Handler_Button(void* parameters) {
		printf("task_Handler_Button - 4");
		BaseType_t pxHigherPriorityTaskWoken;

		pxHigherPriorityTaskWoken = pdFALSE;
		xTaskNotifyFromISR(next_task_handle, 0, eNoAction, &pxHigherPriorityTaskWoken);


}
void Error_Handler(void) {
	printf("________ERROR___________");
	while(1);
}


