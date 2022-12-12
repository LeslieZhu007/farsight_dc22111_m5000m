#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct person{
	char name[20];
	int age;
	char sex;
	void (*eat)(void);
};

void eatfood(void)
{
	printf("hello world\n");
}

void show_person_info(struct person *p)
{
	printf("name = %s,age = %d,sex = %c \n",p->name,p->age,p->sex);

	p->eat();

}




int main()
{
	struct person p1;

	struct person *p2;

	p2 = &p1;

	p2 = malloc(sizeof(struct person));

	strcpy(p1.name,"zhangsan");
	p1.age=25;
	p1.sex='m';
	p1.eat=eatfood;

	show_person_info(&p1);


	p2->name;
	p2->age;
	p2->sex;
	p2->eat;



	return 0;
}
