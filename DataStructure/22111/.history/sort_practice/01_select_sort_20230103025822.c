#include <stdio.h>
#define ARRAY_SIZE(buf) (sizeof(buf)/sizeof(buf[0]))

void swap(int a,int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void select_sort(int *buf,int max)
{   
    for (int i = 0; i < max; i++)
    {
        for (int j = i; j < max; j++)
        {
            if (buf[i] > buf[j])
            {
                swap();
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int buf[9] = {3,6,5,9,7,1,8,2,4};
    select_sort(buf,ARRAY_SIZE(buf));



    return 0;
}
