#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>

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
    int shmid =shmget(key,32,IPC_CREAT);
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
    
    printf("shmaddr = %p\n",shmaddr);
    system("ipcs -m");

    return 0;
}
