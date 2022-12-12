#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
//信号量的操作

//第一步：创建一个信号量
sem_t sem;


void * ThreadFun1(void* arg)
{

	printf("正在做蛋糕...\n");

	sleep(1);

	printf("蛋糕做好了...\n");

	//第三步：先执行的线程执行完毕后执行V操作
	sem_post(&sem);
}


void *ThreadFun2(void *arg)
{
//第四步：后执行的线程执行前执行P操作
	sem_wait(&sem);
    printf("正在买蛋糕...\n");

    sleep(1);

    printf("蛋糕买完了...\n");

}





int main(int argc, char const *argv[])
{

	//第二步：初始化信号量
	sem_init(&sem,0,0);

	pthread_t thread1, thread2;

	if(pthread_create(&thread1, NULL, ThreadFun1, NULL) != 0)
	{
		perror("pthread_create error");
		exit(1);
	}

	if(pthread_create(&thread2, NULL, ThreadFun2, NULL) != 0)
	{
		perror("pthread_create error");
		exit(1);
	}

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	return 0;
}
