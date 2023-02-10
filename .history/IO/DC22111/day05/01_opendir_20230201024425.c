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

void get_file_type_improve(mode_t mode)
{
    switch (mode&S_IFMT)
    {
        case S_IFSOCK:
            putchar('s');
            break;
        case S_IFLNK:
            putchar('l');
            break;
        case S_IFREG:
            putchar('-');
            break;    
        case S_IFBLK:
            putchar('b');
            break;    
        case S_IFDIR:
            putchar('d');
            break;
        case S_IFCHR:
            putchar('c');
            break;
        case S_IFIFO:
            putchar('p');
            break;

        default:
            fprintf(stdout,"mode错误\n");
            break;
    }
}

void print_uid_name(uid_t uid)
{
    struct passwd *usr =  getpwuid(uid);
    if (NULL == usr)
    {
        ERR_MSG("getpwuid");
        return;
    }
    fprintf(stdout,"%s",usr->pw_name); 
}

void print_gid_name(gid_t gid)
{
    struct group *usr =  getgrgid(gid);
    if (NULL == usr)
    {
        ERR_MSG("getgrgid");
        return;
    }
    fprintf(stdout,"%s",usr->gr_name); 
}

char *get_month(int mon)
{
    switch(mon)
    {
        case 0:
            return "Jan";
            break;
        case 1:
            return "Feb";
            break;
        case 2:
            return "Mar";
            break;
        case 3:
            return "Apr";
            break;
        case 4:
            return "May";
            break;
        case 5:
            return "Jun";
            break;
        case 6:
            return "Jul";
            break;
        case 7:
            return "Aug";
            break;
        case 8:
            return "Sep";
            break;
        case 9:
            return "Oct";
            break;
        case 10:
            return "Nov";
            break;
        case 11:
            return "Dec";
            break;
        default:
            break;
    }
}

void print_time(time_t t)
{
    struct tm *info = localtime(&t);
    if (NULL == info)
    {
        ERR_MSG("localtime");
        return;
    }
    printf("%s %02d %02d:%02d",\
    get_month(info->tm_mon),info->tm_mday,\
    info->tm_hour,info->tm_min);
    fflush(stdout); //强制刷新
}





void print_file_info_by_file_name(char *filename)
{
    int fd = open(filename,O_RDONLY);
    if (fd < 0)
    {
        ERR_MSG("open");
        return -1;
    }
    



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
