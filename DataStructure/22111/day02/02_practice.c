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
    char name[20];  //char * name  ==> error ,must specify a size
    double score;
};


void sort_score(struct Student *stu,int size) //struct Student *stu     struct Student stu[]
{
    int i,j,count=0;
    struct Student t;
	for(i=1;i<size;i++)
	{
		count=0;
		for(j=0;j<size-i;j++)
		{
			if(stu[j].score <stu[j+1].score)
			{
				t=stu[j];stu[j]=stu[j+1];stu[j+1]=t;
				count++;//计算交换的次数的
				//如果count=0,没有交换，证明就是有序的
			}
		}
		if(count==0)
		{
			break;
		}
	}
    
}
void print_student_info(struct Student stu[],int count) //struct Student *stu     struct Student stu[]
{
    for(int i = 0;i < count;i++)
    {
        printf("第%d个学生的姓名:%s,年龄:%d,成绩:%.2lf\n",i+1,stu[i].name,stu[i].age,stu[i].score);

		//printf("%s\t%d\t%.2lf\n");
    }
}
int main(int argc, char const *argv[])
{
	//error stu[5]
    struct Student *stu = (struct Student *)malloc(sizeof(struct Student)*COUNT);
	if(NULL== stu)
	{
		printf("memory alloc error\n");
		return -1;
	}


    printf("请输入五名学生的信息:\n");
    for (int i = 0; i < COUNT; i++)
    {
        printf("请输入第%d学生的年纪:",i+1);
        scanf("%d",&(stu[i].age));
        printf("请输入第%d学生的姓名:",i+1);
        scanf("%s",stu[i].name);
        printf("请输入第%d学生的成绩:",i+1);
        scanf("%lf",&(stu[i].score));

		printf("\n");
    }

    //然后求出这五名学生的平均分输出，
    double sum_score = 0;
    for (int i = 0; i < COUNT; i++)
    {
        sum_score += stu[i].score;
    }

    printf("五名学生的平均分为:%.2lf\n",sum_score/COUNT);
    
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

    printf("年龄最大学生信息为:年纪: %d,姓名:%s,分数: %.2lf\n",stu[max_score_index].age
    ,stu[max_score_index].name,stu[max_score_index].score);
    
    //并将这五名学生按成绩进行排序后输出结果
    sort_score(stu,COUNT);
    

    //打印学生信息
    print_student_info(stu,COUNT);


	//free heap space;
	free(stu);
	stu = NULL;
    return 0;
}

