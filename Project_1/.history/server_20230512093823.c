
#include "common.h"

sqlite3 *db = NULL;  //仅服务器使用
int port ;
char ip[128]={0};
int sockfd;
char buf[128] = "";

int process_user_or_admin_login_request(int acceptfd,MSG *msg)
{
	printf("------------%s-----------%d.\n",__func__,__LINE__);
	//封装sql命令，表中查询用户名和密码－存在－登录成功－发送响应－失败－发送失败响应	
	char sql[DATALEN] = {0};
	char *errmsg;
	char **result;
	int nrow,ncolumn;

	
	sprintf(sql,USRINFO_QUERY_SQL,msg->username);
	if(sqlite3_get_table(db,sql,&result,&nrow,&ncolumn,&errmsg) != SQLITE_OK){
		printf("---****----%s.\n",errmsg);		
	}else{
		//printf("----nrow-----%d,ncolumn-----%d.\n",nrow,ncolumn);		
		if(nrow == 0){
			msg->flags = 0; //查询失败
			send(acceptfd,msg,sizeof(MSG),0);
		}else{
			msg->flags = 1; //查询成功
			printf("server user info query row = %d,column =%d\n",nrow,ncolumn);

			int count = 0;
			//row中不包含表头的一行，但是结果中有表头的内容，所以需要将表头的一行加上
			for (int i = 0; i < nrow+1; i++)
			{
				for (int j = 0; j < ncolumn; j++)
				{
					if(i>0)
					{
						if (j>0)
						{
							bzero(msg->recvmsg,sizeof(msg->recvmsg));
							sprintf(msg->recvmsg,"%s\t",result[count]);
							//发送给客户端
							ssize_t sret = send(acceptfd,msg,sizeof(MSG),0);
							if (sret<0)
							{
								ERR_MSG("server do_server_history_query send");
								return -1;
							}
						}
					}
					count++;
				}
				if(i > 0)
				{
					bzero(msg->recvmsg,sizeof(msg->recvmsg));
					strcpy(msg->recvmsg,"\n");
					//发送给客户端
					ssize_t sret = send(acceptfd,msg,sizeof(MSG),0);
					if (sret<0)
					{
						ERR_MSG("server do_server_history_query send");
						return -1;
					}
				}
				
			}
			//发送结束标识给客户端
			strcpy(msg->recvmsg,"**OVER**\n");
			//发送给客户端
			ssize_t sret = send(acceptfd,msg,sizeof(MSG),0);
			if (sret<0)
			{
				ERR_MSG("server do_server_history_query send");
				return -1;
			}
		}
	}
	return 0;	
}

int process_user_modify_request(int acceptfd,MSG *msg)
{
	printf("------------%s-----------%d.\n",__func__,__LINE__);

}



int process_user_query_request(int acceptfd,MSG *msg)
{
	printf("------------%s-----------%d.\n",__func__,__LINE__);

}


int process_admin_modify_request(int acceptfd,MSG *msg)
{
	printf("------------%s-----------%d.\n",__func__,__LINE__);

}


int process_admin_adduser_request(int acceptfd,MSG *msg)
{
	printf("------------%s-----------%d.\n",__func__,__LINE__);

}



int process_admin_deluser_request(int acceptfd,MSG *msg)
{
	printf("------------%s-----------%d.\n",__func__,__LINE__);

}


int process_admin_query_request(int acceptfd,MSG *msg)
{
	printf("------------%s-----------%d.\n",__func__,__LINE__);
	//封装sql命令，表中查询用户名和密码－存在－登录成功－发送响应－失败－发送失败响应	
	char sql[DATALEN] = {0};
	char *errmsg;
	char **result;
	int nrow,ncolumn;

	msg->info.usertype =  msg->usertype;
	strcpy(msg->info.name,msg->username);
	strcpy(msg->info.passwd,msg->passwd);
	
	printf("usrtype: %#x-----usrname: %s---passwd: %s.\n",msg->info.usertype,msg->info.name,msg->info.passwd);
	sprintf(sql,"select * from usrinfo where usertype=%d and name='%s' and passwd='%s';",msg->info.usertype,msg->info.name,msg->info.passwd);
	if(sqlite3_get_table(db,sql,&result,&nrow,&ncolumn,&errmsg) != SQLITE_OK){
		printf("---****----%s.\n",errmsg);		
	}else{
		//printf("----nrow-----%d,ncolumn-----%d.\n",nrow,ncolumn);		
		if(nrow == 0){
			strcpy(msg->recvmsg,"name or passwd failed.\n");
			send(acceptfd,msg,sizeof(MSG),0);
		}else{
			strcpy(msg->recvmsg,"OK");
			send(acceptfd,msg,sizeof(MSG),0);
		}
	}
	return 0;	

}

