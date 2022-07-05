/******************************************************************************
 *
 * Module: VIBRATION MOTOR
 *
 * File Name: vibration_motor.c
 *
 * Description: Source file for the vibration motor driver
 *
 * Author: Smart Glasses Graduation Project Team
 *
 *******************************************************************************/ 

#include "vibration_motor.h"

void START_Vibration_Motor(uint8 motor_number , uint8 motor_speed)
{
	switch(motor_number)
	{
		case 0 : PWM_Timer1_A_Start(motor_speed); break;
		case 1 : PWM_Timer2_Start(motor_speed); break;
		case 2 : PWM_Timer1_B_Start(motor_speed); break;
	}
}
