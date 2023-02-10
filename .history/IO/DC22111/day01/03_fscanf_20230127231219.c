#include <stdio.h>


int main(int argc, char const *argv[])
{
    //打开fopen, r
    FILE *fp = fopen("./fprintf.txt","r");
    if(NULL == fp)
    {
        perror("fopen");
        return -1;
    }
    printf("fopen succeed\n");

    //fscanf  此刻光标在文件尾
    char name[20];
    char name1[20];
    int age;
    float score;
    fscanf(fp,"%s %d %g",name,name1,&score);
    printf("name = %s,name1 = %s,score = %g\n",name,name1,score);

    if(fclose(fp) < 0)
    {
        perror("fclose");
        return -1;
    }
    printf("fclose succeed\n");

    return 0;
}
