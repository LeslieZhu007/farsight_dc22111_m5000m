#include "uart4.h"
//init uart 
void hal_uart4_init()
{
	/******RCC init**************/
	rcc_t *rcc;
	rcc->MP_AHB4ENSETR |= (0x1<<1 | 0x1<<6);
	rcc->MP_APB1ENSETR |= (0x1<<16);
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
	uart_t *uart;
	//M bit init(M1 M0) , sampling 16(OVER8), no even odd parity(PCE)
	uart->CR1 &= (~(0x1<<28 | 0x1<<12 | 0x1<<15 | 0x1<<10));
	//TE RE UE
	uart->CR1 |= (0x1<<3 | 0x1<<2 | 0x1<<0);
	//1 stop bit
	uart->CR2 &= (~(0b11<<12));
	//BRR= 64MHz/115200 = 0x22B
	uart->BRR =  0x22B;
	//no prescaling
	uart->PRESC &= 0b0000;
}

//send a char
void put_char(const char str)
{
	//judge if the TXE==>UART_ISR[7]   is 1,if it's 1,then the next byte could be sent
	while(!(USART4->ISR & (0x1<<7)));
	USART4->TDR = str;


}

//send a string 
void put_string(const char* string)
{
	//the sign of the end of a string '\0' 


}


//recv a char 
char get_char()
{
	//1. judge if RXNE is 1,data received,0 data not received
	


}


//recv a string 
char* get_string()
{
	//receive by loop
	

	//loop: recv a char,then display
	


	//enter===> '\r'

}


