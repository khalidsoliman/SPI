/*
 * SPI.h
 *
 *  Created on: Jan 25, 2018
 *      Author: Khalid
 */

#ifndef SPI_MASTER_SPI_H_
#define SPI_MASTER_SPI_H_

#define MOSI PB5
#define SCK PB7

void SPI_Master_Init();
void SPI_Master_Transmit(unsigned char byte);

#endif /* SPI_MASTER_SPI_H_ */
