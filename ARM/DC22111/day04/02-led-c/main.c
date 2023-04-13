#include "gpio.h"
extern void printf(const char *fmt, ...);
void delay_ms(int ms)
{
	int i,j;
	for(i = 0; i < ms;i++)
		for (j = 0; j < 1800; j++);
}


int main()
{
	hal_gpio_init(); // LED灯初始化

	hal_gpio_output_high(LED1);
	/*
	while(1)
	{
		hal_gpio_output_high(LED1);
		delay_ms(200);
		hal_gpio_output_low(LED1);
		delay_ms(200);
		hal_gpio_output_high(LED2);
		delay_ms(200);
		hal_gpio_output_low(LED2);
		delay_ms(200);
		hal_gpio_output_high(LED3);
		delay_ms(200);
		hal_gpio_output_low(LED3);
		delay_ms(200);
	}
	*/
	return 0;
}