int process_admin_history_request(int acceptfd,MSG *msg)
{
	printf("------------%s-----------%d.\n",__func__,__LINE__);

}


int process_client_quit_request(int acceptfd,MSG *msg)
{
	printf("------------%s-----------%d.\n",__func__,__LINE__);

}


int process_client_request(int acceptfd,struct sockaddr_in cin)
{
	printf("------------%s-----------%d.\n",__func__,__LINE__);
	//通过文件描述符，读取数据
    //原型 ssize_t recv(int sockfd, void *buf, size_t len, int flags);
	switch (msg->msgtype)
	{
		case USER_LOGIN:
		case ADMIN_LOGIN:
			process_user_or_admin_login_request(acceptfd,msg);
			break;
		case USER_MODIFY:
			process_user_modify_request(acceptfd,msg);
			break;
		case USER_QUERY:
			process_user_query_request(acceptfd,msg);
			break;
		case ADMIN_MODIFY:
			process_admin_modify_request(acceptfd,msg);
			break;

		case ADMIN_ADDUSER:
			process_admin_adduser_request(acceptfd,msg);
			break;

		case ADMIN_DELUSER:
			process_admin_deluser_request(acceptfd,msg);
			break;
		case ADMIN_QUERY:
			process_admin_query_request(acceptfd,msg);
			break;
		case ADMIN_HISTORY:
			process_admin_history_request(acceptfd,msg);
			break;
		case QUIT:
			process_client_quit_request(acceptfd,msg);
			break;
		default:
			break;
	}

}


int main(int argc, const char *argv[])
{
	printf("%s %s %s\n",argv[0],argv[1],argv[2]); 
	//判断命令行参数	
	if (argc < 3)
	{
		ERR_MSG("格式错误，正确格式 ./a.out IP PORT");
		return -1;
	}
	port = atoi(argv[2]);
	strcpy(ip, argv[1]);
	printf("server ip = %s,port = %d\n", ip, port);
	
	//打开数据库  ==> 创建数据库，建表
	if(sqlite3_open(STAFF_DATABASE,&db) != SQLITE_OK){
		printf("%s.\n",sqlite3_errmsg(db));
	}else{
		printf("the database open success.\n");
	}

	//执行数据库操作
	char *errmsg = NULL;
	if(sqlite3_exec(db,USRINFO_CREATE_SQL,NULL,NULL,&errmsg)!= SQLITE_OK){
		printf("%s.\n",errmsg);
	}else{
		printf("create usrinfo table success.\n");
	}
	if(sqlite3_exec(db,HISTORYINFO_CREATE_SQL,NULL,NULL,&errmsg)!= SQLITE_OK){
		printf("%s.\n",errmsg);
	}else{
		printf("create historyinfo table success.\n");
	}
	
	//socket->填充->绑定->监听->等待连接->数据交互->关闭

	//创建网络通信的套接字
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd == -1){
		perror("socket failed.\n");
		exit(-1);
	}
	
	//填充网络结构体	
	struct sockaddr_in sin;
	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = inet_addr(ip);
	sin.sin_port = htons(port);

	//绑定网络套接字和网络结构体

	if(bind(sockfd,(struct sockaddr *)&sin,sizeof(sin)) == -1){
		printf("bind failed.\n");
		exit(-1);
	}

	//监听套接字，将主动套接字转化为被动套接字
	if(listen(sockfd,10) == -1){
		printf("listen failed.\n");
		exit(-1);
	}

	/*通过父子进程实现并发支持*/
	struct sockaddr_in cin; 
	socklen_t addrlen = sizeof(cin);
	int newfd = 0;
    int cpid = 0;
    while (1)
    {
        //父进程只负责连接
        newfd =  accept(sockfd,(struct sockaddr *)&cin,&addrlen);
        if (newfd < 0)
        {
            ERR_MSG("accept");
            return -1;
        }
        printf("[%s | %d] newfd = %d\n",inet_ntoa(cin.sin_addr),ntohs(cin.sin_port),newfd);


        cpid = fork();
        if (0==cpid)
        {
            close(sockfd);  //sfd对于子进程没有用
            //与客户端交互的代码

            process_client_request(newfd,&cin);

            //退出子进程
            exit(0);
        } else if(cpid > 0)
        {
            close(newfd);  //newfd对于父进程没有用
        }
    }

    close(sockfd);


