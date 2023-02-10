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
    
    printf("shmaddr = %p\n",shmaddr);
    system("ipcs -m");

    //先存储一个int类型
    int *p = (int *)shmaddr;
    *p = 15;

    //在整型后面存储一个字符串
    char *str = (char *)((int *)shmaddr + 1);
    memset(str,0,sizeof(str));
    strcpy(str,"hello world");

    //在字符串后存储一个short类型
    short *s1 = (short *)((char *)shmaddr + 4 + strlen(str) + 1);
    *s1 = 256;

    printf("str = %s\n",str);
    printf("*p = %d\n",*p);
    printf("*s1 = %d\n",*s1);

    return 0;
}
