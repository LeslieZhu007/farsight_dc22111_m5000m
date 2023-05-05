#include <linux/init.h>
#include <linux/module.h>

static int __init mycdev_init(void)
{
    //static作用是限制这个函数只能在当前文件使用
    //__开头是告诉编译器一些内容的
    //__init作用是吧这个函数放在.init.text段中，方便查找
    //#define __init  __section(".init.text")
    //在内核里面内核源码也有自己的链接脚本文件用于指定不同段落vmlinux.lds
    printk(KERN_ERR "==> 2023.4.17");
    return 0;
}

static void __exit mycdev_exit(void)
{
    //#define __exit        __section(".exit.text")
}

module_init(mycdev_init);
module_exit(mycdev_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Satoshi Nakamoto");