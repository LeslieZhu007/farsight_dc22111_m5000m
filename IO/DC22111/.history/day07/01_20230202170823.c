#include <stdio.h>

int main(int argc, char const *argv[])
{
    
    pid_t pid;
    int i = 0;
    while(i < 2)
    {
        fork();
        i++;
    }
    return 0;
}
