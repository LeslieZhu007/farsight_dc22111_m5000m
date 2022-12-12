#KERNELDIR:=/home/linux/linux-5.10.10/
KERNELDIR:=/lib/modules/$(shell uname -r)/build
PWD:=$(shell pwd)

all:
	make -C $(KERNELDIR) M=$(PWD) modules

clean:
	make -C $(KERNELDIR) M=$(PWD) clean 

obj-m:=demo.o
