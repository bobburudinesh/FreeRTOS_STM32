/*
 * Semaphores_Counting_Interrupt_And_Task_Sync.c
 *
 *  Created on: Feb 16, 2025
 *      Author: dinesh bobburu
 */


/*
 * Counting Semaphores For Interrupt  to Task Synchronization for latching high speed interrupt scenarios.
 *
 *
 * */


#include "main.h"

void master_Task_Handle( void *pvParameters );
void slave_Task_Handle( void *pvParameters );

void UART_init(void);
void SystemClock_Config(void);
void Error_handler(void);
void print_Message(char* message);
void setup_Software_Interrupt(void);

xTaskHandle hmaster_Task;
xTaskHandle hslave_Task;

xSemaphoreHandle sema_Counting_Handle;
BaseType_t status;

UART_HandleTypeDef huart2;

char message[200] = {0};

int main(void) {

	HAL_Init();
	SystemClock_Config();
	UART_init();
	sema_Counting_Handle = xSemaphoreCreateCounting(10,0);

	if(sema_Counting_Handle != NULL) {
		setup_Software_Interrupt();
		status = xTaskCreate(master_Task_Handle, "Master", 200, NULL, 4, &hmaster_Task);
		configASSERT( status == pdPASS);

		status = xTaskCreate(slave_Task_Handle, "Slave", 200, NULL, 4, &hslave_Task);
		configASSERT( status == pdPASS);

		vTaskStartScheduler();
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
	while(1) {
		/* This task is just used to 'simulate' an interrupt.  This is done by
		periodically generating a software interrupt. */
		vTaskDelay( pdMS_TO_TICKS(500) );

		/* Generate the interrupt, printing a message both before hand and
		afterwards so the sequence of execution is evident from the output. */
        sprintf(message, "Periodic task - Pending the interrupt.\r\n" );
        print_Message(message);

        //pend the interrupt
        NVIC_SetPendingIRQ(EXTI15_10_IRQn);

        sprintf(message, "Periodic task - Resuming.\r\n" );
        print_Message(message);
	}
}

void slave_Task_Handle( void *pvParameters ) {
	while(1) {
		/* Use the semaphore to wait for the event.  The semaphore was created
		before the scheduler was started so before this task ran for the first
		time.  The task blocks indefinitely meaning this function call will only
		return once the semaphore has been successfully obtained - so there is no
		need to check the returned value. */
		xSemaphoreTake( sema_Counting_Handle, portMAX_DELAY );

		/* To get here the event must have occurred.  Process the event (in this
		case we just print out a message). */
		sprintf(message, "Handler task - Processing event.\r\n");
		print_Message(message);

	}
}

void print_Message(char* message) {
	HAL_UART_Transmit(&huart2, (uint8_t*)message, strlen(message), HAL_MAX_DELAY);
}


void setup_Software_Interrupt(void) {
	/* here were simulating the button interrupt by manually setting the interrupt enable bit in the NVIC enable register*/

	/* The interrupt service routine uses an (interrupt safe) FreeRTOS API
	function so the interrupt priority must be at or below the priority defined
	by configSYSCALL_INTERRUPT_PRIORITY. */

	NVIC_SetPriority( EXTI15_10_IRQn, configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY );

	/* Enable the interrupt. */
	NVIC_EnableIRQ( EXTI15_10_IRQn );
}

void EXTI15_10_IRQHandler( void )
{
	portBASE_TYPE xHigherPriorityTaskWoken = pdFALSE;

	/* 'Give' the semaphore multiple times.  The first will unblock the handler
	task, the following 'gives' are to demonstrate that the semaphore latches
	the events to allow the handler task to process them in turn without any
	events getting lost.  This simulates multiple interrupts being taken by the
	processor, even though in this case the events are simulated within a single
	interrupt occurrence.*/
	sprintf(message,"==>Button_Handler\r\n");
	print_Message(message);

	xSemaphoreGiveFromISR( sema_Counting_Handle, &xHigherPriorityTaskWoken );
	xSemaphoreGiveFromISR( sema_Counting_Handle, &xHigherPriorityTaskWoken );
	xSemaphoreGiveFromISR( sema_Counting_Handle, &xHigherPriorityTaskWoken );
	xSemaphoreGiveFromISR( sema_Counting_Handle, &xHigherPriorityTaskWoken );
	xSemaphoreGiveFromISR( sema_Counting_Handle, &xHigherPriorityTaskWoken );

    /* Clear the software interrupt bit using the interrupt controllers  */


    /* Giving the semaphore may have unblocked a task - if it did and the
    unblocked task has a priority equal to or above the currently executing
    task then xHigherPriorityTaskWoken will have been set to pdTRUE and
    portEND_SWITCHING_ISR() will force a context switch to the newly unblocked
    higher priority task.

    NOTE: The syntax for forcing a context switch within an ISR varies between
    FreeRTOS ports.  The portEND_SWITCHING_ISR() macro is provided as part of
    the Cortex M3 port layer for this purpose.  taskYIELD() must never be called
    from an ISR! */
    portEND_SWITCHING_ISR( xHigherPriorityTaskWoken );
}

