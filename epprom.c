#include"h.h"
#include<string.h>
static int i=0;
void eeprom(u8 d1,u8 d2,u8 d3,u8 d4){
	u8 r1,r2,r3,r4;
	i2c_write(0xA0,i=i+2,d1);//1
	delay_ms(30);

	i2c_write(0xA0,i=i+2,d2);//2
	delay_ms(30);

	i2c_write(0xA0,i=i+2,d3);//3
	delay_ms(30);

	i2c_write(0xA0,i=i+2,d4);//4
	delay_ms(30);

	i=i-8; //0

	r1=i2c_read(0xA1,i=i+2);//1
	r2=i2c_read(0xA1,i=i+2);//2
	r3=i2c_read(0xA1,i=i+2);//3
	r4=i2c_read(0xA1,i=i+2);//4

	if((r1==d1)&&(r2==d2)&&(r3==d3)&&(r4==d4)){
		uart0_tx_string("EEPROM_status: DATA SAVED\r\n");
	}else{
		uart0_tx_string("EEPROM_status: WRITE FAIL\r\n");
		//return 0;
	}
}
