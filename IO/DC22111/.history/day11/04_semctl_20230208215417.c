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

    //wait for zero操作
    struct sembuf sops[2];
    //wait for zero操作
    // sops[1].sem_num = 0; //操作0号灯
    // sops[1].sem_op = -1; //v操作-1
    // sops[1].sem_flg = 0 ;// 阻塞方式运行

    sops[0].sem_num = 0; //操作1号灯
    sops[0].sem_op = 0; //wait for zero操作
    sops[0].sem_flg = 0 ;// 阻塞方式运行
    if(semop(semid,sops,1)<0) //控制2个灯
    {
        perror("semop");
        return -1;
    }
    printf("wait for zero operation success __%d__\n",__LINE__);

    //删除信号灯集
    if (semctl(semid,0,IPC_RMID) < 0)
    {
        perror("semctl");
        return -1;
    }

    printf("信号灯集删除成功\n");
    system("ipcs -s");
    


    return 0;
}
