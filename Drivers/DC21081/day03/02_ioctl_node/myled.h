#ifndef __MYLED_H__
#define __MYLED_H__


#define GPIOE_PHY_BASE 0x50006000 // MODER[10]  21:20  01  0x00  ODR[10] 10 1   0x14   
#define GPIOF_PHY_BASE 0x50007000 // MODER[10]  21:20  01  0x00  ODR[10] 10 1   0x14  
#define RCC_ENB 0x50000A28 // RCC AHB4 ENB  0xA28  GPIOEEN 4 1


typedef struct
{
	volatile unsigned int MODER; //0x00
	volatile unsigned int OTYPER; //0x04
	volatile unsigned int OSPEEDR; //0x08
	volatile unsigned int PUPDR; //0x0C
	volatile unsigned int IDR; //0x10
	volatile unsigned int ODR; //0x14
	volatile unsigned int BSRR; //0x18
	volatile unsigned int LCKR; //0x1C
	volatile unsigned int AFRL; //0x20
	volatile unsigned int AFRH; //0x24
	volatile unsigned int BRR; //0x28
	volatile unsigned int res; //0x0C
	volatile unsigned int SECCFGR; //0x30

} gpio_t;

typedef struct image
{
	int height;
	int width;
	char image_type[4]; //jpg png bmp
} image_t;

#define IMAGE_STRUCT _IOWR('a',2,image_t)

#define CHR_BUF _IOW('a',1,char[128])

#define LED2_OP _IOW('a',0,int)

#define GET_CMD_SIZE(cmd) ((cmd>>16)&0x3FFF)




#endif
