
#include "common.h"

sqlite3 *db = NULL;  //仅服务器使用
int port ;
char *ip;
int sockfd;


int process_user_or_admin_login_request(int acceptfd,MSG *msg)
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

}

int process_admin_history_request(int acceptfd,MSG *msg)
{
	printf("------------%s-----------%d.\n",__func__,__LINE__);

}


int process_client_quit_request(int acceptfd,MSG *msg)
{
	printf("------------%s-----------%d.\n",__func__,__LINE__);

}


int process_client_request(int acceptfd,MSG *msg)
{
	printf("------------%s-----------%d.\n",__func__,__LINE__);
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
	//判断命令行参数	
	if (argc < 3)
	{
		ERR_MSG("格式错误，正确格式 ./a.out IP PORT");
	}
	ip = atoi(argv[2]);
	strcpy(port, argv[1]);
	printf("server port = %s,ip = %d\n", port, ip);
	
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
	while(1){
		tempfds = readfds;
		retval =select(maxfd+1,&readfds,NULL,NULL,NULL);
		//判断是否是集合里关注的事件
		if(FD_ISSET(sockfd,&readfds)){
			//数据交互 
			acceptfd = accept(sockfd,(struct sockaddr *)&cin,&addrlen);
			printf("[%s | %d] acceptfd = %d 连接成功\n", \
                        inet_ntoa(cin.sin_addr), ntohs(cin.sin_port), acceptfd);
			if(acceptfd == -1){
				printf("acceptfd failed.\n");
				exit(-1);
			}					
		}else{
			recvbytes = recv();
			if(recvbytes == -1){
				printf("recv failed.\n");
				continue;
			}else if(recvbytes == 0){
				printf("peer shutdown.\n");
				close(i);
				FD_CLR(i, &readfds);  //删除集合中的i
			}else{
				process_client_request(i,&msg);
			}
		}
	}
	close(sockfd);

	return 0;
}
