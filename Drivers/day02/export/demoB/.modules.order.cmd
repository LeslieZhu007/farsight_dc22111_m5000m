cmd_/home/linux/farsight/Drivers/day02/export/demoB/modules.order := {   echo /home/linux/farsight/Drivers/day02/export/demoB/demoB.ko; :; } | awk '!x[$$0]++' - > /home/linux/farsight/Drivers/day02/export/demoB/modules.order
