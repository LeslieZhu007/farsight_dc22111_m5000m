#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>

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
    

    return 0;
}
