#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>

#define ERR_MSG(msg) do\
{\
    fprintf(stderr,"line:%d\n",__LINE__);\
    perror(msg);\
} while (0);


void print_file_info_by_file_name(char *filename)
{
    
}





int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr,"请输入目录名\n");
        return -1;
    }
    
    //打开一个目录
    DIR* dp = opendir(argv[1]);
    if (NULL == dp)
    {
        perror("opendir");
        return -1;
    }

    /******************begin**************************/
    struct dirent *rp = NULL;
    int i = 1;
    while (1)
    {
        rp = readdir(dp);
        if (NULL == rp)
        {
            if (0==errno) //没有更新errno
            {
                printf("文件读取完毕\n");
                break;
            } else //更新errno 
            {
                perror("readdir");
                return -1;
            }
            
        }
        //不显示隐藏文件
        //异常文件以.开头
        if ('.' !=(rp->d_name)[0] ) // *(rp->d_name)
        {
            //printf("[%d] %s\n",i++,rp->d_name);
            print_file_info_by_file_name(rp->d_name);
        }
    }
    /******************end***********************/

    if(closedir(dp) < 0)
    {
        perror("closedir");
        return -1;
    }


    return 0;
}
