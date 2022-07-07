/******************************************************************************
 *
 * Module: IR SENSOR
 *
 * File Name: ir_sensr.c
 *
 * Description: Source file for the ir_sensor driver
 *
 * Author: Smart Glasses Graduation Project Team
 *
 *******************************************************************************/

#include "ir_sensor.h"


long map(long x, long in_min, long in_max, long out_min, long out_max) {
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void sort(int a[], int size)
{
	for(int i=0; i<(size-1); i++) {
		int flag = 1;
		for(int o=0; o<(size-(i+1)); o++) {
			if(a[o] > a[o+1]) {
				int t = a[o];
				a[o] = a[o+1];
				a[o+1] = t;
				flag = 0;
			}
		}
		if (flag) break;
	}
}

uint8 IR_getDistance(uint8 channel_input_id)
{
	int ir_val[25];
	uint8 distanceCM;
	for (uint8 i=0; i<25; i++){
		// Read analog value
		ir_val[i] = ADC_readChannel(channel_input_id);
	}
	
	// Sort it
	sort(ir_val,25);
	distanceCM = 27.728 * pow(map(ir_val[25 / 2], 0, 1023, 0, 5000)/1000.0, -1.2045);
	return distanceCM;
}
