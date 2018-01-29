/*
 * ADC.c
 *
 *  Created on: Jan 19, 2018
 *      Author: A7med
 */

#include "ADC.h"
#include <avr/io.h>
void ADC_Init()
{
	DDRA =0x00;          // 1- Make port input
	ADCSRA|=(1<<ADEN);   // 2- Enable ADC
	ADCSRA|=(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0); //PreScaler

}

unsigned int ADC_READ(unsigned char channel)
{
	ADMUX=channel; //Select ADC channel
	ADMUX|=(1<<REFS0);  // Select Vref ----> Vcc = +5v
	ADCSRA|=(1<<ADSC); // Start conversion  ADC
	while(!(ADCSRA&(1<<ADIF))); // Wait till conversion complete
	ADCSRA|=(1<<ADIF); // Clear ADIF
	return ADC ;  // return ADC
}
