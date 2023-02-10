#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define ERR_MSG(msg) do\
{\
    fprintf(stderr,"line:%d\n",__LINE__);\
    perror(msg);\
} while (0);
/*
SYNOPSIS
       #include <stdio.h>

       size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);

       size_t fwrite(const void *ptr, size_t size, size_t nmemb,
                     FILE *stream);

DESCRIPTION
       The  function  fread()  reads  nmemb items of data, each
       size bytes long, from the stream pointed to  by  stream,
       storing them at the location given by ptr.

       The  function  fwrite() writes nmemb items of data, each
       size bytes long, to the stream  pointed  to  by  stream,
       obtaining them from the location given by ptr.

       For nonlocking counterparts, see unlocked_stdio(3).

RETURN VALUE
       On  success,  fread()  and fwrite() return the number of
       items read or written.  This number equals the number of
       bytes  transferred  only  when  size  is 1.  If an error
       occurs, or the end of the file is  reached,  the  return
       value is a short item count (or zero).

       fread()  does  not  distinguish  between end-of-file and
       error, and callers must use  feof(3)  and  ferror(3)  to
       determine which occurred.

*/

int main(int argc, char const *argv[])
{
    
     FILE *fp = fopen("fwrite.txt","w");
    if (NULL == fp)
    {
        ERR_MSG("src_fopen");
        return -1;
    }
    int arr[3] = {48,49,50};
    //fwrite(arr,4,3,fp);
    size_t ret = fwrite(arr,1,sizeof(arr),fp);
    printf("成功输出数据 ret = %d 个\n",ret);



    return 0;
}
