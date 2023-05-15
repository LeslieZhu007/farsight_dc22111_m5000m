
#include "common.h"

int cfd = 0;
int port ;
char ip[128]={0};
char name[20] = {0}; //保存当前用户名，每一个实例只对应一个用户名
/*
#define USER_LOGIN 		0x00000000  // login	登陆    0x00000001
#define USER_MODIFY 	0x00000001  // user-modification  修改
#define USER_QUERY 		0x00000002  // user-query   查询

#define ADMIN_LOGIN 	0x10000000  // login	登陆    0x00000001
#define ADMIN_MODIFY 	0x10000001 // admin_modification
#define ADMIN_ADDUSER 	0x10000002 // admin_adduser
#define ADMIN_DELUSER 	0x10000004 // admin_deluser
#define ADMIN_QUERY 	0x10000008  //hitory_query
#define ADMIN_HISTORY 	0x10000010  //hitory_query
*/

/**************************************
 *函数名：do_query
 *参   数：消息结构体
 *功   能：登陆
 ****************************************/
void do_admin_query(int sockfd,MSG *msg)
{
	//1.设置发送参数
	msg->msgtype = ADMIN_QUERY;
	printf("请输入要查询的员工姓名>>>");
	fscanf(stdin,"%s",msg->username);
    while (getchar()!=10);

	//2.发送查询请求给服务器
	send(sockfd, msg, sizeof(MSG), 0);
	//3.循环接受服务器响应
	while (1)
    {
        ssize_t rret = recv(sockfd, msg, sizeof(MSG), 0);
        if (rret<0)
        {
            ERR_MSG("client do_login recv");
            return;
        }
        printf("%s",msg->recvmsg);
        if (0==strcmp("**OVER**\n",msg->recvmsg))
        {
            break;
        }
    }


}

/**************************************
 *函数名：admin_modification
 *参   数：消息结构体
 *功   能：管理员修改
 ****************************************/
void do_admin_modification(int sockfd,MSG *msg)//管理员修改
{
	printf("------------%s-----------%d.\n",__func__,__LINE__);


}

/**************************************
 *函数名：admin_adduser
 *参   数：消息结构体
 *功   能：管理员创建用户
 ****************************************/
void do_admin_adduser(int sockfd,MSG *msg)//管理员添加用户
{		
	printf("------------%s-----------%d.\n",__func__,__LINE__);
}

/**************************************
 *函数名：admin_deluser
 *参   数：消息结构体
 *功   能：管理员删除用户
 ****************************************/
void do_admin_deluser(int sockfd,MSG *msg)//管理员删除用户
{
	printf("------------%s-----------%d.\n",__func__,__LINE__);

}

/**************************************
 *函数名：do_history
 *参   数：消息结构体
 *功   能：查看历史记录
 ****************************************/
void do_admin_history (int sockfd,MSG *msg)
{
	printf("------------%s-----------%d.\n",__func__,__LINE__);
	//1.设置发送参数
	msg->msgtype = ADMIN_HISTORY;
	printf("请输入要查询的员工姓名>>>");
	fscanf(stdin,"%s",msg->username);
    while (getchar()!=10);

	//2.发送查询请求给服务器
	send(sockfd, msg, sizeof(MSG), 0);
	//3.循环接受服务器响应
	while (1)
    {
        ssize_t rret = recv(sockfd, msg, sizeof(MSG), 0);
        if (rret<0)
        {
            ERR_MSG("client do_login recv");
            return;
        }
        printf("%s",msg->recvmsg);
        if (0==strcmp("**OVER**\n",msg->recvmsg))
        {
            break;
        }
    }
}

/**************************************
 *函数名：admin_menu
 *参   数：套接字、消息结构体
 *功   能：管理员菜单
 ****************************************/
