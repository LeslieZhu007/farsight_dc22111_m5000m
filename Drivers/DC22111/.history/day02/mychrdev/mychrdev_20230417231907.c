#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>



int __init mychrdev_init(void)
{
    return 0;
}

void __exit mychrdev_exit(void)
{

}

module_init(mychrdev_init);
module_exit(mychrdev_exit);
MODULE_LICENSE("GPL");