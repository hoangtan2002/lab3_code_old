/*
 * fsm_manual.c
 *
 *  Created on: Nov 2, 2022
 *      Author: tan
 */

#include"fsm_manual.h"

void fsm_manual_state2(){
	if(mode!=2){
		return;
	}
	disableCountDown();
	blinkLED(1);
	updateClock1(ledGreenTime);
	updateClock2(0);
	if(isButton2Pressed()){
		if(ledGreenTime == 100){
			ledGreenTime = 1;
		}
		else ledGreenTime++;
	}
	if(isButton3Pressed()){
		ledRedTime = ledGreenTime + ledYellowTime;
		reinitStatus();
	}
}


void fsm_manual_state3(){
	if(mode!=3){
		return;
	}
	disableCountDown();
	blinkLED(2);
	updateClock1(ledYellowTime);
	updateClock2(0);
	if(isButton2Pressed()){
		if(ledYellowTime == 100){
			ledYellowTime = 1;
		}
		else ledYellowTime++;
	}
	if(isButton3Pressed()){
		ledRedTime = ledGreenTime + ledYellowTime;
		reinitStatus();
	}

}


