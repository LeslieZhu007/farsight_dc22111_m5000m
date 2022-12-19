#ifndef __GPIO_H__
#define __GPIO_H__
#include "stm32mp1xx_gpio.h"
/* 寄存器的封装 */

/* 方式1 */
	// volatile : 防止编译器对代码的优化，每次使用值时都从地址中取值
	// *(volatile unsigned int *)0x50000A28 = *(volatile unsigned int *)0x50000A28 | (0x1 << 4);
    // 将值写到地址中                从地址中读值

/* 方式2 */
#define   RCC_MP_AHB4ENSETR  (*(volatile unsigned int *)0x50000A28)
#define   RCC_MP_AHB5ENSETR  (*(volatile unsigned int *)0x50000210)
#define   RCC_AHB5RSTSETR    (*(volatile unsigned int *)0x50000190)
#define  RCC_TZCR   (*(volatile unsigned int *)0x50000000)
// RCC_MP_AHB4ENSETR |= (0x1 << 4);
#define   GPIOE_MODER   (*(volatile unsigned int *)0x50006000)
#define   GPIOE_OTYPER  (*(volatile unsigned int *)0x50006004)
#define   GPIOE_OSPEEDR (*(volatile unsigned int *)0x50006008)
#define   GPIOE_PUPDR   (*(volatile unsigned int *)0x5000600C)
#define   GPIOE_IDRR    (*(volatile unsigned int *)0x50006010)
#define   GPIOE_ODR     (*(volatile unsigned int *)0x50006014)

#define   GPIOF_MODER   (*(volatile unsigned int *)0x50007000)
#define   GPIOF_OTYPER  (*(volatile unsigned int *)0x50007004)
#define   GPIOF_OSPEEDR (*(volatile unsigned int *)0x50007008)
#define   GPIOF_PUPDR   (*(volatile unsigned int *)0x5000700C)
#define   GPIOF_IDRR    (*(volatile unsigned int *)0x50007010)
#define   GPIOF_ODR     (*(volatile unsigned int *)0x50007014)

/* 方式3 */
// 声明一个结构体类型的变量
/*
typedef struct{
	volatile unsigned int MODER;
	volatile unsigned int OTYPER;
	volatile unsigned int OSPEEDR;
	volatile unsigned int PUPDR;
	volatile unsigned int IDR;
	volatile unsigned int ODR;
	volatile unsigned int BSRR;
	volatile unsigned int LCKR;
}gpio_t;
//#define  GPIOE  (*(gpio_t *)0x50006000)
// GPIOE.MODER &= (~(0x3 << 20));
// GPIOE.MODER |= (0x1 << 20);

#define  GPIOE  ((gpio_t *)0x50006000)
#define  GPIOF ((gpio_t *)0x50007000)
// GPIOE->MODER &= (~(0x3 << 20));
// GPIOE->MODER |= (0x1 << 20);
#define GPIOZ  ((gpio_t *)0x54004000)
*/
#define GPIOZ_SECCFGR  (*(volatile unsigned int *)0x54004030)

typedef enum{
	LED1 = 1,
	LED2,
	LED3,
	LED4,
	LED5,
	LED6,
}leds_t;
typedef enum{
	GPIO_RESET = 0,
	GPIO_SET,
}states_t;

#define GPIO_PIN_10   10 
#define GPIO_PIN_8    8
#define GPIO_PIN_5    5
#define GPIO_PIN_6    6
#define GPIO_PIN_7    7
/*
 * 函数的功能： gpio初始化函数
 * 函数的参数：无
 * 函数的返回值：无
 * */
void hal_gpio_init(gpio_t *gpio, unsigned int pins);
/* 函数的功能： 设置gpio引脚输出高低电平 
 * 函数的参数：
 * 	@ led  ： 哪个led灯
 * 	@ state : 引脚输出的状态
 * 函数的返回值：无
 * */

void hal_gpio_write(leds_t led, states_t state);


#endif //__GPIO_H__

