#ifndef __UART4_H__
#define __UART4_H__

#include "stm32mp1xx_gpio.h"
#include "stm32mp1xx_rcc.h"
#include "stm32mp1xx_uart.h"



void hal_uart4_init(void);
// 串口发送一个字节的函数
void hal_put_char(const char ch); 
// 串口发送字符串的函数
void hal_put_string(const char *str);
// 串口接收一个字节的函数
char hal_get_char(void);
// 串口接收一个字符串的函数 
char *hal_get_string(void);


#endif 
