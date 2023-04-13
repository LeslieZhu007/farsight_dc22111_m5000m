#include "iic.h"
#include "si7006.h"
extern void delay_ms(unsigned int ms);
/*
 * 函数名：si7006_init
 * 函数功能：SI7006芯片的初始化
 * 函数参数：无
 * 函数返回值：无
*/
void si7006_init(void)
{
	i2c_init();
	i2c_start();
	i2c_write_byte(SI7006_SLAVE<<1 | 0);
	i2c_wait_ack();
	i2c_write_byte(0xE6);
	i2c_wait_ack();
	i2c_write_byte(0x3A);
	i2c_wait_ack();
	i2c_stop();

}
/*
 * 函数名：si7006_read_data
 * 函数功能：读取SI7006的转换结果
 * 函数参数：
 *     slave_addr ： 从机地址
 *     reg_addr ： 寄存器地址
 * 函数返回值：无
*/

//读湿度
unsigned short si7006_read_hum_data(unsigned char slave_addr, unsigned char reg_addr)
{
	unsigned short dat;
	unsigned char dat_h,dat_l;
	i2c_start();
	i2c_write_byte(slave_addr<<1 | 0);
	i2c_wait_ack();
	i2c_write_byte(reg_addr);
	i2c_wait_ack();
	i2c_start();
	i2c_write_byte(slave_addr<<1|1);
	i2c_wait_ack();
	delay_ms(10);
	dat_h = i2c_read_byte(0);
	dat_l = i2c_read_byte(1);
	i2c_stop();
	dat = dat_h;
	dat<<=8;
	dat|=dat_l;
	return dat;
}

short si7006_read_temp_data(unsigned char slave_addr, unsigned char reg_addr)
{
    short dat;
	unsigned char dat_h,dat_l;
	i2c_start();
	i2c_write_byte(slave_addr<<1 | 0);
	i2c_wait_ack();
	i2c_write_byte(reg_addr);
	i2c_wait_ack();
	i2c_start();
	i2c_write_byte(slave_addr<<1|1);
	i2c_wait_ack();
	delay_ms(10);
	dat_h = i2c_read_byte(0);
	dat_l = i2c_read_byte(1);
	i2c_stop();
	dat = dat_h;
	dat<<=8;
	dat|=dat_l;
	return dat;
}
