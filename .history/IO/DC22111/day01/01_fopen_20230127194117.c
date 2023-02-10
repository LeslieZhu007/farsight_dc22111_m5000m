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
    FILE *fp = NULL;
    fp = fopen("./fopen.txt","r");
    if (NULL == fp)
    {
        printf("fopen函数运行失败\n");
        return -1;
    }

    printf("fopen函数运行成功\n");
    

    //2.
    return 0;
}
