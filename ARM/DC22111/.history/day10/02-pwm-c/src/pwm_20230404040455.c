#include "pwm.h"


//蜂鸣器初始化 TIM4_CH1   PB6
void hal_beep_init()
{
    //rcc章节初始化
    //使能GPIOB组
    RCC->MP_AHB4ENSETR |= (0x1<<1);
    
    //gpio章节初始化

    //time4章节初始化

    
}
 
//风扇初始化  TIM1_CH1 PE9
void hal_fan_init()
{
    //rcc章节初始化
    //使能GPIOE组
    RCC->MP_AHB4ENSETR |= (0x1<<4);

    //gpio章节初始化

    //time4章节初始化

}

//马达初始化 TIM16_CH1 PF6
void hal_motor_init()
{
    //rcc章节初始化
    //使能GPIOF组
    RCC->MP_AHB4ENSETR |= (0x1<<5);

    //gpio章节初始化

    //time4章节初始化
    
}