#include <stdio.h>

int main(int argc, char const *argv[])
{
    //1.打开一个文件
    char path[] = "./fopen.txt";
    *path = 'a';

    char mode[] = "r";

    char *path_ptr = "./fopen.txt";
    *path_ptr = 'a';

    fopen(path_ptr,mode);

    //2.
    return 0;
}
