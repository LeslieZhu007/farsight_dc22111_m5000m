#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>    
#include <unistd.h>

pthread_t thread1,thread2;

void * ThreadFun1(void *arg)
{
 //当接收到销毁请求后不使能，意味着不会销毁
 	
	//pthread_setcancelstate(PTHREAD_CANCEL_DISABLE,NULL);
	while(1)
	{
		printf("子线程1:%#lx正在执行...\n",pthread_self());
		sleep(1);

	}
}

void * ThreadFun2(void *arg)
{
	static int i = 888;
	int num = 0;
	while(1)
	{
		num ++;
		printf("子线程2:%#lx正在执行...\n",pthread_self());
		sleep(1);

		if(num == 5)
		{
			pthread_cancel(thread1);
		}
	}
}



int main(int argc, char const *argv[])
{

	printf("主控线程:%#lx 正在执行...\n",pthread_self());



	if( pthread_create(&thread1,NULL,ThreadFun1,NULL)!=0)
	{
		perror("pthread_create error");
		exit(1);
	}

	if( pthread_create(&thread2,NULL,ThreadFun2,NULL)!=0)
	{
		perror("pthread_create error");
		exit(1);
	}
	printf("thread1:%#lx, thread2:%#lx\n", thread1, thread2);

	sleep(10);

	pthread_cancel(thread2);

	while(1);




	return 0;
}
