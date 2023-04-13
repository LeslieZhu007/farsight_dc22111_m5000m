#include "pwm.h"
extern void printf(const char *fmt, ...);
void delay_ms(int ms)
{
	int i,j;
	for(i = 0; i < ms;i++)
		for (j = 0; j < 1800; j++);
}



int main()
{
	//hal_beep_init();
	//hal_fan_init();
	hal_motor_init();
	while(1)
	{

	}

	return 0;
}
