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
Array<T>::Array(const Array<T>& obj)
{
    mLength = obj.mLength;
    mSpace = new T[mLength];
    for (int i = 0; i < mLength; i++)
    {
        mSpace[i] = obj.mSpace[i];
    }
}

template <class T>
int Array<T>::length()
{
    return mLength;
}

template <class T>
Array<T>::~Array()
{
    mLength = -1;
    cout<<mSpace<<endl;
    delete[] mSpace;
}


template <class T>
T& Array<T>::operator[](int i)
{
    return mSpace[i];
}

template <class T>
Array<T>& Array<T>::operator=(const Array<T>& obj)
{
    delete[] mSpace;
    mLength = obj.mLength;
    mSpace = new T[mLength];
    for (int i = 0; i < mLength; i++)
    {
        mSpace[i] = obj.mSpace[i];
    }
    return *this;
}


template <class T>
bool Array<T>::operator==(const Array<T>& obj)
{
    bool ret = true;
    if (mLength == obj.mLength)
    {
        for (int i = 0; i < mLength; i++)
        {
            if (mSpace[i]!=obj.mSpace[i])
            {
                ret = false;
                break;
            }
            
        }
    } else
    {
        ret = false;
    }
    
    return ret;
    

}

template <class T>
bool Array<T>::operator!=(const Array<T>& obj)
{
    return !(*this == obj);
}

int main()
{
    return 0;
}