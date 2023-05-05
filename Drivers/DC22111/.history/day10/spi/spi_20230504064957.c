#include<linux/module.h>
#include<linux/init.h>
#include<linux/spi/spi.h>
int m74hc595_probe(struct spi_device *spi)
{
    //让右边第一个数码管显示数字5
    char buf[] = {0x8,0x6d};
    spi_write(spi,buf,sizeof(buf));

    return 0;
}

int m74hc595_remove(struct spi_device *spi)
{

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