void admin_menu(int sockfd,MSG *msg)
{
	char choose = 0;
	while (1)
	{
		print_admin_menu();
		choose = getchar();
		while (getchar()!=10);
		switch (choose)
        {
            case '4':
			do_admin_query(sockfd,msg);
			break;
			case '5':
			do_admin_history(sockfd,msg);
			break;
			case '6':
			//发送退出信号
			do_login(sockfd);
			break;
            default:
                printf("输入错误，请重新输入\n");
        }
        //请按任意键清屏
        printf("请按任意键清屏\n");
        while (getchar()!=10);
        system("clear");
    }
}

/**************************************
 *函数名：do_query
 *参   数：消息结构体
 *功   能：登陆
 ****************************************/
void do_user_query(int sockfd,MSG *msg)
{
	printf("------------%s-----------%d.\n",__func__,__LINE__);
	//1.设置发送参数
	msg->msgtype = USER_QUERY;
	printf("请输入要查询的员工姓名(注意:只能查询自己的用户名)>>>");
	fscanf(stdin,"%s",msg->username);
    while (getchar()!=10);
	if(0!=strcmp(msg->username,name))
	{
		printf("不允许查询非本人的信息!!\n");
		return;
	}
	//2.发送查询请求给服务器
	send(sockfd, msg, sizeof(MSG), 0);
	//3.循环接受服务器响应
	while (1)
    {
        ssize_t rret = recv(sockfd, msg, sizeof(MSG), 0);
        if (rret<0)
        {
            ERR_MSG("client do_login recv");
            return;
        }
        printf("%s",msg->recvmsg);
        if (0==strcmp("**OVER**\n",msg->recvmsg))
        {
            break;
        }
    }
}

/**************************************
 *函数名：do_modification
 *参   数：消息结构体
 *功   能：修改
 ****************************************/
