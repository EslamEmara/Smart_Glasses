/******************************************************************************
 * File Name: main.c
 *
 * Description: Source file for Application layer
 *
 * Author: Smart Glasses Graduation Project Team
 *
 *******************************************************************************/



#include "APP.h"



int main(void)
{
	INIT_Fucntions();
	
	while(1){
		Motion_Detection_Vibration();
		CAPACITIVE_Touch_Patterns();
	}
}