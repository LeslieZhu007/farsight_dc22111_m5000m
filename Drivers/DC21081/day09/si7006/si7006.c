#include <linux/init.h>
#include <linux/module.h>
#include <linux/i2c.h>
#include <linux/mod_devicetable.h>

const struct of_device_id of_table[] =
{
	{.compatible = "hqyj,si7006",},
	{/*END*/},
};


int si7006_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
	printk("%s====>%d\n",__func__,__LINE__);
	return 0;
}


int si7006_remove(struct i2c_client *client)
{
	printk("%s====>%d\n",__func__,__LINE__);
	return 0;
}


MODULE_DEVICE_TABLE(of, of_table);


struct i2c_driver si7006_driver = {
	.driver = {
		.name = "2022_11_14",
		.of_match_table = of_table,
	},
	.probe = si7006_probe,
	.remove	= si7006_remove,
};

module_i2c_driver(si7006_driver);
MODULE_LICENSE("GPL");


