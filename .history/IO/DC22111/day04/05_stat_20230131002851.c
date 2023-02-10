#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


#define ERR_MSG(msg) do\
{\
    fprintf(stderr,"line:%d\n",__LINE__);\
    perror(msg);\
} while (0);


void get_file_permission(struct stat buf)
{
    fprintf(stdout,"文件权限为:");
    mode_t mode = buf.st_mode;
    if ((mode & 0400)!=0)
    {
        putchar('r');
    } else
    {
        putchar('-');
    }

    if ((mode & 0200)!=0)
    {
        putchar('w');
    } else
    {
        putchar('-');
    }

    if ((mode & 0100)!=0)
    {
        putchar('x');
    } else
    {
        putchar('-');
    }

    /***********************************/

    if ((mode & 0040)!=0)
    {
        putchar('r');
    } else
    {
        putchar('-');
    }


    if ((mode & 0020)!=0)
    {
        putchar('w');
    } else
    {
        putchar('-');
    }

    if ((mode & 0010)!=0)
    {
        putchar('x');
    } else
    {
        putchar('-');
    }

    /*********************************************/

    if ((mode & 0004)!=0)
    {
        putchar('r');
    } else
    {
        putchar('-');
    }


    if ((mode & 0002)!=0)
    {
        putchar('w');
    } else
    {
        putchar('-');
    }

    if ((mode & 0001)!=0)
    {
        putchar('x');
    } else
    {
        putchar('-');
    }

    putchar('\n');
    
}


void get_file_permission_improve(struct stat buf)
{
    fprintf(stdout,"文件权限为:");
    mode_t mode = buf.st_mode;
    
    int i = 8;
    while (i >= 0)
    {
        if ((mode& (0x1<<i))!=0)
        {
            if (i%3==2)
            {
                putchar('r');
            }
            if (i%3==1)
            {
                putchar('w');
            }
            if (i%3==0)
            {
                putchar('x');
            }
            
        }  else
        {
            putchar('-');
        }
        i--;
    }
    
    putchar('\n');


}


void get_file_permission_improve_1(struct stat buf)
{
    fprintf(stdout,"文件权限为:");
    mode_t mode = buf.st_mode;
    
    int i = 0;
    while (1)
    {
        if ((mode& (0400>>i))!=0)
        {
            if (i%3==2)
            {
                putchar('x');
            }
            if (i%3==1)
            {
                putchar('w');
            }
            if (i%3==0)
            {
                putchar('r');
            }
            
        }  else
        {
            putchar('-');
        }
        i++;
        if (i >= 9)
        {
            break;
        }
    }
    putchar('\n');


}

void get_file_permission_improve_2(struct stat buf)
{
    fprintf(stdout,"文件权限为:");
    mode_t mode = buf.st_mode;
    
    char per[] = "rwx";
    for (int i = 0; i < 9; i++)
    {
        if ((mode&(0400>>i))==0)
        {
            putchar('-');
        } else
        {
            //fprintf(stdout,"%c",per[i%3]);
            switch (i%3)
            {
            case 0:
                putchar('r');
                break;
            case 1:
                putchar('w');
                break;
            case 2:
                putchar('x');
                break;
            default:
                break;
            }
        }
    }
    putchar('\n');
    //fflush(stdout);


}

void get_file_permission_improve_3(struct stat buf)
{
    fprintf(stdout,"文件权限为:");
    mode_t mode = buf.st_mode;
    
    char per[] = "rwx";
    for (int i = 0; i < 9; i++)
    {
        if ((mode&(0400>>i))==0)
        {
            putchar('-');
        } else
        {
            fprintf(stdout,"%c",per[i%3]);
        }
    }
    putchar('\n');
    //fflush(stdout);
    
}


//str[10]不代表数组，代表指针
//还有另外一个功能，提示用户
char* get_file_permission_improve_4(struct stat buf,char str[10],int size)
{
    fprintf(stdout,"sizeof str = %ld:",sizeof(str));
    fprintf(stdout,"文件权限为:");
    mode_t mode = buf.st_mode;
    
    if (size < 10) 
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
    putchar('\n');
    //fflush(stdout);

    return str;
    
}


int main(int argc, char const *argv[])
{
    //打开  读的方式
    int fd = open("sophie_marceau.jpeg",O_RDONLY);
    if (fd < 0)
    {
        ERR_MSG("open");
        return -1;
    }

    /****************main code begin*****************/
    struct stat buf;
    if(stat("sophie_marceau.jpeg",&buf) < 0)
    {
        ERR_MSG("stat");
        return -1;
    }
    /*
    struct stat {
               dev_t     st_dev;         /* ID of device containing file */
               ino_t     st_ino;         /* Inode number */
               mode_t    st_mode;        /* File type and mode */
               nlink_t   st_nlink;       /* Number of hard links */
               uid_t     st_uid;         /* User ID of owner */
               gid_t     st_gid;         /* Group ID of owner */
               dev_t     st_rdev;        /* Device ID (if special file) */
               off_t     st_size;        /* Total size, in bytes */
               blksize_t st_blksize;     /* Block size for filesystem I/O */
               blkcnt_t  st_blocks;      /* Number of 512B blocks allocated 

           #define st_atime st_atim.tv_sec      /* Backward compatibility 
           #define st_mtime st_mtim.tv_sec
           #define st_ctime st_ctim.tv_sec
    */

    
    /****************main code end*****************/
    if (close(fd) < 0)
    {
        ERR_MSG("close");
        return -1;
    }

    //文件的类型和权限
    fprintf(stdout,"mode:%d : %o\n",buf.st_mode,buf.st_mode);
    get_file_permission(buf);
    get_file_permission_improve(buf);
    get_file_permission_improve_2(buf);
    get_file_permission_improve_1(buf);
    char str[9] = {0};
    if(get_file_permission_improve_4(buf,str,sizeof(str))==NULL)
    {
       fprintf(stdout,"获取用户权限失败\n");     
    }
    fprintf(stdout,"str = %s\n",str);
    

    //文件的硬链接数
    fprintf(stdout,"link:%ld\n",buf.st_nlink);

    //文件所属用户名
    fprintf(stdout,"uid:%d\n",buf.st_uid);

    //文件所属组用户名
    fprintf(stdout,"gid:%d\n",buf.st_gid);

    //文件的大小
    fprintf(stdout,"size=%ld\n",buf.st_size);

    //文件的时间
    fprintf(stdout,"time:%ld\n",buf.st_ctime);

    return 0;
}
