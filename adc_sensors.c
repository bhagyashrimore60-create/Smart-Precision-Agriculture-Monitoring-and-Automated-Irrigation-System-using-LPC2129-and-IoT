#include<lpc21xx.h>
#include"h.h"
#define Green_LED (1<<17)
#define Yellow_LED (1<<18)
#define Red_LED (1<<19)
//IODIR0=Green_LED|Yellow_LED|Red_LED;
float num;

void soil_sensor(float num)
{
	if(num>=90)
	{
		uart0_tx_string("------------------\n\r");
		uart0_string("Soil Moisture :");
		uart0_float(num);
		uart0_string("%\r\n");
		uart0_string("Soil Status: DRY\r\n");
		uart0_string("Pump Status : ON\r\n");
		uart0_tx_string("------------------\n\r");
		lcd_cmd(0x01);
		lcd_cmd(0x80);
		lcd_string("SOil : DRY");
		lcd_cmd(0xc0);
		lcd_string("pump : ON");
	}
	else if(num<90 && num>=55)
	{
		uart0_tx_string("------------------\n\r");
		uart0_string("Soil Moisture : ");
		uart0_float(num);
		uart0_string("%\r\n");
		uart0_string("Soil Status: NORMAL \r\n");
		uart0_string("Pump Status : OFF \r\n");
		uart0_tx_string("------------------\n\r");
		lcd_cmd(0x01);
		lcd_cmd(0x80);
		lcd_string("SOil : NORMAL");
		lcd_cmd(0xc0);
		lcd_string("pump : OFF");
	}
	else if(num>20 && num<55)
	{
		uart0_tx_string("------------------\n\r");
		uart0_string("Soil Moisture : ");
		uart0_float(num);
		uart0_string("%\r\n");
		uart0_string("Soil Status: WET \r\n");
		uart0_string("Pump Status : OFF \r\n");
		uart0_tx_string("------------------\n\r");
		lcd_cmd(0x01);
		lcd_cmd(0x80);
		lcd_string("Soil :WET");
		lcd_cmd(0xC0);
		lcd_string("Pump :OFF");
	}
}



void water_sensor(float num)
{
	if(num<=20)
	{
		uart0_string("Water Level :");
		uart0_float(num);
		uart0_string("%\r\n");
		uart0_string("Tank Status: LOW\r\n");
		uart0_string("Pump Status : OFF\r\n");

	}
	else if(num>20 && num<=65)
	{
		uart0_string("Water Level :");
		uart0_float(num);
		uart0_string("%\r\n");
		uart0_string("Tank Status: NOTMAL \r\n");
		uart0_string("Pump Status : REDAY \r\n");

	}
	else if(num>65)
	{
		uart0_string("Water Level : ");
		uart0_float(num);
		uart0_string("%\r\n");
		uart0_string("Tank Status: FULL \r\n");
		uart0_string("Pump Status : REDAY \r\n");

	}
}

void temp_sensor(float num)
{
	if(num>18 && num<=30)
	{
		uart0_tx_string("------------------\n\r");
		uart0_string("Tempeature :");
		uart0_float(num);
		uart0_tx_string(" C\r\n");
		uart0_string("Status: NORMAL\r\n");
		uart0_tx_string("-----------------------\n\r");

	}
	else if(num>30 && num<=42)
	{
		uart0_tx_string("------------------\n\r");
		uart0_string("Tempeature :");
		uart0_float(num);
		uart0_string(" C\r\n");
		uart0_string("Status: HIGH\r\n");
		uart0_tx_string("------------------\n\r");
	}
	else if(num<=18)
	{
		uart0_tx_string("------------------\n\r");
		uart0_string("Tempeature :");
		uart0_float(num);
		uart0_string(" C\r\n");
		uart0_string("Status: LOW\r\n");
		uart0_tx_string("------------------\n\r");
	}
}

void ldr_sensor(int num)
{
	if(num>=1023)
	{
		uart0_tx_string("------------------\n\r");
		uart0_string("Bright Sunlight\r\n");
		uart0_string("Light Level:HIGH\r\n");
		uart0_string("Status: SUNNY\r\n");
		uart0_tx_string("------------------\n\r");

	}
	else if(num>=800 && num<1023)
	{
		uart0_tx_string("------------------\n\r");
		uart0_string("Moderate Sunlight\r\n");
		uart0_string("Light Level:MEDIUM\r\n");
		uart0_string("Status: NORMAL\r\n");
		uart0_tx_string("------------------\n\r");

	}
	else 
	{
		uart0_tx_string("------------------\n\r");
		uart0_string("Low Sunlight\r\n");
		uart0_string("Light Level:LOW\r\n");
		uart0_string("Status: CLOUDY\r\n");
		uart0_tx_string("------------------\n\r");

	}
}

