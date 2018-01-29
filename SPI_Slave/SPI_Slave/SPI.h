/*
 * SPI.h
 *
 *  Created on: Jan 25, 2018
 *      Author: Khalid
 */

#ifndef SPI_SLAVE_SPI_H_
#define SPI_SLAVE_SPI_H_

#define MISO PB6
#define SS PB4


void SPI_Slave_Init();
unsigned char SPI_Slave_Receive();

#endif /* SPI_SLAVE_SPI_H_ */
