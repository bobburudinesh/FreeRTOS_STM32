/*
 * task_handler.c
 *
 *  Created on: Feb 14, 2025
 *      Author: dinesh bobburu
 */

#include "main.h"

static int extract_command(command_t *command);
static void process_command(command_t *command);
extern void stop_LedTimer(void);

const char* feature_NotAvailable = "----- RTC Feature Coming Soon... -----\n";

const char* invalid_option = "\n----- INVALID OPTION -----\n";

extern UART_HandleTypeDef huart2;

void led_Task_Handle(void * parameters) {
	uint32_t cmd_addr;
	command_t *cmd;
	const char* ledmenu =  "\n====================\n "
			"|       LED        |\n"
			"====================\n"
			"none, e1, e2, e3, e4 \n"
			"Enter Your Selection Here: ";
	while(1) {
		xTaskNotifyWait(0,0,NULL, portMAX_DELAY);
		xQueueSend(qPrint, (void*)&ledmenu, portMAX_DELAY);
		xTaskNotifyWait(0,0,&cmd_addr, portMAX_DELAY);
		stop_LedTimer();
		cmd = (command_t*)cmd_addr;
		if (cmd->length <=4) {
			if(!(strcmp((char*)cmd->payload, "none"))) {
				led_effects(0);
			} else if(!(strcmp((char*)cmd->payload, "e1"))) {
				led_effects(1);
			}else if(!(strcmp((char*)cmd->payload, "e2"))) {
				led_effects(2);
			}else if(!(strcmp((char*)cmd->payload, "e3"))) {
				led_effects(3);
			}else if(!(strcmp((char*)cmd->payload, "e4"))) {
				led_effects(4);
			} else {
				xQueueSend(qPrint,(void*)&invalid_option, portMAX_DELAY);
			}
		} else {
			xQueueSend(qPrint,(void*)&invalid_option, portMAX_DELAY);
		}
		current_state = sMainMenu;
		xTaskNotify(hMenu_Task,0,eNoAction);

	}

}

void menu_Task_Handle(void * parameters) {
	uint32_t cmd_addr;
	command_t *cmd;
	uint8_t option;
	const char* message = "\n====================\n "
			"|       MENU        |\n"
			"====================\n"
			"LED Effect    ---> 0\n"
			"Date And Time ---> 1\n"
			"Exit          ---> 2\n"
			"Enter Your Selection Here:";

	while(1) {
		xQueueSend(qPrint, &message, portMAX_DELAY);
		xTaskNotifyWait(0,0,&cmd_addr,portMAX_DELAY);
		cmd = (command_t*)cmd_addr;
		if(cmd->length == 1) {
			option = cmd->payload[0]-48;
			switch(option) {
			case 0:
				current_state = sLedEffect;
				xTaskNotify(hLed_Task,0, eNoAction);
				break;
			case 1:
				current_state = sRtcMenu;
				xTaskNotify(hRtc_Task,0,eNoAction);
				break;
			case 2:
				break;
			default:
				xQueueSend(qPrint,&invalid_option, portMAX_DELAY);
				continue;
			}
		} else {
			// invalid option entry
			xQueueSend(qPrint,&invalid_option, portMAX_DELAY);
			continue;
		}

		xTaskNotifyWait(0,0,NULL,portMAX_DELAY);
	}

}

void print_Task_Handle(void * parameters) {
	uint32_t* msg;

	while(1) {
		xQueueReceive(qPrint, &msg, portMAX_DELAY);
		HAL_UART_Transmit(&huart2, (uint8_t*)msg, strlen((char*)msg), HAL_MAX_DELAY);
	}

}

void command_Task_Handle(void * parameters) {
	BaseType_t ret;
	command_t cmd;
	while(1) {
		ret = xTaskNotifyWait(0,0,NULL, portMAX_DELAY);
		if(ret == pdTRUE) {
			process_command(&cmd);
		}

	}

}

void rtc_Task_Handle(void * parameters) {
	const char* rtcMenu =  "\n====================\n "
			"|       RTC        |\n"
			"====================\n"
			"RTC Coming Soon... \n";
	while(1) {
//		xTaskNotifyWait(0,0,NULL,portMAX_DELAY);
//		xQueueSend(qPrint, &rtcMenu, portMAX_DELAY);
//		current_state = sMainMenu;
//		xTaskNotify(hMenu_Task,0, eNoAction);
	}

}


static int extract_command(command_t *command){
	uint8_t data;
	BaseType_t status;
	status = uxQueueMessagesWaiting(qData);
	if(!status) {return -1;}
	uint8_t i = 0;
	do {
		status = xQueueReceive(qData, &data, portMAX_DELAY);
		if(status == pdTRUE) command->payload[i++] = data;
	} while (data != '\n');

	command->payload[i-1] = '\0';
	command->length = i-1;
	return 0;
}

static void process_command(command_t *command) {
	extract_command(command);
	switch(current_state){
	case sMainMenu:
		xTaskNotify(hMenu_Task,(uint32_t)command, eSetValueWithOverwrite);
		break;
	case sLedEffect:
		xTaskNotify(hLed_Task,(uint32_t)command, eSetValueWithOverwrite);
		break;
	case sRtcMenu:
		xTaskNotify(hRtc_Task,(uint32_t)command, eSetValueWithOverwrite);
		break;
	case sRtcTimeConfig:
		xTaskNotify(hRtc_Task,(uint32_t)command, eSetValueWithOverwrite);
		break;
	case sRtcDateConfig:
		xTaskNotify(hRtc_Task,(uint32_t)command, eSetValueWithOverwrite);
		break;
	case sRtcReport:
		xTaskNotify(hRtc_Task,(uint32_t)command, eSetValueWithOverwrite);
		break;

	}
}

