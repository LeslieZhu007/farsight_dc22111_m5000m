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


/* Standard driver model interfaces */
int iic_probe (struct i2c_client *client, const struct i2c_device_id *id)
{
    client1 = client;
    //字符设备驱动注册
    //自动创建设备节点
    return 0;
}


int iic_remove(struct i2c_client *client)
{
    //设备节点的销毁

    //驱动的注销
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