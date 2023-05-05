#include <linux/init.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/of_gpio.h>
#include <linux/timer.h>

struct device_node *dnode;
struct gpio_desc *desc; //led0
struct gpio_desc *desc0;//led1
struct gpio_desc *desc1;//led2

//定义一个定时器对象
struct timer_list mytimer;

//定时器处理函数
void callback_function(struct timer_list *timer)
{   
    gpiod_set_value(desc, !gpiod_get_value(desc));
    gpiod_set_value(desc0,!gpiod_get_value(desc));
    gpiod_set_value(desc1,!gpiod_get_value(desc));
}

static int __init mygpio_init(void)
{
    //2.初始化定时器
    mytimer.expires = jiffies+HZ;  //定时1s   // HZ  CONFIG_HZ
    timer_setup(&mytimer,callback_function,0);

    //3.注册对象进内核并启用定时器
    add_timer(&mytimer);

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

    /*
    gpiod_set_value(desc, 1);
    gpiod_set_value(desc0, 1);
    gpiod_set_value(desc1, 1);
    */

    return 0;

}
static void __exit mygpio_exit(void)
{
    //灭灯
     gpiod_set_value(desc, 0);
     gpiod_set_value(desc0, 0);
     gpiod_set_value(desc1, 0);
    //释放gpio
    gpiod_put(desc);
    gpiod_put(desc0);
    gpiod_put(desc1);

    //注销定时器对象
    del_timer(&mytimer);
}

}

module_init(mygpio_init);
module_exit(mygpio_exit);
MODULE_LICENSE("GPL");
