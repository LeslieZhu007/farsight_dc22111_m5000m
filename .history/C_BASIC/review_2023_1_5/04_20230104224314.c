#include <stdio.h>

int main(int argc, char const *argv[])
{
    
    nt x[5]={2,4,6,8,10}, *p, **pp ;
   p=x , pp = &p ;
   printf(ā%dā,*(p++));
   printf(ā%3dā,**pp);




    return 0;
}
