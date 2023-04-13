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
        /* code */
        break;
    case 98:
        /* code */
        break;
    case 97:
        /* code */
        break;
    
    default:
        break;
    }
    

    //清除中断挂起标志位，清除中断号
}
