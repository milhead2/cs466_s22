#ifndef _MGPIO_466__H_INCLUDED_
#define _MGPIO_466__H_INCLUDED_
#include <stdint.h>

#define IODIRA   0x00
#define IODIRB   0x01
#define IPOLA    0x02
#define IPOLB    0x03
#define GPINTENA 0x04
#define GPINTENB 0x05
#define DEFVALA  0x06
#define DEFVALB  0x07
#define INTCONA  0x08
#define INTCONB  0x09
#define IOCONA   0x0a
#define IOCONB   0x0b
#define GPPUA    0x0c
#define GPPUB    0x0d
#define INTFA    0x0e
#define INTFB    0x0f
#define INTCAPA  0x10
#define INTCAPB  0x11
#define GPIOA    0x12
#define GPIOB    0x13
#define OLATA    0x14
#define OLATB    0x15

void    mGpioInit(void);
void    mGpioWriteByte(uint8_t byte, uint8_t address);
uint8_t mGpioReadByte(uint8_t address);


#endif // _MGPIO_466__H_INCLUDED_
