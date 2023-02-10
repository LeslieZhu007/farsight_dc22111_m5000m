#include <stdio.h>
int main(int argc, char const *argv[])
{
    
    int a = 3;
    int b = 5;
    int c = a ++ || ++b;
    prinf("a = %d,b = %d,c=%d",a,b,c);
    return 0;
}
