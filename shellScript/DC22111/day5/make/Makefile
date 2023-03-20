OBJs+=main.o
OBJs+=fun.o
OBJs+=fun1.o
EXE?=fun  # executable file
CFLAGS=-c -w -g
CC=gcc

all:${EXE}

$(EXE):$(OBJs)
	 $(CC) $^ -o $@

%.o:%.c
	 $(CC) $(CFLAGS) $< -o $@

clean:
	rm *.o $(EXE)
