#include <iostream>
using namespace std;
#define MAX 256
class contact
{
public:
    string name;
    string sex;
    string age;
    string phone;
    string address;
public:
    contact(string name,string sex,string age,string phone,string address);
    ~contact();
    contact();
};
void do_add_contact(contact *c);
void do_show_contact(contact *c);
void do_delete_contact(contact *c);
void do_query_contact(contact *c);
void do_modify_contact(contact *c);
void do_empty_contact(contact *c);
int do_check_exist(contact *c,string name);
void print_contact(contact c);


contact::contact(string name,string sex,string age,string phone,string address):
name(name),sex(sex),age(age),phone(phone),address(address){}
contact::~contact(){}
contact::contact(){}

contact *contact_space_init()
{
    contact *p = new contact[MAX];
    return p;
}

int count=1;
int main(int argc, char const *argv[])
{
    contact *c = contact_space_init();
    char choose = 0;
    while (1)
    {
        printf("................欢迎来到通讯录管理系统.....................\n");
        printf(".....................1.添加联系人.........................\n");
        printf(".....................2.显示联系人.........................\n");
        printf(".....................3.删除联系人.........................\n");
        printf(".....................4.查找联系人..........................\n");
        printf(".....................5.修改联系人..........................\n");
        printf(".....................6.清空联系人..........................\n");
        printf(".....................7.退出通讯录..........................\n");
        printf("请输入>>>");
        choose = getchar();
        while (getchar()!=10);
        switch (choose)
        {
            case '1':
                do_add_contact(c);
                break;
            case '2':
                do_show_contact(c);
                break;
            case '3':
                do_delete_contact(c);
                break;
            case '4':
                do_query_contact(c);
                break;
            case '5':
                do_modify_contact(c);
                break;
            case '6':
                do_empty_contact(c);
                break;
            case '7':
                goto END;
                break;
            
            default:
                printf("输入错误，请重新输入\n");
        }

        //请按任意键清屏
        printf("请按任意键清屏\n");
        while (getchar()!=10);
        system("clear");
        
    }
END:   
    delete[] c;
    return 0;
}

void do_add_contact(contact *c)
{
    if (count>MAX)
    {
        cout<<"存储空间已满，添加联系人失败"<<endl;
        return;
    }
    
    cout<<"请输入联系人姓名，性别，年龄，联系电话，家庭住址，以空格隔开>>";
    string name;
    string sex;
    string age;
    string phone;
    string address;
    cin>>name>>sex>>age>>phone>>address;
    while (getchar()!=10);
    contact c1(name,sex,age,phone,address);
    c[count] = c1;
    count++;
    cout<<"联系人:"<<name<<"添加成功"<<endl;
}
void do_show_contact(contact *c)
{
    for (int i = 0; i < count; i++)
    {
        print_contact(c[i]);
    }
}
void do_delete_contact(contact *c)
{
    cout<<"请输入要删除的联系人的姓名>>";
    string name;
    cin>>name;
    while (getchar()!=10);
    int ret = do_check_exist(c,name);
    if (-1 != ret)
    {
        for (int i = ret; i < count; i++)
        {
            c[i] = c[i+1];
        }
        count--;
        cout<<"删除联系人:"<<name<<"成功"<<endl;
    } else
    {
        cout<<"查无此人"<<endl;
    }
}
void do_query_contact(contact *c)
{
    cout<<"请输入要查找的联系人的姓名>>";
    string name;
    cin>>name;
    while (getchar()!=10);
    int ret = do_check_exist(c,name);
    if (-1 != ret)
    {
        print_contact(c[ret]);
    } else
    {
        cout<<"查无此人"<<endl;
    }
}
void do_modify_contact(contact *c)
{
    cout<<"请输入要修改的联系人的姓名>>";
    string name;
    cin>>name;
    while (getchar()!=10);
    int ret = do_check_exist(c,name);
    if (-1 != ret)
    {
        cout<<"请输入联系人:"<<name<<" 的新信息，性别，年龄，联系电话，家庭住址，以空格隔开>>";
        string sex;
        string age;
        string phone;
        string address;
        cin>>sex>>age>>phone>>address;
        while (getchar()!=10);
        c[ret].sex = sex;
        c[ret].age = age;
        c[ret].phone = phone;
        c[ret].address = address;
        cout<<"请输入联系人:"<<name<<"的新信息修改成功"<<endl;
    } else
    {
        cout<<"查无此人"<<endl;
    }
}
void do_empty_contact(contact *c)
{
    count=0;
}


int do_check_exist(contact *c,string name)
{
    for (int i = 0; i < count; i++)
    {
        if (c[i].name == name)
        {
            return i;
        } 
    }
    return -1;
}


void print_contact(contact c)
{
    cout<<"姓名:"<<c.name<<","<<"性别:"<<c.sex<<","<<"年龄:"<<c.age\
        <<","<<"联系电话:"<<c.phone<<","<<"家庭住址:"<<c.address<<endl;
}