#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>
#include <signal.h>

//定义消息报类型
struct msgbuf
{
    long mtype; //消息类型，必须 > 0
    char mtext[128]; //消息内容
};




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

    //消息队列创建
    int msqid = msgget(key,IPC_CREAT|0664);
    if (msqid < 0)
    {
        perror("msgget");
        return -1;
    }

    printf("msqid = %d\n",msqid);

    system("ipcs -q");

    //创建两个进程，一个进程往消息队列中发送数据，一个进程从队列中写数据
    pid_t cpid = fork();

    if(cpid > 0)
    {
        //父进程向msgtype为101的消息队列发送数据
        

    } else if(0==cpid)
    {
        //子进程向从msgtype为100的进程中读取数据
        struct msgbuf rcv;
        rcv.mtype = 100; //消息类型
        while (1)
        {
            memset(&rcv,0,sizeof(rcv));
            //从消息队列中读取数据
            //阻塞的方式，读取消息队列中的第一条消息
            if(msgrcv(msqid,&rcv,sizeof(rcv.mtext),0,0) < 0)
            //if( msgrcv(msqid,&rcv,sizeof(rcv.mtext),0,IPC_NOWAIT) < 0)
            {
                perror("msgrcv");
                return -1;
            }
            printf("A==读取到的消息内容:%s\n",rcv.mtext);
        }

    } else {
        perror("fork");
        return -1;
    }








    
    return 0;
}