#include <linux/init.h>
#include <linux/module.h>

extern int add(int i,int j);

static int __init mycdev_init(void)
{

    printk("%d\n",add(3,5));
    return 0;
}

static void __exit mycdev_exit(void)
{

}

module_init(mycdev_init);
module_exit(mycdev_exit);
MODULE_LICENSE("GPL");
