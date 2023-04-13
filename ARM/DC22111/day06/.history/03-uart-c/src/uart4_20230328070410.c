#include "uart4.h"
//init uart 
char buff[50]={0};
void hal_uart4_init()
{
	/******RCC init**************/
	RCC->MP_AHB4ENSETR |= (0x1<<1 | 0x1<<6);
	RCC->MP_APB1ENSETR |= (0x1<<16);
	/********GPIO init***********/
	//PB2----> UART4_RX
	GPIOB->MODER &= (~(0b11<<4));
	GPIOB->MODER |= (0b10<<4);
	GPIOB->AFRL &= (~(0b1111<<8));
	GPIOB->AFRL |= (0b1000<<8);
	//PG11---->UART4_TX
	GPIOG->MODER &= (~(0b11<<22));
	GPIOG->MODER |= (0b10<<22);
	GPIOG->AFRH &= (~(0b1111<<12));
	GPIOG->AFRH |= (0b0110<<12);
	/********UART init***********/
	//M bit init(M1 M0) , sampling 16(OVER8), no even odd parity(PCE)
	USART4->CR1 &= (~(0x1<<28 | 0x1<<12 | 0x1<<15 | 0x1<<10));
	//TE RE UE
	USART4->CR1 |= (0x1<<3 | 0x1<<2 | 0x1<<0);
	//1 stop bit
	USART4->CR2 &= (~(0b11<<12));
	//BRR= 64MHz/115200 = 0x22B
	USART4->BRR =  0x22B;
	//no prescaling
	USART4->PRESC &= 0b0000;
}

//send a char
void put_char(const char str)
{
	//judge if the TXE==>UART_ISR[7]   is 1,if it's 1,then the next byte could be sent
	//1:empty  0:not empty
	while(!(USART4->ISR & (0x1<<7)));
	USART4->TDR = str;
	//judge if sending is finished     0 not finshed 1 finshed
	while (!(USART4->ISR & (0x1<<6)));
	
	
}


//send a string 
void put_string(const char* string)
{
	//the sign of the end of a string '\0' 
	const char *p = string;
	while (*p!='\0')
	{
		put_char(*p);
		p++;
	}
}


//recv a char 
char get_char()
{
	char ret;
	//1. judge if RXNE is 1,data received,0 data not received
	while (!(USART4->ISR & (0x1<<5)));
	//call put_char
	ret = USART4->RDR;
	return ret;
}


//recv a string 
char* get_string()
{
	//receive by loop
	
	//loop: recv a char,then display

	//enter===> '\r'

	int i;
	for(i = 0; i < sizeof(buff)-1;i++)
	{
		// receive a char
		buff[i] = get_char();
		// display the char 
		put_char(buff[i]);
		if(buff[i] == '\r')
			break;
	}
	buff[i] = '\0';
	put_char('\n');
	return buff;
}


