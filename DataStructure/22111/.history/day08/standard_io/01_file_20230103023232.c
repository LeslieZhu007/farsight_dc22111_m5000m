#include <stdio.h>
#include <strings.h>
int main(int argc,const char* argv[])
{

	FILE *fp; //define a file pointer
	char str[] = "hello world";

	//1. open file 
	//fp = fopen(".//file.txt","w");
	fp = fopen("./file1.txt","w");
	if(NULL == fp)
	{
		printf("open error\n");
		return -1;
	}

	//read and write 
	fprintf(fp,"%s",str);

	//close a file 
	fclose(fp);


	/**************************************/

	fp = fopen("./file.txt","r");

	if(NULL == fp)
	{
		printf("open error\n");
		return -1;
	}

	char buf[100];
	while(!feof(fp))
	{
		bzero(buf, sizeof(buf));
		fscanf(fp,"%s",buf); //end with space and enter
		printf("buf = %s\n",buf);
	}


	fclose(fp);


}
