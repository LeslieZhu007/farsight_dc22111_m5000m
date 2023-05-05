#include <linux/init.h>
#include <linux/module.h>
#include <linux/of.h>

//自定义设备树
	// mynode@0x12345678{
	// 	compatible = "hqyj,mynode";
	// 	astring = "hello 22111";
	// 	uint = <0xaabbccdd 0x11223344>;
	// 	binarray = [00 0c 29 7b f9 be];
	// 	mixed = "hello",[11 22],<0x12345678>;
	// };

struct device_node * dnode; //用来指向解析的设备树节点

struct property *pr;

static int __init device_tree_init(void)
{
    //获取设备节点的信息api
    dnode = of_find_node_by_name(NULL,"mynode");
    if (NULL == dnode)
    {
        printk("解析设备树节点失败\n");
        return -ENODEV;
    }
    /*
    printk("name:%s,value:%s\n",dnode->properties->name,(char *)dnode->properties->value);
    printk("name:%s,value:%x %x\n",dnode->properties->next->name,
    __be32_to_cpup((unsigned int *)dnode->properties->next->value),
   __be32_to_cpup(((unsigned int *)dnode->properties->next->value)+1));  //数值在地址空间角度是连续的 （数组) 
    */  
   //根据解析得到的设备节点信息解析属性api  of_find_property 
   //根据设备树节点和指定键名解析处指定的属性结构体信息

    pr = of_find_property(dnode, "binarray", NULL);
    return 0;
}
static void __exit device_tree_exit(void)
{


}
module_init(device_tree_init);
module_exit(device_tree_exit);
MODULE_LICENSE("GPL");