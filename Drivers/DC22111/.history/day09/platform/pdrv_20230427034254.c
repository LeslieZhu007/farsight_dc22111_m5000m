#include <linux/init.h>
#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/mod_devicetable.h>

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
        printk("获取设备信息失败\n");
        return -ENODATA;
    }

    //获取中断类型资源
    irqno = platform_get_irq(pdev, 0);
    if (irqno < 0 )
    {
        printk("获取中断类型资源失败\n");
        return -ENODATA;
    }

    printk("mem类型的资源数值为: %x\n",res->start);
    printk("中断类型的资源数值为%d\n",irqno);

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
    {"bbbb",0},
    {"cccc",0},
    {"dddd",0},
    {"eeee",0},
    {"ffff",0},
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
    },
    //.id_table = oftable,

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