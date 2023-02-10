#include <stdio.h>
#include <string.h>
#include <unistd.h>

typedef struct student
{
    char name[20];
    int age;
    float score;
} stu;

int main(int argc, char const *argv[])
{
    //打开fopen, r
    FILE *fp = fopen("./01_fopen.c","r");
    if(NULL == fp)
    {
        perror("fopen");
        return -1;
    }
    printf("fopen succeed\n");

    //fscanf  此刻光标在文件尾
    char name[20];
    int age;
    float score;

    /*
    fscanf(fp,"%s%d%g",name,&age,&score);
    printf("name = %s,age = %d,score = %g\n",name,age,score);

    fscanf(fp,"%s%d%g",name,&age,&score);
    printf("name = %s,age = %d,score = %g\n",name,age,score);

    fscanf(fp,"%s%d%g",name,&age,&score);
    printf("name = %s,age = %d,score = %g\n",name,age,score);

    fscanf(fp,"%s%d%g",name,&age,&score);
    printf("name = %s,age = %d,score = %g\n",name,age,score);

    memset(name,0,sizeof(name));
    memset(&age,0,sizeof(age));
    memset(&score,0,sizeof(score));

    fscanf(fp,"%s%d%g",name,&age,&score);
    printf("name = %s,age = %d,score = %g\n",name,age,score);
    */
   stu s;
   int ret = 0;
char c;
   /*
   while (1)
   {
    memset(&s,0,sizeof(s));
    ret = fscanf(fp,"%s %d %g",s.name,&s.age,&s.score);
    if (EOF == ret)
    {
        printf("EOF met\n");
        break;
    }
    printf("name = %s,age = %d,score = %g\n",s.name,s.age,s.score);
   }
   */
    while (fscanf(fp,"%c",&c)>0)
    {
        printf("%c",c);
        memset(&c,0,sizeof(c));
        sleep(2);
    }
    
   
    if(fclose(fp) < 0)
    {
        perror("fclose");
        return -1;
    }
    printf("fclose succeed\n");

    return 0;
}