/*
	//通过select实现并发
	int retval;
	ssize_t recvbytes;
	//设置一个读集合
    fd_set readfds, tempfds;
	//清空
    FD_ZERO(&readfds);
	//将需要监控的文件描述符加入到集合中
	FD_SET(sockfd,&readfds);
	int maxfd = sockfd;
	//存储客户端信息
	struct sockaddr_in saveCin[1024-4];     //0,1,2,sfd不会有对应的客户端，所以-4
	struct sockaddr_in cin; 
	socklen_t addrlen = sizeof(cin);
	int acceptfd = 0;
	MSG msg;
	while(1){
		tempfds = readfds;
		retval =select(maxfd+1,&readfds,NULL,NULL,NULL);
		if(retval < 0)
        {
            ERR_MSG("select");
            return -1;
        }
        else if(0 == retval)
        {
            printf("time out ....\n");
            break;
        }
		//能运行到当前位置，则代表集合中有文件描述符准备就绪
        //判断哪个文件描述符准备就绪，走对应的函数 
        //select函数解除阻塞后，集合中会只剩下产生事件的文件描述符
        //例如：0产生事件，则只剩下0
        //         sfd产生事件，则只剩下sfd
        //         0、sfd产生事件，则剩下 0， sfd 
        //判断集合中剩下哪个文件描述符，走对应函数即可。
		//判断是否是集合里关注的事件
		for(int i=0; i<=maxfd; i++)
        {
			if(FD_ISSET(i, &tempfds) == 0)
            {
                continue;
            }
			//能运行到这个位置，则说明i代表的文件描述符在tempfds中。
        	//即i代表的文件描述符触发事件

			if(sockfd == i){
				//数据交互 
				acceptfd = accept(sockfd,(struct sockaddr *)&cin,&addrlen);
				if(acceptfd == -1){
					printf("acceptfd failed.\n");
					exit(-1);
				}	
				printf("[%s | %d] acceptfd = %d 连接成功\n", \
							inet_ntoa(cin.sin_addr), ntohs(cin.sin_port), acceptfd);
				saveCin[acceptfd-4] = cin;	
				//将acceptfd添加到读集合中
                FD_SET(acceptfd, &readfds);
				//更新maxfd，判断acceptfd和maxfd谁大，则最终maxfd就等于谁
                maxfd = maxfd>acceptfd ? maxfd:acceptfd;
			}else{
				//客户端交互事件
				//接收
				bzero(buf, sizeof(buf));
				recvbytes = recv(i,buf,sizeof(buf),0);
				if(recvbytes == -1){
					printf("recv failed.\n");
					continue;
				}else if(recvbytes == 0){
					printf("[%s | %d] acceptfd=%d 客户端断开连接\n", 
                            inet_ntoa(saveCin[i-4].sin_addr), ntohs(saveCin[i-4].sin_port), i);
					close(i);
					FD_CLR(i, &readfds);  //删除集合中的i
					//更新maxfd 
                    maxfd = updateMaxfd(maxfd, readfds);
				}else{
					printf("[%s | %d] newfd=%d connect success\n", \
                            inet_ntoa(saveCin[i-4].sin_addr), ntohs(saveCin[i-4].sin_port), i);
					process_client_request(i,&msg);
				}
			}



		}
		

		
	}

	close(sockfd);
	*/

	return 0;
}
int updateMaxfd(int maxfd, fd_set readfds)
{
    for(int i=maxfd; i>0;i--)
    {
        if(FD_ISSET(i, &readfds))
            return i;
    }
    return -1;
}