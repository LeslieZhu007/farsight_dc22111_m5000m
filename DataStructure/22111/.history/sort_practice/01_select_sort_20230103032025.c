#include <stdio.h>
#define ARRAY_SIZE(buf) (sizeof(buf)/sizeof(buf[0]))
void show(int *buf,int max)
{
    for (int i = 0; i < max; i++)
    {
        printf("%d\t",buf[i]);
    }
    printf("\n");
}
void swap(int *a,int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void select_sort(int *buf,int max)
{   
    for (int i = 0; i < max; i++)
    {
        for (int j = i; j < max; j++)
        {
            if (buf[i] > buf[j])
            {
                swap(&buf[i],&buf[j]);
            }
        }
    }
}

void select_sort_improve(int *buf,int max)
{   
    for (int i = 0; i < max; i++)
    {
        int min = i;
        for (int j = i; j < max; j++)
        {
            if (buf[min] > buf[j])
            {
                min = j;
            }
        }
        if (buf[i] > buf[min])
        {
            swap(&buf[i],&buf[min]);
        }
    }
}



void bubble_sort(int *buf,int max)
{
    for (int i = 0; i < max-1; i++)
    {
        for (int j = 0; j < max-i-1; j++)
        {
            if (buf[j] > buf[j+1])
            {
                swap(&buf[j],&buf[j+1]);
            }
            
        }
        
    }
    
}



int main(int argc, char const *argv[])
{
    int buf[9] = {3,6,5,9,7,1,8,2,4};
    //select_sort_improve(buf,ARRAY_SIZE(buf));
    bubble_sort(buf,ARRAY_SIZE(buf));
    show(buf,ARRAY_SIZE(buf));
    return 0;
}
