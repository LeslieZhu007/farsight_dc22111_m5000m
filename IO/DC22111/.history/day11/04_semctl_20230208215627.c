#include <stdio.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <sys/types.h>
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

    //创建信号灯集,灯集中有两个信号灯，分别为0,1号灯
    int semid = semget(key,2,IPC_CREAT|0664);
    if (semid < 0)
    {
        perror("semget");
        return -1;
    }
    
    printf("semid = %d\n",semid);
    system("ipcs -s");

    //设置所有信号灯的值
    unsigned short setall[2] = {100,200};
    if (semctl(semid,100,SETALL,setall) < 0)
    {
        perror("semctl");
        return -1;
    }
    
   


    return 0;
}
