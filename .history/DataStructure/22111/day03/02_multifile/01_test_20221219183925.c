#include "class.h"

#include "class.h"
int main(int argc, char const *argv[])
{
    double sum_score = 0;
    struct Class *cls = (struct Class *)malloc(sizeof(struct Class));
    if (NULL == cls)
    {   
        printf("class 类分配内存失败，请稍后重试");
        return -1;
    }
    printf("请输入学生的总人数:\n");
    int sum = 0;
    scanf("%d",&sum);
    cls->count = sum;
    if (sum > 20)
    {
        printf("请输入正确的学生人数\n");
        return -1;
    }
    
    sum_score = input(cls,sum);

    output(cls,sum);
   
    //求出所有学生的总成绩
    printf("所有学生的总成绩为:%.2lf\n",sum_score);
    
    
    free(cls);
    cls=NULL;
    return 0;
}
