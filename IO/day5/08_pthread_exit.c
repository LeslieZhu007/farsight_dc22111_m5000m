#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>    
#include <unistd.h>

void * ThreadFun1(void *arg)
{
	while(1)
	{
		printf("子线程1:%#lx正在执行...\n",pthread_self());
		sleep(1);
	}
}

void * ThreadFun2(void *arg)
{
	while(1)
	{
		printf("子线程2:%#lx正在执行...\n",pthread_self());
		sleep(1);
	}
}



int main(int argc, char const *argv[])
{


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
    printf("thread1:%#lx, thread2:%#lx\n", thread1, thread2);
    	while(1)
	{

		printf("主控线程:%#lx 正在执行...\n",pthread_self());
		sleep(1);
	}
	sleep(5);

	pthread_exit(NULL);

	while(1);

	return 0;
}
