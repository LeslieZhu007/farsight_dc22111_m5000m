#include "pwm.h"


//蜂鸣器初始化 TIM4_CH1   PB6
void hal_beep_init()
{
    //rcc章节初始化
    RCC->MP_APB1ENSETR |= (0x1<<2);
    //使能GPIOB组
    RCC->MP_AHB4ENSETR |= (0x1<<1);
    

    //gpio章节初始化
    GPIOB->MODER &= (~(0x3<<12));
    GPIOB->MODER |=  (0x2<<12);

    GPIOB->AFRL &= (~(0xf<<24));
    GPIOB->AFRL |= (0x2<<24); //AF2

    //time4章节初始化
     //TIMx_CR1
    //设置自动重载计数器使能  
    TIM4->CR1 |= (0x1<<7); 
    //设置边沿对齐模式
    TIM4->CR1 &= (~(0x3<<5));
    //设置递减计数方式
    TIM4->CR1 |= (0x1<<4);
    //设置计数器使能
    TIM4->CR1 |= (0x1<<0);

    

    //TIMx_CCER
     // 设置捕获/比较寄存输出极性
     TIM4->CCER |= (0x1<<3);
        //设置捕获/比较寄存输出极性，起始状态为高电平
     TIM4->CCER &= (~(0x1<<1));
     //设置捕获/比较寄存输出使能
     TIM4->CCER |= (0x1<<0);
    //TIMx_CCMR1
    //设置输出模式为PWM模式
    TIM4->CCMR1 &= (~(0x1<<16));
    TIM4->CCMR1 &= (~(0x7<<4));
    TIM4->CCMR1 |= (~(0x6<<4));
    TIM4->CCMR1 |= (0x1<<3);
    TIM4->CCMR1 &= (~(0x3<<0));

   

    //设置TIMx_PSC寄存器
    TIM4->PSC |= (209-1);

     //TIMx_ARR寄存器
    TIM4->ARR |= 1000;

    // TIMx_CCR1
    TIM4->CCR1 |= 300;
     
}
 
//风扇初始化  TIM1_CH1 PE9
void hal_fan_init()
{
    //rcc章节初始化
    //使能GPIOE组
    RCC->MP_AHB4ENSETR |= (0x1<<4);
    RCC->MP_APB2ENSETR |= (0x1<<0);

    //gpio章节初始化
    GPIOE->MODER &= (~(0x3<<18));
    GPIOE->MODER |=  (0x2<<18);

    GPIOE->AFRH &= (~(0xf<<4));
    GPIOE->AFRH |= (0x1<<24); //AF1

    //time1章节初始化
    
    //TIMx_CR1
    //设置自动重载计数器使能  
    TIM1->CR1 |= 0x1<<7; 
    //设置边沿对齐模式
    TIM1->CR1 &= (~(0x3<<5));
    //设置递减计数方式
    TIM1->CR1 |= 0x1<<4;
    //设置计数器使能
    TIM1->CR1 |= 0x1<<0;

     //TIMx_CCER
     // 设置捕获/比较寄存输出极性
     TIM1->CCER |= (0x1<<3);
        //设置捕获/比较寄存输出极性，起始状态为高电平
     TIM1->CCER &= (~(0x1<<1));
     //设置捕获/比较寄存输出使能
     TIM1->CCER |= (0x1<<0);


    //TIMx_CCMR1
    //设置输出模式为PWM模式
    TIM1->CCMR1 &= (~(0x1<<16));
    TIM1->CCMR1 &= (~(0x7<<4));
    TIM1->CCMR1 |= (~(0x6<<4));
    TIM1->CCMR1 |= (0x1<<3);
    TIM1->CCMR1 &= (~(0x3<<0));

   
      //设置TIMx_PSC寄存器
    TIM1->PSC |= (209-1);

     //TIMx_ARR寄存器
    TIM1->ARR |= 1000;

    // TIMx_CCR1
    TIM1->CCR1 |= 700;

    TIM1->BDTR |= (0x1<<15);


    

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
    //TIMx_CR1
    //设置自动重载计数器使能  
    TIM16->CR1 |= 0x1<<7; 
    //设置边沿对齐模式
    TIM16->CR1 &= (~(0x3<<5));
    //设置递减计数方式
    TIM16->CR1 |= 0x1<<4;
    //设置计数器使能
    TIM16->CR1 |= 0x1<<0;

    //TIMx_CCMR1



    
}