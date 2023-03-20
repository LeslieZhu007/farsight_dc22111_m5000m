#ifndef _ARRAY_TEMPLATE_H__
#define _ARRAY_TEMPLATE_H__

class Array
{
private:
    int mLength;
    int* mSpace;
public:
    Array(int length);
    Array(const Array& obj);
    int length();
    ~Array();
    int& operator[] (int i);
    Array& operator=(const Array& obj);
    bool operator==(const Array& obj);
    bool operator!=(const Array& obj);
    
    
    
};







#endif