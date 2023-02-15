all:start.o
	arm-linux-gnueabihf-ld -Ttext 0x50000000 -o start.elf $^
%.o:%s
	arm-linux-gnueabihf-gcc -g -o $@ $^ -c
clean:
	rm *.o *.elf