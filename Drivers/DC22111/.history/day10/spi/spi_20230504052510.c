#include<linux/module.h>
#include<linux/init.h>
#include<linux/spi.h>
int m74hc595_probe(struct device *dev)
{



    return 0;
}

int m74hc595_remove(struct device *dev)
{

    return 0;
}




struct spi_driver driver =
{
    .probe = m74hc595_probe,
    .remove = m74hc595_remove,
    .driver = {
        .name = "m74hc595",
        .of_match_table = 
    }


};





module_spi_driver(driver);