void do_user_modification(int sockfd,MSG *msg)
{
	printf("------------%s-----------%d.\n",__func__,__LINE__);
	//1.设置发送参数
	msg->msgtype = USER_MODIFY;
	printf("请输入要修改信息的员工姓名(注意:只能修改自己的用户名的相关信息)>>>");
	fscanf(stdin,"%s",msg->username);
    while (getchar()!=10);
	if(0!=strcmp(msg->username,name))
	{
		printf("不允许修改非本人的信息!!\n");
		return;
	}
	//2.发送查询请求给服务器
	//构造查询条件
	printf("用户admin的信息如下所示:\n");
	//查询用户信息，但凡用户输入信息的，以用户输入信息为准
	//用户未输入信息的，以查询到的用户信息为准
	/***********查询用户信息begin************/
	//1.设置发送参数
	MSG *msg1;
	msg1->msgtype = USER_QUERY;
	strcpy(msg1->username,msg->username);
	//2.发送查询请求给服务器
	send(sockfd, msg1, sizeof(MSG), 0);
	//3.循环接受服务器响应
	char *ret[20] = {0};
	int i = 0;
	while (1)
    {
        ssize_t rret = recv(sockfd, msg, sizeof(MSG), 0);
        if (rret<0)
        {
            ERR_MSG("client do_login recv");
            return;
        }
        printf("%s",msg->recvmsg);
		strcpy(ret[i],msg->recvmsg);
		i++;
        if (0==strcmp("**OVER**\n",msg->recvmsg))
        {
            break;
        }
    }
	for (int i = 0; i < 20; i++)
	{
		printf("ret[%d] = %s\n",i,ret[i]);
	}
	printf("请参照用户信息填入更新的信息,注意，每项必填，\
	若无更新,请填写与原先相同内容.\n");
	memset(&(msg->info), 0, sizeof(msg->info));
	printf("请输入姓名>>>");
	fscanf(stdin,"%s",msg->info.name);
    while (getchar()!=10);
	if (0==strcmp(msg->info.name,""))
	{
		printf("名字不能为空\n");
		return ;
	}
	
	printf("请输入员工编号>>>");
	fscanf(stdin,"%d",msg->info.staffno);
    while (getchar()!=10);
	if (0==msg->info.staffno)
	{
		printf("员工编号不能为空\n");
		return ;
	}

	printf("请输入员工类型,1 ADMIN  0 USER>>>");
	fscanf(stdin,"%d",msg->info.usertype);
    while (getchar()!=10);
	if (0==msg->info.usertype)
	{
		printf("员工类型不能为空\n");
		return ;
	}


	printf("请输入密码>>>");
	fscanf(stdin,"%s",msg->info.passwd);
    while (getchar()!=10);
	if (0==strcmp(msg->info.passwd,""))
	{
		printf("密码不能为空\n");
		return ;
	}

	printf("请输入年龄>>>");
	fscanf(stdin,"%d",msg->info.age);
    while (getchar()!=10);
	if (0==msg->info.age)
	{
		printf("员工年龄不能为空\n");
		return ;
	}

	printf("请输入电话>>>");
	fscanf(stdin,"%s",msg->info.phone);
    while (getchar()!=10);
	if (0==strcmp(msg->info.phone,""))
	{
		printf("电话不能为空\n");
		return ;
	}

	printf("请输入地址>>>");
	fscanf(stdin,"%s",msg->info.addr);
    while (getchar()!=10);
	if (0==strcmp(msg->info.addr,""))
	{
		printf("地址不能为空\n");
		return ;
	}

	printf("请输入职位>>>");
	fscanf(stdin,"%s",msg->info.work);
    while (getchar()!=10);
	if (0==strcmp(msg->info.work,""))
	{
		printf("职位不能为空\n");
		return ;
	}

	printf("请输入入职年月>>>");
	fscanf(stdin,"%s",msg->info.date);
    while (getchar()!=10);
	if (0==strcmp(msg->info.date,""))
	{
		printf("入职年月不能为空\n");
		return ;
	}

	printf("请输入等级>>>");
	fscanf(stdin,"%d",msg->info.level);
    while (getchar()!=10);
	if (0==msg->info.level)
	{
		printf("等级不能为空\n");
		return ;
	}

	printf("请输入工资>>>");
	fscanf(stdin,"%f",msg->info.salary);
    while (getchar()!=10);
	if (0==(int)(msg->info.salary))
	{
		printf("工资不能为空\n");
		return ;
	}


	/***********查询用户信息end************/
	send(sockfd, msg, sizeof(MSG), 0);
	//3.接受服务器响应
	
	ssize_t rret = recv(sockfd, msg, sizeof(MSG), 0);
	if (rret<0)
	{
		ERR_MSG("client do_login recv");
		return;
	}
	printf("%s",msg->recvmsg);
}

/**************************************
 *函数名：user_menu
 *参   数：消息结构体
 *功   能：管理员菜单
 ****************************************/
void user_menu(int sockfd,MSG *msg)
{
	printf("------------%s-----------%d.\n",__func__,__LINE__);
	char choose = 0;
	while (1)
	{
		print_user_menu();
		choose = getchar();
		while (getchar()!=10);
		switch (choose)
        {
            case '1':
			do_user_modification(sockfd,msg);
			break;
			case '2':
			do_user_query(sockfd,msg);
			break;
			case '3':
			//发送退出信号

			//返回上一级
			do_login(sockfd);
			break;
            default:
                printf("输入错误，请重新输入\n");
        }
        //请按任意键清屏
        printf("请按任意键清屏\n");
        while (getchar()!=10);
        system("clear");
    }
}

