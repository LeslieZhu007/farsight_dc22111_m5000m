#include <iostream>
using namespace std;
#define MAX 256

void do_add_contact(contact *c);
void do_show_contact(contact *c);
void do_delete_contact(contact *c);
void do_query_contact(contact *c);
void do_modify_contact(contact *c);
void do_empty_contact(contact *c);

class contact
{
private:
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
contact::contact(string name,string sex,string age,string phone,string address):
name(name),sex(sex),age(age),phone(phone),address(address){}
contact::~contact(){}
contact::contact(){}

contact *contact_space_init()
{
    contact *p = new contact[MAX];
    return p;
}




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
                do_add_contact(contact *c);
                break;
            case '2':
                do_show_contact(contact *c);
                break;
            case '3':
                do_delete_contact(contact *c);
                break;
            case '4':
                do_query_contact(contact *c);
                break;
            case '5':
                do_modify_contact(contact *c);
                break;
            case '6':
                do_empty_contact(contact *c);
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

}
void do_show_contact(contact *c)
{
    
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