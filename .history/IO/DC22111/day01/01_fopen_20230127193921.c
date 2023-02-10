#include <stdio.h>

int main(int argc, char const *argv[])
{
    //1.打开一个文件
    /*
    char path[] = "./fopen.txt";
    *path = 'a';

    char mode[] = "r";

    char *path_ptr = "./fopen.txt";
    //*path_ptr = 'a'; //不能修改
    */
    FILE *p = NULL;
    fopen("./fopen.txt","r");

    //2.
    return 0;
}
