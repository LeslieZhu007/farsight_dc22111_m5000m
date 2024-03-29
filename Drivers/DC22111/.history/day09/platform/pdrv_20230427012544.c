#include <linux/init.h>
#include <linux/module.h>
#include <linux/platform_device.h>


//在platform驱动中获取设备信息
struct resource *res;
int irqno;

int pdrv_probe (struct platform_device *pdev)
{
    printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
    //获取MEM类型的设备资源
    res = platform_get_resource(pdev,IORESOURCE_MEM, 0);
    if (NULL == res )
    {
        printf("获取设备信息失败\n");
        return -ENODATA;
    }

    //获取中断类型资源
    irqno = platform_get_irq(pdev, 0);
    if (irqno < 0 )
    {
        printf("获取设备信息失败\n");
        return -ENODATA;
    }





    return 0;
}
int pdrv_remove (struct platform_device *pdev)
{
    printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
    return 0;

}

struct platform_driver pdrv = 
{
    .probe = pdrv_probe,
    .remove = pdrv_remove,
    .driver = {
        .name = "aaaa",
    }

};

/*
//可被一键注册宏所取代
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