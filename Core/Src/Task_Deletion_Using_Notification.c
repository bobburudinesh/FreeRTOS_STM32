/*
 * Task_Deletion_Using_Notification.c
 *
 *  Created on: Feb 13, 2025
 *      Author: dinesh bobburu
 */


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
void btn_Handler(void * parameters);
void GPIO_init(void);

TaskHandle_t task_1_handle;
TaskHandle_t task_2_handle;
TaskHandle_t task_3_handle;
TaskHandle_t btn_task_handle;

TaskHandle_t volatile next_task_handle = NULL; // holds next handle task handle that needs to be deleted.


int main(void) {

	BaseType_t	status;
	HAL_Init();
	SystemClock_Config();
	GPIO_init();
	SEGGER_UART_init(500000);
	DWT_CTRL |= (1<<0);
	SEGGER_SYSVIEW_Conf();
	status = xTaskCreate(task1_Handler, "Task_1_Green_LED", 200, NULL, 3, &task_1_handle);
	configASSERT(status == pdPASS);
	next_task_handle = task_1_handle;
	status = xTaskCreate(task2_Handler, "Task_2_Orange_LED", 200, NULL, 2, &task_2_handle);
	configASSERT(status == pdPASS);

	status = xTaskCreate(task3_Handler, "Task_3_Red_LED", 200, NULL, 1, &task_3_handle);
	configASSERT(status == pdPASS);
	status = xTaskCreate(btn_Handler, "Button_Task", 200, NULL, 4, &btn_task_handle);
	configASSERT(status == pdPASS);
	vTaskStartScheduler();
	while(1);
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
	__HAL_RCC_GPIOA_CLK_ENABLE();
	GPIO_InitTypeDef	ledGpio;
	GPIO_InitTypeDef 	switchGpio;
	ledGpio.Mode = GPIO_MODE_OUTPUT_PP;
	ledGpio.Pull = GPIO_NOPULL;
	ledGpio.Speed = GPIO_SPEED_FAST;
	ledGpio.Pin = GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14; // GREEN LED TAKS 1 | ORANGE LED TAKS 2 | RED LED TAKS 3
	HAL_GPIO_Init(GPIOD, &ledGpio);

	switchGpio.Mode = GPIO_MODE_INPUT;
	switchGpio.Pull = GPIO_NOPULL;
	//switchGpio.Speed = GPIO_SPEED_FAST;
	switchGpio.Pin = GPIO_PIN_0;
	HAL_GPIO_Init(GPIOA, &switchGpio);
}

void task1_Handler(void * parameters) {
	BaseType_t	status;
	while(1) {
		SEGGER_SYSVIEW_PrintfTarget("Task_1_Green_LED");
		HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12);
		status = xTaskNotifyWait(0,0,NULL,pdMS_TO_TICKS(1000));
		if(status == pdTRUE) {
			vTaskSuspendAll();
			next_task_handle = task_2_handle;
			xTaskResumeAll();
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);
			vTaskDelete(NULL);

		}
	}

}

void task2_Handler(void * parameters) {
	BaseType_t	status;
	while(1) {
			SEGGER_SYSVIEW_PrintfTarget("Task_1_Orange_LED");
			HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_13);
			status = xTaskNotifyWait(0,0,NULL,pdMS_TO_TICKS(800));
			if(status == pdTRUE) {
				vTaskSuspendAll();
				next_task_handle = task_3_handle;
				xTaskResumeAll();
				HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
				vTaskDelete(NULL);

			}
		}

}
void task3_Handler(void * parameters) {
	BaseType_t	status;
	while(1) {
			SEGGER_SYSVIEW_PrintfTarget("Task_1_Red_LED");
			HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_14);
			status = xTaskNotifyWait(0,0,NULL,pdMS_TO_TICKS(400));
			if(status == pdTRUE) {
				vTaskSuspendAll();
				next_task_handle = NULL;
				xTaskResumeAll();
				HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
				vTaskDelete(btn_task_handle);
				vTaskDelete(NULL);

			}
		}

}

void btn_Handler(void * parameters) {
	uint8_t btn_read = 0;
	uint8_t prev_read = 0;
	while(1) {
		//SEGGER_SYSVIEW_PrintfTarget("Task_1_Red_LED");
		btn_read = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);
		if(btn_read) {
			if(!prev_read) {
				xTaskNotify(next_task_handle,0,eNoAction);

			}
			prev_read = btn_read;
			vTaskDelay(pdMS_TO_TICKS(10));
		}
		}

}
