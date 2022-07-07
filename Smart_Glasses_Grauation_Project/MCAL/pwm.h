/******************************************************************************
 *
 * Module: PWM Module
 *
 * File Name: pwm.h
 *
 * Description: Header file for the AVR PWM Module
 *
 * Author: Smart Glasses Graduation Project Team
 *
 *******************************************************************************/


#ifndef PWM_H_
#define PWM_H_

#include <avr/io.h>
#include "gpio.h"
#include "std_types.h"

#define PERCENTAGE 100
#define MAX_COMPARE_NUMBER 0XFF
void PWM_Timer1_A_Start(uint8 duty_cycle);
void PWM_Timer1_B_Start(uint8 duty_cycle);
void PWM_Timer2_Start(uint8 duty_cycle);


#endif /* PWM_H_ */