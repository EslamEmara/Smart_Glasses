/******************************************************************************
 *
 * Module: PWM Module
 *
 * File Name: pwm.c
 *
 * Description: Source file for the AVR PWM Module
 *
 * Author: Smart Glasses Graduation Project Team
 *
 *******************************************************************************/

#include "pwm.h"
#include "gpio.h"
#include <avr/io.h>

void PWM_Timer1_A_Start(uint8 duty_cycle)
{
	
		GPIO_setupPinDirection(PORTB_ID,PIN1_ID,PIN_OUTPUT); /*PB3 as output to generate PWM from it "OC1A"*/
		/*for configuring the PWM for timer1 to */

		TCCR1A = (1<<COM1A1) | (1<< COM1B1) | (1<<WGM10);
		//CLEAR_BIT(TCCR1A,FOC1A);
		//CLEAR_BIT(TCCR1A,FOC1B);
		TCCR1B = (1<< WGM12)  | (1<<CS10); //|  (1<<CS12)
		//TCNT1 = 0;
	    OCR1A = (uint8) ((duty_cycle  *  MAX_COMPARE_NUMBER) / PERCENTAGE);
}

void PWM_Timer1_B_Start(uint8 duty_cycle)
{
		GPIO_setupPinDirection(PORTB_ID,PIN2_ID,PIN_OUTPUT); /*PB2 as output to generate PWM from it "OC1B"*/
		TCCR1A = (1<<COM1A1) | (1<< COM1B1) | (1<<WGM10);
		TCCR1B = (1<< WGM12) | (1<<CS10);	//|  (1<<CS12) 	
		//TCNT1 = 0;
		OCR1B = (uint8) ((duty_cycle  *  MAX_COMPARE_NUMBER) / PERCENTAGE);
}

void PWM_Timer2_Start(uint8 duty_cycle)
{
	GPIO_setupPinDirection(PORTB_ID,PIN3_ID,PIN_OUTPUT); /*PB3 as output to generate PWM from it "OC2"*/
	/*configuring timer0 to:
	 * 1.work as FAST PWM generator -->WGM20=1 WGM21=1
	 * 2.non inverting mode --> COM20=0 COM21=1
	 * 3. compare value depends on duty cycLe given from function
	 * 4.FCPU/1024 PRESCALAR-->  CS20=1 CS21=1 CS22=1
	 * */
	TCCR2 = (1<<WGM20) | (1<<WGM21) | (1<<COM21) | (1<<CS20) ; //| (1<<CS21) | (1<<CS22)
	//TCNT2 = 0;

	/*INTIATING THE TIMER2 COUNTER REGISTER TO ZERO TO START COUNTING FRM ZERO*/

    OCR2 =(uint8) ((duty_cycle  *  MAX_COMPARE_NUMBER) / PERCENTAGE);
}

