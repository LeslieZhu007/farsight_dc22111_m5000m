#include <linux/init.h>
#include <linux/module.h>
#include <linux/cdev.h>

struct cdev* cdev;
static int __init mycdev_init(void)
{
    //1.分配字符设备驱动对象空间
    cdev = cdev_alloc();

    //2.初始化字符设备驱动对象


    //3.申请设备号

    //4.注册

    //5.向上提交目录


    //6.向上提交设备节点信息
    
    return 0;
}
static void __exit mycdev_exit(void)
{
    //1.销毁设备信息结构体

    //2.销毁目录结构体

    //3.注销字符设备驱动对象

    //4.释放设备号

    //5.释放对象空间

}
module_init(mycdev_init);
module_exit(mycdev_exit);
MODULE_LICENSE("GPL");