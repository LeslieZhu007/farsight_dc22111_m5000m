cmd_/home/linux/farsight/Drivers/DC22111/day08/gpio_subsys_chrdev/Module.symvers := sed 's/ko$$/o/' /home/linux/farsight/Drivers/DC22111/day08/gpio_subsys_chrdev/modules.order | scripts/mod/modpost   -E  -o /home/linux/farsight/Drivers/DC22111/day08/gpio_subsys_chrdev/Module.symvers -e -i Module.symvers -i /home/linux/farsight/Drivers/DC22111/day02/1/Module.symvers   -T -