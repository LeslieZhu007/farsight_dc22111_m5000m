#include <stdio.h>

int main(int argc, char const *argv[])
{
    //1.打开一个文件
    char path[] = "./fopen.txt";
    char mode[] = "r";

    char *path_ptr = "./fopen.txt";
    
    fopen(path_ptr,mode);

    //2.
    return 0;
}
