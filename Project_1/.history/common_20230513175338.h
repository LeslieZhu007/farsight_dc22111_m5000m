
#ifndef _COMMON_H_
#define _COMMON_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sqlite3.h>
#include <sys/wait.h>
#include <signal.h>
#include <time.h>
#include <pthread.h>
#include <sys/stat.h>
#include <sqlite3.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <pthread.h>

#define STAFF_DATABASE 	 "staff_manage_system.db"
#define USRINFO_CREATE_SQL "CREATE TABLE usrinfo(staffno integer,usertype integer,name text,passwd text,age integer,phone text,addr text,work text,date text,level integer,salary REAL)"
#define HISTORYINFO_CREATE_SQL "CREATE TABLE historyinfo(time text,name text,words text)"
#define HISTORYINFO_INSERT_FORMAT "insert into historyinfo values(\"%s\",\"%s\",\"%s\")"
#define USER_CREATE_SQL "CREATE TABLE user (name TEXT,status INTEGER,PRIMARY KEY(`name`) )" 
#define USER_QUERY_SQL "select * from user where name = \"%s\""
#define USER_UPDATE_FORMAT "update user set status = %d where name = '%s'"
#define USRINFO_QUERY_SQL "select * from usrinfo where name = \"%s\""
#define USRINFO_UPDATE_SQL "update usrinfo set status = %d where name = '%s'"
#define HISTORYINFO_QUERY_FORMAT "select * from historyinfo where name = \"%s\""
#define USERINFO_UPDATE_FORMAT "update usrinfo set staffno =%d,\
												   usertype = %d,\
												   name = \"%s\",\
												   passwd = \"%s\",\
												   age = %d ,phone = \"%s\",addr = \"%s\",work = \"%s\",date = \"%s\",level = %d ,salary = %f where name = '%s'"


#define LOGIN_IN_FAIL "用户登录失败"
#define LOGIN_IN_SUCCESS "用户登录成功"
#define LOGIN_OUT_SUCCESS "用户登出成功"
#define LOGIN_IN_REPEAT "重复登录"
#define LOGIN_IN_STATUS_NOT_FOUND "找不到用户登录状态，用户登录失败"
#define LOGGED_IN 1
#define LOGGED_OFF 0

#define USER_LOGIN 		0x00000000  // login	登陆    0x00000001
#define USER_MODIFY 	0x00000001  // user-modification  修改
#define USER_QUERY 		0x00000002  // user-query   查询

#define ADMIN_LOGIN 	0x10000000  // login	登陆    0x00000001
#define ADMIN_MODIFY 	0x10000001 // admin_modification
#define ADMIN_ADDUSER 	0x10000002 // admin_adduser
#define ADMIN_DELUSER 	0x10000004 // admin_deluser
#define ADMIN_QUERY 	0x10000008  //hitory_query
#define ADMIN_HISTORY 	0x10000010  //hitory_query

#define QUIT 			0x11111111

#define ADMIN 0	//管理员
#define USER  1	//用户

#define NAMELEN 16
#define DATALEN 128


#define ERR_MSG(msg) do {\
    fprintf(stderr,"line: __%d__ ",__LINE__);\
    perror(msg);\
} while (0)

/*员工基本信息*/
typedef struct staff_info{
	int  staffno; 			//员工编号
	int  usertype;  	//ADMIN 1	USER 2	 
	char name[NAMELEN];	//姓名
	char passwd[8]; 	//密码
	int  age; 			// 年龄
	char phone[NAMELEN];//电话
	char addr[DATALEN]; // 地址
	char work[DATALEN]; //职位
	char date[DATALEN];	//入职年月
	int level;			// 等级
	double salary ;		// 工资
	
}staff_info_t;

/*定义双方通信的结构体信息*/
typedef struct {
	int  msgtype;     //请求的消息类型
	int  usertype;    //ADMIN 1	USER 2	   
	char username[NAMELEN];  //姓名
	char passwd[8];			 //登陆密码
	char recvmsg[DATALEN];   //通信的消息
	int  flags;      //标志位   1 成功  0 失败
	staff_info_t info;      //员工信息
}MSG;

//更新最大文件描述符
int updateMaxfd(int maxfd, fd_set readfds);

//获取当前系统时间
void get_system_time(char *time_buf);

//回收僵尸进程
void handler(int sig);

//管理员界面菜单
void print_admin_menu();

//普通用户界面菜单
void print_user_menu();

//客户端登录函数
int do_login(int sockfd);

//客户端处理请求函数
int process_client_request(int newfd,struct sockaddr_in cin);



#endif

