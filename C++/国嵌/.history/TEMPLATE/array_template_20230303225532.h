#ifndef _ARRAY_TEMPLATE_H__
#define _ARRAY_TEMPLATE_H__

template <class T>
class Array
{
private:
    int mLength;
    T* mSpace;
public:
    Array(int length);
    Array(const Array& obj);
    int length();
    ~Array();
    T& operator[] (int i);
    Array& operator=(const Array& obj);
    bool operator==(const Array& obj);
    bool operator!=(const Array& obj);
};







#endif