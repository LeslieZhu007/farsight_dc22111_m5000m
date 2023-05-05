#include <linux/init.h>
#include <linux/module.h>

static int __init pdev_init(void)
{
    //注册对象
    platform_device_register();

    return 0;
}
static void __exit pdev_exit(void)
{
    //注销

}
module_init(pdev_init);
module_exit(pdev_exit);
MODULE_LICENSE("GPL");