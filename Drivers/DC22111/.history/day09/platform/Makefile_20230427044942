modname ?= pdrv
arch ?= arm

#判断是否要编译成arm架构的
ifeq ($(arch),arm)
#定义一个变量存放内核源码路径
	KERNELDIR := /home/linux/linux-5.10.61
else
	KERNELDIR := /lib/modules/$(shell uname -r)/build
endif


KBUILD_EXTRA_SYMBOLS += /home/linux/farsight/Drivers/DC22111/day02/1/Module.symvers


#在当前终端开启一个新终端进程，执行shell命令，把结果赋值给当前PWD变量
PWD := $(shell pwd)

all:
#make modules代表我们要把被标记为M的文件进行模块化编译
#M=$(PWD) 代表将当前路径下的文件进行模块化编译，或者指定模块化编译的路径
	make -C $(KERNELDIR) M=$(PWD) modules

#清除生成的各种文件
clean:
	make -C $(KERNELDIR) M=$(PWD) clean
#指定当前编译生成的模块名是mycdev    mycdev.c--> mycdev.o -->mycdev.ko
obj-m:=$(modname).o