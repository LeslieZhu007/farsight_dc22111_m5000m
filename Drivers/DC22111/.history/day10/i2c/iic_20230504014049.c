#include <linux/init.h>
#include <linux/module.h>
#include <linux/i2c.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/io.h>
#include <linux/device.h>
#include "iic.h"
int major;
struct class *cls;
struct device *dev;
struct i2c_client *client1;
//封装读取温湿度数据的函数
int i2c_read_hum_tem(unsigned char reg)
{
    int ret;
    char r_buf[] = {reg};
    short value;
    struct i2c_msg r_msg[] = 
    {
        [0]= {
            .addr = client1->addr,
            .flags = 0,
            .len = 1,
            .buf = r_buf,
        },
        [1] = {
            .addr = client1->addr,
            .flags = 1,
            .len = 2,
            .buf = (char *)&value,

        },
    };
    //消息的传输
    ret = i2c_transfer(client1->adapter,r_msg, ARRAY_SIZE(r_msg);
    if(ret != ARRAY_SIZE(r_msg))
    {
        printk("消息传送失败\n");
        return ret;
    }
    return value;
}

int si7006_open(struct inode *inode, struct file *file)
{
    return 0;
}
long si7006_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
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

        }
        break;
        default:
        break;
    }

}

int si7006_close(struct inode *inode, struct file *file)
{
    return 0;
}
struct file_operations fops={
    .open=si7006_open,
    .unlocked_ioctl=si7006_ioctl,
    .release=si7006_close,
};


//给对象分配空间并且初始化
int iic_probe (struct i2c_client *client, const struct i2c_device_id *id)
{
    client1 = client;
    //字符设备驱动注册
    major = register_chrdev(major,"si7006",&fops);
    if(major<0)
    {
        printk("字符设备驱动注册失败\n");
        return major;
    }
    printk("字符设备驱动注册成功\n");

    //向上提交目录
    cls = class_create(THIS_MODULE,"si7006");
    if(IS_ERR(cls))
    {
        printk("向上提交目录失败\n");
        return PTR_ERR(cls);
    }
     printk("向上提交目录成功\n");
    //自动创建设备节点
    dev = device_create(cls,NULL, MKDEV(major,0),\
	      NULL, "si7006");
    if(IS_ERR(dev))
    {
        printk("向上提交设备节点失败\n");
        return PTR_ERR(dev);
    }
    printk("向上提交设备节点成功\n");
    return 0;
}


int iic_remove(struct i2c_client *client)
{
    //设备节点的销毁
    device_destroy(cls,MKDEV(major,0));
    class_destroy(cls);

    //驱动的注销
    unregister_chrdev(major, "si7006");
    return 0;
}

const struct of_device_id oftable[] = 
{
    {.compatible = "hqyj,si7006"},
    {}
};

struct i2c_driver i2c_drv = 
{
    .probe = iic_probe,
    .remove = iic_remove,

    .driver = {
        .name = "si7006",
        .of_match_table = oftable,
    }
};

module_i2c_driver(i2c_drv);
MODULE_LICENSE("GPL");