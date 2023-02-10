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
typedef struct 
{
    char name[10]; //数组名用strcpy
    int age;
    char sex;
    double score;
} stu;


int main(int argc, char const *argv[])
{
    
    FILE *fp = fopen("struct_fread.txt","w");
    if (NULL == fp)
    {
        ERR_MSG("fopen");
        return -1;
    }

    stu s1 = 
    {
        .name = "jack",
        .age = 19,
        .sex = 'F',
        .score = 88.5,
    };

    //结构体写入文件中
    /*
    size_t ret = fwrite(&s1,sizeof(s1),1,fp); //
    printf("成功写入数据 ret = %ld 个\n",ret);
    */

    //结构体数组写入文件中,也可以单独写入，循环写
    stu s3[2] = {
        {"rose",18,'F',90},
        {"kate",20,'F',91}
    };
    size_t ret = fwrite(s3,sizeof(s3),1,fp); //

    if (fclose(fp) < 0)
    {
        ERR_MSG("fclose");
        return -1;
    }

    //也可以继续使用fp1 
    FILE *fp1 = fopen("struct_fread.txt","r");
    if (NULL == fp1)
    {
        ERR_MSG("fopen");
        return -1;
    }


   
   stu s2;
   size_t ret1;
   while (1)
   {
    ret1 = fread(&s2,sizeof(s2),1,fp);
    if (0 == ret1)
    {
        break;
    }
    fprintf(stdout,"ret = %ld, name = %s,age = %d,sex = %c,score = %g \n",ret,s2.name,s2.age,s2.sex,s2.score);
   }
   

    if (fclose(fp1) < 0)
    {
        ERR_MSG("fclose");
        return -1;
    }
    
    return 0;
}
