#include <iostream>
using namespace std;

class stu
{
    string name;
    int age;
    int *p;
public:
    stu()=default;
    //构造函数
    stu(string name,int age,int p):name(name),age(age)
    {
        this->p = new int(p);
        cout<<"2 params constructor"<<endl;
    }
    //拷贝构造函数
    stu(const stu& O)
    {
        this->age = O.age;
        this->name = O.name;
        this->p = new int(*(O.p));
        cout<<"copy  constructor"<<endl;
    }

    //拷贝赋值函数
    stu& operator= (const stu& O)
    {
        this->age = O.age;
        this->name = O.name;
        this->p = new int(*(O.p));
        cout<<"copy  operator"<<endl;
        return *this;
    }
    ~stu()
    {
        cout<<"deconstructor"<<endl;
    }
};

int main()
{
    stu s1("jack",2,3); //构造函数定义的就是int 而不是int *
    stu s2(s1);
    stu s3(s1);
    s3 = s2;
    return 0;
}
