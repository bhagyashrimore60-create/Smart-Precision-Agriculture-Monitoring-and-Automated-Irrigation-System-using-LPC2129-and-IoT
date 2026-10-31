
 #include<string.h>
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned short int u16;
typedef signed short int s16;
typedef unsigned char u8;
typedef signed char s8;

extern void delay_sec(unsigned int  sec);
extern void delay_ms(unsigned int ms);

extern void lcd_data(unsigned char data);
extern void lcd_cmd(unsigned char cmd);
extern void lcd_init(void);
extern void lcd_string(char *ptr);

extern void uart0_rx_string(unsigned char *ptr,int len);
extern void config_eint0(void);
extern void config_vic_for_eint0(void);
extern void config_eint(void);
extern void config_vic_for_eint1(void);
extern void config_vic_for_uart0(void);

extern void config_timer1_intr(void);
extern void config_vic_for_timer1(void);
extern void uart0_integer(int num);
extern void uart0_tx_string(char *ptr);
extern unsigned char uart0_rx(void);
extern void uart0_tx(unsigned char data);

extern void uart0_init(unsigned int baud);
extern void uart0_float(float n);

extern u16 mcp3204_adc_read(u8 ch_num);
extern u8 spi0(u8 data);
extern void spi0_init(void);

extern void config_vic_for_uart0(void);

extern void i2c_init(void);
extern void i2c_send(u8 sa, u8 mr, u8 data);
extern u8 i2c_receive(u8 sa, u8 mr);

typedef struct CAN1_MSG{
	u32 id;
	u32 byteA;
	u32 byteB;
	u8 rtr;
	u8 dlc;
	u8 ff;
}CAN1;


extern void can1_tx(CAN1 v);
extern void can1_init(void);


#define GREEN_LED (1<<19)
#define RED_LED  (1<<20)
#define BUZZER (1<<21)
#define PIR_SENSOR ((IOPIN0>>15)&1)

extern  void pir_Sensor(void);
extern void servo_init(void);
extern void servo_0deg(void);
extern void servo_90deg(void);
extern void servo_180deg(void);

extern int rfid(void);

extern void rtc_init(void);
extern void rtc_set_time(u8 hours,u8 minutes,u8 seconds);
extern void rtc_set_date(u8 date,u8 month,u8 year);
extern void rtc_get_time(void);
extern void rtc_get_date(void);
extern void rtc_get_data(void);
extern void rtc_display_time(void);
extern void rtc_display_date(void);
extern void rtc_display_time_uart(void);

extern void keypad_init(void);
extern char keypad_read(void);
extern	void key(void);

extern void eeprom(void);
extern unsigned char  hours;
extern unsigned char  minutes;
extern unsigned char  seconds;
extern unsigned char  date;
extern unsigned char  month;
extern unsigned char  year;

extern	void i2c_init(void);
extern	void i2c_write(u8 sa, u8 mr ,u8 data);
extern unsigned char i2c_read(u8 sa,u8 mr);


	