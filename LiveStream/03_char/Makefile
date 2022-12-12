KERNELDIR=/lib/modules/$(shell uname -r)/build/
#KERNELDIR=/home/linux/linux-5.10.10
PWD:=$(shell pwd)

all:
	make -C $(KERNELDIR) M=$(PWD) modules
clean:
	make -C $(KERNELDIR) M=$(PWD) clean
obj-m:=module_demo.o
