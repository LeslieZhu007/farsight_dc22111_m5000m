#include <linux/init.h>
#include <linux/module.h>
#include <linux/platform_device.h>




static int __init pdrv_init(void)
{
    platform_driver_register();
    
    return 0;
}



static void __exit pdrv_exit(void)
{
    platform_driver_unregister();

}
module_init(pdrv_init);
module_exit(pdrv_exit);
MODULE_LICENSE("GPL");