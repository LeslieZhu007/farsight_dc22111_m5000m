#include<stdio.h>
int main(int argc, const char *argv[])
{
    FILE *fp;          //定义文件指针
    char str[] = "hello world";

    //文件操作三部曲
    //一、打开文件
    fp = fopen(".//file.txt", "a+");        //以只写的形式打开文件 并且将文件的起始地址赋值给指针fp
    if(NULL == fp)
    {
        printf("open error\n");
        return -1;
    }

    //读写数据
    fprintf( fp ,"%s", str);    //想fp指针指向的文件中以%s的格式输出一个字符串str

    //关闭文件
    fclose(fp);        //关闭fp指向的文件

    //×××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××
    fp = fopen(".//file.txt", "r");              //以只读的形式打开文件
    if(NULL==fp)
    {
        printf("open error\n");
        return -1;
    }

    //读取数据
    char buf[100];
    
    while(!feof(fp))    //当文件没有达到末尾时，不断进行摘取字符串
    {
    fscanf(fp ,"%s", buf);     //从fp指向的文件中，摘取一个字符串以%s的格式放入buf中，但是，遇到空格或回车会结束输入
    printf("buf = %s\n", buf);
    }

    //关闭文件
    fclose(fp);

    
    return 0;
}
