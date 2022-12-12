#include <stdio.h>
#define MAX_ERRNO	4095
int main(int argc,const char * argv[])
{
	unsigned long value = (unsigned long)-MAX_ERRNO;

	printf("(unsigned long)-4095 = %lx\n",value);



	return 0;
}
