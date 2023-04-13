#include "key.h"
extern void printf(const char *fmt, ...);
unsigned int i = 0;
void do_irq(void) 
{
    //获取中断号
    unsigned int interrupt_no = (GICC->IAR & 0x3ff);  //0-9位 10位==> 0x3ff
    printf("interrupt_no = %d\n\r",interrupt_no);
    //判断中断号
    switch (interrupt_no)
    {
    case 99:
        printf("key1###############\r\n");
        //1. 清除中断挂起标志位
        EXTI->FPR1 |= (0x1<<9);
        // 清除GICD层中断挂起标志位
         GICD->ICPENDR[3] |= (0x1<<3);
        //2. 清除中断号
        /*
        GICC->EOIR &= (~(0x1ff<<0));
        GICC->EOIR |= (interrupt_no<<0);
        */
        break;
    case 97:
        printf("key2###############\r\n");
        //1. 清除中断挂起标志位
        EXTI->FPR1 |= (0x1<<7);
        // 清除GICD层中断挂起标志位
        GICD->ICPENDR[3] |= (0x1<<1);
        /*
        //2. 清除中断号
        GICC->EOIR &= (~(0x1ff<<0));
        GICC->EOIR |= (interrupt_no<<0);
        */
        break;
    case 98:
        printf("key3###############\r\n");
        //1. 清除中断挂起标志位
        EXTI->FPR1 |= (0x1<<8);
        // 清除GICD层中断挂起标志位
        GICD->ICPENDR[3] |= (0x1<<2);
        /*
        //2. 清除中断号
        GICC->EOIR &= (~(0x1ff<<0));
        GICC->EOIR |= (interrupt_no<<0);
        */
        break;
    
    default:
        break;
    }
    
    //清除中断号可以在switch外执行
    GICC->EOIR = interrupt_no;

}
