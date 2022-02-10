#ifndef _SPI_466_H_INCLUDED_
#define _SPI_466_H_INCLUDED_
#include <stdint.h>

#define LOW (0)
#define HIGH (1)
#define FEATURE_BITBANG_SPI

#ifdef FEATURE_BITBANG_SPI
#define CS_PIN   17  /* GPIO17 */
#define CLK_PIN  18  /* GPIO18 */
#define MOSI_PIN 19  /* GPIO19 */
#define MISO_PIN 16  /* GPIO16 */
#endif


void    mSpiInit(void);
void    mSpiStart(void);
void    mSpiComplete(void);
uint8_t mSpiTransfer( uint8_t outData);


#endif  // _SPI_466_H_INCLUDED_
