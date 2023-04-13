#include "spi.h"

extern void printf(const char *fmt, ...);
void delay_ms(int ms)
{
	int i,j;
	for(i = 0; i < ms;i++)
		for (j = 0; j < 1800; j++);
}



int num[10] = {0xFC,0x60,0xDA,0xF2,0x66,0xB6,0xBE,0xE0,0xFE,0xF6};
int main()
{
	unsigned int i;
	//初始化
	SPI_init();
	while(1)
	{
		#if 0
		//四位数码管显示相同的值
		for(i = 0;i<10;i++)
		{
			SPI_write(0xF0); //先发送位
			SPI_write(num[i]); //再发送段
			//片选线从低电平到高电平的变化
			//移位寄存器中的值被写入到锁存寄存器中
			NSS_OUTPUT_L();
			delay_ms(1);
			NSS_OUTPUT_H();
			delay_ms(1000);
		}
		#else

		//四位数码管显示不同的值 1 2 3 4
		for(i=0;i<4;i++)
		{
			SPI_write(0x80>>i);
			SPI_write(num[i+1]);

			NSS_OUTPUT_L();
			delay_ms(1);
			NSS_OUTPUT_H();
		}

		#endif
	}

	return 0;
}
