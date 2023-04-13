#include "gpio.h"
extern void printf(const char *fmt, ...);
void delay_ms(int ms)
{
	int i,j;
	for(i = 0; i < ms;i++)
		for (j = 0; j < 1800; j++);
}




int main()
{
	unsigned short hun;
	short temp;
	si7006_init();
	while(1)
	{
		hum = si7006_read_hum_data(0xE5);
		temp = si7006_read_temp_data(0xE0);
	}

	return 0;
}
