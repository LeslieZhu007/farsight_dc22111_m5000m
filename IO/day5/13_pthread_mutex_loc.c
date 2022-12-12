#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
int money = 10000;

pthread_mutex_t mutex;



void *ZhangsanFun(void *arg)
{
	//第三步：操作前对共享资源的操作进行上锁
	pthread_mutex_lock(&mutex);
	int qu = 10000;
	int yu = money;
	int shiji = 0;

	printf("张三正在查询余额...\n");
	sleep(1);
	printf("张三查询到的余额为：%d元\n", yu);

	printf("张三正在取钱...\n");
	sleep(1);
	if(qu > yu)
	{
		shiji = 0;
	}

	else 
	{
		shiji = qu;
		yu = money - qu;
		money = yu;
	}


	printf("张三实际取了%d元，剩余%d元\n", shiji, money);
	//第四步：操作完毕后进行解锁
	pthread_mutex_unlock(&mutex);
}

void *LisiFun(void *arg)
{
	pthread_mutex_lock(&mutex);

	int qu = 10000;
	int yu = money;
	int shiji = 0;

	printf("李四正在查询余额...\n");
	sleep(1);
	printf("李四查询到的余额为：%d元\n", yu);

	printf("李四正在取钱...\n");
	sleep(1);
	if(qu > yu)
	{
		shiji = 0;
	}
	else 
	{
		shiji = qu;
		yu = money - qu;
		money = yu;
	}
	printf("李四实际取了%d元，剩余%d元\n", shiji, money);
	pthread_mutex_unlock(&mutex);
}







int main(int argc, char const *argv[])
{
	//第二步：初始化互斥锁
	pthread_mutex_init(&mutex,NULL);
	pthread_t zhangsan,lisi;

	if(pthread_create(&zhangsan,NULL,ZhangsanFun,NULL) != 0)
	{
		perror("pthread_create error");
		exit(1);
	}

	if(pthread_create(&lisi,NULL,LisiFun,NULL) != 0)
	{
		perror("pthread_create error");
		exit(1);
	}

	pthread_join(zhangsan,NULL);
	pthread_join(lisi,NULL);

	//第五步：销毁互斥锁
	pthread_mutex_destroy(&mutex);
	return 0;
}
