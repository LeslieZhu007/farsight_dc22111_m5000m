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
    mode_t mode = buf.st_mode;
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
