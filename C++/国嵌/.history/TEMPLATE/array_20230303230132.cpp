#include "array_template.h"

template<class T>
Array<T>::Array(int length)
{
    if (length < 0)
    {
        length = 0;
    }
    
    mLength = length;
    mSpace = new T[mLength];
}


template<class T>
Array<T>::Array(const Array& obj)
{
    mLength = obj.mLength;
    mSpace = new T[mLength];
    for (int i = 0; i < mLength; i++)
    {
        mSpace[i] = obj.mSpace[i];
    }
    
}