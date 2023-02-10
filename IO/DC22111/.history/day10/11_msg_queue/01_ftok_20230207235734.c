#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>


int main(int argc, char const *argv[])
{
    //计算Key
    key_t key = ftok("/home/linux/",1);
    if (key < 0)
    {
        perror("ftok");
        return -1;
    }
    
    printf("key = %#x\n",key);

    return 0;
}
