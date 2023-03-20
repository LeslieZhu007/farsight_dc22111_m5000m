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