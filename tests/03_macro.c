#include <stdio.h>
#define MAX(a,b)  ({\
		int max; \
		if(a > b) \
		{\
			max = a;\
		}\
		else\
		{\
			max = b;\
		}\
		max;\
		})

#define PRINT_MSG(msg) do{printf("%s\n",msg); return -1;} while(0)

int main()
{
	
	printf("MAX(10,20)= %d\n",MAX(10,20));

	PRINT_MSG("process invoke error");
	return 0;
}
