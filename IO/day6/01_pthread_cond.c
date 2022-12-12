#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int flags = 0;

pthread_mutex_t mutex;

//创建一个条件变量


pthread_cond_t cond;



void *ThreadFun1(void *arg)
{
	printf("正在做蛋糕...\n");

	sleep(1);

	printf("蛋糕做好了...\n");

	pthread_mutex_lock(&mutex);


	flags = 5;


	pthread_mutex_unlock(&mutex);

	//先执行的线程执行完毕后发送信号通知

	pthread_cond_broadcast(&cond);

}


void *ThreadFun2(void *arg)
{
	pthread_mutex_lock(&mutex);
	//后执行的线程先阻塞等待接收信号通知
	//为什么条件变量要结合互斥锁一起使用？
	//因为接收信号通知的线程可能有很多，所以在条件变量内部会创建一个等待队列,
	//用来保存接收信号通知的线程，对于多个线程而言，这个等待队列就是一个共享
	//资源，所以要保证对这个共享资源操作的时候要互斥，所以内部要使用互斥锁来
	//解决
	//pthread_cond_wait内部运行机制：
	//  将接收信号通知的线程放在等待队列里面
	//  解锁
	//  等待上锁
	//  如果接收到信号通知了，上锁将这个线程从等待队列中移除
	//  解锁
	//  等待上锁
	pthread_cond_wait(&cond,&mutex);
	if(flags > 0)
	{
		printf("%#lx:正在买蛋糕...\n",pthread_self());
		sleep(1);

		printf("蛋糕买完了...\n");

		flags--;



	}

	pthread_mutex_unlock(&mutex);



}


int main(int argc, char const *argv[])
{
	pthread_mutex_init(&mutex,NULL);

	pthread_cond_init(&cond,NULL);

	pthread_t thread1,thread2;

	if(pthread_create(&thread1,NULL,ThreadFun1,NULL) !=0)
	{

		perror("pthread_create error");
		exit(1);

	}

	int i;

	for(i = 0; i <=5;i++)
	{
		if(pthread_create(&thread2,NULL,ThreadFun2,NULL)!=0)
		{
			perror("pthread_create error");
			exit(1);


		}


	}


	while(1);



	pthread_cond_destroy(&cond);

	pthread_mutex_destroy(&mutex);


	return 0;
}

