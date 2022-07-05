/******************************************************************************
 *
 * Module: ADC MODULE
 *
 * File Name: adc.c
 *
 * Description: Source file for the ADC MODULE
 *
 * Author: Smart Glasses Graduation Project Team
 *
 *******************************************************************************/

#include <avr/io.h>
#include "adc.h"

void ADC_init(const ADC_ConfigType * Config_Ptr)
{
	ADMUX = ((Config_Ptr->ref_volt)<<6);
    /*ADMUX = (1<<REFS0) | (1<<REFS1);*/

	  /*
	  internal 2.56 voltage reference --> REFS1=1 REFS0=1
	  WRITE ADC FROM LOW TO HIGH --> ADLAR=0
	  ADC MODULE WORKS ON ADC --> MUX = 00000
	  */
    CLEAR_BIT(ADCSRA,ADIE); /*disables the interrupt */

    /*CHOSSING PRESCALE BASED ON ENUM TYPE CALLED PRESCALER*/
    ADCSRA = (ADCSRA & 0XF8) | (Config_Ptr->prescaler);
	CLEAR_BIT(ADCSRA,ADFR);

    //SET_BIT(ADCSRA,ADPS0);/*adjust clk as FCPU/8 */
    //SET_BIT(ADCSRA,ADPS1);/*adjust clk as FCPU/8 */
    //CLEAR_BIT(ADCSRA,ADPS2);/*adjust clk as FCPU/8 */

    SET_BIT(ADCSRA,ADEN); /*enables ADC*/


}

uint16 ADC_readChannel(uint8 Ch_num)
{
		uint16 data;
		ADMUX = (ADMUX & 0xF0) | Ch_num; /*PUT CH_NUM IN THE FIRST 4 BITS OF ADMUX */
		SET_BIT(ADCSRA,ADSC);
		while(BIT_IS_CLEAR(ADCSRA,ADIF));
		SET_BIT(ADCSRA,ADIF); /*CLEARING THE BIT BY WRITING 1 TO IT*/
		data = ADC;
		return data;
}
