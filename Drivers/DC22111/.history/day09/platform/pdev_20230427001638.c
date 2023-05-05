#include <linux/init.h>
#include <linux/module.h>
#include <linux/platform_device.h>



void pdev_release (struct device *dev)
{
    printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
}

struct platform_device pdev = 
{
    .name = "aaaa",
    .id = PLATFORM_DEVID_AUTO,
    .dev = {
      .release = pdev_release,
    },
    .num_resources = ARRAY_SIZE(),
    .resource = res,
};

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