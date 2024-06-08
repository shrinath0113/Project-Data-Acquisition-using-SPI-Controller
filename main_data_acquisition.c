#include "header.h"
main()
{
float temp,speed,light;
u32 t;
adc_init();
lcd_init();
spi0_init();

while(1)
	{
		lcd_cmd(0x01);

		// Temperature
		t=adc_read(1);						// read Ain1 P0.28
		temp=(((t*3.3)/1023)-0.5)/0.01;		// formula to conv. ADC output // formula to conv. ADC into vtg

		// Speed (Potentiometer)
		t=adc_read(2);						// read Ain2	// ADC potentiometer
		speed=((float)t/1023)*180;

		// Light Intensity
		t=read_mcp3204(2);					// read CH2		// LDR of MCP3204 
		light=100-(((float)t/4095)*100);	// light intensity in percentage

		// Temperature On LCD
		lcd_cmd(0x80);
		lcd_string("TEMP:");	
		lcd_atof(temp);		  				// ADC temperature sensor from MCP9700
		lcd_cgram();
		lcd_cmd(0x8A);
		lcd_data(0); 						// page0
		lcd_string("C   ");

		// Light Intensity On LCD
		lcd_cmd(0xC0);
		lcd_string("L:");
		lcd_atoi((int)light);
		lcd_string("% ");

		// Speed On LCD
		lcd_cmd(0xC7);
		lcd_string("S:");
		lcd_atoi((int)speed);
		lcd_string("KMPH");

		delay_sec(1);
	}
}

	

		

