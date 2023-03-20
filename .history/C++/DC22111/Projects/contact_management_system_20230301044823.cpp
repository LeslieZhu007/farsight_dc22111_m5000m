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


contact::contact(string name,string sex,string age,string phone,string address):
name(name),sex(sex),age(age),phone(phone),address(address){}
contact::~contact(){}
contact::contact(){}

contact *contact_space_init()
{
    contact *p = new contact[MAX];
    return p;
}

int count=0;
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
        cout<<"姓名:"<<c[i].name<<","<<"性别:"<<c[i].sex<<","<<"年龄:"<<c[i].age\
        <<","<<"联系电话:"<<c[i].phone<<","<<"家庭住址:"<<c[i].address<<endl;
    }
}
void do_delete_contact(contact *c)
{
    
}
void do_query_contact(contact *c)
{
    
}
void do_modify_contact(contact *c)
{
    
}
void do_empty_contact(contact *c)
{
    
}