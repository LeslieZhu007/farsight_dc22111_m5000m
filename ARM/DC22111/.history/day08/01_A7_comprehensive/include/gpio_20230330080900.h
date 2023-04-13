#ifndef __GPIO_H__
#define __GPIO_H__

//struct encapsulation
typedef struct
{
	volatile unsigned int MODER;
	volatile unsigned int OTYPER;
	volatile unsigned int OSPEEDR;
	volatile unsigned int PUPDR;
	volatile unsigned int IDR;
	volatile unsigned int ODR;
} gpio_t;
#define GPIOE ((gpio_t *)0x50006000)
#define GPIOF ((gpio_t *)0x50007000)
#define RCC_AHB4_ENSETR ((volatile unsigned int *)0x50000A28)


//pin encapsulation
#define GPIO_PIN_0 0
#define GPIO_PIN_1 1
#define GPIO_PIN_2 2
#define GPIO_PIN_3 3
#define GPIO_PIN_4 4
#define GPIO_PIN_5 5
#define GPIO_PIN_6 6
#define GPIO_PIN_7 7
#define GPIO_PIN_8 8
#define GPIO_PIN_9 9
#define GPIO_PIN_10 10
#define GPIO_PIN_11 11
#define GPIO_PIN_12 12
#define GPIO_PIN_13 13
#define GPIO_PIN_14 14
#define GPIO_PIN_15 15
#define GPIO_PIN_16 16 
#define GPIO_PIN_17 17
#define GPIO_PIN_18 18
#define GPIO_PIN_19 19
#define GPIO_PIN_20 20 
#define GPIO_PIN_21 21
#define GPIO_PIN_22 22
#define GPIO_PIN_23 23
#define GPIO_PIN_24 24 
#define GPIO_PIN_25 25
#define GPIO_PIN_26 26
#define GPIO_PIN_27 27
#define GPIO_PIN_28 28
#define GPIO_PIN_29 29
#define GPIO_PIN_30 30
#define GPIO_PIN_31 31

//MODER encapsulation
typedef enum
{
	INPUT,
	OUTPUT,
	ALF,
	ANALOG
} gpio_moder_t;


//OTYPER encapsulation
typedef enum
{
	PP,
	OD
} gpio_otyper_t;

//OSPEEDR
typedef enum
{
	LOW,
	MEDIUM,
	HIGH,
	VERY_HIGH

} gpio_ospeedr_t;

//PUPDR
typedef enum
{
	NO_PUPD,
	PU,
	PD

} gpio_pupdr_t;

//ODR
typedef enum 
{
	GPIO_RESET_T,
	GPIO_SET_T

} gpio_odr_t;


typedef struct 
{
	gpio_moder_t moder; //mode 
	gpio_otyper_t otyper; //type 
	gpio_ospeedr_t ospeedr; //speed
	gpio_pupdr_t pupdr;  //pupd
} gpio_init_t;




//gpio init
void hal_gpio_init(gpio_t * gpiox,unsigned int pin,gpio_init_t* init);


//gpio write 
void hal_gpio_write(gpio_t * gpiox,unsigned int pin,gpio_odr_t status);



typedef struct
{
	char* cmd_arr; //命令字符串
	gpio_t* gpiox; //gpio组号
	unsigned int pin; //对应引脚编号
	gpio_odr_t status; //对应引脚状态
	void (*gpio_write)(gpio_t * gpiox,unsigned int pin,gpio_odr_t status);

} cmd_t;








#endif




	
