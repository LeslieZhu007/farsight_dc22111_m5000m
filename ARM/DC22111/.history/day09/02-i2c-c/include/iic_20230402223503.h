#ifndef __IIC_H__
#define __IIC_H__
#include "stm32mp1xx_gpio.h"
#include "stm32mp1xx_rcc.h"
#include "gpio.h"
/* 通过程序模拟实现I2C总线的时序和协议
 * GPIOF ---> AHB4
 * I2C1_SCL ---> PF14
 * I2C1_SDA ---> PF15
 *
 * */

#define SET_SDA_OUT     do{GPIOF->MODER &= (~(0x3 << 30)); \
							GPIOF->MODER |= (0x1 << 30);}while(0)
#define SET_SDA_IN      do{GPIOF->MODER &= (~(0x3 << 30));}while(0)

#define I2C_SCL_H       do{GPIOF->BSRR |= (0x1 << 14);}while(0)
#define I2C_SCL_L       do{GPIOF->BRR |= (0x1 << 14);}while(0)

#define I2C_SDA_H       do{GPIOF->BSRR |= (0x1 << 15);}while(0)
#define I2C_SDA_L       do{GPIOF->BRR |= (0x1 << 15);}while(0)

#define I2C_SDA_READ    (GPIOF->IDR & (0x1 << 15))

void delay_us(void);
void i2c_init(void);
void i2c_start(void);
void i2c_stop(void);
void i2c_write_byte(unsigned char  dat);
unsigned char i2c_read_byte(unsigned char ack);
unsigned char i2c_wait_ack(void);       
void i2c_ack(void);
void i2c_nack(void);

#endif 
