#include <linux/init.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/of_gpio.h>
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