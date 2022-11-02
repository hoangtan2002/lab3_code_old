/*
 * fsm_auto.c
 *
 *  Created on: Oct 30, 2022
 *      Author: tan
 */
#include "fsm_auto.h"
#define INIT 1
#define AUTO_RED 2
#define AUTO_GREEN 3
#define AUTO_YELLOW 4
int status = INIT;

void fsm_auto_state1(){
  	switch(status){
  	case INIT:
  		status = AUTO_RED;
  		setTimer1(1000*ledRedTime);
  		turn_LED1_on(0);
  		break;
  	case AUTO_RED:
  		if(timer1_flag == 1){
  			status = AUTO_GREEN;
  			turn_LED1_on(1);
  			setTimer1(1000*ledGreenTime);
  		}
	break;
  	case AUTO_GREEN:
  		if(timer1_flag == 1){
  			status = AUTO_YELLOW;
  			turn_LED1_on(2);
  			setTimer1(1000*ledYellowTime);
  		}
	break;
  	case AUTO_YELLOW:
  		if(timer1_flag == 1){
  			status = AUTO_RED;
  			turn_LED1_on(0);
  			setTimer1(1000*ledRedTime);
  		}
  		break;
  	}
}
