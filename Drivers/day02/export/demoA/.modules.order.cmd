cmd_/home/linux/farsight/Drivers/day02/export/demoA/modules.order := {   echo /home/linux/farsight/Drivers/day02/export/demoA/demoA.ko; :; } | awk '!x[$$0]++' - > /home/linux/farsight/Drivers/day02/export/demoA/modules.order