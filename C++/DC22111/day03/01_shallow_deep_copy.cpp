#include <iostream>
using namespace std;
class stu
{
    int age;
    int *score;
public:
    stu(int a,int s)
    {
        this->age = a;
        score = new int(s);
        cout<<"2 params constructor"<<endl;
    }

    void show()
    {
        cout<<"age:"<<age<<'\t'<<"score:"<<*score<<endl;
    }
    // stu(const stu &O) //浅拷贝。两个指针指向同一个空间
    // {
    //     this->age = O.age;
    //     this->score = O.score;
    //     cout<<"copy constructor"<<endl;
    // }
    stu(const stu &O)  //深拷贝
    {
        this->age = O.age;
        this->score = new int(*(O.score));
        cout<<"copy constructor"<<endl;
    }

    ~stu()
    {
        delete  score;
        cout<<"deconstructor"<<endl;
    }
};

int main()
{
    //int score = 89;
    stu s1(18,89);
    s1.show();
    stu s2(s1);
    
    return 0;
}
