/*
 * led.c
 *
 *  Created on: Oct 30, 2022
 *      Author: tan
 */

#include"led.h"

void turn_LED1_on(int n){ //0 cho red, 1 cho green, 2 cho yellow
	int led_array[3][3] = {
		{0,1,1}, //RED
		{1,0,1}, //GREEN
		{1,1,0}, //YELLOW
	};
	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, led_array[n][0]);
	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, led_array[n][1]);
	HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, led_array[n][2]);
}

void turn_LED2_on(int n){ //0 cho red, 1 cho green, 2 cho yellow
	int led_array[3][3] = {
		{0,1,1}, //RED
		{1,0,1}, //GREEN
		{1,1,0}, //YELLOW
	};
	HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, led_array[n][0]);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, led_array[n][1]);
	HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, led_array[n][2]);
}

void blinkLED(int n){

}

void init_LED_array(){
	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, 1);
	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, 1);
	HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, 1);
	HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, 1);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, 1);
	HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, 1);
}
