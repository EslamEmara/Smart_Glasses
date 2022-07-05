/******************************************************************************
 *
 * Module: CAPACITIVE TOUCH
 *
 * File Name: capacitive_touch.c
 *
 * Description: Source file for the capacitive touch driver
 *
 * Author: Smart Glasses Graduation Project Team
 *
 *******************************************************************************/ 

#include "capacitive_touch.h"


uint8 readRegister(uint8 reg,uint8* s )
{
	i2c_start(0x28,0);
	i2c_write(reg);
	
	i2c_start(0x28,1);
	*s = i2c_readNak();
	
	i2c_stop();
	return 0;
}
void writeRegister(uint8 reg , uint8 data){
	i2c_start(0x28,0);
	i2c_write(reg);
	i2c_write(data);
	i2c_stop();
}
uint8 CAP_isLeftTouched()
{
	uint8 reg;
	readRegister(SENSOR_INPUT_STATUS,&reg);

	// Touch detected
	if (reg == 0b1)
	{
		CAP_clearInterrupt();
		return 1;
	}
	return 0;
}
uint8 CAP_isRightTouched()
{
	uint8 reg;
	readRegister(SENSOR_INPUT_STATUS,&reg);

	// Touch detected
	if (reg == 0b100)
	{
		CAP_clearInterrupt();
		return 1;
	}
	return 0;
}
uint8 CAP_isMiddleTouched()
{
	uint8 reg;
	readRegister(SENSOR_INPUT_STATUS,&reg);

	// Touch detected
	if (reg == 0b10)
	{
		CAP_clearInterrupt();
		return 1;
	}
	return 0;
}


void CAP_clearInterrupt()
{
	MAIN_CONTROL_REG reg;
	readRegister(MAIN_CONTROL, &reg.MAIN_CONTROL_COMBINED );
	reg.MAIN_CONTROL_FIELDS.INT = 0x00;
	writeRegister(MAIN_CONTROL, reg.MAIN_CONTROL_COMBINED);
}