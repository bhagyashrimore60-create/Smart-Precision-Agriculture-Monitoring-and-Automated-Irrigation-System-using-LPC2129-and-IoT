  #include<lpc21xx.h>
  #include"header.h"

 
  int i,op;

  int main()
  {
uart0_init(9600);
lcd_init();
rtc_init();

servo_init();
keypad_init();

  IODIR0=GREEN_LED | RED_LED;
  IOSET0=GREEN_LED | RED_LED;
  IODIR0 &=~(1<<15);

  lcd_cmd(0x01);
  lcd_string("PIR Security");
  delay_ms(200);
  lcd_cmd(0xc0);
  lcd_string("System Ready");
  uart0_tx_string("\r\nSystem Ready\r\n");
  delay_ms(200);

  while(1)
  {
   pir_Sensor();

   if(rfid()==0)
   {
   	 key();
   }
   

	delay_ms(300);
  }                                                            
 }

