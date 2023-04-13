#include "gpio.h"
//led init
void hal_gpio_init()
{
	//GPIOE and GPIOF rcc init
	*RCC_AHB4_ENSETR |= (0x3<<4);
	//MODER init 
	//LED1
	GPIOE->MODER &= (~(0x3<<20));
	GPIOE->MODER |= (0x1<<20);
	//LED2 
	GPIOF->MODER &= (~(0x3<<20));
	GPIOF->MODER |= (0x1<<20);

	//LED3
	GPIOE->MODER &= (~(0x3<<16));
	GPIOE->MODER |= (0x1<<16);

	//OTYPER init 
	//LED1
	GPIOE->OTYPER &= (~(0x1<<10));
	//LED2 
	GPIOF->OTYPER &= (~(0x1<<10));
	//LED3
	GPIOE->OTYPER &= (~(0x1<<8));


	//OSPEEDR init 
	//LED1
	GPIOE->OSPEEDR &= (~(0x3<<20));
	//LED2 
	GPIOF->OSPEEDR &= (~(0x3<<20));
	//LED3
	GPIOE->OSPEEDR &= (~(0x3<<16));

	//PUPDR init 
	//LED1
	GPIOE->PUPDR &= (~(0x3<<20));
	//LED2 
	GPIOF->PUPDR &= (~(0x3<<20));
	//LED3
	GPIOE->PUPDR &= (~(0x3<<18));
}

//led on
void hal_gpio_output_high(led_t led)
{
	switch(led)
	{
		case LED1:
			GPIOE->ODR |= (0x1<<10);
			break;
		case LED2:
			GPIOF->ODR |= (0x1<<10);
			break;
		case LED3:
			GPIOE->ODR |= (0x1<<8);
			break;
		default:
			break;
	}
}




//led off
void hal_gpio_output_low(led_t led)
{
	switch(led)
	{
		case LED1:
			GPIOE->ODR &= (~(0x1<<10));
			break;
		case LED2:
			GPIOF->ODR &= (~(0x1<<10));
			break;
		case LED3:
			GPIOE->ODR &= (~(0x1<<8));
			break;
		default:
			break;
	}



}


