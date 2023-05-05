#include <linux/init.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/of_gpio.h>

struct device_node *dnode;
int gpiono1;
int gpiono2;
int gpiono3;
static int __init mygpio_init(void)
{
    //解析myled设备树节点
    dnode = of_find_node_by_name(NULL,"myleds");
    if(NULL == dnode)
    {
        printk("解析设备树节点失败\n");
        return -1;
    }
    printk("解析设备树节点成功\n");
    //基于设备树节点解析出LED1的GPIO编号
    gpiono1 = of_get_named_gpio(dnode, "myled1",0);
    if(gpiono1 < 0)
    {
        printk("解析LED1的GPIO编号失败\n");
        return -1;
    }
    printk("解析LED1的GPIO编号成功\n");

    gpiono2 = of_get_named_gpio(dnode, "myled2",0);
    if(gpiono2 < 0)
    {
        printk("解析LED2的GPIO编号失败\n");
        return -1;
    }
    printk("解析LED2的GPIO编号成功\n");

    gpiono3 = of_get_named_gpio(dnode, "myled3",0);
    if(gpiono3 < 0)
    {
        printk("解析LED3的GPIO编号失败\n");
        return -1;
    }
    printk("解析LED3的GPIO编号成功\n");

    //向内核申请GPIO编号
    


    return 0;
}




    return 0;
}
static void __exit mygpio_exit(void)
{


}


module_init(mygpio_init);
module_exit(mygpio_exit);
MODULE_LICENSE("GPL");
