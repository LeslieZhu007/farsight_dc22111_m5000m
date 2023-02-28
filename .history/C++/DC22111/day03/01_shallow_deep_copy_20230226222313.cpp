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
    }

    void show()
    {
        cout<<"age:"<<age<<'\t'<<"score:"<<*score<<endl;
    }

    ~stu()
    {
        delete  score;
    }
};

int main()
{
    //int score = 89;
    stu s1(18,89);
    s1.show();
    return 0;
}
