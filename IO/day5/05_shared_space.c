#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>    

int num = 100;

//子线程的空间使用
//因为每一个线程执行都是一个函数，所以基本性质与函数相同，
//比如每一个线程拥有独立的栈区、堆区、静态区



void * ThreadFun1(void *arg)
{

	printf("子线程1正在执行...\n");
	num = 666;
	printf("process 1 : num = %d\n",num);

	int n = *(int *)arg;


	printf("process 1 : n = %d\n",n);


}

void * ThreadFun2(void *arg)
{

	printf("子线程2正在执行...\n");

	printf("process 2 : num = %d\n",num);

	char *s = (char *)arg;

	
	printf("process 2 : s = %s\n",s);
}



int main(int argc, char const *argv[])
{
	printf("主控线程正在执行...\n");

	int sum = 999;
	char buf[] = "hello world";
	pthread_t thread1;
	thread1 = pthread_create(&thread1,NULL,ThreadFun1,&sum);
	if(thread1 !=0)
	{
		perror("pthread_create error");
		exit(1);
	}

	pthread_t thread2;
	thread2 = pthread_create(&thread2,NULL,ThreadFun2,buf);
	if(thread2 !=0)
	{
		perror("pthread_create error");
		exit(1);
	}

	while(1);

	return 0;
}
