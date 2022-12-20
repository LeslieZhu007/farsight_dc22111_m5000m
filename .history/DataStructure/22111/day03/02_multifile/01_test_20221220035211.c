#include "class.h"

#include "class.h"
int main(int argc, char const *argv[])
{
    double sum_score = 0;
    clsSeqList *cls = create_class();
    if (NULL == cls)
    {   
        printf("class 类分配内存失败，请稍后重试");
        return -1;
    }
    sum_score = input(cls);
    output(cls);
   
    //求出所有学生的总成绩
    printf("所有学生的总成绩为:%.2lf\n",sum_score);
    
    
    free(cls);
    cls=NULL;
    return 0;
}
