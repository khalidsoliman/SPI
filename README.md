# SPI
SPI - Serial Peripheral Interface - / Atmega32

## Full-duplex, Three-wire Synchronous Data Transfer
## One Master , Multiple Slaves
## MSB First Data Transfer

## APIs
### Master 
#### void SPI_Master_Init();
#### void SPI_Master_Transmit(unsigned char byte);

### Slave 
#### void SPI_Slave_Init();
#### unsigned char SPI_Slave_Receive();
