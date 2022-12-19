#include <stdio.h>
#include <stdlib.h>
#define MAX 20

/*
 * 注意scanf的垃圾字符处理问题
*/
struct Student
{
    char name[20];
    char id;    //身份  S：学生    T: 老师
    union 
    {
        double score;
        char subject[10];
    };
};

//定义班级结构体
struct Class
{
    struct Student s[MAX]; //学生数组
    int count;     //表示当前班级的人数
};

/*
定义一个班级（Class）结构体，
属性：学生数组(Student)、总人数(count)。
学生类型包括（姓名(name)、 身份（id）、分数(score)、课程（subject）），
课程和分数共享同一段内存，如果该成员是老师，
则使用课程属性，如果是学生，则使用分数属性。
完成，对班级人员的信息输入、输出、求所有学生的总成绩
*/

int main(int argc, char const *argv[])
{
    struct Class *cls = (struct Class *)malloc(sizeof(struct Class));
    if (NULL == cls)
    {
        printf("class 类分配内存失败，请稍后重试");
        return -1;
    }

    printf("请输入学生的总人数:\n");
    int sum;
    scanf("%d",&sum);
    cls->count = sum;
    if (sum > 20)
    {
        printf("请输入正确的学生人数\n");
        return -1;
    }
    struct Student *s =(struct Student *)malloc(sizeof(struct Student)*sum);
    if (NULL == s)
    {
        printf("student 类分配内存失败，请稍后重试");
        return -1;
    }

    for (int i = 0; i < sum; i++)
    {
        printf("请输入第%d个学生的姓名:",i+1);
        scanf("%s",s[i].name);
        printf("请输入第%d个学生的id:",i+1);
        //吸收垃圾字符   "%*c%c"   getchar()
        scanf("%*c%c",&s[i].id);
        if (s[i].id == 'T')
        {
            printf("请输入第%d个老师的课程:",i+1);
            scanf("%s",s[i].subject);
        }

        if (s[i].id == 'S')
        {
            printf("请输入第%d个学生的分数:",i+1);
            scanf("%lf",&s[i].score);
        }
        
        printf("\n");
    }


    //输出所有人员信息
    for (int i = 0; i < sum; i++)
    {
        if (s[i])
        {
            /* code */
        }
        
    }




    //求出所有学生的总成绩
    
    
    free(cls);
    free(s);
    cls=NULL;
    s=NULL;




    return 0;
}
