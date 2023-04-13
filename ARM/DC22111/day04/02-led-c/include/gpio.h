#ifndef __GPIO_H__
#define __GPIO_H__

//struct encapsulation
typedef struct
{
	volatile unsigned int MODER;
	volatile unsigned int OTYPER;
	volatile unsigned int OSPEEDR;
	volatile unsigned int PUPDR;
	volatile unsigned int IDR;
	volatile unsigned int ODR;
} gpio_t;
#define GPIOE ((gpio_t *)0x50006000)
#define GPIOF ((gpio_t *)0x50007000)
#define RCC_AHB4_ENSETR ((volatile unsigned int *)0x50000A28)

typedef enum
{
	LED1,
	LED2,
	LED3
} led_t;

//led init
void hal_gpio_init();

//led on
void hal_gpio_output_high(led_t led);

//led off
void hal_gpio_output_low(led_t led);








#endif




