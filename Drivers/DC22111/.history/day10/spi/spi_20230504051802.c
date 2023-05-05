#include<linux/module.h>
#include<linux/init.h>
#include<linux/spi.h>
int (*probe)(struct device *dev)
{
    
}
struct spi_driver driver =
{
    .probe = spi_probe,



};





module_spi_driver(driver);