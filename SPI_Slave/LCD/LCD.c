/*
 * LCD.c
 *
 *  Created on: Jan 3, 2018
 *      Author: Khalid
 */
#include "LCD.h"
#include <avr/io.h>
#include <util/delay.h>

#define set_bit(reg,pin) reg|=(1<<pin)
#define clear_bit(reg,pin) reg&=~(1<<pin)

static int toggle_counter = 0;
static int curcor_counter = 0;

void LCD_EN()
{
	set_bit(PORTC,7);
	_delay_ms(1);
	clear_bit(PORTC,7);
	_delay_ms(1);
}
void LCD_Write_CMD(unsigned char CMD)
{
	clear_bit(PORTC,6);
	_delay_ms(1);
	LCD_PORT&=0x0F;
	LCD_PORT |=(CMD&0xF0) ;
	_delay_ms(1);
	LCD_EN();
	LCD_PORT&=0x0F;
	LCD_PORT |=((CMD<<4)&0xF0);
	_delay_ms(1);
	LCD_EN();
	_delay_ms(1);
	if (CMD==0x01)	curcor_counter = 0;

}
void Toggle_Curcor_Pos()
{
	LCD_Write_CMD(0x80);
	curcor_counter++;
	if(curcor_counter==16)
	{
		LCD_Write_CMD(0xC0);
		curcor_counter=0;
		toggle_counter++;
	}
	if(toggle_counter==2)
	{
		LCD_Write_CMD(0x80);
		toggle_counter=0;
	}
}
void LCD_init()
{
	LCD_DDR=0xff; // Make PORT output
	LCD_PORT=0;   // Init PORT
	////////////////////////////////////////
	_delay_ms(1);
	DDRC|=(1<<6);   // Make RS Output
	PORTC&=~(1<<6); // Init RS " Command mode "
	_delay_ms(1);
	DDRC|=(1<<7);   // Make EN Output
	PORTC&=~(1<<7); // Init EN
	_delay_ms(1);
	LCD_Write_CMD(0x01); // Clear All Display Data
	_delay_ms(1);
	LCD_Write_CMD(0x28); // 4 bit mode 5*8 dispaly  2 line
	_delay_ms(1);
	LCD_Write_CMD(0x02); // Return Home
	_delay_ms(1);
	LCD_Write_CMD(0x0E); // Display on-Cursor on-Blink off
	_delay_ms(1);
	LCD_Write_CMD(0x06); // after every character cursor will move to right
	_delay_ms(1);
}



void LCD_Write_Data (unsigned char Data)
{
	set_bit(PORTC,6);
	_delay_ms(1);
	LCD_PORT&=0x0F;
	LCD_PORT |=(Data&0xF0) ;
	_delay_ms(1);
	LCD_EN();
	_delay_ms(1);
	LCD_PORT&=0x0F;
	LCD_PORT |=((Data<<4)&0xF0);
	_delay_ms(1);
	LCD_EN();
	Toggle_Curcor_Pos();
	_delay_ms(1);
}

void LCD_Write_String(char *string)
{
	while(*string!='\0')
	{
		LCD_Write_Data(*string);
		string ++;
	}
}


void LCD_GoTo(unsigned char posX,unsigned char posY)
{
	unsigned char curcor_pos[] = {0x80,0xC0};
	LCD_Write_CMD(curcor_pos[posX-1]+posY-1);
}
