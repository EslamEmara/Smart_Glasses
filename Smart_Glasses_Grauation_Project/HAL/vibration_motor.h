/******************************************************************************
 *
 * Module: VIBRATION MOTOR
 *
 * File Name: vibration_motor.h
 *
 * Description: Header file for the vibration motor driver
 *
 * Author: Smart Glasses Graduation Project Team
 *
 *******************************************************************************/ 


#ifndef VIBRATION_MOTOR_H_
#define VIBRATION_MOTOR_H_

#include "../MCAL/pwm.h"
#include "../MCAL/std_types.h"


void START_Vibration_Motor(uint8 motor_number , uint8 speed_value);


#endif /* VIBRATION_MOTOR_H_ */