#include <stdio.h>
#define ARRAY_SIZE(buf) (sizeof(buf)/sizeof(buf[0]))

void select_sort(int arr[],int len)
{   
    for (int i = 0; i < len-1; i++)
    {
        /* code */
    }
    

}

int main(int argc, char const *argv[])
{
    int buf[9] = {3,6,5,9,7,1,8,2,4};
    select_sort(buf,ARRAY_SIZE(buf));



    return 0;
}
