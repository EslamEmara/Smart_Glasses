/******************************************************************************
 *
 * Module: I2C MASTER MODULE
 *
 * File Name: i2cmaster.h
 *
 * Description: Header file for the capacitive touch driver
 *
 * Author: Smart Glasses Graduation Project Team
 *
 *******************************************************************************/ 

#ifndef _I2CMASTER_H
#define _I2CMASTER_H   1

#include <avr/io.h>
#include "std_types.h"

#define F_CPU 1000000UL
//#endif

/* I2C clock in Hz */
#define SCL_CLOCK  100000 //100 kHz

#ifdef DOXYGEN
#if (__GNUC__ * 100 + __GNUC_MINOR__) < 304
#error "This library requires AVR-GCC 3.4 or later, update to newer AVR-GCC compiler !"
#endif
#endif /* DOXYGEN */




/** defines the data direction (reading from I2C device) in i2c_start(),i2c_rep_start() */
#define I2C_READ    1

/** defines the data direction (writing to I2C device) in i2c_start(),i2c_rep_start() */
#define I2C_WRITE   0

#define ACK    1
#define NACK   0
/**
 @brief initialize the I2C master interace. Need to be called only once 
 @param  void
 @return none
 */

/* define CPU frequency in Mhz here if not defined in Makefile */
//#ifndef F_CPU



extern void i2c_init(void);

extern void i2c_read_start(uint8 address); 

extern void i2c_write_start(uint8 address);

/** 
 @brief Terminates the data transfer and releases the I2C bus 
 @param void
 @return none
 */
extern void i2c_stop(void);


/** 
 @brief Issues a start condition and sends address and transfer direction 
  
 @param    addr address and transfer direction of I2C device
 @retval   0   device accessible 
 @retval   1   failed to access device 
 */
extern uint8 i2c_start(uint8 address ,uint8 rw);



/**
 @brief Issues a repeated start condition and sends address and transfer direction 

 @param   addr address and transfer direction of I2C device
 @retval  0 device accessible
 @retval  1 failed to access device
 */
extern uint8_t i2c_rep_start(uint8_t addr);


/**
 @brief Issues a start condition and sends address and transfer direction 
   
 If device is busy, use ack polling to wait until device ready 
 @param    addr address and transfer direction of I2C device
 @return   none
 */
extern void i2c_start_wait(uint8_t addr, uint8_t rw);

 
/**
 @brief Send one byte to I2C device
 @param    data  byte to be transfered
 @retval   0 write successful
 @retval   1 write failed
 */
extern uint8_t i2c_write(uint8_t data);


/**
 @brief    read one byte from the I2C device, request more data from device 
 @return   byte read from I2C device
 */
extern uint8_t i2c_readAck(void);

/**
 @brief    read one byte from the I2C device, read is followed by a stop condition 
 @return   byte read from I2C device
 */
extern uint8_t i2c_readNak(void);

/** 
 @brief    read one byte from the I2C device
 
 Implemented as a macro, which calls either i2c_readAck or i2c_readNak
 
 @param    ack 1 send ack, request more data from device<br>
               0 send nak, read is followed by a stop condition 
 @return   byte read from I2C device
 */
extern uint8_t i2c_read(uint8_t ack);
#define i2c_read(ack)  (ack) ? i2c_readAck() : i2c_readNak(); 


/**@}*/
#endif
