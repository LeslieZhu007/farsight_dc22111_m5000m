#include "gpio.h"
#include "uart4.h"
char buffer[50] = {0};
extern void printf(const char *fmt, ...);
void delay_ms(int ms)
{
	int i,j;
	for(i = 0; i < ms;i++)
		for (j = 0; j < 1800; j++);
}
int main()
{	
	hal_uart4_init();
	hal_put_string("uart test...\n");
	while(1)
	{
#if 0
		/*测试收发字符的函数*/
		// 开发板接收一个字符之后，立马在发送给串口工具
		hal_put_char(hal_get_char());
#else
		/*测试收发字符串的函数 */
		hal_get_string();
		hal_put_string(buffer);
#endif
	}
	return 0;
}
