#include <stdio.h>

int main(int argc, char const *argv[])
{
    char filename = 0;
    char name = 0;
    scanf("%c",&filename);
    printf("filename = %c\n",filename);
    //while(getchar()!=10);
    getchar();
    scanf("%c",&name);
    printf("name = %c\n",name);

    return 0;
}
