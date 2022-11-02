/*
 * modeset.c
 *
 *  Created on: Nov 2, 2022
 *      Author: tan
 */

#include"modeset.h"

void modeset(){
	if(isButton1Pressed()){
		mode++;
		if(mode>3){
			mode = 1;
		}
	}
}


