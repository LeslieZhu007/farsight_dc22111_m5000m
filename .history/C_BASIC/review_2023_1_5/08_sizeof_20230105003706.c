#include <stdio.h>


int main(int argc, char const *argv[])
{
    int a = 520;
    //printf("%ld\n",sizeof(++a)); //sizeof

    sizeof(++a);

    printf("a = %d\n",a);  //520
    
    return 0;
}
