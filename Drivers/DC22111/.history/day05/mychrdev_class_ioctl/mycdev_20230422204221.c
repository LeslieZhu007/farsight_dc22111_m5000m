#include <linux/init.h>
#include <linux/module.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <linux/slab.h>

#if 0
    unsigned int major=0;
#else
    unsigned int major=500;

#endif

unsigned minor=0;
struct cdev* cdev;
dev_t devno;
char kbuf[128] = {0};
struct class *cls;
struct device *dev;
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
    int ret;
    //1.分配字符设备驱动对象空间
    cdev = cdev_alloc();
    if (NULL==cdev)
    {
        printk("申请字符设备驱动对象空间失败\n");
        ret = -ENOMEM;
        goto ERR1;
    }
    printk("申请字符设备驱动对象空间成功\n");


    //2.初始化字符设备驱动对象
    cdev_init(cdev,&fops);

    //3.申请设备号
    if(0==major)
    {
        //动态申请设备号
        ret = alloc_chrdev_region(&devno,minor,3,"myled");
        if (ret)
        {
            printk("动态申请设备号失败\n");
            goto ERR2;
        }
        //通过设备号获取主设备号和次设备号
        major = MAJOR(devno);
        minor = MINOR(devno);

    } else if ( major > 0)
    {
        //静态指定设备号
        ret = register_chrdev_region(MKDEV(major,minor),3,"myled");
      
        if (ret)
        {
            printk("静态指定设备号失败\n");
            goto ERR2;
        }
        printk("静态指定设备号成功\n");
    }
    

    //4.注册
    ret = cdev_add(cdev,MKDEV(major,minor),3);
    if (ret)
    {
        printk("注册字符设备驱动对象失败\n");
        goto ERR3;
        
    }

    return 0;



    //5.向上提交目录
    cls = class_create(THIS_MODULE, "myled");
    if (IS_ERR(cls))
    {
        printk("向上提交目录失败\n");
        ret = PTR_ERR(cls);
        goto ERR4;
    }
    printk("向上提交目录成功\n");

    //6.向上提交设备节点信息
    int i;
    for(i=0;i<3;i++)
    {
        dev=device_create(cls,NULL,MKDEV(major,minor),NULL,"myled%d",i);
        if(IS_ERR(dev))
        {
            printk("向上提交设备信息失败\n");
            ret = PTR_ERR(dev);
            goto ERR5;
        }
    }
 
    return 0;
ERR5:
    for(--i;i>=0;i--)
    {
        device_destroy(cls,MKDEV(major,i));
    }
    class_destroy(cls);
ERR4:
    cdev_del(cdev);
ERR3:
    unregister_chrdev_region(MKDEV(major,minor),3);
ERR2:
    kfree(cdev);
ERR1:
    return ret;
}
static void __exit mycdev_exit(void)
{
    //1.销毁设备信息结构体
    int i;
    for(i=0;i<3;i++)
    {
        device_destroy(cls,MKDEV(major,i));
    }
    
    //2.销毁目录结构体
    class_destroy(cls);

    //3.注销字符设备驱动对象
    cdev_del(cdev);

    //4.释放设备号
    unregister_chrdev_region(MKDEV(major,minor),3);

    //5.释放对象空间
     kfree(cdev);
}
module_init(mycdev_init);
module_exit(mycdev_exit);
MODULE_LICENSE("GPL");