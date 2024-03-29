#include <linux/init.h>
#include <linux/module.h>
#include <linux/interrupt.h>
#include <linux/of.h>
#include <linux/of_irq.h>


struct device_node *dnode;
unsigned int irqno; //key1
unsigned int irqno0; //key2
unsigned int irqno1; //key3

//分配底半部对象
struct work_struct work;
//底半部处理函数
void myirq_func(struct tasklet_struct *work)
{
    for (int i = 0; i < 50;i++) {
        printk("i = %d\n",i);

    }
}


//key1 中断处理函数
irqreturn_t  myirq_handler  (int irqno,void *arg)
{
    printk("key1-interrupt\n");

    //开启底半部
    tasklet_schedule(&tasklet);
    return IRQ_HANDLED;
}

//key2 中断处理函数
irqreturn_t  myirq_handler0  (int irqno0,void *arg)
{
    printk("key2-interrupt\n");
    return IRQ_HANDLED;
}

//key3 中断处理函数
irqreturn_t  myirq_handler1  (int irqno1,void *arg)
{
    printk("key3-interrupt\n");
    return IRQ_HANDLED;
}



static int __init mykey_init(void)
{
    int ret;
    //解析设备树节点
    dnode = of_find_node_by_path("/myirq");
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
        printk("key1软中断号申请失败\n");
        return -1;
    }
    printk("key1软中断号申请成功:%d\n",irqno);

    irqno0 = irq_of_parse_and_map(dnode,1);
    if(!irqno0)
    {
        printk("key2软中断号申请失败\n");
        return -1;
    }
    printk("key2软中断号申请成功:%d\n",irqno0);


    irqno1 = irq_of_parse_and_map(dnode,2);
    if(!irqno1)
    {
        printk("key3软中断号申请失败\n");
        return -1;
    }
    printk("key3软中断号申请成功:%d\n",irqno1);


    //注册中断
    ret = request_irq(irqno,myirq_handler,IRQF_TRIGGER_FALLING,"myirq",NULL);
    if(ret)
    {
        printk("key1注册中断失败\n");
        return -1;
    }

    printk("key1注册中断成功\n");

    ret = request_irq(irqno0,myirq_handler0,IRQF_TRIGGER_FALLING,"myirq",NULL);
    if(ret)
    {
        printk("key2注册中断失败\n");
        return -1;
    }

    printk("key2注册中断成功\n");


    ret = request_irq(irqno1,myirq_handler1,IRQF_TRIGGER_FALLING,"myirq",NULL);
    if(ret)
    {
        printk("key3注册中断失败\n");
        return -1;
    }

    printk("key3注册中断成功\n");


    //初始化底半部
    tasklet_setup(&tasklet,myirq_callback);

    
    return 0;
}
static void __exit mykey_exit(void)
{
    //注销
    free_irq(irqno,NULL);
    free_irq(irqno0,NULL);
    free_irq(irqno1,NULL);
    printk("注销成功\n");

}
module_init(mykey_init);
module_exit(mykey_exit);
MODULE_LICENSE("GPL");