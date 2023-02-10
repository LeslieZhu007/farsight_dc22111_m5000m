#include <stdio.h>

int main(int argc, char const *argv[])
{
    char *s="\ta\018bc";
    for (  ; *s!='\0' ; s++)  
    {
        printf('%c\t',*s) ;
    }
    return 0;
}
