/*
 * fsm_auto.c
 *
 *  Created on: Oct 30, 2022
 *      Author: tan
 */
#include "fsm_auto.h"



void fsm_auto_state1(){
	if(mode!=1){
		return;
	}
  	switch(status1){
  	case INIT:
  		status1 = AUTO_RED;
  		setTimer1(100*ledRedTime);
  		setCountDown1(ledRedTime);
  		turn_LED1_on(0);
  		break;
  	case AUTO_RED:
  		if(timer1_flag == 1){
  			status1 = AUTO_GREEN;
  			turn_LED1_on(1);
  	  		setCountDown1(ledGreenTime);
  			setTimer1(100*ledGreenTime);
  		}
	break;
  	case AUTO_GREEN:
  		if(timer1_flag == 1){
  			status1 = AUTO_YELLOW;
  			turn_LED1_on(2);
  			setTimer1(100*ledYellowTime);
  	  		setCountDown1(ledYellowTime);
  		}
	break;
  	case AUTO_YELLOW:
  		if(timer1_flag == 1){
  			status1 = AUTO_RED;
  			turn_LED1_on(0);
  			setTimer1(100*ledRedTime);
  	  		setCountDown1(ledRedTime);
  		}
  		break;
  	}

  	switch(status2){
  	case INIT:
  		status2 = AUTO_GREEN;
  		setTimer2(100*ledGreenTime);
  		setCountDown2(ledGreenTime);
  		turn_LED2_on(1);
  		break;
  	case AUTO_GREEN:
  		if(timer2_flag == 1){
  			status2 = AUTO_YELLOW;
  			turn_LED2_on(2);
  	  		setCountDown2(ledYellowTime);
  			setTimer2(100*ledYellowTime);
  		}
	break;
  	case AUTO_YELLOW:
  		if(timer2_flag == 1){
  			status2 = AUTO_RED;
  			turn_LED2_on(0);
  			setTimer2(100*ledRedTime);
  	  		setCountDown2(ledRedTime);
  		}
	break;
  	case AUTO_RED:
  		if(timer2_flag == 1){
  			status2 = AUTO_GREEN;
  			turn_LED2_on(1);
  			setTimer2(100*ledGreenTime);
  	  		setCountDown2(ledGreenTime);
  		}
  		break;
  	}
}
