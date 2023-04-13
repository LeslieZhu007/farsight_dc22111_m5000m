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


}
/*
 * 函数名：si7006_read_data
 * 函数功能：读取SI7006的转换结果
 * 函数参数：
 *     slave_addr ： 从机地址
 *     reg_addr ： 寄存器地址
 * 函数返回值：无
*/
short si7006_read_data(unsigned char slave_addr, 
		unsigned char reg_addr)
{

}

