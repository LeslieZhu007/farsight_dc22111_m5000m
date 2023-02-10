#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Func(char str[100])
{
    printf("sizeof(str) = %d\n",sizeof(str));
}

void Test(void)
{
    char *str = (char *)malloc(100);
    strcpy(str,"hello");
    free(str);
    if (str!=NULL)
    {
        printf("str=%p\n",str);
        strcpy(str,"world");
        printf(str);
        printf("\n");
    }
    
    
}

int main(int argc, char const *argv[])
{
    /*
    int a[5] = {1,2,3,4,5};
    int *ptr = (int *)(&a+1);
    printf("%d %d\n",*(a+1),*(ptr-1));
    */
   //Test();
   char str[100];
   Func(str);
    return 0;
}
