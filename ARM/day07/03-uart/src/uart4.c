#include "uart4.h"
extern char buffer[50];
void hal_uart4_init(void)
{
	// 1. 使能GPIOB的时钟  RCC_MP_AHB4ENSETR[1]
	
	// 2. 设置PB2引脚为复用模式 GPIOB_MODER[5:4]
	
	// 3. 设置PB2引脚的复用功能为UART4_RX  GPIOB_AFRL[11:8]
	
	// 4. 使能GPIOG的时钟  RCC_MP_AHB4ENSETR[6] 
	
	// 5. 设置PG11引脚为复用模式 GPIOG_MODER[23:22]
	
	// 6. 设置PG11引脚的复用功能为UART4_TX  GPIOB_AFRH[15:12]
	
	
	// 7. 使能UART4的时钟   RCC_MP_APB1ENSETR[16]
	
	// 8. 判断UART4控制器是否被使能(UE = 0/1)  USART4_CR1[0]

	// 9. 设置串口的协议，1个起始位，8位数据位  USART4_CR1[28][12]
	
	// 10. 设置串口的校验位，不使用校验位   USART4_CR1[10]
	
	// 11. 设置串口的采样率，16倍采样率   USART4_CR1[15]
	
	// 12. 设置串口的停止位个数， 1个停止位  USART4_CR2[13:12]
	
	// 13. 设置串口的波特率 115200bps  USART4_BRR[15:0]
	//   		uart_pclk = usart_ker_ck_pres= 64MHz
	
	// 14. 设置串口的时钟的分频值，不分频(1分频)   USART4_PRESC[3:0]

	// 15. 设置串口的发送器的使能   USART4_CR1[3]
	
	// 16. 设置串口的接收器的使能   USART4_CR1[2]
	
	// 17. 设置串口的使能           USART4_CR1[0]

}

// 串口发送一个字节的函数
// ch : 发送的字节
void hal_put_char(const char ch)
{
	// 1. 判断发送寄存器是否为空  TXE = 1
	// 读TXE位的值，如果读到1，则退出while循环发送数据
	// 如果读到0，则等待发送数据寄存器为空。
	while(!(USART4->ISR & (0x1 << 7)));
	// 2. 发送数据  USART4_TDR = ch;
	
	// 3. 判断发送数据是否完成  TC = 1
}
// 串口发送字符串的函数
void hal_put_string(const char *str)
{
	// 一个字符一个字符的发送，判断字符串的结尾“\0”
}
// 串口接收一个字节的函数
char hal_get_char(void)
{
	char ch;
	// 1. 判断接收数据寄存器是否有有效的数据  RXNE = 1
	// 2. 从接收数据寄存器中读数据  ch = USART4_RDR
	return ch;
}
// 串口接收一个字符串的函数 
char *hal_get_string(void)
{
	// 按下enter键表示接收结束，或者超过49个字符
	// enter键对应的ASCII是'\r'
	return buffer;
}

