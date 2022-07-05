/******************************************************************************
 * File Name: main.c
 *
 * Description: Source file for Application layer
 *
 * Author: Smart Glasses Graduation Project Team
 *
 *******************************************************************************/
#include "APP.h"



void INIT_Fucntions(void)
{
	ADC_ConfigType adc_configuration = {INTERNAL_256VOLT,FCPU_2} , *adc_configuration_ptr = &adc_configuration;
	TIMER0_CONFIG *tconfig = {COMPARE_MODE,0,250,CLK_NO_PRESCALAR};
	ADC_init(adc_configuration_ptr);
	uart_init();
	UART_sendString("eshta8al");
	timer0_init();
	_delay_ms(2000);
}


void Motion_Detection_Vibration(void)
{
		uint8 counter = 0 ,distance, motor_speed;
		MOTOR_Sensitivity_Level sensitivity = LEVEL_ONE;
		
		
				for(counter = 0 ; counter<=2 ; counter++)
				{
					/*FIRST WE NEED TO GET THE DISTANCE FROM EACH IR SENSOR WHERE:
					LEFT IR SENSOR --> ADC CHANNEL 0
					FRONT IR SENSOR --> ADC CHANNEL 1
					RIGHT IR SENSOR --> ADC CHANNEL 2*/
					
					distance = IR_getDistance(2);
					UART_sendByte(distance);
					_delay_ms(1000);
					
					/*THIS CASE IF WE WANT THE VIBRATION INTENISTY AS A FUNCTION OF DISTANCE*/
					/*if(sensitivity == OFF)
					{
						motor_speed = 0;
					}
					else if(sensitivity == LEVEL_ONE)
					{
						motor_speed = 70 - distance;
					}
					else if(sensitivity == LEVEL_TWO)
					{
						motor_speed = 70 - distance;	
						motor_speed += motor_speed * 0.2; 
					}
					else if(sensitivity == LEVEL_THREE)
					{
						motor_speed = 70 - distance;
						motor_speed += motor_speed * 0.3;

					}
					*/
					
					/*STARTING VIBRATION MOTOR WITH WANTED SPEED */
					START_Vibration_Motor(counter,70-distance);
				}
}

void CAPACITIVE_Touch_Patterns(void)
{
	static uint16 front_counter, left_counter,right_counter;
	static uint8 right_flag, left_flag;
	
	if(CAP_isLeftTouched() == 1)
	{
		
		left_counter += 100;
		_delay_ms(100);
		
		if(right_flag == 0)
		{
			left_flag = 1;
		}

	}
	if(CAP_isMiddleTouched() == 1)
	{
		front_counter += 100;
		_delay_ms(100);
	}
	if(CAP_isRightTouched() == 1)
	{
		right_counter += 100;
		_delay_ms(100);
		
		if(left_flag == 0)
		{
			right_flag = 1;
		}
	}
	
	/*****************************************      PATTERN CASES     ******************************************/
	
	if((left_counter == 100) && (front_counter == 100 ) && (right_counter == 100 ) )
	{
		
		if(right_flag == 1)
		{
						UART_sendString(" up");

			//VOLUME UP
			right_flag = 0;
		}
		else if(left_flag == 1)
		{
						UART_sendString(" down");

			//VOLUME DOWN
			left_flag = 0;
		}
		left_counter = 0;
		front_counter = 0;
		right_counter = 0;
	}
	else
	{
			/*FOR THE HOLD CASE OR THE ONE TOUCH CASE FOR LEFT BUTTON*/
			if((left_counter == 100) && (CAP_isLeftTouched() == 0))
			{
				
				// INCREASE SENSITIVITY
				UART_sendString(" yrab iNCREASE SENSITIVITY#");
				left_counter = 0;
				left_flag = 0;

			}
			else if((left_counter >= 5000) && (CAP_isLeftTouched() == 0))
			{
				//SEND CURRENT LOCATION
				UART_sendString(" SEND CURRENT LOCATION#");

				left_counter = 0;
				left_flag = 0;
			}

			/*FOR THE HOLD CASE OR THE ONE TOUCH CASE FOR MIDDLE BUTTON*/

			if((front_counter == 100) && (CAP_isMiddleTouched() == 0))
			{
				// SPEECH ASSISTANT
				UART_sendString(" SPEECH ASSISTANT#");
				front_counter = 0;
			}
			else if((front_counter >= 5000) && (CAP_isMiddleTouched() == 0))
			{
							UART_sendString(" emer call");

				// EMERGENCY CALL
				front_counter = 0;
			}
			/*FOR THE HOLD CASE OR THE ONE TOUCH CASE FOR RIGHT BUTTON*/

			if((right_counter == 100 ) && (CAP_isRightTouched() == 0))
			{
							UART_sendString(" dec sens");

				// DECREASE SENSITIVITY
				right_counter = 0;
				right_flag = 0;
			}
			else if((right_counter >= 5000) && (CAP_isRightTouched() == 0))
			{
							UART_sendString(" ocr");

				//OCR
				right_counter = 0;
				right_flag = 0;
			}
	}
}