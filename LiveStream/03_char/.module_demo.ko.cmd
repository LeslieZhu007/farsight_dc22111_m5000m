cmd_/home/linux/farsight/LiveStream/03_char/module_demo.ko := ld -r -m elf_x86_64  -z max-page-size=0x200000  --build-id  -T ./scripts/module-common.lds -o /home/linux/farsight/LiveStream/03_char/module_demo.ko /home/linux/farsight/LiveStream/03_char/module_demo.o /home/linux/farsight/LiveStream/03_char/module_demo.mod.o;  true