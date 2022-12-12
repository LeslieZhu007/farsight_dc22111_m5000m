#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
int money = 10000;

void *ZhangsanFun(void *arg)
{
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

}

void *LisiFun(void *arg)
{
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

}







int main(int argc, char const *argv[])
{
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



	return 0;
}
