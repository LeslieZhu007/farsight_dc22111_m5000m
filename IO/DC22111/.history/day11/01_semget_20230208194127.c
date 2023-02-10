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

    //创建信号灯集
    int semid = semget(key,2,IPC_CREAT|0664);
    if (semid < 0)
    {
        perror("semget");
        return -1;
    }
    
    printf("semid = %d\n",semid);
    system("ipcs -s");

    //P操作
    struct sembuf sops;
    //P操作
    sops.sem_num = 0; //操作0号灯
    sops.sem_op = -1; //p操作-1
    sops.sem_flg = 0 ;// 阻塞方式运行
    if(semop(semid,&sops,1)<0)
    {
        perror("semop");
        return -1;
    }
    printf("P operation success __%d__\n",__LINE__);
    return 0;
}
