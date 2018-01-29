/*
 * SPI.c
 *
 *  Created on: Jan 25, 2018
 *      Author: Khalid
 */

#include "../SPI_Slave/SPI.h"

#include <avr/io.h>
#include <util/delay.h>

void SPI_Slave_Init()
{
	// MISO pin is OUT , SCK is Input pin
	DDRB |=  (1<<PB6);

	// SPCR (Control Register)
	SPCR |= (1<<SPE)|(1<<SPR0)|(1<<SPR1);
}
unsigned char SPI_Slave_Receive()
{
	// Wait for reception complete
	while((!SPSR&(1<SPIF)));

	// Return data register
	return SPDR;
}

