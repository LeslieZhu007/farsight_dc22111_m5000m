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
    if (argc < 2)
    {
        ERR_MSG("error");
        return -1;
    }
    
    FILE *fp = fopen(argv[1],"r");
    if (NULL == fp)
    {
        ERR_MSG("fopen");
        return -1;
    }
    
    char buf[32]="";
    //从文件中读取数据，打印到终端上
    while (fread(buf,1,sizeof(buf),fp) !=0)  //while (fread(buf,sizeof(buf),1,fp) !=0) ==>最后一次读不到数据
    {
        fwrite(buf,sizeof(buf),1,stdout);
        bzero(buf,sizeof(buf));
    }
    
    
    

    if (fclose(fp) < 0)
    {
        ERR_MSG("fclose");
        return -1;
    }
    
    return 0;
}
