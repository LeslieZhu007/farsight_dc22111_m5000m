
.text 
.global _start
_start: 
	/**********LED1点灯****LED1---->PE10**********/
	@1.LED1 init RCC_AHB4_ENSETR  MODER OTYPER SPEEDR PUPDR 
	@RCC_AHB4_ENSETR    enable GPIOE and GPIOF
	ldr r0,=0x50000A28
	ldr r1,[r0]
	orr r1,#(0x3<<4)
	str r1,[r0]

	@MODER
	@LED1
	ldr r0,=0x50006000
	ldr r1,[r0]
	bic r1,#(0x3<<20)
	orr r1,#(0x1<<20)
	str r1,[r0]

	@LED2 
	ldr r0,=0x50007000
	ldr r1,[r0]
	bic r1,#(0x3<<20)
	orr r1,#(0x1<<20)
	str r1,[r0]

	@LED3
	ldr r0,=0x50006000
	ldr r1,[r0]
	bic r1,#(0x3<<16)
	orr r1,#(0x1<<16)
	str r1,[r0]



	@OTYPER
	@LED1
	ldr r0,=0x50006004
	ldr r1,[r0]
	bic r1,#(0x1<<10)
	str r1,[r0]

	@LED2 
	ldr r0,=0x50007004
	ldr r1,[r0]
	bic r1,#(0x1<<10)
	str r1,[r0]

	@LED3 
	ldr r0,=0x50006004
	ldr r1,[r0]
	bic r1,#(0x1<<8)
	str r1,[r0]

	@OSPEEDR
	@LED1
	ldr r0,=0x50006008
	ldr r1,[r0]
	bic r1,#(0x3<<20)
	str r1,[r0]

	@LED2 
	ldr r0,=0x50007008
	ldr r1,[r0]
	bic r1,#(0x3<<20)
	str r1,[r0]

	@LED3 
	ldr r0,=0x50006008
	ldr r1,[r0]
	bic r1,#(0x3<<16)
	str r1,[r0]




	@PUPDR

	@LED1 
	ldr r0,=0x5000600C
	ldr r1,[r0]
	bic r1,#(0x3<<20)
	str r1,[r0]

	@LED2 
	ldr r0,=0x5000700C
	ldr r1,[r0]
	bic r1,#(0x3<<20)
	str r1,[r0]

	@LED3 
	ldr r0,=0x5000600C
	ldr r1,[r0]
	bic r1,#(0x3<<18)
	str r1,[r0]





	@2.LED1 on and off  ODR
BLINKING:
	bl LED1_ON
	bl delay_1s
	bl LED1_OFF
	bl delay_1s
	bl LED2_ON
	bl delay_1s
	bl LED2_OFF
	bl delay_1s
	bl LED3_ON
	bl delay_1s
	bl LED3_OFF
	bl delay_1s
	bl BLINKING

LED1_ON:
	ldr r0,=0x50006014
	ldr r1,[r0]
	orr r1,#(0x1<<10)
	str r1,[r0]
	mov pc,lr


LED1_OFF:
	ldr r0,=0x50006014
	ldr r1,[r0]
	bic r1,#(0x1<<10)
	str r1,[r0]
	mov pc,lr

LED2_ON:
	ldr r0,=0x50007014
	ldr r1,[r0]
	orr r1,#(0x1<<10)
	str r1,[r0]
	mov pc,lr



LED2_OFF:
	ldr r0,=0x50007014
	ldr r1,[r0]
	bic r1,#(0x1<<10)
	str r1,[r0]
	mov pc,lr



LED3_ON:
	ldr r0,=0x50006014
	ldr r1,[r0]
	orr r1,#(0x1<<8)
	str r1,[r0]
	mov pc,lr


LED3_OFF:
	ldr r0,=0x50006014
	ldr r1,[r0]
	bic r1,#(0x1<<8)
	str r1,[r0]
	mov pc,lr

@ 大概1s的延时函数
delay_1s:
	mov r3, #0x2000000
	mm:
	cmp r3, #0
	subne r3, r3, #1
	bne mm
	mov pc, lr
/*
@ 大概1s的延时函数
delay_1s:
	mov r3, #0x10000000
	mm:
	cmp r3, #0
	subne r3, r3, #1
	bne mm
	mov pc, lr
*/
.end
