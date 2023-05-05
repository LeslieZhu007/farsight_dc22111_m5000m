#include <linux/init.h>
#include <linux/module.h>


int add(int i,int j)
{
    return i+j;
}

//将add函数的符号表导出
EXPORT_SYMBOL_GPL(add);

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
