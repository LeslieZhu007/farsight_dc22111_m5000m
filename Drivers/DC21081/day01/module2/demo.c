#include <linux/init.h>
#include <linux/module.h>

static int __init demo_init(void)
{
	printk(KERN_ERR "This is 21081 driver init\n");
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
	printk(KERN_INFO "*************888%s:%s:%d\n",__FILE__,__func__,__LINE__);
	return 0;
}


static void __exit demo_exit(void)
{

	printk(KERN_ERR "This is 21081 driver exit\n");
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);

}

module_init(demo_init);
module_exit(demo_exit);

MODULE_LICENSE("GPL");
