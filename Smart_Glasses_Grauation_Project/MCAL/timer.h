/******************************************************************************
 *
 * Module: TIMER
 *
 * File Name: timer.h
 *
 * Description: Header file for the AVR Timer0 driver
 *
 * Author: Salma Soliman
 *
 *******************************************************************************/

#ifndef TIMER_H_
#define TIMER_H_

#include "std_types.h"
#include "common_macros.h"
#include <avr/io.h>           /*to be able to use AVR registers*/
#include <avr/interrupt.h>


/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
typedef enum
{
	NORMAL_MODE, COMPARE_MODE
}TIMER0_MODE;

typedef enum
{
	NO_CLK_SOURCE,CLK_NO_PRESCALAR,CLK_8,CLK_64,CLK_256,CLK_1024,EXTERNAL_CLK_T0_FALLING,EXTERNAL_CLK_RISING
}TIMER0_PRESCALAR;

typedef struct
{
	TIMER0_MODE mode_config;
	uint8 intial_value;
	uint8 compare_value;
	TIMER0_PRESCALAR prescalar;
}TIMER0_CONFIG;

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
void TIMER0_init(const TIMER0_CONFIG *timer0_config_ptr);

void TIMER0_setCallBack(void(*a_ptr)(void));

void TIMER0_deinit(void);

void timer0_init();

#endif /* TIMER_H_ */
