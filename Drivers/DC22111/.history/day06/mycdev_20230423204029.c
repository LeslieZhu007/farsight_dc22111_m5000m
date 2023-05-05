#include <linux/init.h>
#include <linux/module.h>
#include<linux/fs.h>
#include<linux/io.h>
#include<linux/device.h>
#include<linux/uaccess.h>

int major;
char kbuf[128]={0};
struct class *cls;
struct device *dev;

//定义等待队列头
wait_queue_head_t wq_head;
unsigned int condition = 0; //判断数据是否准备好的标志


int mycdev_open(struct inode *inode, struct file *file)
{
    printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
    return 0;
}


ssize_t mycdev_read(struct file *file, char  *ubuf, size_t size, loff_t *lof)
{
    printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
     unsigned long ret;
    
    if(file->f_flags & O_NONBLOCK) //非阻塞IO
    {

    } else 
    {
        ret = wait_event_interruptible(wq_head,condition);
        if(ret)
        {
            printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
            unsigned long ret;
        }
    }

    return 0;
}


ssize_t mycdev_write(struct file *file, const char  *ubuf, size_t size, loff_t *lof)
{






    return 0;
}






int mycdev_close(struct inode *inode, struct file *file)
{
    printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
    return 0;
}

//定义操作方法结构体变量并赋值
struct file_operations fops={

    .open=mycdev_open,
    .read=mycdev_read,
    .write=mycdev_write,
    .release=mycdev_close,
};


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