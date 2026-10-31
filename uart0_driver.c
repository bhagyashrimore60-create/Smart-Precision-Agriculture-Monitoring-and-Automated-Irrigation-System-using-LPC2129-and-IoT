#include<lpc21xx.h>
void uart0_init(unsigned int baud)
{
int pclk,result=0; 
if(VPBDIV==0x0)
	pclk=15000000;
else if(VPBDIV==0x01)
	pclk=60000000;
else if(VPBDIV==0x02)
	pclk=30000000;
result=pclk/(16*baud);

PINSEL0|=0x00000005;
U0LCR=0x83;
U0DLL=result&0xff;
U0DLM=(result>>8)&0xff;
U0LCR=0x03;
}
// transmitter function
#define THRE ((U0LSR>>5)&1)
void uart0_tx(unsigned char data)
{
	U0THR=data; // load data into U0THR
	while(THRE==0);// keep wait unit THRE becomes 1
}
// Receiver  function
//#define RDR (U0LSR&1)
unsigned char uart0_rx()
{
	while((U0LSR&1)==0);
	return U0RBR;
}


void uart0_tx_string(char *ptr)
{
	while(*ptr!=0)
	{
		uart0_tx(*ptr);
		ptr++;
	}
}

void uart0_binary(int num)
{
int pos;
for(pos=7;pos>=0;pos--)
{
if(num&(1<<pos))
uart0_tx('1');
else
uart0_tx('0');
}
}


void uart0_integer( int num)
{
int a[10], i; 
if(num==0) // check zero or non zero
{
uart0_tx('0');
}
if(num<0) // check -ve number
{
num=-num;
uart0_tx('-');
}
i=0;
while(num>0) // check +ve number
{
a[i]=num%10+48;
num=num/10;
i++;
}
// print data on lcd 
for(i=i-1;i>=0;i--)
{
uart0_tx(a[i]);
}
}





