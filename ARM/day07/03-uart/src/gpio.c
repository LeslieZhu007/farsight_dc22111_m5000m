#include "gpio.h"
extern void printf(const char *fmt, ...);
/*
 * 函数的功能： gpio初始化函数
 * 函数的参数：无
 * 函数的返回值：无
 * */
void hal_gpio_init(gpio_t *gpio, unsigned int pins)
{
	
	// 2. 设置PE10引脚为通用的输出模式  GPIOE_MODER[21:20]
	gpio->MODER &= (~(0x3 << (pins*2)));
	gpio->MODER |= (0x1 << (pins*2));
	printf("MODER = %x\n", gpio->MODER);
	// 3. 设置PE10引脚为推挽输出 GPIOE_OTYPER[10]
	gpio->OTYPER &= (~(0x1 << pins));
	printf("OTYPER = %x\n", gpio->OTYPER);
	// 4. 设置PE10引脚的输出速率为低速 GPIOE_OSPEEDR[21:20]
	gpio->OSPEEDR &= (~(0x3 << (pins*2)));
	printf("OSPEEDR = %x\n", gpio->OSPEEDR);
	// 5. 设置PE10引脚的禁止上拉和下拉 GPIOE_PUPDR[21:20]
	gpio->PUPDR &= (~(0x3 << (pins*2)));
	printf("PUPDR = %x\n", gpio->PUPDR);
	GPIOZ_SECCFGR &= (~(0xFF));
	printf("GPIOZ_SECCFGR = %x\n", GPIOZ_SECCFGR);
}
/* 函数的功能： 设置gpio引脚输出高低电平 
 * 函数的参数：
 * 	@ led  ： 哪个led灯
 * 	@ state : 引脚输出的状态
 * 函数的返回值：无
 * */

void hal_gpio_write(leds_t led, states_t state)
{
	// 1. 设置PE10引脚输出高电平  GPIOE_ODR[10]
	// 2. 设置PE10引脚输出低电平  GPIOE_ODR[10]
	switch(led)
	{
		case LED1:
			if(state == GPIO_RESET)
				GPIOE->ODR &= (~(0x1 << 10));
			else 
				GPIOE->ODR |= (0x1 << 10);
			break;
		case LED2:
			if(state == GPIO_RESET)
				GPIOF->ODR &= (~(0x1 << 10));
			else 
				GPIOF->ODR |= (0x1 << 10);
			break;
		case LED3:
			if(state == GPIO_RESET)
				GPIOE->ODR &= (~(0x1 << 8));
			else 
				GPIOE->ODR |= (0x1 << 8);
			break;
		case LED4:
			if(state == GPIO_RESET)
				GPIOZ->ODR &= (~(0x1 << 5));
			else 
				GPIOZ->ODR |= (0x1 << 5);
			break;
		case LED5:
			if(state == GPIO_RESET)
				GPIOZ->ODR &= (~(0x1 << 6));
			else 
				GPIOZ->ODR |= (0x1 << 6);
			break;
		case LED6:
			if(state == GPIO_RESET){
				GPIOZ->ODR &= (~(0x1 << 7));
				printf("ODR = %x\n", GPIOZ->ODR);
			} else{ 
				GPIOZ->ODR |= (0x1 << 7);
				printf("ODR = %x\n", GPIOZ->ODR);
			}
				break;
	}
}



