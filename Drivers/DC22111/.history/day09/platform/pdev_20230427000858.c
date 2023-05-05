#include <linux/init.h>
#include <linux/module.h>

static int __init pdev_init(void)
{
    //注册对象



    
    return 0;
}
static void __exit pdev_exit(void)
{
    

}
module_init(pdev_init);
module_exit(pdev_exit);
MODULE_LICENSE("GPL");