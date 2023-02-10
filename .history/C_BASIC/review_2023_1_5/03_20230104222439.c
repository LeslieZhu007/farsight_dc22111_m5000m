#include <stdio.h>

int main(int argc, char const *argv[])
{
    int x[10]={0,1,2,3,4,5,6,7,8,9},*p1;
    p1 =  x+ 3;
    printf("*p1++ = %d\n",*p1++);
    

    return 0;
}
