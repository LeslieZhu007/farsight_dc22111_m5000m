#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    /*
    int *p,m=5,n;
    printf("*p = %d\n",*p);
    scanf("%d",&n);  
    *p=n;
    printf("*p = %d\n",*p);
*/

    /*
    char *s="\ta\018bc";
    for (  ; *s!='\0' ; s++)  
    {
        printf("*") ;
    }
    */

    char s[] = "china";
    char *p;
    p = s;

    printf("strlen(s) = %ld\n",strlen(s));
    printf("sizeof(s) = %ld\n",sizeof(s));

    printf("strlen(p) = %ld\n",strlen(p));
    printf("sizeof(p) = %ld\n",sizeof(*p));





    return 0;
}
