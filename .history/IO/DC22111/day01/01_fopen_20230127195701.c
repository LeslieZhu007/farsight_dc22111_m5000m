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

    fp = fopen("./fopen1.txt","r+");
    if (NULL == fp)
    {
        printf("fopen1函数运行失败\n");
        return -1;
    }
    printf("fopen1函数运行成功\n");

    fp = fopen("./fopen2.txt","w");
    if (NULL == fp)
    {
        printf("fopen2函数运行失败\n");
        return -1;
    }
    printf("fopen2函数运行成功\n");


    fp = fopen("./fopen3.txt","w+");
    if (NULL == fp)
    {
        printf("fopen3函数运行失败\n");
        return -1;
    }
    printf("fopen3函数运行成功\n");


    fp = fopen("./fopen4.txt","a");
    if (NULL == fp)
    {
        printf("fopen4函数运行失败\n");
        return -1;
    }
    printf("fopen4函数运行成功\n");

    fp = fopen("./fopen5.txt","a+");
    if (NULL == fp)
    {
        printf("fopen5函数运行失败\n");
        return -1;
    }
    printf("fopen5函数运行成功\n");
    

    //2.
    return 0;
}
