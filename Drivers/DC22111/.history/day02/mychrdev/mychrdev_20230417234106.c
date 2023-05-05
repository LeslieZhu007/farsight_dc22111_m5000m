#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>



int __init mychrdev_init(void)
{
    //字符设备驱动注册
    register_chrdev(0,"mychrdev",);
    return 0;
}

void __exit mychrdev_exit(void)
{
    unregister_chrdev();
}


module_init(mychrdev_init);
module_exit(mychrdev_exit);
MODULE_LICENSE("GPL");
