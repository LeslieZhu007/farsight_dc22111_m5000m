#include <stdio.h>


int main(int argc, char const *argv[])
{
    //打开fopen, r
    FILE *fp = fopen("./fprintf.txt","r");
    if(NULL == fp)
    {
        perror("fopen");
        return -1;
    }
    printf("fopen succeed\n");

    //fscanf  此刻光标在文件尾
    char name[20];
    int age;
    float score;
    fscanf(fp,"%s%d%g",name,&age,&score);
    printf("name = %s,age = %d,score = %g\n",name,age,score);

    fscanf(fp,"%s%d%g",name,&age,&score);
    printf("name = %s,age = %d,score = %g\n",name,age,score);

    fscanf(fp,"%s%d%g",name,&age,&score);
    printf("name = %s,age = %d,score = %g\n",name,age,score);

    fscanf(fp,"%s%d%g",name,&age,&score);
    printf("name = %s,age = %d,score = %g\n",name,age,score);

    if(fclose(fp) < 0)
    {
        perror("fclose");
        return -1;
    }
    printf("fclose succeed\n");

    return 0;
}
