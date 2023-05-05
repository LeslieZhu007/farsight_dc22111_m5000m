#include <linux/init.h>
#include <linux/module.h>
#include <linux/interrupt.h>
#include <linux/of.h>


struct device_node *dnode;
unsigned int irqno;



//中断处理函数
irqreturn_t  myirq_handler  (int irqno,void *arg)
{


    printk("key1-interrupt\n");
    return IRQ_HANDLED;
}




static int __init mykey_init(void)
{
    int ret;
    //解析设备树节点
    dnode = of_find_node_by_name("/myirq");
    if (NULL == dnode)
    {
        printk("解析设备树节点失败\n");
        return -1;
    }
    printk("解析设备树节点成功\n");
    //根据设备树节点解析出软中断号
    irqno = irq_of_parse_and_map(dnode,0);
    if(!irqno)
    {
        printk("软中断号申请失败\n");
        return -1;
    }
    printk("软中断号申请成功:%d\n",irqno);
    //注册中断
    ret = request_irq(irqno,myirq_handler,IRQF_TRIGGER_FALLING,"myirq",NULL);
    if(ret)
    {
        printk("注册中断失败\n");
        return -1;
    }

    printk("注册中断成功\n");

    
    return 0;
}
static void __exit mykey_exit(void)
{
    //注销
    free_irq(irqno,NULL);
    printk("注销成功\n");

}
module_init(mykey_init);
module_exit(mykey_exit);
MODULE_LICENSE("GPL");