cmd_/home/linux/farsight/Drivers/day03/02_ioctl_node/modules.order := {   echo /home/linux/farsight/Drivers/day03/02_ioctl_node/myled.ko; :; } | awk '!x[$$0]++' - > /home/linux/farsight/Drivers/day03/02_ioctl_node/modules.order
