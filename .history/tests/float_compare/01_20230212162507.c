#include <stdio.h>
typedef enum _bool
{
    FALSE = 0,
    TRUE = -1
} BOOL;

#define E 0.0000001

int main(int argc, char const *argv[])
{
    
    BOOL b = TRUE;
    int i = 0;
    float f = 5.0;

    if (5.0 == f)
    {
        printf("OK");
    } else
    {
        printf("ERROR");
    }
    





    return 0;
}
