#include "uart4.h"
//init uart 
void hal_uart4_init()
{
	/******RCC init**************/
	rcc_t *rcc;
	rcc->MP_AHB4ENSETR |= 

	/********GPIO init***********/


	/********UART init***********/

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


