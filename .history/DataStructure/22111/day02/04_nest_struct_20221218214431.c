#include <stdio.h>
#include <string.h>
struct date
{
    int year;
    int month;
    int day;
};

struct Stu 
{
    char name[20];
    struct date birthday;
    double score;
};



int main(int argc, char const *argv[])
{
    struct Stu s;
    strcpy(s.name,"jack");
    struct date bir = {2020,2,22};
    s.birthday = bir;

    s.score = 99.5;

    //输出信息
    printf("姓名:%s,出生日期:%d年%d月%d日，分数%.2lf\n",s.name
     ,s.birthday.year,s.birthday.month,s.birthday.day,s.score);

     struct Stu *p = &s;
    printf("姓名:%s,出生日期:%d年%d月%d日，分数%.2lf\n",p->name
     ,p->birthday.year,p->birthday.month,p->birthday.day,p->score);

    return 0;
}
