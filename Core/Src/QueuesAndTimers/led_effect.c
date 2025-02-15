/*
 * led_effect.c
 *
 *  Created on: Feb 14, 2025
 *      Author: dinesh bobburu
 */


#include "main.h"

static void led_effect_NONE(void);
static void led_effect_1_AND_2(void);
static void led_effect_3_AND_4(void);


uint8_t led_State = 0;
uint8_t led_current_option = 0;

void led_effects(uint8_t option) {

	switch (option) {
	case 0:
		led_current_option = 0;
		led_State = 0;
		led_effect_NONE();
	case 1:
		led_current_option = 1;
		led_State = 0;
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
		// Start Timer

		// END Timer
	case 2:
		led_current_option = 2;
		led_State = 0;

	case 3:
		led_current_option = 3;
		led_State = 0;

	case 4:
		led_current_option = 4;
		led_State = 0;

	default:
		led_current_option = 0;
		led_State = 0;
		break;
	}
}

static void led_effect_NONE(void) {
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
}

static void led_effect_1_AND_2(void) {
	HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12);
	HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_13);
	HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_14);
	HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_15);
}


static void led_effect_3_AND_4(void) {
	uint8_t i = 0;
	uint8_t value = 0;
	uint8_t led_Offset = 0;
	if (led_current_option == 4) {
		led_Offset = 3;
	}
	value = 0x01<<((led_State + led_Offset)%4);
	while (i<4) {
		HAL_GPIO_WritePin(GPIOD, (GPIO_PIN_12 << i), ((value>>i)&0x01));
	}
	led_State++;
}

void led_Timer_Callback( TimerHandle_t xTimer ) {
	if(led_current_option == 1 || led_current_option == 2) {
		led_effect_1_AND_2();
	} else if(led_current_option == 3 || led_current_option == 4) {
		led_effect_3_AND_4();
	}
}
