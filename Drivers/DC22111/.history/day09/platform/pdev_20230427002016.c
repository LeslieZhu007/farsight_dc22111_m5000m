#include <linux/init.h>
#include <linux/module.h>
#include <linux/platform_device.h>



void pdev_release (struct device *dev)
{
    printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
}

struct resource	res[] =
{
    [0] = 
    {
        .start = 0X12345678,
        .end = 0x12345678+49,
        .flags = IORESOURCE_MEM,
    },
    [1] = 
    {
        .start = 71,
        .end = 71,
        .flags = IORESOURCE_IRQ,
    },
};

struct platform_device pdev = 
{
    .name = "aaaa",
    .id = PLATFORM_DEVID_AUTO,
    .dev = {
      .release = pdev_release,
    },
    .num_resources = ARRAY_SIZE(res),
    .resource = res,
};

static int __init pdev_init(void)
{
    //注册对象
    platform_device_register(&pdev);

    return 0;
}
static void __exit pdev_exit(void)
{
    //注销
    platform_device_unregister(&pdev);
}
module_init(pdev_init);
module_exit(pdev_exit);
MODULE_LICENSE("GPL");