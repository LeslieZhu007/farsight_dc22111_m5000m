#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
	pid_t pid;

	pid = fork();

	if(pid < 0)
	{
		perror("fork error");
		exit(1);
	}
	else if(pid > 0)
	{
		printf("父进程正在执行\n");

		wait(NULL);

	}

	else
	{

		//exec函数族的使用

		//**********执行shell命令************
		//不带p的函数执行shell命令第一个参数必须是绝对路径
		//使用whereis可以查看这个命令的绝对路径
		//if(execl("/bin/ls","ls","-l",NULL) == -1);
		//带p的函数执行shell命令
		puts("=============================");
		//if(execlp("ls","ls","-l",NULL) == -1);
		//带v的函数第二个参数是一个指针数组

		//char *buf[] = {"ls","-l",NULL};
		//if(execvp("ls",buf) == -1);

		puts("*****************************");

		//**********执行shell脚本************
	//	if(execlp("bash","bash","myshell.sh",NULL) == -1);


		//**********执行C程序************


	if(execlp("./hello","./hello",NULL) == -1);




		}


	return 0;
}

