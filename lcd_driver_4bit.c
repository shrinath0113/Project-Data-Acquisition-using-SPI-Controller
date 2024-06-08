// LCD driver for 4-bit 
/*-------------Rhydolabz Board-----------------*/

#include<LPC21XX.H>
#include "header.h"
#define RS (1<<17)
#define	RW (1<<18)
#define EN (1<<19)

#define PIN 0x00FE0000

void lcd_data(unsigned char data){
	unsigned int temp;
	IOCLR1=PIN;
	temp=(data & 0xF0)<<16;
	IOSET1=temp;
	IOSET1=RS;
	IOCLR1=RW;
	IOSET1=EN;
	delay_ms(2);
	IOCLR1=EN;

	IOCLR1=PIN;
	temp=(data & 0x0F)<<20;
	IOSET1=temp;
	IOSET1=RS;
	IOCLR1=RW;
	IOSET1=EN;
	delay_ms(2);
	IOCLR1=EN;
}

void lcd_cmd(unsigned char cmd){
	unsigned int temp;
	IOCLR1=PIN;
	temp=(cmd & 0xF0)<<16;
	IOSET1=temp;
	IOCLR1=RS;
	IOCLR1=RW;
	IOSET1=EN;
	delay_ms(2);
	IOCLR1=EN;

	IOCLR1=PIN;
	temp=(cmd & 0x0F)<<20;
	IOSET1=temp;
	IOCLR1=RS;
	IOCLR1=RW;
	IOSET1=EN;
	delay_ms(2);
	IOCLR1=EN;
}
				 
void lcd_init(void)
{
IODIR1=PIN;
IOCLR1=EN;
PINSEL2=0x0;
lcd_cmd(0x01);
lcd_cmd(0x02);
lcd_cmd(0x28);
lcd_cmd(0x0E);
lcd_cmd(0x01);
}

void lcd_string(signed char *ptr)
{
	while(*ptr!=0)
	lcd_data(*ptr++);
//	ptr++;
}

// u8 a[8]={0x0,0xa,0xa,0x0,0x0,0x11,0xe,0x0};			// .. _
// u8 a[8]={0xE,0x11,0x10,0xe,0x1,0x11,0xe,0x0};		// S
u8 a[8]={0x1C,0x14,0x1C,0x00,0x00,0x00,0x00,0x00};		// degree Celcius

void lcd_cgram(void)
{
	int i;
	lcd_cmd(0x40);
		for(i=0;i<=7;i++)
		{
			lcd_data(a[i]);
		}
}

  	

void lcd_atoi(int num)
{
int i=0;
char a[10];

	if(num==0){
	lcd_data('0');
	return;
	}
	if(num < 0)
	{
	num=-num;
	lcd_data('-');
	}
	while(num>0){
	a[i]=(num%10)+48;
	i++;
	num/=10;
	}
	for(i--;i>=0;i--)
	lcd_data(a[i]);	
}

void lcd_atof(float f)
{
int temp,temp1,i,l;
char a[16];
	if(f==0)
	{
	lcd_string("0.000000");
	return;
	}

	if(f<0)
	{
	lcd_data('-');
	f=-f;
	}

	temp=f;
	if(temp==0)
	{
	lcd_data('0');
	}
	else
	{
		for(l=0,temp1=temp;temp1;temp1=temp1/10,l++);
		l--;

		for(temp1=temp,i=0;temp1;temp1=temp1/10,i++)
		{
			a[i]=(temp1%10)+48;
		}

		for(i=l;i>=0;i--)
		{
			lcd_data(a[i]);
		}
	}

	lcd_data('.');

	temp=(f-temp)*1000000;
	if(temp==0)
	{
		lcd_string("000000");
	}
	else
	{
		for(i=0;temp;temp=temp/10,i++)
		{
			a[i]=(temp%10)+48;
		}
		for(i=5;i>=0;i--)
		{
			lcd_data(a[i]);
		}
	}
}
	 
/*
void lcd_atof(float f)
{
	int i,num;
	char a[10];

	if(f==0){
	lcd_string("0.000000");
	return;
	}

	if(f<0){
	lcd_data('-');
	f=-f;
	}

	num=f;

	if(num==0)
	{
	lcd_data('0');
	}
	else
	{
		while(num>0){
		a[i]=(num%10)+48;
		i++;
		num/=10;
		}
		for(i--;i>=0;i--)
			lcd_data(a[i]);
	}

	lcd_data('.');
	i=0;
	num=(f-num)*1000000;
	if(num==0)
	{
	lcd_string("000000");
	}
	else
	{
	 	while(i<6){
		a[i]=(num%10)+48;
		i++;
		num/=10;
		}
		for(i--;i>=0;i--)
			lcd_data(a[i]);
	}
}
*/
