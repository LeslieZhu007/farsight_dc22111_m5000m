#include <stdio.h>
#define MAX 5
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
    struct Student s[MAX];
};

int main(int argc, char const *argv[])
{
    
    





    return 0;
}
