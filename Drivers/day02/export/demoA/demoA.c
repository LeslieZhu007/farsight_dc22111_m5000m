#include <linux/init.h>
#include <linux/module.h>

int add(int a,int b)
{
	return (a+b);
}
EXPORT_SYMBOL_GPL(add);

static int __init demo_init(void)
{

	return 0;
}


static void __exit demo_exit(void)
{


}

module_init(demo_init);
module_exit(demo_exit);

MODULE_LICENSE("GPL");
