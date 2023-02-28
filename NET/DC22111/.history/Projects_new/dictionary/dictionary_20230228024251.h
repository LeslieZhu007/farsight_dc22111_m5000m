#ifndef __DICTIONARY_H__
#define __DICTIONARY_H__

#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "string.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <sqlite3.h>
#include <sys/stat.h>
#include <fcntl.h>

#define PORT 8888
#define IP "192.168.8.249"
#define DB_NAME "dict.db"
#define WORD_SQL "create table if not exists dictionary (word char,meaning char);"
#define HISTORY_SQL "create table if not exists history (name char,word char,meaning char,time char);"
#define USER_SQL "create table if not exists user (name char primary key,passwd char,status);"
#define USER_INSERT_FORMAT "insert into user values(\"%s\",\"%s\",%d)"
#define USER_SELECT_FORMAT 
#define DICT_SELECT_SQL "select * from dictionary"
#define WORD_INSERT_FORMAT "insert into dictionary values(\"%s\",\"%s\");"
#define FILE_PATH_TEST "dict_test.txt"
#define FILE_PATH "dict.txt"
#define DICT_ROW 7987
#define DICT_TEST_ROW 64

#define ERR_MSG(msg) do {\
    fprintf(stderr,"line: __%d__ ",__LINE__);\
    perror(msg);\
} while (0)

//定义消息类型结构体，用于客户端向服务器发送消息
typedef struct _msg 
{
    char name[20];
    char passwd[20];
    char text[128];
    int status;  //用户登录状态 1.登录成功  0.退出
    int type;  //1.注册 2.登录 3.退出 4.查单词 5.查历史记录
} msg_t;


/*******************服务器部分所用函数**********************/
//获取当前系统时间
void get_system_time();

//接收及发送的函数
int deal_cli_inter(int newfd,struct sockaddr_in cin,sqlite3 *db);

//回收僵尸进程
void handler(int sig);

//数据库初始化，包括库，表的创建，以及数据的导入
void database_init(sqlite3 *db);

//数据库数据导入
int load_db(sqlite3 *db,char *filepath);

//服务器端注册
void do_server_register(int newfd, msg_t* msg, sqlite3 *db);

//服务器端登录
void do_server_login(int newfd,msg_t* msg,sqlite3 * db);

//服务器端退出
void do_server_exit(int newfd,msg_t* msg,sqlite3 * db);

//服务器查询单词
void do_server_word_query(int newfd,msg_t* msg,sqlite3 * db);

//服务器查询历史记录
void do_server_history_query(int newfd,msg_t* msg,sqlite3 * db);


/*******************客户端部分所用函数**********************/
//客户端处理 ctrl+c SIGINT信号的函数
void ctrlc_handler(int sig);

//客户端注册功能
void do_register(int cfd,msg_t* msg);

//客户端登录功能
void do_login(int cfd,msg_t* msg);

//客户端查单词
void do_query_word(int cfd,msg_t* msg);

//客户端查历史记录
void do_query_history(int cfd,msg_t* msg);

//客户端给服务器发送用户退出标识
void set_user_exit_status(int cfd,msg_t* msg);

//客户端打印一级菜单
void print_1st_level_menu();

//客户端打印二级菜单
void print_2nd_level_menu();



#endif