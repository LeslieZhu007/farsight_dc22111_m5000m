#include <stdio.h>
#include <time.h>


int main(int argc, char const *argv[])
{
    
    time_t t = time(NULL);
    fprintf(stdout,"%ld\n",t);




    return 0;
}
