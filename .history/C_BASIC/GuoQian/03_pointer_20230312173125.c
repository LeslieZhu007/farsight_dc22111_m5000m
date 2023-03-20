#include <stdio.h>
#define SWAP(a,b){int t= a;a=b;b=t;}
typedef struct _Test
{
    int a[10000];
    int b[10000];
} Test;
void f(Test *t)
{

}


int main(int argc, char const *argv[])
{
    Test tt;
    f(&tt);

    int i = 1;
    int j = 2;
    printf("i=%d,j =%d\n",i,j);
    SWAP(i,j);
    printf("i=%d,j =%d\n",i,j);
    return 0;
}
