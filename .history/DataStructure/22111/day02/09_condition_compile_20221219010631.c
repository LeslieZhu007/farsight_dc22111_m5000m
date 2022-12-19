#include <stdio.h>
#define MAX 20

int main(int argc, char const *argv[])
{
    
    printf("max=%d\n",MAX);
#undef MAX
    printf("max=%d\n",MAX);




    return 0;
}
