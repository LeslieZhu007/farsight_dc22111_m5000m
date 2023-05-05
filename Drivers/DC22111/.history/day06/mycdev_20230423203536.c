#include <linux/init.h>
#include <linux/module.h>
#include<linux/fs.h>
#include<linux/io.h>
#include<linux/device.h>
#include<linux/uaccess.h>




static int __init mycdev_init(void)
{
    



    return 0;
}
static void __exit mycdev_exit(void)
{


}
module_init(mycdev_init);
module_exit(mycdev_exit);
MODULE_LICENSE("GPL");