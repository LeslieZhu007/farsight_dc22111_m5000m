cmd_/home/linux/farsight/Drivers/day02/04myled-ok/modules.order := {   echo /home/linux/farsight/Drivers/day02/04myled-ok/myled.ko; :; } | awk '!x[$$0]++' - > /home/linux/farsight/Drivers/day02/04myled-ok/modules.order
