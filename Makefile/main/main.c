#include<stdio.h>
extern int sub(int,int);
extern int add(int,int);
int main()
{

	printf("add=%d\n",add(1,2));
	printf("sub=%d\n",sub(2,1));
	return 0;
}
