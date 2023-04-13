#include "gpio.h"
extern void printf(const char *fmt, ...);
void delay_ms(int ms)
{
	int i,j;
	for(i = 0; i < ms;i++)
		for (j = 0; j < 1800; j++);
}


void led_init()
{
	*RCC_AHB4_ENSETR |= (0x3<<4);
	gpio_init_t init = {OUTPUT,PP,LOW,NO_PUPD};
	hal_gpio_init(GPIOE,GPIO_PIN_10,&init);
	hal_gpio_init(GPIOE,GPIO_PIN_8,&init);
	hal_gpio_init(GPIOF,GPIO_PIN_10,&init);


}


int main()
{
	led_init();
	while(1)
	{
		hal_gpio_write(GPIOE,GPIO_PIN_10,GPIO_SET_T);
		delay_ms(200);
		hal_gpio_write(GPIOE,GPIO_PIN_10,GPIO_RESET_T);
		delay_ms(200);
		hal_gpio_write(GPIOF,GPIO_PIN_10,GPIO_SET_T);
		delay_ms(200);
		hal_gpio_write(GPIOF,GPIO_PIN_10,GPIO_RESET_T);
		delay_ms(200);
		hal_gpio_write(GPIOE,GPIO_PIN_8,GPIO_SET_T);
		delay_ms(200);
		hal_gpio_write(GPIOE,GPIO_PIN_8,GPIO_RESET_T);
		delay_ms(200);
	}

	return 0;
}
