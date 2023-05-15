#include "common.h"

//动态拼接sql
char* dynamic_sql(MSG *msg)
{
	int staffno = msg->info.staffno;
	int usertype = msg->info.usertype;
	strcpy(name,msg->info.name);
	char *passwd = msg->info.passwd;
	int age = msg->info.age;
	char *phone = msg->info.phone;
	char *addr = msg->info.addr;
	char *work = msg->info.work;
	char *date = msg->info.date;
	double salary = msg->info.salary;
    
    printf("staffno = %d\n", staffno);
	printf("usertype = %d\n", usertype);
    printf("name = %s\n", name);
    if (NULL == name)
    {
        printf("name is null\n");
    }
    
    printf("passwd = %s\n", passwd);
     if (NULL == passwd)
    {
        printf("passwd is null\n");
    }
    
    printf("age = %d\n", age);
    printf("phone = %s\n", phone);
     if (NULL == phone)
    {
        printf("phone is null\n");
    }
    
    printf("addr = %s\n", addr);
     if (NULL == addr)
    {
        printf("addr is null\n");
    }
    
    printf("work = %s\n", work);
    if (NULL == work)
    {
        printf("work is null\n");
    }
    printf("date = %s\n", date);
    if (NULL == date)
    {
        printf("date is null\n");
    }
    
    printf("salary = %f\n", salary);
    if (0 == (int)salary)
    {
        printf("salary is null\n");
    }
    
}

int main(int argc, char const *argv[])
{
    MSG msg;
    memset(&msg, 0, sizeof(MSG));
    msg.info.staffno = 1;
dynamic_sql(&msg);
    



    return 0;
}
