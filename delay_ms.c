#include<lpc21xx.h>
#include"header.h"
void delay_ms(unsigned int ms)
{
 T0PR=15000-1;
 T0TC=0;
 T0PC=0;
 //T0TCR=0x02;
 T0TCR=0x01;
 while(T0TC < ms);
 T0TCR=0x0;
}

