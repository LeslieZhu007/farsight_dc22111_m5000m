#include <linux/init.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/of_gpio.h>

struct device_node *dnode;
struct gpio_desc *desc;
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
    
    desc = gpiod_get_from_of_node(dnode,"myleds",0,GPIOD_OUT_LOW,NULL) ;
    if(IS_ERR(desc))
    {
        printk("解析GPIO对象失败\n");
        return PTR_ERR(desc);
    }
    printk("解析GPIO对象成功\n");

    return 0;

}
static void __exit mygpio_exit(void)
{
    //灭灯
    gpio_set_value(gpiono1,0);
    gpio_set_value(gpiono2,0);
    gpio_set_value(gpiono3,0);

    //释放gpio
    gpio_free(gpiono1);
    gpio_free(gpiono2);
    gpio_free(gpiono3);

}


void led_control()
{
    gpio_set_value(gpiono1,1);
    gpio_set_value(gpiono2,1);
    gpio_set_value(gpiono3,1);
}


module_init(mygpio_init);
module_exit(mygpio_exit);
MODULE_LICENSE("GPL");
