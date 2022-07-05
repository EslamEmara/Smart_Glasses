/******************************************************************************
 *
 * Module: UART MODULE
 *
 * File Name: uart.c
 *
 * Description: Source file for the UART MODULE
 *
 * Author: Smart Glasses Graduation Project Team
 *
 *******************************************************************************/

#include "uart.h"
#include "std_types.h"
#include <avr/io.h>
// function to initialize UART
void uart_init (void)
{
	UBRRH = (BAUDRATE>>8);                      // shift the register right by 8 bits
	UBRRL = BAUDRATE;                           // set baud rate
	UCSRB|= (1<<TXEN)|(1<<RXEN);                // enable receiver and transmitter
	UCSRC|= (1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);   // 8bit data format
}

void UART_sendByte (uint8 data)
{
	while (!( UCSRA & (1<<UDRE)));                // wait while register is free
	UDR = data;                                   // load data in the register
}
// function to receive data
uint8 UART_recieveByte (void)
{
	while(!(UCSRA) & (1<<RXC));                   // wait while data is being received
	return UDR;                                   // return 8-bit data
}



void UART_sendString(const uint8 *Str)
{
	uint8 i = 0;

	/* Send the whole string */
	while(Str[i] != '\0')
	{
		UART_sendByte(Str[i]);
		i++;
	}
	
}


void UART_receiveString(uint8 *Str)
{
	uint8 i = 0;

	/* Receive the first byte */
	Str[i] = UART_recieveByte();

	/* Receive the whole string until the '#' */
	while(Str[i] != '#')
	{
		i++;
		Str[i] = UART_recieveByte();
	}

	/* After receiving the whole string plus the '#', replace the '#' with '\0' */
	Str[i] = '\0';
}