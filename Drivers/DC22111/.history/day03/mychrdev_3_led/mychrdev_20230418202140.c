#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/io.h>
#include "stm32mp1xx_gpio.h"
#include "stm32mp1xx_rcc.h"

unsigned int major;
char kbuf[128] = {0};
unsigned int *vir_moder;
unsigned int *vir_odr;
unsigned int *vir_rcc;
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
        //(*vir_odr) &= (0x1<<10);
        (*vir_odr) |= (1<<10);
        printk("%s\n","Lights on by kernel");
    } else if ('0' == kbuf[0])
    {
        //(*vir_odr) &= (~(0x1<<10));
        (*vir_odr) &= (~(1<<10));
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

     //寄存器地址映射
     vir_moder = ioremap(PHY_LED1_MODER,4);
     if (vir_moder == NULL)
     {
         printk("ioremap failed:%d\n",__LINE__);
         return -ENOMEM;
     }

     vir_odr = ioremap(PHY_LED1_ODR,4);
     if (vir_odr == NULL)
     {
         printk("ioremap failed:%d\n",__LINE__);
         return -ENOMEM;
     }

    vir_rcc = ioremap(PHY_LED1_RCC,4);
    if (vir_rcc == NULL)
    {
        printk("ioremap failed:%d\n",__LINE__);
        return -ENOMEM;
    }

    printk("physical address mapping succeeded\n");

    //寄存器初始化
    // (*vir_rcc) |= (0x1<<4);
    // (*vir_moder) &= (~(0x3<<20));
    // (*vir_moder) |= (~(0x1<<20));

    (*vir_rcc) |= (1<<4);
    (*vir_moder) &= (~(3<<20));
    (*vir_moder) |= (1<<20);

    //odr输出低电平
    //(*vir_odr) &= (~(0x1<<10));
    (*vir_odr) &= (~(1<<10));
    printk("register init succeeded\n");
    return 0;
}

static void __exit mychrdev_exit(void)
{
    //取消地址映射
    iounmap(vir_moder);
    iounmap(vir_odr);
    iounmap(vir_rcc);
    //注销字符设备驱动
    unregister_chrdev(major,"mychrdev");
    
}


module_init(mychrdev_init);
module_exit(mychrdev_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Satoshi Nakamoto");