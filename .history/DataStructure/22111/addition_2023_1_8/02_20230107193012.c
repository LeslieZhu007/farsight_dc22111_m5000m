#include <stdio.h>

int main(int argc, char const *argv[])
{
    char str[7];
    str = "abc123";  //错误
    //正确
    str[0] = 'a'; str[1] = 'b'; str[2] = 'c';
    str[3] = '1'; str[4] = '2'; str[5] = '3';
    





    return 0;
}
