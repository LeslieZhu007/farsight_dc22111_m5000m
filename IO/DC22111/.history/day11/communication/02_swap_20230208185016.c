#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    
    //创建key值
    key_t key = ftok("/home/linux/",'a');
    if (key < 0)
    {
        perror("ftok");
        return -1;
    }
    printf("key = %#x\n",key);
    
    //创建共享内存
    int shmid =shmget(key,32,IPC_CREAT|0664);
    if (shmid < 0)
    {
        perror("shmget");
        return -1;
    }
    printf("shmid = %d\n",shmid);
    system("ipcs -m");

    //将共享内存映射到用户空间
    void* shmaddr = shmat(shmid,NULL,0);
    if ((void *)-1 == shmaddr)
    {
        perror("shmat");
        return -1;
    }
    
    int *p = (int *)shmaddr;
    char *str = (char *)(p+1);
    //交换
    char temp;
    char *front;
    char *end;
    while (1)
    {
        if (*p = 1)
        {
            front = str;
            end = str + strlen(str) -1;
            while (front <= end)
            {
                temp = *front;
                *front = *end;
                *end = temp;
            }
        }
        *p = 0;
        
    }
    
    

    return 0;
}
