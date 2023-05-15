#include "common.h"

//动态拼接sql
char* dynamic_sql(MSG *msg)
{
	int staffno = msg->info.staffno;
	int usertype = msg->info.usertype;
	char *name = msg->info.name;
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
    printf("passwd = %s\n", passwd);
    printf("age = %d\n", age);
    printf("phone = %s\n", phone);
    printf("addr = %s\n", addr);
    printf("work = %s\n", work);
    printf("date = %s\n", date);
    printf("salary = %f\n", salary);
    
}

int main(int argc, char const *argv[])
{
    MSG msg;
    memset(&msg, 0, sizeof(MSG));
    msg.info.staffno = 1;
dynamic_sql(&msg);
    



    return 0;
}
