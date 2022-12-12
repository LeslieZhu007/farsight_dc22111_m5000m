CC?=gcc
OBJ_BIN=main.o add.o sub.o
CFLAGS=-c -o
TARGET?=cal
export VPATH=main add sub
$(TARGET):$(OBJ_BIN)
	$(CC) ./main/main.o ./add/add.o ./sub/sub.o -o $@ 
%.o:%.c
	make -C $*  
	echo $*
clean:
	rm *.o $(TARGET)
