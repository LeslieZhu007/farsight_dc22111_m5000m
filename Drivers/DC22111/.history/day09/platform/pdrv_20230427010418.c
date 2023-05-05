#include <linux/init.h>
#include <linux/module.h>
#include <linux/platform_device.h>


struct platform_driver pdrv = 
{
    .probe = pdrv_probe,
    .remove = pdrv_remove,
    .driver = {
        .name = "aaaa",
    }

};

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
MODULE_LICENSE("GPL");