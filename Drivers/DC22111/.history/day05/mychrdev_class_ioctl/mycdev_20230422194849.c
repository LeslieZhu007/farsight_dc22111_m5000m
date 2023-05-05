#include <linux/init.h>
#include <linux/module.h>
#include <linux/cdev.h>

struct cdev* cdev;
ssize_t mycdev_read (struct file *file, char __user *ubuf, size_t size, loff_t *loff)
{
    return 0;
}
ssize_t mycdev_write (struct file *file, const char __user *ubuf, size_t size, loff_t *loff)
{
    
}

const struct file_operations fops = 
{
    .read = mycdev_read,
    .write = mycdev_write,
};


static int __init mycdev_init(void)
{
    //1.分配字符设备驱动对象空间
    cdev = cdev_alloc();
    if (!cdev)
    {
        goto out;
    }

    //2.初始化字符设备驱动对象
    cdev_init(cdev,&fops);

    //3.申请设备号
    //动态申请设备号

    //4.注册

    //5.向上提交目录


    //6.向上提交设备节点信息
out:   
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