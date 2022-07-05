/******************************************************************************
 * File Name: main.c
 *
 * Description: Source file for Application layer Functions
 *
 * Author: Smart Glasses Graduation Project Team
 *
 *******************************************************************************/


#ifndef APP_H_
#define APP_H_

#define F_CPU 1000000UL
#include <util/delay.h>

#include "../MCAL/adc.h"
#include "../MCAL/std_types.h"
#include "../MCAL/uart.h"
#include "../MCAL/timer.h"

#include "../MCAL/pwm.h"
#include "../HAL/vibration_motor.h"
#include "../HAL/capacitive_touch.h"



typedef enum
{
	OFF,LEVEL_ONE,LEVEL_TWO,LEVEL_THREE
}MOTOR_Sensitivity_Level;


void INIT_Fucntions(void);
void Motion_Detection_Vibration(void);
void CAPACITIVE_Touch_Patterns(void);


#endif /* APP_H_ */