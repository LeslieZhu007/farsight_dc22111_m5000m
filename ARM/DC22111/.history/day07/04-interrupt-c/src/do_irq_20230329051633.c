#include "key.h"
extern void printf(const char *fmt, ...);
unsigned int i = 0;
void do_irq(void) 
{
    //获取中断号
    int interrupt_no = (GICC->IAR & 0x1ff);

    //判断中断号

    //清除中断挂起标志位，清除中断号
}
