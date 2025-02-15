/*
 * led_effect.c
 *
 *  Created on: Feb 14, 2025
 *      Author: dinesh bobburu
 */


#include "main.h"

static void led_effect_NONE(void);
static void led_effect_1(void);
static void led_effect_2(void);
static void led_effect_3(void);
static void led_effect_4(void);
void stop_LedTimer(void);


uint8_t led_State = 0;
uint8_t led_current_option = 0;

void led_effects(uint8_t option) {

	switch (option) {
	case 0:
		led_current_option = 0;
		led_State = 0;
		xTimerStart(hled_Timer, portMAX_DELAY);
		break;
	case 1:
		led_current_option = 1;
		led_State = 0;
		// Start Timer
		led_effect_NONE();
		xTimerStart(hled_Timer, portMAX_DELAY);
		break;
	case 2:
		led_current_option = 2;
		led_State = 0;
		led_effect_NONE();
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
		xTimerStart(hled_Timer, portMAX_DELAY);
		break;
	case 3:
		led_current_option = 3;
		led_State = 0;
		led_effect_NONE();
		xTimerStart(hled_Timer, portMAX_DELAY);
		break;
	case 4:
		led_current_option = 4;
		led_State = 0;
		led_effect_NONE();
		xTimerStart(hled_Timer, portMAX_DELAY);
		break;
	default:
		led_current_option = 0;
		led_State = 0;
		led_effect_NONE();
		stop_LedTimer();
		break;
	}
}

void stop_LedTimer(void) {
	if(xTimerIsTimerActive(hled_Timer) != pdFALSE) {
			xTimerStop(hled_Timer, portMAX_DELAY);
		}
}

static void led_effect_NONE(void) {
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
}

static void led_effect_1(void) {

	HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12);
	HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_13);
	HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_14);
	HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_15);
}


static void led_effect_3(void) {
	uint8_t i = 0;
	uint8_t value = 0;
	value = 0x01<<(led_State%4);
	while (i<4) {
		HAL_GPIO_WritePin(GPIOD, (GPIO_PIN_12 << i), ((value>>i)&0x01));
		i++;
	}
	led_State++;
}

static void led_effect_4(void) {
	uint8_t i = 0;
	uint8_t value = 0;
	value = 0x01<<((led_State + 0)%4);
	while (i<4) {
		HAL_GPIO_WritePin(GPIOD, (GPIO_PIN_15 >> i), ((value>>i)&0x01));
		i++;
	}
	led_State++;
}

static void led_effect_2(void) {
	led_effect_1();
}

void led_Timer_Callback( TimerHandle_t xTimer ) {
	if(led_current_option == 0) {
		led_effect_NONE();
	} else if(led_current_option == 1) {
		led_effect_1();
	} else if(led_current_option == 2) {
		led_effect_2();
	} else if(led_current_option == 3) {
		led_effect_3();
	} else if(led_current_option == 4) {
		led_effect_4();
	}
}
