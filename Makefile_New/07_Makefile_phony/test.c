#include <stdio.h>

extern int add(int,int);
extern int sub(int,int);
extern int mul(int,int);
extern int div(int,int);

int main(int argc,const char * argv[])
{

	printf("add(100,100)=%d\n",add(100,100));	
	printf("sub(100,100)=%d\n",sub(100,100));	
	printf("mul(100,100)=%d\n",mul(100,100));	
	printf("div(100,100)=%d\n",div(100,100));	




	return 0;
}
