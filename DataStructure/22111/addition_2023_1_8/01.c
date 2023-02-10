#include <stdio.h>
int main(int argc, char const *argv[])
{
    /*
    int a = 3;
    int b = 5;
    int c = a ++ || ++b;
    */
   /*
   int a = 0;
   int b = 5;
   int c = a>b?a++:++b;
   */

  int a = 20;
   int b = 5;
   int c = 10;
   c *= a + b;
    printf("a = %d,b = %d,c = %d\n",a,b,c);
    return 0;
}
