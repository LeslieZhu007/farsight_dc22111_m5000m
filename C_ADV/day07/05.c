#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
argc: 参数的个数
argv: 命令行输入的字符串

*/
int main(int argc, char const *argv[])
{
    // char a[] = "abc";
    // char b[] = "abccd";
    // char c[] = "abdfdgdfgdfgc";

   // char str[3][50] = {"abc","abccd","abdfdgdfgdfgc"};
    
    char *str[3] = {"abc","abccd","abdfdgdfgdfgc"};
    for (int i = 0; i < 3; i++)
    {
        printf("str[%d]=%s,addr=%p\n",i,str[i],str[i]);
    }
    
    //str[0]="abc"
    //str[1]="abccd"

    /*
    printf("argc=%d\n",argc);
    printf("argv[0]=%s\n",argv[0]);
    printf("argv[1]=%s\n",argv[1]);
    printf("argv[2]=%s\n",argv[2]);
    printf("argv[3]=%s\n",argv[3]);
*/
/*
    int a = atoi(argv[1]);
    int b = atoi(argv[3]);

    if (strcmp(argv[2],"+")==0)
    {
        printf("%s + %s = %d\n",argv[1],argv[3],a+b);
    }

    if (strcmp(argv[2],"-")==0)
    {
        printf("%s - %s = %d\n",argv[1],argv[3],a-b);
    }


    if (strcmp(argv[2],"*")==0)
    {
        printf("%s * %s = %d\n",argv[1],argv[3],a*b);
    }

    if (strcmp(argv[2],"/")==0)
    {
        if (b == 0)
        {
            printf("除数不能为0\n");
        }
        
        printf("%s / %s = %.1f\n",argv[1],argv[3],1.0*a/b);
    }
    */
   for (size_t i = 0; i < sizeof(argv[0]); i++)
   {
    printf("%c\n",*(argv[0]+i));
   }
   

    return 0;
}
