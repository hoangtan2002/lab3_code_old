/*
 * fsm_manual.c
 *
 *  Created on: Nov 2, 2022
 *      Author: tan
 */

#include"fsm_manual.h"

int isSet = 0;

void fsm_manual_state2(){
	if(mode!=2){
		return;
	}
	disableCountDown();
	blinkLED(1);
	updateClock1(ledGreenTime);
	updateClock2(mode);
	if(isButton2Pressed()==1){
		ledGreenTime++;
		if(ledGreenTime == 100){
			ledGreenTime = 1;
		}
	}
	if(isButton3Pressed()){
		ledRedTime = ledGreenTime + ledYellowTime;
		reinitStatus();
		isSet++;
	}
}

void fsm_manual_state3(){
	if(mode!=3){
		return;
	}
	disableCountDown();
	blinkLED(2);
	updateClock1(ledYellowTime);
	updateClock2(mode);
	if(isButton2Pressed()==1){
		ledYellowTime++;
		if(ledYellowTime == 100){
			ledYellowTime = 1;
		}

	}
	if(isButton3Pressed()){
		ledRedTime = ledGreenTime + ledYellowTime;
		reinitStatus();
		isSet++;
	}

}


