/*
 * SPI.c
 *
 *  Created on: Jan 25, 2018
 *      Author: Khalid
 */

#include "SPI.h"
#include <avr/io.h>
#include <util/delay.h>

void SPI_Master_Init()
{
	// MOSI pin is OUT , SCK is OUT pin
	DDRB |= (1<<PB5) | (1<<PB7);
	// MISO pin is Input
	DDRB &= ~(1<<PB6);

	// SPCR (Control Register) $ PreScaler F_CPU/128
	SPCR=(1<<SPE)|(1<<MSTR)|(1<<SPR0)|(1<<SPR1);
}

void SPI_Master_Transmit(unsigned char byte)
{
	SPDR = byte;

	// Wait for transmission complete
	while((!SPSR & (1<<SPIF)));
}
