cmd_/home/linux/farsight/Drivers/day02/04myled-ok/Module.symvers := sed 's/ko$$/o/' /home/linux/farsight/Drivers/day02/04myled-ok/modules.order | scripts/mod/modpost -m  -E  -o /home/linux/farsight/Drivers/day02/04myled-ok/Module.symvers -e -i Module.symvers   -T -
