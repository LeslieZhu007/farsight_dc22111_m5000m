#include <linux/init.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/of_gpio.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <linux/slab.h>
#include <linux/fs.h>

struct device_node *dnode;
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

void led_init();



static int __init gpiochrdev_init(void)
{
    //初始化LED灯
    led_init();
    
    int ret;
    //1.分配字符设备驱动对象空间
    cdev = cdev_alloc();
    if(NULL == cdev)
    {
        printk("申请字符设备驱动对象空间失败\n");
        ret = -ENOMEM;
        goto ERR1;
    }
    

    /*
    gpiod_set_value(desc, 1);
    gpiod_set_value(desc0, 1);
    gpiod_set_value(desc1, 1);
    */
    






    return 0;
ERR1:
    return ret;
}
static void __exit gpiochrdev_exit(void)
{


    //灭灯
    gpiod_set_value(desc, 0);
    gpiod_set_value(desc0, 0);
    gpiod_set_value(desc1, 0);
    //释放gpio
    gpiod_put(desc);
    gpiod_put(desc0);
    gpiod_put(desc1);

}


void led_init()
{
    //解析myled设备树节点
    dnode = of_find_node_by_name(NULL,"myleds");
    if(NULL == dnode)
    {
        printk("解析设备树节点失败\n");
        return -1;
    }
    printk("解析设备树节点成功\n");
    
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
}
module_init(gpiochrdev_init);
module_exit(gpiochrdev_exit);
MODULE_LICENSE("GPL");