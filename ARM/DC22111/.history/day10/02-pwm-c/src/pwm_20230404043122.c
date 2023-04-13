#include "pwm.h"


//蜂鸣器初始化 TIM4_CH1   PB6
void hal_beep_init()
{
    //rcc章节初始化
    //使能GPIOB组
    RCC->MP_AHB4ENSETR |= (0x1<<1);
    

    //gpio章节初始化
    GPIOB->MODER &= (~(0x3<<12));
    GPIOB->MODER |=  (0x2<<12);

    GPIOB->AFRL &= (~(0xf<<24));
    GPIOB->AFRL |= (0x2<<24); //AF2

    //time4章节初始化
    RCC->MP_APB1ENSETR |= (0x1<<2);
    
}
 
//风扇初始化  TIM1_CH1 PE9
void hal_fan_init()
{
    //rcc章节初始化
    //使能GPIOE组
    RCC->MP_AHB4ENSETR |= (0x1<<4);
    

    //gpio章节初始化
    GPIOE->MODER &= (~(0x3<<18));
    GPIOE->MODER |=  (0x2<<18);

    GPIOE->AFRH &= (~(0xf<<4));
    GPIOE->AFRH |= (0x1<<24); //AF1

    //time1章节初始化
    RCC->MP_APB2ENSETR |= (0x1<<0);

    

}

//马达初始化 TIM16_CH1 PF6
void hal_motor_init()
{
    //rcc章节初始化
    //使能GPIOF组
    RCC->MP_AHB4ENSETR |= (0x1<<5);
   
    //gpio章节初始化
    GPIOF->MODER &= (~(0x3<<12));
    GPIOF->MODER |=  (0x2<<12);
   
    GPIOF->AFRL &= (~(0xf<<24));
    GPIOF->AFRL |= (0x1<<24); //AF1

    //time16章节初始化
    RCC->MP_APB2ENSETR |= (0x1<<3);
    
    
}