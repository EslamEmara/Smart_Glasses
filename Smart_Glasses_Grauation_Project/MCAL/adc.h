/******************************************************************************
 *
 * Module: ADC MODULE
 *
 * File Name: adc.h
 *
 * Description: Header file for the ADC MODULE
 *
 * Author: Smart Glasses Graduation Project Team
 *
 *******************************************************************************/
#ifndef ADC_H_
#define ADC_H_
#include "common_macros.h"
#include "std_types.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC0_CHANNEL_ID   0B0000
#define ADC1_CHANNEL_ID   0B0001
#define ADC2_CHANNEL_ID   0B0010
#define ADC3_CHANNEL_ID   0B0011
#define ADC4_CHANNEL_ID   0B0100
#define ADC5_CHANNEL_ID   0B0101
#define ADC6_CHANNEL_ID   0B0110
#define ADC7_CHANNEL_ID   0B0111

//extern volatile uint16 data;

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
typedef enum
{
	AREF_INTERNAL_VREF,AVCC_EXTERNAL_AREF,RESERVED,INTERNAL_256VOLT

}ADC_ReferenceVolatge;

typedef enum
{
	FCPU_2,FCPU_22,FCPU_4,FCPU_8,FCPU_16,FCPU_32,FCPU_64,FCPU_128

}ADC_Prescaler;

typedef struct
{
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;

}ADC_ConfigType;

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
/*Description:
 * inputs: functiOn takes a pointer to structure of type ADC_ConfigType
 * that contains the pre-scalar value and the VREF option*/
void ADC_init(const ADC_ConfigType * Config_Ptr);
/*Description:
 *function takes the channel number which is previously defined in this h file
 *function to choose which channel will be read from ADC0 to ADC7*/
uint16 ADC_readChannel(uint8 Ch_num);

#endif /* ADC_H_ */
