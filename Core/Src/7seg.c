/*
 * 7seg.c
 *
 *  Created on: Oct 30, 2022
 *      Author: tan
 */

#include"7seg.h"

int ledBuffer[4] = {0,0,0,0};
int segCounter = 0;

void update7SEG ( int index ) {
	switch ( index ) {
	case 0:
		//Display the first 7 SEG with led_buffer [0]
		selectSEG(0);
		display7SEG(ledBuffer[index]);
		break ;
	case 1:
		//Display the second 7 SEG with led_buffer [1]
		selectSEG(1);
		display7SEG(ledBuffer[index]);
		break ;
	case 2:
		//Display the third 7 SEG with led_buffer [2]
		selectSEG(2);
		display7SEG(ledBuffer[index]);
		break ;
	case 3:
		//Display the forth 7 SEG with led_buffer [3]
		selectSEG(3);
		display7SEG(ledBuffer[index]);
		break ;
	default :
		break ;
	}

 }

void selectSEG(int n){
	int selectSEGArray[4][4] = {
		{0,1,1,1},
		{1,0,1,1},
		{1,1,0,1},
		{1,1,1,0}
	};
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, selectSEGArray[n][0]);
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, selectSEGArray[n][1]);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, selectSEGArray[n][2]);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, selectSEGArray[n][3]);
}

void display7SEG(int n){
	int a[10][7] = {
			{0,0,0,0,0,0,1}, //0
			{1,0,0,1,1,1,1}, //1
			{0,0,1,0,0,1,0}, //2
			{0,0,0,0,1,1,0}, //3
			{1,0,0,1,1,0,0}, //4
			{0,1,0,0,1,0,0}, //5
			{0,1,0,0,0,0,0}, //6
			{0,0,0,1,1,1,1}, //7
			{0,0,0,0,0,0,0}, //8
			{0,0,0,0,1,0,0}, //9
	};
	HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, a[n][0]);
	HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, a[n][1]);
	HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, a[n][2]);
	HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, a[n][3]);
	HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, a[n][4]);
	HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, a[n][5]);
	HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, a[n][6]);
}

void updateBuffer(int led_1, int led_2, int led_3, int led_4){
	ledBuffer[0] = led_1;
	ledBuffer[1] = led_2;
	ledBuffer[2] = led_3;
	ledBuffer[3] = led_4;
}

void segLEDScan(){
	if(timer3_flag==1){
		if(segCounter >= 4){
			segCounter = 0;
		}
		update7SEG(segCounter++);
		setTimer3(25);
	}
}

