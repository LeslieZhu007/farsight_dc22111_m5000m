#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>    

void * ThreadFun1(void *arg)
{

	printf("子线程1正在执行...\n");
}

void * ThreadFun2(void *arg)
{

	printf("子线程2正在执行...\n");
}



int main(int argc, char const *argv[])
{
	printf("主控线程正在执行...\n");

	pthread_t thread1;
	thread1 = pthread_create(&thread1,NULL,ThreadFun1,NULL);
	if(thread1 !=0)
	{
		perror("pthread_create error");
		exit(1);
	}

	pthread_t thread2;
	thread2 = pthread_create(&thread2,NULL,ThreadFun2,NULL);
	if(thread2 !=0)
	{
		perror("pthread_create error");
		exit(1);
	}

	//while(1);

	return 0;
}
