#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>

//定义消息报类型
struct msgbuf
{
    long mtype; //消息类型，必须 > 0
    char mtext[128]; //
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

    struct msgbuf snd;
    snd.mtype = 100; //消息类型

    while (1)
    {
        memset(&snd,0,sizeof(snd));
        //从终端获取消息类型
        printf("请输入消息类型>>>");
        scanf("%ld",&snd.mtype);

        getchar(); //吸收垃圾字符

        if (0 == snd.mtype)
        {
            break;
        }
        

        //从终端获取消息内容
        printf("清输入消息内容>>>");
        fgets(snd.mtext,sizeof(snd.mtext),stdin);
        snd.mtext[strlen(snd.mtext)-1] = 0;

        if (strcasecmp(snd.mtext,"quit")==0)
        {
            break;
        }
        

        //向消息队列中发送数据
        if( msgsnd(msqid,&snd,sizeof(snd.mtext),0) < 0)
        {
            perror("msgsnd");
            return -1;
        }

        }
    
    
    

    return 0;
}
