NAME=asm-led
# 指定交叉编译工具链的前缀
CROSS_COMPILE = arm-linux-gnueabihf-

# CC : gcc 编译器
CC = $(CROSS_COMPILE)gcc
# LD : 连接器  将.o文件链接生成.elf文件
LD = $(CROSS_COMPILE)ld
# OBJCOPY ： 格式化工具  将.elf文件转换为.bin文件
# .bin : 纯粹的二进制文件
OBJCOPY = $(CROSS_COMPILE)objcopy
# OBJDUMP : 反汇编的工具  将.elf文件反汇编生成.dis的反汇编文件
OBJDUMP = $(CROSS_COMPILE)objdump

all:
	@# -O0 : 代码的优化等级， 不优化
	@# -g : 添加gdb的调试信息
	@# -c : 只编译不链接
	@# -o : 重命名
	$(CC) -O0 -g -c $(NAME).S -o $(NAME).o
	@# -Ttext=0xC0008000  : 指定代码段的入口地址为0xc0008000
	$(LD) -Ttext=0xC0008000 $(NAME).o -o $(NAME).elf 
	@# -O binary : 输出二进制文件
	$(OBJCOPY) -O binary $(NAME).elf  $(NAME).bin
	@# 反汇编
	$(OBJDUMP) -D $(NAME).elf > $(NAME).dis
clean:
	rm -rf *.elf *.bin *.o *.dis

install:
	sudo cp $(NAME).bin  /mnt/hgfs/liunx_share/ 
	@# 需要修改为自己的共享文件夹的路径


