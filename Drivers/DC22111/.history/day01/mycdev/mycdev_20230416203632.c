#include <linux/init.h>
#include <linux/module.h>



int __init mycdev_init(void)
{
    return 0;
}

void __exit mycdev_exit(void)
{

}

module_init(mycdev_init);
module_exit(mycdev_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Satoshi Nakamoto");