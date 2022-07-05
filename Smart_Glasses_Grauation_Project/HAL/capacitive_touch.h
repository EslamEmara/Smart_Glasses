/******************************************************************************
 *
 * Module: CAPACITIVE TOUCH
 *
 * File Name: capacitive_touch.h
 *
 * Description: Header file for the capacitive touch driver
 *
 * Author: Smart Glasses Graduation Project Team
 *
 *******************************************************************************/  


#ifndef CAPACITIVE_TOUCH_H_
#define CAPACITIVE_TOUCH_H_


#include "../MCAL/i2cmaster.h"
#include <avr/io.h>

enum CAP1203_Register
{
	MAIN_CONTROL = 0x00,
	GENERAL_STATUS = 0x02,
	SENSOR_INPUT_STATUS = 0x03,
	NOISE_FLAG_STATUS = 0x0A,
	SENSOR_INPUT_1_DELTA_COUNT = 0x10,
	SENSOR_INPUT_2_DELTA_COUNT = 0X11,
	SENSOR_INPUT_3_DELTA_COUNT = 0X12,
	SENSITIVITY_CONTROL = 0x1F,
	CONFIG = 0x20,
	SENSOR_INPUT_ENABLE = 0x21,
	SENSOR_INPUT_CONFIG = 0x22,
	SENSOR_INPUT_CONFIG_2 = 0x23,
	AVERAGING_AND_SAMPLE_CONFIG = 0x24,
	CALIBRATION_ACTIVATE_AND_STATUS = 0x26,
	INTERRUPT_ENABLE = 0x27,
	REPEAT_RATE_ENABLE = 0x28,
	MULTIPLE_TOUCH_CONFIG = 0x2A,
	MULTIPLE_TOUCH_PATTERN_CONFIG = 0x2B,
	MULTIPLE_TOUCH_PATTERN = 0x2D,
	BASE_COUNT_OUT = 0x2E,
	RECALIBRATION_CONFIG = 0x2F,
	SENSOR_1_INPUT_THRESH = 0x30,
	SENSOR_2_INPUT_THRESH = 0x31,
	SENSOR_3_INPUT_THRESH = 0x32,
	SENSOR_INPUT_NOISE_THRESH = 0x38,
	STANDBY_CHANNEL = 0x40,
	STANDBY_CONFIG = 0x41,
	STANDBY_SENSITIVITY = 0x42,
	STANDBY_THRESH = 0x43,
	CONFIG_2 = 0x44,
	SENSOR_INPUT_1_BASE_COUNT = 0x50,
	SENSOR_INPUT_2_BASE_COUNT = 0x51,
	SENSOR_INPUT_3_BASE_COUNT = 0x52,
	POWER_BUTTON = 0x60,
	POWER_BUTTON_CONFIG = 0x61,
	SENSOR_INPUT_1_CALIBRATION = 0xB1,
	SENSOR_INPUT_2_CALIBRATION = 0xB2,
	SENSOR_INPUT_3_CALIBRATION = 0xB3,
	SENSOR_INPUT_CALIBRATION_LSB_1 = 0xB9,
	PROD_ID = 0xFD,
	MANUFACTURE_ID = 0xFE,
	REVISION = 0xFF,
};


typedef union {
	struct
	{
		uint8 INT : 1;
		uint8 EMPTY_1 : 3;
		uint8 DSLEEP : 1;
		uint8 STBY : 1;
		uint8 EMPTY_2 : 2;
	} MAIN_CONTROL_FIELDS;
	uint8 MAIN_CONTROL_COMBINED;
} MAIN_CONTROL_REG;

void CAP_clearInterrupt();
void writeRegister(uint8 reg , uint8 data);
uint8 readRegister(uint8 reg,uint8* s );
uint8 CAP_isLeftTouched();
uint8 CAP_isRightTouched();
uint8 CAP_isMiddleTouched();





#endif /* CAPACITIVE_TOUCH_H_ */