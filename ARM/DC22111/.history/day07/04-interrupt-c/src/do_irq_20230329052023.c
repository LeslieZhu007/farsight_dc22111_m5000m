#include "key.h"
extern void printf(const char *fmt, ...);
unsigned int i = 0;
void do_irq(void) 
{
    //获取中断号
    int interrupt_no = (GICC->IAR & 0x1ff);
    printf("interrupt_no = %d\n\r",interrupt_no);
    //判断中断号
    switch (interrupt_no)
    {
    case 99:
        printf("key1###############\r\n");
        break;
    case 98:
        printf("key2###############\r\n");
        break;
    case 97:
        printf("key3###############\r\n");
        break;
    
    default:
        break;
    }
    
    //清除中断挂起标志位，清除中断号

    //1. 清除中断挂起标志位


    //2. 清除中断号
}
