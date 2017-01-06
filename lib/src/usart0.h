#ifndef USART0_H_
#define USART0_H_

//#include <avr/io.h>
#include <stdint.h>

/* USART0 mode */
#define USART0_NORMAL_ASYNCHRONOUS               0x00
#define USART0_DOUBLE_SPEED_ASYNCHRONOUS         0x01
#define USART0_MASTER_SYNCHRONOUS                0x02
#define USART0_SLAVE_SYNCHRONOUS                 0x03
#define USART0_MASTER_SPI                        0x04 

/* BUAD RATE FACTORS */
#define USUART0_NORMAL_ASYNC_FACTOR              0.0625
#define USUART0_DOUBLE_ASYNC_FACTOR              0.125
#define USUART0_SYNC_FACTOR                      0.5

/* USART frame formats
 * First digit after FF (frame format) is number 
 * of start bits (1), Second digit is number
 * of data bits (5 - 9), third digit is parity
 * (0=none, 1=odd, 2=even), fourth digit is number
 * of stop bits (1 or 2) */
#define USART0_FF1501                            0x00
#define USART0_FF1601                            0x01
#define USART0_FF1701                            0x02
#define USART0_FF1801                            0x03
#define USART0_FF1901                            0x04
#define USART0_FF1511                            0x05
#define USART0_FF1611                            0x06
#define USART0_FF1711                            0x07
#define USART0_FF1811                            0x08
#define USART0_FF1911                            0x09
#define USART0_FF1521                            0x0A
#define USART0_FF1621                            0x0B
#define USART0_FF1721                            0x0C
#define USART0_FF1821                            0x0D
#define USART0_FF1921                            0x0E
#define USART0_FF1502                            0x0F
#define USART0_FF1602                            0x10
#define USART0_FF1702                            0x11
#define USART0_FF1802                            0x12
#define USART0_FF1902                            0x13
#define USART0_FF1512                            0x14
#define USART0_FF1612                            0x15
#define USART0_FF1712                            0x16
#define USART0_FF1812                            0x17
#define USART0_FF1912                            0x18
#define USART0_FF1522                            0x19
#define USART0_FF1622                            0x1A
#define USART0_FF1722                            0x1B
#define USART0_FF1822                            0x1C
#define USART0_FF1922                            0x1D

/* interrupt enabled combinations */
/* recieve complete interrupt enable */
#define USART0_RXCIE                              0x01 
/* transmit complete interrupt enable */
#define USART0_TXCIE                              0x01
/* data register empty interrupt enable */
#define USART0_DREIE                              0x01

/* interrupt disabled combinations */
/* recieve complete interrupt disable */
#define USART0_RXCID                              0x00 
/* transmit complete interrupt disable */
#define USART0_TXCID                              0x00
/* data register empty interrupt disable */
#define USART0_DREID                              0x00

typedef struct USART0_USART0_Config
{
  uint8_t mode;
  uint32_t baudRate;
  uint8_t frameFormat;
} USART0_Config;

/* USART0 module initialization */
extern uint8_t USART0_initModule (const USART0_Config *config);
extern uint8_t USART0_setBaud(uint32_t baud, double bf);
/* interrupt enable/disable for Rx, Tx, and tranmsit buffer empty */
extern void USART0_interrupts(uint8_t rxi, uint8_t txi, uint8_t dri);
extern void USART0_transmitData(uint8_t data);
extern void USART0_transmitData9(uint16_t data);
extern uint8_t USART0_receiveData();
extern uint16_t USART0_receiveData9();


#endif
