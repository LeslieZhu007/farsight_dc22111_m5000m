#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Test(void)
{
    char *str = (char *)malloc(100);
    strcpy(str,"hello");
    free(str);
    if (str!=NULL)
    {
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
   Test();
    return 0;
}
