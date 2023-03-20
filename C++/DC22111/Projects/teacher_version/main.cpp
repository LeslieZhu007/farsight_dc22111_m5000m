#include <iostream>
#include <string>
#define MAX 1000
using namespace std;
struct Person//联系人结构体
{
    string m_Name;
    int m_Sex;
    int m_Age;
    string m_Phone;
    string m_Addr;
};
struct Addressbooks//通讯录结构体
{
    struct Person personArray[MAX];
    int m_Size;
};

//显示菜单界面
void showMenu()
{
    cout<<"*************************"<<endl;
    cout<<"***** 1、添加联系人 *****"<<endl;
    cout<<"***** 2、显示联系人 *****"<<endl;
    cout<<"***** 3、删除联系人 *****"<<endl;
    cout<<"***** 4、查找联系人 *****"<<endl;
    cout<<"***** 5、修改联系人 *****"<<endl;
    cout<<"***** 6、清空联系人 *****"<<endl;
    cout<<"***** 0、退出通讯录 *****"<<endl;
    cout<<"*************************"<<endl;
}
void addPerson(Addressbooks* abs)//1、添加联系人
{
    if(abs->m_Size == MAX)
    {
        cout<<"通讯录已满，无法添加！"<<endl;
        return;
    }
    else
    {
        string name;
        cout<<"请输入姓名："<<endl;
        cin>>name;
        abs->personArray[abs->m_Size].m_Name = name;
        cout<<"请输入性别："<<endl;
        cout<<"1 ---- 男"<<endl;
        cout<<"2 ---- 女"<<endl;
        int sex = 0;
        while(true)
        {
            cin>>sex;
            if(sex == 1 || sex == 2)
            {
                abs->personArray[abs->m_Size].m_Sex = sex;
                break;
            }
            cout<<"输入有误，请重新输入"<<endl;
        }
        cout<<"请输入年龄："<<endl;
        int age = 0;
        while(true)
        {
            cin>>age;
            if(age > 0 && age < 120)
            {
                abs->personArray[abs->m_Size].m_Age = age;
                break;
            }
            cout<<"输入有误，请重新输入"<<endl;
        }
        cout<<"请输入联系电话："<<endl;
        string phone;
        cin>>phone;
        abs->personArray[abs->m_Size].m_Phone = phone;
        cout<<"请输入家庭住址："<<endl;
        string address;
        cin>>address;
        abs->personArray[abs->m_Size].m_Addr = address;
        ++abs->m_Size;
        cout<<"添加成功"<<endl;
        system("pause");//请按任意键继续
        system("cls");//清屏
    }
}
void showPerson(Addressbooks* abs)//2、显示联系人
{
    if(abs->m_Size == 0)
    {
        cout<<"当前记录为空"<<endl;
    }
    else
    {
        for(int i=0;i<abs->m_Size;i++)
        {
            cout<<"姓名："<<abs->personArray[i].m_Name<<'\t';
            cout<<"性别："<<(abs->personArray[i].m_Sex == 1?"男":"女")<<'\t';
            cout<<"年龄："<<abs->personArray[i].m_Age<<'\t';
            cout<<"电话："<<abs->personArray[i].m_Phone<<'\t';
            cout<<"住址："<<abs->personArray[i].m_Addr<<endl;
        }
    }
    system("pause");
    system("cls");
}
int isExist(Addressbooks* abs,string name)//检测联系人是否存在
{
    for(int i=0;i<abs->m_Size;i++)
    {
        if(abs->personArray[i].m_Name == name)
        {
            return i;
        }
    }
    return -1;//如果遍历结束都没有找到返回-1
}
void deletePerson(Addressbooks* abs)//3、删除联系人
{
    cout<<"请输入您要删除的联系人："<<endl;
    string name;
    cin>>name;
    int ret = isExist(abs,name);
    if(ret != -1)
    {
        for(int i = ret;i<abs->m_Size;i++)
        {
            abs->personArray[i] = abs->personArray[i+1];//数据前移
        }
        abs->m_Size--;//更新通讯录中的人员数
        cout<<"删除成功"<<endl;
    }
    else
    {
        cout<<"查无此人"<<endl;
    }
    system("pause");
    system("cls");
}
void findPerson(Addressbooks* abs)//4、查找联系人
{
    cout<<"请输入您要查找的联系人："<<endl;
    string name;
    cin>>name;
    int ret = isExist(abs,name);
    if(ret != -1)
    {
        cout<<"姓名："<<abs->personArray[ret].m_Name<<'\t';
        cout<<"性别："<<(abs->personArray[ret].m_Sex == 1?"男":"女")<<'\t';
        cout<<"年龄："<<abs->personArray[ret].m_Age<<'\t';
        cout<<"电话："<<abs->personArray[ret].m_Phone<<'\t';
        cout<<"地址："<<abs->personArray[ret].m_Addr<<endl;
    }
    else
    {
        cout<<"查无此人"<<endl;
    }
    system("pause");
    system("cls");
}
void modifyPerson(Addressbooks* abs)//5、修改联系人
{
    cout<<"请输入您要修改的联系人："<<endl;
    string name;
    cin>>name;
    int ret = isExist(abs,name);
    if(ret != -1)
    {
        string name;
        cout<<"请输入姓名："<<endl;
        cin>>name;
        abs->personArray[ret].m_Name = name;
        cout<<"请输入性别："<<endl;
        cout<<"1 ---- 男"<<endl;
        cout<<"2 ---- 女"<<endl;
        int sex = 0;
        while(true)
        {
            cin>>sex;
            if(sex == 1 || sex == 2)
            {
                abs->personArray[ret].m_Sex = sex;
                break;
            }
            cout<<"输入有误，请重新输入"<<endl;
        }
        cout<<"请输入年龄："<<endl;
        int age = 0;
        while(true)
        {
            cin>>age;
            if(age > 0 && age < 120)
            {
                abs->personArray[ret].m_Age = age;
                break;
            }
            cout<<"输入有误，请重新输入"<<endl;
        }
        cout<<"请输入联系电话："<<endl;
        string phone;
        cin>>phone;
        abs->personArray[ret].m_Phone = phone;
        cout<<"请输入家庭住址："<<endl;
        string address;
        cin>>address;
        abs->personArray[ret].m_Addr = address;
        cout<<"修改成功"<<endl;
    }
    else
    {
        cout<<"查无此人"<<endl;
    }
    system("pause");//请按任意键继续
    system("cls");//清屏
}
void clearPerson(Addressbooks* abs)//6、清空联系人
{
    abs->m_Size = 0;//将当前记录联系人数量置零，做逻辑清空操作
    cout<<"通讯录信息已清空"<<endl;
    system("pause");//请按任意键继续
    system("cls");//清屏
}

int main()
{
    Addressbooks abs;//创建通讯录结构体变量
    abs.m_Size = 0;
    int select = 0;//创建用户选择输入的变量
    while(true)
    {
        showMenu();
        cin>>select;
        switch (select)
        {
        case 1://1、添加联系人2
            addPerson(&abs);
            break;
        case 2://2、显示联系人3
            showPerson(&abs);
            break;
        case 3://3、删除联系人4
            deletePerson(&abs);
            break;
        case 4://4、查找联系人5
            findPerson(&abs);
            break;
        case 5://5、修改联系人
            modifyPerson(&abs);
            break;
        case 6://6、清空联系人
            clearPerson(&abs);
            break;
        case 0://0、退出通讯录1
            cout<<"欢迎下次使用！"<<endl;
            system("pause");
            return 0;
            break;
        default:
            break;
        }
    }
    system("pause");
    return 0;
}
