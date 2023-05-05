#include <linux/init.h>
#include <linux/module.h>
#include <linux/i2c.h>


/* Standard driver model interfaces */
int iic_probe (struct i2c_client *client, const struct i2c_device_id *id)
{
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