/*
 * 7seg.h
 *
 *  Created on: Oct 30, 2022
 *      Author: tan
 */

#ifndef INC_7SEG_H_
#define INC_7SEG_H_

#include"main.h"
#include"software_timer.h"

extern int ledBuffer[4];
extern int segCounter;

void update7SEG(int n);
void display7SEG(int n);
void updateBuffer(int led_1, int led_2, int led_3, int led_4);
void segLEDScan();
void selectSEG(int n);

#endif /* INC_7SEG_H_ */
