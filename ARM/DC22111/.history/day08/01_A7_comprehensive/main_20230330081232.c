#include "gpio.h"
#include "uart4.h"
extern void printf(const char *fmt, ...);
char buff[10]={0};

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
	cmd_t arr[6] = 
	{
		[0]={},
		[1]={},
		[2]={},
		[3]={},
		[4]={},
		[5]={}
	};


}


int main()
{
	led_init();
	while(1)
	{
		//LED1 on
		hal_gpio_write(GPIOE,GPIO_PIN_10,GPIO_SET_T);
		
		//LED1 off
		hal_gpio_write(GPIOE,GPIO_PIN_10,GPIO_RESET_T);
		
		//LED2 on
		hal_gpio_write(GPIOF,GPIO_PIN_10,GPIO_SET_T);
		
		//LED2 off
		hal_gpio_write(GPIOF,GPIO_PIN_10,GPIO_RESET_T);
		
		//LED3 on
		hal_gpio_write(GPIOE,GPIO_PIN_8,GPIO_SET_T);
		
		//LED3 off
		hal_gpio_write(GPIOE,GPIO_PIN_8,GPIO_RESET_T);
		
	}

	return 0;
}
