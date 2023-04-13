#include "./include/gpio.h"
#include "./include/uart4.h"
extern void printf(const char *fmt, ...);
char buff[10]={0};

void delay_ms(int ms)
{
	int i,j;
	for(i = 0; i < ms;i++)
		for (j = 0; j < 1800; j++);
}
cmd_t arr[6] = 
	{
		[0]={
			    .cmd_arr = "led1on", 
                .gpiox = GPIOE,
                .pin =   GPIO_PIN_10,
                .status = GPIO_SET_T,
                .gpio_write  =  hal_gpio_write, 
			},
		[1]={
				.cmd_arr = "led1off", 
				.gpiox = GPIOE,
				.pin =   GPIO_PIN_10,
				.status = GPIO_RESET_T,
				.gpio_write  =  hal_gpio_write, 
			},
		[2]={

				.cmd_arr = "led2on", 
				.gpiox = GPIOF,
				.pin =   GPIO_PIN_10,
				.status = GPIO_SET_T,
				.gpio_write  =  hal_gpio_write, 
		},
		[3]={
				.cmd_arr = "led2off", 
				.gpiox = GPIOF,
				.pin =   GPIO_PIN_10,
				.status = GPIO_RESET_T,
				.gpio_write  =  hal_gpio_write, 
		},
		[4]={
				.cmd_arr = "led3on", 
				.gpiox = GPIOE,
				.pin =   GPIO_PIN_8,
				.status = GPIO_SET_T,
				.gpio_write  =  hal_gpio_write, 
		},
		[5]={
				.cmd_arr = "led3off", 
				.gpiox = GPIOE,
				.pin =   GPIO_PIN_8,
				.status = GPIO_RESET_T,
				.gpio_write  =  hal_gpio_write, 
		}
};



void led_init()
{
	RCC->MP_AHB4ENSETR |= (0x3<<4);
	gpio_init_t init = {OUTPUT,PP,LOW,NO_PUPD};
	hal_gpio_init(GPIOE,GPIO_PIN_10,&init);
	hal_gpio_init(GPIOE,GPIO_PIN_8,&init);
	hal_gpio_init(GPIOF,GPIO_PIN_10,&init);
	

}

char *cmpbuf;
int main()
{
	led_init();
	while(1)
	{
		cmpbuf = get_string();
		
		if (mystrcmp(cmpbuf,arr[0].cmd_arr))
		{
			//LED1 on
			arr[0].gpio_write(arr[0].gpiox,arr[0].pin,arr[0].status);
			while (1)
			{
				if (USART4->ISR & (0x1<<5))
				{
					break;
				}
			}
		} 
		
		if (mystrcmp(cmpbuf,arr[1].cmd_arr))
		{
			//LED1 off
			arr[1].gpio_write(arr[1].gpiox,arr[1].pin,arr[1].status);
			while (1)
			{
				if (USART4->ISR & (0x1<<5))
				{
					break;
				}
			}
		} 
		/*
		if (mystrcmp(cmpbuf,arr[2].cmd_arr))
		{
			//LED2 on
			arr[2].gpio_write(arr[2].gpiox,arr[2].pin,arr[2].status);
		} 
		
		if (mystrcmp(cmpbuf,arr[3].cmd_arr))
		{
			//LED2 off
			arr[3].gpio_write(arr[3].gpiox,arr[3].pin,arr[3].status);
		} 
		
		if (mystrcmp(cmpbuf,arr[4].cmd_arr))
		{
			//LED3 on
			arr[4].gpio_write(arr[4].gpiox,arr[4].pin,arr[4].status);
		} 
		
		if (mystrcmp(cmpbuf,arr[5].cmd_arr))
		{
			//LED3 off
			arr[5].gpio_write(arr[5].gpiox,arr[5].pin,arr[5].status);
		} 
		*/

		/*
		arr[0].gpio_write(arr[0].gpiox,arr[0].pin,arr[0].status);
		delay_ms(200);
		arr[1].gpio_write(arr[1].gpiox,arr[1].pin,arr[1].status);
		delay_ms(200);
		arr[2].gpio_write(arr[2].gpiox,arr[2].pin,arr[2].status);
		delay_ms(200);
		arr[3].gpio_write(arr[3].gpiox,arr[3].pin,arr[3].status);
		delay_ms(200);
		arr[4].gpio_write(arr[4].gpiox,arr[4].pin,arr[4].status);
		delay_ms(200);
		arr[5].gpio_write(arr[5].gpiox,arr[5].pin,arr[5].status);
		delay_ms(200);
		*/
	}

	return 0;
}
