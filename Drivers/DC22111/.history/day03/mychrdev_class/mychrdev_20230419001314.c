#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/io.h>
#include <linux/device.h>
#include "stm32mp1xx_gpio.h"
#include "stm32mp1xx_rcc.h"

unsigned int major;
char kbuf[128] = {0};
gpio_t* vir_led1;
gpio_t* vir_led2;
gpio_t* vir_led3;
rcc_t*  vir_rcc;
struct class *cls;
struct device *dev;
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
    switch(kbuf[0])
    {
        case '1':
            if ('1' == kbuf[1]) 
            {
                //(*vir_odr) &= (0x1<<10);
                (vir_led1->ODR) |= (1<<10);
                printk("%s\n","LED1 on by kernel");
            } else if ('0' == kbuf[1])
            {
                //(*vir_odr) &= (~(0x1<<10));
                (vir_led1->ODR) &= (~(1<<10));
                printk("%s\n","LED1 off by kernel");
            }
            break;
        case '2':
            if ('1' == kbuf[1]) 
            {
                //(*vir_odr) &= (0x1<<10);
                (vir_led2->ODR) |= (1<<10);
                printk("%s\n","LED2 on by kernel");
            } else if ('0' == kbuf[1])
            {
                //(*vir_odr) &= (~(0x1<<10));
                (vir_led2->ODR) &= (~(1<<10));
                printk("%s\n","LED2 off by kernel");
            }
            break;
        case '3':
            if ('1' == kbuf[1]) 
            {
                //(*vir_odr) &= (0x1<<10);
                (vir_led1->ODR) |= (1<<8);
                printk("%s\n","LED3 on by kernel");
            } else if ('0' == kbuf[1])
            {
                //(*vir_odr) &= (~(0x1<<10));
                (vir_led1->ODR) &= (~(1<<8));
                printk("%s\n","LED3 off by kernel");
            }
            break;
        default:
            break;
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

void led_init()
{
    //寄存器初始化
    // (*vir_rcc) |= (0x1<<4);
    // (*vir_moder) &= (~(0x3<<20));
    // (*vir_moder) |= (~(0x1<<20));
    //GPIOE使能
    (vir_rcc->MP_AHB4ENSETR) |= (1<<4);
    //GPIOF使能
    (vir_rcc->MP_AHB4ENSETR) |= (1<<5);

    //LED1 moder 
    (vir_led1->MODER) &= (~(3<<20));
    (vir_led1->MODER) |= (1<<20);

    //LED2 moder
    (vir_led2->MODER) &= (~(3<<20));
    (vir_led2->MODER) |= (1<<20);

    //LED3 moder
    (vir_led3->MODER) &= (~(3<<16));
    (vir_led3->MODER) |= (1<<16);

    //LED1 odr输出低电平
    //(*vir_odr) &= (~(0x1<<10));
    (vir_led1->ODR) &= (~(1<<10));

    //LED2 odr输出低电平
    (vir_led2->ODR) &= (~(1<<10));

    //LED3 odr输出低电平
    (vir_led3->ODR) &= (~(1<<8));
    printk("register init succeeded\n");
}

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

     //向上提交目录
    cls = class_create(THIS_MODULE,"mychrdev");
    if (IS_ERR(cls))
    {
        printk(" 向上提交目录失败\n");
        return PTR_ERR(cls);
    }
    printk(" 向上提交目录成功\n");

    //向上提交设备信息
    dev = device_create(cls,NULL,MKDEV(major,0),NULL,"mychrdev");
    if (IS_ERR(dev))
    {
        printk(" 向上提交设备信息失败\n");
        return PTR_ERR(dev);
    }
    printk(" 向上提交设备信息成功\n");

    return 0;
     //寄存器地址映射
     //LED1 
     vir_led1 = ioremap(GPIOE,sizeof(gpio_t));
     if (vir_led1 == NULL)
     {
         printk("ioremap failed:%d\n",__LINE__);
         return -ENOMEM;
     }
     vir_led2 = ioremap(GPIOF,sizeof(gpio_t));
     if (vir_led2 == NULL)
     {
         printk("ioremap failed:%d\n",__LINE__);
         return -ENOMEM;
     }
    vir_led3 = vir_led1;
   

    vir_rcc = ioremap(RCC,sizeof(rcc_t));
    if (vir_rcc == NULL)
    {
        printk("ioremap failed:%d\n",__LINE__);
        return -ENOMEM;
    }

    printk("physical address mapping succeeded\n");


    led_init();
    
    return 0;
}

static void __exit mychrdev_exit(void)
{
    //取消地址映射
    iounmap(vir_led1);
    iounmap(vir_led2);
    iounmap(vir_led3);
    iounmap(vir_rcc);
    //销毁设备信息
    device_destroy(cls,MKDEV(major,0));
    //销毁目录
    class_destroy(cls);
    //注销字符设备驱动
    unregister_chrdev(major,"mychrdev");
    
}


module_init(mychrdev_init);
module_exit(mychrdev_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Satoshi Nakamoto");