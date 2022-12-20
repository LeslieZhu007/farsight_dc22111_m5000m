#include "class.h"


clsSeqList * create_class()
{
    //1.在堆区申请一个顺序表的空间
    clsSeqList *cls = (clsSeqList *)malloc(sizeof(clsSeqList));
    if (NULL == cls)
    {
        printf("class顺序表创建失败\n");
        return NULL;
    }
    //2.初始化顺序表
    cls->count=0;//初始化数组长度
    printf("创建class顺序表成功\n");
    return cls;
}

double input(clsSeqList *cls)
{
    double sum_score = 0;
    while (1)
    {
        printf("请输入学生的姓名:\n");
        //scanf("%s",s[i].name);
        scanf("%s",cls->s[cls->count].name);
        printf("请输入学生的id:\n");
        //吸收垃圾字符   "%*c%c"   getchar()
        scanf("%*c%c",&cls->s[cls->count].id);
        if (cls->s[cls->count].id == 'T')
        {
            printf("请输入老师的课程:\n");
            scanf("%s",cls->s[cls->count].subject);
        }

        if (cls->s[cls->count].id == 'S')
        {
            printf("请输学生的分数:\n");
            scanf("%lf",&cls->s[cls->count].score);
            sum_score += cls->s[cls->count].score;
        }
        
        cls->count++;
        printf("是否继续(yes|no):\n");
        char feedback[20];
        scanf("%s",feedback);
        if (strcmp(feedback,"yes") == 0)
        {
            if (cls->count > MAX)
            {
                printf("班级人数已满，无法继续录入\n");
                break;
            }
            
        } else if (strcmp(feedback,"no") == 0)
        {
            break;
        }
    }

    return sum_score;
}

void output(clsSeqList *cls)
{
     //输出所有人员信息
    for (int i = 0; i < cls->count; i++)
    {
        if (cls->s[i].id=='T')
        {
            printf("%d\t老师姓名:%s\tid:%c\t所教课程:%s\n",i+1,cls->s[i].name,cls->s[i].id,cls->s[i].subject);
        }

        if (cls->s[i].id=='S')
        {
            printf("%d\t学生姓名:%s\tid:%c\t成绩:%.2lf\n",i+1,cls->s[i].name,cls->s[i].id,cls->s[i].score);
        }
    }
}


int class_empty(clsSeqList *cls)
{
    return cls->count == 0;
}

int class_full(clsSeqList *cls)
{
    return cls->count == MAX;
}


int class_add(clsSeqList *cls,Stu s)
{
    if (NULL == cls || class_full(cls))
    {
        printf("添加学生信息失败\n");
        return -1;
    }
    //添加逻辑
    cls->s[cls->count] = s;

    //表长变化
    cls->count++;
    printf("添加学生信息成功\n");

}

int class_insert_pos(clsSeqList *cls,int pos,Stu s)
{
    if (NULL==cls || class_full(cls) || pos < 0 || pos > cls->count)
    {
        printf("插入学生信息失败\n");
        return -1;
    }

    //腾空
    for (int i = cls->count-1; i >= pos; i--)
    {
        cls->s[i+1] = cls->s[i];
    }

    cls->s[pos] = s;

    cls->count++;

     printf("插入学生信息成功\n");
    
}



int class_delete_pos(clsSeqList *cls,int pos)
{
     if (NULL==cls || class_empty(cls) || pos < 0 || pos >= cls->count)
    {
        printf("删除学生信息失败\n");
        return -1;
    }

    for (int i = pos; i < cls->count; i++)
    {
        cls->s[i] = cls->s[i+1];
    }
    
    cls->count--;

    printf("删除学生信息成功\n");
}
