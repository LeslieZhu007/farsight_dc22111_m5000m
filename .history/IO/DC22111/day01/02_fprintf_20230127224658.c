#include <stdio.h>
typedef struct student
{
    char name[20];
    int age;
    float score;
} stu;


int main(int argc, char const *argv[])
{
    //打开fopen, w
    FILE *fp = fopen("./fprintf.txt","w");
    if(NULL == fp)
    {
        perror("fopen");
        return -1;
    }
    printf("fopen succeed\n");

    //向文件中写入数据
    fprintf(fp,"hello world %d\n",10);

    stu s;
    printf("请输入姓名，年龄，成绩 >>>");
    scanf("%s %d %f",s.name,&s.age,&s.score);
    printf("%s %d %g\n",s.name,s.age,s.score);
    fprintf(fp,"%s %d %g\n",s.name,s.age,s.score); //%g 只显示有效字符

    if(fclose(fp) < 0)
    {
        perror("fclose");
        return -1;
    }
    printf("fclose succeed\n");

    return 0;
}
