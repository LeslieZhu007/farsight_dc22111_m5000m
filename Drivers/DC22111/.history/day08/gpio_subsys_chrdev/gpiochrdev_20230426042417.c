#include <linux/init.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/of_gpio.h>

struct device_node *dnode;
struct gpio_desc *desc; //led1
struct gpio_desc *desc0;//led2
struct gpio_desc *desc1;//led3


static int __init gpiochrdev_init(void)
{
    






    return 0;
}
static void __exit gpiochrdev_exit(void)
{


}
module_init(gpiochrdev_init);
module_exit(gpiochrdev_exit);
MODULE_LICENSE("GPL");