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

uint8 IR_getDistance(uint8 channel_input_id)
{
	uint8 distance = 0;
	uint16 adc_value = 0;
	const uint16 k = 6762;
	const uint8 a = 9;
	const uint8 b = 4;


	/* Read ADC channel where the IR sensor is connected */
	adc_value = ADC_readChannel(channel_input_id); //depends o which channel we will connect to the IR
	
	if(adc_value <= a)
	{
		return 0;
	}

	distance = (uint8)((k/(adc_value - a)) - b);
	
	return distance;
}
