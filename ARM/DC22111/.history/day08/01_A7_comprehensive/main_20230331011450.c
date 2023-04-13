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



void led_init()
{
	RCC->MP_AHB4ENSETR |= (0x3<<4);
	gpio_init_t init = {OUTPUT,PP,LOW,NO_PUPD};
	hal_gpio_init(GPIOE,GPIO_PIN_10,&init);
	hal_gpio_init(GPIOE,GPIO_PIN_8,&init);
	hal_gpio_init(GPIOF,GPIO_PIN_10,&init);
	

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
char *cmpbuf;
int main()
{
	led_init();
	hal_uart4_init();

	while(1)
	{


		char *cmpbuf = get_string();
		printf(cmpbuf);
		printf("\n");
		for (int i = 0; i <= 5; i++)
		{
			if (mystrcmp(cmpbuf,arr[i].cmd_arr))
			{
				arr[i].gpio_write(arr[i].gpiox,arr[i].pin,arr[i].status);
			} 
		}
	}

	return 0;
}
