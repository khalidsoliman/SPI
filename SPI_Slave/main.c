/*
 * main.c
 *
 *  Created on: Jan 25, 2018
 *      Author: Khalid
 */

#include <avr/io.h>
#include <util/delay.h>
#include "SPI_Slave/SPI.h"
#include "LCD/LCD.h"

int main()
{
	unsigned char Sensor_Read=0;
	SPI_Slave_Init();
	LCD_init();
	_delay_ms(1);
	LCD_Write_String("Temp = ") ;
	while (1)
	{
		Sensor_Read=SPI_Slave_Receive();
		LCD_GoTo(2,1);
		LCD_Write_Data(Sensor_Read);
		_delay_ms(500);
	}
}

