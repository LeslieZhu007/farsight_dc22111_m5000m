#include <stdio.h>

int main(int argc, char const *argv[])
{
    
    int x[5]={2,4,6,8,10}, *p, **pp ;
   p=x , pp = &p ;
   printf("%d",*(p++));
   printf("%3d",**pp);




    return 0;
}
