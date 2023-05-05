#include<linux/module.h
#include<linux/init.h>
#include<linux/spi.h>

struct spi_driver driver;

spi_register_driver(&driver);