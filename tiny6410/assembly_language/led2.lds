SECTIONS {
        . = 0x50000000;

        . = ALIGN(4);
        .text:
        {
            start.o(.text)
            *(.text)
        }

        . = ALIGN(4)
        .data :
        {
            *(.data)
        }

        . = ALIGN(4)
        bss_start = .
        .bss :
        {
            *(.bss)
        }
        bss_end = .
}