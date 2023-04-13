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
    //1.外部中断选择寄存器  EXTI_EXTICRx
    //key1 PF9 ==> EXTI9(EXTI_EXTICR3寄存器中)
    EXTI->EXTICR3 &= (~(0xff<<8));
    EXTI->EXTICR3 |= (0x05<<8);

    //key2 PF7 ==> EXTI7(EXTI_EXTICR2寄存器中)
    EXTI->EXTICR2 &= (~(0xff<<24));
    EXTI->EXTICR2 |= (0x05<<24);

    //key3 PF8 ==> EXTI8(EXTI_EXTICR3寄存器中)
    EXTI->EXTICR3 &= (~(0xff<<0));
    EXTI->EXTICR3 |= (0x05<<0);

    //2.外部中断下降沿触发选择寄存器
    //key1 PF9 ==> EXTI9 ----> 事件9
    EXTI->FTSR1 |= (0x1<<9);
    //key2 PF7 ==> EXTI7 ----> 事件7
    EXTI->FTSR1 |= (0x1<<7);
    //key3 PF8 ==> EXTI8 ----> 事件8
    EXTI->FTSR1 |= (0x1<<8);


    //3.外部中断屏蔽寄存器
    //key1 PF9 ==> EXTI9 ----> 事件9
    EXTI->C1IMR1 |= (0x1<<9);   //置1取消屏蔽
    //key2 PF7 ==> EXTI7 ----> 事件7
    EXTI->C1IMR1 |= (0x1<<7);
    //key3 PF8 ==> EXTI8 ----> 事件8
    EXTI->C1IMR1 |= (0x1<<8);

    //4.外部中断下降沿挂起寄存器==>可读可写 
    //读0:无中断产生 1:有中断产生   写0:不清除中断挂起标志位 写1:清除中断挂起标志位
    //key1 PF9 ==> EXTI9 ----> 事件9
    EXTI->FPR1 |= (0x1<<9);   //置1清除中断挂起标志位
    //key2 PF7 ==> EXTI7 ----> 事件7
    EXTI->FPR1 |= (0x1<<7);
    //key3 PF8 ==> EXTI8 ----> 事件8
    EXTI->FPR1 |= (0x1<<8);
}


void hal_gicd_init()
{
    //1 GICD control register (GICD_CTLR)
    GICD->CTRL|= (0x1<<0); //使能组0

    //2. GICD_ISENABLERx
    //key1 PF9 ==> EXTI9 ----> 事件9 --->中断号 99
    GICD->ISENABLER[3] |= (0x1<<3);
    //key2 PF7 ==> EXTI7 ----> 事件7 --->中断号 97
    GICD->ISENABLER[3] |= (0x1<<1);
    //key3 PF8 ==> EXTI8 ----> 事件8 --->中断号 98
    GICD->ISENABLER[3] |= (0x1<<2);

    //2. GICD_IPRIORITYR  
    //key1 PF9 ==> EXTI9 ----> 事件9 --->中断号 99
    GICD->IPRIORITYR[24] |= (0x1<<27);  //中断优先级设置相同
    
    //key2 PF7 ==> EXTI7 ----> 事件7 --->中断号 97
    GICD->IPRIORITYR[24] |= (0x1<<11);  //中断优先级设置相同

    //key3 PF8 ==> EXTI8 ----> 事件8 --->中断号 98
    GICD->IPRIORITYR[24] |= (0x1<<19);  //中断优先级设置相同

    //2. GICD_ITARGETSRx
    //key1 PF9 ==> EXTI9 ----> 事件9 --->中断号 99
    GICD->ITARGETSR[24] |= (0x3<<24); //分配给cpu0
    
    //key2 PF7 ==> EXTI7 ----> 事件7 --->中断号 97
    GICD->ITARGETSR[24] |= (0x3<<8); //分配给cpu0
  

    //key3 PF8 ==> EXTI8 ----> 事件8 --->中断号 98
    GICD->ITARGETSR[24] |= (0x3<<16); //分配给cpu0


    //3. GICD_ICPENDRx 
    //key1 PF9 ==> EXTI9 ----> 事件9 --->中断号 99
    GICD->ICPENDR[3] |= (0x1<<3);
    //key2 PF7 ==> EXTI7 ----> 事件7 --->中断号 97
    GICD->ICPENDR[3] |= (0x1<<1);
    //key3 PF8 ==> EXTI8 ----> 事件8 --->中断号 98
    GICD->ICPENDR[3] |= (0x1<<2);
    

}


void hal_gicc_init()
{
    //GICC_CTLR寄存器
    GICC->CTRL |= (0x1<<0);

    //GICC_PMR寄存器
    GICC->PMR |= (0x2<<4);
}