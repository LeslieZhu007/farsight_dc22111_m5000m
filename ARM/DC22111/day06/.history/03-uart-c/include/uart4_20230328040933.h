#ifndef __UART4_H__
#define __UART4_H__
#include "stm32mp1xx_uart.h"
#include "stm32mp1xx_gpio.h"
#include "stm32mp1xx_rcc.h"

//init uart 
void hal_uart4_init();

//send a char
void put_char(const char str);

//send a string 
void put_string(const char* string);


//recv a char 
char get_char();


//recv a string 
char* get_string();







#endif 
