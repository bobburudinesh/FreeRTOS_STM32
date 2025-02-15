/*
 * Queues_And_Timers.c
 *
 *  Created on: Feb 14, 2025
 *      Author: dinesh bobburu
 */


/*
 * Exercise in slides
 *
 * */


#include "main.h"

void led_Task_Handle(void * parameters);
void menu_Task_Handle(void * parameters);
void print_Task_Handle(void * parameters);
void command_Task_Handle(void * parameters);
void rtc_Task_Handle(void * parameters);



void UART_init(void);
void SystemClock_Config(void);
void Error_handler(void);
void GPIO_init(void);
void create_Tasks(void);


UART_HandleTypeDef huart2;


char *data = "Please Enter data and press enter\r\n";
xTaskHandle	hPrint_Task;
xTaskHandle hCommand_Task;
xTaskHandle	hMenu_Task;
xTaskHandle hLed_Task;
xTaskHandle hRtc_Task; // TODO: Implement once RTC tutorial is completed

xQueueHandle qData;
xQueueHandle qPrint;


state_t current_state = sMainMenu;
BaseType_t status;

volatile uint8_t user_data;
int main(void) {
	HAL_Init();
	SystemClock_Config();
	UART_init();
	//GPIO_init();
	create_Tasks();
	qData = xQueueCreate(10,sizeof(char));
	configASSERT(qData != NULL);

	qPrint = xQueueCreate(10,sizeof(size_t));
	configASSERT(qPrint != NULL);
	HAL_UART_Receive_IT(&huart2, (uint8_t*)&user_data, 1);

	vTaskStartScheduler();

	while(1);

}


void create_Tasks() {
	status = xTaskCreate(led_Task_Handle, "Led_TASK", 250, NULL, 2, &hLed_Task);
	configASSERT(status == pdPASS);
	status = xTaskCreate(menu_Task_Handle, "Menu_TASK", 250, NULL, 2, &hMenu_Task);
	configASSERT(status == pdPASS);
	status = xTaskCreate(print_Task_Handle, "Print_TASK", 250, NULL, 2, &hPrint_Task);
	configASSERT(status == pdPASS);
	status = xTaskCreate(command_Task_Handle, "Command_TASK", 250, NULL, 2, &hCommand_Task);
	configASSERT(status == pdPASS);
	status = xTaskCreate(rtc_Task_Handle, "Rtc_TASK", 250, NULL, 2, &hRtc_Task);
	configASSERT(status == pdPASS);

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


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
	// Check if queue is full
	if (!xQueueIsQueueFullFromISR(qData)) {
		// Queue not full
		xQueueSendFromISR(qData,(void*)&user_data,NULL);
	} else {
		if(user_data == '\n') {
			xQueueReceiveFromISR(qPrint, (void*)&user_data, NULL);
			xQueueSendFromISR(qData, (void*)&user_data, NULL);
		}
	}
	if(user_data == '\n') {
		xTaskNotifyFromISR(hCommand_Task, 0, eNoAction, NULL);
	}

	HAL_UART_Receive_IT(&huart2, (uint8_t*)&user_data, 1);
}
