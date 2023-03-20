#include <iostream>
using namespace std;
#define MAX 256

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
        printf("................欢迎来到通讯录管理系统....................\n");
        printf(".....................1.添加联系人........................\n");
        printf(".....................2.显示联系人......................................\n");
        printf(".....................3.删除联系人......................................\n");
        printf(".....................4.查找联系人......................................\n");
        printf(".....................5.退出......................................\n");
        printf(".................................................................\n");

        printf("请输入>>>");
        choose = getchar();
        while (getchar()!=10);
    
        switch (choose)
        {
            case '1':
                do_insert(db);
                break;
            case '2':
                do_delete(db);
                break;
            case '3':
                do_update(db);
                break;
            case '4':
                do_select_1(db);
                break;
            case '5':
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
