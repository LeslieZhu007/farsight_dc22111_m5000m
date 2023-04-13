#include "gpio.h"

void hal_gpio_init(gpio_t * gpiox,unsigned int pin,gpio_init_t* init)
{
	//1.mode 
    gpiox->MODER &=(~(0x3 << 2*pin));
	gpiox->MODER |= (init->moder << 2*pin);

	//2.type
	gpiox->OTYPER &= (0x1<<pin);
	gpiox->OTYPER |= (init->otyper << pin);

	//3.speed 
	gpiox->OSPEEDR &= (~(0x3 << 2*pin));
	gpiox->OSPEEDR |= (init->ospeedr <<2*pin);

	//4.push pull 
	gpiox->PUPDR &= (~(0x3<<2*pin));
	gpiox->PUPDR |= (init->pupdr << 2*pin);

}




void hal_gpio_write(gpio_t * gpiox,unsigned int pin,gpio_odr_t status)
{

	if(status == GPIO_SET_T)
	{
		gpiox->ODR |= (0x1<<pin);
	} else if(status == GPIO_RESET_T)
	{
		gpiox->ODR &= (~(0x1<<pin));
	}
}


int mystrcmp(const char *dest,const char* src)
{
	if (sizeof(dest)!=sizeof(sizeof(src)))
	{
		return 0;
	}
	int i=0;
	while (src[i]!='\0' && dest[i]!='\0')
	{
		if(src[i]!=dest[i])
		{
			return 0;
		}
		i++;
	}
	
		
	
	return 1;
}

