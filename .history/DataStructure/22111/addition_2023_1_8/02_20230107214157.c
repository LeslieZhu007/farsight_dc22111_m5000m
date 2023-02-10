#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    char str[] = {'a', 'b', 'c'};
    printf("sizeof str = %ld\n",sizeof(str));
    printf("strlen str = %ld\n",strlen(str));

    char str1[7] = "abc123";
    printf("sizeof str1 = %ld\n",sizeof(str1));
    printf("strlen str1 = %ld\n",strlen(str1));

    char str2[30]={0};
    char c;
    int i;
    for(c=65,i=0; c<=90; c++,i++){
        str2[i] = c;
    }
    //str[i] = 0;
    printf("%s\n", str2);

    char *str3 = "\ta\018bc";
    char *str3 = "\ta\017bc";
    int len = strlen(str3);
    printf("len = %d\n",len);
    for (int i = 0; i < len; i++)
    {
        printf("%c\n",str3[i]);
    }
    
    return 0;
}
