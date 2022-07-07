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
    ADC_ConfigType adc_configuration = {INTERNAL_256VOLT,FCPU_64} , *adc_configuration_ptr = &adc_configuration;
	ADC_init(adc_configuration_ptr);
	uart_init();
	timer0_init();
}


void Motion_Detection_Vibration(void)
{
	uint8 distance,motor_number;
	for(motor_number = 0 ; motor_number <=2 ; motor_number++)
	{
		distance = IR_getDistance(motor_number);
		if (distance >= 10 && distance < 20)
		{
			START_Vibration_Motor(motor_number , 100);
		}
		else if (distance >= 20 && distance < 30)
		{
			START_Vibration_Motor(motor_number , 60);
			
		}
		else if(distance >= 30 && distance < 40){
			START_Vibration_Motor(motor_number , 30);
		}
		else if(distance >= 40 && distance < 50){
			START_Vibration_Motor(motor_number , 15);
		}
		else{
			START_Vibration_Motor(motor_number , 0);
		}
		//START_Vibration_Motor(motor_number , 0);
		_delay_ms(50);

	}
	//distance = IR_getDistance(0);
	//START_Vibration_Motor(0 , 50 - distance);
	//distance = IR_getDistance(1);
	//START_Vibration_Motor(1 , 50 - distance);
}

void CAPACITIVE_Touch_Patterns(void)
{	static uint8_t left= 0,middle = 0,right = 0;
	static uint8_t swipeRight = 0;
	static uint8_t swipeLeft =0;
	
	if (CAP_isLeftTouched()&&left==0){
		left = 1;
		tot_overflow = 0;
	}
	if (CAP_isMiddleTouched()&&middle==0){
		middle =1;
		tot_overflow2=0;
	}
	if(CAP_isRightTouched()&&right==0){
		right =1;
		tot_overflow1 =0;
	}
	
	if (left == 1 && swipeRight ==0){
		swipeLeft = 1;
		if (tot_overflow < 6000){
			if (middle && right){
				UART_sendString(" swipeLEFT ");
				while(CAP_isRightTouched());
				left =0;
				right = 0;
				middle =0;
				swipeLeft =0;
			}
		}
		else{
			if(CAP_isLeftTouched()){
				if(tot_overflow > 12000){
					UART_sendString("HOLD LEFT");
					while(CAP_isLeftTouched());
					left=0;
					swipeLeft =0;

				}
				
			}
			else {
				UART_sendString("LEFT CLICK");
				left =0;
				swipeLeft =0;

			}
		}
	}
	
	
	if (right == 1 && swipeLeft ==0){
		swipeRight = 1;
		if (tot_overflow1 < 6000){
			if (middle && left){
				UART_sendString(" swipeRight ");
				while(CAP_isLeftTouched());
				left =0;
				right = 0;
				middle =0;
				swipeRight =0;
			}
		}
		else{
			if(CAP_isRightTouched()){
				if(tot_overflow1 > 12000){
					UART_sendString(" HOLD RIGHT ");
					while(CAP_isRightTouched());
					right=0;
					swipeRight =0;

				}
				
			}
			else {
				UART_sendString(" Right CLICK ");
				right =0;
				swipeRight =0;
			}
		}
	}
	
	if(middle == 1 && left ==0 &&right==0){
		if (tot_overflow2 > 2000){
			if (CAP_isMiddleTouched()){
				if(tot_overflow2>12000){
					UART_sendString(" MIDDLE HOLD ")	;
					while(CAP_isMiddleTouched());
					middle =0;
				}
			}
			else{
				UART_sendString("MIDDLE");
				middle =0;
			}
		}
	}
	if (tot_overflow1 > 16000 && tot_overflow > 16000){
		left =0;
		right = 0;
		middle =0;
		swipeRight =0;
		swipeLeft =0;
		tot_overflow1 =0;
		tot_overflow =0;
	}
	
}