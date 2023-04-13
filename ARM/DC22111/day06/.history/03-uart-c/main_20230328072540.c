#include "uart4.h"
extern void printf(const char *fmt, ...);
void delay_ms(int ms)
{
	int i,j;
	for(i = 0; i < ms;i++)
		for (j = 0; j < 1800; j++);
}


char buff[50]={0};

int main()
{
	hal_uart4_init();
	//put_char('A');
	//put_string("uart4test*****************");
	//put_string("12345678");
	put_string("uart4 test*****************\r");
	
	/*
	while(1)
	{
		put_char(get_char()+1);	 //only A-Z a-z 0-9
	}
	*/
	while (1)
	{
		get_string();
		put_string(buff);
	}
	
	
	return 0;
}
