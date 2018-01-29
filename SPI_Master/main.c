/*
 * main.c
 *
 *  Created on: Jan 25, 2018
 *      Author: Khalid
 */

#include <avr/io.h>
#include <util/delay.h>
#include "SPI_Master/SPI.h"
#include "ADC/ADC.h"

int main()
{
	long Sensor = 0;
	ADC_Init();
	SPI_Master_Init();
	while(1)
	{
		Sensor = ADC_READ(0);
		Sensor *= 500;
		Sensor /=1023;
		SPI_Master_Transmit((unsigned char)Sensor);
	}
}
