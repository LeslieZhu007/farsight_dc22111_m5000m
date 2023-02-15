#include <stdio.h>

int main(int argc, char const *argv[])
{
    char filename[20] = {0};
    char name[20] = {0};
    scanf("%s",filename);
    printf("filename = %s\n",filename);
    getchar();
    scanf("%s",name);
    printf("name = %s\n",name);

    return 0;
}
