/*----------Header files declarations-----------*/
#include<LPC21XX.H>
#include<string.h>

/*----------Function declarations-----------*/

/*----------Defining datatypes shortcuts-----------*/
typedef signed char s8;
typedef unsigned char u8;
typedef signed short int s16;
typedef unsigned short int u16;
typedef signed int s32;
typedef unsigned int u32;

/*----------Delay functions-----------*/
extern void delay_sec(unsigned int);
extern void delay_ms(unsigned int);

/*----------LCD functions-----------*/
extern void lcd_data(unsigned char);
extern void lcd_cmd(unsigned char);
extern void lcd_init(void);
extern void lcd_string(signed char *);
extern void lcd_cgram(void);
extern void lcd_atoi(int);
extern void lcd_atof(float);

/*************UART0*****************/
/*------******UART FUNCTIONS UART0******-------*/
extern void uart0_init(u32 );

/*--------Transmit UART0--------*/
extern void uart0_tx(u8 );
extern void uart0_tx_string(s8 *);

/*--------Receiver UART0--------*/
extern u8 uart0_rx(void);
extern void uart0_rx_string(s8 *,u8 );

/*-------UART0 OTHER FUNCTIONS UART1-------*/
void uart0_ascii(u8);
void uart0_hex(u8);
void uart0_tx_integer(s32);
void uart0_tx_float(float);

/*-------UART0 FLAGs-------*/
#define THRE ((U0LSR>>5)&1)
#define RDR (U0LSR&1)

/*************UART1*****************/
/*------******UART FUNCTIONS UART1******-------*/
extern void uart1_init(u32 );

/*--------Transmit UART1--------*/
extern void uart1_tx(u8 );
extern void uart1_tx_string(s8 *);

/*--------Receiver UART0--------*/
extern u8 uart1_rx(void);
extern void uart1_rx_string(s8 *,u8 );

/*-------UART1 OTHER FUNCTIONS UART1-------*/
extern void uart1_ascii(u8);
extern void uart1_hex(u8);
extern void uart1_tx_integer(s32);
extern void uart1_tx_float(float);

/*-------UART1 FLAGs-------*/
#define THRE1 ((U1LSR>>5)&1)
#define RDR1 (U1LSR&1)

/*************SPI0*****************/
/*------******SPI0 FUNCTIONS SPI0******-------*/
extern void spi0_init(void);
extern u8 spi0(u8); 

/*-------SPI0 FLAGs-------*/
#define CS0 (1<<7)

/***********I2C**********/
extern void i2c_init(void);
extern void i2c_byte_write_frame(u8 ,u8 ,u8 );
extern u8 i2c_byte_read_frame(u8,u8);

/*-------I2C FLAGs-------*/
#define SI ((I2CONSET>>3)&1)

/*********ADC FUNCTIONS*********/
extern void adc_init(void);
extern u16 adc_read(u8);

/*********MCP3204 FUNCTIONS*********/
extern u16 read_mcp3204(u8);

/********* UART0 Interrupt FUNCTIONS*********/
extern void config_vic_for_uart0(void);
extern void en_uart0_interrupt(void);

/******** TIMER1 Interrupt FUNCTIONS*********/ 
extern void config_vic_for_timer1(void);
extern void en_timer1_interrupt(void);

/*************CAN1*****************/
typedef struct CAN1_MSG
{
u32 id,byteA,byteB;
u8 dlc,rtr;
}CAN1;

extern void can1_rx(CAN1 *);
extern void can1_tx(CAN1 );
extern void can1_init(void);


/*************CAN2*****************/
typedef struct CAN2_MSG
{
u32 id,byteA,byteB;
u8 dlc,rtr;
}CAN2;

extern void can2_rx(CAN2 *);
extern void can2_tx(CAN2);
extern void can2_init(void);

/********* CAN1 Interrupt FUNCTIONS*********/
void en_can1_interrupt(void);
void config_vic_for_can1(void);

/********* CAN2 Interrupt FUNCTIONS*********/
void en_can2_interrupt(void);
void config_vic_for_can2(void);
