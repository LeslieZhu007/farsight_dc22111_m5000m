#include "class.h"


struct class * create_class()
{
    //1.在堆区申请一个顺序表的空间
    struct Class *cls = (struct Class *)malloc(sizeof(struct Class));
    if (NULL == cls)
    {
        printf("class顺序表创建失败\n");
        return NULL;
    }
    //2.初始化顺序表
    memset(cls,0,sizeof(cls));

    
}

double input(struct Class *cls,int sum)
{
    double sum_score = 0;
    
    //没必要申请空间，class结构体中已经包含空间 ==> Student s[MAX]
    // struct Student *s =(struct Student *)malloc(sizeof(struct Student)*sum);
    // if (NULL == s)
    // {
    //     printf("student 类分配内存失败，请稍后重试");
    //     return -1;
    // }

    for (int i = 0; i < sum; i++)
    {
        printf("请输入第%d个学生的姓名:",i+1);
        //scanf("%s",s[i].name);
        scanf("%s",cls->s[i].name);
        printf("请输入第%d个学生的id:",i+1);
        //吸收垃圾字符   "%*c%c"   getchar()
        scanf("%*c%c",&cls->s[i].id);
        if (cls->s[i].id == 'T')
        {
            printf("请输入第%d个老师的课程:",i+1);
            scanf("%s",cls->s[i].subject);
        }

        if (cls->s[i].id == 'S')
        {
            printf("请输入第%d个学生的分数:",i+1);
            scanf("%lf",&cls->s[i].score);
            sum_score += cls->s[i].score;
        }
        
        printf("\n");
    }
}

void output(struct Class *cls,int sum)
{
     //输出所有人员信息
    for (int i = 0; i < sum; i++)
    {
        if (cls->s[i].id=='T')
        {
            printf("老师姓名%s\tid%c\t所教课程%s\n",cls->s[i].name,cls->s[i].id,cls->s[i].subject);
        }

        if (cls->s[i].id=='S')
        {
            printf("学生姓名%s\tid%c\t成绩%.2lf\n",cls->s[i].name,cls->s[i].id,cls->s[i].score);
        }
    }

}