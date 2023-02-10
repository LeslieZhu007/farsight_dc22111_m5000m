#include <stdio.h>
#include <time.h>


int main(int argc, char const *argv[])
{
    
    time_t t = time(NULL);
    fprintf(stdout,"%ld\n",t);

    time_t t1; //time_t *t1;==>指针指向不明，容易造成野指针
    time(&t1); //一级指针一般为普通变量取地址
    fprintf(stdout,"%ld\n",t1);


    localtime()

    return 0;
}
