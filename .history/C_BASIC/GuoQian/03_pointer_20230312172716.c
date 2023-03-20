#include <stdio.h>

typedef struct _Test
{
    int a[10000];
    int b[10000];
} Test;
void f(Test t)
{

}


int main(int argc, char const *argv[])
{
    Test tt;
    f(&tt);
    return 0;
}
