SRC=${wildcard *.c}
OBJS=$(patsubst %.c,%.o,${SRC})
TARGET?=test
CC?=gcc
CFLAGS=-c -o

#$@: 表示目标
#$<: 表示第一个依赖
#$^: 表示所有的依赖

${TARGET}:$(OBJS)
	$(CC) $^ -o  $@
%.o:%.c
	$(CC) $<  $(CFLAGS) $@

.PHONY:clean
clean:
	rm -rf ${OBJS} $(TARGET)
