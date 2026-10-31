#include<lpc21xx.h>
#include"header.h"

void adc_init()
{
	//PINSEL1|=(1<<28);
	PINSEL1|=0X15400000;
	ADCR|=0X00200400;
}

unsigned int adc_read(u32 ch_num)
{
	unsigned temp=0;
	ADCR|=(1<<ch_num);
	ADCR|=1<<24;
	while(((ADDR>>31)&1)==0);
	ADCR^=(1<<24);
	ADCR^=(1<<ch_num);
	temp=((ADDR>>6)&0x3ff);
	return temp;
}