int admin_or_user_login(int sockfd,MSG *msg)
{
	printf("------------%s-----------%d.\n",__func__,__LINE__);
	//输入用户名和密码
	memset(msg->username, 0, NAMELEN);
	printf("请输入用户名：");
	scanf("%s",msg->username);
	getchar();

	memset(msg->passwd, 0, DATALEN);
	printf("请输入密码（6位）");
	scanf("%s",msg->passwd);
	getchar();
	strcpy(name,msg->username);//只要用户登陆过就将用户名保存到全局变量
	//发送登陆请求
	send(sockfd, msg, sizeof(MSG), 0);
	//接受服务器响应
	recv(sockfd, msg, sizeof(MSG), 0);
	printf("msg->recvmsg :%s\n",msg->recvmsg);

	//判断是否登陆成功
	if(strncmp(msg->recvmsg, "OK", 2) == 0)
	{
		
		if(msg->usertype == ADMIN)
		{
			printf("亲爱的管理员，欢迎您登陆员工管理系统！\n");
			admin_menu(sockfd,msg);
		}
		else if(msg->usertype == USER)
		{
			printf("亲爱的用户，欢迎您登陆员工管理系统！\n");
			user_menu(sockfd,msg);
		}
	}
	else
	{
		printf("登陆失败！%s\n", msg->recvmsg);
		return -1;
	}

	return 0;
}


/************************************************
 *函数名：do_login
 *参   数：套接字、消息结构体
 *返回值：是否登陆成功
 *功   能：登陆
 *************************************************/
int do_login(int sockfd)
{	
	int n;
	MSG msg;

	while(1){
		printf("*************************************************************\n");
		printf("********  1：管理员模式    2：普通用户模式    3：退出********\n");
		printf("*************************************************************\n");
		printf("请输入您的选择（数字）>>");
		scanf("%d",&n);
		getchar();

		switch(n)
		{
			case 1:
				msg.msgtype  = ADMIN_LOGIN;
				msg.usertype = ADMIN;
				break;
			case 2:
				msg.msgtype =  USER_LOGIN;
				msg.usertype = USER;
				break;
			case 3:
				msg.msgtype = QUIT;
				if(send(sockfd, &msg, sizeof(MSG), 0)<0)
				{
					perror("do_login send");
					return -1;
				}
				close(sockfd);
				exit(0);
			default:
				printf("您的输入有误，请重新输入\n"); 
		}

		admin_or_user_login(sockfd,&msg);
	}

}

int main(int argc, const char *argv[])
{

	/**********连接服务器部分 begin***************************/
	//socket->填充->绑定->监听->等待连接->数据交互->关闭 
	//判断命令行参数	
	if (argc < 3)
	{
		ERR_MSG("格式错误，正确格式 ./a.out IP PORT");
		return -1;
	}
	port = atoi(argv[2]);
	strcpy(ip, argv[1]);
	printf("server ip = %s,port = %d\n", ip, port);

	//创建网络通信的套接字
	cfd = socket(AF_INET,SOCK_STREAM,0);
    if (cfd < 0)
    {
        ERR_MSG("socket");
        return -1;
    }
	//填充网络结构体
	struct sockaddr_in sin;
    sin.sin_family = AF_INET; //必须填AF_INET
    sin.sin_port = htons(port); //服务器绑定的端口号
    sin.sin_addr.s_addr = inet_addr(ip); //服务器绑定的IP

	//连接服务器
	if(connect(cfd,(struct sockaddr *)&sin,sizeof(sin)) == -1){
		perror("connect failed.\n");
		exit(-1);
	}
	/*******************连接服务器部分 end***************************/
	do_login(cfd);

	close(cfd);

	return 0;
}


//管理员界面菜单
void print_admin_menu()
{
    printf(".................1.修改.......................\n");
    printf(".................2.添加用户.......................\n");
    printf(".................3.删除用户...........................\n");
	printf(".................4.查询...........................\n");
	printf(".................5.历史记录查询...........................\n");
	printf(".................6.返回上一级...........................\n");
    printf("请输入你的选择>>");

}

//普通用户界面菜单
void print_user_menu()
{
	printf(".................1.修改.......................\n");
	printf(".................2.查询...........................\n");
	printf(".................3.返回上一级...........................\n");
}


