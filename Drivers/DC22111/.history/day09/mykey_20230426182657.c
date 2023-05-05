#include <linux/init.h>
#include <linux/module.h>

static int __init mykey_init(void)
{
    //解析设备树节点


    //根据设备树节点解析出软中断号


    //注册中断


    
    return 0;
}
static void __exit mykey_exit(void)
{
    //注销

}
module_init(mykey_init);
module_exit(mykey_exit);
MODULE_LICENSE("GPL");