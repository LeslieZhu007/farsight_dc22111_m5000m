#include "spi.h"
/* SPI4_NSS 	---->   PE11
 * SPI4_SCK     ---->   PE12
 * SPI4_MOSI    ---->   PE14
 * SPI4_MISO    ---->   PE13
 * */

/* 数码管的编码， 先发送低位，在发送高位
 * A B C D E F G DP
 * 1 1 1 1 1 1 0 0    0xFC   0
 * 0 1 1 0 0 0 0 0    0x60   1
 * 1 1 0 1 1 0 1 0    0xDA   2
 * 1 1 1 1 0 0 1 0    0xF2   3
 * 0 1 1 0 0 1 1 0    0x66   4
 * 1 0 1 1 0 1 1 0    0xB6   5 
 * 1 0 1 1 1 1 1 0    0xBE   6
 * 1 1 1 0 0 0 0 0    0xE0   7
 * 1 1 1 1 1 1 1 0    0xFE   8
 * 1 1 1 1 0 1 1 0    0xF6   9
 * */
void delay_us1(unsigned int us)
{
	int i,j;
	for(i = 0; i < us;i++)
		for (j = 0; j < 1;j++);
}

void SPI_init(void)
{
	RCC->MP_AHB4ENSETR |= (0x1 << 4);
	// MOSI    PE14 
	GPIOE->MODER &= (~(0x3 << 28));
	GPIOE->MODER |= (0x1 << 28);
	GPIOE->OTYPER &= (~(0x1 << 14));
	GPIOE->OSPEEDR &= (~(0x3 << 28));
	GPIOE->PUPDR &= (~(0x3 << 28));
	// MISO    PE13
	GPIOE->MODER &= (~(0x3 << 26));
	GPIOE->OSPEEDR &= (~(0x3 << 26));
	GPIOE->PUPDR &= (~(0x3 << 26));
	// SCK     PE12	
	GPIOE->MODER &= (~(0x3 << 24));
	GPIOE->MODER |= (0x1 << 24);
	GPIOE->OTYPER &= (~(0x1 << 12));
	GPIOE->OSPEEDR &= (~(0x3 << 24));
	GPIOE->PUPDR &= (~(0x3 << 24));
	// NSS     PE11
	GPIOE->MODER &= (~(0x3 << 22));
	GPIOE->MODER |= (0x1 << 22);
	GPIOE->OTYPER &= (~(0x1 << 11));
	GPIOE->OSPEEDR &= (~(0x3 << 22));
	GPIOE->PUPDR &= (~(0x3 << 22));
	NSS_OUTPUT_L();    // 595芯片的锁存引脚拉低
	SCK_OUTPUT_L();    // SPI的时钟线拉低
}

void SPI_write(unsigned char dat)
{
	unsigned int i;
	for(i = 0; i< 8;i++)
	{
		if(dat & 0x01)
		{
			MOSI_OUTPUT_H(); //MOSI线写高电平
		} else
		{
			MOSI_OUTPUT_L(); //MOSI线写低电平
		}

		dat>>1;

		//SCK时钟线高电平到低电平的变化
		//MOSI数据线上的数据被写到595芯片的移位寄存器中delay_us1(10);
		SCK_OUTPUT_L;
		delay_us1(10);
		SCK_OUTPUT_H;
		delay_us1(10);
	}
}




