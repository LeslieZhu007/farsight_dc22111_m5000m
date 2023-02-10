#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

//此处参数msg如果写成整数，则在编译的过程中会报错，但是展开的过程中不会报错
#define ERR_MSG(msg) do\
{\
    fprintf(stderr,"line:%d\n",__LINE__);\
    perror(msg);\
} while (0);

int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr,"请在命令行传入文件名\n");
        return -1;
    }
    
    FILE *fp = fopen(argv[1],"r");
    if (NULL == fp)
    {
        ERR_MSG("fopen");
        return -1;
    }

    /*************************/
    //从文件中读取字符串
    
    char str[32] = "";
    /*
    fgets(str,5,fp); //5 最多拿4个
    printf("str = %s\n",str);

    bzero(str,sizeof(str));
    fgets(str,5,fp); //5 最多拿4个
    printf("str = %s\n",str);
   
   bzero(str,sizeof(str));
    fgets(str,5,fp); //5 最多拿4个
    printf("str = %s\n",str);

    bzero(str,sizeof(str));
    fgets(str,5,fp); //5 最多拿4个
    printf("str = %s\n",str);

    bzero(str,sizeof(str));
    fgets(str,5,fp); //5 最多拿4个
    printf("str = %s\n",str);
    */
   /*
   while (1)
   {
     bzero(str,sizeof(str));
     if(fgets(str,5,fp) == NULL){break;}; //5 最多拿4个
     printf("%s",str);
   }
   */
    while (fgets(str,5,fp) != NULL)
    {
        printf("%s",str);
        bzero(str,sizeof(str));
    }
    

    /*************************/
    if (fclose(fp) < 0)
    {
        ERR_MSG("fclose");
        return -1;
    }
    
    return 0;
}
