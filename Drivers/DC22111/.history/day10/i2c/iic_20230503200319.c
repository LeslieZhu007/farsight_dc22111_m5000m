#include <linux/init.h>
#include <linux/module.h>
#include <linux/i2c.h>


/* Standard driver model interfaces */
int iic_probe (struct i2c_client *client, const struct i2c_device_id *id)
{

}


int iic_remove(struct i2c_client *client)
{
    
}

const struct of_device_id oftable[] = 
{
    {.name = ""},
    {}
};

struct i2c_driver i2c_drv = 
{
    .probe = iic_probe,
    .remove = iic_remove,

    .driver = {
        .of_match_table = oftable,
    }
};


MODULE_LICENSE("GPL");