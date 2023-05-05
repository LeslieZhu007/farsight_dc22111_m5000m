MODNAME ?=demo
arch ?=x86
ifeq ($(arch),arm)
KERNELDIR:=/home/linux/linux-5.10.10/
else
KERNELDIR:=/lib/modules/$(shell uname -r)/build
endif
KBUILD_EXTRA_SYMBOLS:=/home/linux/farsight/Drivers/day02/export/demoA/Module.symvers
PWD:=$(shell pwd)
all:
	make -C $(KERNELDIR) M=$(PWD) modules

clean:
	make -C $(KERNELDIR) M=$(PWD) clean 

obj-m:=$(MODNAME).o
