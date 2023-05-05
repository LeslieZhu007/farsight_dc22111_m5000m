#include <linux/init.h>
#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/mod_devicetable.h>
#include <linux/of.h>
#include <linux/of_gpio.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <linux/slab.h>
#include <linux/fs.h>

//在platform驱动中获取设备信息
struct resource *res;
int irqno; //key1
int irqno0; //key2
int irqno1; //key3

struct device_node	*dnode;
struct gpio_desc *desc; //led1
struct gpio_desc *desc0;//led2
struct gpio_desc *desc1;//led3
unsigned int minor = 0;
unsigned int major = 0;
struct cdev *cdev;
dev_t devno;
char kbuf[128] = {0};
struct class *cls;
struct device *dev; 
int i = 0;


int led_init(struct device_node *dnode);

int pdrv_probe (struct platform_device *pdev)
{
    printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
    //获取MEM类型的设备资源
    res = platform_get_resource(pdev,IORESOURCE_MEM, 0);
    if (NULL == res )
    {
        printk("获取设备信息失败\n");
        return -ENODATA;
    }

    //获取中断类型资源
    irqno = platform_get_irq(pdev, 0);
    if (irqno < 0 )
    {
        printk("获取key1中断类型资源失败\n");
        return -ENODATA;
    }
    irqno0 = platform_get_irq(pdev, 1);
    if (irqno0 < 0 )
    {
        printk("获取key2中断类型资源失败\n");
        return -ENODATA;
    }
    irqno1 = platform_get_irq(pdev, 2);
    if (irqno1 < 0 )
    {
        printk("获取key3中断类型资源失败\n");
        return -ENODATA;
    }

    printk("mem类型的资源数值为: %x\n",res->start);
    printk("key1中断类型的资源数值为%d\n",irqno);
    printk("key2中断类型的资源数值为%d\n",irqno0);
    printk("key3中断类型的资源数值为%d\n",irqno1);


    dnode = pdev->dev.of_node;
    led_init(dnode);
    
    return 0;


}


int pdrv_remove (struct platform_device *pdev)
{




    printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
    return 0;

}

/*
//构建名字表
const struct platform_device_id idtable[] =
{
    {"aaaa",0},
    {"bbbb",1},
    {"cccc",2},
    {"dddd",3},
    {"eeee",4},
    {"ffff",5},
    {},
};
*/
//构建设备树匹配
struct of_device_id oftable[] = 
{
    {.compatible = "hqyj,platform",},
    {.compatible = "hqyj,platform1",},
    {},
};

struct platform_driver pdrv = 
{
    .probe = pdrv_probe,
    .remove = pdrv_remove,
    .driver = {
        .name = "aaaa",
        .of_match_table = oftable
    },
    //.id_table = idtable,  //非设备树匹配
};


int led_init(struct device_node *dnode)
{   
    desc = gpiod_get_from_of_node(dnode,"myled1",0,GPIOD_OUT_LOW,NULL) ;
    if(IS_ERR(desc))
    {
        printk("解析LED0对象失败\n");
        return PTR_ERR(desc);
    }
    printk("解析LED0对象成功\n");


    desc0 = gpiod_get_from_of_node(dnode,"myled2",0,GPIOD_OUT_LOW,NULL) ;
    if(IS_ERR(desc0))
    {
        printk("解析LED1对象失败\n");
        return PTR_ERR(desc0);
    }
    printk("解析LED1对象成功\n");


    desc1 = gpiod_get_from_of_node(dnode,"myled3",0,GPIOD_OUT_LOW,NULL) ;
    if(IS_ERR(desc1))
    {
        printk("解析LED2对象失败\n");
        return PTR_ERR(desc1);
    }
    printk("解析LED2对象成功\n");

    if( gpiod_direction_output(desc,0))
    {
        printk("设置LED0输出失败\n");
        return -1;
    }
     printk("设置LED0输出成功\n");

     if( gpiod_direction_output(desc0,0))
    {
        printk("设置LED1输出失败\n");
        return -1;
    }
     printk("设置LED1输出成功\n");

     if( gpiod_direction_output(desc1,0))
    {
        printk("设置LED2输出失败\n");
        return -1;
    }
     printk("设置LED2输出成功\n");

     return 0;

}

/* 
//可被一键注册宏 module_platform_drive 所取代
static int __init pdrv_init(void)
{
    platform_driver_register(&pdrv);
    
    return 0;
}
static void __exit pdrv_exit(void)
{
    platform_driver_unregister(&pdrv);
}
module_init(pdrv_init);
module_exit(pdrv_exit);
*/
module_platform_driver(pdrv);
MODULE_LICENSE("GPL");