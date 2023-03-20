#include <iostream>
#include <string>
#define MAX 1000
using namespace std;
struct Person//��ϵ�˽ṹ��
{
    string m_Name;
    int m_Sex;
    int m_Age;
    string m_Phone;
    string m_Addr;
};
struct Addressbooks//ͨѶ¼�ṹ��
{
    struct Person personArray[MAX];
    int m_Size;
};

//��ʾ�˵�����
void showMenu()
{
    cout<<"*************************"<<endl;
    cout<<"***** 1�������ϵ�� *****"<<endl;
    cout<<"***** 2����ʾ��ϵ�� *****"<<endl;
    cout<<"***** 3��ɾ����ϵ�� *****"<<endl;
    cout<<"***** 4��������ϵ�� *****"<<endl;
    cout<<"***** 5���޸���ϵ�� *****"<<endl;
    cout<<"***** 6�������ϵ�� *****"<<endl;
    cout<<"***** 0���˳�ͨѶ¼ *****"<<endl;
    cout<<"*************************"<<endl;
}
void addPerson(Addressbooks* abs)//1�������ϵ��
{
    if(abs->m_Size == MAX)
    {
        cout<<"ͨѶ¼�������޷���ӣ�"<<endl;
        return;
    }
    else
    {
        string name;
        cout<<"������������"<<endl;
        cin>>name;
        abs->personArray[abs->m_Size].m_Name = name;
        cout<<"�������Ա�"<<endl;
        cout<<"1 ---- ��"<<endl;
        cout<<"2 ---- Ů"<<endl;
        int sex = 0;
        while(true)
        {
            cin>>sex;
            if(sex == 1 || sex == 2)
            {
                abs->personArray[abs->m_Size].m_Sex = sex;
                break;
            }
            cout<<"������������������"<<endl;
        }
        cout<<"���������䣺"<<endl;
        int age = 0;
        while(true)
        {
            cin>>age;
            if(age > 0 && age < 120)
            {
                abs->personArray[abs->m_Size].m_Age = age;
                break;
            }
            cout<<"������������������"<<endl;
        }
        cout<<"��������ϵ�绰��"<<endl;
        string phone;
        cin>>phone;
        abs->personArray[abs->m_Size].m_Phone = phone;
        cout<<"�������ͥסַ��"<<endl;
        string address;
        cin>>address;
        abs->personArray[abs->m_Size].m_Addr = address;
        ++abs->m_Size;
        cout<<"��ӳɹ�"<<endl;
        system("pause");//�밴���������
        system("cls");//����
    }
}
void showPerson(Addressbooks* abs)//2����ʾ��ϵ��
{
    if(abs->m_Size == 0)
    {
        cout<<"��ǰ��¼Ϊ��"<<endl;
    }
    else
    {
        for(int i=0;i<abs->m_Size;i++)
        {
            cout<<"������"<<abs->personArray[i].m_Name<<'\t';
            cout<<"�Ա�"<<(abs->personArray[i].m_Sex == 1?"��":"Ů")<<'\t';
            cout<<"���䣺"<<abs->personArray[i].m_Age<<'\t';
            cout<<"�绰��"<<abs->personArray[i].m_Phone<<'\t';
            cout<<"סַ��"<<abs->personArray[i].m_Addr<<endl;
        }
    }
    system("pause");
    system("cls");
}
int isExist(Addressbooks* abs,string name)//�����ϵ���Ƿ����
{
    for(int i=0;i<abs->m_Size;i++)
    {
        if(abs->personArray[i].m_Name == name)
        {
            return i;
        }
    }
    return -1;//�������������û���ҵ�����-1
}
void deletePerson(Addressbooks* abs)//3��ɾ����ϵ��
{
    cout<<"��������Ҫɾ������ϵ�ˣ�"<<endl;
    string name;
    cin>>name;
    int ret = isExist(abs,name);
    if(ret != -1)
    {
        for(int i = ret;i<abs->m_Size;i++)
        {
            abs->personArray[i] = abs->personArray[i+1];//����ǰ��
        }
        abs->m_Size--;//����ͨѶ¼�е���Ա��
        cout<<"ɾ���ɹ�"<<endl;
    }
    else
    {
        cout<<"���޴���"<<endl;
    }
    system("pause");
    system("cls");
}
void findPerson(Addressbooks* abs)//4��������ϵ��
{
    cout<<"��������Ҫ���ҵ���ϵ�ˣ�"<<endl;
    string name;
    cin>>name;
    int ret = isExist(abs,name);
    if(ret != -1)
    {
        cout<<"������"<<abs->personArray[ret].m_Name<<'\t';
        cout<<"�Ա�"<<(abs->personArray[ret].m_Sex == 1?"��":"Ů")<<'\t';
        cout<<"���䣺"<<abs->personArray[ret].m_Age<<'\t';
        cout<<"�绰��"<<abs->personArray[ret].m_Phone<<'\t';
        cout<<"��ַ��"<<abs->personArray[ret].m_Addr<<endl;
    }
    else
    {
        cout<<"���޴���"<<endl;
    }
    system("pause");
    system("cls");
}
void modifyPerson(Addressbooks* abs)//5���޸���ϵ��
{
    cout<<"��������Ҫ�޸ĵ���ϵ�ˣ�"<<endl;
    string name;
    cin>>name;
    int ret = isExist(abs,name);
    if(ret != -1)
    {
        string name;
        cout<<"������������"<<endl;
        cin>>name;
        abs->personArray[ret].m_Name = name;
        cout<<"�������Ա�"<<endl;
        cout<<"1 ---- ��"<<endl;
        cout<<"2 ---- Ů"<<endl;
        int sex = 0;
        while(true)
        {
            cin>>sex;
            if(sex == 1 || sex == 2)
            {
                abs->personArray[ret].m_Sex = sex;
                break;
            }
            cout<<"������������������"<<endl;
        }
        cout<<"���������䣺"<<endl;
        int age = 0;
        while(true)
        {
            cin>>age;
            if(age > 0 && age < 120)
            {
                abs->personArray[ret].m_Age = age;
                break;
            }
            cout<<"������������������"<<endl;
        }
        cout<<"��������ϵ�绰��"<<endl;
        string phone;
        cin>>phone;
        abs->personArray[ret].m_Phone = phone;
        cout<<"�������ͥסַ��"<<endl;
        string address;
        cin>>address;
        abs->personArray[ret].m_Addr = address;
        cout<<"�޸ĳɹ�"<<endl;
    }
    else
    {
        cout<<"���޴���"<<endl;
    }
    system("pause");//�밴���������
    system("cls");//����
}
void clearPerson(Addressbooks* abs)//6�������ϵ��
{
    abs->m_Size = 0;//����ǰ��¼��ϵ���������㣬���߼���ղ���
    cout<<"ͨѶ¼��Ϣ�����"<<endl;
    system("pause");//�밴���������
    system("cls");//����
}

int main()
{
    Addressbooks abs;//����ͨѶ¼�ṹ�����
    abs.m_Size = 0;
    int select = 0;//�����û�ѡ������ı���
    while(true)
    {
        showMenu();
        cin>>select;
        switch (select)
        {
        case 1://1�������ϵ��2
            addPerson(&abs);
            break;
        case 2://2����ʾ��ϵ��3
            showPerson(&abs);
            break;
        case 3://3��ɾ����ϵ��4
            deletePerson(&abs);
            break;
        case 4://4��������ϵ��5
            findPerson(&abs);
            break;
        case 5://5���޸���ϵ��
            modifyPerson(&abs);
            break;
        case 6://6�������ϵ��
            clearPerson(&abs);
            break;
        case 0://0���˳�ͨѶ¼1
            cout<<"��ӭ�´�ʹ�ã�"<<endl;
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
