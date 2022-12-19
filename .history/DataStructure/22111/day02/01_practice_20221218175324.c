#include <stdio.h>
#include <stdlib.h>
#define COUNT 5

/**
 * 学生类型 name,age,score
 * 一个班级有五名学生，分别输入这五名学生的
 * 信息，然后求出这五名学生的平均分输出，
 * 输出最大年龄学生的信息
 * 
 * 并将这五名学生按成绩进行排序后输出结果
 * 
 * 要求: 在堆区申请空间
*/
struct Student
{
    int age;
    char* name;
    double score;
};

int main(int argc, char const *argv[])
{
    struct Student stu[5] = (struct Student *)malloc(sizeof(struct Student)*COUNT);
    printf("请输入五名学生的信息:\n");
    for (int i = 0; i < COUNT; i++)
    {
        printf("请输入第%d学生的年纪:",i+1);
        scanf("%d",&(stu[i].age));
        printf("请输入第%d学生的姓名:",i+1);
        scanf("%d",stu[i].name);
        printf("请输入第%d学生的成绩:",i+1);
        scanf("%ld",&(stu[i].score));
    }

    //然后求出这五名学生的平均分输出，
    double sum_score = 0;
    for (int i = 0; i < COUNT; i++)
    {
        sum_score += stu[i].score;
    }

    printf("五名学生的平均分为:%ld\n",sum_score/COUNT);
    
    //输出最大年龄学生的信息
    int max_age = 0,max_score_index=0;
    for (int i = 0; i < COUNT; i++)
    {
        if (max_age < stu[i].age)
        {
            max_age = stu[i].age;
            max_score_index = i;
        }
    }

    printf("年龄最大学生信息为:年纪: %d,姓名:%s,分数: %ld\n",stu[max_score_index].age
    ,stu[max_score_index].name,stu[max_score_index].score);
    
    //并将这五名学生按成绩进行排序后输出结果
    
    




    return 0;
}
