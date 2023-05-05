#include <linux/init.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/of_gpio.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <linux/slab.h>
#include <linux/fs.h>

struct device_node *dnode;
struct gpio_desc *desc; //led1
struct gpio_desc *desc0;//led2
struct gpio_desc *desc1;//led3

unsigned int minor = 0;
unsigned int major = 0;
struct cdev *cdev;
dev_t devno;
char kbuf[128] = {0};
struct class *cls;
struct device *dev;
int i = 0;

void led_init();


long gpiochrdev_ioctl (struct file *file, unsigned int cmd, unsigned long args)
{
    



    return 0;
}



int gpiochrdev_open(struct inode *inode, struct file *file)
{
    printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
    return 0;
}

ssize_t gpiochrdev_read (struct file *file, char __user *ubuf, size_t size, loff_t *loff)
{
    printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
     unsigned long ret;
    //向用户空间读取拷贝
    if(size>sizeof(kbuf))//用户空间期待读取的大小内核满足不了，那就给内核支持的最大大小
        size=sizeof(kbuf);
    ret=copy_to_user(ubuf,kbuf,size);
    if(ret)//拷贝失败
    {
        printk("copy_to_user filed\n");
        return ret;
    }
    return 0;
}
ssize_t gpiochrdev_write (struct file *file, const char __user *ubuf, size_t size, loff_t *loff)
{
     unsigned long ret;
    //从用户空间读取数据
    if(size>sizeof(kbuf))//用户空间期待读取的大小内核满足不了，那就给内核支持的最大大小
        size=sizeof(kbuf);
    ret=copy_from_user(kbuf,ubuf,size);
    if(ret)//拷贝失败
    {
        printk("copy_to_user filed\n");
        return ret;
    }
    return 0;
}
int gpiochrdev_close(struct inode *inode, struct file *file)
{
    printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
    return 0;
}




const struct file_operations fops = 
{
    .open = gpiochrdev_open,
    .read = gpiochrdev_read,
    .write =gpiochrdev_write,
    .release = gpiochrdev_close,
    .unlocked_ioctl = gpiochrdev_ioctl,
};

static int __init gpiochrdev_init(void)
{
    //初始化LED灯
    led_init();
    
    int ret;
    //1.分配字符设备驱动对象空间
    cdev = cdev_alloc();
    if(NULL == cdev)
    {
        printk("申请字符设备驱动对象空间失败\n");
        ret = -ENOMEM;
        goto ERR1;
    }
    printk("申请字符设备驱动对象空间成功\n");

    //2.初始化字符设备驱动对象
    cdev_init(cdev,&fops);
    printk("初始化字符设备驱动对象成功\n");

    //3.动态申请设备号
    ret = alloc_chrdev_region(&devno,0, 3,"gpiochrdev");
    if(ret)
    {
        printk("动态申请设备号失败\n");
        ret = -EBUSY;
        goto ERR2;
    }
    printk("动态申请设备号成功\n");
    major = MAJOR(devno);
    minor = MINOR(devno);

    //4.注册
    ret = cdev_add(cdev, MKDEV(major,minor), 3);
    if(ret)
    {
        printk("注册字符设备驱动对象失败\n");
        goto ERR3;
    }
    printk("注册字符设备驱动对象成功\n");

    //5.向上提交目录
    cls = class_create(THIS_MODULE, "gpiochrdev");
    if(IS_ERR(cls))
    {
        printk("向上提交目录失败\n");
        ret = PTR_ERR(cls);
        goto ERR4;
    }
    printk("向上提交目录成功\n");

    //6.创建设备节点
    for(i = 0; i < 3; i++)
    {
        dev =  device_create(cls, NULL,\
			     MKDEV(major,i), NULL, "gpiochrdev%d", i);
        if(IS_ERR(dev))
        {
            printk("创建设备节点gpiochrdev%d失败\n",i);
            ret = PTR_ERR(dev);
            goto ERR5;
        }
        printk("创建设备节点gpiochrdev%d成功\n",i);
    }
    

    /*
    gpiod_set_value(desc, 1);
    gpiod_set_value(desc0, 1);
    gpiod_set_value(desc1, 1);
    */
    






    return 0;
ERR5:
    for(--i; i>=0;i--) 
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
static void __exit gpiochrdev_exit(void)
{


    //灭灯
    gpiod_set_value(desc, 0);
    gpiod_set_value(desc0, 0);
    gpiod_set_value(desc1, 0);
    //释放gpio
    gpiod_put(desc);
    gpiod_put(desc0);
    gpiod_put(desc1);

    for(--i; i>=0;i--) 
    {
        device_destroy(cls,MKDEV(major,i));
    }
    class_destroy(cls);
    cdev_del(cdev);
    unregister_chrdev_region(MKDEV(major,minor),3);
    kfree(cdev);

}


void led_init()
{
    //解析myled设备树节点
    dnode = of_find_node_by_name(NULL,"myleds");
    if(NULL == dnode)
    {
        printk("解析设备树节点失败\n");
        return -1;
    }
    printk("解析设备树节点成功\n");
    
    desc = gpiod_get_from_of_node(dnode,"myled1",0,GPIOD_OUT_LOW,NULL) ;
    if(IS_ERR(desc))
    {
        printk("解析LED0对象失败\n");
        return PTR_ERR(desc);
    }
    printk("解析LED0对象成功\n");


    desc0 = gpiod_get_from_of_node(dnode,"myled2",0,GPIOD_OUT_LOW,NULL) ;
    if(IS_ERR(desc0))
    {
        printk("解析LED1对象失败\n");
        return PTR_ERR(desc0);
    }
    printk("解析LED1对象成功\n");


    desc1 = gpiod_get_from_of_node(dnode,"myled3",0,GPIOD_OUT_LOW,NULL) ;
    if(IS_ERR(desc1))
    {
        printk("解析LED2对象失败\n");
        return PTR_ERR(desc1);
    }
    printk("解析LED2对象成功\n");

    if( gpiod_direction_output(desc,0))
    {
        printk("设置LED0输出失败\n");
        return -1;
    }
     printk("设置LED0输出成功\n");

     if( gpiod_direction_output(desc0,0))
    {
        printk("设置LED1输出失败\n");
        return -1;
    }
     printk("设置LED1输出成功\n");

     if( gpiod_direction_output(desc1,0))
    {
        printk("设置LED2输出失败\n");
        return -1;
    }
     printk("设置LED2输出成功\n");
}
module_init(gpiochrdev_init);
module_exit(gpiochrdev_exit);
MODULE_LICENSE("GPL");