#include<linux/module.h>
#include<linux/init.h>
#include<linux/spi/spi.h>

int major;
struct class *cls;
struct device *dev;




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