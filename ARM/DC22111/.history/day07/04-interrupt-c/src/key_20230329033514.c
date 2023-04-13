#include "key.h"

//key1 ===> GPIOF9
void hal_exti_init()
{
    /*********RCC init************/
    //GPIOF enable
    RCC->MP_AHB4ENSETR |= (0x1<<5);
    /*********GPIO init*********/
    GPIOF->MODER &= (~(0x3<<18)); //key1 PF9
    GPIOF->MODER &= (~(0x3<<14)); //key2 PF7
    GPIOF->MODER &= (~(0x3<<16)); //key3 PF8

    /*********EXTI init*********/
    //1.外部中断选择寄存器
    //key1 PF9 ==> EXTI9(EXTI_EXTICR3寄存器中)
    EXTI->EXTICR3 &= (~(0xff<<8));
    EXTI->EXTICR3 |= (0x05<<8);

    //key2 PF7 ==> EXTI9(EXTI_EXTICR3寄存器中)

    //key3 PF8 ==> EXTI8(EXTI_EXTICR3寄存器中)
    EXTI->EXTICR3 &= (~(0xff<<0));
    EXTI->EXTICR3 |= (0x05<<0);
}


void hal_gicd_init()
{

}


void hal_gicc_init()
{

}