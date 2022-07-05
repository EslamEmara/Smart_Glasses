/******************************************************************************
 *
 * Module: UART MODULE
 *
 * File Name: uart.h
 *
 * Description: Header file for the UART MODULE
 *
 * Author: Smart Glasses Graduation Project Team
 *
 *******************************************************************************/


#ifndef UART_H_
#define UART_H_

#define F_CPU 1000000UL

#include "std_types.h"
#define BAUD 2400                                   // define baud
#define BAUDRATE ((F_CPU)/(BAUD*16UL)-1)            // set baud rate value for UBRR

void uart_init (void);
void UART_sendByte (unsigned char data);
uint8 UART_recieveByte (void);
void UART_sendString(const uint8 *Str);
void UART_receiveString(uint8 *Str);




#endif /* UART_H_ */