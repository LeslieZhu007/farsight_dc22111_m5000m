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
    if(gpio_request(gpiono1,NULL))
    {
        printk("申请LED1失败\n");
        return -1;
    }

     if(gpio_request(gpiono2,NULL))
    {
        printk("申请LED2失败\n");
        return -1;
    }

     if(gpio_request(gpiono3,NULL))
    {
        printk("申请LED3失败\n");
        return -1;
    }

    //设置gpio功能为输出并且设置一个输出的初始值
    if(gpio_direction_output(gpiono1,0))
    {
        printk("设置LED1输出失败\n");
        return -1;
    }

     if(gpio_direction_output(gpiono2,0))
    {
        printk("设置LED2输出失败\n");
        return -1;
    }

     if(gpio_direction_output(gpiono3,0))
    {
        printk("设置LED3输出失败\n");
        return -1;
    }

    //设置输出值
    gpio_set_value(gpiono1,1);
    gpio_set_value(gpiono2,1);
    gpio_set_value(gpiono3,1);

    return 0;
}


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
