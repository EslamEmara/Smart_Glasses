/******************************************************************************
 *
 * Module: IR SENSOR
 *
 * File Name: ir_sensr.h
 *
 * Description: Header file for the ir_sensor driver
 *
 * Author: Smart Glasses Graduation Project Team
 *
 *******************************************************************************/

#ifndef IR_SENSOR_H_
#define IR_SENSOR_H_

#include "../MCAL/std_types.h"
#include "../MCAL/adc.h"


/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
uint8 IR_getDistance(uint8 channel_input_id);

#endif /* IR_SENSOR_H_ */
