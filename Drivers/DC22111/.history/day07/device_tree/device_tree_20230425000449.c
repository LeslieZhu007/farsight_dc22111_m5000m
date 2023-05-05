#include <linux/init.h>
#include <linux/module.h>
#include <linux/of.h>

struct device_node * dnode; //用来指向解析的设备树节点

static int __init device_tree_init(void)
{
    
    return 0;
}
static void __exit device_tree_exit(void)
{


}
module_init(device_tree_init);
module_exit(device_tree_exit);
MODULE_LICENSE("GPL");