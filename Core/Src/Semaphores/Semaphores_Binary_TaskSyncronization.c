/*
 * Semaphores_Binary_TaskSyncronization.c
 *
 *  Created on: Feb 15, 2025
 *      Author: dinesh bobburu
 */


/*
 * case 1: Binary Semaphores For TAsk  to Task Synchronization
 *
 * case2: Binary Semaphore interrupt to task synchronization
 *
 * */


#include "main.h"

void master_Task_Handle( void *pvParameters );
void slave_Task_Handle( void *pvParameters );

void UART_init(void);
void SystemClock_Config(void);
void Error_handler(void);
void GPIO_init(void);
void print_Message(char* message);

xTaskHandle hmaster_Task;
xTaskHandle hslave_Task;

xSemaphoreHandle semaHandle;

xQueueHandle workQueue;

BaseType_t status;

UART_HandleTypeDef huart2;

char message[200] = {0};

int main(void) {

	HAL_Init();
	SystemClock_Config();
	//HAL_RCC_DeInit();
	//SystemCoreClockUpdate();
	UART_init();



	semaHandle = xSemaphoreCreateBinary();

	workQueue = xQueueCreate(1,sizeof(int));

	if(semaHandle != NULL && workQueue != NULL) {
		status = xTaskCreate(master_Task_Handle, "Master", 200, NULL, 4, &hmaster_Task);
		configASSERT( status != pdPASS);

		status = xTaskCreate(slave_Task_Handle, "Slave", 200, NULL, 4, &hslave_Task);
		configASSERT( status != pdPASS);
	}
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
	GPIO_InitTypeDef	ledGpio;
	ledGpio.Mode = GPIO_MODE_OUTPUT_PP;
	ledGpio.Pull = GPIO_NOPULL;
	ledGpio.Speed = GPIO_SPEED_FAST;
	ledGpio.Pin = GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15; // GREEN LED TAKS 1
	HAL_GPIO_Init(GPIOD, &ledGpio);

//	ledGpio.Pin = GPIO_PIN_13; // ORANGE LED TAKS 2
//	HAL_GPIO_Init(GPIOD, &ledGpio);
//
//	ledGpio.Pin = GPIO_PIN_14; // RED LED TAKS 3
//	HAL_GPIO_Init(GPIOD, &ledGpio);
}

void UART_init(void) {
	huart2.Instance = USART2;
	huart2.Init.BaudRate = 115200;
	huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart2.Init.Mode = UART_MODE_TX_RX;
	huart2.Init.StopBits = UART_STOPBITS_1;
	huart2.Init.WordLength = UART_WORDLENGTH_8B;
	huart2.Init.Parity = UART_PARITY_NONE;
	if(HAL_UART_Init(&huart2) != HAL_OK) {
		Error_handler();
	}
}

void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}


void master_Task_Handle( void *pvParameters ) {
	int ticketID;
	BaseType_t status;

    /* The semaphore is created in the 'empty' state, meaning the semaphore must
	 first be given using the xSemaphoreGive() API function before it
	 can subsequently be taken */
	xSemaphoreGive(semaHandle);
	while(1) {
		ticketID = (rand());
		status = xQueueSend(workQueue,&ticketID,0);

		if(status != pdPASS) {
			// Work Queue is FUll. so we are giving semaphore.
			sprintf(message,"Could not send to the Work queue.\r\n");
			print_Message(message);
		} else {
			xSemaphoreGive(semaHandle); // give semaphore to slave and Yield as master have nothing to do
			taskYIELD();
		}
	}
}

void slave_Task_Handle( void *pvParameters ) {
	int ticketID = 0;
	BaseType_t status;
	while(1) {
		    xSemaphoreTake(semaHandle, 0);
			status = xQueueReceive(workQueue, &ticketID, 0);
			if(status == pdTRUE) {
				sprintf(message, "Task %d Completed \r\n", ticketID);
				print_Message(message);
				vTaskDelay(pdMS_TO_TICKS(100));
			} else {
				sprintf(message, "Work Queue is Empty\r\n");
				print_Message(message);
			}


	}
}

void print_Message(char* message) {
	HAL_UART_Transmit(&huart2, (uint8_t*)message, strlen(message), HAL_MAX_DELAY);
}
