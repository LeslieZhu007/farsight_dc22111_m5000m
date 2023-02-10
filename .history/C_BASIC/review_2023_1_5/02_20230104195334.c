#include <stdio.h>

int main(int argc, char const *argv[])
{
    
    

    char a[30]="1111",b[]="hello";
	strcpy(a,b);//===>a
//	printf("a=%s  b=%s\n",a,b);
	printf("a=%s",strcpy(a,b));
	
	
	strcpy(a,"hqyj");
	printf("a=%s\n",a);

	strcpy("111","222");  //不可以修改常量 段错误

    return 0;
}
