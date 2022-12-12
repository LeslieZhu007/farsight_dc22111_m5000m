#SRC=${wildcard *.c}
#OBJS=$(patsubst %.c,%.o,${SRC})
OBJS=test.o add.o sub.o mul.o div.o
TARGET?=cal
CC?=gcc
CFLAGS=-c -o

export VPATH=test add sub mul div

#$@: 表示目标
#$<: 表示第一个依赖
#$^: 表示所有的依赖
#$*: objects after stripped off the suffix

${TARGET}:$(OBJS)
	#$(CC) ./test/test.o ./add/add.o ./sub/sub.o ./mul/mul.o ./div/div.o -o  $@
	$(CC) ./test/test.o ./add/add.o ./sub/sub.o ./mul/mul.o ./div/div.o -o  $@
%.o:%.c
	echo $*
	make -C $*

.PHONY:clean
clean:
	rm ./add/add.o ./sub/sub.o ./mul/mul.o ./div/div.o ./test/test.o $(TARGET)
