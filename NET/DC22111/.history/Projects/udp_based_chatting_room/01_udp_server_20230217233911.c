#include "udpchat.h"

linklist list_create();
int list_insert_tail(linklist L,struct sockaddr_in e);
int list_delete_value(linklist L,struct sockaddr_in e);
//回收僵尸进程
void handler(int sig);



int main(int argc, char const *argv[])
{
    //捕获17号信号，注册新的处理函数，用于回收僵尸进程
    __sighandler_t s = signal(SIGCHLD,handler);
    if (SIG_ERR == s)
    {
        printf("signal");
        return -1;
    }


    //1.创建宝石套接字   socket
    int sfd = socket(AF_INET,SOCK_DGRAM,0);
    if (sfd < 0)
    {
        ERR_MSG("socket");
        return -1;
    }

    //服务器自身的地址信息结构体，真实的地址信息结构体根据AF_INET查找
    //man 7 ip
    struct sockaddr_in sin;
    sin.sin_family = AF_INET;
    sin.sin_port = htons(SERVER_PORT);
    sin.sin_addr.s_addr = inet_addr(SERVER_IP);
    //2.绑定服务器的地址信息结构体  bind
    if(bind(sfd,(struct sockaddr *)&sin,sizeof(sin)) < 0)
    {
        ERR_MSG("bind");
        return -1;
    }
    printf("udp server bind success\n");

    char buf[128] = {0};
    ssize_t ret = 0;

    struct sockaddr_in cin;
    socklen_t addrlen = sizeof(cin);

    protocol_t protocol;

    pid_t cpid;

    //申请地址链表
    linklist L = list_create();
    if (NULL == L)
    {
        ERR_MSG("linklist create failed\n");
    }
    linklist p = L->next;

    cpid = fork();
    if(cpid > 0)
    {
        //父进程接收客户端信息,同时转发
        // L 登录  1.遍历链表转发登录信息    2.将登录用户的地址信息结构体添加到链表中
        // C 聊天  1.遍历链表转发的聊天信息  2.不需要发给自己
        // Q 退出  1.遍历链表转发退出信息    2.删除退出的客户端节点
        while (1)
        {
            bzero(&protocol,sizeof(protocol));
            ret = recvfrom(sfd,&protocol,sizeof(protocol),0,(struct sockaddr *)&cin,&addrlen);

            switch (protocol.type)
            {
                case 'L':
                    printf("%s已登录...\n",protocol.name);
                    list_insert_tail(L,cin);
                    //将登录消息转发其他用户
                    p = L->next;
                    while (NULL!=p)
                    {
                        if (p->cin.sin_addr.s_addr!=cin.sin_addr.s_addr)
                        {
                            if(sendto(sfd,&protocol,sizeof(protocol),0,(struct sockaddr *)&(p->cin),sizeof(p->cin)) < 0)
                            {
                                fprintf(stderr,"%s login msg send fail\n",protocol.name);
                                return -1;
                            }
                            printf("%s login msg send success\n",protocol.name);
                        }
                        p=p->next;
                    }
                    break;
                case 'C':
                    //将聊天消息转发其他用户
                    p = L->next;
                    while (NULL!=p)
                    {
                        if (p->cin.sin_addr.s_addr!=cin.sin_addr.s_addr)
                        {
                            if(sendto(sfd,&protocol,sizeof(protocol),0,(struct sockaddr *)&(p->cin),sizeof(p->cin)) < 0)
                            {
                                fprintf(stderr,"%s msg send fail\n",protocol.name);
                                return -1;
                            }
                            printf("%s msg send success\n",protocol.name);
                        }
                        p=p->next;
                    }
                    break;
                case 'Q':
                    printf("%s已退出...\n",protocol.name);
                    //将退出消息转发其他用户
                    p = L->next;
                    while (NULL!=p)
                    {
                        if (p->cin.sin_addr.s_addr!=cin.sin_addr.s_addr)
                        {
                            if(sendto(sfd,&protocol,sizeof(protocol),0,(struct sockaddr *)&(p->cin),sizeof(p->cin)) < 0)
                            {
                                fprintf(stderr,"%s msg send fail\n",protocol.name);
                                return -1;
                            }
                            printf("%s msg send success\n",protocol.name);
                        } else
                        {
                            //删除节点
                            list_delete_value(L,cin);
                        }
                        p=p->next;
                    }
                    break;
                
                default:
                    break;
            }
        }

    } else if(cpid == 0)
    {
        //子进程发送系统信息
        while (1)
        {
            bzero(&protocol,sizeof(protocol));
            strcpy(protocol.name,"administrator");
            protocol.type = 'C';
            fgets(protocol.text,TEXT_LENGTH,stdin);
            protocol.text[strlen(protocol.text)-1] = 0;
            if(sendto(sfd,&protocol,sizeof(protocol),0,(struct sockaddr *)&cin,sizeof(cin)) < 0)
            {
                ERR_MSG("system msg send fail");
                return -1;
            }
            printf("system msg send success\n");
        }
    } else
    {
        ERR_MSG("fork");
        return -1;
    }

    //5.关闭套接字文件描述符
    close(sfd);
    return 0;
}


linklist list_create()
{
    linklist L = (linklist)malloc(sizeof(Node));
    if (NULL == L)
    {
        ERR_MSG("malloc");
        return NULL;
    }
    memset(&(L->cin),0,sizeof(L->cin));
    L->next = NULL;
    return L;
}

int list_insert_tail(linklist L,struct sockaddr_in e)
{
    if (NULL == L)
    {
        ERR_MSG("insert fail");
        return -1;
    }
    //遍历到链表尾部
    linklist p = L;
    while (NULL != p->next)
    {
        p = p->next;
    }
    //申请节点
    linklist q = (linklist)malloc(sizeof(Node));
    if (NULL == q)
    {
        ERR_MSG("node apply failed\n");
        return -1;
    }
    q->next = NULL;
    q->cin = e;
    //进行尾插
    q->next = p->next;
    p->next = q;
    printf("tail insert success\n");
    return 0;
}

int list_delete_value(linklist L,struct sockaddr_in e)
{
    if (NULL == L)
    {
        ERR_MSG("insert fail");
        return -1;
    }
    linklist p = L->next;
    //找到p的前驱节点
    while (NULL!=p->next)
    {
        if ((e.sin_addr.s_addr == p->cin.sin_addr.s_addr)&&(e.sin_port == p->cin.sin_port))
        {
            break;
        }
        p = p->next;
    }
    if (NULL==p->next)
    {
        printf("delete node failed\n");
        return -1;
    } 
    else
    {
        linklist q = p->next;
        p->next = q->next;
        free(q);
        printf("delete node success\n");
        return 0;
    }
    
}

void handler(int sig)
{
    while (waitpid(-1,NULL,WNOHANG)>0); //循环回收僵尸进程
}
