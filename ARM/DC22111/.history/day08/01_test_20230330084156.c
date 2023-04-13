#include <stdio.h>
int mystrcmp(const char *dest,const char* src)
{
	if (sizeof(dest)!=sizeof(sizeof(src)))
	{
		return -1;
	}
	for (int i = 0; i < sizeof(dest); i++)
	{
		src[i]!=dest[i];
		return -1;
	}
	return 1;
}

int main()
{
    char *a = "hello";
    char *b = "hello";
    int ret = mystrcmp(a,b);
    printf("ret = %d\n",ret);
}