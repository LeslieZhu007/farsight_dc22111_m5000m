#include "pwm.h"


//蜂鸣器初始化 TIM4_CH1   PB6
void hal_beep_init()
{
    //rcc章节初始化
    RCC->MP_APB1ENSETR |= (0x1<<2);
    //使能GPIOB组
    RCC->MP_AHB4ENSETR |= (0x1<<1);
    

    //gpio章节初始化
    GPIOB->MODER &= (~(0x3<<12)); //设置PB6引脚为复用功能  MODER[13:12] = 10
    GPIOB->MODER |=  (0x2<<12);    //0x1<<13

    GPIOB->AFRL &= (~(0xf<<24));  //设置PB6引脚复用功能为TIM4_CH1功能,AFRL[27:24] = 0010
    GPIOB->AFRL |= (0x2<<24); //AF2 //0x1<<25

    //time4章节初始化
    //1. 设置预分频TIMx_PSC寄存器
    TIM4->PSC = (209-1);

    //2.设置PWM方波周期1/1000，频率=1000 ARR 1000
    TIM4->ARR = 1000;

    //3.设置PWM方波占空比 CCR1 = 300
    TIM4->CCR1 = 300;

    //4.设置TIM4_CH1通道输出PWM模式  CCMR1[16][6:4] = 0110
    TIM4->CCMR1 &=(~(0x1<<16));
    TIM4->CCMR1 &=(~(0x7<<4));
    TIM4->CCMR1 |=(0x3<<5);

    //5.设置 TIM4_CH1通道比较和捕获寄存器预加载使能 CCMR1[3] = 1
    TIM4->CCMR1 |= (0x1<<3);

    //6. 设置 TIM4_CH1通道输出 CCMR1[1:0] = 00
    TIM4->CCMR1 &= (~(0x3<<0));

    //7. 设置TIM4_CH1 捕获/比较寄存器输出极性 CCER[3] = 1
    TIM4->CCER |= (0x1<<3);
    //8. 设置TIM4_CH1 通道捕获/比较寄存器为高电平 CCER[1] = 0
    TIM4->CCER &= (~(0x1<<1));

    //9. 设置TIM4_CH1 通道 捕获/比较寄存器输出使能 CCER[0] = 0
    TIM4->CCER &= (~(0x1<<0));

    //10. 设置TIM4_CH1 通道自动重载计数器使能 CR1[7] = 1
    TIM4->CR1 |= (0x1<<7);
    //11. 设置TIM4_CH1 通道边沿对齐模式 CR1[6:5] = 00
    TIM4->CR1 &= (~(0x3<<5));
    //12. 设置TIM4_CH1 通道递减技术方式  CR1[4] = 1
    TIM4->CR1 |= (0x1<<4);
    //13. 设置TIM4_CH1 通道计数器使能 CR1[0] = 1
    TIM4->CR1 |= (0x1<<4);
    /*
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
    //TIM4->CCMR1 |= (~(0x6<<4));
    TIM4->CCMR1 |= (0x6<<4);
    TIM4->CCMR1 |= (0x1<<3);
    TIM4->CCMR1 &= (~(0x3<<0));

   



     //TIMx_ARR寄存器
    TIM4->ARR |= 1000;

    // TIMx_CCR1
    TIM4->CCR1 |= 300;
     */
}
 
//风扇初始化  TIM1_CH1 PE9
void hal_fan_init()
{
    //rcc章节初始化
    //使能GPIOE组
    RCC->MP_APB2ENSETR |= (0x1<<0);
    RCC->MP_AHB4ENSETR |= (0x1<<4);
    

    //gpio章节初始化
    GPIOE->MODER &= (~(0x3<<18));
    GPIOE->MODER |=  (0x2<<18);

    GPIOE->AFRH &= (~(0xf<<4));
    GPIOE->AFRH |= (0x1<<4); //AF1

    //time1章节初始化
    
    //TIMx_CR1
    //设置自动重载计数器使能  
    TIM1->CR1 |= (0x1<<7); 
    //设置边沿对齐模式
    TIM1->CR1 &= (~(0x3<<5));
    //设置递减计数方式


    TIM1->CR1 |= (0x1<<4);
    //设置计数器使能
    TIM1->CR1 |= (0x1<<0);

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
    //TIM1->CCMR1 |= (~(0x6<<4));
    TIM1->CCMR1 |= (0x6<<4);
    TIM1->CCMR1 |= (0x1<<3);
    TIM1->CCMR1 &= (~(0x3<<0));

   
      //设置TIMx_PSC寄存器
    TIM1->PSC |= (209-1);

     //TIMx_ARR寄存器
    TIM1->ARR |= 1000;

    // TIMx_CCR1
    TIM1->CCR1 |=   1000;

    TIM1->BDTR |= (0x1<<15);


    

}

//马达初始化 TIM16_CH1 PF6
void hal_motor_init()
{
    //rcc章节初始化
    //使能GPIOF组
    RCC->MP_APB2ENSETR |= (0x1<<3);
    RCC->MP_AHB4ENSETR |= (0x1<<5);
     
   
    //gpio章节初始化
    GPIOF->MODER &= (~(0x3<<12));
    GPIOF->MODER |=  (0x2<<12);
   
    GPIOF->AFRL &= (~(0xf<<24));
    GPIOF->AFRL |= (0x1<<24); //AF1

    //time16章节初始化
  
    //TIMx_CR1
    //设置自动重载计数器使能  
    TIM16->CR1 |= (0x1<<7); 
    //设置边沿对齐模式
    TIM16->CR1 &= (~(0x3<<5));
    //设置递减计数方式
    TIM16->CR1 |= (0x1<<4);
    //设置计数器使能
    TIM16->CR1 |= (0x1<<0);

    //TIMx_CCER
     // 设置捕获/比较寄存输出极性
     TIM16->CCER |= (0x1<<3);
        //设置捕获/比较寄存输出极性，起始状态为高电平
     TIM16->CCER &= (~(0x1<<1));
     //设置捕获/比较寄存输出使能
     TIM16->CCER |= (0x1<<0);

    //TIMx_CCMR1
    //设置输出模式为PWM模式
    TIM16->CCMR1 &= (~(0x1<<16));
    TIM16->CCMR1 &= (~(0x7<<4));
    //TIM16->CCMR1 |= (0x6<<4);
    TIM16->CCMR1 |= (~(0x6<<4));
    TIM16->CCMR1 |= (0x1<<3);
    TIM16->CCMR1 &= (~(0x3<<0));

          //设置TIMx_PSC寄存器
    TIM16->PSC |= (209-1);

     //TIMx_ARR寄存器
    TIM16->ARR |= 1000;

    // TIMx_CCR1
    TIM16->CCR1 |=  700;

    TIM16->BDTR |= (0x1<<15);

    
}