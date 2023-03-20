#include <stdio.h>
int main(int argc,const char* argv[])
{
	int i,j,rows;
	printf("please input rows:");
	scanf("%d",&rows);
	for(i=0;i<rows;i++)
	{
		for(j=i;j>=0;j--)
		{
			printf("* ");
		}
		printf("\n");	
	}
	return 0;
}
