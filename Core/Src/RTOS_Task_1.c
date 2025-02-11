/*
 * RTOS_Task_1.c
 *
 *  Created on: Feb 11, 2025
 *      Author: dinesh bobburu
 */

/*
 * Exercise to create a 2 Tasks of same priority and print some message.
 * Case 1: configUSE_PREEMPTION = 1, Output was very random.
 * Case 2: configUSE_PREEMPTION = 0, output was somewhat Okay.
 * Case 3: configUSE_PREEMPTION = 0 and taskYIELD();OUtput was as exprected.
 *
 * */

#include "main.h"
#include "FreeRTOS.h"
#include "task.h"

static void task1_handler(void* parameters);
static void task2_handler(void* parameters);
void SystemClock_Config(void);
void Error_handler(void);

int main(void) {
	TaskHandle_t task_1_handle;
	TaskHandle_t task_2_handle;
	BaseType_t	status;
	 HAL_Init();
	 SystemClock_Config();

	// Create TAsk 1
	status = xTaskCreate(task1_handler, "Task_1", 200, "Hello World from Task -1", 2, &task_1_handle);
	configASSERT(status == pdPASS)
	// Create Task 2
	status = xTaskCreate(task2_handler, "Task_2", 200, "Hello World from Task -2", 2, &task_2_handle);
	configASSERT(status == pdPASS)
	// START The Free RTOS Scheduler
	vTaskStartScheduler();
	while(1);
	// If the control COmes here the initialization of task has failed due to insufficient memory in the heap.
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
  RCC_OscInitStruct.PLL.PLLN = 50;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
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

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_handler();
  }
}

void Error_handler(void) {
	while(1);
}
static void task1_handler(void* parameters) {
	while(1) {
		printf("%s\n", (char*)parameters);
		taskYIELD();// Will give up processor after sending the message.
	}
}

static void task2_handler(void* parameters) {
	while(1) {
			printf("%s\n", (char*)parameters);
			taskYIELD();// Will give up processor after sending the message.
		}
}
