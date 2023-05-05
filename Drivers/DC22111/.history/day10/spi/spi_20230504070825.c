#include<linux/module.h>
#include<linux/init.h>
#include<linux/spi/spi.h>

int major;
struct class *cls;
struct device *dev;
struct spi_device *spi1;

int m74hc595_open(struct inode *inode, struct file *file)
{
    return 0;
}
long m74hc595_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
    int tem,hum;
    int ret;
    switch (cmd) 
    {
        case GET_HUM:
        {
            hum = i2c_read_hum_tem(0xE5);
            //将数据拷贝给应用程序
            ret = copy_to_user((void *)arg,&hum,sizeof(int));
             if(ret)
            {
                printk("向用户层拷贝失败\n");
                return -EIO;
            }
        }
        break;
        case GET_TEM:
        {
            tem = i2c_read_hum_tem(0xE3);
            //将数据拷贝给应用程序
            ret = copy_to_user((void *)arg,&tem,sizeof(int));
             if(ret)
            {
                printk("向用户层拷贝失败\n");
                return -EIO;
            }

        }
        break;
        default:
        break;
    }

    return 0;
}

int m74hc595_close(struct inode *inode, struct file *file)
{
    return 0;
}
struct file_operations fops={
    .open=m74hc595_open,
    .unlocked_ioctl=m74hc595_ioctl,
    .release=m74hc595_close,
};


int m74hc595_probe(struct spi_device *spi)
{
    //让右边第一个数码管显示数字5
    char buf[] = {0x8,0x6d};
    spi_write(spi,buf,sizeof(buf));
    /*********字符设备驱动注册*begin**********/
    //字符设备驱动注册
    major = register_chrdev(major,"m74hc595",&fops);
    if(major<0)
    {
        printk("字符设备驱动注册失败\n");
        return major;
    }
    printk("字符设备驱动注册成功\n");

    //向上提交目录
    cls = class_create(THIS_MODULE,"m74hc595");
    if(IS_ERR(cls))
    {
        printk("向上提交目录失败\n");
        return PTR_ERR(cls);
    }
     printk("向上提交目录成功\n");
    //自动创建设备节点
    dev = device_create(cls,NULL, MKDEV(major,0),\
	      NULL, "m74hc595");
    if(IS_ERR(dev))
    {
        printk("向上提交设备节点失败\n");
        return PTR_ERR(dev);
    }
    printk("向上提交设备节点成功\n");



    /*********字符设备驱动注册*end**********/

    printk("%s:%d\n",__FILE__,__LINE__);
    return 0;
}

int m74hc595_remove(struct spi_device *spi)
{
    printk("%s:%d\n",__FILE__,__LINE__);
    return 0;
}


const struct of_device_id oftable[] = 
{
    {.compatible = "hqyj,m74hc595"},
    {}
};

struct spi_driver m74hc595_driver =
{
    .probe = m74hc595_probe,
    .remove = m74hc595_remove,
    .driver = {
        .name = "m74hc595",
        .of_match_table = oftable,
    }
};

module_spi_driver(m74hc595_driver);
MODULE_LICENSE("GPL");