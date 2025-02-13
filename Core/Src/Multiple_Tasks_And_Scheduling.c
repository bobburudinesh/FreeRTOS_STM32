/*
 * Multiple_Tasks_And_Scheduling.c
 *
 *  Created on: Feb 13, 2025
 *      Author: dinesh bobburu
 */

/*
 * Exercise: Create 3 Different tasks to toggle led's after certain delays.
 * */

#include "main.h"
#include "FreeRTOS.h"
#include "task.h"

#define DWT_CTRL	(*(volatile uint32_t*)0xE0001000)

extern  void SEGGER_UART_init(uint32_t);


void SystemClock_Config(void);
void Error_handler(void);
void task1_Handler(void * parameters);
void task2_Handler(void * parameters);
void task3_Handler(void * parameters);
void GPIO_init(void);

int main(void) {
	TaskHandle_t task_1_handle;
	TaskHandle_t task_2_handle;
	TaskHandle_t task_3_handle;
	BaseType_t	task_1_Status;
	BaseType_t  task_2_Status;
	BaseType_t  task_3_Status;
	HAL_Init();
	SystemClock_Config();
	GPIO_init();
	SEGGER_UART_init(500000);
	DWT_CTRL |= (1<<0);
	SEGGER_SYSVIEW_Conf();
	task_1_Status = xTaskCreate(task1_Handler, "Task_1_Green_LED", 200, NULL, 2, &task_1_handle);
	configASSERT(task_1_Status == pdPASS);

	task_2_Status = xTaskCreate(task2_Handler, "Task_2_Orange_LED", 200, NULL, 2, &task_2_handle);
	configASSERT(task_2_Status == pdPASS);

	task_3_Status = xTaskCreate(task3_Handler, "Task_3_Red_LED", 200, NULL, 2, &task_3_handle);
	configASSERT(task_3_Status == pdPASS);
	vTaskStartScheduler();
	return 1;
}

void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_handler();
  }
}


void Error_handler(void) {
	while(1);
}


void GPIO_init(void) {
	__HAL_RCC_GPIOD_CLK_ENABLE();
	GPIO_InitTypeDef	ledGpio;
	ledGpio.Mode = GPIO_MODE_OUTPUT_PP;
	ledGpio.Pull = GPIO_NOPULL;
	ledGpio.Speed = GPIO_SPEED_FAST;
	ledGpio.Pin = GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14; // GREEN LED TAKS 1
	HAL_GPIO_Init(GPIOD, &ledGpio);

//	ledGpio.Pin = GPIO_PIN_13; // ORANGE LED TAKS 2
//	HAL_GPIO_Init(GPIOD, &ledGpio);
//
//	ledGpio.Pin = GPIO_PIN_14; // RED LED TAKS 3
//	HAL_GPIO_Init(GPIOD, &ledGpio);
}

void task1_Handler(void * parameters) {
	while(1) {
		//SEGGER_SYSVIEW_PrintfTarget("Task_1_Green_LED");
		HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12);
	}

}

void task2_Handler(void * parameters) {
	while(1) {
			//SEGGER_SYSVIEW_PrintfTarget("Task_1_Orange_LED");
			HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_13);
		}

}
void task3_Handler(void * parameters) {
	while(1) {
			//SEGGER_SYSVIEW_PrintfTarget("Task_1_Red_LED");
			HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_14);
		}

}
