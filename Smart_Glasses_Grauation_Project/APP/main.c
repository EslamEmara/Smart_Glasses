/******************************************************************************
 * File Name: main.c
 *
 * Description: Source file for Application layer
 *
 * Author: Smart Glasses Graduation Project Team
 *
 *******************************************************************************/



#include "APP.h"
uint16 tot_overflow;
uint16 tot_overflow1;
uint16 tot_overfloww;

int main(void)
{
	uint8_t left= 0,mid = 0,right = 0;
	uint16 start_time = 0;
		uint16 start_time1 = 0;

	uint8 swipe = 0;
		uint8 swipe1 = 0;

		INIT_Fucntions();	
    while(1)
    {		
		
		
		UART_sendByte(IR_getDistance(2));
		
		/*if (tot_overflow > 4000){
			UART_sendString(" 1");
			tot_overflow = 0;
		}*/
		//Motion_Detection_Vibration();
		//CAPACITIVE_Touch_Patterns();
		/*if (CAP_isLeftTouched() == 1){
			left = 1;
			tot_overflow = 0;
		}
		if(CAP_isMiddleTouched() == 1){
			mid  =1;
		}
		if(CAP_isRightTouched() == 1){
			right = 1;		
			tot_overflow1 = 0;	
		}
		
		
		
		
		if (tot_overflow < 4000 && left == 1){
			
			if (mid == 1){
				tot_overfloww = 0;
				if (tot_overfloww < 2000 && right == 1){
					UART_sendString("SWIPE");
					right = 0;
					left = 0;
					mid = 0;
				}
				
			}
		}
		
		if (tot_overflow > 8000){
			right = 0;
			left = 0;
			mid = 0;
		}*/
}
	}