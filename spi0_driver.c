/* spi0_driver */

#include<LPC21XX.H>
#include "header.h"

void spi0_init(void)
{
	PINSEL0|=0x1500;		// P0.4 -> SCK0
							// P0.5 -> MISO0
							// P0.6 -> MOSI0
	IODIR0|=CS0;			// P0.7 -> Is out dir
	IOSET0=CS0;				// deselect slave
	S0SPCR=0x20;			// CPOL=CPHA=0
							// select master first
							// select MSB first
	S0SPCCR=15;				// SPI clock is 1MBPS					 
}

/* SPI0 data transfer function */
#define SPIF ((S0SPSR>>7)&1)
u8 spi0(u8 data)
{
	S0SPDR=data;
	while(SPIF==0);
	return S0SPDR;
}
