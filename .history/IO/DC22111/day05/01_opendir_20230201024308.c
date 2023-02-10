#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <pwd.h>
#include <grp.h>
 #include <time.h>

#define ERR_MSG(msg) do\
{\
    fprintf(stderr,"line:%d\n",__LINE__);\
    perror(msg);\
} while (0);

//str[10]不代表数组，代表指针
//还有另外一个功能，提示用户
char* get_file_permission_improve_4(struct stat buf,char str[10],int size)
{
    //fprintf(stdout,"sizeof str = %ld:",sizeof(str));
    //fprintf(stdout,"文件权限为:");
    mode_t mode = buf.st_mode;
    
    if (size < 10) //权限为9位，还需加上\0
    {
        return NULL;
    }
    
    char per[] = "rwx";
    for (int i = 0; i < 9; i++)
    {
        if ((mode&(0400>>i))==0)
        {
            putchar('-');
            str[i] = '-';
        } else
        {
            fprintf(stdout,"%c",per[i%3]);
            str[i] = per[i%3];
        }
    }
    //putchar('\n');
    fflush(stdout);

    return str;
    
}




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
