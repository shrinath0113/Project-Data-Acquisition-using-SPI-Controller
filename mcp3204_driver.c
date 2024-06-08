/* mcp3204_driver */

#include<LPC21XX.H>
#include "header.h"

u16 read_mcp3204(u8 ch_num)
{
	u8 byteL=0,byteH=0;
	u16 result=0;
	ch_num<<=6;					// set the ch_num
	IOCLR0=CS0;					// select slave
	spi0(0x06);					// start bit , SGL mode , D2
	byteH=spi0(ch_num);			// channel select
	byteL=spi0(0x00);
	IOSET0=CS0;					// diselect slave
	byteH&=0x0F;				// mask higher nibble
	result=(byteH<<8)|byteL;	//merge result
	return result;	
}
