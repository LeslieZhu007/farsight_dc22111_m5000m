#include <linux/init.h>
#include <linux/module.h>
#include <linux/of.h>


struct device_node *dnode;
int gpiono;
static int __init mygpio_init(void)
{
    //解析myled设备树节点
    dnode = of_find_node_by_name(NULL,"myleds");
    if(NULL == dnode)
    {
        printk("解析设备树节点失败\n");
        return -1;
    }
    //基于设备树节点解析出LED1的GPIO编号
    




    return 0;
}
static void __exit mygpio_exit(void)
{


}


module_init(mygpio_init);
module_exit(mygpio_exit);
MODULE_LICENSE("GPL");
