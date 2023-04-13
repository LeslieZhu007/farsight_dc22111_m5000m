#include <stdio.h>


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


int main(int argc,const char* argv[])
{
		
	printf("%d\n",INPUT);
	printf("%d\n",OUTPUT);
	printf("%d\n",ALF);
	printf("%d\n",ANALOG);

	gpio_init_t *init;
	


	return 0;
}
