#include "uart4.h"
#include "key.h"
extern void printf(const char *fmt, ...);
char buff[10]={0};
void delay_ms(int ms)
{
	int i,j;
	for(i = 0; i < ms;i++)
		for (j = 0; j < 1800; j++);
}


int main()
{
	hal_exti_init();
	hal_gicd_init();
    hal_gicc_init();
	while (1)
	{
		
	}
	

	return 0;
}