#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/io.h>
#include "head.h"

unsigned int major;
char kbuf[128] = {0};
int mychrdev_open (struct inode *inode, struct file *file)
{
    printk ("%s:%s:%d\n",__FILE__, __func__, __LINE__);
    return 0;
}
ssize_t mychrdev_read (struct file *file, char  *ubuf, size_t size, loff_t *lof)
{
 
    printk ("%s:%s:%d\n",__FILE__, __func__, __LINE__);
    unsigned long ret;
    //向内核空间拷贝数据
    if(size > sizeof(kbuf)) //    
    {
        size = sizeof(kbuf);
    }
    ret = copy_to_user(ubuf,kbuf,size);
    if(ret)
    {
        printk ("copy to user failed\n");
        return ret;
    }
    return 0;
}
ssize_t mychrdev_write (struct file *file, const char *ubuf, size_t size, loff_t *lof)
{ 
    unsigned long ret;
    //从用户空间读取数据
    if(size > sizeof(kbuf)) //    
    {
        size = sizeof(kbuf);
    }
    ret = copy_from_user(kbuf,ubuf,size);
    if(ret)
    {
        printk ("copy from user failed\n");
        return ret;
    }
    printk ("%s:%s:%d\n",__FILE__, __func__, __LINE__);
    if ('1' == kbuf[0]) 
    {
        printk("%s\n","Lights on by kernel");
    } else if ('0' == kbuf[0])
    {
        printk("%s\n","Lights off by kernel");
    }
    return 0;
}

int mychrdev_close (struct inode *inode, struct file *file)
{
    printk ("%s:%s:%d\n",__FILE__, __func__, __LINE__);
    return 0;
}

const struct file_operations fops = 
{
    .open = mychrdev_open,
    .read =mychrdev_read,
    .write =mychrdev_write,
    .release =mychrdev_close,
};

static int __init mychrdev_init(void)
{
    //字符设备驱动注册
    major = register_chrdev(0,"mychrdev",&fops);
    if (major < 0)
    {
        printk(" register_chrdev failed\n");
        return major;
    }
     printk("register_chrdev succeeded:major=%d\n",major);
    return 0;
}

static void __exit mychrdev_exit(void)
{
    //注销字符设备驱动
    unregister_chrdev(major,"mychrdev");
}


module_init(mychrdev_init);
module_exit(mychrdev_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Satoshi Nakamoto");