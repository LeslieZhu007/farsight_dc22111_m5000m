#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>



//这个例子中我们希望做蛋糕的线程先运行，运行结束之后买蛋糕的线程再运行
//如果什么也不加，无法得到预期
//如果使用互斥锁，能实现互斥，但是无法保证做蛋糕的先执行

pthread_mutex_t mutex;

void * ThreadFun1(void* arg)
{
	pthread_mutex_lock(&mutex);

	printf("正在做蛋糕...\n");

	sleep(1);

	printf("蛋糕做好了...\n");

	pthread_mutex_unlock(&mutex);
}


void *ThreadFun2(void *arg)
{
    pthread_mutex_lock(&mutex);

    printf("正在买蛋糕...\n");

    sleep(1);

    printf("蛋糕买完了...\n");

    pthread_mutex_unlock(&mutex);
}





int main(int argc, char const *argv[])
{
	pthread_t thread1, thread2;
	pthread_mutex_init(&mutex, NULL);

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
