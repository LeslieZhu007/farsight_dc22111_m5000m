#include <stdio.h>
int main(int argc, char const *argv[])
{
    /*
    int *p,m=5,n;
    printf("*p = %d\n",*p);
    scanf("%d",&n);  
    *p=n;
    printf("*p = %d\n",*p);
*/
    char *s="\ta\018bc";
    for (  ; *s!='\0' ; s++)  
    {
        printf("*") ;
    }




    return 0;
}
