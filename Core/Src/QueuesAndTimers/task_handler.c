/*
 * task_handler.c
 *
 *  Created on: Feb 14, 2025
 *      Author: dinesh bobburu
 */

#include "main.h"

static int extract_command(command_t *command);
static void process_command(command_t *command);




void led_Task_Handle(void * parameters) {

	while(1) {

	}

}

void menu_Task_Handle(void * parameters) {
	const char* message = "====================\n "
			"|       MENU        |\n"
			"====================\n"
			"LED Effect    ---> 0\n"
			"Date And Time ---> 1\n"
			"Exit          ---> 3\n"
			"Enter Your Selection Here:";

	while(1) {

	}

}

void print_Task_Handle(void * parameters) {

	while(1) {

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

	while(1) {

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
	case sLedEffect:
		xTaskNotify(hLed_Task,(uint32_t)command, eSetValueWithOverwrite);
	case sRtcMenu:
		xTaskNotify(hRtc_Task,(uint32_t)command, eSetValueWithOverwrite);
	case sRtcTimeConfig:
		xTaskNotify(hRtc_Task,(uint32_t)command, eSetValueWithOverwrite);
	case sRtcDateConfig:
		xTaskNotify(hRtc_Task,(uint32_t)command, eSetValueWithOverwrite);
	case sRtcReport:
		xTaskNotify(hRtc_Task,(uint32_t)command, eSetValueWithOverwrite);
	default:
		break;

	}
}

